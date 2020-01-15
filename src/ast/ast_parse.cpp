#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"

void das_yybegin(const char * str);
int das_yyparse();
int das_yylex_destroy();

namespace das {

    vector<string> getAllRequie ( const char * src, uint32_t length ) {
        vector<string> req;
        const char * src_end = src + length;
        bool wb = true;
        while ( src < src_end ) {
            if ( src[0]=='"' ) {
                src ++;
                while ( src < src_end && src[0]!='"' ) {
                    src ++;
                }
                src ++;
                wb = true;
                continue;
            } else if ( src[0]=='/' && src[1]=='/' ) {
                while ( src < src_end && !(src[0]=='\n') ) {
                    src ++;
                }
                src ++;
                wb = true;
                continue;
            } else if ( src[0]=='/' && src[1]=='*' ) {
                int depth = 0;
                while ( src < src_end ) {
                    if ( src[0]=='/' && src[1]=='*' ) {
                        depth ++;
                        src += 2;
                    } else if ( src[0]=='*' && src[1]=='/' ) {
                        if ( --depth==0 ) break;
                        src += 2;
                    } else {
                        src ++;
                    }
                }
                src +=2;
                wb = true;
                continue;
            } else if ( wb && ((src+8)<src_end) && src[0]=='r') {   // need space for 'require '
                if ( memcmp(src, "require", 7)==0 ) {
                    src += 7;
                    if ( isspace(src[0]) ) {
                        while ( src < src_end && isspace(src[0]) ) {
                            src ++;
                        }
                        if ( src >= src_end ) {
                            continue;
                        }
                        if ( src[0]=='_' || isalpha(src[0]) || src[0] ) {
                            string mod;
                            while ( src < src_end && (isalnum(src[0]) || src[0]=='_' || src[0]=='.' || src[0]=='/') ) {
                                mod += *src ++;
                            }
                            req.push_back(mod);
                            continue;
                        } else {
                            wb = true;
                            goto nextChar;
                        }
                    } else {
                        wb = false;
                        goto nextChar;
                    }
                } else {
                    goto nextChar;
                }
            }
        nextChar:
            wb = src[0]!='_' && (wb ? !isalnum(src[0]) : !isalpha(src[0]));
            src ++;
        }
        return req;
    }

    string getModuleName ( const string & nameWithDots ) {
        auto idx = nameWithDots.find_last_of("./");
        if ( idx==string::npos ) return nameWithDots;
        return nameWithDots.substr(idx+1);
    }

    string getModuleFileName ( const string & nameWithDots ) {
        auto fname = nameWithDots;
        // TODO: should we?
        replace ( fname.begin(), fname.end(), '.', '/' );
        return fname;
    }

    bool getPrerequisits ( const string & fileName,
                          const FileAccessPtr & access,
                          vector<pair<string,string>> & req,
                          vector<string> & missing,
                          vector<string> & circular,
                          das_set<string> & dependencies,
                          ModuleGroup & libGroup,
                          TextWriter & log,
                          int tab ) {
        if ( auto fi = access->getFileInfo(fileName) ) {
            log << string(tab,'\t') << "in " << fileName << "\n";
            vector<string> ownReq = getAllRequie(fi->source, fi->sourceLength);
            for ( auto & mod : ownReq ) {
                log << string(tab,'\t') << "require " << mod << "\n";
                auto module = Module::require(mod); // try native with that name
                if ( !module ) {
                    auto it_r = find_if(req.begin(), req.end(), [&] ( const pair<string,string> & reqM ) {
                        return reqM.first == mod;
                    });
                    if ( it_r==req.end() ) {
                        if ( dependencies.find(mod) != dependencies.end() ) {
                            // circular dependency
                            log << string(tab,'\t') << "from " << fileName << " require " << mod << " - CIRCULAR DEPENDENCY\n";
                            circular.push_back(mod);
                            return false;
                        }
                        dependencies.insert(mod);
                        // module file name
                        auto info = access->getModuleInfo(mod, fileName);
                        if ( info.first.empty() ) {
                            // request can't be translated to module name
                            log << string(tab,'\t') << "from " << fileName << " require " << mod << " - MODULE INFO NOT FOUND\n";
                            missing.push_back(mod);
                            return false;
                        }
                        if ( !getPrerequisits(info.second, access, req, missing, circular, dependencies, libGroup, log, tab + 1) ) {
                            return false;
                        }
                        log << string(tab,'\t') << "from " << fileName << " require " << mod << " - ok, new module\n";
                        req.push_back(info);
                    } else {
                        log << string(tab,'\t') << "from " << fileName << " require " << mod << " - already required\n";
                    }
                } else {
                    log << string(tab,'\t') << "from " << fileName << " require " << mod << " - ok\n";
                    libGroup.addModule(module);
                }
            }
            return true;
        } else {
            log << string(tab,'\t') << "in " << fileName << " - NOT FOUND\n";
            missing.push_back(fileName);
            return false;
        }
    }

