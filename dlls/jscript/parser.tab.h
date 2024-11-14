/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_PARSER_DLLS_JSCRIPT_PARSER_TAB_H_INCLUDED
# define YY_PARSER_DLLS_JSCRIPT_PARSER_TAB_H_INCLUDED
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

#line 142 "dlls/jscript/parser.tab.h"

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


#endif /* !YY_PARSER_DLLS_JSCRIPT_PARSER_TAB_H_INCLUDED  */
