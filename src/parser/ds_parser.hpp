/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_DAS_YY_DS_PARSER_HPP_INCLUDED
# define YY_DAS_YY_DS_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef DAS_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define DAS_YYDEBUG 1
#  else
#   define DAS_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define DAS_YYDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined DAS_YYDEBUG */
#if DAS_YYDEBUG
extern int das_yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "ds_parser.ypp"

	#include "daScript/misc/platform.h"
	#include "daScript/ast/ast.h"
    #include "daScript/ast/ast_generate.h"
    #include "daScript/ast/ast_expressions.h"

    enum {
        CorM_COPY   = 0,
        CorM_MOVE   = (1<<0),
        CorM_CLONE  = (1<<1)
    };

    namespace das {
        extern ProgramPtr			    g_Program;
        extern FileAccessPtr            g_Access;
        extern vector<FileInfo *>	    g_FileAccessStack;
        extern das_map<string,string>   das_module_alias;
    }
    using namespace das;

    struct VariableDeclaration {
        VariableDeclaration ( const LineInfo & a, vector<string> * n, TypeDecl * t, Expression * i )
            : at(a), pNameList(n), pTypeDecl(t), pInit(i) {}
        virtual ~VariableDeclaration () {
            if ( pNameList ) delete pNameList;
            delete pTypeDecl;
            if ( pInit ) delete pInit;
            if ( annotation ) delete annotation;
        }
        LineInfo                at;
        vector<string>          *pNameList;
        TypeDecl                *pTypeDecl;
        Expression              *pInit;
        bool                    init_via_move = false;
        bool                    init_via_clone = false;
        bool                    override = false;
        AnnotationArgumentList  *annotation = nullptr;
    };

    ExprLooksLikeCall * parseFunctionArguments ( ExprLooksLikeCall * pCall, Expression * arguments );
    vector<ExpressionPtr> sequenceToList ( Expression * arguments );
    void deleteVariableDeclarationList ( vector<VariableDeclaration *> * list );
    void varDeclToTypeDecl ( TypeDecl * pType, vector<VariableDeclaration*> * list, bool needNames = false );

    LineInfo tokAt ( const struct YYLTYPE & li );
    LineInfo tokRangeAt ( const struct YYLTYPE & li, const struct YYLTYPE & lie );

    Annotation * findAnnotation ( const string & name, const LineInfo & at );

    extern bool das_need_oxford_comma;
    extern bool das_force_oxford_comma;
    extern bool das_supress_errors;

#line 110 "ds_parser.hpp"

