#include "daScript/misc/platform.h"

#include "module_builtin_rtti.h"

#include "daScript/simulate/simulate_visit_op.h"
#include "daScript/ast/ast_policy_types.h"
#include "daScript/ast/ast_expressions.h"
#include "daScript/simulate/aot_builtin_ast.h"
#include "daScript/misc/performance_time.h"

using namespace das;

namespace das {
    class VisitorAdapter;
};

MAKE_TYPE_FACTORY(TypeDecl,TypeDecl)
MAKE_TYPE_FACTORY(FieldDeclaration, Structure::FieldDeclaration)
MAKE_TYPE_FACTORY(Structure,Structure)
MAKE_TYPE_FACTORY(Enumeration,Enumeration)
MAKE_TYPE_FACTORY(Expression,Expression)
MAKE_TYPE_FACTORY(Function,Function)
MAKE_TYPE_FACTORY(InferHistory, Function::InferHistory)
MAKE_TYPE_FACTORY(Variable,Variable)
MAKE_TYPE_FACTORY(VisitorAdapter,VisitorAdapter)

MAKE_TYPE_FACTORY(ExprBlock,ExprBlock)
MAKE_TYPE_FACTORY(ExprLet,ExprLet)
MAKE_TYPE_FACTORY(ExprStringBuilder,ExprStringBuilder)
MAKE_TYPE_FACTORY(ExprNew,ExprNew)
MAKE_TYPE_FACTORY(ExprNamedCall,ExprNamedCall)
MAKE_TYPE_FACTORY(MakeFieldDecl,MakeFieldDecl)
MAKE_TYPE_FACTORY(MakeStruct,MakeStruct)
MAKE_TYPE_FACTORY(ExprCall,ExprCall)
MAKE_TYPE_FACTORY(ExprLooksLikeCall,ExprLooksLikeCall)
MAKE_TYPE_FACTORY(ExprNullCoalescing,ExprNullCoalescing)
MAKE_TYPE_FACTORY(ExprAt,ExprAt)
MAKE_TYPE_FACTORY(ExprSafeAt,ExprSafeAt)
MAKE_TYPE_FACTORY(ExprPtr2Ref,ExprPtr2Ref)
MAKE_TYPE_FACTORY(ExprIs,ExprIs)
MAKE_TYPE_FACTORY(ExprOp2,ExprOp2)
MAKE_TYPE_FACTORY(ExprOp3,ExprOp3)
MAKE_TYPE_FACTORY(ExprCopy,ExprCopy)
MAKE_TYPE_FACTORY(ExprMove,ExprMove)
MAKE_TYPE_FACTORY(ExprClone,ExprClone)
MAKE_TYPE_FACTORY(ExprWith,ExprWith)
MAKE_TYPE_FACTORY(ExprWhile,ExprWhile)
MAKE_TYPE_FACTORY(ExprTryCatch,ExprTryCatch)
MAKE_TYPE_FACTORY(ExprIfThenElse,ExprIfThenElse)
MAKE_TYPE_FACTORY(ExprFor,ExprFor)
MAKE_TYPE_FACTORY(ExprMakeLocal,ExprMakeLocal)
MAKE_TYPE_FACTORY(ExprMakeVariant,ExprMakeVariant)
MAKE_TYPE_FACTORY(ExprMakeStruct,ExprMakeStruct)
MAKE_TYPE_FACTORY(ExprMakeArray,ExprMakeArray)
MAKE_TYPE_FACTORY(ExprMakeTuple,ExprMakeTuple)
MAKE_TYPE_FACTORY(ExprArrayComprehension,ExprArrayComprehension)
MAKE_TYPE_FACTORY(TypeInfoMacro,TypeInfoMacro);
MAKE_TYPE_FACTORY(ExprTypeInfo,ExprTypeInfo)
MAKE_TYPE_FACTORY(ExprLabel,ExprLabel);
MAKE_TYPE_FACTORY(ExprGoto,ExprGoto);
MAKE_TYPE_FACTORY(ExprRef2Value,ExprRef2Value);
MAKE_TYPE_FACTORY(ExprRef2Ptr,ExprRef2Ptr);
MAKE_TYPE_FACTORY(ExprAddr,ExprAddr);
MAKE_TYPE_FACTORY(ExprAssert,ExprAssert);
MAKE_TYPE_FACTORY(ExprStaticAssert,ExprStaticAssert);
MAKE_TYPE_FACTORY(ExprDebug,ExprDebug);
MAKE_TYPE_FACTORY(ExprInvoke,ExprInvoke);
MAKE_TYPE_FACTORY(ExprErase,ExprErase);
MAKE_TYPE_FACTORY(ExprFind,ExprFind);
MAKE_TYPE_FACTORY(ExprKeyExists,ExprKeyExists);
MAKE_TYPE_FACTORY(ExprAscend,ExprAscend);
MAKE_TYPE_FACTORY(ExprCast,ExprCast);
MAKE_TYPE_FACTORY(ExprDelete,ExprDelete);
MAKE_TYPE_FACTORY(ExprVar,ExprVar);
MAKE_TYPE_FACTORY(ExprSwizzle,ExprSwizzle);
MAKE_TYPE_FACTORY(ExprField,ExprField);
MAKE_TYPE_FACTORY(ExprSafeField,ExprSafeField);
MAKE_TYPE_FACTORY(ExprIsVariant,ExprIsVariant);
MAKE_TYPE_FACTORY(ExprAsVariant,ExprAsVariant);
MAKE_TYPE_FACTORY(ExprSafeAsVariant,ExprSafeAsVariant);
MAKE_TYPE_FACTORY(ExprOp1,ExprOp1);
MAKE_TYPE_FACTORY(ExprReturn,ExprReturn);
MAKE_TYPE_FACTORY(ExprYield,ExprYield);
MAKE_TYPE_FACTORY(ExprBreak,ExprBreak);
MAKE_TYPE_FACTORY(ExprContinue,ExprContinue);
MAKE_TYPE_FACTORY(ExprConst,ExprConst);
MAKE_TYPE_FACTORY(ExprFakeContext,ExprFakeContext);
MAKE_TYPE_FACTORY(ExprFakeLineInfo,ExprFakeLineInfo);
MAKE_TYPE_FACTORY(ExprConstPtr,ExprConstPtr);
MAKE_TYPE_FACTORY(ExprConstEnumeration,ExprConstEnumeration);
MAKE_TYPE_FACTORY(ExprConstBitfield,ExprConstBitfield);
MAKE_TYPE_FACTORY(ExprConstInt8,ExprConstInt8);
MAKE_TYPE_FACTORY(ExprConstInt16,ExprConstInt16);
MAKE_TYPE_FACTORY(ExprConstInt64,ExprConstInt64);
MAKE_TYPE_FACTORY(ExprConstInt,ExprConstInt);
MAKE_TYPE_FACTORY(ExprConstInt2,ExprConstInt2);
MAKE_TYPE_FACTORY(ExprConstInt3,ExprConstInt3);
MAKE_TYPE_FACTORY(ExprConstInt4,ExprConstInt4);
MAKE_TYPE_FACTORY(ExprConstUInt8,ExprConstUInt8);
MAKE_TYPE_FACTORY(ExprConstUInt16,ExprConstUInt16);
MAKE_TYPE_FACTORY(ExprConstUInt64,ExprConstUInt64);
MAKE_TYPE_FACTORY(ExprConstUInt,ExprConstUInt);
MAKE_TYPE_FACTORY(ExprConstUInt2,ExprConstUInt2);
MAKE_TYPE_FACTORY(ExprConstUInt3,ExprConstUInt3);
MAKE_TYPE_FACTORY(ExprConstUInt4,ExprConstUInt4);
MAKE_TYPE_FACTORY(ExprConstRange,ExprConstRange);
MAKE_TYPE_FACTORY(ExprConstURange,ExprConstURange);
MAKE_TYPE_FACTORY(ExprConstBool,ExprConstBool);
MAKE_TYPE_FACTORY(ExprConstFloat,ExprConstFloat);
MAKE_TYPE_FACTORY(ExprConstFloat2,ExprConstFloat2);
MAKE_TYPE_FACTORY(ExprConstFloat3,ExprConstFloat3);
MAKE_TYPE_FACTORY(ExprConstFloat4,ExprConstFloat4);
MAKE_TYPE_FACTORY(ExprConstString,ExprConstString);
MAKE_TYPE_FACTORY(ExprConstDouble,ExprConstDouble);
MAKE_TYPE_FACTORY(ExprMakeBlock,ExprMakeBlock);
MAKE_TYPE_FACTORY(ExprMakeGenerator,ExprMakeGenerator);
MAKE_TYPE_FACTORY(ExprMemZero,ExprMemZero);

DAS_BASE_BIND_ENUM(das::SideEffects, SideEffects,
    none, unsafe, userScenario, modifyExternal, accessExternal, modifyArgument,
    modifyArgumentAndExternal, worstDefault, accessGlobal, invoke, inferedSideEffects)


namespace das {

