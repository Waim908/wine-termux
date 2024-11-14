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

#ifndef YY_SQL_DLLS_MSI_SQL_TAB_H_INCLUDED
# define YY_SQL_DLLS_MSI_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef SQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define SQL_DEBUG 1
#  else
#   define SQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define SQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined SQL_DEBUG */
#if SQL_DEBUG
extern int sql_debug;
#endif

/* Token kinds.  */
#ifndef SQL_TOKENTYPE
# define SQL_TOKENTYPE
  enum sql_tokentype
  {
    SQL_EMPTY = -2,
    SQL_EOF = 0,                   /* "end of file"  */
    SQL_error = 256,               /* error  */
    SQL_UNDEF = 257,               /* "invalid token"  */
    TK_ALTER = 258,                /* TK_ALTER  */
    TK_AND = 259,                  /* TK_AND  */
    TK_BY = 260,                   /* TK_BY  */
    TK_CHAR = 261,                 /* TK_CHAR  */
    TK_COMMA = 262,                /* TK_COMMA  */
    TK_CREATE = 263,               /* TK_CREATE  */
    TK_DELETE = 264,               /* TK_DELETE  */
    TK_DROP = 265,                 /* TK_DROP  */
    TK_DISTINCT = 266,             /* TK_DISTINCT  */
    TK_DOT = 267,                  /* TK_DOT  */
    TK_EQ = 268,                   /* TK_EQ  */
    TK_FREE = 269,                 /* TK_FREE  */
    TK_FROM = 270,                 /* TK_FROM  */
    TK_GE = 271,                   /* TK_GE  */
    TK_GT = 272,                   /* TK_GT  */
    TK_HOLD = 273,                 /* TK_HOLD  */
    TK_ADD = 274,                  /* TK_ADD  */
    TK_ID = 275,                   /* TK_ID  */
    TK_ILLEGAL = 276,              /* TK_ILLEGAL  */
    TK_INSERT = 277,               /* TK_INSERT  */
    TK_INT = 278,                  /* TK_INT  */
    TK_INTEGER = 279,              /* TK_INTEGER  */
    TK_INTO = 280,                 /* TK_INTO  */
    TK_IS = 281,                   /* TK_IS  */
    TK_KEY = 282,                  /* TK_KEY  */
    TK_LE = 283,                   /* TK_LE  */
    TK_LONG = 284,                 /* TK_LONG  */
    TK_LONGCHAR = 285,             /* TK_LONGCHAR  */
    TK_LP = 286,                   /* TK_LP  */
    TK_LT = 287,                   /* TK_LT  */
    TK_LOCALIZABLE = 288,          /* TK_LOCALIZABLE  */
    TK_MINUS = 289,                /* TK_MINUS  */
    TK_NE = 290,                   /* TK_NE  */
    TK_NOT = 291,                  /* TK_NOT  */
    TK_NULL = 292,                 /* TK_NULL  */
    TK_OBJECT = 293,               /* TK_OBJECT  */
    TK_OR = 294,                   /* TK_OR  */
    TK_ORDER = 295,                /* TK_ORDER  */
    TK_PRIMARY = 296,              /* TK_PRIMARY  */
    TK_RP = 297,                   /* TK_RP  */
    TK_SELECT = 298,               /* TK_SELECT  */
    TK_SET = 299,                  /* TK_SET  */
    TK_SHORT = 300,                /* TK_SHORT  */
    TK_SPACE = 301,                /* TK_SPACE  */
    TK_STAR = 302,                 /* TK_STAR  */
    TK_STRING = 303,               /* TK_STRING  */
    TK_TABLE = 304,                /* TK_TABLE  */
    TK_TEMPORARY = 305,            /* TK_TEMPORARY  */
    TK_UPDATE = 306,               /* TK_UPDATE  */
    TK_VALUES = 307,               /* TK_VALUES  */
    TK_WHERE = 308,                /* TK_WHERE  */
    TK_WILDCARD = 309,             /* TK_WILDCARD  */
    END_OF_FILE = 310,             /* END_OF_FILE  */
    ILLEGAL = 311,                 /* ILLEGAL  */
    SPACE = 312,                   /* SPACE  */
    UNCLOSED_STRING = 313,         /* UNCLOSED_STRING  */
    COMMENT = 314,                 /* COMMENT  */
    FUNCTION = 315,                /* FUNCTION  */
    COLUMN = 316,                  /* COLUMN  */
    TK_LIKE = 318,                 /* TK_LIKE  */
    TK_NEGATION = 319              /* TK_NEGATION  */
  };
  typedef enum sql_tokentype sql_token_kind_t;
#endif

/* Value type.  */
#if ! defined SQL_STYPE && ! defined SQL_STYPE_IS_DECLARED
union SQL_STYPE
{
#line 65 "dlls/msi/sql.y"

    struct sql_str str;
    LPWSTR string;
    column_info *column_list;
    MSIVIEW *query;
    struct expr *expr;
    USHORT column_type;
    int integer;

#line 145 "dlls/msi/sql.tab.h"

};
typedef union SQL_STYPE SQL_STYPE;
# define SQL_STYPE_IS_TRIVIAL 1
# define SQL_STYPE_IS_DECLARED 1
#endif




int sql_parse (SQL_input *info);


#endif /* !YY_SQL_DLLS_MSI_SQL_TAB_H_INCLUDED  */
