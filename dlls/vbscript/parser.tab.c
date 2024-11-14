/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PARSER_STYPE
#define YYLTYPE         PARSER_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs

/* First part of user prologue.  */
#line 19 "dlls/vbscript/parser.y"


#include "vbscript.h"
#include "parse.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(vbscript);

static int parser_error(unsigned*,parser_ctx_t*,const char*);

static void handle_isexpression_script(parser_ctx_t *ctx, expression_t *expr);

static void source_add_statement(parser_ctx_t*,statement_t*);
static void source_add_class(parser_ctx_t*,class_decl_t*);

static void *new_expression(parser_ctx_t*,expression_type_t,size_t);
static expression_t *new_bool_expression(parser_ctx_t*,VARIANT_BOOL);
static expression_t *new_date_expression(parser_ctx_t*,DATE);
static expression_t *new_string_expression(parser_ctx_t*,const WCHAR*);
static expression_t *new_long_expression(parser_ctx_t*,expression_type_t,LONG);
static expression_t *new_double_expression(parser_ctx_t*,double);
static expression_t *new_unary_expression(parser_ctx_t*,expression_type_t,expression_t*);
static expression_t *new_binary_expression(parser_ctx_t*,expression_type_t,expression_t*,expression_t*);
static expression_t *new_new_expression(parser_ctx_t*,const WCHAR*);

static member_expression_t *new_member_expression(parser_ctx_t*,expression_t*,const WCHAR*);
static call_expression_t *new_call_expression(parser_ctx_t*,expression_t*,expression_t*);
static call_expression_t *make_call_expression(parser_ctx_t*,expression_t*,expression_t*);

static void *new_statement(parser_ctx_t*,statement_type_t,size_t,unsigned);
static statement_t *new_call_statement(parser_ctx_t*,unsigned,expression_t*);
static statement_t *new_assign_statement(parser_ctx_t*,unsigned,expression_t*,expression_t*);
static statement_t *new_set_statement(parser_ctx_t*,unsigned,expression_t*,expression_t*);
static statement_t *new_dim_statement(parser_ctx_t*,unsigned,dim_decl_t*);
static statement_t *new_redim_statement(parser_ctx_t*,unsigned,BOOL,redim_decl_t*);
static statement_t *new_while_statement(parser_ctx_t*,unsigned,statement_type_t,expression_t*,statement_t*);
static statement_t *new_forto_statement(parser_ctx_t*,unsigned,const WCHAR*,expression_t*,expression_t*,expression_t*,statement_t*);
static statement_t *new_foreach_statement(parser_ctx_t*,unsigned,const WCHAR*,expression_t*,statement_t*);
static statement_t *new_if_statement(parser_ctx_t*,unsigned,expression_t*,statement_t*,elseif_decl_t*,statement_t*);
static statement_t *new_function_statement(parser_ctx_t*,unsigned,function_decl_t*);
static statement_t *new_onerror_statement(parser_ctx_t*,unsigned,BOOL);
static statement_t *new_const_statement(parser_ctx_t*,unsigned,const_decl_t*);
static statement_t *new_select_statement(parser_ctx_t*,unsigned,expression_t*,case_clausule_t*);
static statement_t *new_with_statement(parser_ctx_t*,unsigned,expression_t*,statement_t*);

static dim_decl_t *new_dim_decl(parser_ctx_t*,const WCHAR*,BOOL,dim_list_t*);
static dim_list_t *new_dim(parser_ctx_t*,unsigned,dim_list_t*);
static redim_decl_t *new_redim_decl(parser_ctx_t*,const WCHAR*,expression_t*);
static elseif_decl_t *new_elseif_decl(parser_ctx_t*,unsigned,expression_t*,statement_t*);
static function_decl_t *new_function_decl(parser_ctx_t*,const WCHAR*,function_type_t,unsigned,arg_decl_t*,statement_t*);
static arg_decl_t *new_argument_decl(parser_ctx_t*,const WCHAR*,BOOL);
static const_decl_t *new_const_decl(parser_ctx_t*,const WCHAR*,expression_t*);
static case_clausule_t *new_case_clausule(parser_ctx_t*,expression_t*,statement_t*,case_clausule_t*);

static class_decl_t *new_class_decl(parser_ctx_t*);
static class_decl_t *add_class_function(parser_ctx_t*,class_decl_t*,function_decl_t*);
static class_decl_t *add_dim_prop(parser_ctx_t*,class_decl_t*,dim_decl_t*,unsigned);

static statement_t *link_statements(statement_t*,statement_t*);

#define STORAGE_IS_PRIVATE    1
#define STORAGE_IS_DEFAULT    2

#define CHECK_ERROR if(((parser_ctx_t*)ctx)->hres != S_OK) YYABORT

#define PARSER_LTYPE unsigned
#define YYLLOC_DEFAULT(Cur, Rhs, N) Cur = YYRHSLOC((Rhs), (N) ? 1 : 0)


#line 149 "dlls/vbscript/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER_DEBUG 1
#  else
#   define PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER_DEBUG */
#if PARSER_DEBUG
extern int parser_debug;
#endif

