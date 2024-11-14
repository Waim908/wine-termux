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

#ifndef YY_PARSER_DLLS_VBSCRIPT_PARSER_TAB_H_INCLUDED
# define YY_PARSER_DLLS_VBSCRIPT_PARSER_TAB_H_INCLUDED
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

#line 168 "dlls/vbscript/parser.tab.h"

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


#endif /* !YY_PARSER_DLLS_VBSCRIPT_PARSER_TAB_H_INCLUDED  */
