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
#line 19 "dlls/jscript/parser.y"


#include "jscript.h"
#include "engine.h"
#include "parser.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(jscript);

static int parser_error(unsigned*,parser_ctx_t*,const char*);
static void set_error(parser_ctx_t*,unsigned,HRESULT);
static BOOL explicit_error(parser_ctx_t*,void*,WCHAR);
static BOOL allow_auto_semicolon(parser_ctx_t*);

static literal_t *new_string_literal(parser_ctx_t*,jsstr_t*);
static literal_t *new_null_literal(parser_ctx_t*);

typedef struct _property_list_t {
    property_definition_t *head;
    property_definition_t *tail;
} property_list_t;

static property_definition_t *new_property_definition(parser_ctx_t *ctx, property_definition_type_t,
                                                      literal_t *name, expression_t *value);
static property_list_t *new_property_list(parser_ctx_t*,property_definition_t*);
static property_list_t *property_list_add(parser_ctx_t*,property_list_t*,property_definition_t*);

typedef struct _element_list_t {
    array_element_t *head;
    array_element_t *tail;
} element_list_t;

static element_list_t *new_element_list(parser_ctx_t*,int,expression_t*);
static element_list_t *element_list_add(parser_ctx_t*,element_list_t*,int,expression_t*);

typedef struct _argument_list_t {
    argument_t *head;
    argument_t *tail;
} argument_list_t;

static argument_list_t *new_argument_list(parser_ctx_t*,expression_t*);
static argument_list_t *argument_list_add(parser_ctx_t*,argument_list_t*,expression_t*);

typedef struct _case_list_t {
    case_clausule_t *head;
    case_clausule_t *tail;
} case_list_t;

typedef struct _statement_list_t {
   statement_t *head;
   statement_t *tail;
} statement_list_t;

static catch_block_t *new_catch_block(parser_ctx_t*,const WCHAR*,statement_t*);
static case_clausule_t *new_case_clausule(parser_ctx_t*,unsigned,expression_t*,statement_list_t*);
static case_list_t *new_case_list(parser_ctx_t*,case_clausule_t*);
static case_list_t *case_list_add(parser_ctx_t*,case_list_t*,case_clausule_t*);
static case_clausule_t *new_case_block(parser_ctx_t*,case_list_t*,case_clausule_t*,case_list_t*);

typedef struct _variable_list_t {
    variable_declaration_t *head;
    variable_declaration_t *tail;
} variable_list_t;

static variable_declaration_t *new_variable_declaration(parser_ctx_t*,const WCHAR*,expression_t*);
static variable_list_t *new_variable_list(parser_ctx_t*,variable_declaration_t*);
static variable_list_t *variable_list_add(parser_ctx_t*,variable_list_t*,variable_declaration_t*);

static void *new_statement(parser_ctx_t*,statement_type_t,size_t,unsigned);
static statement_t *new_block_statement(parser_ctx_t*,unsigned,statement_list_t*);
static statement_t *new_var_statement(parser_ctx_t*,BOOL,BOOL,unsigned,variable_list_t*);
static statement_t *new_expression_statement(parser_ctx_t*,unsigned,expression_t*);
static statement_t *new_if_statement(parser_ctx_t*,unsigned,expression_t*,statement_t*,statement_t*);
static statement_t *new_while_statement(parser_ctx_t*,unsigned,BOOL,expression_t*,statement_t*);
static statement_t *new_for_statement(parser_ctx_t*,unsigned,variable_declaration_t*,expression_t*,expression_t*,unsigned,
                                      expression_t*,unsigned,statement_t*);
static statement_t *new_forin_statement(parser_ctx_t*,unsigned,variable_declaration_t*,expression_t*,expression_t*,statement_t*);
static statement_t *new_continue_statement(parser_ctx_t*,unsigned,const WCHAR*);
static statement_t *new_break_statement(parser_ctx_t*,unsigned,const WCHAR*);
static statement_t *new_return_statement(parser_ctx_t*,unsigned,expression_t*);
static statement_t *new_with_statement(parser_ctx_t*,unsigned,expression_t*,statement_t*);
static statement_t *new_labelled_statement(parser_ctx_t*,unsigned,const WCHAR*,statement_t*);
static statement_t *new_switch_statement(parser_ctx_t*,unsigned,expression_t*,case_clausule_t*);
static statement_t *new_throw_statement(parser_ctx_t*,unsigned,expression_t*);
static statement_t *new_try_statement(parser_ctx_t*,statement_t*,catch_block_t*,statement_t*,unsigned);

static statement_list_t *new_statement_list(parser_ctx_t*,statement_t*);
static statement_list_t *statement_list_add(statement_list_t*,statement_t*);

typedef struct _parameter_list_t {
    parameter_t *head;
    parameter_t *tail;
} parameter_list_t;

static parameter_list_t *new_parameter_list(parser_ctx_t*,const WCHAR*);
static parameter_list_t *parameter_list_add(parser_ctx_t*,parameter_list_t*,const WCHAR*);

static void *new_expression(parser_ctx_t *ctx,expression_type_t,size_t);
static expression_t *new_function_expression(parser_ctx_t*,const WCHAR*,parameter_list_t*,
        statement_list_t*,const WCHAR*,const WCHAR*,DWORD);
static expression_t *new_binary_expression(parser_ctx_t*,expression_type_t,expression_t*,expression_t*);
static expression_t *new_unary_expression(parser_ctx_t*,expression_type_t,expression_t*);
static expression_t *new_conditional_expression(parser_ctx_t*,expression_t*,expression_t*,expression_t*);
static expression_t *new_member_expression(parser_ctx_t*,expression_t*,const WCHAR*);
static expression_t *new_new_expression(parser_ctx_t*,expression_t*,argument_list_t*);
static expression_t *new_call_expression(parser_ctx_t*,expression_t*,argument_list_t*);
static expression_t *new_identifier_expression(parser_ctx_t*,const WCHAR*);
static expression_t *new_literal_expression(parser_ctx_t*,literal_t*);
static expression_t *new_array_literal_expression(parser_ctx_t*,element_list_t*,int);
static expression_t *new_prop_and_value_expression(parser_ctx_t*,property_list_t*);

#define PARSER_LTYPE unsigned
#define YYLLOC_DEFAULT(Cur, Rhs, N) Cur = YYRHSLOC((Rhs), (N) ? 1 : 0)