    TypeDeclPtr makeExprGenFlagsFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprGenFlags";
        ft->argNames = { "alwaysSafe", "generated" };
        return ft;
    }

    TypeDeclPtr makeExprFlagsFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprFlags";
        ft->argNames = { "constexpression", "noSideEffects", "noNativeSideEffects" };
        return ft;
    }

    TypeDeclPtr makeExprPrintFlagsFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprPrintFlags";
        ft->argNames = { "topLevel", "argLevel", "bottomLevel" };
        return ft;
    }

    template <typename EXPR>
    struct AstExprAnnotation : ManagedStructureAnnotation <EXPR> {
        AstExprAnnotation(const string & en, ModuleLibrary & ml)
            : ManagedStructureAnnotation<EXPR> (en, ml) {
        }
        void init() {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            this->template addField<DAS_BIND_MANAGED_FIELD(type)>("typeDecl");
            this->template addField<DAS_BIND_MANAGED_FIELD(__rtti)>("__rtti");
            this->addFieldEx ( "genFlags", "genFlags", offsetof(Expression, genFlags), makeExprGenFlagsFlags() );
            this->addFieldEx ( "flags", "flags", offsetof(Expression, flags), makeExprFlagsFlags() );
            this->addFieldEx ( "printFlags", "printFlags", offsetof(Expression, printFlags), makeExprPrintFlagsFlags() );
        }
    };

    template <typename EXPR>
    struct AstExpressionAnnotation : AstExprAnnotation<EXPR> {
        AstExpressionAnnotation(const string & en, ModuleLibrary & ml)
            :  AstExprAnnotation<EXPR> (en, ml) {
            this->init();
        }
    };

    TypeDeclPtr makeExprBlockFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprBlockFlags";
        ft->argNames = { "isClosure", "hasReturn", "copyOnReturn", "moveOnReturn",
            "inTheLoop", "finallyBeforeBody", "finallyDisabled","aotSkipMakeBlock",
            "aotDoNotSkipAnnotationData", "isCollapseable", "needCollapse" };
        return ft;
    }

    struct AstExprBlockAnnotation : AstExpressionAnnotation<ExprBlock> {
        AstExprBlockAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprBlock> ("ExprBlock", ml) {
            addField<DAS_BIND_MANAGED_FIELD(list)>("list");
            addField<DAS_BIND_MANAGED_FIELD(finalList)>("finalList");
            addField<DAS_BIND_MANAGED_FIELD(returnType)>("returnType");
            addField<DAS_BIND_MANAGED_FIELD(arguments)>("arguments");
            addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
            addField<DAS_BIND_MANAGED_FIELD(maxLabelIndex)>("maxLabelIndex");
            addField<DAS_BIND_MANAGED_FIELD(annotations)>("annotations");
            addField<DAS_BIND_MANAGED_FIELD(annotationData)>("annotationData");
            addField<DAS_BIND_MANAGED_FIELD(annotationDataSid)>("annotationDataSid");
            addFieldEx ( "blockFlags", "blockFlags", offsetof(ExprBlock, blockFlags), makeExprBlockFlags() );
        }
    };

    struct AstExprLetAnnotation : AstExpressionAnnotation<ExprLet> {
        AstExprLetAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprLet> ("ExprLet", ml) {
            addField<DAS_BIND_MANAGED_FIELD(variables)>("variables");
            addField<DAS_BIND_MANAGED_FIELD(inScope)>("inScope");
        }
    };

    struct AstExprStringBuilderAnnotation : AstExpressionAnnotation<ExprStringBuilder> {
        AstExprStringBuilderAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprStringBuilder> ("ExprStringBuilder", ml) {
            addField<DAS_BIND_MANAGED_FIELD(elements)>("elements");
        }
    };

    TypeDeclPtr makeMakeFieldDeclFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "MakeFieldDeclFlags";
        ft->argNames = { "moveSemantics", "cloneSemantics" };
        return ft;
    }

    struct AstMakeFieldDeclAnnotation : ManagedStructureAnnotation<MakeFieldDecl> {
        AstMakeFieldDeclAnnotation(ModuleLibrary & ml)
            :  ManagedStructureAnnotation<MakeFieldDecl> ("MakeFieldDecl", ml) {
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(value)>("value");
            addFieldEx ( "flags", "flags", offsetof(MakeFieldDecl, flags), makeMakeFieldDeclFlags() );
        }
    };

    struct AstMakeStructAnnotation : ManagedVectorAnnotation<MakeStruct> {
        AstMakeStructAnnotation(ModuleLibrary & ml)
            :  ManagedVectorAnnotation<MakeStruct> ("MakeStruct", ml) {
        };
    };

    template <typename EXPR>
    struct AstExprLooksLikeCallAnnotation : AstExpressionAnnotation<EXPR> {
        AstExprLooksLikeCallAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExpressionAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            this->template addField<DAS_BIND_MANAGED_FIELD(arguments)>("arguments");
            this->template addField<DAS_BIND_MANAGED_FIELD(argumentsFailedToInfer)>("argumentsFailedToInfer");
        }
    };

    template <typename EXPR>
    struct AstExprCallFuncAnnotation : AstExprLooksLikeCallAnnotation<EXPR> {
        AstExprCallFuncAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExprLooksLikeCallAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(func)>("func");
            this->template addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
        }
    };

    struct AstExprNamedCallAnnotation : AstExpressionAnnotation<ExprNamedCall> {
        AstExprNamedCallAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprNamedCall> ("ExprNamedCall", ml) {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(arguments)>("arguments");
            addField<DAS_BIND_MANAGED_FIELD(argumentsFailedToInfer)>("argumentsFailedToInfer");
        }
    };

    struct AstExprNewAnnotation : AstExprCallFuncAnnotation<ExprNew> {
        AstExprNewAnnotation(ModuleLibrary & ml)
            :  AstExprCallFuncAnnotation<ExprNew> ("ExprNew", ml) {
            addField<DAS_BIND_MANAGED_FIELD(typeexpr)>("typeexpr");
            addField<DAS_BIND_MANAGED_FIELD(initializer)>("initializer");
        }
    };

    struct AstExprCallAnnotation : AstExprCallFuncAnnotation<ExprNew> {
        AstExprCallAnnotation(ModuleLibrary & ml)
            :  AstExprCallFuncAnnotation<ExprNew> ("ExprCall", ml) {
            addField<DAS_BIND_MANAGED_FIELD(typeexpr)>("doesNotNeedSp");
        }
    };

    template <typename EXPR>
    struct AstExprPtr2RefAnnotation : AstExpressionAnnotation<EXPR> {
        AstExprPtr2RefAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExpressionAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
        }
    };

    struct AstExprNullCoalescingAnnotation : AstExprPtr2RefAnnotation<ExprNullCoalescing> {
        AstExprNullCoalescingAnnotation(ModuleLibrary & ml)
            :  AstExprPtr2RefAnnotation<ExprNullCoalescing> ("ExprNullCoalescing", ml) {
            addField<DAS_BIND_MANAGED_FIELD(defaultValue)>("defaultValue");
        }
    };

    TypeDeclPtr makeExprAtFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprAtFlags";
        ft->argNames = { "r2v", "r2cr", "write" };
        return ft;
    }

    template <typename EXPR>
    struct AstExprAtAnnotation : AstExpressionAnnotation<EXPR> {
        AstExprAtAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExpressionAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            this->template addField<DAS_BIND_MANAGED_FIELD(subexpr)>("index");
            this->addFieldEx ( "atFlags", "atFlags", offsetof(ExprAt, atFlags), makeExprAtFlags() );
        }
    };

    struct AstExprIsAnnotation : AstExpressionAnnotation<ExprIs> {
        AstExprIsAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprIs> ("ExprIs", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(typeexpr)>("typeexpr");
        }
    };

    template <typename EXPR>
    struct AstExprOpAnnotation : AstExpressionAnnotation<EXPR> {
        AstExprOpAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExpressionAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(op)>("op");
        }
    };

    template <typename EXPR>
    struct AstExprOp2Annotation : AstExprOpAnnotation<EXPR> {
        AstExprOp2Annotation(const string & na, ModuleLibrary & ml)
            :  AstExprOpAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(left)>("left");
            this->template addField<DAS_BIND_MANAGED_FIELD(right)>("right");
        }
    };

    struct AstExprOp3Annotation : AstExprOpAnnotation<ExprOp3> {
        AstExprOp3Annotation(ModuleLibrary & ml)
            :  AstExprOpAnnotation<ExprOp3> ("ExprOp3", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(left)>("left");
            addField<DAS_BIND_MANAGED_FIELD(right)>("right");
        }
    };

    struct AstExprCopyAnnotation : AstExprOp2Annotation<ExprCopy> {
        AstExprCopyAnnotation(ModuleLibrary & ml)
            :  AstExprOp2Annotation<ExprCopy> ("ExprCopy", ml) {
            addField<DAS_BIND_MANAGED_FIELD(takeOverRightStack)>("takeOverRightStack");
        }
    };

    struct AstExprWithAnnotation : AstExpressionAnnotation<ExprWith> {
        AstExprWithAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprWith> ("ExprWith", ml) {
            addField<DAS_BIND_MANAGED_FIELD(with)>("with");
            addField<DAS_BIND_MANAGED_FIELD(body)>("body");
        }
    };

    struct AstExprWhileAnnotation : AstExpressionAnnotation<ExprWhile> {
        AstExprWhileAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprWhile> ("ExprWhile", ml) {
            addField<DAS_BIND_MANAGED_FIELD(cond)>("cond");
            addField<DAS_BIND_MANAGED_FIELD(body)>("body");
        }
    };

    struct AstExprTryCatchAnnotation : AstExpressionAnnotation<ExprTryCatch> {
        AstExprTryCatchAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprTryCatch> ("ExprTryCatch", ml) {
            addField<DAS_BIND_MANAGED_FIELD(try_block)>("try_block");
            addField<DAS_BIND_MANAGED_FIELD(catch_block)>("catch_block");
        }
    };

    struct AstExprForAnnotation : AstExpressionAnnotation<ExprFor> {
        AstExprForAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprFor> ("ExprFor", ml) {
            addField<DAS_BIND_MANAGED_FIELD(iterators)>("iterators");
            addField<DAS_BIND_MANAGED_FIELD(iteratorsAt)>("iteratorsAt");
            addField<DAS_BIND_MANAGED_FIELD(iteratorVariables)>("iteratorVariables");
            addField<DAS_BIND_MANAGED_FIELD(sources)>("sources");
            addField<DAS_BIND_MANAGED_FIELD(body)>("body");
        }
    };

    struct AstExprIfThenElseAnnotation : AstExpressionAnnotation<ExprIfThenElse> {
        AstExprIfThenElseAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprIfThenElse> ("ExprIfThenElse", ml) {
            addField<DAS_BIND_MANAGED_FIELD(cond)>("cond");
            addField<DAS_BIND_MANAGED_FIELD(if_true)>("if_true");
            addField<DAS_BIND_MANAGED_FIELD(if_false)>("if_false");
            addField<DAS_BIND_MANAGED_FIELD(isStatic)>("isStatic");
        }
    };

    TypeDeclPtr makeExprMakeLocalFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprMakeLocalFlags";
        ft->argNames = { "useStackRef", "useCMRES", "doesNotNeedSp",
            "doesNotNeedInit", "initAllFields" };
        return ft;
    }

    template <typename EXPR>
    struct AstExprMakeLocalAnnotation : AstExpressionAnnotation<EXPR> {
        AstExprMakeLocalAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExpressionAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(makeType)>("makeType");
            this->template addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
            this->template addField<DAS_BIND_MANAGED_FIELD(extraOffset)>("extraOffset");
            this->addFieldEx ( "makeFlags", "makeFlags", offsetof(ExprMakeLocal, makeFlags), makeExprMakeLocalFlags() );
        }
    };

    TypeDeclPtr makeExprMakeStructFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprMakeStructFlags";
        ft->argNames = { "useInitializer", "isNewHandle" };
        return ft;
    }

    struct AstExprMakeStructAnnotation : AstExprMakeLocalAnnotation<ExprMakeStruct> {
        AstExprMakeStructAnnotation(ModuleLibrary & ml)
            :  AstExprMakeLocalAnnotation<ExprMakeStruct> ("ExprMakeStruct", ml) {
            addField<DAS_BIND_MANAGED_FIELD(structs)>("structs");
            this->addFieldEx ( "makeStructFlags", "makeStructFlags", offsetof(ExprMakeStruct, makeStructFlags), makeExprMakeStructFlags() );
        }
    };

    struct AstExprMakeVariantAnnotation : AstExprMakeLocalAnnotation<ExprMakeVariant> {
        AstExprMakeVariantAnnotation(ModuleLibrary & ml)
            :  AstExprMakeLocalAnnotation<ExprMakeVariant> ("ExprMakeVariant", ml) {
            addField<DAS_BIND_MANAGED_FIELD(variants)>("variants");
        }
    };

    template <typename EXPR>
    struct AstExprMakeArrayAnnotation : AstExprMakeLocalAnnotation<EXPR> {
        AstExprMakeArrayAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExprMakeLocalAnnotation<EXPR> (na, ml) {
                using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(recordType)>("recordType");
            this->template addField<DAS_BIND_MANAGED_FIELD(values)>("values");
        }
    };

    struct AstExprMakeTupleAnnotation : AstExprMakeArrayAnnotation<ExprMakeTuple> {
        AstExprMakeTupleAnnotation(ModuleLibrary & ml)
            :  AstExprMakeArrayAnnotation<ExprMakeTuple> ("ExprMakeTuple", ml) {
            addField<DAS_BIND_MANAGED_FIELD(isKeyValue)>("isKeyValue");
        }
    };

    struct AstExprArrayComprehensionAnnotation : AstExpressionAnnotation<ExprArrayComprehension> {
        AstExprArrayComprehensionAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprArrayComprehension> ("ExprArrayComprehension", ml) {
            addField<DAS_BIND_MANAGED_FIELD(exprFor)>("exprFor");
            addField<DAS_BIND_MANAGED_FIELD(exprWhere)>("exprWhere");
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(generatorSyntax)>("generatorSyntax");
        }
    };

    struct AstTypeInfoMacroAnnotation : ManagedStructureAnnotation<TypeInfoMacro,false> {
        AstTypeInfoMacroAnnotation(ModuleLibrary & ml)
            :  ManagedStructureAnnotation<TypeInfoMacro,false> ("TypeInfoMacro", ml) {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
        }
    };

    struct AstExprTypeInfoAnnotation : AstExpressionAnnotation<ExprTypeInfo> {
        AstExprTypeInfoAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprTypeInfo> ("ExprTypeInfo", ml) {
            addField<DAS_BIND_MANAGED_FIELD(trait)>("trait");
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(typeexpr)>("typeexpr");
            addField<DAS_BIND_MANAGED_FIELD(subtrait)>("subtrait");
            addField<DAS_BIND_MANAGED_FIELD(extratrait)>("extratrait");
            addField<DAS_BIND_MANAGED_FIELD(macro)>("macro");
        }
    };

    struct AstExprLabelAnnotation : AstExpressionAnnotation<ExprLabel> {
        AstExprLabelAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprLabel> ("ExprLabel", ml) {
            addField<DAS_BIND_MANAGED_FIELD(label)>("labelName","label");
            addField<DAS_BIND_MANAGED_FIELD(comment)>("comment");
        }
    };

    struct AstExprGotoAnnotation : AstExpressionAnnotation<ExprGoto> {
        AstExprGotoAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprGoto> ("ExprGoto", ml) {
            addField<DAS_BIND_MANAGED_FIELD(label)>("labelName","label");
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
        }
    };

    struct AstExprRef2ValueAnnotation : AstExpressionAnnotation<ExprRef2Value> {
        AstExprRef2ValueAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprRef2Value> ("ExprRef2Value", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
        }
    };

    struct AstExprRef2PtrAnnotation : AstExpressionAnnotation<ExprRef2Ptr> {
        AstExprRef2PtrAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprRef2Ptr> ("ExprRef2Ptr", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
        }
    };

    struct AstExprAddrAnnotation : AstExpressionAnnotation<ExprAddr> {
        AstExprAddrAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprAddr> ("ExprAddr", ml) {
            addField<DAS_BIND_MANAGED_FIELD(target)>("target");
            addField<DAS_BIND_MANAGED_FIELD(funcType)>("funcType");
            addField<DAS_BIND_MANAGED_FIELD(func)>("func");
        }
    };

    template <typename EXPR>
    struct AstExprLikeCallAnnotation : AstExprLooksLikeCallAnnotation<EXPR> {
        AstExprLikeCallAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExprLooksLikeCallAnnotation<EXPR> (na, ml) {
        }
    };

    struct AstExprAssertAnnotation : AstExprLikeCallAnnotation<ExprAssert> {
        AstExprAssertAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprAssert> ("ExprAssert", ml) {
            addField<DAS_BIND_MANAGED_FIELD(isVerify)>("isVerify");
        }
    };

    struct AstExprStaticAssertAnnotation : AstExprLikeCallAnnotation<ExprStaticAssert> {
        AstExprStaticAssertAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprStaticAssert> ("ExprStaticAssert", ml) {
        }
    };

    struct AstExprDebugAnnotation : AstExprLikeCallAnnotation<ExprDebug> {
        AstExprDebugAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprDebug> ("ExprDebug", ml) {
        }
    };

    struct AstExprInvokeAnnotation : AstExprLikeCallAnnotation<ExprInvoke> {
        AstExprInvokeAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprInvoke> ("ExprInvoke", ml) {
            addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
            addField<DAS_BIND_MANAGED_FIELD(doesNotNeedSp)>("doesNotNeedSp");
        }
    };

    struct AstExprEraseAnnotation : AstExprLikeCallAnnotation<ExprErase> {
        AstExprEraseAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprErase> ("ExprErase", ml) {
        }
    };

    struct AstExprFindAnnotation : AstExprLikeCallAnnotation<ExprFind> {
        AstExprFindAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprFind> ("ExprFind", ml) {
        }
    };

    struct AstExprKeyExistsAnnotation : AstExprLikeCallAnnotation<ExprKeyExists> {
        AstExprKeyExistsAnnotation(ModuleLibrary & ml)
            :  AstExprLikeCallAnnotation<ExprKeyExists> ("ExprKeyExists", ml) {
        }
    };

    TypeDeclPtr makeExprAscendFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprAscendFlags";
        ft->argNames = { "useStackRef", "needTypeInfo" };
        return ft;
    }

    struct AstExprAscendAnnotation : AstExpressionAnnotation<ExprAscend> {
        AstExprAscendAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprAscend> ("ExprAscend", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(ascType)>("ascType");
            addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
            addFieldEx ( "ascendFlags", "ascendFlags", offsetof(ExprAscend, ascendFlags), makeExprAscendFlags() );
        }
    };

    TypeDeclPtr makeExprCastFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprCastFlags";
        ft->argNames = { "upcastCast", "reinterpretCast" };
        return ft;
    }

    struct AstExprCastAnnotation : AstExpressionAnnotation<ExprCast> {
        AstExprCastAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprCast> ("ExprCast", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(castType)>("castType");
            addFieldEx ( "castFlags", "castFlags", offsetof(ExprCast, castFlags), makeExprCastFlags() );
        }
    };

    struct AstExprDeleteAnnotation : AstExpressionAnnotation<ExprDelete> {
        AstExprDeleteAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprDelete> ("ExprDelete", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(native)>("native");
        }
    };

    TypeDeclPtr makeExprVarFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprVarFlags";
        ft->argNames = { "local", "argument", "block",
            "thisBlock", "r2v", "r2cr", "write" };
        return ft;
    }

    struct AstExprVarAnnotation : AstExpressionAnnotation<ExprVar> {
        AstExprVarAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprVar> ("ExprVar", ml) {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(variable)>("variable");
            addField<DAS_BIND_MANAGED_FIELD(pBlock)>("pBlock");
            addField<DAS_BIND_MANAGED_FIELD(argumentIndex)>("argumentIndex");
            addFieldEx ( "varFlags", "varFlags", offsetof(ExprVar, varFlags), makeExprVarFlags() );
        }
    };

    TypeDeclPtr makeExprFieldDerefFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprFieldDerefFlags";
        ft->argNames = { "unsafeDeref", "ignoreCaptureConst" };
        return ft;
    }

    TypeDeclPtr makeExprFieldFieldFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprFieldFieldFlags";
        ft->argNames = { "r2v", "r2cr", "write" };
        return ft;
    }

    template <typename EXPR>
    struct AstExprFieldAnnotation : AstExpressionAnnotation<EXPR> {
        AstExprFieldAnnotation(const string & na, ModuleLibrary & ml)
            :  AstExpressionAnnotation<EXPR> (na, ml) {
            using ManagedType = EXPR;
            this->template addField<DAS_BIND_MANAGED_FIELD(value)>("value");
            this->template addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            this->template addField<DAS_BIND_MANAGED_FIELD(atField)>("atField");
            this->template addField<DAS_BIND_MANAGED_FIELD(field)>("field");
            this->template addField<DAS_BIND_MANAGED_FIELD(fieldIndex)>("fieldIndex");
            this->template addField<DAS_BIND_MANAGED_FIELD(annotation)>("annotation");
            this->addFieldEx ( "derefFlags", "derefFlags", offsetof(ExprField, derefFlags), makeExprFieldDerefFlags() );
            this->addFieldEx ( "fieldFlags", "fieldFlags", offsetof(ExprField, fieldFlags), makeExprFieldFieldFlags() );
        }
    };

    struct AstExprSafeFieldAnnotation : AstExprFieldAnnotation<ExprSafeField> {
        AstExprSafeFieldAnnotation(ModuleLibrary & ml)
            :  AstExprFieldAnnotation<ExprSafeField> ("ExprSafeField", ml) {
            addField<DAS_BIND_MANAGED_FIELD(skipQQ)>("skipQQ");
        }
    };

    TypeDeclPtr makeExprSwizzleFieldFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprSwizzleFieldFlags";
        ft->argNames = { "r2v", "r2cr", "write" };
        return ft;
    }

    struct AstExprSwizzleAnnotation : AstExpressionAnnotation<ExprSwizzle> {
        AstExprSwizzleAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprSwizzle> ("ExprSwizzle", ml) {
            addField<DAS_BIND_MANAGED_FIELD(value)>("value");
            addField<DAS_BIND_MANAGED_FIELD(mask)>("mask");
            addField<DAS_BIND_MANAGED_FIELD(fields)>("fields");
            addFieldEx ( "fieldFlags", "fieldFlags", offsetof(ExprSwizzle, fieldFlags), makeExprSwizzleFieldFlags() );
        }
    };

    struct AstExprSafeAsVariantAnnotation : AstExprFieldAnnotation<ExprSafeField> {
        AstExprSafeAsVariantAnnotation(ModuleLibrary & ml)
            :  AstExprFieldAnnotation<ExprSafeField> ("ExprSafeAsVariant", ml) {
            addField<DAS_BIND_MANAGED_FIELD(skipQQ)>("skipQQ");
        }
    };

    struct AstExprOp1Annotation : AstExprOpAnnotation<ExprOp1> {
        AstExprOp1Annotation(ModuleLibrary & ml)
            :  AstExprOpAnnotation<ExprOp1> ("ExprOp1", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
        }
    };

    TypeDeclPtr makeExprYieldFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprYieldFlags";
        ft->argNames = { "moveSemantics" };
        return ft;
    }

    struct AstExprYieldAnnotation : AstExpressionAnnotation<ExprYield> {
        AstExprYieldAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprYield> ("ExprYield", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addFieldEx ( "returnFlags", "returnFlags", offsetof(ExprYield, returnFlags), makeExprYieldFlags() );
        }
    };

    TypeDeclPtr makeExprReturnFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprReturnFlags";
        ft->argNames = { "moveSemantics", "returnReference", "returnInBlock",
            "takeOverRightStack", "returnCallCMRES", "returnCMRES", "fromYield" };
        return ft;
    }

    struct AstExprReturnAnnotation : AstExpressionAnnotation<ExprReturn> {
        AstExprReturnAnnotation(ModuleLibrary & ml)
            :  AstExpressionAnnotation<ExprReturn> ("ExprReturn", ml) {
            addField<DAS_BIND_MANAGED_FIELD(subexpr)>("subexpr");
            addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
            addField<DAS_BIND_MANAGED_FIELD(refStackTop)>("refStackTop");
            addField<DAS_BIND_MANAGED_FIELD(block)>("block");
            addFieldEx ( "returnFlags", "returnFlags", offsetof(ExprReturn, returnFlags), makeExprReturnFlags() );
        }
    };

     // TYPE STUFF

    struct AstEnumerationAnnotation : ManagedStructureAnnotation <Enumeration> {
        AstEnumerationAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("Enumeration", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(cppName)>("cppName");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(list)>("list");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            addField<DAS_BIND_MANAGED_FIELD(external)>("external");
            addField<DAS_BIND_MANAGED_FIELD(baseType)>("baseType");
        }
    };

    TypeDeclPtr makeTypeDeclFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "TypeDeclFlags";
        ft->argNames = { "ref", "constant", "temporary", "implicit",
            "removeRef", "removeConstant", "removeDim",
            "removeTemporary", "explicitConst", "aotAlias", "smartPtr" };
        return ft;
    }

    struct AstTypeDeclAnnnotation : ManagedStructureAnnotation <TypeDecl> {
        AstTypeDeclAnnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("TypeDecl", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(baseType)>("baseType");
            addField<DAS_BIND_MANAGED_FIELD(structType)>("structType");
            addField<DAS_BIND_MANAGED_FIELD(enumType)>("enumType");
            addField<DAS_BIND_MANAGED_FIELD(annotation)>("annotation");
            addField<DAS_BIND_MANAGED_FIELD(firstType)>("firstType");
            addField<DAS_BIND_MANAGED_FIELD(secondType)>("secondType");
            addField<DAS_BIND_MANAGED_FIELD(argTypes)>("argTypes");
            addField<DAS_BIND_MANAGED_FIELD(argNames)>("argNames");
            addField<DAS_BIND_MANAGED_FIELD(dim)>("dim");
            addField<DAS_BIND_MANAGED_FIELD(dimExpr)>("dimExpr");
            addFieldEx ( "flags", "flags", offsetof(TypeDecl, flags), makeTypeDeclFlags() );
            addField<DAS_BIND_MANAGED_FIELD(alias)>("alias");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            // properties
            addProperty<DAS_BIND_MANAGED_PROP(isVoid)>("isVoid","isVoid");
            addProperty<DAS_BIND_MANAGED_PROP(isExprType)>("isExprType","isExprType");
        }
    };

    TypeDeclPtr makeFieldDeclarationFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "FieldDeclarationFlags";
        ft->argNames = { "moveSemantics", "parentType", "capturedConstant", "generated" };
        return ft;
    }

    struct AstFieldDeclarationAnnotation : ManagedStructureAnnotation<Structure::FieldDeclaration> {
        AstFieldDeclarationAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("FieldDeclaration", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(type)>("typeDecl");
            addField<DAS_BIND_MANAGED_FIELD(init)>("init");
            addField<DAS_BIND_MANAGED_FIELD(annotation)>("annotation");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
            addFieldEx ( "flags", "flags", offsetof(Structure::FieldDeclaration, flags), makeFieldDeclarationFlags() );
        }
    };

    TypeDeclPtr makeStructureFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "StructureFlags";
        ft->argNames = { "isClass", "genCtor", "cppLayout", "cppLayoutNotPod",
            "generated", "persistent" };
        return ft;
    }

    struct AstStructureAnnotation : ManagedStructureAnnotation<Structure> {
        AstStructureAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("Structure", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(fields)>("fields");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            addField<DAS_BIND_MANAGED_FIELD(parent)>("parent");
            addField<DAS_BIND_MANAGED_FIELD(annotations)>("annotations");
            addFieldEx ( "flags", "flags", offsetof(Structure, flags), makeStructureFlags() );
        }
    };

    TypeDeclPtr makeFunctionFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "FunctionFlags";
        ft->argNames = { "builtIn", "policyBased", "callBased", "interopFn",
            "hasRetur", "copyOnReturn", "moveOnReturn", "exports", "init",
            "addr", "used", "fastCall", "knownSideEffects", "hasToRunAtCompileTime",
            "unsafe", "unsafeOperation", "unsafeDeref", "hasMakeBlock", "aotNeedPrologue",
            "noAot", "aotHybrid", "aotTemplate", "generated", "privateFunction",
            "generatorFunction", "lambda"
        };
        return ft;
    }

    TypeDeclPtr makeFunctionSideEffectFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "FunctionSideEffectFlags";
        ft->argNames = { "unsafe", "userScenario","modifyExternal",
            "modifyArgument","accessGlobal","invoke"
        };
        return ft;
    }

    struct AstInferHistoryAnnotation : ManagedStructureAnnotation<Function::InferHistory> {
        AstInferHistoryAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("InferHistory", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(func)>("func");
        }
    };

    struct AstFunctionAnnotation : ManagedStructureAnnotation<Function> {
        AstFunctionAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("Function", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(annotations)>("annotations");
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(arguments)>("arguments");
            addField<DAS_BIND_MANAGED_FIELD(result)>("result");
            addField<DAS_BIND_MANAGED_FIELD(body)>("body");
            addField<DAS_BIND_MANAGED_FIELD(index)>("index");
            addField<DAS_BIND_MANAGED_FIELD(totalStackSize)>("totalStackSize");
            addField<DAS_BIND_MANAGED_FIELD(totalGenLabel)>("totalGenLabel");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(atDecl)>("atDecl");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            // addField<DAS_BIND_MANAGED_FIELD(useFunctions)>("useFunctions");
            // addField<DAS_BIND_MANAGED_FIELD(useFunctions)>("useGlobalVariables");
            // use global v
            addFieldEx ( "flags", "flags",
                offsetof(Function, flags), makeFunctionFlags() );
            addFieldEx ( "sideEffectFlags", "sideEffectFlags",
                offsetof(Function, sideEffectFlags), makeFunctionSideEffectFlags() );
            addField<DAS_BIND_MANAGED_FIELD(inferStack)>("inferStack");
            addField<DAS_BIND_MANAGED_FIELD(fromGeneric)>("fromGeneric");
            addField<DAS_BIND_MANAGED_FIELD(hash)>("hash");
            addField<DAS_BIND_MANAGED_FIELD(aotHash)>("aotHash");
        }
    };

    TypeDeclPtr makeVariableFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "VariableFlags";
        ft->argNames = { "init_via_move", "init_via_clone", "used", "aliasCMRES",
            "marked_used", "global_shared", "do_not_delete", "generated" };
        return ft;
    }

    TypeDeclPtr makeVariableAccessFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "VariableAccessFlags";
        ft->argNames = { "access_extern", "access_get", "access_ref",
            "access_init", "access_pass" };
        return ft;
    }

    struct AstVariableAnnotation : ManagedStructureAnnotation<Variable> {
        AstVariableAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("Variable", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(type)>("typeDecl");
            addField<DAS_BIND_MANAGED_FIELD(init)>("init");
            addField<DAS_BIND_MANAGED_FIELD(source)>("source");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(index)>("index");
            addField<DAS_BIND_MANAGED_FIELD(stackTop)>("stackTop");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            // addField<DAS_BIND_MANAGED_FIELD(useFunctions)>("useFunctions");
            // addField<DAS_BIND_MANAGED_FIELD(useFunctions)>("useGlobalVariables");
            addField<DAS_BIND_MANAGED_FIELD(initStackSize)>("initStackSize");
            addFieldEx ( "flags", "flags", offsetof(Variable, flags), makeVariableFlags() );
            addFieldEx ( "access_flags", "access_flags", offsetof(Variable, access_flags), makeVariableAccessFlags() );
            addField<DAS_BIND_MANAGED_FIELD(annotation)>("annotation");
            // properties
            addProperty<DAS_BIND_MANAGED_PROP(isAccessUnused)>("isAccessUnused","isAccessUnused");
        }
    };

    struct SimNode_AstGetTypeDecl : SimNode_CallBase {
        DAS_PTR_NODE;
        SimNode_AstGetTypeDecl ( const LineInfo & at, const TypeDeclPtr & d )
            : SimNode_CallBase(at) {
            typeExpr = d.get();
        }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            V_OP(AstGetTypeDecl);
            V_ARG(typeExpr->getMangledName().c_str());
            V_END();
        }
        __forceinline char * compute(Context &) {
            DAS_PROFILE_NODE
            return (char *) typeExpr;
        }
        TypeDecl *  typeExpr;   // requires RTTI
    };

    struct SimNode_AstGetExpression : SimNode_CallBase {
        DAS_PTR_NODE;
        SimNode_AstGetExpression ( const LineInfo & at, const ExpressionPtr & e, char * d )
            : SimNode_CallBase(at) {
            expr = e.get();
            descr = d;
        }
        virtual SimNode * copyNode ( Context & context, NodeAllocator * code ) override {
            auto that = (SimNode_AstGetExpression *) SimNode::copyNode(context, code);
            that->descr = code->allocateName(descr);
            return that;
        }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            V_OP(AstGetExpression);
            V_ARG(descr);
            V_END();
        }
        __forceinline char * compute(Context &) {
            DAS_PROFILE_NODE
            return (char *) expr;
        }
        Expression *  expr;   // requires RTTI
        char *        descr;
    };

    struct SimNode_AstGetFunction : SimNode_CallBase {
        DAS_PTR_NODE;
        SimNode_AstGetFunction ( const LineInfo & at, Function * f )
            : SimNode_CallBase(at) {
            func = f;
        }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            V_OP(AstGetTypeDecl);
            V_ARG(func->getMangledName().c_str());
            V_END();
        }
        __forceinline char * compute(Context &) {
            DAS_PROFILE_NODE
            return (char *) func;
        }
        Function *  func;   // requires RTTI
    };

    struct AstTypeDeclMacro : TypeInfoMacro {
        AstTypeDeclMacro() : TypeInfoMacro("ast_typedecl") {}
        virtual TypeDeclPtr getAstType ( ModuleLibrary & lib, const ExpressionPtr &, string & ) override {
            return typeFactory<smart_ptr<TypeDecl>>::make(lib);
        }
        virtual SimNode * simluate ( Context * context, const ExpressionPtr & expr, string & ) override {
            auto exprTypeInfo = static_pointer_cast<ExprTypeInfo>(expr);
            return context->code->makeNode<SimNode_AstGetTypeDecl>(expr->at, exprTypeInfo->typeexpr);
        }
        virtual bool noAot ( const ExpressionPtr & ) const override {
            return true;
        }
    };

    struct AstExpressionMacro : TypeInfoMacro {
        AstExpressionMacro() : TypeInfoMacro("ast_expression") {}
        virtual TypeDeclPtr getAstType ( ModuleLibrary & lib, const ExpressionPtr &, string & ) override {
            return typeFactory<smart_ptr<Expression>>::make(lib);
        }
        virtual SimNode * simluate ( Context * context, const ExpressionPtr & expr, string & errors ) override {
            auto exprTypeInfo = static_pointer_cast<ExprTypeInfo>(expr);
            if ( exprTypeInfo->subexpr ) {
                TextWriter ss;
                ss << *exprTypeInfo->subexpr;
                char * descr = context->code->allocateName(ss.str());
                return context->code->makeNode<SimNode_AstGetExpression>(expr->at, exprTypeInfo->subexpr, descr);
            } else {
                errors = "ast_expression requires expression, not just type";
                return nullptr;
            }
        }
        virtual bool noAot ( const ExpressionPtr & ) const override {
            return true;
        }
    };

    struct AstFunctionMacro : TypeInfoMacro {
        AstFunctionMacro() : TypeInfoMacro("ast_function") {}
        virtual TypeDeclPtr getAstType ( ModuleLibrary & lib, const ExpressionPtr &, string & ) override {
            return typeFactory<smart_ptr<Function>>::make(lib);
        }
        virtual SimNode * simluate ( Context * context, const ExpressionPtr & expr, string & errors ) override {
            auto exprTypeInfo = static_pointer_cast<ExprTypeInfo>(expr);
            if ( exprTypeInfo->subexpr && exprTypeInfo->subexpr->rtti_isAddr() ) {
                auto exprAddr = static_pointer_cast<ExprAddr>(exprTypeInfo->subexpr);
                return context->code->makeNode<SimNode_AstGetFunction>(expr->at, exprAddr->func);
            } else {
                errors = "ast_expression requires @@func expression";
                return nullptr;
            }
        }
        virtual bool noAot ( const ExpressionPtr & ) const override {
            return true;
        }
    };

    // TODO:
    //  optimize multiple-adapt-calls
    Func adapt ( const char * funcName, char * pClass, const StructInfo * info ) {
        for ( uint32_t i=0; i!=info->count; ++i ) {
            if ( strcmp(info->fields[i]->name,funcName)==0 ) {
                return *(Func *)(pClass + info->fields[i]->offset);
            }
        }
        DAS_ASSERTF(0,"mapping %s not found. not fully implemented dervied class %s", funcName, info->name);
        return 0;
    }