/* Token kinds.  */
#ifndef PARSER_TOKENTYPE
# define PARSER_TOKENTYPE
  enum parser_tokentype
  {
    PARSER_EMPTY = -2,
    PARSER_EOF = 0,                /* "end of file"  */
    PARSER_error = 256,            /* error  */
    PARSER_UNDEF = 257,            /* "invalid token"  */
    tEXPRESSION = 258,             /* tEXPRESSION  */
    tNL = 259,                     /* tNL  */
    tEMPTYBRACKETS = 260,          /* tEMPTYBRACKETS  */
    tEXPRLBRACKET = 261,           /* tEXPRLBRACKET  */
    tLTEQ = 262,                   /* tLTEQ  */
    tGTEQ = 263,                   /* tGTEQ  */
    tNEQ = 264,                    /* tNEQ  */
    tSTOP = 265,                   /* tSTOP  */
    tME = 266,                     /* tME  */
    tREM = 267,                    /* tREM  */
    tDOT = 268,                    /* tDOT  */
    tTRUE = 269,                   /* tTRUE  */
    tFALSE = 270,                  /* tFALSE  */
    tNOT = 271,                    /* tNOT  */
    tAND = 272,                    /* tAND  */
    tOR = 273,                     /* tOR  */
    tXOR = 274,                    /* tXOR  */
    tEQV = 275,                    /* tEQV  */
    tIMP = 276,                    /* tIMP  */
    tIS = 277,                     /* tIS  */
    tMOD = 278,                    /* tMOD  */
    tCALL = 279,                   /* tCALL  */
    tSUB = 280,                    /* tSUB  */
    tFUNCTION = 281,               /* tFUNCTION  */
    tGET = 282,                    /* tGET  */
    tLET = 283,                    /* tLET  */
    tCONST = 284,                  /* tCONST  */
    tDIM = 285,                    /* tDIM  */
    tREDIM = 286,                  /* tREDIM  */
    tPRESERVE = 287,               /* tPRESERVE  */
    tIF = 288,                     /* tIF  */
    tELSE = 289,                   /* tELSE  */
    tELSEIF = 290,                 /* tELSEIF  */
    tEND = 291,                    /* tEND  */
    tTHEN = 292,                   /* tTHEN  */
    tEXIT = 293,                   /* tEXIT  */
    tWHILE = 294,                  /* tWHILE  */
    tWEND = 295,                   /* tWEND  */
    tDO = 296,                     /* tDO  */
    tLOOP = 297,                   /* tLOOP  */
    tUNTIL = 298,                  /* tUNTIL  */
    tFOR = 299,                    /* tFOR  */
    tTO = 300,                     /* tTO  */
    tEACH = 301,                   /* tEACH  */
    tIN = 302,                     /* tIN  */
    tSELECT = 303,                 /* tSELECT  */
    tCASE = 304,                   /* tCASE  */
    tWITH = 305,                   /* tWITH  */
    tBYREF = 306,                  /* tBYREF  */
    tBYVAL = 307,                  /* tBYVAL  */
    tOPTION = 308,                 /* tOPTION  */
    tNOTHING = 309,                /* tNOTHING  */
    tEMPTY = 310,                  /* tEMPTY  */
    tNULL = 311,                   /* tNULL  */
    tCLASS = 312,                  /* tCLASS  */
    tSET = 313,                    /* tSET  */
    tNEW = 314,                    /* tNEW  */
    tPUBLIC = 315,                 /* tPUBLIC  */
    tPRIVATE = 316,                /* tPRIVATE  */
    tNEXT = 317,                   /* tNEXT  */
    tON = 318,                     /* tON  */
    tRESUME = 319,                 /* tRESUME  */
    tGOTO = 320,                   /* tGOTO  */
    tIdentifier = 321,             /* tIdentifier  */
    tString = 322,                 /* tString  */
    tDEFAULT = 323,                /* tDEFAULT  */
    tERROR = 324,                  /* tERROR  */
    tEXPLICIT = 325,               /* tEXPLICIT  */
    tPROPERTY = 326,               /* tPROPERTY  */
    tSTEP = 327,                   /* tSTEP  */
    tInt = 328,                    /* tInt  */
    tDouble = 329,                 /* tDouble  */
    tDate = 330                    /* tDate  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 96 "dlls/vbscript/parser.y"

    const WCHAR *string;
    statement_t *statement;
    expression_t *expression;
    member_expression_t *member;
    elseif_decl_t *elseif;
    dim_decl_t *dim_decl;
    dim_list_t *dim_list;
    redim_decl_t *redim_decl;
    function_decl_t *func_decl;
    arg_decl_t *arg_decl;
    class_decl_t *class_decl;
    const_decl_t *const_decl;
    case_clausule_t *case_clausule;
    unsigned uint;
    LONG integer;
    BOOL boolean;
    double dbl;
    DATE date;

#line 300 "dlls/vbscript/parser.tab.c"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined PARSER_LTYPE && ! defined PARSER_LTYPE_IS_DECLARED
typedef struct PARSER_LTYPE PARSER_LTYPE;
struct PARSER_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define PARSER_LTYPE_IS_DECLARED 1
# define PARSER_LTYPE_IS_TRIVIAL 1
#endif




int parser_parse (parser_ctx_t *ctx);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tEXPRESSION = 3,                /* tEXPRESSION  */
  YYSYMBOL_tNL = 4,                        /* tNL  */
  YYSYMBOL_tEMPTYBRACKETS = 5,             /* tEMPTYBRACKETS  */
  YYSYMBOL_tEXPRLBRACKET = 6,              /* tEXPRLBRACKET  */
  YYSYMBOL_tLTEQ = 7,                      /* tLTEQ  */
  YYSYMBOL_tGTEQ = 8,                      /* tGTEQ  */
  YYSYMBOL_tNEQ = 9,                       /* tNEQ  */
  YYSYMBOL_tSTOP = 10,                     /* tSTOP  */
  YYSYMBOL_tME = 11,                       /* tME  */
  YYSYMBOL_tREM = 12,                      /* tREM  */
  YYSYMBOL_tDOT = 13,                      /* tDOT  */
  YYSYMBOL_tTRUE = 14,                     /* tTRUE  */
  YYSYMBOL_tFALSE = 15,                    /* tFALSE  */
  YYSYMBOL_tNOT = 16,                      /* tNOT  */
  YYSYMBOL_tAND = 17,                      /* tAND  */
  YYSYMBOL_tOR = 18,                       /* tOR  */
  YYSYMBOL_tXOR = 19,                      /* tXOR  */
  YYSYMBOL_tEQV = 20,                      /* tEQV  */
  YYSYMBOL_tIMP = 21,                      /* tIMP  */
  YYSYMBOL_tIS = 22,                       /* tIS  */
  YYSYMBOL_tMOD = 23,                      /* tMOD  */
  YYSYMBOL_tCALL = 24,                     /* tCALL  */
  YYSYMBOL_tSUB = 25,                      /* tSUB  */
  YYSYMBOL_tFUNCTION = 26,                 /* tFUNCTION  */
  YYSYMBOL_tGET = 27,                      /* tGET  */
  YYSYMBOL_tLET = 28,                      /* tLET  */
  YYSYMBOL_tCONST = 29,                    /* tCONST  */
  YYSYMBOL_tDIM = 30,                      /* tDIM  */
  YYSYMBOL_tREDIM = 31,                    /* tREDIM  */
  YYSYMBOL_tPRESERVE = 32,                 /* tPRESERVE  */
  YYSYMBOL_tIF = 33,                       /* tIF  */
  YYSYMBOL_tELSE = 34,                     /* tELSE  */
  YYSYMBOL_tELSEIF = 35,                   /* tELSEIF  */
  YYSYMBOL_tEND = 36,                      /* tEND  */
  YYSYMBOL_tTHEN = 37,                     /* tTHEN  */
  YYSYMBOL_tEXIT = 38,                     /* tEXIT  */
  YYSYMBOL_tWHILE = 39,                    /* tWHILE  */
  YYSYMBOL_tWEND = 40,                     /* tWEND  */
  YYSYMBOL_tDO = 41,                       /* tDO  */
  YYSYMBOL_tLOOP = 42,                     /* tLOOP  */
  YYSYMBOL_tUNTIL = 43,                    /* tUNTIL  */
  YYSYMBOL_tFOR = 44,                      /* tFOR  */
  YYSYMBOL_tTO = 45,                       /* tTO  */
  YYSYMBOL_tEACH = 46,                     /* tEACH  */
  YYSYMBOL_tIN = 47,                       /* tIN  */
  YYSYMBOL_tSELECT = 48,                   /* tSELECT  */
  YYSYMBOL_tCASE = 49,                     /* tCASE  */
  YYSYMBOL_tWITH = 50,                     /* tWITH  */
  YYSYMBOL_tBYREF = 51,                    /* tBYREF  */
  YYSYMBOL_tBYVAL = 52,                    /* tBYVAL  */
  YYSYMBOL_tOPTION = 53,                   /* tOPTION  */
  YYSYMBOL_tNOTHING = 54,                  /* tNOTHING  */
  YYSYMBOL_tEMPTY = 55,                    /* tEMPTY  */
  YYSYMBOL_tNULL = 56,                     /* tNULL  */
  YYSYMBOL_tCLASS = 57,                    /* tCLASS  */
  YYSYMBOL_tSET = 58,                      /* tSET  */
  YYSYMBOL_tNEW = 59,                      /* tNEW  */
  YYSYMBOL_tPUBLIC = 60,                   /* tPUBLIC  */
  YYSYMBOL_tPRIVATE = 61,                  /* tPRIVATE  */
  YYSYMBOL_tNEXT = 62,                     /* tNEXT  */
  YYSYMBOL_tON = 63,                       /* tON  */
  YYSYMBOL_tRESUME = 64,                   /* tRESUME  */
  YYSYMBOL_tGOTO = 65,                     /* tGOTO  */
  YYSYMBOL_tIdentifier = 66,               /* tIdentifier  */
  YYSYMBOL_tString = 67,                   /* tString  */
  YYSYMBOL_tDEFAULT = 68,                  /* tDEFAULT  */
  YYSYMBOL_tERROR = 69,                    /* tERROR  */
  YYSYMBOL_tEXPLICIT = 70,                 /* tEXPLICIT  */
  YYSYMBOL_tPROPERTY = 71,                 /* tPROPERTY  */
  YYSYMBOL_tSTEP = 72,                     /* tSTEP  */
  YYSYMBOL_tInt = 73,                      /* tInt  */
  YYSYMBOL_tDouble = 74,                   /* tDouble  */
  YYSYMBOL_tDate = 75,                     /* tDate  */
  YYSYMBOL_76_ = 76,                       /* ':'  */
  YYSYMBOL_77_ = 77,                       /* '='  */
  YYSYMBOL_78_0_ = 78,                     /* '0'  */
  YYSYMBOL_79_ = 79,                       /* '.'  */
  YYSYMBOL_80_ = 80,                       /* '('  */
  YYSYMBOL_81_ = 81,                       /* ')'  */
  YYSYMBOL_82_ = 82,                       /* ','  */
  YYSYMBOL_83_ = 83,                       /* '-'  */
  YYSYMBOL_84_ = 84,                       /* '>'  */
  YYSYMBOL_85_ = 85,                       /* '<'  */
  YYSYMBOL_86_ = 86,                       /* '&'  */
  YYSYMBOL_87_ = 87,                       /* '+'  */
  YYSYMBOL_88_ = 88,                       /* '\\'  */
  YYSYMBOL_89_ = 89,                       /* '*'  */
  YYSYMBOL_90_ = 90,                       /* '/'  */
  YYSYMBOL_91_ = 91,                       /* '^'  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_Program = 93,                   /* Program  */
  YYSYMBOL_OptionExplicit_opt = 94,        /* OptionExplicit_opt  */
  YYSYMBOL_SourceElements = 95,            /* SourceElements  */
  YYSYMBOL_GlobalDimDeclaration = 96,      /* GlobalDimDeclaration  */
  YYSYMBOL_ExpressionNl_opt = 97,          /* ExpressionNl_opt  */
  YYSYMBOL_BodyStatements = 98,            /* BodyStatements  */
  YYSYMBOL_StatementsNl_opt = 99,          /* StatementsNl_opt  */
  YYSYMBOL_StatementsNl = 100,             /* StatementsNl  */
  YYSYMBOL_StatementNl = 101,              /* StatementNl  */
  YYSYMBOL_Statement = 102,                /* Statement  */
  YYSYMBOL_SimpleStatement = 103,          /* SimpleStatement  */
  YYSYMBOL_MemberExpression = 104,         /* MemberExpression  */
  YYSYMBOL_Preserve_opt = 105,             /* Preserve_opt  */
  YYSYMBOL_ReDimDecl = 106,                /* ReDimDecl  */
  YYSYMBOL_ReDimDeclList = 107,            /* ReDimDeclList  */
  YYSYMBOL_DimDeclList = 108,              /* DimDeclList  */
  YYSYMBOL_DimDecl = 109,                  /* DimDecl  */
  YYSYMBOL_DimList = 110,                  /* DimList  */
  YYSYMBOL_ConstDeclList = 111,            /* ConstDeclList  */
  YYSYMBOL_ConstDecl = 112,                /* ConstDecl  */
  YYSYMBOL_ConstExpression = 113,          /* ConstExpression  */
  YYSYMBOL_DoType = 114,                   /* DoType  */
  YYSYMBOL_Step_opt = 115,                 /* Step_opt  */
  YYSYMBOL_IfStatement = 116,              /* IfStatement  */
  YYSYMBOL_EndIf_opt = 117,                /* EndIf_opt  */
  YYSYMBOL_ElseIfs_opt = 118,              /* ElseIfs_opt  */
  YYSYMBOL_ElseIfs = 119,                  /* ElseIfs  */
  YYSYMBOL_ElseIf = 120,                   /* ElseIf  */
  YYSYMBOL_Else_opt = 121,                 /* Else_opt  */
  YYSYMBOL_CaseClausules = 122,            /* CaseClausules  */
  YYSYMBOL_Arguments = 123,                /* Arguments  */
  YYSYMBOL_ArgumentList_opt = 124,         /* ArgumentList_opt  */
  YYSYMBOL_ArgumentList = 125,             /* ArgumentList  */
  YYSYMBOL_EmptyBrackets_opt = 126,        /* EmptyBrackets_opt  */
  YYSYMBOL_ExpressionList = 127,           /* ExpressionList  */
  YYSYMBOL_Expression = 128,               /* Expression  */
  YYSYMBOL_EqvExpression = 129,            /* EqvExpression  */
  YYSYMBOL_XorExpression = 130,            /* XorExpression  */
  YYSYMBOL_OrExpression = 131,             /* OrExpression  */
  YYSYMBOL_AndExpression = 132,            /* AndExpression  */
  YYSYMBOL_NotExpression = 133,            /* NotExpression  */
  YYSYMBOL_EqualityExpression = 134,       /* EqualityExpression  */
  YYSYMBOL_ConcatExpression = 135,         /* ConcatExpression  */
  YYSYMBOL_AdditiveExpression = 136,       /* AdditiveExpression  */
  YYSYMBOL_ModExpression = 137,            /* ModExpression  */
  YYSYMBOL_IntdivExpression = 138,         /* IntdivExpression  */
  YYSYMBOL_MultiplicativeExpression = 139, /* MultiplicativeExpression  */
  YYSYMBOL_ExpExpression = 140,            /* ExpExpression  */
  YYSYMBOL_SignExpression = 141,           /* SignExpression  */
  YYSYMBOL_UnaryExpression = 142,          /* UnaryExpression  */
  YYSYMBOL_CallExpression = 143,           /* CallExpression  */
  YYSYMBOL_LiteralExpression = 144,        /* LiteralExpression  */
  YYSYMBOL_NumericLiteralExpression = 145, /* NumericLiteralExpression  */
  YYSYMBOL_IntegerValue = 146,             /* IntegerValue  */
  YYSYMBOL_PrimaryExpression = 147,        /* PrimaryExpression  */
  YYSYMBOL_ClassDeclaration = 148,         /* ClassDeclaration  */
  YYSYMBOL_ClassBody = 149,                /* ClassBody  */
  YYSYMBOL_PropertyDecl = 150,             /* PropertyDecl  */
  YYSYMBOL_FunctionDecl = 151,             /* FunctionDecl  */
  YYSYMBOL_Storage_opt = 152,              /* Storage_opt  */
  YYSYMBOL_Storage = 153,                  /* Storage  */
  YYSYMBOL_ArgumentsDecl_opt = 154,        /* ArgumentsDecl_opt  */
  YYSYMBOL_ArgumentsDecl = 155,            /* ArgumentsDecl  */
  YYSYMBOL_ArgumentDeclList = 156,         /* ArgumentDeclList  */
  YYSYMBOL_ArgumentDecl = 157,             /* ArgumentDecl  */
  YYSYMBOL_Identifier = 158,               /* Identifier  */
  YYSYMBOL_StSep_opt = 159,                /* StSep_opt  */
  YYSYMBOL_Nl_opt = 160,                   /* Nl_opt  */
  YYSYMBOL_StSep = 161                     /* StSep  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL \
             && defined PARSER_STYPE_IS_TRIVIAL && PARSER_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  391

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,     2,
      80,    81,    89,    87,    82,    83,    79,    90,    78,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,     2,
      85,    77,    84,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    88,     2,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   163,   163,   164,   167,   168,   171,   172,   174,   175,
     178,   179,   180,   181,   184,   185,   188,   189,   190,   193,
     194,   197,   198,   201,   204,   205,   206,   207,   208,   211,
     213,   214,   216,   217,   218,   219,   221,   224,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   241,   243,   245,   249,   250,   251,   255,   256,   259,
     262,   263,   266,   267,   270,   271,   272,   275,   276,   279,
     280,   283,   286,   287,   290,   291,   294,   295,   298,   300,
     301,   305,   306,   309,   310,   313,   314,   317,   321,   322,
     325,   326,   327,   330,   331,   334,   335,   338,   339,   340,
     343,   344,   347,   348,   351,   352,   355,   356,   359,   360,
     363,   364,   367,   368,   371,   372,   375,   376,   377,   378,
     379,   380,   381,   382,   385,   386,   389,   390,   391,   394,
     395,   398,   399,   403,   404,   406,   410,   411,   414,   415,
     416,   419,   420,   421,   424,   425,   426,   430,   431,   432,
     433,   434,   435,   436,   437,   440,   441,   442,   445,   446,
     449,   450,   453,   456,   457,   458,   460,   462,   464,   465,
     466,   467,   470,   472,   474,   478,   480,   482,   484,   488,
     489,   492,   493,   494,   497,   498,   501,   502,   505,   506,
     509,   510,   511,   515,   516,   517,   518,   519,   520,   523,
     524,   527,   528,   532,   533,   534,   535
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if PARSER_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tEXPRESSION", "tNL",
  "tEMPTYBRACKETS", "tEXPRLBRACKET", "tLTEQ", "tGTEQ", "tNEQ", "tSTOP",
  "tME", "tREM", "tDOT", "tTRUE", "tFALSE", "tNOT", "tAND", "tOR", "tXOR",
  "tEQV", "tIMP", "tIS", "tMOD", "tCALL", "tSUB", "tFUNCTION", "tGET",
  "tLET", "tCONST", "tDIM", "tREDIM", "tPRESERVE", "tIF", "tELSE",
  "tELSEIF", "tEND", "tTHEN", "tEXIT", "tWHILE", "tWEND", "tDO", "tLOOP",
  "tUNTIL", "tFOR", "tTO", "tEACH", "tIN", "tSELECT", "tCASE", "tWITH",
  "tBYREF", "tBYVAL", "tOPTION", "tNOTHING", "tEMPTY", "tNULL", "tCLASS",
  "tSET", "tNEW", "tPUBLIC", "tPRIVATE", "tNEXT", "tON", "tRESUME",
  "tGOTO", "tIdentifier", "tString", "tDEFAULT", "tERROR", "tEXPLICIT",
  "tPROPERTY", "tSTEP", "tInt", "tDouble", "tDate", "':'", "'='", "'0'",
  "'.'", "'('", "')'", "','", "'-'", "'>'", "'<'", "'&'", "'+'", "'\\\\'",
  "'*'", "'/'", "'^'", "$accept", "Program", "OptionExplicit_opt",
  "SourceElements", "GlobalDimDeclaration", "ExpressionNl_opt",
  "BodyStatements", "StatementsNl_opt", "StatementsNl", "StatementNl",
  "Statement", "SimpleStatement", "MemberExpression", "Preserve_opt",
  "ReDimDecl", "ReDimDeclList", "DimDeclList", "DimDecl", "DimList",
  "ConstDeclList", "ConstDecl", "ConstExpression", "DoType", "Step_opt",
  "IfStatement", "EndIf_opt", "ElseIfs_opt", "ElseIfs", "ElseIf",
  "Else_opt", "CaseClausules", "Arguments", "ArgumentList_opt",
  "ArgumentList", "EmptyBrackets_opt", "ExpressionList", "Expression",
  "EqvExpression", "XorExpression", "OrExpression", "AndExpression",
  "NotExpression", "EqualityExpression", "ConcatExpression",
  "AdditiveExpression", "ModExpression", "IntdivExpression",
  "MultiplicativeExpression", "ExpExpression", "SignExpression",
  "UnaryExpression", "CallExpression", "LiteralExpression",
  "NumericLiteralExpression", "IntegerValue", "PrimaryExpression",
  "ClassDeclaration", "ClassBody", "PropertyDecl", "FunctionDecl",
  "Storage_opt", "Storage", "ArgumentsDecl_opt", "ArgumentsDecl",
  "ArgumentDeclList", "ArgumentDecl", "Identifier", "StSep_opt", "Nl_opt",
  "StSep", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-299)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-182)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,   471,   -22,    51,  -299,   471,  -299,    -5,  -299,  -299,
     471,  -299,  -299,  -299,   360,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,   542,   542,  -299,  -299,
     106,    85,   107,   121,   125,  -299,    23,    60,   -48,   129,
      80,    61,    84,  -299,  -299,    35,  -299,  -299,  -299,  -299,
      40,  -299,   621,    -9,  -299,  -299,  -299,  -299,  -299,  -299,
     471,   471,   471,   471,   471,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
    -299,   113,   368,  -299,    40,    40,  -299,  -299,   730,   360,
     360,   141,   471,   118,   471,    82,   402,   136,   471,   360,
     299,   161,   252,   127,   800,    40,  -299,   183,   122,  -299,
     332,  -299,  -299,   176,  -299,  -299,    85,   107,   121,   125,
    -299,    60,    60,    60,    60,    60,    60,    60,   -48,   129,
     129,    80,    61,    84,    84,  -299,  -299,   368,   124,     8,
    -299,  -299,  -299,  -299,   112,   134,  -299,   131,    14,  -299,
     154,    98,  -299,  -299,  -299,  -299,  -299,     3,  -299,  -299,
     471,  1068,   360,   157,   471,     3,    40,    32,   360,   198,
    -299,   360,  -299,   173,   178,  -299,  -299,  -299,  -299,   800,
     471,  -299,  -299,   360,   360,  -299,  -299,   368,   360,   201,
     360,  -299,   -18,   170,   169,  -299,   690,  1135,     3,   212,
    -299,    40,   211,   471,     3,  1202,   117,   471,  -299,  -299,
     199,   182,  -299,  -299,   241,     4,     4,  -299,  -299,   148,
    -299,  -299,  -299,  -299,  -299,   186,   181,   368,   154,  1001,
      13,   231,  1068,    19,  1001,   471,     5,   223,   237,   360,
     242,    40,    40,    92,   214,   241,  -299,  -299,  -299,   424,
     273,   867,   273,   867,  -299,  -299,   -18,   202,  -299,   247,
     934,   253,  -299,  -299,   245,   471,  -299,     3,   471,   446,
     254,   239,    40,   235,   117,   117,    -6,    40,   360,   360,
     219,   213,   296,   273,   867,   270,   867,   183,   867,   271,
    -299,  -299,   471,   274,  -299,   247,   275,  -299,  -299,   241,
    1269,    -8,    40,    40,    21,   261,  -299,   117,    40,  -299,
    -299,   360,   360,   360,   117,   296,   296,  -299,   424,  -299,
    -299,  -299,   278,   290,  -299,   280,   293,   103,    40,   289,
    -299,  -299,   264,   471,    40,  1202,  -299,  1001,   471,  -299,
    -299,  -299,    18,   250,   251,  -299,  -299,  -299,  -299,   308,
    -299,   309,  -299,    40,  1202,   303,  -299,   241,  1269,  -299,
     223,  -299,    40,  -299,   424,   424,  -299,  -299,  1001,  -299,
    -299,   282,  -299,   867,   259,   268,  -299,  -299,   316,    40,
      40,   284,   867,   867,  -299,   317,   320,   286,   287,  -299,
    -299
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    14,     0,     0,     6,     0,   161,     0,   147,   148,
       0,   154,   152,   153,     0,   193,   149,   194,   195,   196,
     197,   198,   156,   157,   150,   155,     0,     0,     3,   145,
       0,   104,   106,   108,   110,   112,   114,   116,   124,   126,
     129,   131,   133,   136,   138,   142,   141,   151,   144,    54,
       0,     1,   179,     0,    56,   115,   143,   139,   140,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,   146,   203,   204,     5,    46,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,    24,     0,     8,     0,    26,    34,
      95,     9,    39,     0,   180,   160,   105,   107,   109,   111,
     113,   122,   121,   118,   123,   117,   119,   120,   125,   128,
     127,   130,   132,   134,   135,   137,    55,     0,     0,    97,
     205,   206,    30,    49,    69,     0,    32,    62,    64,    58,
       0,     0,    44,    42,    40,    41,    43,     0,    74,    75,
       0,   179,     0,     0,     0,     0,     0,     0,     0,   194,
      13,     0,    12,     0,   182,   183,    25,     7,    23,    28,
       0,    29,    96,     0,     0,    99,    94,     0,     0,     0,
       0,    66,     0,     0,    60,    33,   179,   179,     0,     0,
      20,     0,     0,     0,     0,   179,   179,     0,    11,    10,
       0,     0,   181,    27,    31,     0,     0,    98,    70,     0,
      71,    72,    63,   159,   158,     0,    67,     0,     0,    19,
      81,     0,   179,    38,    21,     0,     0,    90,     0,     0,
       0,   170,   164,     0,   180,    45,    47,    48,   186,     0,
     201,   179,   201,   179,    73,    65,     0,     0,    61,    83,
     179,     0,    79,    35,     0,     0,    22,     0,     0,     0,
       0,     0,   168,     0,   179,   179,     0,   166,     0,     0,
       0,   188,   100,   201,   179,     0,   179,    17,   179,     0,
      68,    59,     0,    88,    84,    85,    81,    82,    36,    37,
     179,    76,   199,   199,   102,     0,    53,   179,     0,   171,
     165,     0,     0,     0,   179,   100,   100,   187,     0,   101,
     190,   202,     0,     0,    18,     0,     0,     0,   199,     0,
      86,    80,     0,     0,     0,   179,   200,    19,     0,    52,
     169,   162,   184,     0,     0,   167,   191,   192,   189,     0,
     175,     0,   177,   199,   179,     0,    51,    77,   179,    91,
      90,   103,     0,   185,     0,     0,   176,   178,    19,    89,
      78,     0,    92,   179,     0,     0,    87,    50,     0,     0,
       0,     0,   179,   179,   172,     0,     0,     0,     0,   173,
     174
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,  -299,  -299,  -299,  -299,  -250,  -140,   126,   310,
     -51,  -151,  -299,  -299,  -299,   133,   -86,   137,   110,    12,
    -299,  -299,   130,  -299,  -299,    76,  -299,    78,  -299,  -299,
      15,  -299,  -299,   -96,   -76,    39,     1,   318,   319,   323,
     326,     7,  -299,   494,   321,   168,   315,   337,   171,    43,
     304,   -41,   205,   177,  -299,  -299,  -299,  -108,  -299,  -201,
    -178,  -173,  -299,  -212,  -298,  -299,   -14,  -285,  -227,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    52,   105,    28,   285,   199,   200,   286,
     287,   108,    29,   150,   194,   195,   146,   147,   225,   143,
     144,   220,   160,   334,   109,   262,   293,   294,   295,   329,
     270,    83,   181,   138,   320,   303,   139,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   226,    48,   111,   240,   241,   112,
     113,   114,   362,   250,   280,   281,    49,   335,   284,   336
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   107,    30,   289,   252,   242,    53,    84,    84,   248,
     201,   110,    60,    60,   182,   170,   172,    55,   337,   191,
     348,   311,   312,   248,    60,   288,    60,     1,   243,    60,
      65,    66,    67,   244,   322,    73,   324,    80,   325,    74,
      80,   185,    60,   354,    84,    68,   201,   260,    50,   261,
     268,    51,   313,   176,   201,   223,   321,   231,   158,   167,
     224,    54,   159,   110,   333,   238,   374,   375,   368,    57,
      58,   120,   115,   242,   242,   145,   148,     2,   201,    85,
      85,   201,   163,   201,   249,   166,    84,   148,   148,   259,
     187,   217,   264,   151,   192,   157,   243,   243,   249,   165,
      69,   244,   244,   338,   222,    61,   242,    70,    71,   207,
      59,    81,    82,   242,    81,    82,    85,   183,   184,    60,
     110,   158,   135,   378,    60,   159,    62,    60,   213,   243,
     363,   257,   385,   386,   244,   196,   243,    86,   110,    63,
     353,   244,    64,   152,   153,   230,    72,   239,   202,   201,
      77,    78,    75,  -163,   145,   110,   110,   145,    85,   154,
     332,   198,   155,   276,   110,   204,   309,   310,    76,   215,
     216,   140,   141,   149,   145,    79,   148,   174,   175,   136,
     208,   214,   161,   209,   201,   164,   201,   178,   110,   156,
     168,   110,   177,   110,   188,   359,   173,   360,   179,   340,
     218,   183,   184,   201,   236,   186,   345,   201,   245,   296,
     110,   189,   110,   190,   369,     8,     9,   201,   371,   110,
     193,    22,    23,  -181,  -181,   148,    25,    15,   376,   169,
      18,    19,    20,    21,   203,   282,   267,   210,   211,   346,
     347,   129,   130,   110,   197,   110,   212,   110,   133,   134,
     227,   228,   205,   206,   233,    11,    12,    13,   235,   110,
     247,   246,    60,   256,   315,   316,   299,   255,    16,   301,
     304,   263,   269,   271,    22,    23,    24,   283,   273,    25,
     277,   171,   292,   291,   219,   232,   297,   298,   234,   306,
     305,   237,   308,   327,   110,   318,   110,   342,   343,   344,
     317,   319,   251,   253,   282,     5,   323,   326,   328,   339,
       6,   261,     7,   110,   349,   350,   351,   110,    15,   352,
      17,    18,    19,    20,    21,   355,   356,   110,   274,   275,
     364,   365,   110,   366,   357,   367,   370,    80,     5,   304,
     379,   110,   110,     6,   377,     7,     8,     9,    10,   380,
     282,   282,   381,   387,   300,   384,   388,   389,   390,   307,
     266,   258,   106,   265,   314,    15,   290,    17,    18,    19,
      20,    21,   331,   330,     5,   372,   272,   361,   116,     6,
     117,     7,     8,     9,    10,   118,    11,    12,    13,   119,
     131,    14,   142,   128,   221,   341,   254,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,   180,
      25,    81,    82,   132,   137,    26,     0,     0,     0,    27,
       0,   358,    11,    12,    13,     0,    15,    14,    17,    18,
      19,    20,    21,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,    25,     0,   162,   373,
     137,    26,     5,     0,     0,    27,     0,     6,     0,     7,
       8,     9,    10,     0,     0,     0,   382,   383,    15,     0,
      17,    18,    19,    20,    21,   278,   279,     5,     0,     0,
     302,     0,     6,     0,     7,     8,     9,    10,     0,     0,
      15,     0,    17,    18,    19,    20,    21,     0,     0,     0,
      11,    12,    13,     0,     0,    14,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,    25,    11,    12,    13,     0,    26,
      14,     0,     0,    27,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     5,    25,
       0,     0,     0,     6,    26,     7,     8,     9,    27,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,    14,     0,     0,     0,     0,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
      25,    -2,     0,     0,     0,    26,     0,     5,     0,    27,
       0,    87,     6,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
      89,    90,    91,     0,    92,     0,     0,     0,     0,    93,
      94,     0,    95,     0,     0,    96,     0,     0,     0,    97,
       0,    98,     0,     0,     0,     0,     0,     0,    99,   100,
       0,   101,   102,     0,   103,     0,     0,    15,     0,    17,
      18,    19,    20,    21,   229,     0,     5,   104,     0,     0,
      87,     6,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,    89,
      90,    91,     0,    92,     0,     0,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,     5,     0,    97,     0,
      98,     6,     0,     7,     8,     9,     0,     0,   100,     0,
     174,   175,     0,   103,     0,     0,    15,     0,    17,    18,
      19,    20,    21,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,     0,    14,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     5,     0,    25,     0,
      87,     6,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,  -179,  -179,     0,     0,    89,
      90,    91,     0,    92,     0,     0,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,     0,     0,    97,     0,
      98,     0,     0,     0,     0,     0,     0,     0,   100,     0,
     174,   175,     0,   103,     0,     0,    15,     0,    17,    18,
      19,    20,    21,     5,     0,     0,   104,    87,     6,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,    89,    90,    91,     0,
      92,     0,     0,   -16,     0,    93,    94,     0,    95,     0,
       0,    96,     0,     0,     0,    97,     0,    98,     0,     0,
       0,     0,     0,     0,     0,   100,     0,   174,   175,     0,
     103,     0,     0,    15,     0,    17,    18,    19,    20,    21,
       5,     0,     0,   104,    87,     6,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,    89,    90,    91,     0,    92,     0,     0,
       0,     0,    93,    94,     0,    95,     0,     0,    96,     0,
       0,     0,    97,     0,    98,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   174,   175,     0,   103,     0,     0,
      15,     0,    17,    18,    19,    20,    21,     5,     0,     0,
     104,    87,     6,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,  -179,  -179,     0,     0,
      89,    90,    91,     0,    92,     0,     0,     0,     0,    93,
      94,     0,    95,     0,     0,    96,     0,     0,     0,    97,
       0,    98,     0,     0,     0,     0,     0,     0,     0,   100,
       0,   174,   175,     0,   103,     0,     0,    15,     0,    17,
      18,    19,    20,    21,     5,     0,     0,     0,    87,     6,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,    89,    90,    91,
       0,    92,     0,     0,     0,     0,    93,    94,     0,    95,
     -19,     0,    96,     0,     0,     0,    97,     0,    98,     0,
       0,     0,     0,     0,     0,     0,   100,     0,   174,   175,
       0,   103,     0,     0,    15,     0,    17,    18,    19,    20,
      21,     5,     0,     0,     0,    87,     6,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,    89,    90,    91,     0,    92,     0,
       0,     0,     0,    93,    94,   -19,    95,     0,     0,    96,
       0,     0,     0,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,   100,     0,   174,   175,     0,   103,     0,
       0,    15,     0,    17,    18,    19,    20,    21,     5,     0,
       0,     0,    87,     6,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,    89,    90,    91,     0,    92,     0,     0,   -19,     0,
      93,    94,     0,    95,     0,     0,    96,     0,     0,     0,
      97,     0,    98,     0,     0,     0,     0,     0,     0,     0,
     100,     0,   174,   175,     0,   103,     0,     0,    15,     0,
      17,    18,    19,    20,    21,     5,     0,     0,     0,    87,
       6,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,    89,    90,
      91,     0,    92,     0,     0,     0,     0,    93,    94,     0,
      95,     0,     0,    96,     0,     0,     0,    97,     0,    98,
       0,     0,     0,     0,     0,     0,     0,   100,     0,   174,
     175,   -19,   103,     0,     0,    15,     0,    17,    18,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
      14,    52,     1,   253,   216,   206,     5,     4,     4,     5,
     161,    52,    21,    21,   110,   101,   102,    10,   303,     5,
     318,    27,    28,     5,    21,   252,    21,     3,   206,    21,
       7,     8,     9,   206,   284,    83,   286,     5,   288,    87,
       5,   137,    21,   328,     4,    22,   197,    34,    70,    36,
      45,     0,    58,   104,   205,    73,   283,   197,    39,   100,
      78,    66,    43,   104,    72,   205,   364,   365,   353,    26,
      27,    64,    81,   274,   275,    89,    90,    53,   229,    76,
      76,   232,    96,   234,    80,    99,     4,   101,   102,   229,
      82,   187,   232,    92,    80,    94,   274,   275,    80,    98,
      77,   274,   275,    82,   190,    20,   307,    84,    85,    77,
       4,    79,    80,   314,    79,    80,    76,    25,    26,    21,
     161,    39,    79,   373,    21,    43,    19,    21,   179,   307,
     342,   227,   382,   383,   307,    37,   314,    50,   179,    18,
      37,   314,    17,    25,    26,   196,    86,    30,   162,   300,
      89,    90,    23,    36,   168,   196,   197,   171,    76,    41,
     300,   160,    44,    71,   205,   164,   274,   275,    88,   183,
     184,    84,    85,    32,   188,    91,   190,    60,    61,    66,
     168,   180,    95,   171,   335,    49,   337,     4,   229,    71,
      29,   232,   105,   234,    82,   335,    69,   337,    76,   307,
     188,    25,    26,   354,   203,    81,   314,   358,   207,   260,
     251,    77,   253,    82,   354,    14,    15,   368,   358,   260,
      66,    73,    74,    25,    26,   239,    78,    66,   368,    68,
      69,    70,    71,    72,    77,   249,   235,    64,    65,   315,
     316,    73,    74,   284,   157,   286,    68,   288,    77,    78,
      80,    82,   165,   166,    42,    54,    55,    56,    47,   300,
      78,    62,    21,    82,   278,   279,   265,    81,    67,   268,
     269,    40,    49,    36,    73,    74,    75,     4,    36,    78,
      66,    29,    35,    81,    83,   198,    33,    42,   201,    50,
      36,   204,    57,   292,   335,    82,   337,   311,   312,   313,
      81,     5,   215,   216,   318,     6,    36,    36,    34,    48,
      11,    36,    13,   354,    36,    25,    36,   358,    66,    26,
      68,    69,    70,    71,    72,    36,    62,   368,   241,   242,
      80,    80,   373,    25,   333,    26,    33,     5,     6,   338,
      81,   382,   383,    11,    62,    13,    14,    15,    16,    81,
     364,   365,    36,    36,   267,    71,    36,    71,    71,   272,
     234,   228,    52,   233,   277,    66,   256,    68,    69,    70,
      71,    72,   296,   295,     6,   360,   239,   338,    60,    11,
      61,    13,    14,    15,    16,    62,    54,    55,    56,    63,
      75,    59,    88,    72,   189,   308,   219,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    76,    82,    83,    -1,    -1,    -1,    87,
      -1,   334,    54,    55,    56,    -1,    66,    59,    68,    69,
      70,    71,    72,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    78,    -1,    46,   362,
      82,    83,     6,    -1,    -1,    87,    -1,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,   379,   380,    66,    -1,
      68,    69,    70,    71,    72,    51,    52,     6,    -1,    -1,
      34,    -1,    11,    -1,    13,    14,    15,    16,    -1,    -1,
      66,    -1,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    78,    54,    55,    56,    -1,    83,
      59,    -1,    -1,    87,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,     6,    78,
      -1,    -1,    -1,    11,    83,    13,    14,    15,    87,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      78,     0,    -1,    -1,    -1,    83,    -1,     6,    -1,    87,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    66,    -1,    68,
      69,    70,    71,    72,     4,    -1,     6,    76,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    41,    -1,    -1,    44,    -1,     6,    -1,    48,    -1,
      50,    11,    -1,    13,    14,    15,    -1,    -1,    58,    -1,
      60,    61,    -1,    63,    -1,    -1,    66,    -1,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     6,    -1,    78,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    61,    -1,    63,    -1,    -1,    66,    -1,    68,    69,
      70,    71,    72,     6,    -1,    -1,    76,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    -1,    38,    39,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,    -1,
      63,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
       6,    -1,    -1,    76,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60,    61,    -1,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    71,    72,     6,    -1,    -1,
      76,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    66,    -1,    68,
      69,    70,    71,    72,     6,    -1,    -1,    -1,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,
      -1,    63,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      72,     6,    -1,    -1,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,    -1,
      -1,    66,    -1,    68,    69,    70,    71,    72,     6,    -1,
      -1,    -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,    -1,
      38,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    61,    -1,    63,    -1,    -1,    66,    -1,
      68,    69,    70,    71,    72,     6,    -1,    -1,    -1,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    62,    63,    -1,    -1,    66,    -1,    68,    69,    70,
      71,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    93,    94,     6,    11,    13,    14,    15,
      16,    54,    55,    56,    59,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    78,    83,    87,    97,   104,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   147,   158,
      70,     0,    95,   128,    66,   133,   158,   141,   141,     4,
      21,    20,    19,    18,    17,     7,     8,     9,    22,    77,
      84,    85,    86,    83,    87,    23,    88,    89,    90,    91,
       5,    79,    80,   123,     4,    76,   161,    10,    24,    29,
      30,    31,    33,    38,    39,    41,    44,    48,    50,    57,
      58,    60,    61,    63,    76,    96,   101,   102,   103,   116,
     143,   148,   151,   152,   153,    81,   129,   130,   131,   132,
     133,   135,   135,   135,   135,   135,   135,   135,   136,   137,
     137,   138,   139,   140,   140,   141,    66,    82,   125,   128,
     161,   161,   142,   111,   112,   158,   108,   109,   158,    32,
     105,   128,    25,    26,    41,    44,    71,   128,    39,    43,
     114,   161,    46,   158,    49,   128,   158,   143,    29,    68,
     108,    29,   108,    69,    60,    61,   102,   161,     4,    76,
      77,   124,   125,    25,    26,   125,    81,    82,    82,    77,
      82,     5,    80,    66,   106,   107,    37,   161,   128,    99,
     100,   103,   158,    77,   128,   161,   161,    77,   111,   111,
      64,    65,    68,   102,   128,   158,   158,   125,   111,    83,
     113,   144,   108,    73,    78,   110,   146,    80,    82,     4,
     102,    99,   161,    42,   161,    47,   128,   161,    99,    30,
     149,   150,   151,   152,   153,   128,    62,    78,     5,    80,
     155,   161,   155,   161,   145,    81,    82,   125,   107,    99,
      34,    36,   117,    40,    99,   114,   100,   128,    45,    49,
     122,    36,   109,    36,   161,   161,    71,    66,    51,    52,
     156,   157,   158,     4,   160,    98,   101,   102,   160,    98,
     110,    81,    35,   118,   119,   120,   102,    33,    42,   128,
     161,   128,    34,   127,   128,    36,    50,   161,    57,   149,
     149,    27,    28,    58,   161,   158,   158,    81,    82,     5,
     126,   160,    98,    36,    98,    98,    36,   128,    34,   121,
     119,   117,    99,    72,   115,   159,   161,   159,    82,    48,
     149,   161,   158,   158,   158,   149,   126,   126,   156,    36,
      25,    36,    26,    37,   159,    36,    62,   128,   161,    99,
      99,   127,   154,   155,    80,    80,    25,    26,   159,    99,
      33,    99,   122,   161,   156,   156,    99,    62,    98,    81,
      81,    36,   161,   161,    71,    98,    98,    36,    36,    71,
      71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   111,
     111,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   121,   121,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   135,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   141,   141,
     141,   142,   142,   142,   143,   143,   143,   144,   144,   144,
     144,   144,   144,   144,   144,   145,   145,   145,   146,   146,
     147,   147,   148,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   150,   150,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   157,   157,   158,   158,   158,   158,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   161
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     0,     3,     2,     2,
       3,     3,     2,     2,     0,     2,     0,     1,     2,     0,
       1,     2,     3,     2,     1,     2,     1,     3,     2,     2,
       2,     3,     2,     3,     1,     5,     6,     6,     4,     1,
       2,     2,     2,     2,     2,     4,     1,     4,     4,     2,
      10,     8,     7,     6,     1,     3,     2,     0,     1,     4,
       1,     3,     1,     3,     1,     4,     2,     1,     3,     1,
       3,     3,     1,     2,     1,     1,     0,     2,     9,     5,
       7,     0,     2,     0,     1,     1,     2,     5,     0,     3,
       0,     4,     5,     1,     3,     0,     1,     1,     3,     2,
       0,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     2,
       2,     1,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     7,     0,     1,     3,     2,     4,     2,     4,
       1,     3,     9,    11,    11,     7,     8,     7,     8,     0,
       1,     2,     1,     1,     0,     1,     1,     3,     1,     3,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     2,     1,     1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = PARSER_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == PARSER_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PARSER_error or PARSER_UNDEF. */
#define YYERRCODE PARSER_UNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if PARSER_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, parser_ctx_t *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (ctx);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, parser_ctx_t *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, ctx);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, parser_ctx_t *ctx)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !PARSER_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PARSER_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, parser_ctx_t *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (parser_ctx_t *ctx)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = PARSER_EMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, ctx);
    }

  if (yychar <= PARSER_EOF)
    {
      yychar = PARSER_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == PARSER_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = PARSER_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = PARSER_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* Program: tEXPRESSION ExpressionNl_opt  */
#line 164 "dlls/vbscript/parser.y"
                                            { handle_isexpression_script(ctx, (yyvsp[0].expression)); }
#line 2059 "dlls/vbscript/parser.tab.c"
    break;

  case 5: /* OptionExplicit_opt: tOPTION tEXPLICIT StSep  */
#line 168 "dlls/vbscript/parser.y"
                                            { ctx->option_explicit = TRUE; }
#line 2065 "dlls/vbscript/parser.tab.c"
    break;

  case 7: /* SourceElements: SourceElements GlobalDimDeclaration StSep  */
#line 173 "dlls/vbscript/parser.y"
                                            { source_add_statement(ctx, (yyvsp[-1].statement)); }
#line 2071 "dlls/vbscript/parser.tab.c"
    break;

  case 8: /* SourceElements: SourceElements StatementNl  */
#line 174 "dlls/vbscript/parser.y"
                                            { source_add_statement(ctx, (yyvsp[0].statement)); }
#line 2077 "dlls/vbscript/parser.tab.c"
    break;

  case 9: /* SourceElements: SourceElements ClassDeclaration  */
#line 175 "dlls/vbscript/parser.y"
                                            { source_add_class(ctx, (yyvsp[0].class_decl)); }
#line 2083 "dlls/vbscript/parser.tab.c"
    break;

  case 10: /* GlobalDimDeclaration: tPRIVATE tCONST ConstDeclList  */
#line 178 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_const_statement(ctx, (yyloc), (yyvsp[0].const_decl)); CHECK_ERROR; }
#line 2089 "dlls/vbscript/parser.tab.c"
    break;

  case 11: /* GlobalDimDeclaration: tPUBLIC tCONST ConstDeclList  */
#line 179 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_const_statement(ctx, (yyloc), (yyvsp[0].const_decl)); CHECK_ERROR; }
#line 2095 "dlls/vbscript/parser.tab.c"
    break;

  case 12: /* GlobalDimDeclaration: tPRIVATE DimDeclList  */
#line 180 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_dim_statement(ctx, (yyloc), (yyvsp[0].dim_decl)); CHECK_ERROR; }
#line 2101 "dlls/vbscript/parser.tab.c"
    break;

  case 13: /* GlobalDimDeclaration: tPUBLIC DimDeclList  */
#line 181 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_dim_statement(ctx, (yyloc), (yyvsp[0].dim_decl)); CHECK_ERROR; }
#line 2107 "dlls/vbscript/parser.tab.c"
    break;

  case 14: /* ExpressionNl_opt: %empty  */
#line 184 "dlls/vbscript/parser.y"
                                            { (yyval.expression) = NULL; }
#line 2113 "dlls/vbscript/parser.tab.c"
    break;

  case 15: /* ExpressionNl_opt: Expression tNL  */
#line 185 "dlls/vbscript/parser.y"
                                            { (yyval.expression) = (yyvsp[-1].expression); }
#line 2119 "dlls/vbscript/parser.tab.c"
    break;

  case 16: /* BodyStatements: %empty  */
#line 188 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = NULL; }
#line 2125 "dlls/vbscript/parser.tab.c"
    break;

  case 17: /* BodyStatements: Statement  */
#line 189 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2131 "dlls/vbscript/parser.tab.c"
    break;

  case 18: /* BodyStatements: StatementNl BodyStatements  */
#line 190 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = link_statements((yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 2137 "dlls/vbscript/parser.tab.c"
    break;

  case 19: /* StatementsNl_opt: %empty  */
#line 193 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = NULL; }
#line 2143 "dlls/vbscript/parser.tab.c"
    break;

  case 20: /* StatementsNl_opt: StatementsNl  */
#line 194 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2149 "dlls/vbscript/parser.tab.c"
    break;

  case 21: /* StatementsNl: SimpleStatement StSep  */
#line 197 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[-1].statement); }
#line 2155 "dlls/vbscript/parser.tab.c"
    break;

  case 22: /* StatementsNl: SimpleStatement StSep StatementsNl  */
#line 198 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = link_statements((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2161 "dlls/vbscript/parser.tab.c"
    break;

  case 23: /* StatementNl: Statement tNL  */
#line 201 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[-1].statement); }
#line 2167 "dlls/vbscript/parser.tab.c"
    break;

  case 24: /* Statement: ':'  */
#line 204 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = NULL; }
#line 2173 "dlls/vbscript/parser.tab.c"
    break;

  case 25: /* Statement: ':' Statement  */
#line 205 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2179 "dlls/vbscript/parser.tab.c"
    break;

  case 26: /* Statement: SimpleStatement  */
#line 206 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2185 "dlls/vbscript/parser.tab.c"
    break;

  case 27: /* Statement: SimpleStatement ':' Statement  */
#line 207 "dlls/vbscript/parser.y"
                                            { (yyvsp[-2].statement)->next = (yyvsp[0].statement); (yyval.statement) = (yyvsp[-2].statement); }
#line 2191 "dlls/vbscript/parser.tab.c"
    break;

  case 28: /* Statement: SimpleStatement ':'  */
#line 208 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[-1].statement); }
#line 2197 "dlls/vbscript/parser.tab.c"
    break;

  case 29: /* SimpleStatement: CallExpression ArgumentList_opt  */
#line 211 "dlls/vbscript/parser.y"
                                            { call_expression_t *call_expr = make_call_expression(ctx, (yyvsp[-1].expression), (yyvsp[0].expression)); CHECK_ERROR;
                                              (yyval.statement) = new_call_statement(ctx, (yyloc), &call_expr->expr); CHECK_ERROR; }
#line 2204 "dlls/vbscript/parser.tab.c"
    break;

  case 30: /* SimpleStatement: tCALL UnaryExpression  */
#line 213 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_call_statement(ctx, (yyloc), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2210 "dlls/vbscript/parser.tab.c"
    break;

  case 31: /* SimpleStatement: CallExpression '=' Expression  */
#line 215 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_assign_statement(ctx, (yyloc), (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2216 "dlls/vbscript/parser.tab.c"
    break;

  case 32: /* SimpleStatement: tDIM DimDeclList  */
#line 216 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_dim_statement(ctx, (yyloc), (yyvsp[0].dim_decl)); CHECK_ERROR; }
#line 2222 "dlls/vbscript/parser.tab.c"
    break;

  case 33: /* SimpleStatement: tREDIM Preserve_opt ReDimDeclList  */
#line 217 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_redim_statement(ctx, (yyloc), (yyvsp[-1].boolean), (yyvsp[0].redim_decl)); CHECK_ERROR; }
#line 2228 "dlls/vbscript/parser.tab.c"
    break;

  case 34: /* SimpleStatement: IfStatement  */
#line 218 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2234 "dlls/vbscript/parser.tab.c"
    break;

  case 35: /* SimpleStatement: tWHILE Expression StSep StatementsNl_opt tWEND  */
#line 220 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yyloc), STAT_WHILE, (yyvsp[-3].expression), (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2240 "dlls/vbscript/parser.tab.c"
    break;

  case 36: /* SimpleStatement: tDO DoType Expression StSep StatementsNl_opt tLOOP  */
#line 222 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yyloc), (yyvsp[-4].boolean) ? STAT_WHILELOOP : STAT_UNTIL, (yyvsp[-3].expression), (yyvsp[-1].statement));
                                              CHECK_ERROR; }