#line 195 "dlls/jscript/parser.tab.c"

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
    kBREAK = 258,                  /* kBREAK  */
    kCASE = 259,                   /* kCASE  */
    kCATCH = 260,                  /* kCATCH  */
    kCONST = 261,                  /* kCONST  */
    kCONTINUE = 262,               /* kCONTINUE  */
    kDEFAULT = 263,                /* kDEFAULT  */
    kDELETE = 264,                 /* kDELETE  */
    kDO = 265,                     /* kDO  */
    kELSE = 266,                   /* kELSE  */
    kFUNCTION = 267,               /* kFUNCTION  */
    kIF = 268,                     /* kIF  */
    kFINALLY = 269,                /* kFINALLY  */
    kFOR = 270,                    /* kFOR  */
    kGET = 271,                    /* kGET  */
    kIN = 272,                     /* kIN  */
    kLET = 273,                    /* kLET  */
    kSET = 274,                    /* kSET  */
    kINSTANCEOF = 275,             /* kINSTANCEOF  */
    kNEW = 276,                    /* kNEW  */
    kNULL = 277,                   /* kNULL  */
    kRETURN = 278,                 /* kRETURN  */
    kSWITCH = 279,                 /* kSWITCH  */
    kTHIS = 280,                   /* kTHIS  */
    kTHROW = 281,                  /* kTHROW  */
    kTRUE = 282,                   /* kTRUE  */
    kFALSE = 283,                  /* kFALSE  */
    kTRY = 284,                    /* kTRY  */
    kTYPEOF = 285,                 /* kTYPEOF  */
    kVAR = 286,                    /* kVAR  */
    kVOID = 287,                   /* kVOID  */
    kWHILE = 288,                  /* kWHILE  */
    kWITH = 289,                   /* kWITH  */
    tANDAND = 290,                 /* tANDAND  */
    tOROR = 291,                   /* tOROR  */
    tINC = 292,                    /* tINC  */
    tDEC = 293,                    /* tDEC  */
    tHTMLCOMMENT = 294,            /* tHTMLCOMMENT  */
    kDIVEQ = 295,                  /* kDIVEQ  */
    kDCOL = 296,                   /* kDCOL  */
    tIdentifier = 297,             /* tIdentifier  */
    tAssignOper = 298,             /* tAssignOper  */
    tEqOper = 299,                 /* tEqOper  */
    tShiftOper = 300,              /* tShiftOper  */
    tRelOper = 301,                /* tRelOper  */
    tNumericLiteral = 302,         /* tNumericLiteral  */
    tBooleanLiteral = 303,         /* tBooleanLiteral  */
    tStringLiteral = 304,          /* tStringLiteral  */
    LOWER_THAN_ELSE = 305          /* LOWER_THAN_ELSE  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 142 "dlls/jscript/parser.y"

    int                     ival;
    jsstr_t                 *str;
    literal_t               *literal;
    struct _argument_list_t *argument_list;
    case_clausule_t         *case_clausule;
    struct _case_list_t     *case_list;
    catch_block_t           *catch_block;
    struct _element_list_t  *element_list;
    expression_t            *expr;
    const WCHAR            *identifier;
    struct _parameter_list_t *parameter_list;
    struct _property_list_t *property_list;
    property_definition_t   *property_definition;
    statement_t             *statement;
    struct _statement_list_t *statement_list;
    struct _variable_list_t *variable_list;
    variable_declaration_t  *variable_declaration;

#line 320 "dlls/jscript/parser.tab.c"

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
  YYSYMBOL_kBREAK = 3,                     /* kBREAK  */
  YYSYMBOL_kCASE = 4,                      /* kCASE  */
  YYSYMBOL_kCATCH = 5,                     /* kCATCH  */
  YYSYMBOL_kCONST = 6,                     /* kCONST  */
  YYSYMBOL_kCONTINUE = 7,                  /* kCONTINUE  */
  YYSYMBOL_kDEFAULT = 8,                   /* kDEFAULT  */
  YYSYMBOL_kDELETE = 9,                    /* kDELETE  */
  YYSYMBOL_kDO = 10,                       /* kDO  */
  YYSYMBOL_kELSE = 11,                     /* kELSE  */
  YYSYMBOL_kFUNCTION = 12,                 /* kFUNCTION  */
  YYSYMBOL_kIF = 13,                       /* kIF  */
  YYSYMBOL_kFINALLY = 14,                  /* kFINALLY  */
  YYSYMBOL_kFOR = 15,                      /* kFOR  */
  YYSYMBOL_kGET = 16,                      /* kGET  */
  YYSYMBOL_kIN = 17,                       /* kIN  */
  YYSYMBOL_kLET = 18,                      /* kLET  */
  YYSYMBOL_kSET = 19,                      /* kSET  */
  YYSYMBOL_kINSTANCEOF = 20,               /* kINSTANCEOF  */
  YYSYMBOL_kNEW = 21,                      /* kNEW  */
  YYSYMBOL_kNULL = 22,                     /* kNULL  */
  YYSYMBOL_kRETURN = 23,                   /* kRETURN  */
  YYSYMBOL_kSWITCH = 24,                   /* kSWITCH  */
  YYSYMBOL_kTHIS = 25,                     /* kTHIS  */
  YYSYMBOL_kTHROW = 26,                    /* kTHROW  */
  YYSYMBOL_kTRUE = 27,                     /* kTRUE  */
  YYSYMBOL_kFALSE = 28,                    /* kFALSE  */
  YYSYMBOL_kTRY = 29,                      /* kTRY  */
  YYSYMBOL_kTYPEOF = 30,                   /* kTYPEOF  */
  YYSYMBOL_kVAR = 31,                      /* kVAR  */
  YYSYMBOL_kVOID = 32,                     /* kVOID  */
  YYSYMBOL_kWHILE = 33,                    /* kWHILE  */
  YYSYMBOL_kWITH = 34,                     /* kWITH  */
  YYSYMBOL_tANDAND = 35,                   /* tANDAND  */
  YYSYMBOL_tOROR = 36,                     /* tOROR  */
  YYSYMBOL_tINC = 37,                      /* tINC  */
  YYSYMBOL_tDEC = 38,                      /* tDEC  */
  YYSYMBOL_tHTMLCOMMENT = 39,              /* tHTMLCOMMENT  */
  YYSYMBOL_kDIVEQ = 40,                    /* kDIVEQ  */
  YYSYMBOL_kDCOL = 41,                     /* kDCOL  */
  YYSYMBOL_tIdentifier = 42,               /* tIdentifier  */
  YYSYMBOL_tAssignOper = 43,               /* tAssignOper  */
  YYSYMBOL_tEqOper = 44,                   /* tEqOper  */
  YYSYMBOL_tShiftOper = 45,                /* tShiftOper  */
  YYSYMBOL_tRelOper = 46,                  /* tRelOper  */
  YYSYMBOL_tNumericLiteral = 47,           /* tNumericLiteral  */
  YYSYMBOL_tBooleanLiteral = 48,           /* tBooleanLiteral  */
  YYSYMBOL_tStringLiteral = 49,            /* tStringLiteral  */
  YYSYMBOL_LOWER_THAN_ELSE = 50,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_51_ = 51,                       /* ':'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '='  */
  YYSYMBOL_56_ = 56,                       /* ';'  */
  YYSYMBOL_57_ = 57,                       /* '?'  */
  YYSYMBOL_58_ = 58,                       /* '|'  */
  YYSYMBOL_59_ = 59,                       /* '^'  */
  YYSYMBOL_60_ = 60,                       /* '&'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_66_ = 66,                       /* '~'  */
  YYSYMBOL_67_ = 67,                       /* '!'  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_70_ = 70,                       /* '.'  */
  YYSYMBOL_71_ = 71,                       /* '('  */
  YYSYMBOL_72_ = 72,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_Script = 74,                    /* Script  */
  YYSYMBOL_ScriptBody = 75,                /* ScriptBody  */
  YYSYMBOL_HtmlComment = 76,               /* HtmlComment  */
  YYSYMBOL_FunctionStatementList = 77,     /* FunctionStatementList  */
  YYSYMBOL_FunctionExpression = 78,        /* FunctionExpression  */
  YYSYMBOL_FunctionBody = 79,              /* FunctionBody  */
  YYSYMBOL_FormalParameterList = 80,       /* FormalParameterList  */
  YYSYMBOL_FormalParameterList_opt = 81,   /* FormalParameterList_opt  */
  YYSYMBOL_Statement = 82,                 /* Statement  */
  YYSYMBOL_Declaration = 83,               /* Declaration  */
  YYSYMBOL_StatementListItem = 84,         /* StatementListItem  */
  YYSYMBOL_StatementList = 85,             /* StatementList  */
  YYSYMBOL_StatementList_opt = 86,         /* StatementList_opt  */
  YYSYMBOL_Block = 87,                     /* Block  */
  YYSYMBOL_LexicalDeclaration = 88,        /* LexicalDeclaration  */
  YYSYMBOL_LexicalDeclarationNoIn = 89,    /* LexicalDeclarationNoIn  */
  YYSYMBOL_VariableStatement = 90,         /* VariableStatement  */
  YYSYMBOL_VariableDeclarationList = 91,   /* VariableDeclarationList  */
  YYSYMBOL_VariableDeclarationListNoIn = 92, /* VariableDeclarationListNoIn  */
  YYSYMBOL_VariableDeclaration = 93,       /* VariableDeclaration  */
  YYSYMBOL_VariableDeclarationNoIn = 94,   /* VariableDeclarationNoIn  */
  YYSYMBOL_Initialiser_opt = 95,           /* Initialiser_opt  */
  YYSYMBOL_Initialiser = 96,               /* Initialiser  */
  YYSYMBOL_InitialiserNoIn_opt = 97,       /* InitialiserNoIn_opt  */
  YYSYMBOL_InitialiserNoIn = 98,           /* InitialiserNoIn  */
  YYSYMBOL_EmptyStatement = 99,            /* EmptyStatement  */
  YYSYMBOL_ExpressionStatement = 100,      /* ExpressionStatement  */
  YYSYMBOL_IfStatement = 101,              /* IfStatement  */
  YYSYMBOL_IterationStatement = 102,       /* IterationStatement  */
  YYSYMBOL_103_1 = 103,                    /* $@1  */
  YYSYMBOL_104_2 = 104,                    /* $@2  */
  YYSYMBOL_105_3 = 105,                    /* $@3  */
  YYSYMBOL_106_4 = 106,                    /* $@4  */
  YYSYMBOL_107_5 = 107,                    /* $@5  */
  YYSYMBOL_108_6 = 108,                    /* $@6  */
  YYSYMBOL_ContinueStatement = 109,        /* ContinueStatement  */
  YYSYMBOL_BreakStatement = 110,           /* BreakStatement  */
  YYSYMBOL_ReturnStatement = 111,          /* ReturnStatement  */
  YYSYMBOL_WithStatement = 112,            /* WithStatement  */
  YYSYMBOL_LabelledStatement = 113,        /* LabelledStatement  */
  YYSYMBOL_SwitchStatement = 114,          /* SwitchStatement  */
  YYSYMBOL_CaseBlock = 115,                /* CaseBlock  */
  YYSYMBOL_CaseClausules_opt = 116,        /* CaseClausules_opt  */
  YYSYMBOL_CaseClausules = 117,            /* CaseClausules  */
  YYSYMBOL_CaseClausule = 118,             /* CaseClausule  */
  YYSYMBOL_DefaultClausule = 119,          /* DefaultClausule  */
  YYSYMBOL_ThrowStatement = 120,           /* ThrowStatement  */
  YYSYMBOL_TryStatement = 121,             /* TryStatement  */
  YYSYMBOL_Catch = 122,                    /* Catch  */
  YYSYMBOL_Finally = 123,                  /* Finally  */
  YYSYMBOL_Expression_opt = 124,           /* Expression_opt  */
  YYSYMBOL_Expression_err = 125,           /* Expression_err  */
  YYSYMBOL_Expression = 126,               /* Expression  */
  YYSYMBOL_ExpressionNoIn_opt = 127,       /* ExpressionNoIn_opt  */
  YYSYMBOL_ExpressionNoIn = 128,           /* ExpressionNoIn  */
  YYSYMBOL_AssignOper = 129,               /* AssignOper  */
  YYSYMBOL_AssignmentExpression = 130,     /* AssignmentExpression  */
  YYSYMBOL_AssignmentExpressionNoIn = 131, /* AssignmentExpressionNoIn  */
  YYSYMBOL_ConditionalExpression = 132,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalExpressionNoIn = 133, /* ConditionalExpressionNoIn  */
  YYSYMBOL_LogicalORExpression = 134,      /* LogicalORExpression  */
  YYSYMBOL_LogicalORExpressionNoIn = 135,  /* LogicalORExpressionNoIn  */
  YYSYMBOL_LogicalANDExpression = 136,     /* LogicalANDExpression  */
  YYSYMBOL_LogicalANDExpressionNoIn = 137, /* LogicalANDExpressionNoIn  */
  YYSYMBOL_BitwiseORExpression = 138,      /* BitwiseORExpression  */
  YYSYMBOL_BitwiseORExpressionNoIn = 139,  /* BitwiseORExpressionNoIn  */
  YYSYMBOL_BitwiseXORExpression = 140,     /* BitwiseXORExpression  */
  YYSYMBOL_BitwiseXORExpressionNoIn = 141, /* BitwiseXORExpressionNoIn  */
  YYSYMBOL_BitwiseANDExpression = 142,     /* BitwiseANDExpression  */
  YYSYMBOL_BitwiseANDExpressionNoIn = 143, /* BitwiseANDExpressionNoIn  */
  YYSYMBOL_EqualityExpression = 144,       /* EqualityExpression  */
  YYSYMBOL_EqualityExpressionNoIn = 145,   /* EqualityExpressionNoIn  */
  YYSYMBOL_RelationalExpression = 146,     /* RelationalExpression  */
  YYSYMBOL_RelationalExpressionNoIn = 147, /* RelationalExpressionNoIn  */
  YYSYMBOL_ShiftExpression = 148,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 149,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 150, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 151,          /* UnaryExpression  */
  YYSYMBOL_PostfixExpression = 152,        /* PostfixExpression  */
  YYSYMBOL_LeftHandSideExpression = 153,   /* LeftHandSideExpression  */
  YYSYMBOL_NewExpression = 154,            /* NewExpression  */
  YYSYMBOL_MemberExpression = 155,         /* MemberExpression  */
  YYSYMBOL_CallExpression = 156,           /* CallExpression  */
  YYSYMBOL_Arguments = 157,                /* Arguments  */
  YYSYMBOL_ArgumentList = 158,             /* ArgumentList  */
  YYSYMBOL_PrimaryExpression = 159,        /* PrimaryExpression  */
  YYSYMBOL_ArrayLiteral = 160,             /* ArrayLiteral  */
  YYSYMBOL_ElementList = 161,              /* ElementList  */
  YYSYMBOL_Elision = 162,                  /* Elision  */
  YYSYMBOL_Elision_opt = 163,              /* Elision_opt  */
  YYSYMBOL_ObjectLiteral = 164,            /* ObjectLiteral  */
  YYSYMBOL_PropertyNameAndValueList = 165, /* PropertyNameAndValueList  */
  YYSYMBOL_PropertyDefinition = 166,       /* PropertyDefinition  */
  YYSYMBOL_GetterSetterMethod = 167,       /* GetterSetterMethod  */
  YYSYMBOL_PropertyName = 168,             /* PropertyName  */
  YYSYMBOL_Identifier_opt = 169,           /* Identifier_opt  */
  YYSYMBOL_Identifier = 170,               /* Identifier  */
  YYSYMBOL_IdentifierName = 171,           /* IdentifierName  */
  YYSYMBOL_ReservedAsIdentifier = 172,     /* ReservedAsIdentifier  */
  YYSYMBOL_ES5Keyword = 173,               /* ES5Keyword  */
  YYSYMBOL_Literal = 174,                  /* Literal  */
  YYSYMBOL_BooleanLiteral = 175,           /* BooleanLiteral  */
  YYSYMBOL_semicolon_opt = 176,            /* semicolon_opt  */
  YYSYMBOL_left_bracket = 177,             /* left_bracket  */
  YYSYMBOL_right_bracket = 178,            /* right_bracket  */
  YYSYMBOL_semicolon = 179                 /* semicolon  */
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
#define YYFINAL  189
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  274
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  498

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
       2,     2,     2,    67,     2,     2,     2,    65,    60,     2,
      71,    72,    63,    61,    54,    62,    70,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    56,
       2,    55,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    58,    53,    66,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   254,   254,   258,   261,   262,   266,   270,   272,   274,
     279,   283,   284,   289,   290,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     312,   316,   317,   321,   322,   327,   328,   332,   333,   337,
     339,   352,   354,   367,   372,   373,   378,   380,   385,   390,
     395,   396,   400,   405,   406,   410,   415,   419,   424,   426,
     431,   433,   436,   438,   435,   442,   444,   441,   447,   449,
     452,   454,   451,   461,   466,   471,   476,   481,   488,   489,
     490,   494,   499,   501,   506,   507,   511,   512,   517,   522,
     527,   532,   533,   534,   539,   544,   548,   549,   552,   553,
     557,   558,   563,   564,   568,   570,   574,   575,   579,   580,
     582,   587,   589,   591,   596,   597,   602,   604,   609,   610,
     615,   617,   622,   623,   628,   630,   635,   636,   641,   643,
     648,   649,   654,   656,   661,   662,   667,   669,   674,   675,
     680,   681,   686,   687,   689,   691,   696,   697,   699,   704,
     705,   710,   712,   714,   719,   720,   722,   724,   729,   730,
     732,   733,   735,   736,   737,   738,   739,   740,   744,   746,
     748,   754,   755,   759,   760,   764,   765,   766,   768,   770,
     775,   777,   779,   781,   786,   787,   791,   792,   797,   799,
     800,   801,   802,   803,   804,   805,   806,   810,   811,   812,
     813,   818,   820,   825,   826,   830,   831,   835,   836,   838,
     850,   851,   856,   858,   860,   864,   869,   870,   871,   875,
     876,   879,   880,   884,   885,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   929,   930,   931,   935,   936,
     937,   938,   939,   941,   946,   947,   948,   951,   952,   955,
     956,   959,   960,   963,   964
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
  "\"end of file\"", "error", "\"invalid token\"", "kBREAK", "kCASE",
  "kCATCH", "kCONST", "kCONTINUE", "kDEFAULT", "kDELETE", "kDO", "kELSE",
  "kFUNCTION", "kIF", "kFINALLY", "kFOR", "kGET", "kIN", "kLET", "kSET",
  "kINSTANCEOF", "kNEW", "kNULL", "kRETURN", "kSWITCH", "kTHIS", "kTHROW",
  "kTRUE", "kFALSE", "kTRY", "kTYPEOF", "kVAR", "kVOID", "kWHILE", "kWITH",
  "tANDAND", "tOROR", "tINC", "tDEC", "tHTMLCOMMENT", "kDIVEQ", "kDCOL",
  "tIdentifier", "tAssignOper", "tEqOper", "tShiftOper", "tRelOper",
  "tNumericLiteral", "tBooleanLiteral", "tStringLiteral",
  "LOWER_THAN_ELSE", "':'", "'{'", "'}'", "','", "'='", "';'", "'?'",
  "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'",
  "'['", "']'", "'.'", "'('", "')'", "$accept", "Script", "ScriptBody",
  "HtmlComment", "FunctionStatementList", "FunctionExpression",
  "FunctionBody", "FormalParameterList", "FormalParameterList_opt",
  "Statement", "Declaration", "StatementListItem", "StatementList",
  "StatementList_opt", "Block", "LexicalDeclaration",
  "LexicalDeclarationNoIn", "VariableStatement", "VariableDeclarationList",
  "VariableDeclarationListNoIn", "VariableDeclaration",
  "VariableDeclarationNoIn", "Initialiser_opt", "Initialiser",
  "InitialiserNoIn_opt", "InitialiserNoIn", "EmptyStatement",
  "ExpressionStatement", "IfStatement", "IterationStatement", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "ContinueStatement", "BreakStatement",
  "ReturnStatement", "WithStatement", "LabelledStatement",
  "SwitchStatement", "CaseBlock", "CaseClausules_opt", "CaseClausules",
  "CaseClausule", "DefaultClausule", "ThrowStatement", "TryStatement",
  "Catch", "Finally", "Expression_opt", "Expression_err", "Expression",
  "ExpressionNoIn_opt", "ExpressionNoIn", "AssignOper",
  "AssignmentExpression", "AssignmentExpressionNoIn",
  "ConditionalExpression", "ConditionalExpressionNoIn",
  "LogicalORExpression", "LogicalORExpressionNoIn", "LogicalANDExpression",
  "LogicalANDExpressionNoIn", "BitwiseORExpression",
  "BitwiseORExpressionNoIn", "BitwiseXORExpression",
  "BitwiseXORExpressionNoIn", "BitwiseANDExpression",
  "BitwiseANDExpressionNoIn", "EqualityExpression",
  "EqualityExpressionNoIn", "RelationalExpression",
  "RelationalExpressionNoIn", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "PostfixExpression",
  "LeftHandSideExpression", "NewExpression", "MemberExpression",
  "CallExpression", "Arguments", "ArgumentList", "PrimaryExpression",
  "ArrayLiteral", "ElementList", "Elision", "Elision_opt", "ObjectLiteral",
  "PropertyNameAndValueList", "PropertyDefinition", "GetterSetterMethod",
  "PropertyName", "Identifier_opt", "Identifier", "IdentifierName",
  "ReservedAsIdentifier", "ES5Keyword", "Literal", "BooleanLiteral",
  "semicolon_opt", "left_bracket", "right_bracket", "semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-376)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-258)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     853,   315,   315,   315,  1224,   919,   266,    18,    18,   -27,
     258,    58,  1281,  -376,  1224,    18,  -376,  1224,  -376,  -376,
      63,  1224,   315,  1224,    18,    18,  1224,  1224,  -376,   100,
    -376,  -376,  -376,   655,  -376,  1224,  1224,  -376,  1224,  1224,
     206,  1224,   163,    41,   540,  -376,  -376,  -376,   853,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,    73,  -376,  -376,   125,   132,
     113,   118,   119,   150,   210,   180,    -6,   311,  -376,  -376,
     273,  -376,   278,   333,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,    56,  -376,  -376,    80,  -376,   209,    56,
    -376,  -376,  -376,  -376,  1350,  -376,  -376,    35,   177,   228,
    -376,  -376,    30,   315,   506,   982,   919,   919,    80,   919,
    -376,   278,    56,   211,  1224,    73,   721,   254,  -376,    80,
    -376,   506,  1224,  -376,  -376,   919,   288,  -376,  -376,   315,
     296,  -376,  1224,   919,  -376,   173,    31,  -376,    62,  1452,
    -376,   303,  1501,  -376,  1281,   218,  1103,    95,   245,  1224,
     248,   250,    63,  1224,   315,  1224,   167,   175,   100,   272,
     290,   587,   787,    50,  -376,   291,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,   249,   251,  1224,   160,  -376,
    -376,  -376,  -376,  -376,  1224,  -376,  -376,  1224,  1224,  1224,
    1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,
    1224,  1224,  1224,  -376,  -376,  -376,  -376,  1224,  1224,  1224,
    1597,  1042,  -376,  1224,  1597,  -376,  -376,   315,  -376,  1224,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  1550,  1550,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,    18,   315,   315,   270,    27,  -376,  -376,    27,   211,
     315,   315,   315,  -376,  -376,   289,  -376,  -376,   133,   318,
     292,   299,   309,   340,    72,   180,   199,  -376,  -376,  -376,
    -376,  -376,  -376,    22,  -376,  -376,    18,    63,   371,  -376,
    -376,    27,    22,  -376,    18,    18,  -376,  -376,  1401,  1224,
     336,  -376,  -376,  -376,  -376,  -376,  -376,   132,   342,   113,
     118,   119,   150,   210,   180,   180,   180,    -6,   311,   311,
    -376,  -376,  -376,  -376,  -376,   263,  -376,  -376,  -376,   194,
     271,  -376,  -376,  -376,   506,    18,    27,   315,  -376,  -376,
     343,   919,   127,  -376,   345,   127,   351,   389,  1224,   156,
    1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,
     506,  1224,  1224,   356,   315,  -376,  -376,   919,   919,  -376,
     315,  -376,  -376,  -376,  -376,   357,  1163,  1224,  -376,  1224,
    -376,  -376,    27,   315,   358,  -376,   853,   401,   315,  -376,
    1224,  -376,  -376,  -376,   156,   506,  -376,  -376,  -376,  1224,
    -376,   354,   318,   362,   292,   299,   309,   340,    72,   180,
     180,    27,  -376,  -376,   410,  -376,    27,  -376,  -376,    27,
    -376,  -376,  -376,  -376,    56,    27,   853,  -376,   363,  -376,
     919,  -376,  -376,  1224,    27,   156,  -376,  1224,   919,  1224,
      44,   410,  -376,    63,   365,  -376,   366,   367,  -376,  -376,
    -376,   919,  1224,   156,  -376,  -376,   169,   364,  -376,   410,
    -376,  -376,   853,   853,  -376,   156,  -376,    27,  1224,   853,
     853,   368,   369,   370,  1224,   919,    27,  -376,  -376,  -376,
    -376,  -376,    27,  -376,   919,   919,  -376,  -376
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      35,   219,     0,   219,     0,     0,     0,     0,     0,   190,
     192,   191,     0,   258,    96,     0,   188,     0,   264,   265,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   189,
     260,   266,   261,     0,    56,     0,     0,   262,     0,     0,
     205,     0,     0,     5,    18,    31,    32,    33,    36,     3,
      15,    30,    16,    17,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,   100,   108,   114,   118,
     122,   126,   130,   134,   138,   142,   149,   151,   154,   158,
     168,   171,   173,   172,   175,   194,   195,   193,   259,   255,
     256,   257,   221,     0,   220,   222,     0,    44,    50,     0,
     190,   192,   191,   189,     0,   176,   159,   168,   192,     0,
     270,   269,     0,    13,     0,   102,     0,     0,     0,     0,
     174,   173,     0,    97,     0,     0,     0,     0,   161,     0,
     160,     0,     0,   162,   163,     0,   219,   226,   227,   228,
     219,   230,   231,   232,   233,     0,     0,   235,     0,   190,
     239,   192,   191,   240,   241,   258,    96,     0,   188,   246,
     264,   265,   248,   249,   250,   251,     0,     0,   189,   260,
     261,    38,     0,     0,   210,     0,   216,   224,   254,   164,
     165,   166,   167,   203,   197,     0,   206,     0,     0,     1,
       4,     2,    34,   268,     0,   267,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   107,   106,     0,     0,     0,
       0,     0,   180,     0,     0,   181,    74,     0,    40,     0,
      48,    51,    73,   225,   228,   229,   231,   232,   237,   238,
     236,   255,   257,   241,   242,   243,   244,   245,   246,   247,
     234,   248,   249,   250,   251,   252,   253,   223,   218,   217,
     207,     0,     0,    13,    14,     0,    11,    99,     0,    98,
       0,   192,     0,    70,    62,   103,   104,   111,   116,   120,
     124,   128,   132,   136,   140,   146,   168,    78,    80,    39,
      79,   179,    75,     0,    90,    38,     0,     0,    91,    92,
      43,     0,     0,    77,     0,     0,    37,   208,     0,     0,
     205,   199,   204,   198,   201,   196,   101,   119,     0,   123,
     127,   131,   135,   139,   145,   144,   143,   150,   152,   153,
     155,   156,   157,   109,   110,     0,   178,   184,   186,     0,
       0,   183,    45,    52,     0,     0,     0,     0,   272,   271,
       0,     0,     0,    46,    53,     0,    65,    46,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    93,     0,     0,   213,
      13,   214,   209,   211,   212,   206,     0,     0,   177,     0,
     185,   182,     0,    13,     0,    12,    35,    59,     0,    42,
       0,    49,    54,    41,     0,     0,    71,   274,   273,    96,
     105,   168,   121,     0,   125,   129,   133,   137,   141,   148,
     147,     0,   112,   113,    84,    81,     0,    61,    76,     0,
     200,   202,   115,   187,     0,     0,    35,    10,     0,     6,
       0,    47,    55,    96,     0,     0,    63,     0,     0,     0,
       0,    85,    86,     0,     0,    60,     0,     0,     7,    58,
      66,     0,    96,     0,   117,    68,     0,     0,    82,    84,
      87,    94,    35,    35,     8,     0,    69,     0,    96,    35,
      35,     0,     0,     0,    96,     0,     0,    88,    89,    83,
     215,     9,     0,    72,     0,     0,    64,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -376,  -376,  -376,  -376,  -376,     0,  -251,  -376,  -256,     4,
    -376,   -32,    32,     2,   -14,  -376,  -376,  -376,    29,  -186,
     192,  -242,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,   -45,  -376,   -26,  -376,  -376,  -376,  -376,
     129,  -265,  -127,    28,  -376,  -376,   349,  -134,  -294,  -376,
    -376,  -376,  -376,   233,    70,   235,    69,   238,    71,   240,
      77,   241,    79,   244,    82,   -74,   243,    49,    23,  -376,
      -1,    -4,     1,  -376,   -16,  -376,  -376,  -376,  -376,   141,
     143,  -376,  -376,   146,   151,  -131,    -2,     9,  -145,  -376,
      21,  -376,  -376,   -82,    83,    34,  -375
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    42,    43,   191,   437,   105,   438,   264,   265,    45,
      46,    47,    48,   439,    50,    51,   273,    52,    96,   352,
      97,   353,   230,   231,   401,   402,    53,    54,    55,    56,
     359,   463,   404,   475,   358,   445,    57,    58,    59,    60,
      61,    62,   425,   450,   451,   452,   469,    63,    64,   298,
     299,   122,   268,    65,   274,   275,   372,    66,   276,    67,
     277,    68,   278,    69,   279,    70,   280,    71,   281,    72,
     282,    73,   283,    74,   284,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   222,   339,    84,    85,   185,   186,
     187,    86,   173,   174,   379,   175,    93,    98,   176,   177,
      95,    87,    88,   196,   113,   350,   409
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    99,    49,   107,   301,    44,   127,   346,   120,   109,
      94,   226,    94,   121,   228,   112,   192,   232,   304,   110,
     107,   305,   107,   348,   116,   107,   107,   106,   348,   443,
     357,   110,   110,    44,   107,   107,   289,   107,   107,   118,
     292,   285,   123,   294,   128,   125,   130,   300,    44,   133,
     134,   129,   467,   314,   178,   208,   209,   193,   179,   180,
     316,   181,   182,   110,   318,   172,   410,   225,   413,   188,
     462,   262,   213,   214,   193,   336,   194,   422,   423,   341,
     190,   193,  -238,   333,   334,   355,   356,   338,   478,   111,
     114,   115,   368,   406,   349,   343,   110,   468,   124,   349,
     484,   111,   111,   307,   308,   291,   442,   131,   132,   119,
     304,   305,   195,  -236,   286,   126,    44,    44,   369,    44,
     287,   288,   266,   290,   429,   178,    44,   194,   193,   195,
     324,   325,   326,   111,   227,    44,   195,   435,    99,   303,
     192,   107,   269,    44,   446,    94,  -244,   109,   127,    94,
     120,   135,   293,   464,   112,   121,   441,   407,   172,   269,
     302,   197,   107,   189,   107,   106,   111,   199,   110,   361,
     178,   200,    44,   178,   110,   384,   110,   201,   460,   202,
     118,   398,   198,   195,   123,   457,   128,   125,   130,    89,
     362,    90,    91,   129,   203,   263,   107,   477,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   408,   486,   194,    92,   370,   392,  -252,   492,
     479,   482,   483,   194,  -237,   207,  -253,   204,   117,   114,
     205,   115,   315,   330,   331,   332,   213,   214,   111,   215,
     124,   178,   216,   421,   111,   178,   111,   335,   389,   131,
     132,   340,   431,   432,   371,   433,   206,   328,   329,   296,
     183,   261,   178,   178,   229,   194,   390,   110,   297,  -242,
     399,   345,   266,   403,    89,   184,    90,    91,   444,   354,
     354,   354,    89,   375,    90,    91,   285,   285,   285,   285,
     285,   285,   285,   285,   419,   420,  -245,   285,   285,  -247,
      92,  -234,   351,   310,    89,   312,    90,    91,    92,   117,
     213,   214,    89,   215,    90,    91,   216,   194,   311,    89,
     313,    90,    91,  -218,   347,   194,   285,   373,   217,   178,
      92,    89,   388,    90,    91,   377,   378,   111,    92,  -225,
     391,  -217,   309,   360,   344,    92,   219,  -229,   220,   221,
     364,    44,   455,   363,  -256,   397,   395,    92,   365,   411,
     107,   411,   107,   107,   107,   107,   107,   107,   107,   366,
     411,   411,   269,   285,   210,   211,   212,    44,    44,   374,
     394,   427,   428,   426,   367,   297,   123,   380,   380,   266,
     183,   213,   214,   387,   215,   396,    44,   216,   269,   411,
     400,   223,   266,   224,   221,   398,   405,   354,   424,   371,
     436,   312,   440,   447,   449,   480,   458,   472,   473,   342,
     474,   489,   490,   491,   481,   470,   434,   376,   393,   218,
     317,   412,   414,   269,   319,   415,    44,   123,   320,   471,
      44,   321,   416,   322,   459,   417,   411,   323,    44,   418,
     327,   385,   465,   386,   383,   448,   381,     0,     0,     0,
     453,    44,     0,   454,     0,   476,     0,     0,     0,   456,
       0,   123,    44,    44,     0,     0,     0,   466,   461,    44,
      44,   487,   488,     0,     0,    44,     0,     0,     0,   493,
     123,     0,     0,     0,    44,    44,     0,     0,   496,   497,
       0,     0,     0,     0,     0,     0,   123,   267,     0,     0,
       0,   485,   123,     0,     0,     4,     0,     0,     6,     0,
     494,     0,   100,     0,   101,   102,   495,    12,    13,     0,
       0,    16,     0,    18,    19,     0,    21,     0,    23,     0,
       0,  -176,     0,    26,    27,     0,    28,     0,   103,     0,
       0,     0,     0,    30,    31,    32,     0,  -176,   104,     0,
    -176,     0,     0,     0,     0,     0,     0,    35,    36,     0,
      37,     0,    38,    39,    40,  -176,  -176,    41,     0,     0,
       0,     0,     0,  -176,  -176,  -176,  -176,     0,  -207,     0,
       0,     0,     0,     0,  -176,  -176,     0,  -176,  -176,  -176,
    -176,     0,     0,  -176,  -207,  -176,     0,  -207,     0,     0,
    -176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -207,  -207,     0,     0,     0,     0,     0,     0,
    -207,  -207,  -207,  -207,     0,     0,     0,     0,     0,     0,
       0,  -207,  -207,     0,  -207,  -207,  -207,  -207,     0,     0,
    -207,     0,  -207,     0,     0,     0,     0,  -207,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,    26,    27,     0,    28,     0,   168,     0,     0,
       0,     0,   169,    31,   170,     0,     0,    33,   171,     0,
       0,    34,     0,     0,     0,     0,    35,    36,     0,    37,
       0,    38,    39,    40,     1,     0,    41,     2,     3,     0,
       4,     5,     0,     6,     7,     0,     8,     9,     0,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,    26,    27,
       0,    28,     0,    29,     0,     0,     0,     0,    30,    31,
      32,     0,     0,    33,   295,     0,     0,    34,     0,     0,
       0,     0,    35,    36,     0,    37,     0,    38,    39,    40,
       1,     0,    41,     2,     3,     0,     4,     5,     0,     6,
       7,     0,     8,     9,     0,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,    26,    27,     0,    28,     0,    29,
       0,     0,     0,     0,    30,    31,    32,     0,     0,    33,
     306,     0,     0,    34,     0,     0,     0,     0,    35,    36,
       0,    37,     0,    38,    39,    40,     1,     0,    41,     2,
       3,     0,     4,     5,     0,     6,     7,     0,     8,     9,
       0,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
      26,    27,     0,    28,     0,    29,     0,     0,     0,     0,
      30,    31,    32,     0,     0,    33,     0,     0,     0,    34,
       0,     0,     0,     0,    35,    36,     0,    37,     0,    38,
      39,    40,     1,     0,    41,     0,     3,     0,     4,     5,
       0,     6,     7,     0,     8,     9,     0,   108,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,    26,    27,     0,    28,
       0,    29,     0,     0,     0,     0,    30,    31,    32,     0,
       0,    33,     0,     0,     0,    34,     0,     0,     0,     0,
      35,    36,     0,    37,     0,    38,    39,    40,   270,     0,
      41,     4,     0,     0,     6,     0,     0,     0,   100,     0,
     271,   102,     0,    12,    13,     0,     0,    16,     0,    18,
      19,     0,    21,   272,    23,     0,     0,     0,     0,    26,
      27,     0,    28,     0,   103,     0,     0,     0,     0,    30,
      31,    32,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,    37,     0,    38,    39,
      40,     4,     0,    41,     6,     0,     0,     0,   100,     0,
     101,   102,     0,    12,    13,     0,     0,    16,     0,    18,
      19,     0,    21,     0,    23,     0,     0,     0,     0,    26,
      27,     0,    28,     0,   103,     0,     0,     0,     0,    30,
      31,    32,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,    37,     0,    38,    39,
      40,     0,     4,    41,   337,     6,     0,     0,     0,   100,
       0,   101,   102,     0,    12,    13,     0,     0,    16,     0,
      18,    19,     0,    21,     0,    23,     0,     0,     0,     0,
      26,    27,     0,    28,     0,   103,     0,     0,     0,     0,
      30,    31,    32,     0,  -243,   104,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    36,     0,    37,     0,    38,
      39,    40,     4,     0,    41,     6,     0,     0,     0,   100,
       0,   101,   102,     0,    12,    13,     0,     0,    16,     0,
      18,    19,     0,    21,     0,    23,     0,     0,     0,     0,
      26,    27,     0,    28,     0,   103,     0,     0,     0,     0,
      30,    31,    32,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    36,     0,    37,     0,    38,
      39,    40,   430,     4,    41,     0,     6,     0,     0,     0,
     100,     0,   101,   102,     0,    12,    13,     0,     0,    16,
       0,    18,    19,     0,    21,     0,    23,     0,     0,     0,
       0,    26,    27,     0,    28,     0,   103,     0,     0,     0,
       0,    30,    31,    32,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,     0,    37,     0,
      38,    39,    40,     6,     0,    41,     0,   100,     0,   101,
     102,     0,    12,    13,     0,     0,    16,     0,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,   103,     0,     0,     0,     0,    30,    31,
      32,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    40,
       0,     0,    41,   233,   137,   138,   234,   235,   141,   236,
     237,   144,   238,   239,   147,   240,   241,   150,    90,   242,
     153,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,   258,     0,   259,
       0,     0,     0,   260,   233,   137,   138,   234,   235,   141,
     236,   237,   144,   238,   239,   147,   240,   241,   150,    90,
     242,   153,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,     0,     0,   258,     0,
     259,     0,     0,     0,   382,   233,   137,   138,   234,   235,
     141,   236,   237,   144,   238,   239,   147,   240,    89,     0,
      90,    91,     0,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,     0,     0,     0,
       0,     0,     0,     0,   257,     0,     0,     0,     0,   258,
       0,   259,     0,  -255,   233,   137,   138,   234,   235,   141,
     236,   237,   144,   238,   239,   147,   240,    89,     0,    90,
      91,     0,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,     0,     0,   258,     0,
     259,     0,  -257,   233,   137,   138,   234,   235,   141,   236,
     237,   144,   238,   239,   147,   240,    89,   150,    90,    91,
     153,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,   258,     0,   259,
     233,   137,   138,   234,   235,   141,   236,   237,   144,   238,
     239,   147,   240,    89,   150,    90,    91,   153,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,     0,     0,     0,     0,     0,     0,     0,   257
};