#define FN_PREVISIT(WHAT)  fnPreVisit##WHAT
#define FN_VISIT(WHAT)      fnVisit##WHAT

#define IMPL_PREVISIT1(WHAT,WHATTYPE) \
    if ( FN_PREVISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>> \
            (context,FN_PREVISIT(WHAT),classPtr,expr); \
    }

#define IMPL_PREVISIT2(WHAT,WHATTYPE,ARG1T,ARG1) \
    if ( FN_PREVISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T> \
            (context,FN_PREVISIT(WHAT),classPtr,expr,ARG1); \
    }

#define IMPL_PREVISIT3(WHAT,WHATTYPE,ARG1T,ARG1,ARG2T,ARG2) \
    if ( FN_PREVISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T,ARG2T> \
            (context,FN_PREVISIT(WHAT),classPtr,expr,ARG1,ARG2); \
    }

#define IMPL_PREVISIT4(WHAT,WHATTYPE,ARG1T,ARG1,ARG2T,ARG2,ARG3T,ARG3) \
    if ( FN_PREVISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T,ARG2T,ARG3T> \
            (context,FN_PREVISIT(WHAT),classPtr,expr,ARG1,ARG2,ARG3); \
    }

#define IMPL_PREVISIT(WHAT) IMPL_PREVISIT1(WHAT,WHAT)