/* Token type.  */
#ifndef DAS_YYTOKENTYPE
# define DAS_YYTOKENTYPE
  enum das_yytokentype
  {
    LEXER_ERROR = 258,
    DAS_STRUCT = 259,
    DAS_LET = 260,
    DAS_DEF = 261,
    DAS_WHILE = 262,
    DAS_IF = 263,
    DAS_STATIC_IF = 264,
    DAS_ELSE = 265,
    DAS_FOR = 266,
    DAS_CATCH = 267,
    DAS_TRUE = 268,
    DAS_FALSE = 269,
    DAS_NEWT = 270,
    DAS_TYPEINFO = 271,
    DAS_TYPE = 272,
    DAS_IN = 273,
    DAS_IS = 274,
    DAS_AS = 275,
    DAS_ELIF = 276,
    DAS_STATIC_ELIF = 277,
    DAS_ARRAY = 278,
    DAS_RETURN = 279,
    DAS_NULL = 280,
    DAS_BREAK = 281,
    DAS_TRY = 282,
    DAS_OPTIONS = 283,
    DAS_TABLE = 284,
    DAS_EXPECT = 285,
    DAS_CONST = 286,
    DAS_REQUIRE = 287,
    DAS_OPERATOR = 288,
    DAS_ENUM = 289,
    DAS_FINALLY = 290,
    DAS_DELETE = 291,
    DAS_DEREF = 292,
    DAS_SCOPE = 293,
    DAS_TYPEDEF = 294,
    DAS_WITH = 295,
    DAS_CAST = 296,
    DAS_OVERRIDE = 297,
    DAS_UPCAST = 298,
    DAS_ITERATOR = 299,
    DAS_VAR = 300,
    DAS_ADDR = 301,
    DAS_CONTINUE = 302,
    DAS_WHERE = 303,
    DAS_PASS = 304,
    DAS_REINTERPRET = 305,
    DAS_MODULE = 306,
    DAS_PUBLIC = 307,
    DAS_LABEL = 308,
    DAS_GOTO = 309,
    DAS_IMPLICIT = 310,
    DAS_SHARED = 311,
    DAS_SMART_PTR = 312,
    DAS_TBOOL = 313,
    DAS_TVOID = 314,
    DAS_TSTRING = 315,
    DAS_TAUTO = 316,
    DAS_TINT = 317,
    DAS_TINT2 = 318,
    DAS_TINT3 = 319,
    DAS_TINT4 = 320,
    DAS_TUINT = 321,
    DAS_TBITFIELD = 322,
    DAS_TUINT2 = 323,
    DAS_TUINT3 = 324,
    DAS_TUINT4 = 325,
    DAS_TFLOAT = 326,
    DAS_TFLOAT2 = 327,
    DAS_TFLOAT3 = 328,
    DAS_TFLOAT4 = 329,
    DAS_TRANGE = 330,
    DAS_TURANGE = 331,
    DAS_TBLOCK = 332,
    DAS_TINT64 = 333,
    DAS_TUINT64 = 334,
    DAS_TDOUBLE = 335,
    DAS_TFUNCTION = 336,
    DAS_TLAMBDA = 337,
    DAS_TINT8 = 338,
    DAS_TUINT8 = 339,
    DAS_TINT16 = 340,
    DAS_TUINT16 = 341,
    DAS_TTUPLE = 342,
    DAS_TVARIANT = 343,
    DAS_GENERATOR = 344,
    DAS_YIELD = 345,
    ADDEQU = 346,
    SUBEQU = 347,
    DIVEQU = 348,
    MULEQU = 349,
    MODEQU = 350,
    ANDEQU = 351,
    OREQU = 352,
    XOREQU = 353,
    SHL = 354,
    SHR = 355,
    ADDADD = 356,
    SUBSUB = 357,
    LEEQU = 358,
    SHLEQU = 359,
    SHREQU = 360,
    GREQU = 361,
    EQUEQU = 362,
    NOTEQU = 363,
    RARROW = 364,
    LARROW = 365,
    QQ = 366,
    QDOT = 367,
    QBRA = 368,
    LPIPE = 369,
    LBPIPE = 370,
    LAPIPE = 371,
    RPIPE = 372,
    CLONEEQU = 373,
    ROTL = 374,
    ROTR = 375,
    ROTLEQU = 376,
    ROTREQU = 377,
    MAPTO = 378,
    BRABRAB = 379,
    BRACBRB = 380,
    CBRCBRB = 381,
    INTEGER = 382,
    LONG_INTEGER = 383,
    UNSIGNED_INTEGER = 384,
    UNSIGNED_LONG_INTEGER = 385,
    FLOAT = 386,
    DOUBLE = 387,
    NAME = 388,
    BEGIN_STRING = 389,
    STRING_CHARACTER = 390,
    END_STRING = 391,
    BEGIN_STRING_EXPR = 392,
    END_STRING_EXPR = 393,
    UNARY_MINUS = 394,
    UNARY_PLUS = 395,
    PRE_INC = 396,
    PRE_DEC = 397,
    POST_INC = 398,
    POST_DEC = 399,
    DEREF = 400,
    COLCOL = 401
  };
#endif

/* Value type.  */
#if ! defined DAS_YYSTYPE && ! defined DAS_YYSTYPE_IS_DECLARED
union DAS_YYSTYPE
{
#line 83 "ds_parser.ypp"

    char                            ch;
    bool                            b;
    int32_t                         i;
    uint32_t                        ui;
    int64_t                         i64;
    uint64_t                        ui64;
    double                          d;
	double                          fd;
    string *                        s;
    vector<string> *                pNameList;
    vector<pair<string,LineInfo>> * pNameWithPosList;
    VariableDeclaration *           pVarDecl;
    vector<VariableDeclaration*> *  pVarDeclList;
    TypeDecl *                      pTypeDecl;
    Expression *                    pExpression;
    Type                            type;
    AnnotationArgument *            aa;
    AnnotationArgumentList *        aaList;
    AnnotationDeclaration *         fa;
    AnnotationList *                faList;
    MakeStruct *                    pMakeStruct;
    Enumeration *                   pEnum;
    Structure *                     pStructure;

#line 294 "ds_parser.hpp"

};
typedef union DAS_YYSTYPE DAS_YYSTYPE;
# define DAS_YYSTYPE_IS_TRIVIAL 1
# define DAS_YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined DAS_YYLTYPE && ! defined DAS_YYLTYPE_IS_DECLARED
typedef struct DAS_YYLTYPE DAS_YYLTYPE;
struct DAS_YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define DAS_YYLTYPE_IS_DECLARED 1
# define DAS_YYLTYPE_IS_TRIVIAL 1
#endif


extern DAS_YYSTYPE das_yylval;
extern DAS_YYLTYPE das_yylloc;
int das_yyparse (void);

#endif /* !YY_DAS_YY_DS_PARSER_HPP_INCLUDED  */