static const yytype_int16 yycheck[] =
{
       0,     3,     0,     4,   131,     5,    20,   263,    12,     5,
       1,    93,     3,    12,    96,     6,    48,    99,   149,     1,
      21,   152,    23,     1,    51,    26,    27,     4,     1,   404,
     272,     1,     1,    33,    35,    36,   118,    38,    39,    10,
     122,   115,    14,   125,    21,    17,    23,   129,    48,    26,
      27,    22,     8,   187,    33,    61,    62,     1,    35,    36,
     194,    38,    39,     1,   198,    33,   360,    83,   362,    41,
     445,    41,    37,    38,     1,   220,    54,   371,   372,   224,
      39,     1,    51,   217,   218,   271,   272,   221,   463,    71,
       7,     8,    20,   358,    72,   229,     1,    53,    15,    72,
     475,    71,    71,    53,    54,   121,   400,    24,    25,    51,
     241,   242,    56,    51,   115,    52,   116,   117,    46,   119,
     116,   117,   113,   119,   380,   104,   126,    54,     1,    56,
     204,   205,   206,    71,    54,   135,    56,   393,   140,   135,
     172,   142,   114,   143,   409,   136,    51,   143,   162,   140,
     154,    51,   124,   447,   145,   154,   398,     1,   126,   131,
     132,    36,   163,     0,   165,   142,    71,    35,     1,    36,
     149,    58,   172,   152,     1,   309,     1,    59,   443,    60,
     151,    54,    57,    56,   156,   436,   163,   159,   165,    16,
      57,    18,    19,   164,    44,   112,   197,   462,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    56,   478,    54,    42,    17,   344,    51,   484,
      51,   472,   473,    54,    51,    45,    51,    17,    51,   146,
      20,   148,    72,   210,   211,   212,    37,    38,    71,    40,
     157,   220,    43,   370,    71,   224,    71,   219,    54,   166,
     167,   223,   386,   387,    55,   389,    46,   208,   209,     5,
      54,    33,   241,   242,    55,    54,    72,     1,    14,    51,
     352,   262,   263,   355,    16,    69,    18,    19,   405,   270,
     271,   272,    16,   297,    18,    19,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,    51,   371,   372,    51,
      42,    51,   268,    54,    16,    54,    18,    19,    42,    51,
      37,    38,    16,    40,    18,    19,    43,    54,    69,    16,
      69,    18,    19,    51,    54,    54,   400,   293,    55,   308,
      42,    16,    69,    18,    19,   301,   302,    71,    42,    51,
      69,    51,    51,    54,   261,    42,    68,    51,    70,    71,
      58,   351,   434,    35,    51,   351,   347,    42,    59,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,    60,
     371,   372,   344,   447,    63,    64,    65,   377,   378,   296,
     346,   377,   378,   374,    44,    14,   358,   304,   305,   380,
      54,    37,    38,    51,    40,    52,   396,    43,   370,   400,
      55,    68,   393,    70,    71,    54,    17,   398,    52,    55,
      52,    54,    11,    51,     4,    51,    53,    52,    52,   227,
      53,    53,    53,    53,   469,   451,   392,   298,   345,    80,
     197,   361,   363,   405,   199,   364,   436,   409,   200,   453,
     440,   201,   365,   202,   440,   366,   447,   203,   448,   367,
     207,   310,   448,   310,   308,   421,   305,    -1,    -1,    -1,
     426,   461,    -1,   429,    -1,   461,    -1,    -1,    -1,   435,
      -1,   443,   472,   473,    -1,    -1,    -1,   449,   444,   479,
     480,   479,   480,    -1,    -1,   485,    -1,    -1,    -1,   485,
     462,    -1,    -1,    -1,   494,   495,    -1,    -1,   494,   495,
      -1,    -1,    -1,    -1,    -1,    -1,   478,     1,    -1,    -1,
      -1,   477,   484,    -1,    -1,     9,    -1,    -1,    12,    -1,
     486,    -1,    16,    -1,    18,    19,   492,    21,    22,    -1,
      -1,    25,    -1,    27,    28,    -1,    30,    -1,    32,    -1,
      -1,     1,    -1,    37,    38,    -1,    40,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    17,    52,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    -1,    66,    67,    68,    35,    36,    71,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    -1,    57,    58,    59,
      60,    -1,    -1,    63,    17,    65,    -1,    20,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    57,    58,    59,    60,    -1,    -1,
      63,    -1,    65,    -1,    -1,    -1,    -1,    70,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      -1,    66,    67,    68,     3,    -1,    71,     6,     7,    -1,
       9,    10,    -1,    12,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    61,    62,    -1,    64,    -1,    66,    67,    68,
       3,    -1,    71,     6,     7,    -1,     9,    10,    -1,    12,
      13,    -1,    15,    16,    -1,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    -1,    66,    67,    68,     3,    -1,    71,     6,
       7,    -1,     9,    10,    -1,    12,    13,    -1,    15,    16,
      -1,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,
      67,    68,     3,    -1,    71,    -1,     7,    -1,     9,    10,
      -1,    12,    13,    -1,    15,    16,    -1,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      61,    62,    -1,    64,    -1,    66,    67,    68,     6,    -1,
      71,     9,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
      18,    19,    -1,    21,    22,    -1,    -1,    25,    -1,    27,
      28,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,    67,
      68,     9,    -1,    71,    12,    -1,    -1,    -1,    16,    -1,
      18,    19,    -1,    21,    22,    -1,    -1,    25,    -1,    27,
      28,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,    67,
      68,    -1,     9,    71,    72,    12,    -1,    -1,    -1,    16,
      -1,    18,    19,    -1,    21,    22,    -1,    -1,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,
      67,    68,     9,    -1,    71,    12,    -1,    -1,    -1,    16,
      -1,    18,    19,    -1,    21,    22,    -1,    -1,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,
      67,    68,    69,     9,    71,    -1,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    -1,    21,    22,    -1,    -1,    25,
      -1,    27,    28,    -1,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,    -1,
      66,    67,    68,    12,    -1,    71,    -1,    16,    -1,    18,
      19,    -1,    21,    22,    -1,    -1,    25,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    -1,    71,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    -1,    -1,    53,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    -1,    -1,    53,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    51,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     9,    10,    12,    13,    15,    16,
      18,    19,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    37,    38,    40,    42,
      47,    48,    49,    52,    56,    61,    62,    64,    66,    67,
      68,    71,    74,    75,    78,    82,    83,    84,    85,    86,
      87,    88,    90,    99,   100,   101,   102,   109,   110,   111,
     112,   113,   114,   120,   121,   126,   130,   132,   134,   136,
     138,   140,   142,   144,   146,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   159,   160,   164,   174,   175,    16,
      18,    19,    42,   169,   170,   173,    91,    93,   170,   169,
      16,    18,    19,    42,    52,    78,   151,   153,    18,    82,
       1,    71,   170,   177,   177,   177,    51,    51,    91,    51,
     154,   155,   124,   126,   177,   126,    52,    87,   151,    91,
     151,   177,   177,   151,   151,    51,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    42,    47,
      49,    53,    85,   165,   166,   168,   171,   172,   173,   151,
     151,   151,   151,    54,    69,   161,   162,   163,   126,     0,
      39,    76,    84,     1,    54,    56,   176,    36,    57,    35,
      58,    59,    60,    44,    17,    20,    46,    45,    61,    62,
      63,    64,    65,    37,    38,    40,    43,    55,   129,    68,
      70,    71,   157,    68,    70,   157,   176,    54,   176,    55,
      95,    96,   176,     3,     6,     7,     9,    10,    12,    13,
      15,    16,    19,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    42,    47,    49,
      53,    33,    41,   177,    80,    81,   170,     1,   125,   126,
       6,    18,    31,    89,   127,   128,   131,   133,   135,   137,
     139,   141,   143,   145,   147,   148,   153,    82,    82,   176,
      82,   157,   176,   126,   176,    53,     5,    14,   122,   123,
     176,   125,   126,    82,   168,   168,    53,    53,    54,    51,
      54,    69,    54,    69,   130,    72,   130,   136,   130,   138,
     140,   142,   144,   146,   148,   148,   148,   149,   150,   150,
     151,   151,   151,   130,   130,   126,   171,    72,   130,   158,
     126,   171,    93,   130,   177,   170,    81,    54,     1,    72,
     178,   178,    92,    94,   170,    92,    92,    94,   107,   103,
      54,    36,    57,    35,    58,    59,    60,    44,    20,    46,
      17,    55,   129,   178,   177,    87,   123,   178,   178,   167,
     177,   167,    53,   166,   130,   162,   163,    51,    69,    54,
      72,    69,   125,   177,   178,   170,    52,    82,    54,   176,
      55,    97,    98,   176,   105,    17,   124,     1,    56,   179,
     131,   153,   137,   131,   139,   141,   143,   145,   147,   148,
     148,   125,   131,   131,    52,   115,   170,    82,    82,    81,
      69,   130,   130,   130,   178,    81,    52,    77,    79,    86,
      11,    94,   131,   179,   125,   108,   124,    51,   178,     4,
     116,   117,   118,   178,   178,   176,   178,    79,    53,    82,
     124,   178,   179,   104,   131,    82,   126,     8,    53,   119,
     118,    87,    52,    52,    53,   106,    82,   124,   179,    51,
      51,   116,    79,    79,   179,   178,   124,    86,    86,    53,
      53,    53,   124,    82,   178,   178,    82,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    76,    76,    77,    78,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    91,    91,    92,    92,    93,    94,
      95,    95,    96,    97,    97,    98,    99,   100,   101,   101,
     102,   102,   103,   104,   102,   105,   106,   102,   102,   102,
     107,   108,   102,   109,   110,   111,   112,   113,   113,   113,
     113,   114,   115,   115,   116,   116,   117,   117,   118,   119,
     120,   121,   121,   121,   122,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   146,   146,   147,   147,   147,   148,
     148,   149,   149,   149,   150,   150,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   155,   155,   155,
     156,   156,   156,   156,   157,   157,   158,   158,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   160,   160,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     165,   165,   166,   166,   166,   167,   168,   168,   168,   169,
     169,   170,   170,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   173,   173,   173,   174,   174,
     174,   174,   174,   174,   175,   175,   175,   176,   176,   177,
     177,   178,   178,   179,   179
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     1,     7,     8,    10,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     1,     3,     2,     3,
       3,     3,     3,     3,     1,     3,     1,     3,     2,     2,
       0,     1,     2,     0,     1,     2,     1,     2,     7,     5,
       7,     5,     0,     0,    11,     0,     0,    12,     7,     8,
       0,     0,    10,     3,     3,     3,     5,     3,     3,     3,
       3,     5,     3,     5,     0,     1,     1,     2,     4,     3,
       3,     3,     3,     4,     5,     2,     0,     1,     1,     1,
       1,     3,     0,     1,     1,     3,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     5,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     2,     1,     1,     4,     3,     3,
       2,     2,     4,     3,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       5,     2,     4,     1,     2,     0,     1,     2,     3,     4,
       1,     3,     3,     3,     3,     6,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
  case 2: /* Script: ScriptBody HtmlComment  */
#line 254 "dlls/jscript/parser.y"
                                { ctx->source = (yyvsp[-1].statement_list) ? (yyvsp[-1].statement_list)->head : NULL; }
#line 2223 "dlls/jscript/parser.tab.c"
    break;

  case 3: /* ScriptBody: StatementList_opt  */
#line 258 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = (yyvsp[0].statement_list); }
#line 2229 "dlls/jscript/parser.tab.c"
    break;

  case 6: /* FunctionStatementList: StatementList_opt  */
#line 266 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = (yyvsp[0].statement_list); }
#line 2235 "dlls/jscript/parser.tab.c"
    break;

  case 7: /* FunctionExpression: kFUNCTION left_bracket FormalParameterList_opt right_bracket '{' FunctionBody '}'  */
#line 271 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_function_expression(ctx, NULL, (yyvsp[-4].parameter_list), (yyvsp[-1].statement_list), NULL, ctx->begin + (yylsp[-6]), (yylsp[0]) - (yylsp[-6]) + 1); }
#line 2241 "dlls/jscript/parser.tab.c"
    break;

  case 8: /* FunctionExpression: kFUNCTION Identifier left_bracket FormalParameterList_opt right_bracket '{' FunctionBody '}'  */
#line 273 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_function_expression(ctx, (yyvsp[-6].identifier), (yyvsp[-4].parameter_list), (yyvsp[-1].statement_list), NULL, ctx->begin + (yylsp[-7]), (yylsp[0]) - (yylsp[-7]) + 1); }
#line 2247 "dlls/jscript/parser.tab.c"
    break;

  case 9: /* FunctionExpression: kFUNCTION Identifier kDCOL Identifier left_bracket FormalParameterList_opt right_bracket '{' FunctionBody '}'  */
#line 275 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_function_expression(ctx, (yyvsp[-6].identifier), (yyvsp[-4].parameter_list), (yyvsp[-1].statement_list), (yyvsp[-8].identifier), ctx->begin + (yylsp[-9]), (yylsp[0]) - (yylsp[-9]) + 1); }
#line 2253 "dlls/jscript/parser.tab.c"
    break;

  case 10: /* FunctionBody: FunctionStatementList  */
#line 279 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = (yyvsp[0].statement_list); }
#line 2259 "dlls/jscript/parser.tab.c"
    break;

  case 11: /* FormalParameterList: Identifier  */
#line 283 "dlls/jscript/parser.y"
                                { (yyval.parameter_list) = new_parameter_list(ctx, (yyvsp[0].identifier)); }
#line 2265 "dlls/jscript/parser.tab.c"
    break;

  case 12: /* FormalParameterList: FormalParameterList ',' Identifier  */
#line 285 "dlls/jscript/parser.y"
                                { (yyval.parameter_list) = parameter_list_add(ctx, (yyvsp[-2].parameter_list), (yyvsp[0].identifier)); }
#line 2271 "dlls/jscript/parser.tab.c"
    break;

  case 13: /* FormalParameterList_opt: %empty  */
#line 289 "dlls/jscript/parser.y"
                                { (yyval.parameter_list) = NULL; }
#line 2277 "dlls/jscript/parser.tab.c"
    break;

  case 14: /* FormalParameterList_opt: FormalParameterList  */
#line 290 "dlls/jscript/parser.y"
                                { (yyval.parameter_list) = (yyvsp[0].parameter_list); }
#line 2283 "dlls/jscript/parser.tab.c"
    break;

  case 15: /* Statement: Block  */
#line 294 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2289 "dlls/jscript/parser.tab.c"
    break;

  case 16: /* Statement: VariableStatement  */
#line 295 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2295 "dlls/jscript/parser.tab.c"
    break;

  case 17: /* Statement: EmptyStatement  */
#line 296 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2301 "dlls/jscript/parser.tab.c"
    break;

  case 18: /* Statement: FunctionExpression  */
#line 297 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_expression_statement(ctx, (yyloc), (yyvsp[0].expr)); }
#line 2307 "dlls/jscript/parser.tab.c"
    break;

  case 19: /* Statement: ExpressionStatement  */
#line 298 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2313 "dlls/jscript/parser.tab.c"
    break;

  case 20: /* Statement: IfStatement  */
#line 299 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2319 "dlls/jscript/parser.tab.c"
    break;

  case 21: /* Statement: IterationStatement  */
#line 300 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2325 "dlls/jscript/parser.tab.c"
    break;

  case 22: /* Statement: ContinueStatement  */
#line 301 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2331 "dlls/jscript/parser.tab.c"
    break;

  case 23: /* Statement: BreakStatement  */
#line 302 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2337 "dlls/jscript/parser.tab.c"
    break;

  case 24: /* Statement: ReturnStatement  */
#line 303 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2343 "dlls/jscript/parser.tab.c"
    break;

  case 25: /* Statement: WithStatement  */
#line 304 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2349 "dlls/jscript/parser.tab.c"
    break;

  case 26: /* Statement: LabelledStatement  */
#line 305 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2355 "dlls/jscript/parser.tab.c"
    break;

  case 27: /* Statement: SwitchStatement  */
#line 306 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2361 "dlls/jscript/parser.tab.c"
    break;

  case 28: /* Statement: ThrowStatement  */
#line 307 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2367 "dlls/jscript/parser.tab.c"
    break;

  case 29: /* Statement: TryStatement  */
#line 308 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2373 "dlls/jscript/parser.tab.c"
    break;

  case 30: /* Declaration: LexicalDeclaration  */
#line 312 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2379 "dlls/jscript/parser.tab.c"
    break;

  case 31: /* StatementListItem: Statement  */
#line 316 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2385 "dlls/jscript/parser.tab.c"
    break;

  case 32: /* StatementListItem: Declaration  */
#line 317 "dlls/jscript/parser.y"
                                { (yyval.statement) = (yyvsp[0].statement); }
#line 2391 "dlls/jscript/parser.tab.c"
    break;

  case 33: /* StatementList: StatementListItem  */
#line 321 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = new_statement_list(ctx, (yyvsp[0].statement)); }
#line 2397 "dlls/jscript/parser.tab.c"
    break;

  case 34: /* StatementList: StatementList StatementListItem  */
#line 323 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = statement_list_add((yyvsp[-1].statement_list), (yyvsp[0].statement)); }
#line 2403 "dlls/jscript/parser.tab.c"
    break;

  case 35: /* StatementList_opt: %empty  */
#line 327 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = NULL; }
#line 2409 "dlls/jscript/parser.tab.c"
    break;

  case 36: /* StatementList_opt: StatementList  */
#line 328 "dlls/jscript/parser.y"
                                { (yyval.statement_list) = (yyvsp[0].statement_list); }
#line 2415 "dlls/jscript/parser.tab.c"
    break;

  case 37: /* Block: '{' StatementList '}'  */
#line 332 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_block_statement(ctx, (yylsp[-1]), (yyvsp[-1].statement_list)); }
#line 2421 "dlls/jscript/parser.tab.c"
    break;

  case 38: /* Block: '{' '}'  */
#line 333 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_block_statement(ctx, (yyloc), NULL); }
#line 2427 "dlls/jscript/parser.tab.c"
    break;

  case 39: /* LexicalDeclaration: kLET VariableDeclarationList semicolon_opt  */
#line 338 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_var_statement(ctx, TRUE, FALSE, (yyloc), (yyvsp[-1].variable_list)); }
#line 2433 "dlls/jscript/parser.tab.c"
    break;

  case 40: /* LexicalDeclaration: kCONST VariableDeclarationList semicolon_opt  */
#line 340 "dlls/jscript/parser.y"
                                {
                                    if(ctx->script->version < SCRIPTLANGUAGEVERSION_ES5) {
                                        WARN("const var declaration %s in legacy mode.\n",
                                                debugstr_w((yyvsp[-2].identifier)));
                                        set_error(ctx, (yyloc), JS_E_SYNTAX);
                                        YYABORT;
                                    }
                                    (yyval.statement) = new_var_statement(ctx, TRUE, TRUE, (yyloc), (yyvsp[-1].variable_list));
                                }
#line 2447 "dlls/jscript/parser.tab.c"
    break;

  case 41: /* LexicalDeclarationNoIn: kLET VariableDeclarationListNoIn semicolon_opt  */
#line 353 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_var_statement(ctx, TRUE, FALSE, (yyloc), (yyvsp[-1].variable_list)); }
#line 2453 "dlls/jscript/parser.tab.c"
    break;

  case 42: /* LexicalDeclarationNoIn: kCONST VariableDeclarationListNoIn semicolon_opt  */
#line 355 "dlls/jscript/parser.y"
                                {
                                    if(ctx->script->version < SCRIPTLANGUAGEVERSION_ES5) {
                                        WARN("const var declaration %s in legacy mode.\n",
                                                debugstr_w((yyvsp[-2].identifier)));
                                        set_error(ctx, (yyloc), JS_E_SYNTAX);
                                        YYABORT;
                                    }
                                    (yyval.statement) = new_var_statement(ctx, TRUE, TRUE, (yyloc), (yyvsp[-1].variable_list));
                                }
#line 2467 "dlls/jscript/parser.tab.c"
    break;

  case 43: /* VariableStatement: kVAR VariableDeclarationList semicolon_opt  */
#line 368 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_var_statement(ctx, FALSE, FALSE, (yyloc), (yyvsp[-1].variable_list)); }
#line 2473 "dlls/jscript/parser.tab.c"
    break;

  case 44: /* VariableDeclarationList: VariableDeclaration  */
#line 372 "dlls/jscript/parser.y"
                                { (yyval.variable_list) = new_variable_list(ctx, (yyvsp[0].variable_declaration)); }
#line 2479 "dlls/jscript/parser.tab.c"
    break;

  case 45: /* VariableDeclarationList: VariableDeclarationList ',' VariableDeclaration  */
#line 374 "dlls/jscript/parser.y"
                                { (yyval.variable_list) = variable_list_add(ctx, (yyvsp[-2].variable_list), (yyvsp[0].variable_declaration)); }
#line 2485 "dlls/jscript/parser.tab.c"
    break;

  case 46: /* VariableDeclarationListNoIn: VariableDeclarationNoIn  */
#line 379 "dlls/jscript/parser.y"
                                { (yyval.variable_list) = new_variable_list(ctx, (yyvsp[0].variable_declaration)); }
#line 2491 "dlls/jscript/parser.tab.c"
    break;

  case 47: /* VariableDeclarationListNoIn: VariableDeclarationListNoIn ',' VariableDeclarationNoIn  */
#line 381 "dlls/jscript/parser.y"
                                { (yyval.variable_list) = variable_list_add(ctx, (yyvsp[-2].variable_list), (yyvsp[0].variable_declaration)); }
#line 2497 "dlls/jscript/parser.tab.c"
    break;

  case 48: /* VariableDeclaration: Identifier Initialiser_opt  */
#line 386 "dlls/jscript/parser.y"
                                { (yyval.variable_declaration) = new_variable_declaration(ctx, (yyvsp[-1].identifier), (yyvsp[0].expr)); }
#line 2503 "dlls/jscript/parser.tab.c"
    break;

  case 49: /* VariableDeclarationNoIn: Identifier InitialiserNoIn_opt  */
#line 391 "dlls/jscript/parser.y"
                                { (yyval.variable_declaration) = new_variable_declaration(ctx, (yyvsp[-1].identifier), (yyvsp[0].expr)); }
#line 2509 "dlls/jscript/parser.tab.c"
    break;

  case 50: /* Initialiser_opt: %empty  */
#line 395 "dlls/jscript/parser.y"
                                { (yyval.expr) = NULL; }
#line 2515 "dlls/jscript/parser.tab.c"
    break;

  case 51: /* Initialiser_opt: Initialiser  */
#line 396 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2521 "dlls/jscript/parser.tab.c"
    break;

  case 52: /* Initialiser: '=' AssignmentExpression  */
#line 401 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2527 "dlls/jscript/parser.tab.c"
    break;

  case 53: /* InitialiserNoIn_opt: %empty  */
#line 405 "dlls/jscript/parser.y"
                                { (yyval.expr) = NULL; }
#line 2533 "dlls/jscript/parser.tab.c"
    break;

  case 54: /* InitialiserNoIn_opt: InitialiserNoIn  */
#line 406 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2539 "dlls/jscript/parser.tab.c"
    break;

  case 55: /* InitialiserNoIn: '=' AssignmentExpressionNoIn  */
#line 411 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2545 "dlls/jscript/parser.tab.c"
    break;

  case 56: /* EmptyStatement: ';'  */
#line 415 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_statement(ctx, STAT_EMPTY, 0, (yyloc)); }
#line 2551 "dlls/jscript/parser.tab.c"
    break;

  case 57: /* ExpressionStatement: Expression semicolon_opt  */
#line 420 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_expression_statement(ctx, (yyloc),  (yyvsp[-1].expr)); }
#line 2557 "dlls/jscript/parser.tab.c"
    break;

  case 58: /* IfStatement: kIF left_bracket Expression_err right_bracket Statement kELSE Statement  */
#line 425 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-4].expr), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2563 "dlls/jscript/parser.tab.c"
    break;

  case 59: /* IfStatement: kIF left_bracket Expression_err right_bracket Statement  */
#line 427 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-2].expr), (yyvsp[0].statement), NULL); }
#line 2569 "dlls/jscript/parser.tab.c"
    break;

  case 60: /* IterationStatement: kDO Statement kWHILE left_bracket Expression_err right_bracket semicolon_opt  */
#line 432 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_while_statement(ctx, (yylsp[-4]), TRUE, (yyvsp[-2].expr), (yyvsp[-5].statement)); }
#line 2575 "dlls/jscript/parser.tab.c"
    break;

  case 61: /* IterationStatement: kWHILE left_bracket Expression_err right_bracket Statement  */
#line 434 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_while_statement(ctx, (yyloc), FALSE, (yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 2581 "dlls/jscript/parser.tab.c"
    break;

  case 62: /* $@1: %empty  */
#line 436 "dlls/jscript/parser.y"
                                { if(!explicit_error(ctx, (yyvsp[0].expr), ';')) YYABORT; }
#line 2587 "dlls/jscript/parser.tab.c"
    break;

  case 63: /* $@2: %empty  */
#line 438 "dlls/jscript/parser.y"
                                { if(!explicit_error(ctx, (yyvsp[0].expr), ';')) YYABORT; }
#line 2593 "dlls/jscript/parser.tab.c"
    break;

  case 64: /* IterationStatement: kFOR left_bracket ExpressionNoIn_opt $@1 semicolon Expression_opt $@2 semicolon Expression_opt right_bracket Statement  */
#line 440 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_for_statement(ctx, (yylsp[-8]), NULL, (yyvsp[-8].expr), (yyvsp[-5].expr), (yylsp[-5]), (yyvsp[-2].expr), (yylsp[-2]), (yyvsp[0].statement)); }
#line 2599 "dlls/jscript/parser.tab.c"
    break;

  case 65: /* $@3: %empty  */
#line 442 "dlls/jscript/parser.y"
                                { if(!explicit_error(ctx, (yyvsp[0].variable_list), ';')) YYABORT; }
#line 2605 "dlls/jscript/parser.tab.c"
    break;

  case 66: /* $@4: %empty  */
#line 444 "dlls/jscript/parser.y"
                                { if(!explicit_error(ctx, (yyvsp[0].expr), ';')) YYABORT; }
#line 2611 "dlls/jscript/parser.tab.c"
    break;

  case 67: /* IterationStatement: kFOR left_bracket kVAR VariableDeclarationListNoIn $@3 semicolon Expression_opt $@4 semicolon Expression_opt right_bracket Statement  */
#line 446 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_for_statement(ctx, (yylsp[-9]), (yyvsp[-8].variable_list) ? (yyvsp[-8].variable_list)->head : NULL, NULL, (yyvsp[-5].expr), (yylsp[-5]), (yyvsp[-2].expr), (yylsp[-2]), (yyvsp[0].statement)); }
#line 2617 "dlls/jscript/parser.tab.c"
    break;

  case 68: /* IterationStatement: kFOR left_bracket LeftHandSideExpression kIN Expression_err right_bracket Statement  */
#line 448 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_forin_statement(ctx, (yyloc), NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 2623 "dlls/jscript/parser.tab.c"
    break;

  case 69: /* IterationStatement: kFOR left_bracket kVAR VariableDeclarationNoIn kIN Expression_err right_bracket Statement  */
#line 450 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_forin_statement(ctx, (yyloc),  (yyvsp[-4].variable_declaration), NULL, (yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 2629 "dlls/jscript/parser.tab.c"
    break;

  case 70: /* $@5: %empty  */
#line 452 "dlls/jscript/parser.y"
                                { if(!explicit_error(ctx, (yyvsp[0].statement), ';')) YYABORT; }
#line 2635 "dlls/jscript/parser.tab.c"
    break;

  case 71: /* $@6: %empty  */
#line 454 "dlls/jscript/parser.y"
                                { if(!explicit_error(ctx, (yyvsp[0].expr), ';')) YYABORT; }
#line 2641 "dlls/jscript/parser.tab.c"
    break;

  case 72: /* IterationStatement: kFOR left_bracket LexicalDeclarationNoIn $@5 Expression_opt $@6 semicolon Expression_opt right_bracket Statement  */
#line 456 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_for_statement(ctx, (yylsp[-7]), ((var_statement_t *)(yyvsp[-7].statement))->variable_list,
                                  NULL, (yyvsp[-5].expr), (yylsp[-5]), (yyvsp[-2].expr), (yylsp[-2]), (yyvsp[0].statement)); }
