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

#ifndef YY_DBG_PROGRAMS_WINEDBG_DBG_TAB_H_INCLUDED
# define YY_DBG_PROGRAMS_WINEDBG_DBG_TAB_H_INCLUDED
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

#line 179 "programs/winedbg/dbg.tab.h"

};
typedef union DBG_STYPE DBG_STYPE;
# define DBG_STYPE_IS_TRIVIAL 1
# define DBG_STYPE_IS_DECLARED 1
#endif


extern DBG_STYPE dbg_lval;


int dbg_parse (void);


#endif /* !YY_DBG_PROGRAMS_WINEDBG_DBG_TAB_H_INCLUDED  */