#line 2247 "dlls/vbscript/parser.tab.c"
    break;

  case 37: /* SimpleStatement: tDO StSep StatementsNl_opt tLOOP DoType Expression  */
#line 225 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yylsp[-2]), (yyvsp[-1].boolean) ? STAT_DOWHILE : STAT_DOUNTIL, (yyvsp[0].expression), (yyvsp[-3].statement));
                                              CHECK_ERROR; }
#line 2254 "dlls/vbscript/parser.tab.c"
    break;

  case 38: /* SimpleStatement: tDO StSep StatementsNl_opt tLOOP  */
#line 227 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yyloc), STAT_DOWHILE, NULL, (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2260 "dlls/vbscript/parser.tab.c"
    break;

  case 39: /* SimpleStatement: FunctionDecl  */
#line 228 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_function_statement(ctx, (yyloc), (yyvsp[0].func_decl)); CHECK_ERROR; }
#line 2266 "dlls/vbscript/parser.tab.c"
    break;

  case 40: /* SimpleStatement: tEXIT tDO  */
#line 229 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITDO, 0, (yyloc)); CHECK_ERROR; }
#line 2272 "dlls/vbscript/parser.tab.c"
    break;

  case 41: /* SimpleStatement: tEXIT tFOR  */
#line 230 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITFOR, 0, (yyloc)); CHECK_ERROR; }
#line 2278 "dlls/vbscript/parser.tab.c"
    break;

  case 42: /* SimpleStatement: tEXIT tFUNCTION  */