#line 2648 "dlls/jscript/parser.tab.c"
    break;

  case 73: /* ContinueStatement: kCONTINUE Identifier_opt semicolon_opt  */
#line 462 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_continue_statement(ctx, (yyloc), (yyvsp[-1].identifier)); }
#line 2654 "dlls/jscript/parser.tab.c"
    break;

  case 74: /* BreakStatement: kBREAK Identifier_opt semicolon_opt  */
#line 467 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_break_statement(ctx, (yyloc), (yyvsp[-1].identifier)); }
#line 2660 "dlls/jscript/parser.tab.c"
    break;

  case 75: /* ReturnStatement: kRETURN Expression_opt semicolon_opt  */
#line 472 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_return_statement(ctx, (yyloc), (yyvsp[-1].expr)); }
#line 2666 "dlls/jscript/parser.tab.c"
    break;

  case 76: /* WithStatement: kWITH left_bracket Expression right_bracket Statement  */
#line 477 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_with_statement(ctx, (yyloc), (yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 2672 "dlls/jscript/parser.tab.c"
    break;

  case 77: /* LabelledStatement: tIdentifier ':' Statement  */
#line 482 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_labelled_statement(ctx, (yyloc), (yyvsp[-2].identifier), (yyvsp[0].statement)); }
#line 2678 "dlls/jscript/parser.tab.c"
    break;

  case 78: /* LabelledStatement: kGET ':' Statement  */
