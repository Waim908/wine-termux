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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         DBG_STYPE
/* Substitute the variable and function names.  */
#define yyparse         dbg_parse
#define yylex           dbg_lex
#define yyerror         dbg_error
#define yydebug         dbg_debug
#define yynerrs         dbg_nerrs
#define yylval          dbg_lval
#define yychar          dbg_char

/* First part of user prologue.  */
#line 1 "programs/winedbg/dbg.y"

/*
 * Parser for command lines in the Wine debugger
 *
 * Copyright 1993 Eric Youngdale
 * Copyright 1995 Morten Welinder
 * Copyright 2000 Eric Pouech
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugger.h"
#include "wine/exception.h"
#include "expr.h"

int dbg_lex(void);
static int dbg_error(const char*);
static void parser(const char*);


#line 116 "programs/winedbg/dbg.tab.c"

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
#ifndef DBG_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define DBG_DEBUG 1
#  else
#   define DBG_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define DBG_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined DBG_DEBUG */
#if DBG_DEBUG
extern int dbg_debug;
#endif

/* Token kinds.  */
#ifndef DBG_TOKENTYPE
# define DBG_TOKENTYPE
  enum dbg_tokentype
  {
    DBG_EMPTY = -2,
    DBG_EOF = 0,                   /* "end of file"  */
    DBG_error = 256,               /* error  */
    DBG_UNDEF = 257,               /* "invalid token"  */
    tCONT = 258,                   /* tCONT  */
    tPASS = 259,                   /* tPASS  */
    tSTEP = 260,                   /* tSTEP  */
    tLIST = 261,                   /* tLIST  */
    tNEXT = 262,                   /* tNEXT  */
    tQUIT = 263,                   /* tQUIT  */
    tHELP = 264,                   /* tHELP  */
    tBACKTRACE = 265,              /* tBACKTRACE  */
    tALL = 266,                    /* tALL  */
    tINFO = 267,                   /* tINFO  */
    tUP = 268,                     /* tUP  */
    tDOWN = 269,                   /* tDOWN  */
    tENABLE = 270,                 /* tENABLE  */
    tDISABLE = 271,                /* tDISABLE  */
    tBREAK = 272,                  /* tBREAK  */
    tHBREAK = 273,                 /* tHBREAK  */
    tWATCH = 274,                  /* tWATCH  */
    tRWATCH = 275,                 /* tRWATCH  */
    tDELETE = 276,                 /* tDELETE  */
    tSET = 277,                    /* tSET  */
    tPRINT = 278,                  /* tPRINT  */
    tEXAM = 279,                   /* tEXAM  */
    tABORT = 280,                  /* tABORT  */
    tECHO = 281,                   /* tECHO  */
    tCLASS = 282,                  /* tCLASS  */
    tMAPS = 283,                   /* tMAPS  */
    tSTACK = 284,                  /* tSTACK  */
    tSEGMENTS = 285,               /* tSEGMENTS  */
    tSYMBOL = 286,                 /* tSYMBOL  */
    tREGS = 287,                   /* tREGS  */
    tALLREGS = 288,                /* tALLREGS  */
    tWND = 289,                    /* tWND  */
    tLOCAL = 290,                  /* tLOCAL  */
    tEXCEPTION = 291,              /* tEXCEPTION  */
    tPROCESS = 292,                /* tPROCESS  */
    tTHREAD = 293,                 /* tTHREAD  */
    tEOL = 294,                    /* tEOL  */
    tEOF = 295,                    /* tEOF  */
    tFRAME = 296,                  /* tFRAME  */
    tSHARE = 297,                  /* tSHARE  */
    tMODULE = 298,                 /* tMODULE  */
    tCOND = 299,                   /* tCOND  */
    tDISPLAY = 300,                /* tDISPLAY  */
    tUNDISPLAY = 301,              /* tUNDISPLAY  */
    tDISASSEMBLE = 302,            /* tDISASSEMBLE  */
    tSYSTEM = 303,                 /* tSYSTEM  */
    tSTEPI = 304,                  /* tSTEPI  */
    tNEXTI = 305,                  /* tNEXTI  */
    tFINISH = 306,                 /* tFINISH  */
    tSHOW = 307,                   /* tSHOW  */
    tDIR = 308,                    /* tDIR  */
    tWHATIS = 309,                 /* tWHATIS  */
    tSOURCE = 310,                 /* tSOURCE  */
    tPATH = 311,                   /* tPATH  */
    tIDENTIFIER = 312,             /* tIDENTIFIER  */
    tSTRING = 313,                 /* tSTRING  */
    tINTVAR = 314,                 /* tINTVAR  */
    tNUM = 315,                    /* tNUM  */
    tFORMAT = 316,                 /* tFORMAT  */
    tTYPEDEF = 317,                /* tTYPEDEF  */
    tSYMBOLFILE = 318,             /* tSYMBOLFILE  */
    tEXECFILE = 319,               /* tEXECFILE  */
    tRUN = 320,                    /* tRUN  */
    tATTACH = 321,                 /* tATTACH  */
    tDETACH = 322,                 /* tDETACH  */
    tKILL = 323,                   /* tKILL  */
    tMAINTENANCE = 324,            /* tMAINTENANCE  */
    tTYPE = 325,                   /* tTYPE  */
    tMINIDUMP = 326,               /* tMINIDUMP  */
    tNOPROCESS = 327,              /* tNOPROCESS  */
    tWOW = 328,                    /* tWOW  */
    tVOID = 329,                   /* tVOID  */
    tCHAR = 330,                   /* tCHAR  */
    tWCHAR = 331,                  /* tWCHAR  */
    tSHORT = 332,                  /* tSHORT  */
    tINT = 333,                    /* tINT  */
    tLONG = 334,                   /* tLONG  */
    tFLOAT = 335,                  /* tFLOAT  */
    tDOUBLE = 336,                 /* tDOUBLE  */
    tUNSIGNED = 337,               /* tUNSIGNED  */
    tSIGNED = 338,                 /* tSIGNED  */
    tSTRUCT = 339,                 /* tSTRUCT  */
    tUNION = 340,                  /* tUNION  */
    tENUM = 341,                   /* tENUM  */
    OP_LOR = 342,                  /* OP_LOR  */
    OP_LAND = 343,                 /* OP_LAND  */
    OP_EQ = 344,                   /* OP_EQ  */
    OP_NE = 345,                   /* OP_NE  */
    OP_LE = 346,                   /* OP_LE  */
    OP_GE = 347,                   /* OP_GE  */
    OP_SHL = 348,                  /* OP_SHL  */
    OP_SHR = 349,                  /* OP_SHR  */
    OP_SIGN = 350,                 /* OP_SIGN  */
    OP_DEREF = 351,                /* OP_DEREF  */
    OP_DRF = 352                   /* OP_DRF  */
  };
  typedef enum dbg_tokentype dbg_token_kind_t;
#endif

/* Value type.  */
#if ! defined DBG_STYPE && ! defined DBG_STYPE_IS_DECLARED
union DBG_STYPE
{
#line 41 "programs/winedbg/dbg.y"

    struct dbg_lvalue   lvalue;
    char*               string;
    dbg_lgint_t         integer;
    IMAGEHLP_LINE64     listing;
    struct expr*        expression;
    struct dbg_type     type;
    struct list_string* strings;

#line 278 "programs/winedbg/dbg.tab.c"

};
typedef union DBG_STYPE DBG_STYPE;
# define DBG_STYPE_IS_TRIVIAL 1
# define DBG_STYPE_IS_DECLARED 1
#endif


extern DBG_STYPE dbg_lval;