#line 231 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITFUNC, 0, (yyloc)); CHECK_ERROR; }
#line 2284 "dlls/vbscript/parser.tab.c"
    break;

  case 43: /* SimpleStatement: tEXIT tPROPERTY  */
#line 232 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITPROP, 0, (yyloc)); CHECK_ERROR; }
#line 2290 "dlls/vbscript/parser.tab.c"
    break;

  case 44: /* SimpleStatement: tEXIT tSUB  */
#line 233 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITSUB, 0, (yyloc)); CHECK_ERROR; }
#line 2296 "dlls/vbscript/parser.tab.c"
    break;

  case 45: /* SimpleStatement: tSET CallExpression '=' Expression  */
#line 234 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_set_statement(ctx, (yyloc), (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2302 "dlls/vbscript/parser.tab.c"
    break;

  case 46: /* SimpleStatement: tSTOP  */
#line 235 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_STOP, 0, (yyloc)); CHECK_ERROR; }
#line 2308 "dlls/vbscript/parser.tab.c"
    break;

  case 47: /* SimpleStatement: tON tERROR tRESUME tNEXT  */
#line 236 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_onerror_statement(ctx, (yyloc), TRUE); CHECK_ERROR; }
#line 2314 "dlls/vbscript/parser.tab.c"
    break;

  case 48: /* SimpleStatement: tON tERROR tGOTO '0'  */