#line 488 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_labelled_statement(ctx, (yyloc), (yyvsp[-2].identifier), (yyvsp[0].statement)); }
#line 2684 "dlls/jscript/parser.tab.c"
    break;

  case 79: /* LabelledStatement: kSET ':' Statement  */
#line 489 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_labelled_statement(ctx, (yyloc), (yyvsp[-2].identifier), (yyvsp[0].statement)); }
#line 2690 "dlls/jscript/parser.tab.c"
    break;

  case 80: /* LabelledStatement: kLET ':' Statement  */
#line 490 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_labelled_statement(ctx, (yyloc), (yyvsp[-2].identifier), (yyvsp[0].statement)); }
#line 2696 "dlls/jscript/parser.tab.c"
    break;

  case 81: /* SwitchStatement: kSWITCH left_bracket Expression right_bracket CaseBlock  */
#line 495 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_switch_statement(ctx, (yyloc), (yyvsp[-2].expr), (yyvsp[0].case_clausule)); }
#line 2702 "dlls/jscript/parser.tab.c"
    break;

  case 82: /* CaseBlock: '{' CaseClausules_opt '}'  */
#line 500 "dlls/jscript/parser.y"
                                 { (yyval.case_clausule) = new_case_block(ctx, (yyvsp[-1].case_list), NULL, NULL); }
#line 2708 "dlls/jscript/parser.tab.c"
    break;

  case 83: /* CaseBlock: '{' CaseClausules_opt DefaultClausule CaseClausules_opt '}'  */
#line 502 "dlls/jscript/parser.y"
                                 { (yyval.case_clausule) = new_case_block(ctx, (yyvsp[-3].case_list), (yyvsp[-2].case_clausule), (yyvsp[-1].case_list)); }
#line 2714 "dlls/jscript/parser.tab.c"
    break;

  case 84: /* CaseClausules_opt: %empty  */
#line 506 "dlls/jscript/parser.y"
                                 { (yyval.case_list) = NULL; }
#line 2720 "dlls/jscript/parser.tab.c"
    break;

  case 85: /* CaseClausules_opt: CaseClausules  */
#line 507 "dlls/jscript/parser.y"
                                 { (yyval.case_list) = (yyvsp[0].case_list); }
#line 2726 "dlls/jscript/parser.tab.c"
    break;

  case 86: /* CaseClausules: CaseClausule  */
#line 511 "dlls/jscript/parser.y"
                                 { (yyval.case_list) = new_case_list(ctx, (yyvsp[0].case_clausule)); }
#line 2732 "dlls/jscript/parser.tab.c"
    break;

  case 87: /* CaseClausules: CaseClausules CaseClausule  */
#line 513 "dlls/jscript/parser.y"
                                 { (yyval.case_list) = case_list_add(ctx, (yyvsp[-1].case_list), (yyvsp[0].case_clausule)); }
#line 2738 "dlls/jscript/parser.tab.c"
    break;

  case 88: /* CaseClausule: kCASE Expression ':' StatementList_opt  */
#line 518 "dlls/jscript/parser.y"
                                 { (yyval.case_clausule) = new_case_clausule(ctx, (yyloc), (yyvsp[-2].expr), (yyvsp[0].statement_list)); }
#line 2744 "dlls/jscript/parser.tab.c"
    break;

  case 89: /* DefaultClausule: kDEFAULT ':' StatementList_opt  */
#line 523 "dlls/jscript/parser.y"
                                 { (yyval.case_clausule) = new_case_clausule(ctx, (yyloc), NULL, (yyvsp[0].statement_list)); }
#line 2750 "dlls/jscript/parser.tab.c"
    break;

  case 90: /* ThrowStatement: kTHROW Expression semicolon_opt  */
#line 528 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_throw_statement(ctx, (yyloc), (yyvsp[-1].expr)); }
#line 2756 "dlls/jscript/parser.tab.c"
    break;

  case 91: /* TryStatement: kTRY Block Catch  */
#line 532 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_try_statement(ctx, (yyvsp[-1].statement), (yyvsp[0].catch_block), NULL, 0); }
#line 2762 "dlls/jscript/parser.tab.c"
    break;

  case 92: /* TryStatement: kTRY Block Finally  */
#line 533 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_try_statement(ctx, (yyvsp[-1].statement), NULL, (yyvsp[0].statement), (yylsp[0])); }
#line 2768 "dlls/jscript/parser.tab.c"
    break;

  case 93: /* TryStatement: kTRY Block Catch Finally  */
#line 535 "dlls/jscript/parser.y"
                                { (yyval.statement) = new_try_statement(ctx, (yyvsp[-2].statement), (yyvsp[-1].catch_block), (yyvsp[0].statement), (yylsp[0])); }
#line 2774 "dlls/jscript/parser.tab.c"
    break;

  case 94: /* Catch: kCATCH left_bracket Identifier right_bracket Block  */
#line 540 "dlls/jscript/parser.y"
                                { (yyval.catch_block) = new_catch_block(ctx, (yyvsp[-2].identifier), (yyvsp[0].statement)); }
#line 2780 "dlls/jscript/parser.tab.c"
    break;

  case 95: /* Finally: kFINALLY Block  */
#line 544 "dlls/jscript/parser.y"
                                { (yyloc) = (yylsp[0]); (yyval.statement) = (yyvsp[0].statement); }
#line 2786 "dlls/jscript/parser.tab.c"
    break;

  case 96: /* Expression_opt: %empty  */
#line 548 "dlls/jscript/parser.y"
                                { (yyval.expr) = NULL; }
#line 2792 "dlls/jscript/parser.tab.c"
    break;

  case 97: /* Expression_opt: Expression  */
#line 549 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2798 "dlls/jscript/parser.tab.c"
    break;

  case 98: /* Expression_err: Expression  */
#line 552 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2804 "dlls/jscript/parser.tab.c"
    break;

  case 99: /* Expression_err: error  */
#line 553 "dlls/jscript/parser.y"
                                { set_error(ctx, (yyloc), JS_E_SYNTAX); YYABORT; }
#line 2810 "dlls/jscript/parser.tab.c"
    break;

  case 100: /* Expression: AssignmentExpression  */
#line 557 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2816 "dlls/jscript/parser.tab.c"
    break;

  case 101: /* Expression: Expression ',' AssignmentExpression  */
#line 559 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_COMMA, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2822 "dlls/jscript/parser.tab.c"
    break;

  case 102: /* ExpressionNoIn_opt: %empty  */
#line 563 "dlls/jscript/parser.y"
                                { (yyval.expr) = NULL; }
#line 2828 "dlls/jscript/parser.tab.c"
    break;

  case 103: /* ExpressionNoIn_opt: ExpressionNoIn  */
#line 564 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2834 "dlls/jscript/parser.tab.c"
    break;

  case 104: /* ExpressionNoIn: AssignmentExpressionNoIn  */
#line 569 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2840 "dlls/jscript/parser.tab.c"
    break;

  case 105: /* ExpressionNoIn: ExpressionNoIn ',' AssignmentExpressionNoIn  */
#line 571 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_COMMA, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2846 "dlls/jscript/parser.tab.c"
    break;

  case 106: /* AssignOper: tAssignOper  */
#line 574 "dlls/jscript/parser.y"
                                { (yyval.ival) = (yyvsp[0].ival); }
#line 2852 "dlls/jscript/parser.tab.c"
    break;

  case 107: /* AssignOper: kDIVEQ  */
#line 575 "dlls/jscript/parser.y"
                                { (yyval.ival) = EXPR_ASSIGNDIV; }
#line 2858 "dlls/jscript/parser.tab.c"
    break;

  case 108: /* AssignmentExpression: ConditionalExpression  */
#line 579 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2864 "dlls/jscript/parser.tab.c"
    break;

  case 109: /* AssignmentExpression: LeftHandSideExpression '=' AssignmentExpression  */
#line 581 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2870 "dlls/jscript/parser.tab.c"
    break;

  case 110: /* AssignmentExpression: LeftHandSideExpression AssignOper AssignmentExpression  */
#line 583 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2876 "dlls/jscript/parser.tab.c"
    break;

  case 111: /* AssignmentExpressionNoIn: ConditionalExpressionNoIn  */
#line 588 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2882 "dlls/jscript/parser.tab.c"
    break;

  case 112: /* AssignmentExpressionNoIn: LeftHandSideExpression '=' AssignmentExpressionNoIn  */