    // PARSER

    ProgramPtr g_Program;
    FileAccessPtr g_Access;
    vector<FileInfo *>  g_FileAccessStack;

    extern "C" int64_t ref_time_ticks ();
    extern "C" int get_time_usec (int64_t reft);

    ProgramPtr parseDaScript ( const string & fileName,
                              const FileAccessPtr & access,
                              TextWriter & logs,
                              ModuleGroup & libGroup,
                              bool exportAll,
                              CodeOfPolicies policies ) {
        auto time0 = ref_time_ticks();
        int err;
        auto program = g_Program = make_shared<Program>();
        g_Program->policies = policies;
        g_Access = access;
        program->thisModuleGroup = &libGroup;
        libGroup.foreach([&](Module * pm){
            g_Program->library.addModule(pm);
            return true;
        },"*");
        g_FileAccessStack.clear();
        if ( auto fi = access->getFileInfo(fileName) ) {
            g_FileAccessStack.push_back(fi);
            das_yybegin(fi->source);
        } else {
            g_Program->error(fileName + " not found", LineInfo());
            g_Program.reset();
            g_Access.reset();
            g_FileAccessStack.clear();
            return program;
        }
        err = das_yyparse();        // TODO: add mutex or make thread safe?
        das_yylex_destroy();
        g_Program.reset();
        g_Access.reset();
        g_FileAccessStack.clear();
        if ( err || program->failed() ) {
            sort(program->errors.begin(),program->errors.end());
            return program;
        } else {
            program->inferTypes(logs);
            if ( !program->failed() ) {
                program->lint();
                if (program->options.getBoolOption("optimize", true)) {
                    program->optimize(logs);
                } else {
                    program->buildAccessFlags(logs);
                }
                if (!program->failed())
                    program->verifyAndFoldContracts();
                if (!program->failed())
                    program->markOrRemoveUnusedSymbols(exportAll);
                if (!program->failed())
                    program->allocateStack(logs);
                if (!program->failed())
                    program->finalizeAnnotations();
            }
            if (!program->failed()) {
                if (program->options.getBoolOption("log")) {
                    logs << *program;
                }
                if (program->options.getBoolOption("plot")) {
                    logs << "\n" << program->dotGraph() << "\n";
                }
            }
            sort(program->errors.begin(), program->errors.end());
            if ( program->options.getBoolOption("log_compile_time",false) ) {
                auto dt = get_time_usec(time0) / 1000000.;
                logs << "compiler took " << dt << "\n";
            }
            return program;
        }
    }

    ProgramPtr compileDaScript ( const string & fileName,
                                const FileAccessPtr & access,
                                TextWriter & logs,
                                ModuleGroup & libGroup,
                                bool exportAll,
                                CodeOfPolicies policies ) {
        vector<pair<string,string>> req;
        vector<string> missing, circular;
        das_set<string> dependencies;
        TextWriter tw;
        if ( getPrerequisits(fileName, access, req, missing, circular, dependencies, libGroup, tw, 1) ) {
            for ( auto & mod : req ) {
                if ( !libGroup.findModule(mod.first) ) {
                    auto program = parseDaScript(mod.second, access, logs, libGroup, true, policies);
                    if ( program->failed() ) {
                        return program;
                    }
                    if ( program->thisModule->name.empty() ) {
                        program->thisModule->name = mod.first;
                    }
                    libGroup.addModule(program->thisModule.release());
                    program->library.foreach([&](Module * pm) -> bool {
                        if ( !pm->name.empty() && pm->name!="$" ) {
                            if ( !libGroup.findModule(pm->name) ) {
                                libGroup.addModule(pm);
                            }
                        }
                        return true;
                    }, "*");
                }
            }
            return parseDaScript(fileName, access, logs, libGroup, exportAll, policies);
        } else {
            auto program = make_shared<Program>();
            program->policies = policies;
            program->thisModuleGroup = &libGroup;
            TextWriter err;
            for ( auto & mis : missing ) {
                err << "missing prerequisit " << mis << "\n";
            }
            for ( auto & mis : circular ) {
                err << "circular dependency " << mis << "\n";
            }
            program->error(err.str()  + "module dependency graph:\n" + tw.str(), LineInfo(), 
                            CompilationError::module_not_found);
            return program;
        }
    }
}