#line 237 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_onerror_statement(ctx, (yyloc), FALSE); CHECK_ERROR; }
#line 2320 "dlls/vbscript/parser.tab.c"
    break;

  case 49: /* SimpleStatement: tCONST ConstDeclList  */
#line 238 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_const_statement(ctx, (yyloc), (yyvsp[0].const_decl)); CHECK_ERROR; }
#line 2326 "dlls/vbscript/parser.tab.c"
    break;

  case 50: /* SimpleStatement: tFOR Identifier '=' Expression tTO Expression Step_opt StSep StatementsNl_opt tNEXT  */
#line 240 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_forto_statement(ctx, (yyloc), (yyvsp[-8].string), (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-3].expression), (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2332 "dlls/vbscript/parser.tab.c"
    break;

  case 51: /* SimpleStatement: tFOR tEACH Identifier tIN Expression StSep StatementsNl_opt tNEXT  */
#line 242 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_foreach_statement(ctx, (yyloc), (yyvsp[-5].string), (yyvsp[-3].expression), (yyvsp[-1].statement)); }
#line 2338 "dlls/vbscript/parser.tab.c"
    break;

  case 52: /* SimpleStatement: tSELECT tCASE Expression StSep CaseClausules tEND tSELECT  */
#line 244 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_select_statement(ctx, (yyloc), (yyvsp[-4].expression), (yyvsp[-2].case_clausule)); }
#line 2344 "dlls/vbscript/parser.tab.c"
    break;

  case 53: /* SimpleStatement: tWITH Expression StSep StatementsNl_opt tEND tWITH  */
#line 246 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = new_with_statement(ctx, (yyloc), (yyvsp[-4].expression), (yyvsp[-2].statement)); }
#line 2350 "dlls/vbscript/parser.tab.c"
    break;

  case 54: /* MemberExpression: Identifier  */
#line 249 "dlls/vbscript/parser.y"
                                            { (yyval.member) = new_member_expression(ctx, NULL, (yyvsp[0].string)); CHECK_ERROR; }
#line 2356 "dlls/vbscript/parser.tab.c"
    break;

  case 55: /* MemberExpression: CallExpression '.' tIdentifier  */
#line 250 "dlls/vbscript/parser.y"
                                            { (yyval.member) = new_member_expression(ctx, (yyvsp[-2].expression), (yyvsp[0].string)); CHECK_ERROR; }
#line 2362 "dlls/vbscript/parser.tab.c"
    break;

  case 56: /* MemberExpression: tDOT tIdentifier  */
#line 251 "dlls/vbscript/parser.y"
                                            { expression_t *dot_expr = new_expression(ctx, EXPR_DOT, sizeof(*dot_expr)); CHECK_ERROR;
                                              (yyval.member) = new_member_expression(ctx, dot_expr, (yyvsp[0].string)); CHECK_ERROR; }
#line 2369 "dlls/vbscript/parser.tab.c"
    break;

  case 57: /* Preserve_opt: %empty  */
#line 255 "dlls/vbscript/parser.y"
                                            { (yyval.boolean) = FALSE; }
#line 2375 "dlls/vbscript/parser.tab.c"
    break;

  case 58: /* Preserve_opt: tPRESERVE  */
#line 256 "dlls/vbscript/parser.y"
                                            { (yyval.boolean) = TRUE; }
#line 2381 "dlls/vbscript/parser.tab.c"
    break;

  case 59: /* ReDimDecl: tIdentifier '(' ArgumentList ')'  */
#line 259 "dlls/vbscript/parser.y"
                                            { (yyval.redim_decl) = new_redim_decl(ctx, (yyvsp[-3].string), (yyvsp[-1].expression)); CHECK_ERROR; }
#line 2387 "dlls/vbscript/parser.tab.c"
    break;

  case 60: /* ReDimDeclList: ReDimDecl  */
#line 262 "dlls/vbscript/parser.y"
                                            { (yyval.redim_decl) = (yyvsp[0].redim_decl); }
#line 2393 "dlls/vbscript/parser.tab.c"
    break;

  case 61: /* ReDimDeclList: ReDimDecl ',' ReDimDeclList  */
#line 263 "dlls/vbscript/parser.y"
                                            { (yyvsp[-2].redim_decl)->next = (yyvsp[0].redim_decl); (yyval.redim_decl) = (yyvsp[-2].redim_decl); }
#line 2399 "dlls/vbscript/parser.tab.c"
    break;

  case 62: /* DimDeclList: DimDecl  */
#line 266 "dlls/vbscript/parser.y"
                                            { (yyval.dim_decl) = (yyvsp[0].dim_decl); }
#line 2405 "dlls/vbscript/parser.tab.c"
    break;

  case 63: /* DimDeclList: DimDecl ',' DimDeclList  */
#line 267 "dlls/vbscript/parser.y"
                                            { (yyvsp[-2].dim_decl)->next = (yyvsp[0].dim_decl); (yyval.dim_decl) = (yyvsp[-2].dim_decl); }
#line 2411 "dlls/vbscript/parser.tab.c"
    break;

  case 64: /* DimDecl: Identifier  */
#line 270 "dlls/vbscript/parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[0].string), FALSE, NULL); CHECK_ERROR; }
#line 2417 "dlls/vbscript/parser.tab.c"
    break;

  case 65: /* DimDecl: Identifier '(' DimList ')'  */
#line 271 "dlls/vbscript/parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[-3].string), TRUE, (yyvsp[-1].dim_list)); CHECK_ERROR; }
#line 2423 "dlls/vbscript/parser.tab.c"
    break;

  case 66: /* DimDecl: Identifier tEMPTYBRACKETS  */
#line 272 "dlls/vbscript/parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[-1].string), TRUE, NULL); CHECK_ERROR; }
#line 2429 "dlls/vbscript/parser.tab.c"
    break;

  case 67: /* DimList: IntegerValue  */
#line 275 "dlls/vbscript/parser.y"
                                            { (yyval.dim_list) = new_dim(ctx, (yyvsp[0].uint), NULL); }
#line 2435 "dlls/vbscript/parser.tab.c"
    break;

  case 68: /* DimList: IntegerValue ',' DimList  */
#line 276 "dlls/vbscript/parser.y"
                                            { (yyval.dim_list) = new_dim(ctx, (yyvsp[-2].uint), (yyvsp[0].dim_list)); }
#line 2441 "dlls/vbscript/parser.tab.c"
    break;

  case 69: /* ConstDeclList: ConstDecl  */
#line 279 "dlls/vbscript/parser.y"
                                            { (yyval.const_decl) = (yyvsp[0].const_decl); }
#line 2447 "dlls/vbscript/parser.tab.c"
    break;

  case 70: /* ConstDeclList: ConstDecl ',' ConstDeclList  */
#line 280 "dlls/vbscript/parser.y"
                                            { (yyvsp[-2].const_decl)->next = (yyvsp[0].const_decl); (yyval.const_decl) = (yyvsp[-2].const_decl); }
#line 2453 "dlls/vbscript/parser.tab.c"
    break;

  case 71: /* ConstDecl: Identifier '=' ConstExpression  */
#line 283 "dlls/vbscript/parser.y"
                                            { (yyval.const_decl) = new_const_decl(ctx, (yyvsp[-2].string), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2459 "dlls/vbscript/parser.tab.c"
    break;

  case 72: /* ConstExpression: LiteralExpression  */
#line 286 "dlls/vbscript/parser.y"
                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 2465 "dlls/vbscript/parser.tab.c"
    break;

  case 73: /* ConstExpression: '-' NumericLiteralExpression  */
#line 287 "dlls/vbscript/parser.y"
                                            { (yyval.expression) = new_unary_expression(ctx, EXPR_NEG, (yyvsp[0].expression)); CHECK_ERROR; }
#line 2471 "dlls/vbscript/parser.tab.c"
    break;

  case 74: /* DoType: tWHILE  */
#line 290 "dlls/vbscript/parser.y"
                    { (yyval.boolean) = TRUE; }
#line 2477 "dlls/vbscript/parser.tab.c"
    break;

  case 75: /* DoType: tUNTIL  */
#line 291 "dlls/vbscript/parser.y"
                    { (yyval.boolean) = FALSE; }
#line 2483 "dlls/vbscript/parser.tab.c"
    break;

  case 76: /* Step_opt: %empty  */
#line 294 "dlls/vbscript/parser.y"
                                            { (yyval.expression) = NULL;}
#line 2489 "dlls/vbscript/parser.tab.c"
    break;

  case 77: /* Step_opt: tSTEP Expression  */
#line 295 "dlls/vbscript/parser.y"
                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 2495 "dlls/vbscript/parser.tab.c"
    break;

  case 78: /* IfStatement: tIF Expression tTHEN tNL StatementsNl_opt ElseIfs_opt Else_opt tEND tIF  */
#line 299 "dlls/vbscript/parser.y"
                                               { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-7].expression), (yyvsp[-4].statement), (yyvsp[-3].elseif), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 2501 "dlls/vbscript/parser.tab.c"
    break;

  case 79: /* IfStatement: tIF Expression tTHEN Statement EndIf_opt  */
#line 300 "dlls/vbscript/parser.y"
                                               { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-3].expression), (yyvsp[-1].statement), NULL, NULL); CHECK_ERROR; }