#line 590 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2888 "dlls/jscript/parser.tab.c"
    break;

  case 113: /* AssignmentExpressionNoIn: LeftHandSideExpression AssignOper AssignmentExpressionNoIn  */
#line 592 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2894 "dlls/jscript/parser.tab.c"
    break;

  case 114: /* ConditionalExpression: LogicalORExpression  */
#line 596 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2900 "dlls/jscript/parser.tab.c"
    break;

  case 115: /* ConditionalExpression: LogicalORExpression '?' AssignmentExpression ':' AssignmentExpression  */
#line 598 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_conditional_expression(ctx, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2906 "dlls/jscript/parser.tab.c"
    break;

  case 116: /* ConditionalExpressionNoIn: LogicalORExpressionNoIn  */
#line 603 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2912 "dlls/jscript/parser.tab.c"
    break;

  case 117: /* ConditionalExpressionNoIn: LogicalORExpressionNoIn '?' AssignmentExpressionNoIn ':' AssignmentExpressionNoIn  */
#line 605 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_conditional_expression(ctx, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2918 "dlls/jscript/parser.tab.c"
    break;

  case 118: /* LogicalORExpression: LogicalANDExpression  */
#line 609 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2924 "dlls/jscript/parser.tab.c"
    break;

  case 119: /* LogicalORExpression: LogicalORExpression tOROR LogicalANDExpression  */
#line 611 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2930 "dlls/jscript/parser.tab.c"
    break;

  case 120: /* LogicalORExpressionNoIn: LogicalANDExpressionNoIn  */
#line 616 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2936 "dlls/jscript/parser.tab.c"
    break;

  case 121: /* LogicalORExpressionNoIn: LogicalORExpressionNoIn tOROR LogicalANDExpressionNoIn  */
#line 618 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2942 "dlls/jscript/parser.tab.c"
    break;

  case 122: /* LogicalANDExpression: BitwiseORExpression  */
#line 622 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2948 "dlls/jscript/parser.tab.c"
    break;

  case 123: /* LogicalANDExpression: LogicalANDExpression tANDAND BitwiseORExpression  */
#line 624 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2954 "dlls/jscript/parser.tab.c"
    break;

  case 124: /* LogicalANDExpressionNoIn: BitwiseORExpressionNoIn  */
#line 629 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2960 "dlls/jscript/parser.tab.c"
    break;

  case 125: /* LogicalANDExpressionNoIn: LogicalANDExpressionNoIn tANDAND BitwiseORExpressionNoIn  */
#line 631 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2966 "dlls/jscript/parser.tab.c"
    break;

  case 126: /* BitwiseORExpression: BitwiseXORExpression  */
#line 635 "dlls/jscript/parser.y"
                                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2972 "dlls/jscript/parser.tab.c"
    break;

  case 127: /* BitwiseORExpression: BitwiseORExpression '|' BitwiseXORExpression  */
#line 637 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_BOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2978 "dlls/jscript/parser.tab.c"
    break;

  case 128: /* BitwiseORExpressionNoIn: BitwiseXORExpressionNoIn  */
#line 642 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2984 "dlls/jscript/parser.tab.c"
    break;

  case 129: /* BitwiseORExpressionNoIn: BitwiseORExpressionNoIn '|' BitwiseXORExpressionNoIn  */
#line 644 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_BOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2990 "dlls/jscript/parser.tab.c"
    break;

  case 130: /* BitwiseXORExpression: BitwiseANDExpression  */
#line 648 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2996 "dlls/jscript/parser.tab.c"
    break;

  case 131: /* BitwiseXORExpression: BitwiseXORExpression '^' BitwiseANDExpression  */
#line 650 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_BXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3002 "dlls/jscript/parser.tab.c"
    break;

  case 132: /* BitwiseXORExpressionNoIn: BitwiseANDExpressionNoIn  */
#line 655 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3008 "dlls/jscript/parser.tab.c"
    break;

  case 133: /* BitwiseXORExpressionNoIn: BitwiseXORExpressionNoIn '^' BitwiseANDExpressionNoIn  */
#line 657 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_BXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3014 "dlls/jscript/parser.tab.c"
    break;

  case 134: /* BitwiseANDExpression: EqualityExpression  */
#line 661 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3020 "dlls/jscript/parser.tab.c"
    break;

  case 135: /* BitwiseANDExpression: BitwiseANDExpression '&' EqualityExpression  */
#line 663 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_BAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3026 "dlls/jscript/parser.tab.c"
    break;

  case 136: /* BitwiseANDExpressionNoIn: EqualityExpressionNoIn  */
#line 668 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3032 "dlls/jscript/parser.tab.c"
    break;

  case 137: /* BitwiseANDExpressionNoIn: BitwiseANDExpressionNoIn '&' EqualityExpressionNoIn  */
#line 670 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_BAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3038 "dlls/jscript/parser.tab.c"
    break;

  case 138: /* EqualityExpression: RelationalExpression  */
#line 674 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3044 "dlls/jscript/parser.tab.c"
    break;

  case 139: /* EqualityExpression: EqualityExpression tEqOper RelationalExpression  */
#line 676 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3050 "dlls/jscript/parser.tab.c"
    break;

  case 140: /* EqualityExpressionNoIn: RelationalExpressionNoIn  */
#line 680 "dlls/jscript/parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3056 "dlls/jscript/parser.tab.c"
    break;

  case 141: /* EqualityExpressionNoIn: EqualityExpressionNoIn tEqOper RelationalExpressionNoIn  */
#line 682 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3062 "dlls/jscript/parser.tab.c"
    break;

  case 142: /* RelationalExpression: ShiftExpression  */
#line 686 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3068 "dlls/jscript/parser.tab.c"
    break;

  case 143: /* RelationalExpression: RelationalExpression tRelOper ShiftExpression  */
#line 688 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3074 "dlls/jscript/parser.tab.c"
    break;

  case 144: /* RelationalExpression: RelationalExpression kINSTANCEOF ShiftExpression  */
#line 690 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_INSTANCEOF, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3080 "dlls/jscript/parser.tab.c"
    break;

  case 145: /* RelationalExpression: RelationalExpression kIN ShiftExpression  */
#line 692 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_IN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3086 "dlls/jscript/parser.tab.c"
    break;

  case 146: /* RelationalExpressionNoIn: ShiftExpression  */
#line 696 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3092 "dlls/jscript/parser.tab.c"
    break;

  case 147: /* RelationalExpressionNoIn: RelationalExpressionNoIn tRelOper ShiftExpression  */
#line 698 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3098 "dlls/jscript/parser.tab.c"
    break;

  case 148: /* RelationalExpressionNoIn: RelationalExpressionNoIn kINSTANCEOF ShiftExpression  */
#line 700 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_INSTANCEOF, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3104 "dlls/jscript/parser.tab.c"
    break;

  case 149: /* ShiftExpression: AdditiveExpression  */
#line 704 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3110 "dlls/jscript/parser.tab.c"
    break;

  case 150: /* ShiftExpression: ShiftExpression tShiftOper AdditiveExpression  */
#line 706 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, (yyvsp[-1].ival), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3116 "dlls/jscript/parser.tab.c"
    break;

  case 151: /* AdditiveExpression: MultiplicativeExpression  */
#line 711 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3122 "dlls/jscript/parser.tab.c"
    break;

  case 152: /* AdditiveExpression: AdditiveExpression '+' MultiplicativeExpression  */
#line 713 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3128 "dlls/jscript/parser.tab.c"
    break;

  case 153: /* AdditiveExpression: AdditiveExpression '-' MultiplicativeExpression  */
#line 715 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3134 "dlls/jscript/parser.tab.c"
    break;

  case 154: /* MultiplicativeExpression: UnaryExpression  */
#line 719 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3140 "dlls/jscript/parser.tab.c"
    break;

  case 155: /* MultiplicativeExpression: MultiplicativeExpression '*' UnaryExpression  */
#line 721 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3146 "dlls/jscript/parser.tab.c"
    break;

  case 156: /* MultiplicativeExpression: MultiplicativeExpression '/' UnaryExpression  */
#line 723 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3152 "dlls/jscript/parser.tab.c"
    break;

  case 157: /* MultiplicativeExpression: MultiplicativeExpression '%' UnaryExpression  */
#line 725 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3158 "dlls/jscript/parser.tab.c"
    break;

  case 158: /* UnaryExpression: PostfixExpression  */
#line 729 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3164 "dlls/jscript/parser.tab.c"
    break;

  case 159: /* UnaryExpression: kDELETE UnaryExpression  */
#line 731 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_DELETE, (yyvsp[0].expr)); }
#line 3170 "dlls/jscript/parser.tab.c"
    break;

  case 160: /* UnaryExpression: kVOID UnaryExpression  */
#line 732 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_VOID, (yyvsp[0].expr)); }
#line 3176 "dlls/jscript/parser.tab.c"
    break;

  case 161: /* UnaryExpression: kTYPEOF UnaryExpression  */
#line 734 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_TYPEOF, (yyvsp[0].expr)); }
#line 3182 "dlls/jscript/parser.tab.c"
    break;

  case 162: /* UnaryExpression: tINC UnaryExpression  */
#line 735 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_PREINC, (yyvsp[0].expr)); }
#line 3188 "dlls/jscript/parser.tab.c"
    break;

  case 163: /* UnaryExpression: tDEC UnaryExpression  */
#line 736 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_PREDEC, (yyvsp[0].expr)); }
#line 3194 "dlls/jscript/parser.tab.c"
    break;

  case 164: /* UnaryExpression: '+' UnaryExpression  */
#line 737 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_PLUS, (yyvsp[0].expr)); }
#line 3200 "dlls/jscript/parser.tab.c"
    break;

  case 165: /* UnaryExpression: '-' UnaryExpression  */
#line 738 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_MINUS, (yyvsp[0].expr)); }
#line 3206 "dlls/jscript/parser.tab.c"
    break;

  case 166: /* UnaryExpression: '~' UnaryExpression  */
#line 739 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_BITNEG, (yyvsp[0].expr)); }
#line 3212 "dlls/jscript/parser.tab.c"
    break;

  case 167: /* UnaryExpression: '!' UnaryExpression  */
#line 740 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_LOGNEG, (yyvsp[0].expr)); }
#line 3218 "dlls/jscript/parser.tab.c"
    break;

  case 168: /* PostfixExpression: LeftHandSideExpression  */
#line 745 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3224 "dlls/jscript/parser.tab.c"
    break;

  case 169: /* PostfixExpression: LeftHandSideExpression tINC  */
#line 747 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_POSTINC, (yyvsp[-1].expr)); }
#line 3230 "dlls/jscript/parser.tab.c"
    break;

  case 170: /* PostfixExpression: LeftHandSideExpression tDEC  */
#line 749 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_unary_expression(ctx, EXPR_POSTDEC, (yyvsp[-1].expr)); }
#line 3236 "dlls/jscript/parser.tab.c"
    break;

  case 171: /* LeftHandSideExpression: NewExpression  */
#line 754 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3242 "dlls/jscript/parser.tab.c"
    break;

  case 172: /* LeftHandSideExpression: CallExpression  */
#line 755 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3248 "dlls/jscript/parser.tab.c"
    break;

  case 173: /* NewExpression: MemberExpression  */
#line 759 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3254 "dlls/jscript/parser.tab.c"
    break;

  case 174: /* NewExpression: kNEW NewExpression  */
#line 760 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_new_expression(ctx, (yyvsp[0].expr), NULL); }
#line 3260 "dlls/jscript/parser.tab.c"
    break;

  case 175: /* MemberExpression: PrimaryExpression  */
#line 764 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3266 "dlls/jscript/parser.tab.c"
    break;

  case 176: /* MemberExpression: FunctionExpression  */
#line 765 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3272 "dlls/jscript/parser.tab.c"
    break;

  case 177: /* MemberExpression: MemberExpression '[' Expression ']'  */
#line 767 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3278 "dlls/jscript/parser.tab.c"
    break;

  case 178: /* MemberExpression: MemberExpression '.' IdentifierName  */
#line 769 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_member_expression(ctx, (yyvsp[-2].expr), (yyvsp[0].identifier)); }
#line 3284 "dlls/jscript/parser.tab.c"
    break;

  case 179: /* MemberExpression: kNEW MemberExpression Arguments  */
#line 771 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_new_expression(ctx, (yyvsp[-1].expr), (yyvsp[0].argument_list)); }
#line 3290 "dlls/jscript/parser.tab.c"
    break;

  case 180: /* CallExpression: MemberExpression Arguments  */
#line 776 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_call_expression(ctx, (yyvsp[-1].expr), (yyvsp[0].argument_list)); }
#line 3296 "dlls/jscript/parser.tab.c"
    break;

  case 181: /* CallExpression: CallExpression Arguments  */
#line 778 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_call_expression(ctx, (yyvsp[-1].expr), (yyvsp[0].argument_list)); }
#line 3302 "dlls/jscript/parser.tab.c"
    break;

  case 182: /* CallExpression: CallExpression '[' Expression ']'  */
#line 780 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_binary_expression(ctx, EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3308 "dlls/jscript/parser.tab.c"
    break;

  case 183: /* CallExpression: CallExpression '.' IdentifierName  */
#line 782 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_member_expression(ctx, (yyvsp[-2].expr), (yyvsp[0].identifier)); }
#line 3314 "dlls/jscript/parser.tab.c"
    break;

  case 184: /* Arguments: '(' ')'  */
#line 786 "dlls/jscript/parser.y"
                                { (yyval.argument_list) = NULL; }
#line 3320 "dlls/jscript/parser.tab.c"
    break;

  case 185: /* Arguments: '(' ArgumentList ')'  */
#line 787 "dlls/jscript/parser.y"
                                { (yyval.argument_list) = (yyvsp[-1].argument_list); }
#line 3326 "dlls/jscript/parser.tab.c"
    break;

  case 186: /* ArgumentList: AssignmentExpression  */
#line 791 "dlls/jscript/parser.y"
                                { (yyval.argument_list) = new_argument_list(ctx, (yyvsp[0].expr)); }
#line 3332 "dlls/jscript/parser.tab.c"
    break;

  case 187: /* ArgumentList: ArgumentList ',' AssignmentExpression  */
#line 793 "dlls/jscript/parser.y"
                                { (yyval.argument_list) = argument_list_add(ctx, (yyvsp[-2].argument_list), (yyvsp[0].expr)); }
#line 3338 "dlls/jscript/parser.tab.c"
    break;

  case 188: /* PrimaryExpression: kTHIS  */
#line 797 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_expression(ctx, EXPR_THIS, 0); }
#line 3344 "dlls/jscript/parser.tab.c"
    break;

  case 189: /* PrimaryExpression: tIdentifier  */
#line 799 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_identifier_expression(ctx, (yyvsp[0].identifier)); }
#line 3350 "dlls/jscript/parser.tab.c"
    break;

  case 190: /* PrimaryExpression: kGET  */
#line 800 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_identifier_expression(ctx, (yyvsp[0].identifier)); }
#line 3356 "dlls/jscript/parser.tab.c"
    break;

  case 191: /* PrimaryExpression: kSET  */
#line 801 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_identifier_expression(ctx, (yyvsp[0].identifier)); }
#line 3362 "dlls/jscript/parser.tab.c"
    break;

  case 192: /* PrimaryExpression: kLET  */
#line 802 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_identifier_expression(ctx, (yyvsp[0].identifier)); }
#line 3368 "dlls/jscript/parser.tab.c"
    break;

  case 193: /* PrimaryExpression: Literal  */
#line 803 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_literal_expression(ctx, (yyvsp[0].literal)); }
#line 3374 "dlls/jscript/parser.tab.c"
    break;

  case 194: /* PrimaryExpression: ArrayLiteral  */
#line 804 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3380 "dlls/jscript/parser.tab.c"
    break;

  case 195: /* PrimaryExpression: ObjectLiteral  */
#line 805 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3386 "dlls/jscript/parser.tab.c"
    break;

  case 196: /* PrimaryExpression: '(' Expression ')'  */
#line 806 "dlls/jscript/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 3392 "dlls/jscript/parser.tab.c"
    break;

  case 197: /* ArrayLiteral: '[' ']'  */
#line 810 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_array_literal_expression(ctx, NULL, 0); }
#line 3398 "dlls/jscript/parser.tab.c"
    break;

  case 198: /* ArrayLiteral: '[' Elision ']'  */
#line 811 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_array_literal_expression(ctx, NULL, (yyvsp[-1].ival)+1); }
#line 3404 "dlls/jscript/parser.tab.c"
    break;

  case 199: /* ArrayLiteral: '[' ElementList ']'  */
#line 812 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_array_literal_expression(ctx, (yyvsp[-1].element_list), 0); }
#line 3410 "dlls/jscript/parser.tab.c"
    break;

  case 200: /* ArrayLiteral: '[' ElementList ',' Elision_opt ']'  */
#line 814 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_array_literal_expression(ctx, (yyvsp[-3].element_list), (yyvsp[-1].ival)+1); }
#line 3416 "dlls/jscript/parser.tab.c"
    break;

  case 201: /* ElementList: Elision_opt AssignmentExpression  */