int dbg_parse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tCONT = 3,                      /* tCONT  */
  YYSYMBOL_tPASS = 4,                      /* tPASS  */
  YYSYMBOL_tSTEP = 5,                      /* tSTEP  */
  YYSYMBOL_tLIST = 6,                      /* tLIST  */
  YYSYMBOL_tNEXT = 7,                      /* tNEXT  */
  YYSYMBOL_tQUIT = 8,                      /* tQUIT  */
  YYSYMBOL_tHELP = 9,                      /* tHELP  */
  YYSYMBOL_tBACKTRACE = 10,                /* tBACKTRACE  */
  YYSYMBOL_tALL = 11,                      /* tALL  */
  YYSYMBOL_tINFO = 12,                     /* tINFO  */
  YYSYMBOL_tUP = 13,                       /* tUP  */
  YYSYMBOL_tDOWN = 14,                     /* tDOWN  */
  YYSYMBOL_tENABLE = 15,                   /* tENABLE  */
  YYSYMBOL_tDISABLE = 16,                  /* tDISABLE  */
  YYSYMBOL_tBREAK = 17,                    /* tBREAK  */
  YYSYMBOL_tHBREAK = 18,                   /* tHBREAK  */
  YYSYMBOL_tWATCH = 19,                    /* tWATCH  */
  YYSYMBOL_tRWATCH = 20,                   /* tRWATCH  */
  YYSYMBOL_tDELETE = 21,                   /* tDELETE  */
  YYSYMBOL_tSET = 22,                      /* tSET  */
  YYSYMBOL_tPRINT = 23,                    /* tPRINT  */
  YYSYMBOL_tEXAM = 24,                     /* tEXAM  */
  YYSYMBOL_tABORT = 25,                    /* tABORT  */
  YYSYMBOL_tECHO = 26,                     /* tECHO  */
  YYSYMBOL_tCLASS = 27,                    /* tCLASS  */
  YYSYMBOL_tMAPS = 28,                     /* tMAPS  */
  YYSYMBOL_tSTACK = 29,                    /* tSTACK  */
  YYSYMBOL_tSEGMENTS = 30,                 /* tSEGMENTS  */
  YYSYMBOL_tSYMBOL = 31,                   /* tSYMBOL  */
  YYSYMBOL_tREGS = 32,                     /* tREGS  */
  YYSYMBOL_tALLREGS = 33,                  /* tALLREGS  */
  YYSYMBOL_tWND = 34,                      /* tWND  */
  YYSYMBOL_tLOCAL = 35,                    /* tLOCAL  */
  YYSYMBOL_tEXCEPTION = 36,                /* tEXCEPTION  */
  YYSYMBOL_tPROCESS = 37,                  /* tPROCESS  */
  YYSYMBOL_tTHREAD = 38,                   /* tTHREAD  */
  YYSYMBOL_tEOL = 39,                      /* tEOL  */
  YYSYMBOL_tEOF = 40,                      /* tEOF  */
  YYSYMBOL_tFRAME = 41,                    /* tFRAME  */
  YYSYMBOL_tSHARE = 42,                    /* tSHARE  */
  YYSYMBOL_tMODULE = 43,                   /* tMODULE  */
  YYSYMBOL_tCOND = 44,                     /* tCOND  */
  YYSYMBOL_tDISPLAY = 45,                  /* tDISPLAY  */
  YYSYMBOL_tUNDISPLAY = 46,                /* tUNDISPLAY  */
  YYSYMBOL_tDISASSEMBLE = 47,              /* tDISASSEMBLE  */
  YYSYMBOL_tSYSTEM = 48,                   /* tSYSTEM  */
  YYSYMBOL_tSTEPI = 49,                    /* tSTEPI  */
  YYSYMBOL_tNEXTI = 50,                    /* tNEXTI  */
  YYSYMBOL_tFINISH = 51,                   /* tFINISH  */
  YYSYMBOL_tSHOW = 52,                     /* tSHOW  */
  YYSYMBOL_tDIR = 53,                      /* tDIR  */
  YYSYMBOL_tWHATIS = 54,                   /* tWHATIS  */
  YYSYMBOL_tSOURCE = 55,                   /* tSOURCE  */
  YYSYMBOL_tPATH = 56,                     /* tPATH  */
  YYSYMBOL_tIDENTIFIER = 57,               /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 58,                   /* tSTRING  */
  YYSYMBOL_tINTVAR = 59,                   /* tINTVAR  */
  YYSYMBOL_tNUM = 60,                      /* tNUM  */
  YYSYMBOL_tFORMAT = 61,                   /* tFORMAT  */
  YYSYMBOL_tTYPEDEF = 62,                  /* tTYPEDEF  */
  YYSYMBOL_tSYMBOLFILE = 63,               /* tSYMBOLFILE  */
  YYSYMBOL_tEXECFILE = 64,                 /* tEXECFILE  */
  YYSYMBOL_tRUN = 65,                      /* tRUN  */
  YYSYMBOL_tATTACH = 66,                   /* tATTACH  */
  YYSYMBOL_tDETACH = 67,                   /* tDETACH  */
  YYSYMBOL_tKILL = 68,                     /* tKILL  */
  YYSYMBOL_tMAINTENANCE = 69,              /* tMAINTENANCE  */
  YYSYMBOL_tTYPE = 70,                     /* tTYPE  */
  YYSYMBOL_tMINIDUMP = 71,                 /* tMINIDUMP  */
  YYSYMBOL_tNOPROCESS = 72,                /* tNOPROCESS  */
  YYSYMBOL_tWOW = 73,                      /* tWOW  */
  YYSYMBOL_tVOID = 74,                     /* tVOID  */
  YYSYMBOL_tCHAR = 75,                     /* tCHAR  */
  YYSYMBOL_tWCHAR = 76,                    /* tWCHAR  */
  YYSYMBOL_tSHORT = 77,                    /* tSHORT  */
  YYSYMBOL_tINT = 78,                      /* tINT  */
  YYSYMBOL_tLONG = 79,                     /* tLONG  */
  YYSYMBOL_tFLOAT = 80,                    /* tFLOAT  */
  YYSYMBOL_tDOUBLE = 81,                   /* tDOUBLE  */
  YYSYMBOL_tUNSIGNED = 82,                 /* tUNSIGNED  */
  YYSYMBOL_tSIGNED = 83,                   /* tSIGNED  */
  YYSYMBOL_tSTRUCT = 84,                   /* tSTRUCT  */
  YYSYMBOL_tUNION = 85,                    /* tUNION  */
  YYSYMBOL_tENUM = 86,                     /* tENUM  */
  YYSYMBOL_OP_LOR = 87,                    /* OP_LOR  */
  YYSYMBOL_OP_LAND = 88,                   /* OP_LAND  */
  YYSYMBOL_89_ = 89,                       /* '|'  */
  YYSYMBOL_90_ = 90,                       /* '^'  */
  YYSYMBOL_91_ = 91,                       /* '&'  */
  YYSYMBOL_OP_EQ = 92,                     /* OP_EQ  */
  YYSYMBOL_OP_NE = 93,                     /* OP_NE  */
  YYSYMBOL_94_ = 94,                       /* '<'  */
  YYSYMBOL_95_ = 95,                       /* '>'  */
  YYSYMBOL_OP_LE = 96,                     /* OP_LE  */
  YYSYMBOL_OP_GE = 97,                     /* OP_GE  */
  YYSYMBOL_OP_SHL = 98,                    /* OP_SHL  */
  YYSYMBOL_OP_SHR = 99,                    /* OP_SHR  */
  YYSYMBOL_100_ = 100,                     /* '+'  */
  YYSYMBOL_101_ = 101,                     /* '-'  */
  YYSYMBOL_102_ = 102,                     /* '*'  */
  YYSYMBOL_103_ = 103,                     /* '/'  */
  YYSYMBOL_104_ = 104,                     /* '%'  */
  YYSYMBOL_OP_SIGN = 105,                  /* OP_SIGN  */
  YYSYMBOL_106_ = 106,                     /* '!'  */
  YYSYMBOL_107_ = 107,                     /* '~'  */
  YYSYMBOL_OP_DEREF = 108,                 /* OP_DEREF  */
  YYSYMBOL_109_ = 109,                     /* '.'  */
  YYSYMBOL_110_ = 110,                     /* '['  */
  YYSYMBOL_OP_DRF = 111,                   /* OP_DRF  */
  YYSYMBOL_112_ = 112,                     /* ':'  */
  YYSYMBOL_113_ = 113,                     /* ','  */
  YYSYMBOL_114_ = 114,                     /* '='  */
  YYSYMBOL_115_ = 115,                     /* '('  */
  YYSYMBOL_116_ = 116,                     /* ')'  */
  YYSYMBOL_117_ = 117,                     /* ']'  */
  YYSYMBOL_YYACCEPT = 118,                 /* $accept  */
  YYSYMBOL_input = 119,                    /* input  */
  YYSYMBOL_line = 120,                     /* line  */
  YYSYMBOL_command = 121,                  /* command  */
  YYSYMBOL_pathname = 122,                 /* pathname  */
  YYSYMBOL_identifier = 123,               /* identifier  */
  YYSYMBOL_list_arg = 124,                 /* list_arg  */
  YYSYMBOL_run_command = 125,              /* run_command  */
  YYSYMBOL_list_of_words = 126,            /* list_of_words  */
  YYSYMBOL_list_command = 127,             /* list_command  */
  YYSYMBOL_disassemble_command = 128,      /* disassemble_command  */
  YYSYMBOL_set_command = 129,              /* set_command  */
  YYSYMBOL_x_command = 130,                /* x_command  */
  YYSYMBOL_print_command = 131,            /* print_command  */
  YYSYMBOL_break_command = 132,            /* break_command  */
  YYSYMBOL_watch_command = 133,            /* watch_command  */
  YYSYMBOL_display_command = 134,          /* display_command  */
  YYSYMBOL_info_command = 135,             /* info_command  */
  YYSYMBOL_maintenance_command = 136,      /* maintenance_command  */
  YYSYMBOL_noprocess_state = 137,          /* noprocess_state  */
  YYSYMBOL_type_expr = 138,                /* type_expr  */
  YYSYMBOL_expr_lvalue = 139,              /* expr_lvalue  */
  YYSYMBOL_expr_rvalue = 140,              /* expr_rvalue  */
  YYSYMBOL_expr = 141,                     /* expr  */
  YYSYMBOL_lvalue_addr = 142,              /* lvalue_addr  */
  YYSYMBOL_lvalue = 143                    /* lvalue  */
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
         || (defined DBG_STYPE_IS_TRIVIAL && DBG_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  190
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   989

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  252
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  366

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   352


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
       2,     2,     2,   106,     2,     2,     2,   104,    91,     2,
     115,   116,   102,   100,   113,   101,   109,   103,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   112,     2,
      94,   114,    95,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   110,     2,   117,    90,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    89,     2,   107,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    92,    93,    96,    97,    98,    99,
     105,   108,   111
};

#if DBG_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,    99,   103,   104,   105,   106,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   166,   167,   168,   172,   176,   177,   178,   179,   180,
     186,   190,   191,   195,   196,   197,   198,   199,   203,   204,
     205,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   223,   224,   228,   229,   230,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   253,   254,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   301,   302,   303,   307,   308,   309,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   362,   366,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   423,   427,   428,   429,   430,
     431,   432,   433
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if DBG_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tCONT", "tPASS",
  "tSTEP", "tLIST", "tNEXT", "tQUIT", "tHELP", "tBACKTRACE", "tALL",
  "tINFO", "tUP", "tDOWN", "tENABLE", "tDISABLE", "tBREAK", "tHBREAK",
  "tWATCH", "tRWATCH", "tDELETE", "tSET", "tPRINT", "tEXAM", "tABORT",
  "tECHO", "tCLASS", "tMAPS", "tSTACK", "tSEGMENTS", "tSYMBOL", "tREGS",
  "tALLREGS", "tWND", "tLOCAL", "tEXCEPTION", "tPROCESS", "tTHREAD",
  "tEOL", "tEOF", "tFRAME", "tSHARE", "tMODULE", "tCOND", "tDISPLAY",
  "tUNDISPLAY", "tDISASSEMBLE", "tSYSTEM", "tSTEPI", "tNEXTI", "tFINISH",
  "tSHOW", "tDIR", "tWHATIS", "tSOURCE", "tPATH", "tIDENTIFIER", "tSTRING",
  "tINTVAR", "tNUM", "tFORMAT", "tTYPEDEF", "tSYMBOLFILE", "tEXECFILE",
  "tRUN", "tATTACH", "tDETACH", "tKILL", "tMAINTENANCE", "tTYPE",
  "tMINIDUMP", "tNOPROCESS", "tWOW", "tVOID", "tCHAR", "tWCHAR", "tSHORT",
  "tINT", "tLONG", "tFLOAT", "tDOUBLE", "tUNSIGNED", "tSIGNED", "tSTRUCT",
  "tUNION", "tENUM", "OP_LOR", "OP_LAND", "'|'", "'^'", "'&'", "OP_EQ",
  "OP_NE", "'<'", "'>'", "OP_LE", "OP_GE", "OP_SHL", "OP_SHR", "'+'",
  "'-'", "'*'", "'/'", "'%'", "OP_SIGN", "'!'", "'~'", "OP_DEREF", "'.'",
  "'['", "OP_DRF", "':'", "','", "'='", "'('", "')'", "']'", "$accept",
  "input", "line", "command", "pathname", "identifier", "list_arg",
  "run_command", "list_of_words", "list_command", "disassemble_command",
  "set_command", "x_command", "print_command", "break_command",
  "watch_command", "display_command", "info_command",
  "maintenance_command", "noprocess_state", "type_expr", "expr_lvalue",
  "expr_rvalue", "expr", "lvalue_addr", "lvalue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-104)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     447,    -7,   -19,   -97,     5,    45,    14,   -97,    26,    -8,
      82,    16,    24,    23,    25,    84,   116,   130,   130,    37,
      69,   200,   446,   -97,    30,    38,   -97,   -97,    44,    47,
     463,    83,   130,    85,   107,   -97,   -27,    76,   130,    76,
      76,    76,    80,   103,   -97,   -97,   -36,    76,     0,   375,
     -97,   129,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   130,   121,   -49,    68,    70,   -97,   -97,   -97,
     -97,   -97,   124,   130,   125,   130,   135,   -97,   -97,   130,
     -97,   -97,   -97,   -97,   130,   130,   -97,   -97,   171,   181,
     -97,   -97,   157,   159,   -97,   160,   162,   -97,   -97,   130,
     114,   189,   -97,   130,   126,   208,   -97,   -97,   -97,   130,
     130,   130,   130,   130,   130,   262,   136,   -97,   734,   -97,
     179,   193,   -97,   -20,   -97,   -97,     3,     4,   130,   197,
     -97,   141,    40,   210,   130,   -97,   -97,   -97,   -97,   -32,
     -97,   -34,   -97,   -97,   -22,    87,   210,   210,   210,   167,
     -97,   130,   -97,   -97,   -97,   -97,   130,   130,   734,   -97,
     158,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   130,   -97,
      80,   -97,   -97,   -97,   212,   -97,   229,   -97,   276,   -97,
     -97,   -97,   -97,   -97,   -97,   -33,   121,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   130,   -97,   -97,
     -97,   -97,   -97,   228,   -97,   230,   154,   154,   154,   154,
     154,   154,   -96,   674,   -29,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   235,   130,   236,   130,   -97,   -97,     7,
      10,   -97,   -97,   -97,   -97,   734,   237,   130,   238,   130,
     239,   -97,   -97,   -97,   219,   220,   -97,    -3,   -97,   221,
     225,   -97,   226,   -97,    43,   -97,   227,   -97,    78,   -97,
     -97,   -97,   -97,   -97,   734,   734,   130,   -97,   -97,   -97,
     250,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   130,   -97,
     -97,   554,   759,   783,   806,   828,   849,   431,   431,   864,
     864,   864,   864,   877,   877,   131,   131,   154,   154,   154,
     -97,   492,   -97,   198,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   523,   -97,   -97,   -97,   -97,   231,   -97,   -97,   -97,
     -97,   233,   -97,   -97,   234,   -97,   -97,   154,   130,   -97,
     -97,   -97,   -97,   -97,   -97,   584,   130,   -97,   614,   130,
     -97,   644,   130,   -97,   704,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    11,    14,    73,    16,     8,     9,    24,
       0,    27,    29,     0,     0,   101,   106,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     5,     6,     0,     0,
     115,   123,    78,    18,    20,    22,     0,    34,     0,     0,
       0,     0,    71,     0,    43,    45,     0,     0,   154,     0,
       2,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     7,    13,    15,    63,    64,    62,
      65,    74,     0,     0,     0,    67,    75,    17,    10,    26,
      25,   124,   137,   147,   133,   131,     0,   128,   129,   139,
     135,   149,   143,   144,   145,   125,   136,   150,     0,     0,
      28,    30,     0,     0,   107,     0,     0,   109,   100,     0,
       0,    61,   105,     0,     0,    61,   206,   207,   205,     0,
       0,     0,     0,     0,     0,     0,   208,   113,   203,   114,
       0,   121,   111,    64,   247,   246,     0,     0,     0,     0,
     248,     0,   245,     0,     0,   197,   157,   158,   159,   163,
     172,   176,   194,   195,   174,     0,     0,     0,     0,    96,
      94,     0,    92,    47,    44,    31,    35,     0,   116,   122,
      79,    19,    21,    32,    33,    61,    40,    37,    38,    48,
      71,    70,    41,    42,     0,   151,     0,    46,     0,   156,
       1,     3,     4,    69,    76,     0,     0,   138,   204,   148,
     132,   130,   134,   140,   146,   127,   126,   141,   108,   118,
     110,   119,    97,     0,   102,     0,   243,   238,   237,   242,
     239,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   120,     0,
       0,    83,    82,    85,    84,   252,    91,     0,     0,     0,
       0,   199,    95,   162,   168,   167,   177,   186,   196,   182,
     180,   161,   170,   175,   184,   160,   165,   173,   178,   200,
     201,   202,   198,    93,    36,   117,     0,    39,    72,   152,
       0,   155,    66,    68,    77,   142,    99,   104,     0,   241,
     211,     0,   219,   220,   221,   223,   222,   224,   229,   226,
     225,   228,   227,   230,   231,   232,   233,   234,   235,   236,
     210,     0,   209,   218,    87,    86,    89,    88,    90,    81,
     250,     0,   249,   169,   166,   187,   192,   183,   181,   171,
     185,   190,   164,   179,   188,    80,   153,   244,     0,   212,
     217,   251,   193,   191,   189,     0,     0,   213,     0,     0,
     214,     0,     0,   215,     0,   216
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   264,   -97,   209,    -4,   -71,   -97,   134,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     191,   -13,   -72,   -30,   -97,   -97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    49,    50,    51,    74,   126,    76,    52,   181,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     159,   198,   199,   128,   141,   142
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     168,    75,   194,    79,   127,   129,   282,   184,   160,   162,
     188,   111,   115,   201,   251,   253,   140,   203,   324,   170,
     298,   326,   204,   205,    68,   176,   173,   292,    68,   116,
     117,   118,    64,   175,   185,   175,   175,   175,    78,   175,
     102,    65,   105,   175,   266,   267,   263,   268,   269,   270,
     264,   265,    80,   271,   130,   272,   273,   274,   189,   193,
     252,   254,   119,   195,   325,    66,   186,   327,   103,    75,
     106,   120,   121,   122,    77,   335,   100,   123,   124,   336,
     249,   250,   131,   104,   101,   107,   125,   300,   163,   216,
     217,   218,   219,   220,   221,   223,   212,   132,   164,    81,
     214,    67,    68,    69,   165,    70,   287,   166,   255,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   340,   341,    94,    95,   294,   133,    96,   134,   135,
      97,   262,    67,    68,    69,   295,   284,   285,   180,   261,
      67,    68,    69,   169,   108,   171,    71,    72,   283,   258,
     259,   260,   279,   280,   281,    98,   343,   344,    73,    67,
      68,    69,   275,   182,   276,   277,   278,   172,   192,   136,
     137,   138,    67,    68,    69,   139,   112,    67,    68,    69,
     -61,    70,   197,   196,    99,   200,   109,    68,   116,   117,
     118,   293,    75,   202,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   206,   321,   207,   323,   208,   113,   209,
     210,   119,   211,    72,   110,   114,   213,   143,   -98,   331,
     120,   121,   122,   240,   241,   242,   123,   124,   215,   247,
     243,   244,   245,   246,   329,   125,   174,  -103,   177,   178,
     179,   224,   183,   248,   256,   257,   187,    68,   116,   117,
     118,   144,   145,   243,   244,   245,   246,    68,   347,   282,
     289,   286,   290,   345,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   291,   296,   143,
     297,   119,   320,   322,   328,   330,   332,   333,   334,   337,
     120,   121,   122,   338,   339,   342,   123,   124,   346,   352,
    -104,   353,   354,   191,   288,   125,   222,     0,   355,    68,
     116,   117,   118,     0,   145,     0,   358,     0,     0,   361,
       0,     0,   364,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,     0,     0,     0,   123,   124,
       0,     0,     0,     0,     0,   190,     1,   125,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,     0,     0,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,     0,     0,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,     0,
       0,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    68,   116,   117,   118,   161,     0,     0,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      68,   116,   117,   118,   167,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   119,     0,     0,
     243,   244,   245,   246,     0,     0,   120,   121,   122,     0,
       0,     0,   123,   124,   119,     0,     0,     0,     0,     0,
       0,   125,     0,   120,   121,   122,     0,     0,     0,   123,
     124,     0,     0,     0,     0,     0,     0,     0,   125,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   243,   244,   245,   246,     0,     0,     0,     0,   350,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       0,     0,   243,   244,   245,   246,     0,     0,     0,     0,
     351,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,   348,     0,     0,
     349,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,   356,     0,     0,
     357,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,   359,     0,     0,
     360,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,   362,     0,     0,
     363,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,     0,     0,     0,
     299,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,     0,     0,     0,
     365,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,   243,   244,
     245,   246,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       0,     0,   243,   244,   245,   246,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,   243,   244,   245,   246,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,   243,   244,   245,
     246,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,   243,   244,
     245,   246,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,   245,   246,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   243,   244,   245,   246
};