#line 2507 "dlls/vbscript/parser.tab.c"
    break;

  case 80: /* IfStatement: tIF Expression tTHEN Statement tELSE Statement EndIf_opt  */
#line 302 "dlls/vbscript/parser.y"
                                               { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-5].expression), (yyvsp[-3].statement), NULL, (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2513 "dlls/vbscript/parser.tab.c"
    break;

  case 83: /* ElseIfs_opt: %empty  */
#line 309 "dlls/vbscript/parser.y"
                                            { (yyval.elseif) = NULL; }
#line 2519 "dlls/vbscript/parser.tab.c"
    break;

  case 84: /* ElseIfs_opt: ElseIfs  */
#line 310 "dlls/vbscript/parser.y"
                                            { (yyval.elseif) = (yyvsp[0].elseif); }
#line 2525 "dlls/vbscript/parser.tab.c"
    break;

  case 85: /* ElseIfs: ElseIf  */
#line 313 "dlls/vbscript/parser.y"
                                            { (yyval.elseif) = (yyvsp[0].elseif); }
#line 2531 "dlls/vbscript/parser.tab.c"
    break;

  case 86: /* ElseIfs: ElseIf ElseIfs  */
#line 314 "dlls/vbscript/parser.y"
                                            { (yyvsp[-1].elseif)->next = (yyvsp[0].elseif); (yyval.elseif) = (yyvsp[-1].elseif); }
#line 2537 "dlls/vbscript/parser.tab.c"
    break;

  case 87: /* ElseIf: tELSEIF Expression tTHEN StSep_opt StatementsNl_opt  */
#line 318 "dlls/vbscript/parser.y"
                                            { (yyval.elseif) = new_elseif_decl(ctx, (yyloc), (yyvsp[-3].expression), (yyvsp[0].statement)); }
#line 2543 "dlls/vbscript/parser.tab.c"
    break;

  case 88: /* Else_opt: %empty  */
#line 321 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = NULL; }
#line 2549 "dlls/vbscript/parser.tab.c"
    break;

  case 89: /* Else_opt: tELSE StSep_opt StatementsNl_opt  */
#line 322 "dlls/vbscript/parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2555 "dlls/vbscript/parser.tab.c"
    break;

  case 90: /* CaseClausules: %empty  */
#line 325 "dlls/vbscript/parser.y"
                                                                       { (yyval.case_clausule) = NULL; }
#line 2561 "dlls/vbscript/parser.tab.c"
    break;

  case 91: /* CaseClausules: tCASE tELSE StSep_opt StatementsNl_opt  */
#line 326 "dlls/vbscript/parser.y"
                                                                       { (yyval.case_clausule) = new_case_clausule(ctx, NULL, (yyvsp[0].statement), NULL); }
#line 2567 "dlls/vbscript/parser.tab.c"
    break;

  case 92: /* CaseClausules: tCASE ExpressionList StSep_opt StatementsNl_opt CaseClausules  */
#line 327 "dlls/vbscript/parser.y"
                                                                       { (yyval.case_clausule) = new_case_clausule(ctx, (yyvsp[-3].expression), (yyvsp[-1].statement), (yyvsp[0].case_clausule)); }
#line 2573 "dlls/vbscript/parser.tab.c"
    break;

  case 93: /* Arguments: tEMPTYBRACKETS  */
#line 330 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = NULL; }
#line 2579 "dlls/vbscript/parser.tab.c"
    break;

  case 94: /* Arguments: '(' ArgumentList ')'  */
#line 331 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[-1].expression); }
#line 2585 "dlls/vbscript/parser.tab.c"
    break;

  case 95: /* ArgumentList_opt: %empty  */
#line 334 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = NULL; }
#line 2591 "dlls/vbscript/parser.tab.c"
    break;

  case 96: /* ArgumentList_opt: ArgumentList  */
#line 335 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2597 "dlls/vbscript/parser.tab.c"
    break;

  case 97: /* ArgumentList: Expression  */
#line 338 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2603 "dlls/vbscript/parser.tab.c"
    break;

  case 98: /* ArgumentList: Expression ',' ArgumentList  */
#line 339 "dlls/vbscript/parser.y"
                                    { (yyvsp[-2].expression)->next = (yyvsp[0].expression); (yyval.expression) = (yyvsp[-2].expression); }
#line 2609 "dlls/vbscript/parser.tab.c"
    break;

  case 99: /* ArgumentList: ',' ArgumentList  */
#line 340 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_NOARG, 0); CHECK_ERROR; (yyval.expression)->next = (yyvsp[0].expression); }
#line 2615 "dlls/vbscript/parser.tab.c"
    break;

  case 102: /* ExpressionList: Expression  */
#line 347 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2621 "dlls/vbscript/parser.tab.c"
    break;

  case 103: /* ExpressionList: Expression ',' ExpressionList  */
#line 348 "dlls/vbscript/parser.y"
                                    { (yyvsp[-2].expression)->next = (yyvsp[0].expression); (yyval.expression) = (yyvsp[-2].expression); }
#line 2627 "dlls/vbscript/parser.tab.c"
    break;

  case 104: /* Expression: EqvExpression  */
#line 351 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2633 "dlls/vbscript/parser.tab.c"
    break;

  case 105: /* Expression: Expression tIMP EqvExpression  */
#line 352 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_IMP, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2639 "dlls/vbscript/parser.tab.c"
    break;

  case 106: /* EqvExpression: XorExpression  */
#line 355 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2645 "dlls/vbscript/parser.tab.c"
    break;

  case 107: /* EqvExpression: EqvExpression tEQV XorExpression  */
#line 356 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_EQV, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2651 "dlls/vbscript/parser.tab.c"
    break;

  case 108: /* XorExpression: OrExpression  */
#line 359 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2657 "dlls/vbscript/parser.tab.c"
    break;

  case 109: /* XorExpression: XorExpression tXOR OrExpression  */
#line 360 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_XOR, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2663 "dlls/vbscript/parser.tab.c"
    break;

  case 110: /* OrExpression: AndExpression  */
#line 363 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2669 "dlls/vbscript/parser.tab.c"
    break;

  case 111: /* OrExpression: OrExpression tOR AndExpression  */
#line 364 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_OR, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2675 "dlls/vbscript/parser.tab.c"
    break;

  case 112: /* AndExpression: NotExpression  */
#line 367 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2681 "dlls/vbscript/parser.tab.c"
    break;

  case 113: /* AndExpression: AndExpression tAND NotExpression  */
#line 368 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_AND, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2687 "dlls/vbscript/parser.tab.c"
    break;

  case 114: /* NotExpression: EqualityExpression  */
#line 371 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2693 "dlls/vbscript/parser.tab.c"
    break;

  case 115: /* NotExpression: tNOT NotExpression  */
#line 372 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_unary_expression(ctx, EXPR_NOT, (yyvsp[0].expression)); CHECK_ERROR; }
#line 2699 "dlls/vbscript/parser.tab.c"
    break;

  case 116: /* EqualityExpression: ConcatExpression  */
#line 375 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2705 "dlls/vbscript/parser.tab.c"
    break;

  case 117: /* EqualityExpression: EqualityExpression '=' ConcatExpression  */
#line 376 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_EQUAL, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2711 "dlls/vbscript/parser.tab.c"
    break;

  case 118: /* EqualityExpression: EqualityExpression tNEQ ConcatExpression  */
#line 377 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_NEQUAL, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2717 "dlls/vbscript/parser.tab.c"
    break;

  case 119: /* EqualityExpression: EqualityExpression '>' ConcatExpression  */
#line 378 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_GT, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2723 "dlls/vbscript/parser.tab.c"
    break;

  case 120: /* EqualityExpression: EqualityExpression '<' ConcatExpression  */
#line 379 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_LT, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2729 "dlls/vbscript/parser.tab.c"
    break;

  case 121: /* EqualityExpression: EqualityExpression tGTEQ ConcatExpression  */
#line 380 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_GTEQ, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2735 "dlls/vbscript/parser.tab.c"
    break;

  case 122: /* EqualityExpression: EqualityExpression tLTEQ ConcatExpression  */
#line 381 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_LTEQ, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2741 "dlls/vbscript/parser.tab.c"
    break;

  case 123: /* EqualityExpression: EqualityExpression tIS ConcatExpression  */
#line 382 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_IS, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2747 "dlls/vbscript/parser.tab.c"
    break;

  case 124: /* ConcatExpression: AdditiveExpression  */
#line 385 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2753 "dlls/vbscript/parser.tab.c"
    break;

  case 125: /* ConcatExpression: ConcatExpression '&' AdditiveExpression  */
#line 386 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_CONCAT, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2759 "dlls/vbscript/parser.tab.c"
    break;

  case 126: /* AdditiveExpression: ModExpression  */
#line 389 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2765 "dlls/vbscript/parser.tab.c"
    break;

  case 127: /* AdditiveExpression: AdditiveExpression '+' ModExpression  */
#line 390 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_ADD, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2771 "dlls/vbscript/parser.tab.c"
    break;

  case 128: /* AdditiveExpression: AdditiveExpression '-' ModExpression  */
#line 391 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_SUB, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2777 "dlls/vbscript/parser.tab.c"
    break;

  case 129: /* ModExpression: IntdivExpression  */
#line 394 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2783 "dlls/vbscript/parser.tab.c"
    break;

  case 130: /* ModExpression: ModExpression tMOD IntdivExpression  */
#line 395 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_MOD, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2789 "dlls/vbscript/parser.tab.c"
    break;

  case 131: /* IntdivExpression: MultiplicativeExpression  */
#line 398 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2795 "dlls/vbscript/parser.tab.c"
    break;

  case 132: /* IntdivExpression: IntdivExpression '\\' MultiplicativeExpression  */
#line 400 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_IDIV, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2801 "dlls/vbscript/parser.tab.c"
    break;

  case 133: /* MultiplicativeExpression: ExpExpression  */
#line 403 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2807 "dlls/vbscript/parser.tab.c"
    break;

  case 134: /* MultiplicativeExpression: MultiplicativeExpression '*' ExpExpression  */
#line 405 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_MUL, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2813 "dlls/vbscript/parser.tab.c"
    break;

  case 135: /* MultiplicativeExpression: MultiplicativeExpression '/' ExpExpression  */
#line 407 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_DIV, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2819 "dlls/vbscript/parser.tab.c"
    break;

  case 136: /* ExpExpression: SignExpression  */
#line 410 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2825 "dlls/vbscript/parser.tab.c"
    break;

  case 137: /* ExpExpression: ExpExpression '^' SignExpression  */
#line 411 "dlls/vbscript/parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_EXP, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2831 "dlls/vbscript/parser.tab.c"
    break;

  case 138: /* SignExpression: UnaryExpression  */
#line 414 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2837 "dlls/vbscript/parser.tab.c"
    break;

  case 139: /* SignExpression: '-' SignExpression  */
#line 415 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_unary_expression(ctx, EXPR_NEG, (yyvsp[0].expression)); CHECK_ERROR; }
#line 2843 "dlls/vbscript/parser.tab.c"
    break;

  case 140: /* SignExpression: '+' SignExpression  */
#line 416 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2849 "dlls/vbscript/parser.tab.c"
    break;

  case 141: /* UnaryExpression: LiteralExpression  */
#line 419 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2855 "dlls/vbscript/parser.tab.c"
    break;

  case 142: /* UnaryExpression: CallExpression  */
#line 420 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2861 "dlls/vbscript/parser.tab.c"
    break;

  case 143: /* UnaryExpression: tNEW Identifier  */
#line 421 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_new_expression(ctx, (yyvsp[0].string)); CHECK_ERROR; }
#line 2867 "dlls/vbscript/parser.tab.c"
    break;

  case 144: /* CallExpression: PrimaryExpression  */
#line 424 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2873 "dlls/vbscript/parser.tab.c"
    break;

  case 145: /* CallExpression: MemberExpression  */
#line 425 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = &(yyvsp[0].member)->expr; }
#line 2879 "dlls/vbscript/parser.tab.c"
    break;

  case 146: /* CallExpression: CallExpression Arguments  */
#line 426 "dlls/vbscript/parser.y"
                                    { call_expression_t *expr = new_call_expression(ctx, (yyvsp[-1].expression), (yyvsp[0].expression)); CHECK_ERROR;
                                      (yyval.expression) = &expr->expr; }
#line 2886 "dlls/vbscript/parser.tab.c"
    break;

  case 147: /* LiteralExpression: tTRUE  */
#line 430 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_bool_expression(ctx, VARIANT_TRUE); CHECK_ERROR; }
#line 2892 "dlls/vbscript/parser.tab.c"
    break;

  case 148: /* LiteralExpression: tFALSE  */
#line 431 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_bool_expression(ctx, VARIANT_FALSE); CHECK_ERROR; }
#line 2898 "dlls/vbscript/parser.tab.c"
    break;

  case 149: /* LiteralExpression: tString  */
#line 432 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_string_expression(ctx, (yyvsp[0].string)); CHECK_ERROR; }
#line 2904 "dlls/vbscript/parser.tab.c"
    break;

  case 150: /* LiteralExpression: tDate  */
#line 433 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_date_expression(ctx, (yyvsp[0].date)); CHECK_ERROR; }
#line 2910 "dlls/vbscript/parser.tab.c"
    break;

  case 151: /* LiteralExpression: NumericLiteralExpression  */
#line 434 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2916 "dlls/vbscript/parser.tab.c"
    break;

  case 152: /* LiteralExpression: tEMPTY  */
#line 435 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_EMPTY, 0); CHECK_ERROR; }
#line 2922 "dlls/vbscript/parser.tab.c"
    break;

  case 153: /* LiteralExpression: tNULL  */
#line 436 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_NULL, 0); CHECK_ERROR; }
#line 2928 "dlls/vbscript/parser.tab.c"
    break;

  case 154: /* LiteralExpression: tNOTHING  */
#line 437 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_NOTHING, 0); CHECK_ERROR; }
#line 2934 "dlls/vbscript/parser.tab.c"
    break;

  case 155: /* NumericLiteralExpression: '0'  */
#line 440 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_long_expression(ctx, EXPR_INT, 0); CHECK_ERROR; }
#line 2940 "dlls/vbscript/parser.tab.c"
    break;

  case 156: /* NumericLiteralExpression: tInt  */
#line 441 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_long_expression(ctx, EXPR_INT, (yyvsp[0].integer)); CHECK_ERROR; }
#line 2946 "dlls/vbscript/parser.tab.c"
    break;

  case 157: /* NumericLiteralExpression: tDouble  */
#line 442 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_double_expression(ctx, (yyvsp[0].dbl)); CHECK_ERROR; }
#line 2952 "dlls/vbscript/parser.tab.c"
    break;

  case 158: /* IntegerValue: '0'  */
#line 445 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = 0; }
#line 2958 "dlls/vbscript/parser.tab.c"
    break;

  case 159: /* IntegerValue: tInt  */
#line 446 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = (yyvsp[0].integer); }
#line 2964 "dlls/vbscript/parser.tab.c"
    break;

  case 160: /* PrimaryExpression: tEXPRLBRACKET Expression ')'  */
#line 449 "dlls/vbscript/parser.y"
                                              { (yyval.expression) = new_unary_expression(ctx, EXPR_BRACKETS, (yyvsp[-1].expression)); }
#line 2970 "dlls/vbscript/parser.tab.c"
    break;

  case 161: /* PrimaryExpression: tME  */
#line 450 "dlls/vbscript/parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_ME, 0); CHECK_ERROR; }
#line 2976 "dlls/vbscript/parser.tab.c"
    break;

  case 162: /* ClassDeclaration: tCLASS Identifier StSep ClassBody tEND tCLASS StSep  */
#line 453 "dlls/vbscript/parser.y"
                                                                { (yyvsp[-3].class_decl)->name = (yyvsp[-5].string); (yyval.class_decl) = (yyvsp[-3].class_decl); }
#line 2982 "dlls/vbscript/parser.tab.c"
    break;

  case 163: /* ClassBody: %empty  */
#line 456 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = new_class_decl(ctx); }
#line 2988 "dlls/vbscript/parser.tab.c"
    break;

  case 164: /* ClassBody: FunctionDecl  */
#line 457 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, new_class_decl(ctx), (yyvsp[0].func_decl)); CHECK_ERROR; }
#line 2994 "dlls/vbscript/parser.tab.c"
    break;

  case 165: /* ClassBody: FunctionDecl StSep ClassBody  */
#line 458 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, (yyvsp[0].class_decl), (yyvsp[-2].func_decl)); CHECK_ERROR; }
#line 3000 "dlls/vbscript/parser.tab.c"
    break;

  case 166: /* ClassBody: Storage tIdentifier  */
#line 460 "dlls/vbscript/parser.y"
                                                  { dim_decl_t *dim_decl = new_dim_decl(ctx, (yyvsp[0].string), FALSE, NULL); CHECK_ERROR;
                                                  (yyval.class_decl) = add_dim_prop(ctx, new_class_decl(ctx), dim_decl, (yyvsp[-1].uint)); CHECK_ERROR; }
#line 3007 "dlls/vbscript/parser.tab.c"
    break;

  case 167: /* ClassBody: Storage tIdentifier StSep ClassBody  */
#line 462 "dlls/vbscript/parser.y"
                                                  { dim_decl_t *dim_decl = new_dim_decl(ctx, (yyvsp[-2].string), FALSE, NULL); CHECK_ERROR;
                                                  (yyval.class_decl) = add_dim_prop(ctx, (yyvsp[0].class_decl), dim_decl, (yyvsp[-3].uint)); CHECK_ERROR; }
#line 3014 "dlls/vbscript/parser.tab.c"
    break;

  case 168: /* ClassBody: tDIM DimDecl  */
#line 464 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = add_dim_prop(ctx, new_class_decl(ctx), (yyvsp[0].dim_decl), 0); CHECK_ERROR; }
#line 3020 "dlls/vbscript/parser.tab.c"
    break;

  case 169: /* ClassBody: tDIM DimDecl StSep ClassBody  */
#line 465 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = add_dim_prop(ctx, (yyvsp[0].class_decl), (yyvsp[-2].dim_decl), 0); CHECK_ERROR; }
#line 3026 "dlls/vbscript/parser.tab.c"
    break;

  case 170: /* ClassBody: PropertyDecl  */
#line 466 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, new_class_decl(ctx), (yyvsp[0].func_decl)); CHECK_ERROR; }
#line 3032 "dlls/vbscript/parser.tab.c"
    break;

  case 171: /* ClassBody: PropertyDecl StSep ClassBody  */
#line 467 "dlls/vbscript/parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, (yyvsp[0].class_decl), (yyvsp[-2].func_decl)); CHECK_ERROR; }
#line 3038 "dlls/vbscript/parser.tab.c"
    break;

  case 172: /* PropertyDecl: Storage_opt tPROPERTY tGET Identifier ArgumentsDecl_opt StSep BodyStatements tEND tPROPERTY  */
#line 471 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-5].string), FUNC_PROPGET, (yyvsp[-8].uint), (yyvsp[-4].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3044 "dlls/vbscript/parser.tab.c"
    break;

  case 173: /* PropertyDecl: Storage_opt tPROPERTY tLET Identifier '(' ArgumentDeclList ')' StSep BodyStatements tEND tPROPERTY  */
#line 473 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-7].string), FUNC_PROPLET, (yyvsp[-10].uint), (yyvsp[-5].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3050 "dlls/vbscript/parser.tab.c"
    break;

  case 174: /* PropertyDecl: Storage_opt tPROPERTY tSET Identifier '(' ArgumentDeclList ')' StSep BodyStatements tEND tPROPERTY  */
#line 475 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-7].string), FUNC_PROPSET, (yyvsp[-10].uint), (yyvsp[-5].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3056 "dlls/vbscript/parser.tab.c"
    break;

  case 175: /* FunctionDecl: Storage_opt tSUB Identifier StSep BodyStatements tEND tSUB  */
#line 479 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-4].string), FUNC_SUB, (yyvsp[-6].uint), NULL, (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3062 "dlls/vbscript/parser.tab.c"
    break;

  case 176: /* FunctionDecl: Storage_opt tSUB Identifier ArgumentsDecl Nl_opt BodyStatements tEND tSUB  */
#line 481 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-5].string), FUNC_SUB, (yyvsp[-7].uint), (yyvsp[-4].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3068 "dlls/vbscript/parser.tab.c"
    break;

  case 177: /* FunctionDecl: Storage_opt tFUNCTION Identifier StSep BodyStatements tEND tFUNCTION  */
#line 483 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-4].string), FUNC_FUNCTION, (yyvsp[-6].uint), NULL, (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3074 "dlls/vbscript/parser.tab.c"
    break;

  case 178: /* FunctionDecl: Storage_opt tFUNCTION Identifier ArgumentsDecl Nl_opt BodyStatements tEND tFUNCTION  */
#line 485 "dlls/vbscript/parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-5].string), FUNC_FUNCTION, (yyvsp[-7].uint), (yyvsp[-4].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3080 "dlls/vbscript/parser.tab.c"
    break;

  case 179: /* Storage_opt: %empty  */
#line 488 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = 0; }
#line 3086 "dlls/vbscript/parser.tab.c"
    break;

  case 180: /* Storage_opt: Storage  */
#line 489 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = (yyvsp[0].uint); }
#line 3092 "dlls/vbscript/parser.tab.c"
    break;

  case 181: /* Storage: tPUBLIC tDEFAULT  */
#line 492 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = STORAGE_IS_DEFAULT; }
#line 3098 "dlls/vbscript/parser.tab.c"
    break;

  case 182: /* Storage: tPUBLIC  */
#line 493 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = 0; }
#line 3104 "dlls/vbscript/parser.tab.c"
    break;

  case 183: /* Storage: tPRIVATE  */
#line 494 "dlls/vbscript/parser.y"
                                    { (yyval.uint) = STORAGE_IS_PRIVATE; }
#line 3110 "dlls/vbscript/parser.tab.c"
    break;

  case 184: /* ArgumentsDecl_opt: %empty  */
#line 497 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = 0; }
#line 3116 "dlls/vbscript/parser.tab.c"
    break;

  case 185: /* ArgumentsDecl_opt: ArgumentsDecl  */
#line 498 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = (yyvsp[0].arg_decl); }
#line 3122 "dlls/vbscript/parser.tab.c"
    break;

  case 186: /* ArgumentsDecl: tEMPTYBRACKETS  */
#line 501 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = NULL; }
#line 3128 "dlls/vbscript/parser.tab.c"
    break;

  case 187: /* ArgumentsDecl: '(' ArgumentDeclList ')'  */
#line 502 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = (yyvsp[-1].arg_decl); }
#line 3134 "dlls/vbscript/parser.tab.c"
    break;

  case 188: /* ArgumentDeclList: ArgumentDecl  */
#line 505 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = (yyvsp[0].arg_decl); }
#line 3140 "dlls/vbscript/parser.tab.c"
    break;

  case 189: /* ArgumentDeclList: ArgumentDecl ',' ArgumentDeclList  */
#line 506 "dlls/vbscript/parser.y"
                                                { (yyvsp[-2].arg_decl)->next = (yyvsp[0].arg_decl); (yyval.arg_decl) = (yyvsp[-2].arg_decl); }
#line 3146 "dlls/vbscript/parser.tab.c"
    break;

  case 190: /* ArgumentDecl: Identifier EmptyBrackets_opt  */
#line 509 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = new_argument_decl(ctx, (yyvsp[-1].string), TRUE); }
#line 3152 "dlls/vbscript/parser.tab.c"
    break;

  case 191: /* ArgumentDecl: tBYREF Identifier EmptyBrackets_opt  */
#line 510 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = new_argument_decl(ctx, (yyvsp[-1].string), TRUE); }
#line 3158 "dlls/vbscript/parser.tab.c"
    break;

  case 192: /* ArgumentDecl: tBYVAL Identifier EmptyBrackets_opt  */
#line 511 "dlls/vbscript/parser.y"
                                                { (yyval.arg_decl) = new_argument_decl(ctx, (yyvsp[-1].string), FALSE); }
#line 3164 "dlls/vbscript/parser.tab.c"
    break;

  case 193: /* Identifier: tIdentifier  */
#line 515 "dlls/vbscript/parser.y"
                     { (yyval.string) = (yyvsp[0].string); }
#line 3170 "dlls/vbscript/parser.tab.c"
    break;

  case 194: /* Identifier: tDEFAULT  */
#line 516 "dlls/vbscript/parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3176 "dlls/vbscript/parser.tab.c"
    break;

  case 195: /* Identifier: tERROR  */
#line 517 "dlls/vbscript/parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3182 "dlls/vbscript/parser.tab.c"
    break;

  case 196: /* Identifier: tEXPLICIT  */
#line 518 "dlls/vbscript/parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3188 "dlls/vbscript/parser.tab.c"
    break;

  case 197: /* Identifier: tPROPERTY  */
#line 519 "dlls/vbscript/parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3194 "dlls/vbscript/parser.tab.c"
    break;

  case 198: /* Identifier: tSTEP  */
#line 520 "dlls/vbscript/parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3200 "dlls/vbscript/parser.tab.c"
    break;


#line 3204 "dlls/vbscript/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (&yylloc, ctx, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= PARSER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == PARSER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, ctx);
          yychar = PARSER_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, ctx, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != PARSER_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 537 "dlls/vbscript/parser.y"


static int parser_error(unsigned *loc, parser_ctx_t *ctx, const char *str)
{
    if(ctx->error_loc == -1)
        ctx->error_loc = *loc;
    if(ctx->hres == S_OK) {
        FIXME("%s: %s\n", debugstr_w(ctx->code + *loc), debugstr_a(str));
        ctx->hres = E_FAIL;
    }else {
        WARN("%s: %08lx\n", debugstr_w(ctx->code + *loc), ctx->hres);
    }
    return 0;
}

static void source_add_statement(parser_ctx_t *ctx, statement_t *stat)
{
    if(!stat)
        return;

    /* concatenate both linked lists */
    if(ctx->stats) {
        ctx->stats_tail->next = stat;
        ctx->stats_tail = stat;
    }else {
        ctx->stats = ctx->stats_tail = stat;
    }
    /* find new tail */
    while(ctx->stats_tail->next) {
        ctx->stats_tail=ctx->stats_tail->next;
    }
}

static void source_add_class(parser_ctx_t *ctx, class_decl_t *class_decl)
{
    class_decl->next = ctx->class_decls;
    ctx->class_decls = class_decl;
}

static void handle_isexpression_script(parser_ctx_t *ctx, expression_t *expr)
{
    retval_statement_t *stat;

    if(!expr)
        return;

    stat = new_statement(ctx, STAT_RETVAL, sizeof(*stat), 0);
    if(!stat)
        return;

    stat->expr = expr;
    ctx->stats = &stat->stat;
}

static void *new_expression(parser_ctx_t *ctx, expression_type_t type, size_t size)
{
    expression_t *expr;

    expr = parser_alloc(ctx, size ? size : sizeof(*expr));
    if(expr) {
        expr->type = type;
        expr->next = NULL;
    }

    return expr;
}

static expression_t *new_bool_expression(parser_ctx_t *ctx, VARIANT_BOOL value)
{
    bool_expression_t *expr;

    expr = new_expression(ctx, EXPR_BOOL, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_string_expression(parser_ctx_t *ctx, const WCHAR *value)
{
    string_expression_t *expr;

    expr = new_expression(ctx, EXPR_STRING, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_date_expression(parser_ctx_t *ctx, DATE value)
{
    date_expression_t *expr;

    expr = new_expression(ctx, EXPR_DATE, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_long_expression(parser_ctx_t *ctx, expression_type_t type, LONG value)
{
    int_expression_t *expr;

    expr = new_expression(ctx, type, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_double_expression(parser_ctx_t *ctx, double value)
{
    double_expression_t *expr;

    expr = new_expression(ctx, EXPR_DOUBLE, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_unary_expression(parser_ctx_t *ctx, expression_type_t type, expression_t *subexpr)
{
    unary_expression_t *expr;

    expr = new_expression(ctx, type, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->subexpr = subexpr;
    return &expr->expr;
}

static expression_t *new_binary_expression(parser_ctx_t *ctx, expression_type_t type, expression_t *left, expression_t *right)
{
    binary_expression_t *expr;

    expr = new_expression(ctx, type, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->left = left;
    expr->right = right;
    return &expr->expr;
}

static member_expression_t *new_member_expression(parser_ctx_t *ctx, expression_t *obj_expr, const WCHAR *identifier)
{
    member_expression_t *expr;

    expr = new_expression(ctx, EXPR_MEMBER, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->obj_expr = obj_expr;
    expr->identifier = identifier;
    return expr;
}

static call_expression_t *new_call_expression(parser_ctx_t *ctx, expression_t *expr, expression_t *arguments)
{
    call_expression_t *call_expr;

    call_expr = new_expression(ctx, EXPR_CALL, sizeof(*call_expr));
    if(!call_expr)
        return NULL;

    call_expr->call_expr = expr;
    call_expr->args = arguments;
    return call_expr;
}

static call_expression_t *make_call_expression(parser_ctx_t *ctx, expression_t *callee_expr, expression_t *arguments)
{
    call_expression_t *call_expr;

    if(callee_expr->type == EXPR_MEMBER)
        return new_call_expression(ctx, callee_expr, arguments);
    if(callee_expr->type != EXPR_CALL) {
        FIXME("Unhandled for expr type %u\n", callee_expr->type);
        ctx->hres = E_FAIL;
        return NULL;
    }
    call_expr = (call_expression_t*)callee_expr;
    if(!call_expr->args) {
        call_expr->args = arguments;
        return call_expr;
    }

    if(call_expr->args->next) {
        FIXME("Invalid syntax: invalid use of parentheses for arguments\n");
        ctx->hres = E_FAIL;
        return NULL;
    }

    call_expr->args = new_unary_expression(ctx, EXPR_BRACKETS, call_expr->args);
    if(!call_expr->args)
        return NULL;
    if(!arguments)
        return call_expr;

    if(arguments->type != EXPR_NOARG) {
        FIXME("Invalid syntax: missing comma\n");
        ctx->hres = E_FAIL;
        return NULL;
    }

    call_expr->args->next = arguments->next;
    return call_expr;
}

static expression_t *new_new_expression(parser_ctx_t *ctx, const WCHAR *identifier)
{
    string_expression_t *expr;

    expr = new_expression(ctx, EXPR_NEW, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = identifier;
    return &expr->expr;
}

static void *new_statement(parser_ctx_t *ctx, statement_type_t type, size_t size, unsigned loc)
{
    statement_t *stat;

    stat = parser_alloc(ctx, size ? size : sizeof(*stat));
    if(stat) {
        stat->type = type;
        stat->loc = loc;
        stat->next = NULL;
    }

    return stat;
}

static statement_t *new_call_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr)
{
    call_expression_t *call_expr = NULL;
    call_statement_t *stat;

    stat = new_statement(ctx, STAT_CALL, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    switch(expr->type) {
    case EXPR_MEMBER:
        call_expr = new_call_expression(ctx, expr, NULL);
        break;
    case EXPR_CALL:
        call_expr = (call_expression_t*)expr;
        break;
    default:
        FIXME("Unsupported expr type %u\n", expr->type);
        ctx->hres = E_NOTIMPL;
    }
    if(!call_expr)
        return NULL;

    stat->expr = call_expr;
    return &stat->stat;
}

static statement_t *new_assign_statement(parser_ctx_t *ctx, unsigned loc, expression_t *left, expression_t *right)
{
    assign_statement_t *stat;

    stat = new_statement(ctx, STAT_ASSIGN, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->left_expr = left;
    stat->value_expr = right;

    return &stat->stat;
}

static statement_t *new_set_statement(parser_ctx_t *ctx, unsigned loc, expression_t *left, expression_t *right)
{
    assign_statement_t *stat;

    stat = new_statement(ctx, STAT_SET, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->left_expr = left;
    stat->value_expr = right;

    return &stat->stat;
}

static dim_decl_t *new_dim_decl(parser_ctx_t *ctx, const WCHAR *name, BOOL is_array, dim_list_t *dims)
{
    dim_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->name = name;
    decl->is_array = is_array;
    decl->dims = dims;
    decl->next = NULL;
    return decl;
}

static dim_list_t *new_dim(parser_ctx_t *ctx, unsigned val, dim_list_t *next)
{
    dim_list_t *ret;

    ret = parser_alloc(ctx, sizeof(*ret));
    if(!ret)
        return NULL;

    ret->val = val;
    ret->next = next;
    return ret;
}

static statement_t *new_dim_statement(parser_ctx_t *ctx, unsigned loc, dim_decl_t *decls)
{
    dim_statement_t *stat;

    stat = new_statement(ctx, STAT_DIM, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->dim_decls = decls;
    return &stat->stat;
}

static redim_decl_t *new_redim_decl(parser_ctx_t *ctx, const WCHAR *identifier, expression_t *dims)
{
    redim_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->identifier = identifier;
    decl->dims = dims;
    decl->next = NULL;
    return decl;
}

static statement_t *new_redim_statement(parser_ctx_t *ctx, unsigned loc, BOOL preserve, redim_decl_t *decls)
{
    redim_statement_t *stat;

    stat = new_statement(ctx, STAT_REDIM, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->preserve = preserve;
    stat->redim_decls = decls;
    return &stat->stat;
}

static elseif_decl_t *new_elseif_decl(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *stat)
{
    elseif_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->expr = expr;
    decl->stat = stat;
    decl->loc = loc;
    decl->next = NULL;
    return decl;
}

static statement_t *new_while_statement(parser_ctx_t *ctx, unsigned loc, statement_type_t type, expression_t *expr, statement_t *body)
{
    while_statement_t *stat;

    stat = new_statement(ctx, type, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->body = body;
    return &stat->stat;
}

static statement_t *new_forto_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier, expression_t *from_expr,
        expression_t *to_expr, expression_t *step_expr, statement_t *body)
{
    forto_statement_t *stat;

    stat = new_statement(ctx, STAT_FORTO, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->identifier = identifier;
    stat->from_expr = from_expr;
    stat->to_expr = to_expr;
    stat->step_expr = step_expr;
    stat->body = body;
    return &stat->stat;
}

static statement_t *new_foreach_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier, expression_t *group_expr,
        statement_t *body)
{
    foreach_statement_t *stat;

    stat = new_statement(ctx, STAT_FOREACH, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->identifier = identifier;
    stat->group_expr = group_expr;
    stat->body = body;
    return &stat->stat;
}

static statement_t *new_if_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *if_stat, elseif_decl_t *elseif_decl,
        statement_t *else_stat)
{
    if_statement_t *stat;

    stat = new_statement(ctx, STAT_IF, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->if_stat = if_stat;
    stat->elseifs = elseif_decl;
    stat->else_stat = else_stat;
    return &stat->stat;
}

static statement_t *new_select_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, case_clausule_t *case_clausules)
{
    select_statement_t *stat;

    stat = new_statement(ctx, STAT_SELECT, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->case_clausules = case_clausules;
    return &stat->stat;
}

static statement_t *new_with_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *body)
{
    with_statement_t *stat;

    stat = new_statement(ctx, STAT_WITH, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->body = body;
    return &stat->stat;
}

static case_clausule_t *new_case_clausule(parser_ctx_t *ctx, expression_t *expr, statement_t *stat, case_clausule_t *next)
{
    case_clausule_t *ret;

    ret = parser_alloc(ctx, sizeof(*ret));
    if(!ret)
        return NULL;

    ret->expr = expr;
    ret->stat = stat;
    ret->next = next;
    return ret;
}

static statement_t *new_onerror_statement(parser_ctx_t *ctx, unsigned loc, BOOL resume_next)
{
    onerror_statement_t *stat;

    stat = new_statement(ctx, STAT_ONERROR, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->resume_next = resume_next;
    return &stat->stat;
}

static arg_decl_t *new_argument_decl(parser_ctx_t *ctx, const WCHAR *name, BOOL by_ref)
{
    arg_decl_t *arg_decl;

    arg_decl = parser_alloc(ctx, sizeof(*arg_decl));
    if(!arg_decl)
        return NULL;

    arg_decl->name = name;
    arg_decl->by_ref = by_ref;
    arg_decl->next = NULL;
    return arg_decl;
}

static function_decl_t *new_function_decl(parser_ctx_t *ctx, const WCHAR *name, function_type_t type,
        unsigned storage_flags, arg_decl_t *arg_decl, statement_t *body)
{
    function_decl_t *decl;
    BOOL is_default = FALSE;

    if(storage_flags & STORAGE_IS_DEFAULT) {
        if(type == FUNC_PROPGET || type == FUNC_FUNCTION || type == FUNC_SUB) {
            is_default = TRUE;
        }else {
            FIXME("Invalid default property\n");
            ctx->hres = E_FAIL;
            return NULL;
        }
    }

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->name = name;
    decl->type = type;
    decl->is_public = !(storage_flags & STORAGE_IS_PRIVATE);
    decl->is_default = is_default;
    decl->args = arg_decl;
    decl->body = body;
    decl->next = NULL;
    decl->next_prop_func = NULL;
    return decl;
}

static statement_t *new_function_statement(parser_ctx_t *ctx, unsigned loc, function_decl_t *decl)
{
    function_statement_t *stat;

    stat = new_statement(ctx, STAT_FUNC, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->func_decl = decl;
    return &stat->stat;
}

static class_decl_t *new_class_decl(parser_ctx_t *ctx)
{
    class_decl_t *class_decl;

    class_decl = parser_alloc(ctx, sizeof(*class_decl));
    if(!class_decl)
        return NULL;

    class_decl->funcs = NULL;
    class_decl->props = NULL;
    class_decl->next = NULL;
    return class_decl;
}

static class_decl_t *add_class_function(parser_ctx_t *ctx, class_decl_t *class_decl, function_decl_t *decl)
{
    function_decl_t *iter;

    for(iter = class_decl->funcs; iter; iter = iter->next) {
        if(!wcsicmp(iter->name, decl->name)) {
            if(decl->type == FUNC_SUB || decl->type == FUNC_FUNCTION) {
                FIXME("Redefinition of %s::%s\n", debugstr_w(class_decl->name), debugstr_w(decl->name));
                ctx->hres = E_FAIL;
                return NULL;
            }

            while(1) {
                if(iter->type == decl->type) {
                    FIXME("Redefinition of %s::%s\n", debugstr_w(class_decl->name), debugstr_w(decl->name));
                    ctx->hres = E_FAIL;
                    return NULL;
                }
                if(!iter->next_prop_func)
                    break;
                iter = iter->next_prop_func;
            }

            iter->next_prop_func = decl;
            return class_decl;
        }
    }

    decl->next = class_decl->funcs;
    class_decl->funcs = decl;
    return class_decl;
}

static class_decl_t *add_dim_prop(parser_ctx_t *ctx, class_decl_t *class_decl, dim_decl_t *dim_decl, unsigned storage_flags)
{
    if(storage_flags & STORAGE_IS_DEFAULT) {
        FIXME("variant prop can't be default value\n");
        ctx->hres = E_FAIL;
        return NULL;
    }

    dim_decl->is_public = !(storage_flags & STORAGE_IS_PRIVATE);
    dim_decl->next = class_decl->props;
    class_decl->props = dim_decl;
    return class_decl;
}

static const_decl_t *new_const_decl(parser_ctx_t *ctx, const WCHAR *name, expression_t *expr)
{
    const_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->name = name;
    decl->value_expr = expr;
    decl->next = NULL;
    return decl;
}

static statement_t *new_const_statement(parser_ctx_t *ctx, unsigned loc, const_decl_t *decls)
{
    const_statement_t *stat;

    stat = new_statement(ctx, STAT_CONST, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->decls = decls;
    return &stat->stat;
}

static statement_t *link_statements(statement_t *head, statement_t *tail)
{
    statement_t *iter;

    if (!head) return tail;

    for(iter = head; iter->next; iter = iter->next);
    iter->next = tail;

    return head;
}

void *parser_alloc(parser_ctx_t *ctx, size_t size)
{
    void *ret;

    ret = heap_pool_alloc(&ctx->heap, size);
    if(!ret)
        ctx->hres = E_OUTOFMEMORY;
    return ret;
}

HRESULT parse_script(parser_ctx_t *ctx, const WCHAR *code, const WCHAR *delimiter, DWORD flags)
{
    ctx->code = ctx->ptr = code;
    ctx->end = ctx->code + lstrlenW(ctx->code);

    heap_pool_init(&ctx->heap);

    ctx->hres = S_OK;
    ctx->error_loc = -1;
    ctx->last_token = tNL;
    ctx->last_nl = 0;
    ctx->stats = ctx->stats_tail = NULL;
    ctx->class_decls = NULL;
    ctx->option_explicit = FALSE;
    ctx->is_html = delimiter && !wcsicmp(delimiter, L"</script>");

    if(flags & SCRIPTTEXT_ISEXPRESSION)
        ctx->last_token = tEXPRESSION;

    parser_parse(ctx);

    return ctx->hres;
}

void parser_release(parser_ctx_t *ctx)
{
    heap_pool_free(&ctx->heap);
}