#line 819 "dlls/jscript/parser.y"
                                { (yyval.element_list) = new_element_list(ctx, (yyvsp[-1].ival), (yyvsp[0].expr)); }
#line 3422 "dlls/jscript/parser.tab.c"
    break;

  case 202: /* ElementList: ElementList ',' Elision_opt AssignmentExpression  */
#line 821 "dlls/jscript/parser.y"
                                { (yyval.element_list) = element_list_add(ctx, (yyvsp[-3].element_list), (yyvsp[-1].ival), (yyvsp[0].expr)); }
#line 3428 "dlls/jscript/parser.tab.c"
    break;

  case 203: /* Elision: ','  */
#line 825 "dlls/jscript/parser.y"
                                { (yyval.ival) = 1; }
#line 3434 "dlls/jscript/parser.tab.c"
    break;

  case 204: /* Elision: Elision ','  */
#line 826 "dlls/jscript/parser.y"
                                { (yyval.ival) = (yyvsp[-1].ival) + 1; }
#line 3440 "dlls/jscript/parser.tab.c"
    break;

  case 205: /* Elision_opt: %empty  */
#line 830 "dlls/jscript/parser.y"
                                { (yyval.ival) = 0; }
#line 3446 "dlls/jscript/parser.tab.c"
    break;

  case 206: /* Elision_opt: Elision  */
#line 831 "dlls/jscript/parser.y"
                                { (yyval.ival) = (yyvsp[0].ival); }
#line 3452 "dlls/jscript/parser.tab.c"
    break;

  case 207: /* ObjectLiteral: '{' '}'  */
#line 835 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_prop_and_value_expression(ctx, NULL); }
#line 3458 "dlls/jscript/parser.tab.c"
    break;

  case 208: /* ObjectLiteral: '{' PropertyNameAndValueList '}'  */
#line 837 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_prop_and_value_expression(ctx, (yyvsp[-1].property_list)); }
#line 3464 "dlls/jscript/parser.tab.c"
    break;

  case 209: /* ObjectLiteral: '{' PropertyNameAndValueList ',' '}'  */
#line 839 "dlls/jscript/parser.y"
        {
            if(ctx->script->version < 2) {
                WARN("Trailing comma in object literal is illegal in legacy mode.\n");
                set_error(ctx, (yylsp[-1]), JS_E_SYNTAX);
                YYABORT;
            }
            (yyval.expr) = new_prop_and_value_expression(ctx, (yyvsp[-2].property_list));
        }
#line 3477 "dlls/jscript/parser.tab.c"
    break;

  case 210: /* PropertyNameAndValueList: PropertyDefinition  */
#line 850 "dlls/jscript/parser.y"
                                { (yyval.property_list) = new_property_list(ctx, (yyvsp[0].property_definition)); }
#line 3483 "dlls/jscript/parser.tab.c"
    break;

  case 211: /* PropertyNameAndValueList: PropertyNameAndValueList ',' PropertyDefinition  */
#line 852 "dlls/jscript/parser.y"
                                { (yyval.property_list) = property_list_add(ctx, (yyvsp[-2].property_list), (yyvsp[0].property_definition)); }
#line 3489 "dlls/jscript/parser.tab.c"
    break;

  case 212: /* PropertyDefinition: PropertyName ':' AssignmentExpression  */
#line 857 "dlls/jscript/parser.y"
                                { (yyval.property_definition) = new_property_definition(ctx, PROPERTY_DEFINITION_VALUE, (yyvsp[-2].literal), (yyvsp[0].expr)); }
#line 3495 "dlls/jscript/parser.tab.c"
    break;

  case 213: /* PropertyDefinition: kGET PropertyName GetterSetterMethod  */
#line 859 "dlls/jscript/parser.y"
                                { (yyval.property_definition) = new_property_definition(ctx, PROPERTY_DEFINITION_GETTER, (yyvsp[-1].literal), (yyvsp[0].expr)); }
#line 3501 "dlls/jscript/parser.tab.c"
    break;

  case 214: /* PropertyDefinition: kSET PropertyName GetterSetterMethod  */
#line 861 "dlls/jscript/parser.y"
                                { (yyval.property_definition) = new_property_definition(ctx, PROPERTY_DEFINITION_SETTER, (yyvsp[-1].literal), (yyvsp[0].expr)); }
#line 3507 "dlls/jscript/parser.tab.c"
    break;

  case 215: /* GetterSetterMethod: left_bracket FormalParameterList_opt right_bracket '{' FunctionBody '}'  */
#line 865 "dlls/jscript/parser.y"
                                { (yyval.expr) = new_function_expression(ctx, NULL, (yyvsp[-4].parameter_list), (yyvsp[-1].statement_list), NULL, ctx->begin + (yylsp[-5]), (yylsp[0]) - (yylsp[-5]) + 1); }
#line 3513 "dlls/jscript/parser.tab.c"
    break;

  case 216: /* PropertyName: IdentifierName  */
#line 869 "dlls/jscript/parser.y"
                                { (yyval.literal) = new_string_literal(ctx, compiler_alloc_string_len(ctx->compiler, (yyvsp[0].identifier), lstrlenW((yyvsp[0].identifier)))); }
#line 3519 "dlls/jscript/parser.tab.c"
    break;

  case 217: /* PropertyName: tStringLiteral  */
#line 870 "dlls/jscript/parser.y"
                                { (yyval.literal) = new_string_literal(ctx, (yyvsp[0].str)); }
#line 3525 "dlls/jscript/parser.tab.c"
    break;

  case 218: /* PropertyName: tNumericLiteral  */
#line 871 "dlls/jscript/parser.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 3531 "dlls/jscript/parser.tab.c"
    break;

  case 219: /* Identifier_opt: %empty  */
#line 875 "dlls/jscript/parser.y"
                                { (yyval.identifier) = NULL; }
#line 3537 "dlls/jscript/parser.tab.c"
    break;

  case 220: /* Identifier_opt: Identifier  */
#line 876 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3543 "dlls/jscript/parser.tab.c"
    break;

  case 221: /* Identifier: tIdentifier  */
#line 879 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3549 "dlls/jscript/parser.tab.c"
    break;

  case 222: /* Identifier: ES5Keyword  */
#line 880 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3555 "dlls/jscript/parser.tab.c"
    break;

  case 223: /* IdentifierName: tIdentifier  */
#line 884 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3561 "dlls/jscript/parser.tab.c"
    break;

  case 224: /* IdentifierName: ReservedAsIdentifier  */
#line 886 "dlls/jscript/parser.y"
        {
            if(ctx->script->version < SCRIPTLANGUAGEVERSION_ES5) {
                WARN("%s keyword used as an identifier in legacy mode.\n",
                     debugstr_w((yyvsp[0].identifier)));
                set_error(ctx, (yyloc), JS_E_SYNTAX);
                YYABORT;
            }
            (yyval.identifier) = (yyvsp[0].identifier);
        }
#line 3575 "dlls/jscript/parser.tab.c"
    break;

  case 225: /* ReservedAsIdentifier: kBREAK  */
#line 897 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3581 "dlls/jscript/parser.tab.c"
    break;

  case 226: /* ReservedAsIdentifier: kCASE  */
#line 898 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3587 "dlls/jscript/parser.tab.c"
    break;

  case 227: /* ReservedAsIdentifier: kCATCH  */
#line 899 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3593 "dlls/jscript/parser.tab.c"
    break;

  case 228: /* ReservedAsIdentifier: kCONST  */
#line 900 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3599 "dlls/jscript/parser.tab.c"
    break;

  case 229: /* ReservedAsIdentifier: kCONTINUE  */
#line 901 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3605 "dlls/jscript/parser.tab.c"
    break;

  case 230: /* ReservedAsIdentifier: kDEFAULT  */
#line 902 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3611 "dlls/jscript/parser.tab.c"
    break;

  case 231: /* ReservedAsIdentifier: kDELETE  */
#line 903 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3617 "dlls/jscript/parser.tab.c"
    break;

  case 232: /* ReservedAsIdentifier: kDO  */
#line 904 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3623 "dlls/jscript/parser.tab.c"
    break;

  case 233: /* ReservedAsIdentifier: kELSE  */
#line 905 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3629 "dlls/jscript/parser.tab.c"
    break;

  case 234: /* ReservedAsIdentifier: kFALSE  */
#line 906 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3635 "dlls/jscript/parser.tab.c"
    break;

  case 235: /* ReservedAsIdentifier: kFINALLY  */
#line 907 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3641 "dlls/jscript/parser.tab.c"
    break;

  case 236: /* ReservedAsIdentifier: kFOR  */
#line 908 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3647 "dlls/jscript/parser.tab.c"
    break;

  case 237: /* ReservedAsIdentifier: kFUNCTION  */
#line 909 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3653 "dlls/jscript/parser.tab.c"
    break;

  case 238: /* ReservedAsIdentifier: kIF  */
#line 910 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3659 "dlls/jscript/parser.tab.c"
    break;

  case 239: /* ReservedAsIdentifier: kIN  */
#line 911 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3665 "dlls/jscript/parser.tab.c"
    break;

  case 240: /* ReservedAsIdentifier: kINSTANCEOF  */
#line 912 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3671 "dlls/jscript/parser.tab.c"
    break;

  case 241: /* ReservedAsIdentifier: kNEW  */
#line 913 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3677 "dlls/jscript/parser.tab.c"
    break;

  case 242: /* ReservedAsIdentifier: kNULL  */
#line 914 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3683 "dlls/jscript/parser.tab.c"
    break;

  case 243: /* ReservedAsIdentifier: kRETURN  */
#line 915 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3689 "dlls/jscript/parser.tab.c"
    break;

  case 244: /* ReservedAsIdentifier: kSWITCH  */
#line 916 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3695 "dlls/jscript/parser.tab.c"
    break;

  case 245: /* ReservedAsIdentifier: kTHIS  */
#line 917 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3701 "dlls/jscript/parser.tab.c"
    break;

  case 246: /* ReservedAsIdentifier: kTHROW  */
#line 918 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3707 "dlls/jscript/parser.tab.c"
    break;

  case 247: /* ReservedAsIdentifier: kTRUE  */
#line 919 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3713 "dlls/jscript/parser.tab.c"
    break;

  case 248: /* ReservedAsIdentifier: kTRY  */
#line 920 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3719 "dlls/jscript/parser.tab.c"
    break;

  case 249: /* ReservedAsIdentifier: kTYPEOF  */
#line 921 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3725 "dlls/jscript/parser.tab.c"
    break;

  case 250: /* ReservedAsIdentifier: kVAR  */
#line 922 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3731 "dlls/jscript/parser.tab.c"
    break;

  case 251: /* ReservedAsIdentifier: kVOID  */
#line 923 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3737 "dlls/jscript/parser.tab.c"
    break;

  case 252: /* ReservedAsIdentifier: kWHILE  */
#line 924 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3743 "dlls/jscript/parser.tab.c"
    break;

  case 253: /* ReservedAsIdentifier: kWITH  */
#line 925 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3749 "dlls/jscript/parser.tab.c"
    break;

  case 254: /* ReservedAsIdentifier: ES5Keyword  */
#line 926 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3755 "dlls/jscript/parser.tab.c"
    break;

  case 255: /* ES5Keyword: kGET  */
#line 929 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3761 "dlls/jscript/parser.tab.c"
    break;

  case 256: /* ES5Keyword: kLET  */
#line 930 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3767 "dlls/jscript/parser.tab.c"
    break;

  case 257: /* ES5Keyword: kSET  */
#line 931 "dlls/jscript/parser.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 3773 "dlls/jscript/parser.tab.c"
    break;

  case 258: /* Literal: kNULL  */
#line 935 "dlls/jscript/parser.y"
                                { (yyval.literal) = new_null_literal(ctx); }
#line 3779 "dlls/jscript/parser.tab.c"
    break;

  case 259: /* Literal: BooleanLiteral  */
#line 936 "dlls/jscript/parser.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 3785 "dlls/jscript/parser.tab.c"
    break;

  case 260: /* Literal: tNumericLiteral  */
#line 937 "dlls/jscript/parser.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 3791 "dlls/jscript/parser.tab.c"
    break;

  case 261: /* Literal: tStringLiteral  */
#line 938 "dlls/jscript/parser.y"
                                { (yyval.literal) = new_string_literal(ctx, (yyvsp[0].str)); }
#line 3797 "dlls/jscript/parser.tab.c"
    break;

  case 262: /* Literal: '/'  */
#line 939 "dlls/jscript/parser.y"
                                { (yyval.literal) = parse_regexp(ctx);
                                  if(!(yyval.literal)) YYABORT; }
#line 3804 "dlls/jscript/parser.tab.c"
    break;

  case 263: /* Literal: kDIVEQ  */
#line 941 "dlls/jscript/parser.y"
                                { (yyval.literal) = parse_regexp(ctx);
                                  if(!(yyval.literal)) YYABORT; }
#line 3811 "dlls/jscript/parser.tab.c"
    break;

  case 264: /* BooleanLiteral: kTRUE  */
#line 946 "dlls/jscript/parser.y"
                                { (yyval.literal) = new_boolean_literal(ctx, VARIANT_TRUE); }
#line 3817 "dlls/jscript/parser.tab.c"
    break;

  case 265: /* BooleanLiteral: kFALSE  */
#line 947 "dlls/jscript/parser.y"
                                { (yyval.literal) = new_boolean_literal(ctx, VARIANT_FALSE); }
#line 3823 "dlls/jscript/parser.tab.c"
    break;

  case 266: /* BooleanLiteral: tBooleanLiteral  */
#line 948 "dlls/jscript/parser.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 3829 "dlls/jscript/parser.tab.c"
    break;

  case 268: /* semicolon_opt: error  */
#line 952 "dlls/jscript/parser.y"
                                { if(!allow_auto_semicolon(ctx)) {YYABORT;} else { ctx->hres = S_OK; ctx->error_loc = -1; } }
#line 3835 "dlls/jscript/parser.tab.c"
    break;

  case 270: /* left_bracket: error  */
#line 956 "dlls/jscript/parser.y"
                                { set_error(ctx, (yyloc), JS_E_MISSING_LBRACKET); YYABORT; }
#line 3841 "dlls/jscript/parser.tab.c"
    break;

  case 272: /* right_bracket: error  */
#line 960 "dlls/jscript/parser.y"
                                { set_error(ctx, (yyloc), JS_E_MISSING_RBRACKET); YYABORT; }
#line 3847 "dlls/jscript/parser.tab.c"
    break;

  case 274: /* semicolon: error  */
#line 964 "dlls/jscript/parser.y"
                                { set_error(ctx,  (yyloc), JS_E_MISSING_SEMICOLON); YYABORT; }
#line 3853 "dlls/jscript/parser.tab.c"
    break;


#line 3857 "dlls/jscript/parser.tab.c"

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

#line 966 "dlls/jscript/parser.y"


static BOOL allow_auto_semicolon(parser_ctx_t *ctx)
{
    return ctx->nl || ctx->ptr == ctx->end || *(ctx->ptr-1) == '}';
}

static void *new_statement(parser_ctx_t *ctx, statement_type_t type, size_t size, unsigned loc)
{
    statement_t *stat;

    stat = parser_alloc(ctx, size ? size : sizeof(*stat));
    if(!stat)
        return NULL;

    stat->type = type;
    stat->loc  = loc;
    stat->next = NULL;

    return stat;
}

static literal_t *new_string_literal(parser_ctx_t *ctx, jsstr_t *str)
{
    literal_t *ret = parser_alloc(ctx, sizeof(literal_t));

    ret->type = LT_STRING;
    ret->u.str = str;

    return ret;
}

static literal_t *new_null_literal(parser_ctx_t *ctx)
{
    literal_t *ret = parser_alloc(ctx, sizeof(literal_t));

    ret->type = LT_NULL;

    return ret;
}

static property_definition_t *new_property_definition(parser_ctx_t *ctx, property_definition_type_t type,
                                                      literal_t *name, expression_t *value)
{
    property_definition_t *ret = parser_alloc(ctx, sizeof(property_definition_t));

    ret->type = type;
    ret->name = name;
    ret->value = value;
    ret->next = NULL;

    return ret;
}

static property_list_t *new_property_list(parser_ctx_t *ctx, property_definition_t *prop)
{
    property_list_t *ret = parser_alloc_tmp(ctx, sizeof(property_list_t));
    ret->head = ret->tail = prop;
    return ret;
}

static property_list_t *property_list_add(parser_ctx_t *ctx, property_list_t *list, property_definition_t *prop)
{
    list->tail = list->tail->next = prop;
    return list;
}

static array_element_t *new_array_element(parser_ctx_t *ctx, int elision, expression_t *expr)
{
    array_element_t *ret = parser_alloc(ctx, sizeof(array_element_t));

    ret->elision = elision;
    ret->expr = expr;
    ret->next = NULL;

    return ret;
}