static const yytype_int16 yycheck[] =
{
      30,     5,    73,    11,    17,    18,   102,    43,    21,    22,
      10,    15,    16,    85,    11,    11,    20,    89,    11,    32,
     116,    11,    94,    95,    57,    38,    53,    60,    57,    58,
      59,    60,    39,    37,    70,    39,    40,    41,    12,    43,
      17,    60,    17,    47,    78,    79,    78,    81,    82,    83,
      82,    83,    60,    75,    17,    77,    78,    79,    58,    72,
      57,    57,    91,   112,    57,    60,   102,    57,    45,    73,
      45,   100,   101,   102,    60,    78,    60,   106,   107,    82,
     100,   101,    45,    60,    60,    60,   115,   116,    58,   119,
     120,   121,   122,   123,   124,   125,   109,    60,    60,    17,
     113,    56,    57,    58,    60,    60,   178,    60,   138,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    78,    79,    41,    42,   196,    57,    45,    59,    60,
      48,   144,    56,    57,    58,   207,   166,   167,    58,   143,
      56,    57,    58,    60,    60,    60,   101,   102,   161,   109,
     110,   111,   156,   157,   158,    73,    78,    79,   113,    56,
      57,    58,    75,    60,    77,    78,    79,    60,    39,   100,
     101,   102,    56,    57,    58,   106,    60,    56,    57,    58,
     112,    60,    58,   113,   102,    60,   102,    57,    58,    59,
      60,   195,   196,    58,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    42,   244,    34,   246,    60,   102,    60,
      60,    91,    60,   102,    15,    16,   112,    27,    39,   259,
     100,   101,   102,   102,   103,   104,   106,   107,   112,    60,
     109,   110,   111,   112,   257,   115,    37,    39,    39,    40,
      41,   115,    43,    60,    57,   114,    47,    57,    58,    59,
      60,    61,    62,   109,   110,   111,   112,    57,   298,   102,
      58,   113,    43,   286,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    11,    60,    27,
      60,    91,    57,    57,    57,    57,    57,    78,    78,    78,
     100,   101,   102,    78,    78,    78,   106,   107,    58,    78,
     112,    78,    78,    49,   180,   115,   125,    -1,   348,    57,
      58,    59,    60,    -1,    62,    -1,   356,    -1,    -1,   359,
      -1,    -1,   362,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,    -1,     0,     1,   115,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    55,    57,    58,    59,    60,    61,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      57,    58,    59,    60,    61,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    91,    -1,    -1,
     109,   110,   111,   112,    -1,    -1,   100,   101,   102,    -1,
      -1,    -1,   106,   107,    91,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,    -1,
     116,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,    -1,
     116,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,    -1,
     116,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,    -1,
     116,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,
     116,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,
     116,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    38,    39,    40,    41,    44,
      45,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      63,    64,    65,    66,    67,    68,    69,    71,    72,   119,
     120,   121,   125,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    39,    60,    60,    56,    57,    58,
      60,   101,   102,   113,   122,   123,   124,    60,    12,    11,
      60,    17,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    41,    42,    45,    48,    73,   102,
      60,    60,    17,    45,    60,    17,    45,    60,    60,   102,
     122,   123,    60,   102,   122,   123,    58,    59,    60,    91,
     100,   101,   102,   106,   107,   115,   123,   139,   141,   139,
      17,    45,    60,    57,    59,    60,   100,   101,   102,   106,
     123,   142,   143,    27,    61,    62,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   138,
     139,    61,   139,    58,    60,    60,    60,    61,   141,    60,
     139,    60,    60,    53,   122,   123,   139,   122,   122,   122,
      58,   126,    60,   122,    43,    70,   102,   122,    10,    58,
       0,   120,    39,   139,   124,   112,   113,    58,   139,   140,
      60,   140,    58,   140,   140,   140,    42,    34,    60,    60,
      60,    60,   139,   112,   139,   112,   141,   141,   141,   141,
     141,   141,   138,   141,   115,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   109,   110,   111,   112,    60,    60,   100,
     101,    11,    57,    11,    57,   141,    57,   114,   109,   110,
     111,   123,   139,    78,    82,    83,    78,    79,    81,    82,
      83,    75,    77,    78,    79,    75,    77,    78,    79,   123,
     123,   123,   102,   139,   141,   141,   113,   140,   126,    58,
      43,    11,    60,   123,   124,   140,    60,    60,   116,   116,
     116,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
      57,   141,    57,   141,    11,    57,    11,    57,    57,   139,
      57,   141,    57,    78,    78,    78,    82,    78,    78,    78,
      78,    79,    78,    78,    79,   139,    58,   141,   113,   116,
     117,   117,    78,    78,    78,   141,   113,   116,   141,   113,
     116,   141,   113,   116,   141,   116
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   119,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   122,   123,   124,   124,   124,   124,   124,
     125,   126,   126,   127,   127,   127,   127,   127,   128,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   130,   130,   131,   131,   131,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   136,   136,   136,   137,   137,   137,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   139,   140,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   142,   143,   143,   143,   143,
     143,   143,   143
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     1,     1,
       2,     1,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     2,     2,     1,     2,     1,
       2,     2,     2,     2,     1,     2,     3,     2,     2,     3,
       2,     2,     2,     1,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       2,     0,     2,     1,     2,     2,     3,     4,     1,     2,
       4,     4,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     3,     2,     3,     2,     3,     2,     3,     2,     4,
       2,     1,     3,     2,     4,     2,     1,     2,     3,     2,
       3,     2,     3,     2,     2,     1,     2,     3,     3,     3,
       3,     2,     2,     1,     2,     2,     3,     3,     2,     2,
       3,     2,     3,     2,     3,     2,     2,     2,     3,     2,
       3,     3,     4,     2,     2,     2,     3,     2,     3,     2,
       2,     2,     3,     4,     1,     3,     2,     1,     1,     1,
       2,     2,     2,     1,     3,     2,     3,     2,     2,     3,
       2,     3,     1,     2,     1,     2,     1,     2,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     3,     4,
       3,     4,     3,     4,     1,     1,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     4,     6,     8,    10,    12,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     2,     2,     4,     1,     1,     1,     1,     3,
       3,     4,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = DBG_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == DBG_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use DBG_error or DBG_UNDEF. */
#define YYERRCODE DBG_UNDEF


/* Enable debugging if requested.  */
#if DBG_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !DBG_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !DBG_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = DBG_EMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yychar == DBG_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= DBG_EOF)
    {
      yychar = DBG_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == DBG_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = DBG_UNDEF;
      yytoken = YYSYMBOL_YYerror;
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

  /* Discard the shifted token.  */
  yychar = DBG_EMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* line: command tEOL  */
#line 103 "programs/winedbg/dbg.y"
                                { expr_free_all(); }
#line 1800 "programs/winedbg/dbg.tab.c"
    break;

  case 6: /* line: tEOF  */
#line 105 "programs/winedbg/dbg.y"
                                { return 1; }
#line 1806 "programs/winedbg/dbg.tab.c"
    break;

  case 7: /* line: error tEOL  */
#line 106 "programs/winedbg/dbg.y"
                                { yyerrok; expr_free_all(); }
#line 1812 "programs/winedbg/dbg.tab.c"
    break;

  case 8: /* command: tQUIT  */
#line 110 "programs/winedbg/dbg.y"
                                { return 1; }
#line 1818 "programs/winedbg/dbg.tab.c"
    break;

  case 9: /* command: tHELP  */
#line 111 "programs/winedbg/dbg.y"
                                { print_help(); }
#line 1824 "programs/winedbg/dbg.tab.c"
    break;

  case 10: /* command: tHELP tINFO  */
#line 112 "programs/winedbg/dbg.y"
                                { info_help(); }
#line 1830 "programs/winedbg/dbg.tab.c"
    break;

  case 11: /* command: tPASS  */
#line 113 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_EXCEPTION_NOT_HANDLED, 0, 0); }
#line 1836 "programs/winedbg/dbg.tab.c"
    break;

  case 12: /* command: tCONT  */
#line 114 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, 1,  dbg_exec_cont); }
#line 1842 "programs/winedbg/dbg.tab.c"
    break;

  case 13: /* command: tCONT tNUM  */
#line 115 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, (yyvsp[0].integer), dbg_exec_cont); }
#line 1848 "programs/winedbg/dbg.tab.c"
    break;

  case 14: /* command: tSTEP  */
#line 116 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, 1,  dbg_exec_step_into_line); }
#line 1854 "programs/winedbg/dbg.tab.c"
    break;

  case 15: /* command: tSTEP tNUM  */
#line 117 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, (yyvsp[0].integer), dbg_exec_step_into_line); }
#line 1860 "programs/winedbg/dbg.tab.c"
    break;

  case 16: /* command: tNEXT  */
#line 118 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, 1,  dbg_exec_step_over_line); }
#line 1866 "programs/winedbg/dbg.tab.c"
    break;

  case 17: /* command: tNEXT tNUM  */
#line 119 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, (yyvsp[0].integer), dbg_exec_step_over_line); }
#line 1872 "programs/winedbg/dbg.tab.c"
    break;

  case 18: /* command: tSTEPI  */
#line 120 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, 1,  dbg_exec_step_into_insn); }
#line 1878 "programs/winedbg/dbg.tab.c"
    break;

  case 19: /* command: tSTEPI tNUM  */
#line 121 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, (yyvsp[0].integer), dbg_exec_step_into_insn); }
#line 1884 "programs/winedbg/dbg.tab.c"
    break;

  case 20: /* command: tNEXTI  */
#line 122 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, 1,  dbg_exec_step_over_insn); }
#line 1890 "programs/winedbg/dbg.tab.c"
    break;

  case 21: /* command: tNEXTI tNUM  */
#line 123 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, (yyvsp[0].integer), dbg_exec_step_over_insn); }
#line 1896 "programs/winedbg/dbg.tab.c"
    break;

  case 22: /* command: tFINISH  */
#line 124 "programs/winedbg/dbg.y"
                                { dbg_wait_next_exception(DBG_CONTINUE, 0,  dbg_exec_finish); }
#line 1902 "programs/winedbg/dbg.tab.c"
    break;

  case 23: /* command: tABORT  */
#line 125 "programs/winedbg/dbg.y"
                                { abort(); }
#line 1908 "programs/winedbg/dbg.tab.c"
    break;

  case 24: /* command: tBACKTRACE  */
#line 126 "programs/winedbg/dbg.y"
                                { stack_backtrace(dbg_curr_tid); }
#line 1914 "programs/winedbg/dbg.tab.c"
    break;

  case 25: /* command: tBACKTRACE tNUM  */
#line 127 "programs/winedbg/dbg.y"
                                { stack_backtrace((yyvsp[0].integer)); }
#line 1920 "programs/winedbg/dbg.tab.c"
    break;

  case 26: /* command: tBACKTRACE tALL  */
#line 128 "programs/winedbg/dbg.y"
                                { stack_backtrace(-1); }
#line 1926 "programs/winedbg/dbg.tab.c"
    break;

  case 27: /* command: tUP  */
#line 129 "programs/winedbg/dbg.y"
                                { stack_set_frame(dbg_curr_thread->curr_frame + 1);  }
#line 1932 "programs/winedbg/dbg.tab.c"
    break;

  case 28: /* command: tUP tNUM  */
#line 130 "programs/winedbg/dbg.y"
                                { stack_set_frame(dbg_curr_thread->curr_frame + (yyvsp[0].integer)); }
#line 1938 "programs/winedbg/dbg.tab.c"
    break;

  case 29: /* command: tDOWN  */
#line 131 "programs/winedbg/dbg.y"
                                { stack_set_frame(dbg_curr_thread->curr_frame - 1);  }
#line 1944 "programs/winedbg/dbg.tab.c"
    break;

  case 30: /* command: tDOWN tNUM  */
#line 132 "programs/winedbg/dbg.y"
                                { stack_set_frame(dbg_curr_thread->curr_frame - (yyvsp[0].integer)); }
#line 1950 "programs/winedbg/dbg.tab.c"
    break;

  case 31: /* command: tFRAME tNUM  */
#line 133 "programs/winedbg/dbg.y"
                                { stack_set_frame((yyvsp[0].integer)); }
#line 1956 "programs/winedbg/dbg.tab.c"
    break;

  case 32: /* command: tSHOW tDIR  */
#line 134 "programs/winedbg/dbg.y"
                                { source_show_path(); }
#line 1962 "programs/winedbg/dbg.tab.c"
    break;

  case 33: /* command: tDIR pathname  */
#line 135 "programs/winedbg/dbg.y"
                                { source_add_path((yyvsp[0].string)); }
#line 1968 "programs/winedbg/dbg.tab.c"
    break;

  case 34: /* command: tDIR  */
#line 136 "programs/winedbg/dbg.y"
                                { source_nuke_path(dbg_curr_process); }
#line 1974 "programs/winedbg/dbg.tab.c"
    break;

  case 35: /* command: tCOND tNUM  */
#line 137 "programs/winedbg/dbg.y"
                                { break_add_condition((yyvsp[0].integer), NULL); }
#line 1980 "programs/winedbg/dbg.tab.c"
    break;

  case 36: /* command: tCOND tNUM expr  */
#line 138 "programs/winedbg/dbg.y"
                                { break_add_condition((yyvsp[-1].integer), (yyvsp[0].expression)); }
#line 1986 "programs/winedbg/dbg.tab.c"
    break;

  case 37: /* command: tSOURCE pathname  */
#line 139 "programs/winedbg/dbg.y"
                                { parser((yyvsp[0].string)); }
#line 1992 "programs/winedbg/dbg.tab.c"
    break;

  case 38: /* command: tSYMBOLFILE pathname  */
#line 140 "programs/winedbg/dbg.y"
                                { symbol_read_symtable((yyvsp[0].string), 0); }
#line 1998 "programs/winedbg/dbg.tab.c"
    break;

  case 39: /* command: tSYMBOLFILE pathname expr_rvalue  */
#line 141 "programs/winedbg/dbg.y"
                                       { symbol_read_symtable((yyvsp[-1].string), (yyvsp[0].integer)); }
#line 2004 "programs/winedbg/dbg.tab.c"
    break;

  case 40: /* command: tWHATIS expr_lvalue  */
#line 142 "programs/winedbg/dbg.y"
                                { dbg_printf("type = "); types_print_type(&(yyvsp[0].lvalue).type, FALSE, NULL); dbg_printf("\n"); }
#line 2010 "programs/winedbg/dbg.tab.c"
    break;

  case 41: /* command: tATTACH tNUM  */
#line 143 "programs/winedbg/dbg.y"
                                { if (dbg_attach_debuggee((yyvsp[0].integer))) dbg_active_wait_for_first_exception(); }
#line 2016 "programs/winedbg/dbg.tab.c"
    break;

  case 42: /* command: tATTACH pathname  */
#line 144 "programs/winedbg/dbg.y"
                                { minidump_reload((yyvsp[0].string)); }
#line 2022 "programs/winedbg/dbg.tab.c"
    break;

  case 43: /* command: tDETACH  */
#line 145 "programs/winedbg/dbg.y"
                                { dbg_curr_process->process_io->close_process(dbg_curr_process, FALSE); }
#line 2028 "programs/winedbg/dbg.tab.c"
    break;

  case 44: /* command: tTHREAD tNUM  */
#line 146 "programs/winedbg/dbg.y"
                                { dbg_set_curr_thread((yyvsp[0].integer)); }
#line 2034 "programs/winedbg/dbg.tab.c"
    break;

  case 45: /* command: tKILL  */
#line 147 "programs/winedbg/dbg.y"
                                { dbg_curr_process->process_io->close_process(dbg_curr_process, TRUE); }
#line 2040 "programs/winedbg/dbg.tab.c"
    break;

  case 46: /* command: tMINIDUMP pathname  */
#line 148 "programs/winedbg/dbg.y"
                                { minidump_write((yyvsp[0].string), (dbg_curr_thread && dbg_curr_thread->in_exception) ? &dbg_curr_thread->excpt_record : NULL); }
#line 2046 "programs/winedbg/dbg.tab.c"
    break;

  case 47: /* command: tECHO tSTRING  */
#line 149 "programs/winedbg/dbg.y"
                                { dbg_printf("%s\n", (yyvsp[0].string)); }
#line 2052 "programs/winedbg/dbg.tab.c"
    break;

  case 48: /* command: tEXECFILE pathname  */
#line 150 "programs/winedbg/dbg.y"
                                { dbg_set_exec_file((yyvsp[0].string)); }
#line 2058 "programs/winedbg/dbg.tab.c"
    break;

  case 61: /* pathname: identifier  */
#line 166 "programs/winedbg/dbg.y"
                                { (yyval.string) = (yyvsp[0].string); }
#line 2064 "programs/winedbg/dbg.tab.c"
    break;

  case 62: /* pathname: tSTRING  */
#line 167 "programs/winedbg/dbg.y"
                                { (yyval.string) = (yyvsp[0].string); }
#line 2070 "programs/winedbg/dbg.tab.c"
    break;

  case 63: /* pathname: tPATH  */
#line 168 "programs/winedbg/dbg.y"
                                { (yyval.string) = (yyvsp[0].string); }
#line 2076 "programs/winedbg/dbg.tab.c"
    break;

  case 64: /* identifier: tIDENTIFIER  */
#line 172 "programs/winedbg/dbg.y"
                               { (yyval.string) = (yyvsp[0].string); }
#line 2082 "programs/winedbg/dbg.tab.c"
    break;

  case 65: /* list_arg: tNUM  */
#line 176 "programs/winedbg/dbg.y"
                                { (yyval.listing).FileName = NULL; (yyval.listing).LineNumber = (yyvsp[0].integer); }
#line 2088 "programs/winedbg/dbg.tab.c"
    break;

  case 66: /* list_arg: pathname ':' tNUM  */
#line 177 "programs/winedbg/dbg.y"
                                { (yyval.listing).FileName = (yyvsp[-2].string); (yyval.listing).LineNumber = (yyvsp[0].integer); }
#line 2094 "programs/winedbg/dbg.tab.c"
    break;

  case 67: /* list_arg: identifier  */
#line 178 "programs/winedbg/dbg.y"
                                { symbol_get_line(NULL, (yyvsp[0].string), &(yyval.listing)); }
#line 2100 "programs/winedbg/dbg.tab.c"
    break;

  case 68: /* list_arg: pathname ':' identifier  */
#line 179 "programs/winedbg/dbg.y"
                                { symbol_get_line((yyvsp[-2].string), (yyvsp[0].string), &(yyval.listing)); }
#line 2106 "programs/winedbg/dbg.tab.c"
    break;

  case 69: /* list_arg: '*' expr_lvalue  */
#line 180 "programs/winedbg/dbg.y"
                                { DWORD disp; ADDRESS64 addr; (yyval.listing).SizeOfStruct = sizeof((yyval.listing));
                                  types_extract_as_address(&(yyvsp[0].lvalue), &addr);
                                  SymGetLineFromAddr64(dbg_curr_process->handle, (ULONG_PTR)memory_to_linear_addr(& addr), &disp, & (yyval.listing)); }
#line 2114 "programs/winedbg/dbg.tab.c"
    break;

  case 70: /* run_command: tRUN list_of_words  */
#line 186 "programs/winedbg/dbg.y"
                                { dbg_run_debuggee((yyvsp[0].strings)); }
#line 2120 "programs/winedbg/dbg.tab.c"
    break;

  case 71: /* list_of_words: %empty  */
#line 190 "programs/winedbg/dbg.y"
                                { (yyval.strings) = NULL; }
#line 2126 "programs/winedbg/dbg.tab.c"
    break;

  case 72: /* list_of_words: tSTRING list_of_words  */
#line 191 "programs/winedbg/dbg.y"
                                { (yyval.strings) = (struct list_string*)lexeme_alloc_size(sizeof(*(yyval.strings))); (yyval.strings)->next = (yyvsp[0].strings); (yyval.strings)->string = (yyvsp[-1].string); }
#line 2132 "programs/winedbg/dbg.tab.c"
    break;

  case 73: /* list_command: tLIST  */
#line 195 "programs/winedbg/dbg.y"
                                { source_list(NULL, NULL, 10); }
#line 2138 "programs/winedbg/dbg.tab.c"
    break;

  case 74: /* list_command: tLIST '-'  */
#line 196 "programs/winedbg/dbg.y"
                                { source_list(NULL,  NULL, -10); }
#line 2144 "programs/winedbg/dbg.tab.c"
    break;

  case 75: /* list_command: tLIST list_arg  */
#line 197 "programs/winedbg/dbg.y"
                                { source_list(& (yyvsp[0].listing), NULL, 10); }
#line 2150 "programs/winedbg/dbg.tab.c"
    break;

  case 76: /* list_command: tLIST ',' list_arg  */
#line 198 "programs/winedbg/dbg.y"
                                { source_list(NULL, & (yyvsp[0].listing), -10); }
#line 2156 "programs/winedbg/dbg.tab.c"
    break;

  case 77: /* list_command: tLIST list_arg ',' list_arg  */
#line 199 "programs/winedbg/dbg.y"
                                       { source_list(& (yyvsp[-2].listing), & (yyvsp[0].listing), 0); }
#line 2162 "programs/winedbg/dbg.tab.c"
    break;

  case 78: /* disassemble_command: tDISASSEMBLE  */
#line 203 "programs/winedbg/dbg.y"
                                { memory_disassemble(NULL, NULL, 10); }
#line 2168 "programs/winedbg/dbg.tab.c"
    break;

  case 79: /* disassemble_command: tDISASSEMBLE expr_lvalue  */
#line 204 "programs/winedbg/dbg.y"
                                { memory_disassemble(&(yyvsp[0].lvalue), NULL, 10); }
#line 2174 "programs/winedbg/dbg.tab.c"
    break;

  case 80: /* disassemble_command: tDISASSEMBLE expr_lvalue ',' expr_lvalue  */
#line 205 "programs/winedbg/dbg.y"
                                               { memory_disassemble(&(yyvsp[-2].lvalue), &(yyvsp[0].lvalue), 0); }
#line 2180 "programs/winedbg/dbg.tab.c"
    break;

  case 81: /* set_command: tSET lvalue_addr '=' expr_lvalue  */
#line 209 "programs/winedbg/dbg.y"
                                       { types_store_value(&(yyvsp[-2].lvalue), &(yyvsp[0].lvalue)); }
#line 2186 "programs/winedbg/dbg.tab.c"
    break;

  case 82: /* set_command: tSET '+' tIDENTIFIER  */
#line 210 "programs/winedbg/dbg.y"
                                { info_wine_dbg_channel(TRUE, NULL, (yyvsp[0].string)); }
#line 2192 "programs/winedbg/dbg.tab.c"
    break;

  case 83: /* set_command: tSET '+' tALL  */
#line 211 "programs/winedbg/dbg.y"
                                { info_wine_dbg_channel(TRUE, NULL, "all"); }
#line 2198 "programs/winedbg/dbg.tab.c"
    break;

  case 84: /* set_command: tSET '-' tIDENTIFIER  */
#line 212 "programs/winedbg/dbg.y"
                                { info_wine_dbg_channel(FALSE, NULL, (yyvsp[0].string)); }
#line 2204 "programs/winedbg/dbg.tab.c"
    break;

  case 85: /* set_command: tSET '-' tALL  */
#line 213 "programs/winedbg/dbg.y"
                                { info_wine_dbg_channel(FALSE, NULL, "all"); }
#line 2210 "programs/winedbg/dbg.tab.c"
    break;

  case 86: /* set_command: tSET tIDENTIFIER '+' tIDENTIFIER  */
#line 214 "programs/winedbg/dbg.y"
                                       { info_wine_dbg_channel(TRUE, (yyvsp[-2].string), (yyvsp[0].string)); }
#line 2216 "programs/winedbg/dbg.tab.c"
    break;

  case 87: /* set_command: tSET tIDENTIFIER '+' tALL  */
#line 215 "programs/winedbg/dbg.y"
                                       { info_wine_dbg_channel(TRUE, (yyvsp[-2].string), "all"); }
#line 2222 "programs/winedbg/dbg.tab.c"
    break;

  case 88: /* set_command: tSET tIDENTIFIER '-' tIDENTIFIER  */
#line 216 "programs/winedbg/dbg.y"
                                       { info_wine_dbg_channel(FALSE, (yyvsp[-2].string), (yyvsp[0].string)); }
#line 2228 "programs/winedbg/dbg.tab.c"
    break;

  case 89: /* set_command: tSET tIDENTIFIER '-' tALL  */
#line 217 "programs/winedbg/dbg.y"
                                       { info_wine_dbg_channel(FALSE, (yyvsp[-2].string), "all"); }
#line 2234 "programs/winedbg/dbg.tab.c"
    break;

  case 90: /* set_command: tSET '!' tIDENTIFIER tIDENTIFIER  */
#line 218 "programs/winedbg/dbg.y"
                                        { dbg_set_option((yyvsp[-1].string), (yyvsp[0].string)); }
#line 2240 "programs/winedbg/dbg.tab.c"
    break;

  case 91: /* set_command: tSET '!' tIDENTIFIER  */
#line 219 "programs/winedbg/dbg.y"
                                { dbg_set_option((yyvsp[0].string), NULL); }
#line 2246 "programs/winedbg/dbg.tab.c"
    break;

  case 92: /* x_command: tEXAM expr_lvalue  */
#line 223 "programs/winedbg/dbg.y"
                                { memory_examine(&(yyvsp[0].lvalue), 1, 'x'); }
#line 2252 "programs/winedbg/dbg.tab.c"
    break;

  case 93: /* x_command: tEXAM tFORMAT expr_lvalue  */
#line 224 "programs/winedbg/dbg.y"
                                { memory_examine(&(yyvsp[0].lvalue), (yyvsp[-1].integer) >> 8, (yyvsp[-1].integer) & 0xff); }
#line 2258 "programs/winedbg/dbg.tab.c"
    break;

  case 94: /* print_command: tPRINT expr_lvalue  */
#line 228 "programs/winedbg/dbg.y"
                                 { print_value(&(yyvsp[0].lvalue), 0, 0); }
#line 2264 "programs/winedbg/dbg.tab.c"
    break;

  case 95: /* print_command: tPRINT tFORMAT expr_lvalue  */
#line 229 "programs/winedbg/dbg.y"
                                 { if (((yyvsp[-1].integer) >> 8) == 1) print_value(&(yyvsp[0].lvalue), (yyvsp[-1].integer) & 0xff, 0); else dbg_printf("Count is meaningless in print command\n"); }
#line 2270 "programs/winedbg/dbg.tab.c"
    break;

  case 96: /* print_command: tPRINT type_expr  */
#line 230 "programs/winedbg/dbg.y"
                                 { types_print_type(&(yyvsp[0].type), TRUE, NULL); dbg_printf("\n"); }
#line 2276 "programs/winedbg/dbg.tab.c"
    break;

  case 97: /* break_command: tBREAK '*' expr_lvalue  */
#line 234 "programs/winedbg/dbg.y"
                                { break_add_break_from_lvalue(&(yyvsp[0].lvalue), TRUE); }
#line 2282 "programs/winedbg/dbg.tab.c"
    break;

  case 98: /* break_command: tBREAK identifier  */
#line 235 "programs/winedbg/dbg.y"
                                { break_add_break_from_id((yyvsp[0].string), -1, TRUE); }
#line 2288 "programs/winedbg/dbg.tab.c"
    break;

  case 99: /* break_command: tBREAK pathname ':' tNUM  */
#line 236 "programs/winedbg/dbg.y"
                                { break_add_break_from_lineno((yyvsp[-2].string), (yyvsp[0].integer), TRUE); }
#line 2294 "programs/winedbg/dbg.tab.c"
    break;

  case 100: /* break_command: tBREAK tNUM  */
#line 237 "programs/winedbg/dbg.y"
                                { break_add_break_from_lineno(NULL, (yyvsp[0].integer), TRUE); }
#line 2300 "programs/winedbg/dbg.tab.c"
    break;

  case 101: /* break_command: tBREAK  */
#line 238 "programs/winedbg/dbg.y"
                                { break_add_break_from_lineno(NULL, -1, TRUE); }
#line 2306 "programs/winedbg/dbg.tab.c"
    break;

  case 102: /* break_command: tHBREAK '*' expr_lvalue  */
#line 239 "programs/winedbg/dbg.y"
                                { break_add_break_from_lvalue(&(yyvsp[0].lvalue), FALSE); }
#line 2312 "programs/winedbg/dbg.tab.c"
    break;

  case 103: /* break_command: tHBREAK identifier  */
#line 240 "programs/winedbg/dbg.y"
                                { break_add_break_from_id((yyvsp[0].string), -1, FALSE); }
#line 2318 "programs/winedbg/dbg.tab.c"
    break;

  case 104: /* break_command: tHBREAK pathname ':' tNUM  */
#line 241 "programs/winedbg/dbg.y"
                                { break_add_break_from_lineno((yyvsp[-2].string), (yyvsp[0].integer), FALSE); }
#line 2324 "programs/winedbg/dbg.tab.c"
    break;

  case 105: /* break_command: tHBREAK tNUM  */
#line 242 "programs/winedbg/dbg.y"
                                { break_add_break_from_lineno(NULL, (yyvsp[0].integer), FALSE); }
#line 2330 "programs/winedbg/dbg.tab.c"
    break;

  case 106: /* break_command: tHBREAK  */
#line 243 "programs/winedbg/dbg.y"
                                { break_add_break_from_lineno(NULL, -1, FALSE); }
#line 2336 "programs/winedbg/dbg.tab.c"
    break;

  case 107: /* break_command: tENABLE tNUM  */
#line 244 "programs/winedbg/dbg.y"
                                { break_enable_xpoint((yyvsp[0].integer), TRUE); }
#line 2342 "programs/winedbg/dbg.tab.c"
    break;

  case 108: /* break_command: tENABLE tBREAK tNUM  */
#line 245 "programs/winedbg/dbg.y"
                                { break_enable_xpoint((yyvsp[0].integer), TRUE); }
#line 2348 "programs/winedbg/dbg.tab.c"
    break;

  case 109: /* break_command: tDISABLE tNUM  */
#line 246 "programs/winedbg/dbg.y"
                                { break_enable_xpoint((yyvsp[0].integer), FALSE); }
#line 2354 "programs/winedbg/dbg.tab.c"
    break;

  case 110: /* break_command: tDISABLE tBREAK tNUM  */
#line 247 "programs/winedbg/dbg.y"
                                { break_enable_xpoint((yyvsp[0].integer), FALSE); }
#line 2360 "programs/winedbg/dbg.tab.c"
    break;

  case 111: /* break_command: tDELETE tNUM  */
#line 248 "programs/winedbg/dbg.y"
                                { break_delete_xpoint((yyvsp[0].integer)); }
#line 2366 "programs/winedbg/dbg.tab.c"
    break;

  case 112: /* break_command: tDELETE tBREAK tNUM  */
#line 249 "programs/winedbg/dbg.y"
                                { break_delete_xpoint((yyvsp[0].integer)); }
#line 2372 "programs/winedbg/dbg.tab.c"
    break;

  case 113: /* watch_command: tWATCH expr_lvalue  */
#line 253 "programs/winedbg/dbg.y"
                                { break_add_watch(&(yyvsp[0].lvalue), TRUE); }
#line 2378 "programs/winedbg/dbg.tab.c"
    break;

  case 114: /* watch_command: tRWATCH expr_lvalue  */
#line 254 "programs/winedbg/dbg.y"
                                { break_add_watch(&(yyvsp[0].lvalue), FALSE); }
#line 2384 "programs/winedbg/dbg.tab.c"
    break;

  case 115: /* display_command: tDISPLAY  */
#line 259 "programs/winedbg/dbg.y"
                                { display_print(); }
#line 2390 "programs/winedbg/dbg.tab.c"
    break;

  case 116: /* display_command: tDISPLAY expr  */
#line 260 "programs/winedbg/dbg.y"
                                { display_add((yyvsp[0].expression), 1, 0); }
#line 2396 "programs/winedbg/dbg.tab.c"
    break;

  case 117: /* display_command: tDISPLAY tFORMAT expr  */
#line 261 "programs/winedbg/dbg.y"
                                { display_add((yyvsp[0].expression), (yyvsp[-1].integer) >> 8, (yyvsp[-1].integer) & 0xff); }
#line 2402 "programs/winedbg/dbg.tab.c"
    break;

  case 118: /* display_command: tENABLE tDISPLAY tNUM  */
#line 262 "programs/winedbg/dbg.y"
                                { display_enable((yyvsp[0].integer), TRUE); }
#line 2408 "programs/winedbg/dbg.tab.c"
    break;

  case 119: /* display_command: tDISABLE tDISPLAY tNUM  */
#line 263 "programs/winedbg/dbg.y"
                                { display_enable((yyvsp[0].integer), FALSE); }
#line 2414 "programs/winedbg/dbg.tab.c"
    break;

  case 120: /* display_command: tDELETE tDISPLAY tNUM  */
#line 264 "programs/winedbg/dbg.y"
                                { display_delete((yyvsp[0].integer)); }
#line 2420 "programs/winedbg/dbg.tab.c"
    break;

  case 121: /* display_command: tDELETE tDISPLAY  */
#line 265 "programs/winedbg/dbg.y"
                                { display_delete(-1); }
#line 2426 "programs/winedbg/dbg.tab.c"
    break;

  case 122: /* display_command: tUNDISPLAY tNUM  */
#line 266 "programs/winedbg/dbg.y"
                                { display_delete((yyvsp[0].integer)); }
#line 2432 "programs/winedbg/dbg.tab.c"
    break;

  case 123: /* display_command: tUNDISPLAY  */
#line 267 "programs/winedbg/dbg.y"
                                { display_delete(-1); }
#line 2438 "programs/winedbg/dbg.tab.c"
    break;

  case 124: /* info_command: tINFO tBREAK  */
#line 271 "programs/winedbg/dbg.y"
                                { break_info(); }
#line 2444 "programs/winedbg/dbg.tab.c"
    break;

  case 125: /* info_command: tINFO tSHARE  */
#line 272 "programs/winedbg/dbg.y"
                                { info_win32_module(0, FALSE); }
#line 2450 "programs/winedbg/dbg.tab.c"
    break;

  case 126: /* info_command: tINFO tWOW tSHARE  */
#line 273 "programs/winedbg/dbg.y"
                                { info_win32_module(0, TRUE); }
#line 2456 "programs/winedbg/dbg.tab.c"
    break;

  case 127: /* info_command: tINFO tSHARE expr_rvalue  */
#line 274 "programs/winedbg/dbg.y"
                                { info_win32_module((yyvsp[0].integer), FALSE); }
#line 2462 "programs/winedbg/dbg.tab.c"
    break;

  case 128: /* info_command: tINFO tREGS  */
#line 275 "programs/winedbg/dbg.y"
                                { dbg_curr_process->be_cpu->print_context(dbg_curr_thread->handle, &dbg_context, 0); }
#line 2468 "programs/winedbg/dbg.tab.c"
    break;

  case 129: /* info_command: tINFO tALLREGS  */
#line 276 "programs/winedbg/dbg.y"
                                { dbg_curr_process->be_cpu->print_context(dbg_curr_thread->handle, &dbg_context, 1); }
#line 2474 "programs/winedbg/dbg.tab.c"
    break;

  case 130: /* info_command: tINFO tSEGMENTS expr_rvalue  */
#line 277 "programs/winedbg/dbg.y"
                                  { info_win32_segments((yyvsp[0].integer) >> 3, 1); }
#line 2480 "programs/winedbg/dbg.tab.c"
    break;

  case 131: /* info_command: tINFO tSEGMENTS  */
#line 278 "programs/winedbg/dbg.y"
                                { info_win32_segments(0, -1); }
#line 2486 "programs/winedbg/dbg.tab.c"
    break;

  case 132: /* info_command: tINFO tSTACK tNUM  */
#line 279 "programs/winedbg/dbg.y"
                                { stack_info((yyvsp[0].integer)); }
#line 2492 "programs/winedbg/dbg.tab.c"
    break;

  case 133: /* info_command: tINFO tSTACK  */
#line 280 "programs/winedbg/dbg.y"
                                { stack_info(-1); }
#line 2498 "programs/winedbg/dbg.tab.c"
    break;

  case 134: /* info_command: tINFO tSYMBOL tSTRING  */
#line 281 "programs/winedbg/dbg.y"
                                { symbol_info((yyvsp[0].string)); }
#line 2504 "programs/winedbg/dbg.tab.c"
    break;

  case 135: /* info_command: tINFO tLOCAL  */
#line 282 "programs/winedbg/dbg.y"
                                { symbol_info_locals(); }
#line 2510 "programs/winedbg/dbg.tab.c"
    break;

  case 136: /* info_command: tINFO tDISPLAY  */
#line 283 "programs/winedbg/dbg.y"
                                { display_info(); }
#line 2516 "programs/winedbg/dbg.tab.c"
    break;

  case 137: /* info_command: tINFO tCLASS  */
#line 284 "programs/winedbg/dbg.y"
                                { info_win32_class(NULL, NULL); }
#line 2522 "programs/winedbg/dbg.tab.c"
    break;

  case 138: /* info_command: tINFO tCLASS tSTRING  */
#line 285 "programs/winedbg/dbg.y"
                                { info_win32_class(NULL, (yyvsp[0].string)); }
#line 2528 "programs/winedbg/dbg.tab.c"
    break;

  case 139: /* info_command: tINFO tWND  */
#line 286 "programs/winedbg/dbg.y"
                                { info_win32_window(NULL, FALSE); }
#line 2534 "programs/winedbg/dbg.tab.c"
    break;

  case 140: /* info_command: tINFO tWND expr_rvalue  */
#line 287 "programs/winedbg/dbg.y"
                                { info_win32_window((HWND)(DWORD_PTR)(yyvsp[0].integer), FALSE); }
#line 2540 "programs/winedbg/dbg.tab.c"
    break;

  case 141: /* info_command: tINFO '*' tWND  */
#line 288 "programs/winedbg/dbg.y"
                                { info_win32_window(NULL, TRUE); }
#line 2546 "programs/winedbg/dbg.tab.c"
    break;

  case 142: /* info_command: tINFO '*' tWND expr_rvalue  */
#line 289 "programs/winedbg/dbg.y"
                                 { info_win32_window((HWND)(DWORD_PTR)(yyvsp[0].integer), TRUE); }
#line 2552 "programs/winedbg/dbg.tab.c"
    break;

  case 143: /* info_command: tINFO tPROCESS  */
#line 290 "programs/winedbg/dbg.y"
                                { info_win32_processes(); }
#line 2558 "programs/winedbg/dbg.tab.c"
    break;

  case 144: /* info_command: tINFO tTHREAD  */
#line 291 "programs/winedbg/dbg.y"
                                { info_win32_threads(); }
#line 2564 "programs/winedbg/dbg.tab.c"
    break;

  case 145: /* info_command: tINFO tFRAME  */
#line 292 "programs/winedbg/dbg.y"
                                { info_win32_frame_exceptions(dbg_curr_tid); }
#line 2570 "programs/winedbg/dbg.tab.c"
    break;

  case 146: /* info_command: tINFO tFRAME expr_rvalue  */
#line 293 "programs/winedbg/dbg.y"
                                { info_win32_frame_exceptions((yyvsp[0].integer)); }
#line 2576 "programs/winedbg/dbg.tab.c"
    break;

  case 147: /* info_command: tINFO tMAPS  */
#line 294 "programs/winedbg/dbg.y"
                                { info_win32_virtual(dbg_curr_pid); }
#line 2582 "programs/winedbg/dbg.tab.c"
    break;

  case 148: /* info_command: tINFO tMAPS expr_rvalue  */
#line 295 "programs/winedbg/dbg.y"
                                { info_win32_virtual((yyvsp[0].integer)); }
#line 2588 "programs/winedbg/dbg.tab.c"
    break;

  case 149: /* info_command: tINFO tEXCEPTION  */
#line 296 "programs/winedbg/dbg.y"
                                { info_win32_exception(); }
#line 2594 "programs/winedbg/dbg.tab.c"
    break;

  case 150: /* info_command: tINFO tSYSTEM  */
#line 297 "programs/winedbg/dbg.y"
                                { info_win32_system(); }
#line 2600 "programs/winedbg/dbg.tab.c"
    break;

  case 151: /* maintenance_command: tMAINTENANCE tTYPE  */
#line 301 "programs/winedbg/dbg.y"
                                { print_types(); }
#line 2606 "programs/winedbg/dbg.tab.c"
    break;

  case 152: /* maintenance_command: tMAINTENANCE tMODULE tSTRING  */
#line 302 "programs/winedbg/dbg.y"
                                   { tgt_module_load((yyvsp[0].string), FALSE); }
#line 2612 "programs/winedbg/dbg.tab.c"
    break;

  case 153: /* maintenance_command: tMAINTENANCE '*' tMODULE tSTRING  */
#line 303 "programs/winedbg/dbg.y"
                                       { tgt_module_load((yyvsp[0].string), TRUE); }
#line 2618 "programs/winedbg/dbg.tab.c"
    break;

  case 154: /* noprocess_state: tNOPROCESS  */
#line 307 "programs/winedbg/dbg.y"
                                 {}
#line 2624 "programs/winedbg/dbg.tab.c"
    break;

  case 155: /* noprocess_state: tNOPROCESS tBACKTRACE tALL  */
#line 308 "programs/winedbg/dbg.y"
                                 { stack_backtrace(-1); }
#line 2630 "programs/winedbg/dbg.tab.c"
    break;

  case 156: /* noprocess_state: tNOPROCESS tSTRING  */
#line 309 "programs/winedbg/dbg.y"
                                 { dbg_printf("No process loaded, cannot execute '%s'\n", (yyvsp[0].string)); }
#line 2636 "programs/winedbg/dbg.tab.c"
    break;

  case 157: /* type_expr: tVOID  */
#line 313 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"void",                   (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2642 "programs/winedbg/dbg.tab.c"
    break;

  case 158: /* type_expr: tCHAR  */
#line 314 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"char",                   (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2648 "programs/winedbg/dbg.tab.c"
    break;

  case 159: /* type_expr: tWCHAR  */
#line 315 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"WCHAR",                  (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2654 "programs/winedbg/dbg.tab.c"
    break;

  case 160: /* type_expr: tSIGNED tCHAR  */
#line 316 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"signed char",            (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2660 "programs/winedbg/dbg.tab.c"
    break;

  case 161: /* type_expr: tUNSIGNED tCHAR  */
#line 317 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned char",          (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2666 "programs/winedbg/dbg.tab.c"
    break;

  case 162: /* type_expr: tSHORT tINT  */
#line 318 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"short int",              (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2672 "programs/winedbg/dbg.tab.c"
    break;

  case 163: /* type_expr: tSHORT  */
#line 319 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"short int",              (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2678 "programs/winedbg/dbg.tab.c"
    break;

  case 164: /* type_expr: tSIGNED tSHORT tINT  */
#line 320 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"short int",              (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2684 "programs/winedbg/dbg.tab.c"
    break;

  case 165: /* type_expr: tSIGNED tSHORT  */
#line 321 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"short int",              (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2690 "programs/winedbg/dbg.tab.c"
    break;

  case 166: /* type_expr: tSHORT tSIGNED tINT  */
#line 322 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"short int",              (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2696 "programs/winedbg/dbg.tab.c"
    break;

  case 167: /* type_expr: tSHORT tSIGNED  */
#line 323 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"short int",              (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2702 "programs/winedbg/dbg.tab.c"
    break;

  case 168: /* type_expr: tSHORT tUNSIGNED  */
#line 324 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned short int",     (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2708 "programs/winedbg/dbg.tab.c"
    break;

  case 169: /* type_expr: tSHORT tUNSIGNED tINT  */
#line 325 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned short int",     (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2714 "programs/winedbg/dbg.tab.c"
    break;

  case 170: /* type_expr: tUNSIGNED tSHORT  */
#line 326 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned short int",     (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2720 "programs/winedbg/dbg.tab.c"
    break;

  case 171: /* type_expr: tUNSIGNED tSHORT tINT  */
#line 327 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned short int",     (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2726 "programs/winedbg/dbg.tab.c"
    break;

  case 172: /* type_expr: tINT  */
#line 328 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"int",                    (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2732 "programs/winedbg/dbg.tab.c"
    break;

  case 173: /* type_expr: tSIGNED tINT  */
#line 329 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"int",                    (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2738 "programs/winedbg/dbg.tab.c"
    break;

  case 174: /* type_expr: tUNSIGNED  */
#line 330 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned int",           (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2744 "programs/winedbg/dbg.tab.c"
    break;

  case 175: /* type_expr: tUNSIGNED tINT  */
#line 331 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned int",           (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2750 "programs/winedbg/dbg.tab.c"
    break;

  case 176: /* type_expr: tLONG  */
#line 332 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long int",               (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2756 "programs/winedbg/dbg.tab.c"
    break;

  case 177: /* type_expr: tLONG tINT  */
#line 333 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long int",               (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2762 "programs/winedbg/dbg.tab.c"
    break;

  case 178: /* type_expr: tSIGNED tLONG  */
#line 334 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long int",               (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2768 "programs/winedbg/dbg.tab.c"
    break;

  case 179: /* type_expr: tSIGNED tLONG tINT  */
#line 335 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long int",               (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2774 "programs/winedbg/dbg.tab.c"
    break;

  case 180: /* type_expr: tLONG tSIGNED  */
#line 336 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long int",               (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2780 "programs/winedbg/dbg.tab.c"
    break;

  case 181: /* type_expr: tLONG tSIGNED tINT  */
#line 337 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long int",               (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2786 "programs/winedbg/dbg.tab.c"
    break;

  case 182: /* type_expr: tLONG tUNSIGNED  */
#line 338 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long int",      (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2792 "programs/winedbg/dbg.tab.c"
    break;

  case 183: /* type_expr: tLONG tUNSIGNED tINT  */
#line 339 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long int",      (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2798 "programs/winedbg/dbg.tab.c"
    break;

  case 184: /* type_expr: tUNSIGNED tLONG  */
#line 340 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long int",      (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2804 "programs/winedbg/dbg.tab.c"
    break;

  case 185: /* type_expr: tUNSIGNED tLONG tINT  */
#line 341 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long int",      (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2810 "programs/winedbg/dbg.tab.c"
    break;

  case 186: /* type_expr: tLONG tLONG  */
#line 342 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long long int",          (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2816 "programs/winedbg/dbg.tab.c"
    break;

  case 187: /* type_expr: tLONG tLONG tINT  */
#line 343 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long long int",          (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2822 "programs/winedbg/dbg.tab.c"
    break;

  case 188: /* type_expr: tSIGNED tLONG tLONG  */
#line 344 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long long int",          (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2828 "programs/winedbg/dbg.tab.c"
    break;

  case 189: /* type_expr: tSIGNED tLONG tLONG tINT  */
#line 345 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long long int",          (yyvsp[-3].string), &(yyval.type))) YYERROR; }
#line 2834 "programs/winedbg/dbg.tab.c"
    break;

  case 190: /* type_expr: tUNSIGNED tLONG tLONG  */
#line 346 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long long int", (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2840 "programs/winedbg/dbg.tab.c"
    break;

  case 191: /* type_expr: tUNSIGNED tLONG tLONG tINT  */
#line 347 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long long int", (yyvsp[-3].string), &(yyval.type))) YYERROR; }
#line 2846 "programs/winedbg/dbg.tab.c"
    break;

  case 192: /* type_expr: tLONG tLONG tUNSIGNED  */
#line 348 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long long int", (yyvsp[-2].string), &(yyval.type))) YYERROR; }
#line 2852 "programs/winedbg/dbg.tab.c"
    break;

  case 193: /* type_expr: tLONG tLONG tUNSIGNED tINT  */
#line 349 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"unsigned long long int", (yyvsp[-3].string), &(yyval.type))) YYERROR; }
#line 2858 "programs/winedbg/dbg.tab.c"
    break;

  case 194: /* type_expr: tFLOAT  */
#line 350 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"float",                  (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2864 "programs/winedbg/dbg.tab.c"
    break;

  case 195: /* type_expr: tDOUBLE  */
#line 351 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"double",                 (yyvsp[0].string), &(yyval.type))) YYERROR; }
#line 2870 "programs/winedbg/dbg.tab.c"
    break;

  case 196: /* type_expr: tLONG tDOUBLE  */
#line 352 "programs/winedbg/dbg.y"
                                { if (!types_find_basic(L"long double",            (yyvsp[-1].string), &(yyval.type))) YYERROR; }
#line 2876 "programs/winedbg/dbg.tab.c"
    break;

  case 197: /* type_expr: tTYPEDEF  */
#line 353 "programs/winedbg/dbg.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 2882 "programs/winedbg/dbg.tab.c"
    break;

  case 198: /* type_expr: type_expr '*'  */
#line 354 "programs/winedbg/dbg.y"
                                { if (!types_find_pointer(&(yyvsp[-1].type), &(yyval.type))) {yyerror("Cannot find pointer type\n"); YYERROR; } }
#line 2888 "programs/winedbg/dbg.tab.c"
    break;

  case 199: /* type_expr: tCLASS identifier  */
#line 355 "programs/winedbg/dbg.y"
                                { if (!types_find_type((yyvsp[0].string), SymTagUDT, &(yyval.type))) {yyerror("Unknown type\n"); YYERROR; } }
#line 2894 "programs/winedbg/dbg.tab.c"
    break;

  case 200: /* type_expr: tSTRUCT identifier  */
#line 356 "programs/winedbg/dbg.y"
                                { if (!types_find_type((yyvsp[0].string), SymTagUDT, &(yyval.type))) {yyerror("Unknown type\n"); YYERROR; } }
#line 2900 "programs/winedbg/dbg.tab.c"
    break;

  case 201: /* type_expr: tUNION identifier  */
#line 357 "programs/winedbg/dbg.y"
                                { if (!types_find_type((yyvsp[0].string), SymTagUDT, &(yyval.type))) {yyerror("Unknown type\n"); YYERROR; } }
#line 2906 "programs/winedbg/dbg.tab.c"
    break;

  case 202: /* type_expr: tENUM identifier  */
#line 358 "programs/winedbg/dbg.y"
                                { if (!types_find_type((yyvsp[0].string), SymTagEnum, &(yyval.type))) {yyerror("Unknown type\n"); YYERROR; } }
#line 2912 "programs/winedbg/dbg.tab.c"
    break;

  case 203: /* expr_lvalue: expr  */
#line 362 "programs/winedbg/dbg.y"
                                { (yyval.lvalue) = expr_eval((yyvsp[0].expression)); }
#line 2918 "programs/winedbg/dbg.tab.c"
    break;

  case 204: /* expr_rvalue: expr_lvalue  */
#line 366 "programs/winedbg/dbg.y"
                                { (yyval.integer) = types_extract_as_integer(&(yyvsp[0].lvalue)); }
#line 2924 "programs/winedbg/dbg.tab.c"
    break;

  case 205: /* expr: tNUM  */
#line 376 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_sconstant((yyvsp[0].integer)); }
#line 2930 "programs/winedbg/dbg.tab.c"
    break;

  case 206: /* expr: tSTRING  */
#line 377 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_string((yyvsp[0].string)); }
#line 2936 "programs/winedbg/dbg.tab.c"
    break;

  case 207: /* expr: tINTVAR  */
#line 378 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_internal_var((yyvsp[0].string)); }
#line 2942 "programs/winedbg/dbg.tab.c"
    break;

  case 208: /* expr: identifier  */
#line 379 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_symbol((yyvsp[0].string)); }
#line 2948 "programs/winedbg/dbg.tab.c"
    break;

  case 209: /* expr: expr OP_DRF tIDENTIFIER  */
#line 380 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_pstruct((yyvsp[-2].expression), (yyvsp[0].string)); }
#line 2954 "programs/winedbg/dbg.tab.c"
    break;

  case 210: /* expr: expr '.' tIDENTIFIER  */
#line 381 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_struct((yyvsp[-2].expression), (yyvsp[0].string)); }
#line 2960 "programs/winedbg/dbg.tab.c"
    break;

  case 211: /* expr: identifier '(' ')'  */
#line 382 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_func_call((yyvsp[-2].string), 0); }
#line 2966 "programs/winedbg/dbg.tab.c"
    break;

  case 212: /* expr: identifier '(' expr ')'  */
#line 383 "programs/winedbg/dbg.y"
                                { (yyval.expression) = expr_alloc_func_call((yyvsp[-3].string), 1, (yyvsp[-1].expression)); }
#line 2972 "programs/winedbg/dbg.tab.c"
    break;

  case 213: /* expr: identifier '(' expr ',' expr ')'  */
#line 384 "programs/winedbg/dbg.y"
                                       { (yyval.expression) = expr_alloc_func_call((yyvsp[-5].string), 2, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2978 "programs/winedbg/dbg.tab.c"
    break;

  case 214: /* expr: identifier '(' expr ',' expr ',' expr ')'  */
#line 385 "programs/winedbg/dbg.y"
                                                { (yyval.expression) = expr_alloc_func_call((yyvsp[-7].string), 3, (yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2984 "programs/winedbg/dbg.tab.c"
    break;

  case 215: /* expr: identifier '(' expr ',' expr ',' expr ',' expr ')'  */
#line 386 "programs/winedbg/dbg.y"
                                                         { (yyval.expression) = expr_alloc_func_call((yyvsp[-9].string), 4, (yyvsp[-7].expression), (yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2990 "programs/winedbg/dbg.tab.c"
    break;

  case 216: /* expr: identifier '(' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 387 "programs/winedbg/dbg.y"
                                                                  { (yyval.expression) = expr_alloc_func_call((yyvsp[-11].string), 5, (yyvsp[-9].expression), (yyvsp[-7].expression), (yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2996 "programs/winedbg/dbg.tab.c"
    break;

  case 217: /* expr: expr '[' expr ']'  */
#line 388 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_ARR, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 3002 "programs/winedbg/dbg.tab.c"
    break;

  case 218: /* expr: expr ':' expr  */
#line 389 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_SEG, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3008 "programs/winedbg/dbg.tab.c"
    break;

  case 219: /* expr: expr OP_LOR expr  */
#line 390 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_LOR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3014 "programs/winedbg/dbg.tab.c"
    break;

  case 220: /* expr: expr OP_LAND expr  */
#line 391 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_LAND, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3020 "programs/winedbg/dbg.tab.c"
    break;

  case 221: /* expr: expr '|' expr  */
#line 392 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_OR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3026 "programs/winedbg/dbg.tab.c"
    break;

  case 222: /* expr: expr '&' expr  */
#line 393 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_AND, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3032 "programs/winedbg/dbg.tab.c"
    break;

  case 223: /* expr: expr '^' expr  */
#line 394 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_XOR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3038 "programs/winedbg/dbg.tab.c"
    break;

  case 224: /* expr: expr OP_EQ expr  */
#line 395 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_EQ, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3044 "programs/winedbg/dbg.tab.c"
    break;

  case 225: /* expr: expr '>' expr  */
#line 396 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_GT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3050 "programs/winedbg/dbg.tab.c"
    break;

  case 226: /* expr: expr '<' expr  */
#line 397 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_LT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3056 "programs/winedbg/dbg.tab.c"
    break;

  case 227: /* expr: expr OP_GE expr  */
#line 398 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_GE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3062 "programs/winedbg/dbg.tab.c"
    break;

  case 228: /* expr: expr OP_LE expr  */
#line 399 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_LE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3068 "programs/winedbg/dbg.tab.c"
    break;

  case 229: /* expr: expr OP_NE expr  */
#line 400 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_NE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3074 "programs/winedbg/dbg.tab.c"
    break;

  case 230: /* expr: expr OP_SHL expr  */
#line 401 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_SHL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3080 "programs/winedbg/dbg.tab.c"
    break;

  case 231: /* expr: expr OP_SHR expr  */
#line 402 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_SHR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3086 "programs/winedbg/dbg.tab.c"
    break;

  case 232: /* expr: expr '+' expr  */
#line 403 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_ADD, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3092 "programs/winedbg/dbg.tab.c"
    break;

  case 233: /* expr: expr '-' expr  */
#line 404 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_SUB, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3098 "programs/winedbg/dbg.tab.c"
    break;

  case 234: /* expr: expr '*' expr  */
#line 405 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_MUL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3104 "programs/winedbg/dbg.tab.c"
    break;

  case 235: /* expr: expr '/' expr  */
#line 406 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_DIV, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3110 "programs/winedbg/dbg.tab.c"
    break;

  case 236: /* expr: expr '%' expr  */
#line 407 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_REM, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3116 "programs/winedbg/dbg.tab.c"
    break;

  case 237: /* expr: '-' expr  */
#line 408 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_unary_op(EXP_OP_NEG, (yyvsp[0].expression)); }
#line 3122 "programs/winedbg/dbg.tab.c"
    break;

  case 238: /* expr: '+' expr  */
#line 409 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = (yyvsp[0].expression); }
#line 3128 "programs/winedbg/dbg.tab.c"
    break;

  case 239: /* expr: '!' expr  */
#line 410 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_unary_op(EXP_OP_NOT, (yyvsp[0].expression)); }
#line 3134 "programs/winedbg/dbg.tab.c"
    break;

  case 240: /* expr: '~' expr  */
#line 411 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_unary_op(EXP_OP_LNOT, (yyvsp[0].expression)); }
#line 3140 "programs/winedbg/dbg.tab.c"
    break;

  case 241: /* expr: '(' expr ')'  */
#line 412 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = (yyvsp[-1].expression); }
#line 3146 "programs/winedbg/dbg.tab.c"
    break;

  case 242: /* expr: '*' expr  */
#line 413 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_unary_op(EXP_OP_DEREF, (yyvsp[0].expression)); }
#line 3152 "programs/winedbg/dbg.tab.c"
    break;

  case 243: /* expr: '&' expr  */
#line 414 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_unary_op(EXP_OP_ADDR, (yyvsp[0].expression)); }
#line 3158 "programs/winedbg/dbg.tab.c"
    break;

  case 244: /* expr: '(' type_expr ')' expr  */
#line 415 "programs/winedbg/dbg.y"
                                            { (yyval.expression) = expr_alloc_typecast(&(yyvsp[-2].type), (yyvsp[0].expression)); }
#line 3164 "programs/winedbg/dbg.tab.c"
    break;

  case 245: /* lvalue_addr: lvalue  */
#line 423 "programs/winedbg/dbg.y"
                                 { (yyval.lvalue) = expr_eval((yyvsp[0].expression)); }
#line 3170 "programs/winedbg/dbg.tab.c"
    break;

  case 246: /* lvalue: tNUM  */
#line 427 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_sconstant((yyvsp[0].integer)); }
#line 3176 "programs/winedbg/dbg.tab.c"
    break;

  case 247: /* lvalue: tINTVAR  */
#line 428 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_internal_var((yyvsp[0].string)); }
#line 3182 "programs/winedbg/dbg.tab.c"
    break;

  case 248: /* lvalue: identifier  */
#line 429 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_symbol((yyvsp[0].string)); }
#line 3188 "programs/winedbg/dbg.tab.c"
    break;

  case 249: /* lvalue: lvalue OP_DRF tIDENTIFIER  */
#line 430 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_pstruct((yyvsp[-2].expression), (yyvsp[0].string)); }
#line 3194 "programs/winedbg/dbg.tab.c"
    break;

  case 250: /* lvalue: lvalue '.' tIDENTIFIER  */
#line 431 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_struct((yyvsp[-2].expression), (yyvsp[0].string)); }
#line 3200 "programs/winedbg/dbg.tab.c"
    break;

  case 251: /* lvalue: lvalue '[' expr ']'  */
#line 432 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_binary_op(EXP_OP_ARR, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 3206 "programs/winedbg/dbg.tab.c"
    break;

  case 252: /* lvalue: '*' expr  */
#line 433 "programs/winedbg/dbg.y"
                                 { (yyval.expression) = expr_alloc_unary_op(EXP_OP_DEREF, (yyvsp[0].expression)); }
#line 3212 "programs/winedbg/dbg.tab.c"
    break;


#line 3216 "programs/winedbg/dbg.tab.c"

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
  yytoken = yychar == DBG_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= DBG_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == DBG_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = DBG_EMPTY;
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != DBG_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 436 "programs/winedbg/dbg.y"


static LONG WINAPI wine_dbg_cmd(EXCEPTION_POINTERS *eptr)
{
    switch (eptr->ExceptionRecord->ExceptionCode)
    {
    case DEBUG_STATUS_INTERNAL_ERROR:
        dbg_printf("\nWineDbg internal error\n");
        break;
    case DEBUG_STATUS_NO_SYMBOL:
        dbg_printf("\nUndefined symbol\n");
        break;
    case DEBUG_STATUS_DIV_BY_ZERO:
        dbg_printf("\nDivision by zero\n");
        break;
    case DEBUG_STATUS_BAD_TYPE:
        dbg_printf("\nNo type or type mismatch\n");
        break;
    case DEBUG_STATUS_NO_FIELD:
        dbg_printf("\nNo such field in structure or union\n");
        break;
    case DEBUG_STATUS_CANT_DEREF:
        dbg_printf("\nDereference failed (not a pointer, or out of array bounds)\n");
        break;
    case DEBUG_STATUS_ABORT:
        break;
    case DEBUG_STATUS_NOT_AN_INTEGER:
        dbg_printf("\nNeeding an integral value\n");
        break;
    case CONTROL_C_EXIT:
        /* this is generally sent by a ctrl-c when we run winedbg outside of wineconsole */
        /* stop the debuggee, and continue debugger execution, we will be reentered by the
         * debug events generated by stopping
         */
        dbg_interrupt_debuggee();
        return EXCEPTION_CONTINUE_EXECUTION;
    default:
        dbg_printf("\nException %lx\n", eptr->ExceptionRecord->ExceptionCode);
        break;
    }

    return EXCEPTION_EXECUTE_HANDLER;
}

struct parser_context
{
    const char* filename;
    HANDLE input;
    HANDLE output;
    unsigned line_no;
    char*  last_line;
    size_t last_line_idx;
};

static struct parser_context dbg_parser = {NULL, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, 0, NULL, 0};

static int input_fetch_entire_line(const char* pfx, char** line)
{
    char*       buffer;
    char        ch;
    DWORD	nread;
    size_t      len, alloc;

    /* as of today, console handles can be file handles... so better use file APIs rather than
     * console's
     */
    WriteFile(dbg_parser.output, pfx, strlen(pfx), &nread, NULL);

    buffer = malloc(alloc = 16);
    assert(buffer != NULL);

    dbg_parser.line_no++;
    len = 0;
    do
    {
        if (!ReadFile(dbg_parser.input, &ch, 1, &nread, NULL) || nread == 0)
        {
            free(buffer);
            return -1;
        }

        if (len + 2 > alloc)
        {
            char* new;
            while (len + 2 > alloc) alloc *= 2;
            if (!(new = realloc(buffer, alloc)))
            {
                free(buffer);
                return -1;
            }
            buffer = new;
        }
        buffer[len++] = ch;
    }
    while (ch != '\n');
    buffer[len] = '\0';

    *line = buffer;
    return len;
}

size_t input_lex_read_buffer(char* buf, int size)
{
    int len;

    /* try first to fetch the remaining of an existing line */
    if (dbg_parser.last_line_idx == 0)
    {
        char* tmp = NULL;
        /* no remaining chars to be read from last line, grab a brand new line up to '\n' */
        lexeme_flush();
        len = input_fetch_entire_line("Wine-dbg>", &tmp);
        if (len < 0) return 0;  /* eof */

        /* remove carriage return in newline */
        if (len >= 2 && tmp[len - 2] == '\r')
        {
            tmp[len - 2] = '\n';
            tmp[len - 1] = '\0';
            len--;
        }

        /* recall last command when empty input buffer and not parsing a file */
        if (dbg_parser.last_line && (len == 0 || (len == 1 && tmp[0] == '\n')) &&
            dbg_parser.output != INVALID_HANDLE_VALUE)
        {
            free(tmp);
        }
        else
        {
            free(dbg_parser.last_line);
            dbg_parser.last_line = tmp;
        }
    }

    len = min(strlen(dbg_parser.last_line + dbg_parser.last_line_idx), size - 1);
    memcpy(buf, dbg_parser.last_line + dbg_parser.last_line_idx, len);
    buf[len] = '\0';
    if ((dbg_parser.last_line_idx += len) >= strlen(dbg_parser.last_line))
        dbg_parser.last_line_idx = 0;
    return len;
}

int input_read_line(const char* pfx, char* buf, int size)
{
    char*       line = NULL;

    int len = input_fetch_entire_line(pfx, &line);
    if (len < 0) return 0;
    /* remove trailing \n and \r */
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) len--;
    len = min(size - 1, len);
    memcpy(buf, line, len);
    buf[len] = '\0';
    free(line);
    return 1;
}

/***********************************************************************
 *           parser_handle
 *
 * Debugger command line parser
 */
void	parser_handle(const char* filename, HANDLE input)
{
    BOOL ret_ok;
    struct parser_context prev = dbg_parser;

    ret_ok = FALSE;

    if (input != INVALID_HANDLE_VALUE)
    {
        dbg_parser.output = INVALID_HANDLE_VALUE;
        dbg_parser.input  = input;
    }
    else
    {
        dbg_parser.output = GetStdHandle(STD_OUTPUT_HANDLE);
        dbg_parser.input  = GetStdHandle(STD_INPUT_HANDLE);
    }
    dbg_parser.line_no = 0;
    dbg_parser.filename = filename;
    dbg_parser.last_line = NULL;
    dbg_parser.last_line_idx = 0;
    do
    {
       __TRY
       {
	  ret_ok = TRUE;
	  dbg_parse();
       }
       __EXCEPT(wine_dbg_cmd)
       {
	  ret_ok = FALSE;
       }
       __ENDTRY;
       lexeme_flush();
       expr_free_all();
    } while (!ret_ok);

    dbg_parser = prev;
}

static void parser(const char* filename)
{
    HANDLE h = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0L, 0);
    if (h != INVALID_HANDLE_VALUE)
    {
        parser_handle(filename, h);
        CloseHandle(h);
    }
}

static int dbg_error(const char* s)
{
    if (dbg_parser.filename)
        dbg_printf("%s:%d:", dbg_parser.filename, dbg_parser.line_no);
    dbg_printf("%s\n", s);
    return 0;
}

HANDLE WINAPIV parser_generate_command_file(const char* pmt, ...)
{
    HANDLE      hFile;
    char        path[MAX_PATH], file[MAX_PATH];
    DWORD       w;
    const char* p;

    GetTempPathA(sizeof(path), path);
    GetTempFileNameA(path, "WD", 0, file);
    hFile = CreateFileA(file, GENERIC_READ|GENERIC_WRITE|DELETE, FILE_SHARE_DELETE, 
                        NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_DELETE_ON_CLOSE, 0);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        va_list ap;

        WriteFile(hFile, pmt, strlen(pmt), &w, 0);
        va_start(ap, pmt);
        while ((p = va_arg(ap, const char*)) != NULL)
        {
            WriteFile(hFile, "\n", 1, &w, 0);
            WriteFile(hFile, p, strlen(p), &w, 0);
        }
        va_end(ap);
        WriteFile(hFile, "\nquit\n", 6, &w, 0);
        SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    }
    return hFile;
}