#define IMPL_VISIT_VOID1(WHAT,WHATTYPE) \
    if ( FN_VISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>> \
            (context,FN_VISIT(WHAT),classPtr,expr); \
    }

#define IMPL_VISIT_VOID2(WHAT,WHATTYPE,ARG1T,ARG1) \
    if ( FN_VISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T> \
            (context,FN_VISIT(WHAT),classPtr,expr,ARG1); \
    }

#define IMPL_VISIT_VOID3(WHAT,WHATTYPE,ARG1T,ARG1,ARG2T,ARG2) \
    if ( FN_VISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T,ARG2T> \
            (context,FN_VISIT(WHAT),classPtr,expr,ARG1,ARG2); \
    }

#define IMPL_VISIT_VOID4(WHAT,WHATTYPE,ARG1T,ARG1,ARG2T,ARG2,ARG3T,ARG3) \
    if ( FN_VISIT(WHAT) ) { \
        das_invoke_function<void>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T,ARG2T,ARG3T> \
            (context,FN_VISIT(WHAT),classPtr,expr,ARG1,ARG2,ARG3); \
    }

#define IMPL_VISIT1(WHAT,WHATTYPE,RETTYPE,RETVALUE) \
    if ( FN_VISIT(WHAT) ) { \
        return das_invoke_function<smart_ptr_raw<RETTYPE>>::invoke<void *,smart_ptr<WHATTYPE>> \
            (context,FN_VISIT(WHAT),classPtr,expr); \
    } else { \
        return RETVALUE; \
    }

#define IMPL_VISIT2(WHAT,WHATTYPE,RETTYPE,RETVALUE,ARG1T,ARG1) \
    if ( FN_VISIT(WHAT) ) { \
        return das_invoke_function<smart_ptr_raw<RETTYPE>>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T> \
            (context,FN_VISIT(WHAT),classPtr,expr,ARG1); \
    } else { \
        return RETVALUE; \
    }

#define IMPL_VISIT3(WHAT,WHATTYPE,RETTYPE,RETVALUE,ARG1T,ARG1,ARG2T,ARG2) \
    if ( FN_VISIT(WHAT) ) { \
        return das_invoke_function<smart_ptr_raw<RETTYPE>>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T,ARG2T> \
            (context,FN_VISIT(WHAT),classPtr,expr,ARG1,ARG2); \
    } else { \
        return RETVALUE; \
    }

#define IMPL_VISIT4(WHAT,WHATTYPE,RETTYPE,RETVALUE,ARG1T,ARG1,ARG2T,ARG2,ARG3T,ARG3) \
    if ( FN_VISIT(WHAT) ) { \
        return das_invoke_function<smart_ptr_raw<RETTYPE>>::invoke<void *,smart_ptr<WHATTYPE>,ARG1T,ARG2T,ARG3T> \
            (context,FN_VISIT(WHAT),classPtr,expr,ARG1,ARG2,ARG3); \
    } else { \
        return RETVALUE; \
    }


#define IMPL_VISIT(WHAT) IMPL_VISIT1(WHAT,WHAT,WHAT,expr)

#define IMPL_VISIT_VOID(WHAT) IMPL_VISIT_VOID1(WHAT,WHAT)

#define DECL_VISIT(WHAT) \
    Func        FN_PREVISIT(WHAT); \
    Func        FN_VISIT(WHAT);