static element_list_t *new_element_list(parser_ctx_t *ctx, int elision, expression_t *expr)
{
    element_list_t *ret = parser_alloc_tmp(ctx, sizeof(element_list_t));

    ret->head = ret->tail = new_array_element(ctx, elision, expr);

    return ret;
}

static element_list_t *element_list_add(parser_ctx_t *ctx, element_list_t *list, int elision, expression_t *expr)
{
    list->tail = list->tail->next = new_array_element(ctx, elision, expr);

    return list;
}

static argument_t *new_argument(parser_ctx_t *ctx, expression_t *expr)
{
    argument_t *ret = parser_alloc(ctx, sizeof(argument_t));

    ret->expr = expr;
    ret->next = NULL;

    return ret;
}

static argument_list_t *new_argument_list(parser_ctx_t *ctx, expression_t *expr)
{
    argument_list_t *ret = parser_alloc_tmp(ctx, sizeof(argument_list_t));

    ret->head = ret->tail = new_argument(ctx, expr);

    return ret;
}

static argument_list_t *argument_list_add(parser_ctx_t *ctx, argument_list_t *list, expression_t *expr)
{
    list->tail = list->tail->next = new_argument(ctx, expr);

    return list;
}

static catch_block_t *new_catch_block(parser_ctx_t *ctx, const WCHAR *identifier, statement_t *statement)
{
    catch_block_t *ret = parser_alloc(ctx, sizeof(catch_block_t));

    ret->identifier = identifier;
    ret->statement = statement;

    return ret;
}

static case_clausule_t *new_case_clausule(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_list_t *stat_list)
{
    case_clausule_t *ret = parser_alloc(ctx, sizeof(case_clausule_t));

    ret->expr = expr;
    ret->stat = stat_list ? stat_list->head : NULL;
    ret->loc = loc;
    ret->next = NULL;

    return ret;
}

static case_list_t *new_case_list(parser_ctx_t *ctx, case_clausule_t *case_clausule)
{
    case_list_t *ret = parser_alloc_tmp(ctx, sizeof(case_list_t));

    ret->head = ret->tail = case_clausule;

    return ret;
}

static case_list_t *case_list_add(parser_ctx_t *ctx, case_list_t *list, case_clausule_t *case_clausule)
{
    list->tail = list->tail->next = case_clausule;

    return list;
}

static case_clausule_t *new_case_block(parser_ctx_t *ctx, case_list_t *case_list1,
        case_clausule_t *default_clausule, case_list_t *case_list2)
{
    case_clausule_t *ret = NULL, *iter = NULL, *iter2;
    statement_t *stat = NULL;

    if(case_list1) {
        ret = case_list1->head;
        iter = case_list1->tail;
    }

    if(default_clausule) {
        if(ret)
            iter = iter->next = default_clausule;
        else
            ret = iter = default_clausule;
    }

    if(case_list2) {
        if(ret)
            iter->next = case_list2->head;
        else
            ret = case_list2->head;
    }

    if(!ret)
        return NULL;

    for(iter = ret; iter; iter = iter->next) {
        for(iter2 = iter; iter2 && !iter2->stat; iter2 = iter2->next);
        if(!iter2)
            break;

        while(iter != iter2) {
            iter->stat = iter2->stat;
            iter = iter->next;
        }

        if(stat) {
            while(stat->next)
                stat = stat->next;
            stat->next = iter->stat;
        }else {
            stat = iter->stat;
        }
    }

    return ret;
}

static statement_t *new_block_statement(parser_ctx_t *ctx, unsigned loc, statement_list_t *list)
{
    block_statement_t *ret;

    ret = new_statement(ctx, STAT_BLOCK, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->scope_index = 0;
    ret->stat_list = list ? list->head : NULL;

    return &ret->stat;
}

static variable_declaration_t *new_variable_declaration(parser_ctx_t *ctx, const WCHAR *identifier, expression_t *expr)
{
    variable_declaration_t *ret = parser_alloc(ctx, sizeof(variable_declaration_t));

    ret->identifier = identifier;
    ret->expr = expr;
    ret->next = NULL;
    ret->global_next = NULL;
    ret->block_scope = FALSE;
    ret->constant = FALSE;

    return ret;
}

static variable_list_t *new_variable_list(parser_ctx_t *ctx, variable_declaration_t *decl)
{
    variable_list_t *ret = parser_alloc_tmp(ctx, sizeof(variable_list_t));

    ret->head = ret->tail = decl;

    return ret;
}

static variable_list_t *variable_list_add(parser_ctx_t *ctx, variable_list_t *list, variable_declaration_t *decl)
{
    list->tail = list->tail->next = decl;

    return list;
}

static statement_t *new_var_statement(parser_ctx_t *ctx, BOOL block_scope, BOOL constant, unsigned loc,
        variable_list_t *variable_list)
{
    variable_declaration_t *var;
    var_statement_t *ret;

    ret = new_statement(ctx, STAT_VAR, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->variable_list = variable_list->head;
    for (var = ret->variable_list; var; var = var->next)
    {
        var->block_scope = block_scope;
        var->constant = constant;
    }

    return &ret->stat;
}

static statement_t *new_expression_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr)
{
    expression_statement_t *ret;

    ret = new_statement(ctx, STAT_EXPR, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->expr = expr;

    return &ret->stat;
}

static statement_t *new_if_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr,
                                     statement_t *if_stat, statement_t *else_stat)
{
    if_statement_t *ret;

    ret = new_statement(ctx, STAT_IF, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->expr = expr;
    ret->if_stat = if_stat;
    ret->else_stat = else_stat;

    return &ret->stat;
}

static statement_t *new_while_statement(parser_ctx_t *ctx, unsigned loc, BOOL dowhile, expression_t *expr, statement_t *stat)
{
    while_statement_t *ret;

    ret = new_statement(ctx, STAT_WHILE, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->do_while = dowhile;
    ret->expr = expr;
    ret->statement = stat;

    return &ret->stat;
}

static statement_t *new_for_statement(parser_ctx_t *ctx, unsigned loc, variable_declaration_t *variable_list, expression_t *begin_expr,
        expression_t *expr, unsigned expr_loc, expression_t *end_expr, unsigned end_loc, statement_t *statement)
{
    for_statement_t *ret;

    ret = new_statement(ctx, STAT_FOR, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->variable_list = variable_list;
    ret->begin_expr = begin_expr;
    ret->expr = expr;
    ret->expr_loc = expr_loc;
    ret->end_expr = end_expr;
    ret->end_loc = end_loc;
    ret->statement = statement;
    ret->scope_index = 0;

    return &ret->stat;
}

static statement_t *new_forin_statement(parser_ctx_t *ctx, unsigned loc, variable_declaration_t *variable, expression_t *expr,
        expression_t *in_expr, statement_t *statement)
{
    forin_statement_t *ret;

    ret = new_statement(ctx, STAT_FORIN, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->variable = variable;
    ret->expr = expr;
    ret->in_expr = in_expr;
    ret->statement = statement;

    return &ret->stat;
}

static statement_t *new_continue_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier)
{
    branch_statement_t *ret;

    ret = new_statement(ctx, STAT_CONTINUE, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->identifier = identifier;

    return &ret->stat;
}

static statement_t *new_break_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier)
{
    branch_statement_t *ret;

    ret = new_statement(ctx, STAT_BREAK, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->identifier = identifier;

    return &ret->stat;
}

static statement_t *new_return_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr)
{
    expression_statement_t *ret;

    ret = new_statement(ctx, STAT_RETURN, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->expr = expr;

    return &ret->stat;
}

static statement_t *new_with_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *statement)
{
    with_statement_t *ret;

    ret = new_statement(ctx, STAT_WITH, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->expr = expr;
    ret->statement = statement;

    return &ret->stat;
}

static statement_t *new_labelled_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier, statement_t *statement)
{
    labelled_statement_t *ret;

    ret = new_statement(ctx, STAT_LABEL, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->identifier = identifier;
    ret->statement = statement;

    return &ret->stat;
}

static statement_t *new_switch_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, case_clausule_t *case_list)
{
    switch_statement_t *ret;

    ret = new_statement(ctx, STAT_SWITCH, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->expr = expr;
    ret->case_list = case_list;

    return &ret->stat;
}

static statement_t *new_throw_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr)
{
    expression_statement_t *ret;

    ret = new_statement(ctx, STAT_THROW, sizeof(*ret), loc);
    if(!ret)
        return NULL;

    ret->expr = expr;

    return &ret->stat;
}

static statement_t *new_try_statement(parser_ctx_t *ctx, statement_t *try_statement,
        catch_block_t *catch_block, statement_t *finally_statement, unsigned finally_loc)
{
    try_statement_t *ret;

    ret = new_statement(ctx, STAT_TRY, sizeof(*ret), try_statement->loc);
    if(!ret)
        return NULL;

    ret->try_statement = try_statement;
    ret->catch_block = catch_block;
    ret->finally_statement = finally_statement;
    ret->finally_loc = finally_loc;

    return &ret->stat;
}

static parameter_t *new_parameter(parser_ctx_t *ctx, const WCHAR *identifier)
{
    parameter_t *ret = parser_alloc(ctx, sizeof(parameter_t));

    ret->identifier = identifier;
    ret->next = NULL;

    return ret;
}

static parameter_list_t *new_parameter_list(parser_ctx_t *ctx, const WCHAR *identifier)
{
    parameter_list_t *ret = parser_alloc_tmp(ctx, sizeof(parameter_list_t));

    ret->head = ret->tail = new_parameter(ctx, identifier);

    return ret;
}

static parameter_list_t *parameter_list_add(parser_ctx_t *ctx, parameter_list_t *list, const WCHAR *identifier)
{
    list->tail = list->tail->next = new_parameter(ctx, identifier);

    return list;
}

static expression_t *new_function_expression(parser_ctx_t *ctx, const WCHAR *identifier, parameter_list_t *parameter_list,
    statement_list_t *statement_list, const WCHAR *event_target, const WCHAR *src_str, DWORD src_len)
{
    function_expression_t *ret = new_expression(ctx, EXPR_FUNC, sizeof(*ret));

    ret->identifier = identifier;
    ret->parameter_list = parameter_list ? parameter_list->head : NULL;
    ret->statement_list = statement_list ? statement_list->head : NULL;
    ret->event_target = event_target;
    ret->src_str = src_str;
    ret->src_len = src_len;
    ret->is_statement = FALSE;
    ret->scope_index = 0;
    ret->next = NULL;

    return &ret->expr;
}

static void *new_expression(parser_ctx_t *ctx, expression_type_t type, size_t size)
{
    expression_t *ret = parser_alloc(ctx, size ? size : sizeof(*ret));

    ret->type = type;

    return ret;
}

static expression_t *new_binary_expression(parser_ctx_t *ctx, expression_type_t type,
       expression_t *expression1, expression_t *expression2)
{
    binary_expression_t *ret = new_expression(ctx, type, sizeof(*ret));

    ret->expression1 = expression1;
    ret->expression2 = expression2;

    return &ret->expr;
}

static expression_t *new_unary_expression(parser_ctx_t *ctx, expression_type_t type, expression_t *expression)
{
    unary_expression_t *ret = new_expression(ctx, type, sizeof(*ret));

    ret->expression = expression;

    return &ret->expr;
}

static expression_t *new_conditional_expression(parser_ctx_t *ctx, expression_t *expression,
       expression_t *true_expression, expression_t *false_expression)
{
    conditional_expression_t *ret = new_expression(ctx, EXPR_COND, sizeof(*ret));

    ret->expression = expression;
    ret->true_expression = true_expression;
    ret->false_expression = false_expression;

    return &ret->expr;
}

static expression_t *new_member_expression(parser_ctx_t *ctx, expression_t *expression, const WCHAR *identifier)
{
    member_expression_t *ret = new_expression(ctx, EXPR_MEMBER, sizeof(*ret));

    ret->expression = expression;
    ret->identifier = identifier;

    return &ret->expr;
}

static expression_t *new_new_expression(parser_ctx_t *ctx, expression_t *expression, argument_list_t *argument_list)
{
    call_expression_t *ret = new_expression(ctx, EXPR_NEW, sizeof(*ret));

    ret->expression = expression;
    ret->argument_list = argument_list ? argument_list->head : NULL;

    return &ret->expr;
}

static expression_t *new_call_expression(parser_ctx_t *ctx, expression_t *expression, argument_list_t *argument_list)
{
    call_expression_t *ret = new_expression(ctx, EXPR_CALL, sizeof(*ret));

    ret->expression = expression;
    ret->argument_list = argument_list ? argument_list->head : NULL;

    return &ret->expr;
}

static int parser_error(unsigned *loc, parser_ctx_t *ctx, const char *str)
{
    if(ctx->error_loc == -1)
        ctx->error_loc = *loc;
    if(ctx->hres == S_OK)
        ctx->hres = JS_E_SYNTAX;
    return 0;
}

static void set_error(parser_ctx_t *ctx, unsigned loc, HRESULT error)
{
    ctx->hres = error;
    ctx->error_loc = loc;
}

static BOOL explicit_error(parser_ctx_t *ctx, void *obj, WCHAR next)
{
    if(obj || *(ctx->ptr-1)==next) return TRUE;

    set_error(ctx, ctx->ptr - ctx->begin /* FIXME */, JS_E_SYNTAX);
    return FALSE;
}


static expression_t *new_identifier_expression(parser_ctx_t *ctx, const WCHAR *identifier)
{
    identifier_expression_t *ret = new_expression(ctx, EXPR_IDENT, sizeof(*ret));

    ret->identifier = identifier;

    return &ret->expr;
}

static expression_t *new_array_literal_expression(parser_ctx_t *ctx, element_list_t *element_list, int length)
{
    array_literal_expression_t *ret = new_expression(ctx, EXPR_ARRAYLIT, sizeof(*ret));

    ret->element_list = element_list ? element_list->head : NULL;
    ret->length = length;

    return &ret->expr;
}

static expression_t *new_prop_and_value_expression(parser_ctx_t *ctx, property_list_t *property_list)
{
    property_value_expression_t *ret = new_expression(ctx, EXPR_PROPVAL, sizeof(*ret));

    ret->property_list = property_list ? property_list->head : NULL;

    return &ret->expr;
}

static expression_t *new_literal_expression(parser_ctx_t *ctx, literal_t *literal)
{
    literal_expression_t *ret = new_expression(ctx, EXPR_LITERAL, sizeof(*ret));

    ret->literal = literal;

    return &ret->expr;
}

static statement_list_t *new_statement_list(parser_ctx_t *ctx, statement_t *statement)
{
    statement_list_t *ret =  parser_alloc_tmp(ctx, sizeof(statement_list_t));

    ret->head = ret->tail = statement;

    return ret;
}

static statement_list_t *statement_list_add(statement_list_t *list, statement_t *statement)
{
    list->tail = list->tail->next = statement;

    return list;
}

void parser_release(parser_ctx_t *ctx)
{
    script_release(ctx->script);
    heap_pool_free(&ctx->heap);
    free(ctx);
}

HRESULT script_parse(script_ctx_t *ctx, struct _compiler_ctx_t *compiler, bytecode_t *code, const WCHAR *delimiter, BOOL from_eval,
        parser_ctx_t **ret)
{
    parser_ctx_t *parser_ctx;
    heap_pool_t *mark;
    HRESULT hres;

    parser_ctx = calloc(1, sizeof(parser_ctx_t));
    if(!parser_ctx)
        return E_OUTOFMEMORY;

    parser_ctx->error_loc = -1;
    parser_ctx->is_html = delimiter && !wcsicmp(delimiter, L"</script>");

    parser_ctx->begin = parser_ctx->ptr = code->source;
    parser_ctx->end = parser_ctx->begin + lstrlenW(parser_ctx->begin);

    script_addref(ctx);
    parser_ctx->script = ctx;

    mark = heap_pool_mark(&ctx->tmp_heap);
    heap_pool_init(&parser_ctx->heap);

    parser_ctx->compiler = compiler;
    parser_parse(parser_ctx);
    parser_ctx->compiler = NULL;

    heap_pool_clear(mark);
    hres = parser_ctx->hres;
    if(FAILED(hres)) {
        unsigned int error_loc = parser_ctx->error_loc == -1 ? 0 : parser_ctx->error_loc;
        const WCHAR *line_start = code->source + error_loc, *line_end = line_start;
        jsstr_t *line_str;

        while(line_start > code->source && line_start[-1] != '\n')
            line_start--;
        while(*line_end && *line_end != '\n')
            line_end++;
        line_str = jsstr_alloc_len(line_start, line_end - line_start);

        WARN("parser failed around %s in line %s\n",
             debugstr_w(parser_ctx->begin+20 > parser_ctx->ptr ? parser_ctx->begin : parser_ctx->ptr-20),
             debugstr_jsstr(line_str));

        throw_error(ctx, hres, NULL);
        set_error_location(ctx->ei, code, error_loc, IDS_COMPILATION_ERROR, line_str);
        parser_release(parser_ctx);
        if(line_str)
            jsstr_release(line_str);
        return DISP_E_EXCEPTION;
    }

    *ret = parser_ctx;
    return S_OK;
}