#define IMPL_ADAPT(WHAT) \
    FN_PREVISIT(WHAT) = adapt("preVisit" #WHAT,pClass,info); \
    FN_VISIT(WHAT) = adapt("visit" #WHAT,pClass,info);

#define IMPL_BIND_EXPR(WHAT) \
    virtual void preVisit ( WHAT * expr ) override \
        { IMPL_PREVISIT(WHAT); } \
    virtual ExpressionPtr visit ( WHAT * expr ) override \
        { IMPL_VISIT(WHAT); }

    class VisitorAdapter : public Visitor {
    public:
        VisitorAdapter ( char * pClass, const StructInfo * info, Context * ctx ) {
            context = ctx;
            classPtr = pClass;
            // adapt
            IMPL_ADAPT(Program);
            FN_PREVISIT(ProgramBody) = adapt("preVisitProgramBody",pClass,info);
            IMPL_ADAPT(TypeDecl);
            IMPL_ADAPT(Expression);
            IMPL_ADAPT(Alias);
            IMPL_ADAPT(Enumeration);
            IMPL_ADAPT(EnumerationValue);
            IMPL_ADAPT(Structure);
            IMPL_ADAPT(StructureField);
            IMPL_ADAPT(Function);
            IMPL_ADAPT(FunctionArgument);
            IMPL_ADAPT(FunctionArgumentInit);
            IMPL_ADAPT(FunctionBody);
            IMPL_ADAPT(ExprBlock);
            IMPL_ADAPT(ExprBlockArgument);
            IMPL_ADAPT(ExprBlockArgumentInit);
            IMPL_ADAPT(ExprBlockExpression);
            IMPL_ADAPT(ExprBlockFinal);
            IMPL_ADAPT(ExprBlockFinalExpression);
            IMPL_ADAPT(ExprLet);
            IMPL_ADAPT(ExprLetVariable);
            IMPL_ADAPT(ExprLetVariableInit);
            IMPL_ADAPT(GlobalLet);
            IMPL_ADAPT(GlobalLetVariable);
            IMPL_ADAPT(GlobalLetVariableInit);
            IMPL_ADAPT(ExprStringBuilder);
            IMPL_ADAPT(ExprStringBuilderElement);
            IMPL_ADAPT(ExprNew);
            IMPL_ADAPT(ExprNewArgument);
            IMPL_ADAPT(ExprNamedCall);
            IMPL_ADAPT(ExprNamedCallArgument);
            IMPL_ADAPT(ExprCall);
            IMPL_ADAPT(ExprCallArgument);
            IMPL_ADAPT(ExprLooksLikeCall);
            IMPL_ADAPT(ExprLooksLikeCallArgument);
            IMPL_ADAPT(ExprNullCoalescing);
            FN_PREVISIT(ExprNullCoalescingDefault) = adapt("preVisitExprNullCoalescingDefault",pClass,info);
            IMPL_ADAPT(ExprAt);
            FN_PREVISIT(ExprAtIndex) = adapt("preVisitExprAtIndex",pClass,info);
            IMPL_ADAPT(ExprSafeAt);
            FN_PREVISIT(ExprSafeAtIndex) = adapt("preVisitExprSafeAtIndex",pClass,info);
            IMPL_ADAPT(ExprIs);
            FN_PREVISIT(ExprIsType) = adapt("preVisitExprIsType",pClass,info);
            IMPL_ADAPT(ExprOp2);
            FN_PREVISIT(ExprOp2Right) = adapt("preVisitExprOp2Right",pClass,info);
            IMPL_ADAPT(ExprOp3);
            FN_PREVISIT(ExprOp3Left) = adapt("preVisitExprOp3Left",pClass,info);
            FN_PREVISIT(ExprOp3Right) = adapt("preVisitExprOp3Right",pClass,info);
            IMPL_ADAPT(ExprCopy);
            FN_PREVISIT(ExprCopyRight) = adapt("preVisitExprCopyRight",pClass,info);
            IMPL_ADAPT(ExprMove);
            FN_PREVISIT(ExprMoveRight) = adapt("preVisitExprMoveRight",pClass,info);
            IMPL_ADAPT(ExprClone);
            FN_PREVISIT(ExprCloneRight) = adapt("preVisitExprCloneRight",pClass,info);
            IMPL_ADAPT(ExprWith);
            FN_PREVISIT(ExprWithBody) = adapt("preVisitExprWithBody",pClass,info);
            IMPL_ADAPT(ExprWhile);
            FN_PREVISIT(ExprWhileBody) = adapt("preVisitExprWhileBody",pClass,info);
            IMPL_ADAPT(ExprTryCatch);
            FN_PREVISIT(ExprTryCatchCatch) = adapt("preVisitExprTryCatchCatch",pClass,info);
            IMPL_ADAPT(ExprIfThenElse);
            FN_PREVISIT(ExprIfThenElseIfBlock) = adapt("preVisitExprIfThenElseIfBlock",pClass,info);
            FN_PREVISIT(ExprIfThenElseElseBlock) = adapt("preVisitExprIfThenElseElseBlock",pClass,info);
            IMPL_ADAPT(ExprFor);
            IMPL_ADAPT(ExprForVariable);
            IMPL_ADAPT(ExprForSource);
            FN_PREVISIT(ExprForStack) = adapt("preVisitExprForStack",pClass,info);
            FN_PREVISIT(ExprForBody) = adapt("preVisitExprForBody",pClass,info);
            IMPL_ADAPT(ExprMakeVariant);
            IMPL_ADAPT(ExprMakeVariantField);
            IMPL_ADAPT(ExprMakeStruct);
            IMPL_ADAPT(ExprMakeStructIndex);
            IMPL_ADAPT(ExprMakeStructField);
            IMPL_ADAPT(ExprMakeArray);
            IMPL_ADAPT(ExprMakeArrayIndex);
            IMPL_ADAPT(ExprMakeTuple);
            IMPL_ADAPT(ExprMakeTupleIndex);
            IMPL_ADAPT(ExprArrayComprehension);
            FN_PREVISIT(ExprArrayComprehensionSubexpr) = adapt("preVisitExprArrayComprehensionSubexpr",pClass,info);
            FN_PREVISIT(ExprArrayComprehensionWhere) = adapt("preVisitExprArrayComprehensionWhere",pClass,info);
            IMPL_ADAPT(ExprTypeInfo);
            IMPL_ADAPT(ExprLabel);
            IMPL_ADAPT(ExprGoto);
            IMPL_ADAPT(ExprRef2Value);
            IMPL_ADAPT(ExprRef2Ptr);
            IMPL_ADAPT(ExprPtr2Ref);
            IMPL_ADAPT(ExprAddr);
            IMPL_ADAPT(ExprAssert);
            IMPL_ADAPT(ExprStaticAssert);
            IMPL_ADAPT(ExprDebug);
            IMPL_ADAPT(ExprInvoke);
            IMPL_ADAPT(ExprErase);
            IMPL_ADAPT(ExprFind);
            IMPL_ADAPT(ExprKeyExists);
            IMPL_ADAPT(ExprAscend);
            IMPL_ADAPT(ExprCast);
            IMPL_ADAPT(ExprDelete);
            IMPL_ADAPT(ExprVar);
            IMPL_ADAPT(ExprSwizzle);
            IMPL_ADAPT(ExprField);
            IMPL_ADAPT(ExprSafeField);
            IMPL_ADAPT(ExprIsVariant);
            IMPL_ADAPT(ExprAsVariant);
            IMPL_ADAPT(ExprSafeAsVariant);
            IMPL_ADAPT(ExprOp1);
            IMPL_ADAPT(ExprReturn);
            IMPL_ADAPT(ExprYield);
            IMPL_ADAPT(ExprBreak);
            IMPL_ADAPT(ExprContinue);
        /*
            IMPL_ADAPT(ExprConst);
            IMPL_ADAPT(ExprFakeContext);
            IMPL_ADAPT(ExprFakeLineInfo);
            IMPL_ADAPT(ExprConstPtr);
            IMPL_ADAPT(ExprConstEnumeration);
            IMPL_ADAPT(ExprConstBitfield);
            IMPL_ADAPT(ExprConstInt8);
            IMPL_ADAPT(ExprConstInt16);
            IMPL_ADAPT(ExprConstInt64);
            IMPL_ADAPT(ExprConstInt);
            IMPL_ADAPT(ExprConstInt2);
            IMPL_ADAPT(ExprConstInt3);
            IMPL_ADAPT(ExprConstInt4);
            IMPL_ADAPT(ExprConstUInt8);
            IMPL_ADAPT(ExprConstUInt16);
            IMPL_ADAPT(ExprConstUInt64);
            IMPL_ADAPT(ExprConstUInt);
            IMPL_ADAPT(ExprConstUInt2);
            IMPL_ADAPT(ExprConstUInt3);
            IMPL_ADAPT(ExprConstUInt4);
            IMPL_ADAPT(ExprConstRange);
            IMPL_ADAPT(ExprConstURange);
            IMPL_ADAPT(ExprConstBool);
            IMPL_ADAPT(ExprConstFloat);
            IMPL_ADAPT(ExprConstFloat2);
            IMPL_ADAPT(ExprConstFloat3);
            IMPL_ADAPT(ExprConstFloat4);
            IMPL_ADAPT(ExprConstString);
            IMPL_ADAPT(ExprConstDouble);
            IMPL_ADAPT(ExprMakeBlock);
            IMPL_ADAPT(ExprMakeGenerator);
            IMPL_ADAPT(ExprMemZero);
        */
        }
    protected:
        void *      classPtr;
        Context *   context;
    protected:
        DECL_VISIT(Program);
        Func FN_PREVISIT(ProgramBody);
        DECL_VISIT(TypeDecl);
        DECL_VISIT(Expression);
        DECL_VISIT(Alias);
        DECL_VISIT(Enumeration);
        DECL_VISIT(EnumerationValue);
        DECL_VISIT(Structure);
        DECL_VISIT(StructureField);
        DECL_VISIT(Function);
        DECL_VISIT(FunctionArgument);
        DECL_VISIT(FunctionArgumentInit);
        DECL_VISIT(FunctionBody);
        DECL_VISIT(ExprBlock);
        DECL_VISIT(ExprBlockArgument);
        DECL_VISIT(ExprBlockArgumentInit);
        DECL_VISIT(ExprBlockExpression);
        DECL_VISIT(ExprBlockFinal);
        DECL_VISIT(ExprBlockFinalExpression);
        DECL_VISIT(ExprLet);
        DECL_VISIT(ExprLetVariable);
        DECL_VISIT(ExprLetVariableInit);
        DECL_VISIT(GlobalLet);
        DECL_VISIT(GlobalLetVariable);
        DECL_VISIT(GlobalLetVariableInit);
        DECL_VISIT(ExprStringBuilder);
        DECL_VISIT(ExprStringBuilderElement);
        DECL_VISIT(ExprNew);
        DECL_VISIT(ExprNewArgument);
        DECL_VISIT(ExprNamedCall);
        DECL_VISIT(ExprNamedCallArgument);
        DECL_VISIT(ExprCall);
        DECL_VISIT(ExprCallArgument);
        DECL_VISIT(ExprLooksLikeCall);
        DECL_VISIT(ExprLooksLikeCallArgument);
        DECL_VISIT(ExprNullCoalescing);
        Func FN_PREVISIT(ExprNullCoalescingDefault);
        DECL_VISIT(ExprAt);
        Func FN_PREVISIT(ExprAtIndex);
        DECL_VISIT(ExprSafeAt);
        Func FN_PREVISIT(ExprSafeAtIndex);
        DECL_VISIT(ExprIs);
        Func FN_PREVISIT(ExprIsType);
        DECL_VISIT(ExprOp2);
        Func FN_PREVISIT(ExprOp2Right);
        DECL_VISIT(ExprOp3);
        Func FN_PREVISIT(ExprOp3Left);
        Func FN_PREVISIT(ExprOp3Right);
        DECL_VISIT(ExprCopy);
        Func FN_PREVISIT(ExprCopyRight);
        DECL_VISIT(ExprMove);
        Func FN_PREVISIT(ExprMoveRight);
        DECL_VISIT(ExprClone);
        Func FN_PREVISIT(ExprCloneRight);
        DECL_VISIT(ExprWith);
        Func FN_PREVISIT(ExprWithBody);
        DECL_VISIT(ExprWhile);
        Func FN_PREVISIT(ExprWhileBody);
        DECL_VISIT(ExprTryCatch);
        Func FN_PREVISIT(ExprTryCatchCatch);
        DECL_VISIT(ExprIfThenElse);
        Func FN_PREVISIT(ExprIfThenElseIfBlock);
        Func FN_PREVISIT(ExprIfThenElseElseBlock);
        DECL_VISIT(ExprFor);
        DECL_VISIT(ExprForVariable);
        DECL_VISIT(ExprForSource);
        Func FN_PREVISIT(ExprForStack);
        Func FN_PREVISIT(ExprForBody);
        DECL_VISIT(ExprMakeVariant);
        DECL_VISIT(ExprMakeVariantField);
        DECL_VISIT(ExprMakeStruct);
        DECL_VISIT(ExprMakeStructIndex);
        DECL_VISIT(ExprMakeStructField);
        DECL_VISIT(ExprMakeArray);
        DECL_VISIT(ExprMakeArrayIndex);
        DECL_VISIT(ExprMakeTuple);
        DECL_VISIT(ExprMakeTupleIndex);
        DECL_VISIT(ExprArrayComprehension);
        Func FN_PREVISIT(ExprArrayComprehensionSubexpr);
        Func FN_PREVISIT(ExprArrayComprehensionWhere);
        DECL_VISIT(ExprTypeInfo);
        DECL_VISIT(ExprLabel);
        DECL_VISIT(ExprGoto);
        DECL_VISIT(ExprRef2Value);
        DECL_VISIT(ExprRef2Ptr);
        DECL_VISIT(ExprPtr2Ref);
        DECL_VISIT(ExprAddr);
        DECL_VISIT(ExprAssert);
        DECL_VISIT(ExprStaticAssert);
        DECL_VISIT(ExprDebug);
        DECL_VISIT(ExprInvoke);
        DECL_VISIT(ExprErase);
        DECL_VISIT(ExprFind);
        DECL_VISIT(ExprKeyExists);
        DECL_VISIT(ExprAscend);
        DECL_VISIT(ExprCast);
        DECL_VISIT(ExprDelete);
        DECL_VISIT(ExprVar);
        DECL_VISIT(ExprSwizzle);
        DECL_VISIT(ExprField);
        DECL_VISIT(ExprSafeField);
        DECL_VISIT(ExprIsVariant);
        DECL_VISIT(ExprAsVariant);
        DECL_VISIT(ExprSafeAsVariant);
        DECL_VISIT(ExprOp1);
        DECL_VISIT(ExprReturn);
        DECL_VISIT(ExprYield);
        DECL_VISIT(ExprBreak);
        DECL_VISIT(ExprContinue);
        DECL_VISIT(ExprConst);
        DECL_VISIT(ExprFakeContext);
        DECL_VISIT(ExprFakeLineInfo);
        DECL_VISIT(ExprConstPtr);
        DECL_VISIT(ExprConstEnumeration);
        DECL_VISIT(ExprConstBitfield);
        DECL_VISIT(ExprConstInt8);
        DECL_VISIT(ExprConstInt16);
        DECL_VISIT(ExprConstInt64);
        DECL_VISIT(ExprConstInt);
        DECL_VISIT(ExprConstInt2);
        DECL_VISIT(ExprConstInt3);
        DECL_VISIT(ExprConstInt4);
        DECL_VISIT(ExprConstUInt8);
        DECL_VISIT(ExprConstUInt16);
        DECL_VISIT(ExprConstUInt64);
        DECL_VISIT(ExprConstUInt);
        DECL_VISIT(ExprConstUInt2);
        DECL_VISIT(ExprConstUInt3);
        DECL_VISIT(ExprConstUInt4);
        DECL_VISIT(ExprConstRange);
        DECL_VISIT(ExprConstURange);
        DECL_VISIT(ExprConstBool);
        DECL_VISIT(ExprConstFloat);
        DECL_VISIT(ExprConstFloat2);
        DECL_VISIT(ExprConstFloat3);
        DECL_VISIT(ExprConstFloat4);
        DECL_VISIT(ExprConstString);
        DECL_VISIT(ExprConstDouble);
        DECL_VISIT(ExprMakeBlock);
        DECL_VISIT(ExprMakeGenerator);
        DECL_VISIT(ExprMemZero);
    protected:
    // whole program
        virtual void preVisitProgram ( Program * expr ) override
            { IMPL_PREVISIT(Program); }
        virtual void visitProgram ( Program * expr ) override
            { IMPL_VISIT_VOID(Program); }
        virtual void preVisitProgramBody ( Program * expr ) override
            { IMPL_PREVISIT1(ProgramBody,Program); }
    // type
        virtual void preVisit ( TypeDecl * expr ) override
            { IMPL_PREVISIT(TypeDecl); }
        virtual TypeDeclPtr visit ( TypeDecl * expr ) override
            { IMPL_VISIT(TypeDecl); }
    // alias
        virtual void preVisitAlias ( TypeDecl * expr, const string & name ) override
            { IMPL_PREVISIT2(Alias,TypeDecl,const string &,name); }
        virtual TypeDeclPtr visitAlias ( TypeDecl * expr, const string & name ) override
            { IMPL_VISIT2(Alias,TypeDecl,TypeDecl,expr,const string &,name); }
    // enumeration
        virtual void preVisit ( Enumeration * expr ) override
            { IMPL_PREVISIT(Enumeration); }
        virtual EnumerationPtr visit ( Enumeration * expr ) override
            { IMPL_VISIT(Enumeration); }
        virtual void preVisitEnumerationValue ( Enumeration * expr, const string & name, Expression * value, bool last ) override
            { IMPL_PREVISIT4(EnumerationValue,Enumeration,const string &,name,ExpressionPtr,value,bool,last); }
        virtual ExpressionPtr visitEnumerationValue ( Enumeration * expr, const string & name, Expression * value, bool last ) override
            { IMPL_VISIT4(EnumerationValue,Enumeration,Expression,value,const string &,name,ExpressionPtr,value,bool,last); }
    // structure
        virtual void preVisit ( Structure * expr ) override
            { IMPL_PREVISIT(Structure); }
        virtual void preVisitStructureField ( Structure * expr, Structure::FieldDeclaration & decl, bool last ) override
            { IMPL_PREVISIT3(StructureField,Structure,Structure::FieldDeclaration &,decl,bool,last); }
        virtual void visitStructureField ( Structure * expr, Structure::FieldDeclaration & decl, bool last ) override {
            if ( FN_VISIT(StructureField) ) {
                das_invoke_function<void>::invoke<void *,StructurePtr,Structure::FieldDeclaration&,bool>
                    (context,FN_VISIT(StructureField),classPtr,expr,decl,last);
            }
        }
        virtual StructurePtr visit ( Structure * expr ) override
            { IMPL_VISIT(Structure); }
    // function
        virtual void preVisit ( Function * expr ) override
            { IMPL_PREVISIT(Function); }
        virtual FunctionPtr visit ( Function * expr ) override
            { IMPL_VISIT(Function); }
        virtual void preVisitArgument ( Function * expr, const VariablePtr & var, bool lastArg ) override
            { IMPL_PREVISIT3(FunctionArgument,Function,VariablePtr,var,bool,lastArg); }
        virtual VariablePtr visitArgument ( Function * expr, const VariablePtr & var, bool lastArg ) override
            { IMPL_VISIT3(FunctionArgument,Function,Variable,var,VariablePtr,var,bool,lastArg); }
        virtual void preVisitArgumentInit ( Function * expr, const VariablePtr & var, Expression * init ) override
            { IMPL_PREVISIT3(FunctionArgument,Function,VariablePtr,var,ExpressionPtr,init); }
        virtual ExpressionPtr visitArgumentInit ( Function * expr, const VariablePtr & var, Expression * init ) override
            { IMPL_VISIT3(FunctionArgument,Function,Expression,init,VariablePtr,var,ExpressionPtr,init); }
        virtual void preVisitFunctionBody ( Function * expr, Expression * that ) override
            { IMPL_PREVISIT2(FunctionBody,Function,ExpressionPtr,that); }
        virtual ExpressionPtr visitFunctionBody ( Function * expr, Expression * that ) override
            { IMPL_VISIT2(FunctionBody,Function,Expression,that,ExpressionPtr,that); }
    // expression
        virtual void preVisitExpression ( Expression * expr ) override
            { IMPL_PREVISIT(Expression); }
        virtual ExpressionPtr visitExpression ( Expression * expr ) override
            { IMPL_VISIT(Expression); }
    // block
        IMPL_BIND_EXPR(ExprBlock);
        virtual void preVisitBlockArgument ( ExprBlock * expr, const VariablePtr & var, bool lastArg ) override
            { IMPL_PREVISIT3(ExprBlockArgument,ExprBlock,VariablePtr,var,bool,lastArg); }
        virtual VariablePtr visitBlockArgument ( ExprBlock * expr, const VariablePtr & var, bool lastArg ) override
            { IMPL_VISIT3(ExprBlockArgument,ExprBlock,Variable,var,VariablePtr,var,bool,lastArg); }
        virtual void preVisitBlockArgumentInit ( ExprBlock * expr, const VariablePtr & var, Expression * init ) override
            { IMPL_PREVISIT3(ExprBlockArgumentInit,ExprBlock,VariablePtr,var,ExpressionPtr,init); }
        virtual ExpressionPtr visitBlockArgumentInit ( ExprBlock * expr, const VariablePtr & var, Expression * init ) override
            { IMPL_VISIT3(ExprBlockArgumentInit,ExprBlock,Expression,init,VariablePtr,var,ExpressionPtr,init); }
        virtual void preVisitBlockExpression ( ExprBlock * expr, Expression * bexpr ) override
            { IMPL_PREVISIT2(ExprBlockExpression,ExprBlock,ExpressionPtr,bexpr); }
        virtual ExpressionPtr visitBlockExpression (  ExprBlock * expr, Expression * bexpr ) override
            { IMPL_VISIT2(ExprBlockExpression,ExprBlock,Expression,bexpr,ExpressionPtr,bexpr); }
        virtual void preVisitBlockFinal ( ExprBlock * expr ) override
            { IMPL_PREVISIT1(ExprBlockFinal,ExprBlock); }
        virtual void visitBlockFinal ( ExprBlock * expr ) override {
            if ( FN_VISIT(ExprBlockFinal) ) {
                das_invoke_function<void>::invoke<void *,smart_ptr<ExprBlock>>
                    (context,FN_VISIT(ExprBlockFinal),classPtr,expr);
            }
        }
        virtual void preVisitBlockFinalExpression ( ExprBlock * expr, Expression * bexpr ) override
            { IMPL_PREVISIT2(ExprBlockFinalExpression,ExprBlock,ExpressionPtr,bexpr); }
        virtual ExpressionPtr visitBlockFinalExpression (  ExprBlock * expr, Expression * bexpr ) override
            { IMPL_VISIT2(ExprBlockFinalExpression,ExprBlock,Expression,expr,ExpressionPtr,bexpr); }
    // let
        IMPL_BIND_EXPR(ExprLet);
        virtual void preVisitLet ( ExprLet * expr, const VariablePtr & var, bool last ) override
            { IMPL_PREVISIT3(ExprLetVariable,ExprLet,VariablePtr,var,bool,last); }
        virtual VariablePtr visitLet ( ExprLet * expr, const VariablePtr & var, bool last ) override
            { IMPL_VISIT3(ExprLetVariable,ExprLet,Variable,var,VariablePtr,var,bool,last); }
        virtual void preVisitLetInit ( ExprLet * expr, const VariablePtr & var, Expression * init ) override
            { IMPL_PREVISIT3(ExprLetVariableInit,ExprLet,VariablePtr,var,ExpressionPtr,init); }
        virtual ExpressionPtr visitLetInit ( ExprLet * expr, const VariablePtr & var, Expression * init ) override
            { IMPL_VISIT3(ExprLetVariableInit,ExprLet,Expression,init,VariablePtr,var,ExpressionPtr,init); }
    // global let
        virtual void preVisitGlobalLetBody ( Program * expr ) override
            { IMPL_PREVISIT1(GlobalLet,Program); }
        virtual void visitGlobalLetBody ( Program * expr ) override
            { IMPL_VISIT_VOID1(GlobalLet,Program); }
        virtual void preVisitGlobalLet ( const VariablePtr & expr ) override
            { IMPL_PREVISIT1(GlobalLetVariable,Variable); }
        virtual VariablePtr visitGlobalLet ( const VariablePtr & expr ) override
            { IMPL_VISIT1(GlobalLetVariable,Variable,Variable,expr); }
        virtual void preVisitGlobalLetInit ( const VariablePtr & expr, Expression * init ) override
            { IMPL_PREVISIT2(GlobalLetVariableInit,Variable,ExpressionPtr,init); }
        virtual ExpressionPtr visitGlobalLetInit ( const VariablePtr & expr, Expression * init ) override
            { IMPL_VISIT2(GlobalLetVariableInit,Variable,Expression,init,ExpressionPtr,init); }
    // string builder
        IMPL_BIND_EXPR(ExprStringBuilder);
        virtual void preVisitStringBuilderElement ( ExprStringBuilder * expr, Expression * element, bool last ) override
            { IMPL_PREVISIT3(ExprStringBuilderElement,ExprStringBuilder,ExpressionPtr,element,bool,last); }
        virtual ExpressionPtr visitStringBuilderElement ( ExprStringBuilder * expr, Expression * element, bool last ) override
            { IMPL_VISIT3(ExprStringBuilderElement,ExprStringBuilder,Expression,element,ExpressionPtr,element,bool,last); }
    // new
        IMPL_BIND_EXPR(ExprNew);
        virtual void preVisitNewArg ( ExprNew * expr, Expression * arg, bool last ) override
            { IMPL_PREVISIT3(ExprNewArgument,ExprNew,ExpressionPtr,arg,bool,last); }
        virtual ExpressionPtr visitNewArg ( ExprNew * expr, Expression * arg , bool last ) override
            { IMPL_VISIT3(ExprNewArgument,ExprNew,Expression,arg,ExpressionPtr,arg,bool,last); }
    // named call
        IMPL_BIND_EXPR(ExprNamedCall);
        virtual void preVisitNamedCallArg ( ExprNamedCall * expr, MakeFieldDecl * arg, bool last ) override
            { IMPL_PREVISIT3(ExprNamedCallArgument,ExprNamedCall,MakeFieldDeclPtr,arg,bool,last); }
        virtual MakeFieldDeclPtr visitNamedCallArg ( ExprNamedCall * expr, MakeFieldDecl * arg , bool last ) override
            { IMPL_VISIT3(ExprNamedCallArgument,ExprNamedCall,MakeFieldDecl,arg,MakeFieldDeclPtr,arg,bool,last); }
    // call
        IMPL_BIND_EXPR(ExprCall);
        virtual void preVisitCallArg ( ExprCall * expr, Expression * arg, bool last ) override
            { IMPL_PREVISIT3(ExprCallArgument,ExprCall,ExpressionPtr,arg,bool,last); }
        virtual ExpressionPtr visitCallArg ( ExprCall * expr, Expression * arg , bool last ) override
            { IMPL_VISIT3(ExprCallArgument,ExprCall,Expression,arg,ExpressionPtr,arg,bool,last); }
    // looks like call
        IMPL_BIND_EXPR(ExprLooksLikeCall);
        virtual void preVisitLooksLikeCallArg ( ExprLooksLikeCall * expr, Expression * arg, bool last ) override
            { IMPL_PREVISIT3(ExprLooksLikeCallArgument,ExprLooksLikeCall,ExpressionPtr,arg,bool,last); }
        virtual ExpressionPtr visitLooksLikeCallArg ( ExprLooksLikeCall * expr, Expression * arg , bool last ) override
            { IMPL_VISIT3(ExprLooksLikeCallArgument,ExprLooksLikeCall,Expression,arg,ExpressionPtr,arg,bool,last); }
    // null coaelescing
        IMPL_BIND_EXPR(ExprNullCoalescing);
        virtual void preVisitNullCoaelescingDefault ( ExprNullCoalescing * expr, Expression * defval ) override
            { IMPL_PREVISIT2(ExprNullCoalescingDefault,ExprNullCoalescing,ExpressionPtr, defval); }
    // at
        IMPL_BIND_EXPR(ExprAt);
        virtual void preVisitAtIndex ( ExprAt * expr, Expression * index ) override
            { IMPL_PREVISIT2(ExprAtIndex,ExprAt,ExpressionPtr,index); }
    // safe at
        IMPL_BIND_EXPR(ExprSafeAt);
        virtual void preVisitSafeAtIndex ( ExprSafeAt * expr, Expression * index ) override
            { IMPL_PREVISIT2(ExprSafeAtIndex,ExprSafeAt,ExpressionPtr,index); }
    // is
        IMPL_BIND_EXPR(ExprIs);
        virtual void preVisitType ( ExprIs * expr, TypeDecl * typeDecl ) override
            { IMPL_PREVISIT2(ExprIsType,ExprIs,TypeDeclPtr,typeDecl); }
    // op2
        IMPL_BIND_EXPR(ExprOp2);
        virtual void preVisitRight ( ExprOp2 * expr, Expression * right ) override
            { IMPL_PREVISIT2(ExprOp2Right,ExprOp2,ExpressionPtr,right); }
    // op3
        IMPL_BIND_EXPR(ExprOp3);
        virtual void preVisitLeft  ( ExprOp3 * expr, Expression * left ) override
            { IMPL_PREVISIT2(ExprOp3Left,ExprOp3,ExpressionPtr,left); }
        virtual void preVisitRight ( ExprOp3 * expr, Expression * right ) override
            { IMPL_PREVISIT2(ExprOp3Right,ExprOp3,ExpressionPtr,right); }
    // copy
        IMPL_BIND_EXPR(ExprCopy);
        virtual void preVisitRight ( ExprCopy * expr, Expression * right ) override
            { IMPL_PREVISIT2(ExprCopyRight,ExprCopy,ExpressionPtr,right); }
    // move
        IMPL_BIND_EXPR(ExprMove);
        virtual void preVisitRight ( ExprMove * expr, Expression * right ) override
            { IMPL_PREVISIT2(ExprMoveRight,ExprMove,ExpressionPtr,right); }
    // clone
        IMPL_BIND_EXPR(ExprClone);
        virtual void preVisitRight ( ExprClone * expr, Expression * right ) override
            { IMPL_PREVISIT2(ExprCloneRight,ExprClone,ExpressionPtr,right); }
    // with
        IMPL_BIND_EXPR(ExprWith);
        virtual void preVisitWithBody ( ExprWith * expr, Expression * body ) override
            { IMPL_PREVISIT2(ExprWithBody,ExprWith,ExpressionPtr,body); }
    // while
        IMPL_BIND_EXPR(ExprWhile);
        virtual void preVisitWhileBody ( ExprWhile * expr, Expression * body ) override
            { IMPL_PREVISIT2(ExprWhileBody,ExprWhile,ExpressionPtr,body); }
    // try-catch
        IMPL_BIND_EXPR(ExprTryCatch);
        virtual void preVisitCatch ( ExprTryCatch * expr, Expression * body ) override
            { IMPL_PREVISIT2(ExprTryCatchCatch,ExprTryCatch,ExpressionPtr,body); }
    // if-then-else
        IMPL_BIND_EXPR(ExprIfThenElse);
        virtual void preVisitIfBlock ( ExprIfThenElse * expr, Expression * ifBlock ) override
            { IMPL_PREVISIT2(ExprIfThenElseIfBlock,ExprIfThenElse,ExpressionPtr,ifBlock); }
        virtual void preVisitElseBlock ( ExprIfThenElse * expr, Expression * elseBlock ) override
            { IMPL_PREVISIT2(ExprIfThenElseElseBlock,ExprIfThenElse,ExpressionPtr,elseBlock); }
    // for
        IMPL_BIND_EXPR(ExprFor);
        virtual void preVisitFor ( ExprFor * expr, const VariablePtr & var, bool last ) override
            { IMPL_PREVISIT3(ExprForVariable,ExprFor,VariablePtr,var,bool,last); }
        virtual VariablePtr visitFor ( ExprFor * expr, const VariablePtr & var, bool last ) override
            { IMPL_VISIT3(ExprForVariable,ExprFor,Variable,var,VariablePtr,var,bool,last); }
        virtual void preVisitForStack ( ExprFor * expr ) override
            { IMPL_PREVISIT1(ExprForStack,ExprFor); }
        virtual void preVisitForBody ( ExprFor * expr, Expression * body ) override
            { IMPL_PREVISIT2(ExprForBody,ExprFor,ExpressionPtr,body); }
        virtual void preVisitForSource ( ExprFor * expr, Expression * source, bool last ) override
            { IMPL_PREVISIT3(ExprForSource,ExprFor,ExpressionPtr,source,bool,last); }
        virtual ExpressionPtr visitForSource ( ExprFor * expr, Expression * source , bool last ) override
            { IMPL_VISIT3(ExprForSource,ExprFor,Expression,source,ExpressionPtr,source,bool,last); }
    // make variant
        IMPL_BIND_EXPR(ExprMakeVariant);
        virtual void preVisitMakeVariantField ( ExprMakeVariant * expr, int index, MakeFieldDecl * decl, bool last ) override
            { IMPL_PREVISIT4(ExprMakeVariantField,ExprMakeVariant,int,index,MakeFieldDeclPtr,decl,bool,last); }
        virtual MakeFieldDeclPtr visitMakeVariantField(ExprMakeVariant * expr, int index, MakeFieldDecl * decl, bool last) override
            { IMPL_VISIT4(ExprMakeVariantField,ExprMakeVariant,MakeFieldDecl,decl,int,index,MakeFieldDeclPtr,decl,bool,last); }
    // make structure
        IMPL_BIND_EXPR(ExprMakeStruct);
        virtual void preVisitMakeStructureIndex ( ExprMakeStruct * expr, int index, bool last ) override
            { IMPL_PREVISIT3(ExprMakeStructIndex,ExprMakeStruct,int,index,bool,last); }
        virtual void visitMakeStructureIndex ( ExprMakeStruct * expr, int index, bool last ) override
            { IMPL_VISIT_VOID3(ExprMakeStructIndex,ExprMakeStruct,int,index,bool,last); }
        virtual void preVisitMakeStructureField ( ExprMakeStruct * expr, int index, MakeFieldDecl * decl, bool last ) override
             { IMPL_PREVISIT4(ExprMakeStructField,ExprMakeStruct,int,index,MakeFieldDeclPtr,decl,bool,last); }
        virtual MakeFieldDeclPtr visitMakeStructureField ( ExprMakeStruct * expr, int index, MakeFieldDecl * decl, bool last ) override
            { IMPL_VISIT4(ExprMakeStructField,ExprMakeStruct,MakeFieldDecl,decl,int,index,MakeFieldDeclPtr,decl,bool,last); }
    // make array
        IMPL_BIND_EXPR(ExprMakeArray);
        virtual void preVisitMakeArrayIndex ( ExprMakeArray * expr, int index, Expression * init, bool last ) override
            { IMPL_PREVISIT4(ExprMakeArrayIndex,ExprMakeArray,int,index,ExpressionPtr,init,bool,last); }
        virtual ExpressionPtr visitMakeArrayIndex ( ExprMakeArray * expr, int index, Expression * init, bool last ) override
            { IMPL_VISIT4(ExprMakeArrayIndex,ExprMakeArray,Expression,init,int,index,ExpressionPtr,init,bool,last); }
    // make tuple
        IMPL_BIND_EXPR(ExprMakeTuple);
        virtual void preVisitMakeTupleIndex ( ExprMakeTuple * expr, int index, Expression * init, bool last ) override
            { IMPL_PREVISIT4(ExprMakeTupleIndex,ExprMakeTuple,int,index,ExpressionPtr,init,bool,last); }
        virtual ExpressionPtr visitMakeTupleIndex ( ExprMakeTuple * expr, int index, Expression * init, bool last ) override
            { IMPL_VISIT4(ExprMakeTupleIndex,ExprMakeTuple,Expression,init,int,index,ExpressionPtr,init,bool,last); }
    // array comprehension
        IMPL_BIND_EXPR(ExprArrayComprehension);
        virtual void preVisitArrayComprehensionSubexpr ( ExprArrayComprehension * expr, Expression * subexpr ) override
            { IMPL_PREVISIT2(ExprArrayComprehensionSubexpr,ExprArrayComprehension,ExpressionPtr,subexpr); }
        virtual void preVisitArrayComprehensionWhere ( ExprArrayComprehension * expr, Expression * where ) override
            { IMPL_PREVISIT2(ExprArrayComprehensionWhere,ExprArrayComprehension,ExpressionPtr,where); }
    // type info
        IMPL_BIND_EXPR(ExprTypeInfo);
    // all other expressions
        IMPL_BIND_EXPR(ExprLabel);
        IMPL_BIND_EXPR(ExprGoto);
        IMPL_BIND_EXPR(ExprRef2Value);
        IMPL_BIND_EXPR(ExprRef2Ptr);
        IMPL_BIND_EXPR(ExprPtr2Ref);
        IMPL_BIND_EXPR(ExprAddr);
        IMPL_BIND_EXPR(ExprAssert);
        IMPL_BIND_EXPR(ExprStaticAssert);
        IMPL_BIND_EXPR(ExprDebug);
        IMPL_BIND_EXPR(ExprInvoke);
        IMPL_BIND_EXPR(ExprErase);
        IMPL_BIND_EXPR(ExprFind);
        IMPL_BIND_EXPR(ExprKeyExists);
        IMPL_BIND_EXPR(ExprAscend);
        IMPL_BIND_EXPR(ExprCast);
        IMPL_BIND_EXPR(ExprDelete);
        IMPL_BIND_EXPR(ExprVar);
        IMPL_BIND_EXPR(ExprSwizzle);
        IMPL_BIND_EXPR(ExprField);
        IMPL_BIND_EXPR(ExprSafeField);
        IMPL_BIND_EXPR(ExprIsVariant);
        IMPL_BIND_EXPR(ExprAsVariant);
        IMPL_BIND_EXPR(ExprSafeAsVariant);
        IMPL_BIND_EXPR(ExprOp1);
        IMPL_BIND_EXPR(ExprReturn);
        IMPL_BIND_EXPR(ExprYield);
        IMPL_BIND_EXPR(ExprBreak);
        IMPL_BIND_EXPR(ExprContinue);
        /*
        IMPL_BIND_EXPR(ExprConst);
        IMPL_BIND_EXPR(ExprFakeContext);
        IMPL_BIND_EXPR(ExprFakeLineInfo);
        IMPL_BIND_EXPR(ExprConstPtr);
        IMPL_BIND_EXPR(ExprConstEnumeration);
        IMPL_BIND_EXPR(ExprConstBitfield);
        IMPL_BIND_EXPR(ExprConstInt8);
        IMPL_BIND_EXPR(ExprConstInt16);
        IMPL_BIND_EXPR(ExprConstInt64);
        IMPL_BIND_EXPR(ExprConstInt);
        IMPL_BIND_EXPR(ExprConstInt2);
        IMPL_BIND_EXPR(ExprConstInt3);
        IMPL_BIND_EXPR(ExprConstInt4);
        IMPL_BIND_EXPR(ExprConstUInt8);
        IMPL_BIND_EXPR(ExprConstUInt16);
        IMPL_BIND_EXPR(ExprConstUInt64);
        IMPL_BIND_EXPR(ExprConstUInt);
        IMPL_BIND_EXPR(ExprConstUInt2);
        IMPL_BIND_EXPR(ExprConstUInt3);
        IMPL_BIND_EXPR(ExprConstUInt4);
        IMPL_BIND_EXPR(ExprConstRange);
        IMPL_BIND_EXPR(ExprConstURange);
        IMPL_BIND_EXPR(ExprConstBool);
        IMPL_BIND_EXPR(ExprConstFloat);
        IMPL_BIND_EXPR(ExprConstFloat2);
        IMPL_BIND_EXPR(ExprConstFloat3);
        IMPL_BIND_EXPR(ExprConstFloat4);
        IMPL_BIND_EXPR(ExprConstString);
        IMPL_BIND_EXPR(ExprConstDouble);
        IMPL_BIND_EXPR(ExprMakeBlock);
        IMPL_BIND_EXPR(ExprMakeGenerator);
        IMPL_BIND_EXPR(ExprMemZero);
    */
    };

    struct AstVisitorAdapterAnnotation : ManagedStructureAnnotation<VisitorAdapter,false> {
        AstVisitorAdapterAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("VisitorAdapter", ml) {
        }
    };

    #include "ast.das.inc"

    smart_ptr<VisitorAdapter> makeVisitor ( void * pClass, const StructInfo * info, Context * context ) {
        return make_smart<VisitorAdapter>((char *)pClass,info,context);
    }

    smart_ptr_raw<Program> thisProgram ( Context * context ) {
        return context->thisProgram;
    }

    void astVisit ( smart_ptr_raw<Program> program, smart_ptr_raw<VisitorAdapter> adapter ) {
        program->visit(*adapter);
    }

    char * ast_describe_typedecl ( smart_ptr_raw<TypeDecl> t, bool d_extra, bool d_contracts, bool d_module, Context * context ) {
        return context->stringHeap.allocateString(t->describe(
            d_extra ? TypeDecl::DescribeExtra::yes : TypeDecl::DescribeExtra::no,
            d_contracts ? TypeDecl::DescribeContracts::yes : TypeDecl::DescribeContracts::no,
            d_module ? TypeDecl::DescribeModule::yes : TypeDecl::DescribeModule::no));
    }

    char * ast_describe_expression ( smart_ptr_raw<Expression> t, Context * context ) {
        TextWriter ss;
        ss << *t;
        return context->stringHeap.allocateString(ss.str());
    }

    char * ast_describe_function ( smart_ptr_raw<Function> t, Context * context ) {
        TextWriter ss;
        ss << *t;
        return context->stringHeap.allocateString(ss.str());
    }

    char * ast_das_to_string ( Type bt, Context * context ) {
        return context->stringHeap.allocateString(das_to_string(bt));
    }

    class Module_Ast : public Module {
    public:
        template <typename RecAnn>
        void addRecAnnotation ( ModuleLibrary & lib ) {
            auto rec = make_smart<RecAnn>(lib);
            addAnnotation(rec);
            initRecAnnotation(rec, lib);
        }
        Module_Ast() : Module("ast") {
            DAS_PROFILE_SECTION("Module_Ast");
            ModuleLibrary lib;
            lib.addModule(this);
            lib.addBuiltInModule();
            lib.addModule(Module::require("rtti"));
            // THE MAGNIFICENT TWO
            addTypeInfoMacro(make_smart<AstTypeDeclMacro>());
            addTypeInfoMacro(make_smart<AstExpressionMacro>());
            addTypeInfoMacro(make_smart<AstFunctionMacro>());
            // FLAGS?
            addAlias(makeTypeDeclFlags());
            addAlias(makeFieldDeclarationFlags());
            addAlias(makeStructureFlags());
            addAlias(makeExprGenFlagsFlags());
            addAlias(makeExprFlagsFlags());
            addAlias(makeExprPrintFlagsFlags());
            addAlias(makeFunctionFlags());
            addAlias(makeFunctionSideEffectFlags());
            addAlias(makeVariableFlags());
            addAlias(makeVariableAccessFlags());
            addAlias(makeExprBlockFlags());
            addAlias(makeExprAtFlags());
            addAlias(makeExprMakeLocalFlags());
            addAlias(makeExprAscendFlags());
            addAlias(makeExprCastFlags());
            addAlias(makeExprVarFlags());
            addAlias(makeExprMakeStructFlags());
            addAlias(makeMakeFieldDeclFlags());
            addAlias(makeExprFieldDerefFlags());
            addAlias(makeExprFieldFieldFlags());
            addAlias(makeExprSwizzleFieldFlags());
            addAlias(makeExprYieldFlags());
            addAlias(makeExprReturnFlags());
            // ENUMS
            addEnumeration(make_smart<EnumerationSideEffects>());
            // AST TYPES (due to a lot of xrefs we declare everyone as recursive type)
            auto exa = make_smart<AstExprAnnotation<Expression>>("Expression",lib);
            addAnnotation(exa);
            auto tda = make_smart<AstTypeDeclAnnnotation>(lib);
            addAnnotation(tda);
            auto sta = make_smart<AstStructureAnnotation>(lib);
            addAnnotation(sta);
            auto fta = make_smart<AstFieldDeclarationAnnotation>(lib);
            addAnnotation(fta);
            auto ena = make_smart<AstEnumerationAnnotation>(lib);
            addAnnotation(ena);
            auto fna = make_smart<AstFunctionAnnotation>(lib);
            addAnnotation(fna);
            auto iha = make_smart<AstInferHistoryAnnotation>(lib);
            addAnnotation(iha);
            auto vaa = make_smart<AstVariableAnnotation>(lib);
            addAnnotation(vaa);
            initRecAnnotation(tda, lib);
            initRecAnnotation(sta, lib);
            initRecAnnotation(fta, lib);
            initRecAnnotation(ena, lib);
            initRecAnnotation(exa, lib);
            initRecAnnotation(fna, lib);
            initRecAnnotation(iha, lib);
            initRecAnnotation(vaa, lib);
            // expressions
            addAnnotation(make_smart<AstExprBlockAnnotation>(lib));
            addAnnotation(make_smart<AstExprLetAnnotation>(lib));
            addAnnotation(make_smart<AstExprStringBuilderAnnotation>(lib));
            addAnnotation(make_smart<AstExprNewAnnotation>(lib));
            addAnnotation(make_smart<AstMakeFieldDeclAnnotation>(lib));
            addAnnotation(make_smart<AstMakeStructAnnotation>(lib));
            addAnnotation(make_smart<AstExprNamedCallAnnotation>(lib));
            addAnnotation(make_smart<AstExprLooksLikeCallAnnotation<ExprLooksLikeCall>>("ExprLooksLikeCall",lib));
            addAnnotation(make_smart<AstExprCallAnnotation>(lib));
            addAnnotation(make_smart<AstExprPtr2RefAnnotation<ExprPtr2Ref>>("ExprPtr2Ref",lib));
            addAnnotation(make_smart<AstExprNullCoalescingAnnotation>(lib));
            addAnnotation(make_smart<AstExprAtAnnotation<ExprAt>>("ExprAt",lib));
            addAnnotation(make_smart<AstExprAtAnnotation<ExprSafeAt>>("ExprSafeAt",lib));
            addAnnotation(make_smart<AstExprIsAnnotation>(lib));
            addAnnotation(make_smart<AstExprOp2Annotation<ExprOp2>>("ExprOp2",lib));
            addAnnotation(make_smart<AstExprOp3Annotation>(lib));
            addAnnotation(make_smart<AstExprCopyAnnotation>(lib));
            addAnnotation(make_smart<AstExprOp2Annotation<ExprMove>>("ExprMove",lib));
            addAnnotation(make_smart<AstExprOp2Annotation<ExprClone>>("ExprClone",lib));
            addAnnotation(make_smart<AstExprWithAnnotation>(lib));
            addAnnotation(make_smart<AstExprWhileAnnotation>(lib));
            addAnnotation(make_smart<AstExprTryCatchAnnotation>(lib));
            addAnnotation(make_smart<AstExprIfThenElseAnnotation>(lib));
            addAnnotation(make_smart<AstExprForAnnotation>(lib));
            addAnnotation(make_smart<AstExprMakeLocalAnnotation<ExprMakeLocal>>("ExprMakeLocal",lib));
            addAnnotation(make_smart<AstExprMakeStructAnnotation>(lib));
            addAnnotation(make_smart<AstExprMakeVariantAnnotation>(lib));
            addAnnotation(make_smart<AstExprMakeArrayAnnotation<ExprMakeArray>>("ExprMakeArray",lib));
            addAnnotation(make_smart<AstExprMakeTupleAnnotation>(lib));
            addAnnotation(make_smart<AstExprArrayComprehensionAnnotation>(lib));
            addAnnotation(make_smart<AstTypeInfoMacroAnnotation>(lib));
            addAnnotation(make_smart<AstExprTypeInfoAnnotation>(lib));
            // expressions with no extra syntax
            addAnnotation(make_smart<AstExprLabelAnnotation>(lib));
            addAnnotation(make_smart<AstExprGotoAnnotation>(lib));
            addAnnotation(make_smart<AstExprRef2ValueAnnotation>(lib));
            addAnnotation(make_smart<AstExprRef2PtrAnnotation>(lib));
            addAnnotation(make_smart<AstExprAddrAnnotation>(lib));
            addAnnotation(make_smart<AstExprAssertAnnotation>(lib));
            addAnnotation(make_smart<AstExprStaticAssertAnnotation>(lib));
            addAnnotation(make_smart<AstExprDebugAnnotation>(lib));
            addAnnotation(make_smart<AstExprInvokeAnnotation>(lib));
            addAnnotation(make_smart<AstExprEraseAnnotation>(lib));
            addAnnotation(make_smart<AstExprFindAnnotation>(lib));
            addAnnotation(make_smart<AstExprKeyExistsAnnotation>(lib));
            addAnnotation(make_smart<AstExprAscendAnnotation>(lib));
            addAnnotation(make_smart<AstExprCastAnnotation>(lib));
            addAnnotation(make_smart<AstExprDeleteAnnotation>(lib));
            addAnnotation(make_smart<AstExprVarAnnotation>(lib));
            addAnnotation(make_smart<AstExprSwizzleAnnotation>(lib));
            addAnnotation(make_smart<AstExprFieldAnnotation<ExprField>>("ExprField",lib));
            addAnnotation(make_smart<AstExprSafeFieldAnnotation>(lib));
            addAnnotation(make_smart<AstExprFieldAnnotation<ExprIsVariant>>("ExprIsVariant",lib));
            addAnnotation(make_smart<AstExprFieldAnnotation<ExprAsVariant>>("ExprAsVariant",lib));
            addAnnotation(make_smart<AstExprSafeAsVariantAnnotation>(lib));
            addAnnotation(make_smart<AstExprOp1Annotation>(lib));
            addAnnotation(make_smart<AstExprReturnAnnotation>(lib));
            addAnnotation(make_smart<AstExprYieldAnnotation>(lib));
            addAnnotation(make_smart<AstExpressionAnnotation<ExprBreak>>("ExprBreak",lib));
            addAnnotation(make_smart<AstExpressionAnnotation<ExprContinue>>("ExprContinue",lib));
            /*
            addAnnotation(make_smart<AstExprConstAnnotation>(lib));
            addAnnotation(make_smart<AstExprFakeContextAnnotation>(lib));
            addAnnotation(make_smart<AstExprFakeLineInfoAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstPtrAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstEnumerationAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstBitfieldAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstInt8Annotation>(lib));
            addAnnotation(make_smart<AstExprConstInt16Annotation>(lib));
            addAnnotation(make_smart<AstExprConstInt64Annotation>(lib));
            addAnnotation(make_smart<AstExprConstIntAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstInt2Annotation>(lib));
            addAnnotation(make_smart<AstExprConstInt3Annotation>(lib));
            addAnnotation(make_smart<AstExprConstInt4Annotation>(lib));
            addAnnotation(make_smart<AstExprConstUInt8Annotation>(lib));
            addAnnotation(make_smart<AstExprConstUInt16Annotation>(lib));
            addAnnotation(make_smart<AstExprConstUInt64Annotation>(lib));
            addAnnotation(make_smart<AstExprConstUIntAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstUInt2Annotation>(lib));
            addAnnotation(make_smart<AstExprConstUInt3Annotation>(lib));
            addAnnotation(make_smart<AstExprConstUInt4Annotation>(lib));
            addAnnotation(make_smart<AstExprConstRangeAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstURangeAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstBoolAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstFloatAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstFloat2Annotation>(lib));
            addAnnotation(make_smart<AstExprConstFloat3Annotation>(lib));
            addAnnotation(make_smart<AstExprConstFloat4Annotation>(lib));
            addAnnotation(make_smart<AstExprConstStringAnnotation>(lib));
            addAnnotation(make_smart<AstExprConstDoubleAnnotation>(lib));
            addAnnotation(make_smart<AstExprMakeBlockAnnotation>(lib));
            addAnnotation(make_smart<AstExprMakeGeneratorAnnotation>(lib));
            addAnnotation(make_smart<AstExprMemZeroAnnotation>(lib));
        */
            // visitor
            addAnnotation(make_smart<AstVisitorAdapterAnnotation>(lib));
            addExtern<DAS_BIND_FUN(makeVisitor)>(*this, lib,  "make_visitor",
                SideEffects::modifyExternal, "makeVisitor");
            addExtern<DAS_BIND_FUN(thisProgram)>(*this, lib,  "ast_this_program",
                SideEffects::accessExternal, "thisProgram");
            addExtern<DAS_BIND_FUN(astVisit)>(*this, lib,  "ast_visit",
                SideEffects::accessExternal, "astVisit");
            // helper functions
            addExtern<DAS_BIND_FUN(ast_describe_typedecl)>(*this, lib,  "ast_describe_typedecl",
                SideEffects::none, "ast_describe_typedecl");
            addExtern<DAS_BIND_FUN(ast_describe_expression)>(*this, lib,  "ast_describe_expression",
                SideEffects::none, "ast_describe_expression");
            addExtern<DAS_BIND_FUN(ast_describe_function)>(*this, lib,  "ast_describe_function",
                SideEffects::none, "ast_describe_function");
            // type conversion functions
            addExtern<DAS_BIND_FUN(ast_das_to_string)>(*this, lib,  "ast_das_to_string",
                SideEffects::none, "ast_das_to_string");
            // add builtin module
            compileBuiltinModule("ast.das",ast_das,sizeof(ast_das));
            // lets make sure its all aot ready
            // verifyAotReady();
        }
        virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
            tw << "#include \"daScript/simulate/aot_builtin_ast.h\"\n";
            return ModuleAotType::hybrid;
        }
    };
}

REGISTER_MODULE_IN_NAMESPACE(Module_Ast,das);
