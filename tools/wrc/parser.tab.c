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
#define YYSTYPE         PARSER_STYPE
/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs
#define yylval          parser_lval
#define yychar          parser_char

/* First part of user prologue.  */
#line 1 "tools/wrc/parser.y"

/*
 * Copyright 1994	Martin von Loewis
 * Copyright 1998-2000	Bertho A. Stultiens (BS)
 *           1999	Juergen Schmied (JS)
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
 *
 * History:
 * 24-Jul-2000 BS	- Made a fix for broken Berkeley yacc on
 *			  non-terminals (see cjunk rule).
 * 21-May-2000 BS	- Partial implementation of font resources.
 *			- Corrected language propagation for binary
 *			  resources such as bitmaps, icons, cursors,
 *			  userres and rcdata. The language is now
 *			  correct in .res files.
 *			- Fixed reading the resource name as ident,
 *			  so that it may overlap keywords.
 * 20-May-2000 BS	- Implemented animated cursors and icons
 *			  resource types.
 * 30-Apr-2000 BS	- Reintegration into the wine-tree
 * 14-Jan-2000 BS	- Redid the usertype resources so that they
 *			  are compatible.
 * 02-Jan-2000 BS	- Removed the preprocessor from the grammar
 *			  except for the # command (line numbers).
 *
 * 06-Nov-1999 JS	- see CHANGES
 *
 * 29-Dec-1998 AdH	- Grammar and function extensions.
 *			     grammar: TOOLBAR resources, Named ICONs in
 *				DIALOGS
 *			     functions: semantic actions for the grammar
 *				changes, resource files can now be anywhere
 *				on the include path instead of just in the
 *				current directory
 *
 * 20-Jun-1998 BS	- Fixed a bug in load_file() where the name was not
 *			  printed out correctly.
 *
 * 17-Jun-1998 BS	- Fixed a bug in CLASS statement parsing which should
 *			  also accept a tSTRING as argument.
 *
 * 25-May-1998 BS	- Found out that I need to support language, version
 *			  and characteristics in inline resources (bitmap,
 *			  cursor, etc) but they can also be specified with
 *			  a filename. This renders my filename-scanning scheme
 *			  worthless. Need to build newline parsing to solve
 *			  this one.
 *			  It will come with version 1.1.0 (sigh).
 *
 * 19-May-1998 BS	- Started to build a builtin preprocessor
 *
 * 30-Apr-1998 BS	- Redid the stringtable parsing/handling. My previous
 *			  ideas had some serious flaws.
 *
 * 27-Apr-1998 BS	- Removed a lot of dead comments and put it in a doc
 *			  file.
 *
 * 21-Apr-1998 BS	- Added correct behavior for cursors and icons.
 *			- This file is growing too big. It is time to strip
 *			  things and put it in a support file.
 *
 * 19-Apr-1998 BS	- Tagged the stringtable resource so that only one
 *			  resource will be created. This because the table
 *			  has a different layout than other resources. The
 *			  table has to be sorted, and divided into smaller
 *			  resource entries (see comment in source).
 *
 * 17-Apr-1998 BS	- Almost all strings, including identifiers, are parsed
 *			  as string_t which include unicode strings upon
 *			  input.
 *			- Parser now emits a warning when compiling win32
 *			  extensions in win16 mode.
 *
 * 16-Apr-1998 BS	- Raw data elements are now *optionally* separated
 *			  by commas. Read the comments in file sq2dq.l.
 *			- FIXME: there are instances in the source that rely
 *			  on the fact that int==32bit and pointers are int size.
 *			- Fixed the conflict in menuex by changing a rule
 *			  back into right recursion. See note in source.
 *			- UserType resources cannot have an expression as its
 *			  typeclass. See note in source.
 *
 * 15-Apr-1998 BS	- Changed all right recursion into left recursion to
 *			  get reduction of the parsestack.
 *			  This also helps communication between bison and flex.
 *			  Main advantage is that the Empty rule gets reduced
 *			  first, which is used to allocate/link things.
 *			  It also added a shift/reduce conflict in the menuex
 *			  handling, due to expression/option possibility,
 *			  although not serious.
 *
 * 14-Apr-1998 BS	- Redone almost the entire parser. We're not talking
 *			  about making it more efficient, but readable (for me)
 *			  and slightly easier to expand/change.
 *			  This is done primarily by using more reduce states
 *			  with many (intuitive) types for the various resource
 *			  statements.
 *			- Added expression handling for all resources where a
 *			  number is accepted (not only for win32). Also added
 *			  multiply and division (not MS compatible, but handy).
 *			  Unary minus introduced a shift/reduce conflict, but
 *			  it is not serious.
 *
 * 13-Apr-1998 BS	- Reordered a lot of things
 *			- Made the source more readable
 *			- Added Win32 resource definitions
 *			- Corrected syntax problems with an old yacc (;)
 *			- Added extra comment about grammar
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "../tools.h"
#include "wrc.h"
#include "utils.h"
#include "newstruc.h"
#include "wpp_private.h"
#include "parser.h"
#include "windef.h"
#include "winbase.h"
#include "wingdi.h"
#include "winuser.h"

int want_nl = 0;	/* Signal flex that we need the next newline */
int want_id = 0;	/* Signal flex that we need the next identifier */
static stringtable_t *tagstt;	/* Stringtable tag.
			 * It is set while parsing a stringtable to one of
			 * the stringtables in the sttres list or a new one
			 * if the language was not parsed before.
			 */
static stringtable_t *sttres;	/* Stringtable resources. This holds the list of
			 * stringtables with different lanuages
			 */
static int dont_want_id = 0;	/* See language parsing for details */

/* Set to the current options of the currently scanning stringtable */
static int *tagstt_memopt;
static characts_t tagstt_characts;
static version_t tagstt_version;

static const char riff[4] = "RIFF";	/* RIFF file magic for animated cursor/icon */

/* Prototypes of here defined functions */
static event_t *get_event_head(event_t *p);
static control_t *get_control_head(control_t *p);
static ver_value_t *get_ver_value_head(ver_value_t *p);
static ver_block_t *get_ver_block_head(ver_block_t *p);
static resource_t *get_resource_head(resource_t *p);
static menu_item_t *get_item_head(menu_item_t *p);
static raw_data_t *merge_raw_data_str(raw_data_t *r1, string_t *str);
static raw_data_t *merge_raw_data_int(raw_data_t *r1, int i);
static raw_data_t *merge_raw_data_long(raw_data_t *r1, int i);
static raw_data_t *merge_raw_data(raw_data_t *r1, raw_data_t *r2);
static raw_data_t *str2raw_data(string_t *str);
static raw_data_t *int2raw_data(int i);
static raw_data_t *long2raw_data(int i);
static raw_data_t *load_file(string_t *name, language_t lang);
static itemex_opt_t *new_itemex_opt(int id, int type, int state, int helpid);
static event_t *add_string_event(string_t *key, int id, int flags, event_t *prev);
static event_t *add_event(int key, int id, int flags, event_t *prev);
static name_id_t *convert_ctlclass(name_id_t *cls);
static control_t *ins_ctrl(int type, int special_style, control_t *ctrl, control_t *prev);
static dialog_t *dialog_version(version_t v, dialog_t *dlg);
static dialog_t *dialog_characteristics(characts_t c, dialog_t *dlg);
static dialog_t *dialog_language(language_t l, dialog_t *dlg);
static dialog_t *dialog_menu(name_id_t *m, dialog_t *dlg);
static dialog_t *dialog_class(name_id_t *n, dialog_t *dlg);
static dialog_t *dialog_font(font_id_t *f, dialog_t *dlg);
static dialog_t *dialog_caption(string_t *s, dialog_t *dlg);
static dialog_t *dialog_exstyle(style_t * st, dialog_t *dlg);
static dialog_t *dialog_style(style_t * st, dialog_t *dlg);
static resource_t *build_stt_resources(stringtable_t *stthead);
static stringtable_t *find_stringtable(lvc_t *lvc);
static toolbar_item_t *ins_tlbr_button(toolbar_item_t *prev, toolbar_item_t *idrec);
static toolbar_item_t *get_tlbr_buttons_head(toolbar_item_t *p, int *nitems);
static string_t *make_filename(string_t *s);
static resource_t *build_fontdirs(resource_t *tail);
static resource_t *build_fontdir(resource_t **fnt, int nfnt);
static int rsrcid_to_token(int lookahead);

/* bison >= 3.6 applies api.prefix also to YYEMPTY */
#define YYEMPTY (-2)


#line 284 "tools/wrc/parser.tab.c"

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
    tNL = 258,                     /* tNL  */
    tNUMBER = 259,                 /* tNUMBER  */
    tLNUMBER = 260,                /* tLNUMBER  */
    tSTRING = 261,                 /* tSTRING  */
    tIDENT = 262,                  /* tIDENT  */
    tRAWDATA = 263,                /* tRAWDATA  */
    tACCELERATORS = 264,           /* tACCELERATORS  */
    tBITMAP = 265,                 /* tBITMAP  */
    tCURSOR = 266,                 /* tCURSOR  */
    tDIALOG = 267,                 /* tDIALOG  */
    tDIALOGEX = 268,               /* tDIALOGEX  */
    tMENU = 269,                   /* tMENU  */
    tMENUEX = 270,                 /* tMENUEX  */
    tMESSAGETABLE = 271,           /* tMESSAGETABLE  */
    tRCDATA = 272,                 /* tRCDATA  */
    tVERSIONINFO = 273,            /* tVERSIONINFO  */
    tSTRINGTABLE = 274,            /* tSTRINGTABLE  */
    tFONT = 275,                   /* tFONT  */
    tFONTDIR = 276,                /* tFONTDIR  */
    tICON = 277,                   /* tICON  */
    tHTML = 278,                   /* tHTML  */
    tAUTO3STATE = 279,             /* tAUTO3STATE  */
    tAUTOCHECKBOX = 280,           /* tAUTOCHECKBOX  */
    tAUTORADIOBUTTON = 281,        /* tAUTORADIOBUTTON  */
    tCHECKBOX = 282,               /* tCHECKBOX  */
    tDEFPUSHBUTTON = 283,          /* tDEFPUSHBUTTON  */
    tPUSHBUTTON = 284,             /* tPUSHBUTTON  */
    tRADIOBUTTON = 285,            /* tRADIOBUTTON  */
    tSTATE3 = 286,                 /* tSTATE3  */
    tGROUPBOX = 287,               /* tGROUPBOX  */
    tCOMBOBOX = 288,               /* tCOMBOBOX  */
    tLISTBOX = 289,                /* tLISTBOX  */
    tSCROLLBAR = 290,              /* tSCROLLBAR  */
    tCONTROL = 291,                /* tCONTROL  */
    tEDITTEXT = 292,               /* tEDITTEXT  */
    tRTEXT = 293,                  /* tRTEXT  */
    tCTEXT = 294,                  /* tCTEXT  */
    tLTEXT = 295,                  /* tLTEXT  */
    tBLOCK = 296,                  /* tBLOCK  */
    tVALUE = 297,                  /* tVALUE  */
    tSHIFT = 298,                  /* tSHIFT  */
    tALT = 299,                    /* tALT  */
    tASCII = 300,                  /* tASCII  */
    tVIRTKEY = 301,                /* tVIRTKEY  */
    tGRAYED = 302,                 /* tGRAYED  */
    tCHECKED = 303,                /* tCHECKED  */
    tINACTIVE = 304,               /* tINACTIVE  */
    tNOINVERT = 305,               /* tNOINVERT  */
    tPURE = 306,                   /* tPURE  */
    tIMPURE = 307,                 /* tIMPURE  */
    tDISCARDABLE = 308,            /* tDISCARDABLE  */
    tLOADONCALL = 309,             /* tLOADONCALL  */
    tPRELOAD = 310,                /* tPRELOAD  */
    tFIXED = 311,                  /* tFIXED  */
    tMOVEABLE = 312,               /* tMOVEABLE  */
    tCLASS = 313,                  /* tCLASS  */
    tCAPTION = 314,                /* tCAPTION  */
    tCHARACTERISTICS = 315,        /* tCHARACTERISTICS  */
    tEXSTYLE = 316,                /* tEXSTYLE  */
    tSTYLE = 317,                  /* tSTYLE  */
    tVERSION = 318,                /* tVERSION  */
    tLANGUAGE = 319,               /* tLANGUAGE  */
    tFILEVERSION = 320,            /* tFILEVERSION  */
    tPRODUCTVERSION = 321,         /* tPRODUCTVERSION  */
    tFILEFLAGSMASK = 322,          /* tFILEFLAGSMASK  */
    tFILEOS = 323,                 /* tFILEOS  */
    tFILETYPE = 324,               /* tFILETYPE  */
    tFILEFLAGS = 325,              /* tFILEFLAGS  */
    tFILESUBTYPE = 326,            /* tFILESUBTYPE  */
    tMENUBARBREAK = 327,           /* tMENUBARBREAK  */
    tMENUBREAK = 328,              /* tMENUBREAK  */
    tMENUITEM = 329,               /* tMENUITEM  */
    tPOPUP = 330,                  /* tPOPUP  */
    tSEPARATOR = 331,              /* tSEPARATOR  */
    tHELP = 332,                   /* tHELP  */
    tTOOLBAR = 333,                /* tTOOLBAR  */
    tBUTTON = 334,                 /* tBUTTON  */
    tBEGIN = 335,                  /* tBEGIN  */
    tEND = 336,                    /* tEND  */
    tDLGINIT = 337,                /* tDLGINIT  */
    tNOT = 338,                    /* tNOT  */
    pUPM = 339                     /* pUPM  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 208 "tools/wrc/parser.y"

	string_t	*str;
	int		num;
	int		*iptr;
	char		*cptr;
	resource_t	*res;
	accelerator_t	*acc;
	bitmap_t	*bmp;
	dialog_t	*dlg;
	font_t		*fnt;
	fontdir_t	*fnd;
	menu_t		*men;
	html_t		*html;
	rcdata_t	*rdt;
	stringtable_t	*stt;
	stt_entry_t	*stte;
	user_t		*usr;
	messagetable_t	*msg;
	versioninfo_t	*veri;
	control_t	*ctl;
	name_id_t	*nid;
	font_id_t	*fntid;
	language_t	lan;
	version_t	ver;
	characts_t	chars;
	event_t		*event;
	menu_item_t	*menitm;
	itemex_opt_t	*exopt;
	raw_data_t	*raw;
	lvc_t		*lvc;
	ver_value_t	*val;
	ver_block_t	*blk;
	ver_words_t	*verw;
	toolbar_t	*tlbar;
	toolbar_item_t	*tlbarItems;
	dlginit_t       *dginit;
	style_pair_t	*styles;
	style_t		*style;
	ani_any_t	*ani;

#line 464 "tools/wrc/parser.tab.c"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif


extern PARSER_STYPE parser_lval;


int parser_parse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tNL = 3,                        /* tNL  */
  YYSYMBOL_tNUMBER = 4,                    /* tNUMBER  */
  YYSYMBOL_tLNUMBER = 5,                   /* tLNUMBER  */
  YYSYMBOL_tSTRING = 6,                    /* tSTRING  */
  YYSYMBOL_tIDENT = 7,                     /* tIDENT  */
  YYSYMBOL_tRAWDATA = 8,                   /* tRAWDATA  */
  YYSYMBOL_tACCELERATORS = 9,              /* tACCELERATORS  */
  YYSYMBOL_tBITMAP = 10,                   /* tBITMAP  */
  YYSYMBOL_tCURSOR = 11,                   /* tCURSOR  */
  YYSYMBOL_tDIALOG = 12,                   /* tDIALOG  */
  YYSYMBOL_tDIALOGEX = 13,                 /* tDIALOGEX  */
  YYSYMBOL_tMENU = 14,                     /* tMENU  */
  YYSYMBOL_tMENUEX = 15,                   /* tMENUEX  */
  YYSYMBOL_tMESSAGETABLE = 16,             /* tMESSAGETABLE  */
  YYSYMBOL_tRCDATA = 17,                   /* tRCDATA  */
  YYSYMBOL_tVERSIONINFO = 18,              /* tVERSIONINFO  */
  YYSYMBOL_tSTRINGTABLE = 19,              /* tSTRINGTABLE  */
  YYSYMBOL_tFONT = 20,                     /* tFONT  */
  YYSYMBOL_tFONTDIR = 21,                  /* tFONTDIR  */
  YYSYMBOL_tICON = 22,                     /* tICON  */
  YYSYMBOL_tHTML = 23,                     /* tHTML  */
  YYSYMBOL_tAUTO3STATE = 24,               /* tAUTO3STATE  */
  YYSYMBOL_tAUTOCHECKBOX = 25,             /* tAUTOCHECKBOX  */
  YYSYMBOL_tAUTORADIOBUTTON = 26,          /* tAUTORADIOBUTTON  */
  YYSYMBOL_tCHECKBOX = 27,                 /* tCHECKBOX  */
  YYSYMBOL_tDEFPUSHBUTTON = 28,            /* tDEFPUSHBUTTON  */
  YYSYMBOL_tPUSHBUTTON = 29,               /* tPUSHBUTTON  */
  YYSYMBOL_tRADIOBUTTON = 30,              /* tRADIOBUTTON  */
  YYSYMBOL_tSTATE3 = 31,                   /* tSTATE3  */
  YYSYMBOL_tGROUPBOX = 32,                 /* tGROUPBOX  */
  YYSYMBOL_tCOMBOBOX = 33,                 /* tCOMBOBOX  */
  YYSYMBOL_tLISTBOX = 34,                  /* tLISTBOX  */
  YYSYMBOL_tSCROLLBAR = 35,                /* tSCROLLBAR  */
  YYSYMBOL_tCONTROL = 36,                  /* tCONTROL  */
  YYSYMBOL_tEDITTEXT = 37,                 /* tEDITTEXT  */
  YYSYMBOL_tRTEXT = 38,                    /* tRTEXT  */
  YYSYMBOL_tCTEXT = 39,                    /* tCTEXT  */
  YYSYMBOL_tLTEXT = 40,                    /* tLTEXT  */
  YYSYMBOL_tBLOCK = 41,                    /* tBLOCK  */
  YYSYMBOL_tVALUE = 42,                    /* tVALUE  */
  YYSYMBOL_tSHIFT = 43,                    /* tSHIFT  */
  YYSYMBOL_tALT = 44,                      /* tALT  */
  YYSYMBOL_tASCII = 45,                    /* tASCII  */
  YYSYMBOL_tVIRTKEY = 46,                  /* tVIRTKEY  */
  YYSYMBOL_tGRAYED = 47,                   /* tGRAYED  */
  YYSYMBOL_tCHECKED = 48,                  /* tCHECKED  */
  YYSYMBOL_tINACTIVE = 49,                 /* tINACTIVE  */
  YYSYMBOL_tNOINVERT = 50,                 /* tNOINVERT  */
  YYSYMBOL_tPURE = 51,                     /* tPURE  */
  YYSYMBOL_tIMPURE = 52,                   /* tIMPURE  */
  YYSYMBOL_tDISCARDABLE = 53,              /* tDISCARDABLE  */
  YYSYMBOL_tLOADONCALL = 54,               /* tLOADONCALL  */
  YYSYMBOL_tPRELOAD = 55,                  /* tPRELOAD  */
  YYSYMBOL_tFIXED = 56,                    /* tFIXED  */
  YYSYMBOL_tMOVEABLE = 57,                 /* tMOVEABLE  */
  YYSYMBOL_tCLASS = 58,                    /* tCLASS  */
  YYSYMBOL_tCAPTION = 59,                  /* tCAPTION  */
  YYSYMBOL_tCHARACTERISTICS = 60,          /* tCHARACTERISTICS  */
  YYSYMBOL_tEXSTYLE = 61,                  /* tEXSTYLE  */
  YYSYMBOL_tSTYLE = 62,                    /* tSTYLE  */
  YYSYMBOL_tVERSION = 63,                  /* tVERSION  */
  YYSYMBOL_tLANGUAGE = 64,                 /* tLANGUAGE  */
  YYSYMBOL_tFILEVERSION = 65,              /* tFILEVERSION  */
  YYSYMBOL_tPRODUCTVERSION = 66,           /* tPRODUCTVERSION  */
  YYSYMBOL_tFILEFLAGSMASK = 67,            /* tFILEFLAGSMASK  */
  YYSYMBOL_tFILEOS = 68,                   /* tFILEOS  */
  YYSYMBOL_tFILETYPE = 69,                 /* tFILETYPE  */
  YYSYMBOL_tFILEFLAGS = 70,                /* tFILEFLAGS  */
  YYSYMBOL_tFILESUBTYPE = 71,              /* tFILESUBTYPE  */
  YYSYMBOL_tMENUBARBREAK = 72,             /* tMENUBARBREAK  */
  YYSYMBOL_tMENUBREAK = 73,                /* tMENUBREAK  */
  YYSYMBOL_tMENUITEM = 74,                 /* tMENUITEM  */
  YYSYMBOL_tPOPUP = 75,                    /* tPOPUP  */
  YYSYMBOL_tSEPARATOR = 76,                /* tSEPARATOR  */
  YYSYMBOL_tHELP = 77,                     /* tHELP  */
  YYSYMBOL_tTOOLBAR = 78,                  /* tTOOLBAR  */
  YYSYMBOL_tBUTTON = 79,                   /* tBUTTON  */
  YYSYMBOL_tBEGIN = 80,                    /* tBEGIN  */
  YYSYMBOL_tEND = 81,                      /* tEND  */
  YYSYMBOL_tDLGINIT = 82,                  /* tDLGINIT  */
  YYSYMBOL_83_ = 83,                       /* '|'  */
  YYSYMBOL_84_ = 84,                       /* '^'  */
  YYSYMBOL_85_ = 85,                       /* '&'  */
  YYSYMBOL_86_ = 86,                       /* '+'  */
  YYSYMBOL_87_ = 87,                       /* '-'  */
  YYSYMBOL_88_ = 88,                       /* '*'  */
  YYSYMBOL_89_ = 89,                       /* '/'  */
  YYSYMBOL_90_ = 90,                       /* '~'  */
  YYSYMBOL_tNOT = 91,                      /* tNOT  */
  YYSYMBOL_pUPM = 92,                      /* pUPM  */
  YYSYMBOL_93_ = 93,                       /* ','  */
  YYSYMBOL_94_ = 94,                       /* '('  */
  YYSYMBOL_95_ = 95,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_resource_file = 97,             /* resource_file  */
  YYSYMBOL_resources = 98,                 /* resources  */
  YYSYMBOL_resource = 99,                  /* resource  */
  YYSYMBOL_100_1 = 100,                    /* $@1  */
  YYSYMBOL_usrcvt = 101,                   /* usrcvt  */
  YYSYMBOL_nameid = 102,                   /* nameid  */
  YYSYMBOL_nameid_s = 103,                 /* nameid_s  */
  YYSYMBOL_resource_definition = 104,      /* resource_definition  */
  YYSYMBOL_filename = 105,                 /* filename  */
  YYSYMBOL_bitmap = 106,                   /* bitmap  */
  YYSYMBOL_cursor = 107,                   /* cursor  */
  YYSYMBOL_icon = 108,                     /* icon  */
  YYSYMBOL_font = 109,                     /* font  */
  YYSYMBOL_fontdir = 110,                  /* fontdir  */
  YYSYMBOL_messagetable = 111,             /* messagetable  */
  YYSYMBOL_html = 112,                     /* html  */
  YYSYMBOL_rcdata = 113,                   /* rcdata  */
  YYSYMBOL_dlginit = 114,                  /* dlginit  */
  YYSYMBOL_userres = 115,                  /* userres  */
  YYSYMBOL_usertype = 116,                 /* usertype  */
  YYSYMBOL_accelerators = 117,             /* accelerators  */
  YYSYMBOL_events = 118,                   /* events  */
  YYSYMBOL_acc_opt = 119,                  /* acc_opt  */
  YYSYMBOL_accs = 120,                     /* accs  */
  YYSYMBOL_acc = 121,                      /* acc  */
  YYSYMBOL_dialog = 122,                   /* dialog  */
  YYSYMBOL_dlg_attributes = 123,           /* dlg_attributes  */
  YYSYMBOL_ctrls = 124,                    /* ctrls  */
  YYSYMBOL_lab_ctrl = 125,                 /* lab_ctrl  */
  YYSYMBOL_ctrl_desc = 126,                /* ctrl_desc  */
  YYSYMBOL_iconinfo = 127,                 /* iconinfo  */
  YYSYMBOL_gen_ctrl = 128,                 /* gen_ctrl  */
  YYSYMBOL_opt_font = 129,                 /* opt_font  */
  YYSYMBOL_optional_style_pair = 130,      /* optional_style_pair  */
  YYSYMBOL_style = 131,                    /* style  */
  YYSYMBOL_ctlclass = 132,                 /* ctlclass  */
  YYSYMBOL_dialogex = 133,                 /* dialogex  */
  YYSYMBOL_dlgex_attribs = 134,            /* dlgex_attribs  */
  YYSYMBOL_exctrls = 135,                  /* exctrls  */
  YYSYMBOL_gen_exctrl = 136,               /* gen_exctrl  */
  YYSYMBOL_lab_exctrl = 137,               /* lab_exctrl  */
  YYSYMBOL_exctrl_desc = 138,              /* exctrl_desc  */
  YYSYMBOL_opt_data = 139,                 /* opt_data  */
  YYSYMBOL_helpid = 140,                   /* helpid  */
  YYSYMBOL_opt_exfont = 141,               /* opt_exfont  */
  YYSYMBOL_opt_expr = 142,                 /* opt_expr  */
  YYSYMBOL_menu = 143,                     /* menu  */
  YYSYMBOL_menu_body = 144,                /* menu_body  */
  YYSYMBOL_item_definitions = 145,         /* item_definitions  */
  YYSYMBOL_item_options = 146,             /* item_options  */
  YYSYMBOL_menuex = 147,                   /* menuex  */
  YYSYMBOL_menuex_body = 148,              /* menuex_body  */
  YYSYMBOL_itemex_definitions = 149,       /* itemex_definitions  */
  YYSYMBOL_itemex_options = 150,           /* itemex_options  */
  YYSYMBOL_itemex_p_options = 151,         /* itemex_p_options  */
  YYSYMBOL_stringtable = 152,              /* stringtable  */
  YYSYMBOL_stt_head = 153,                 /* stt_head  */
  YYSYMBOL_strings = 154,                  /* strings  */
  YYSYMBOL_opt_comma = 155,                /* opt_comma  */
  YYSYMBOL_versioninfo = 156,              /* versioninfo  */
  YYSYMBOL_fix_version = 157,              /* fix_version  */
  YYSYMBOL_ver_blocks = 158,               /* ver_blocks  */
  YYSYMBOL_ver_block = 159,                /* ver_block  */
  YYSYMBOL_ver_values = 160,               /* ver_values  */
  YYSYMBOL_ver_value = 161,                /* ver_value  */
  YYSYMBOL_ver_words = 162,                /* ver_words  */
  YYSYMBOL_toolbar = 163,                  /* toolbar  */
  YYSYMBOL_toolbar_items = 164,            /* toolbar_items  */
  YYSYMBOL_loadmemopts = 165,              /* loadmemopts  */
  YYSYMBOL_lamo = 166,                     /* lamo  */
  YYSYMBOL_lama = 167,                     /* lama  */
  YYSYMBOL_opt_lvc = 168,                  /* opt_lvc  */
  YYSYMBOL_opt_language = 169,             /* opt_language  */
  YYSYMBOL_opt_characts = 170,             /* opt_characts  */
  YYSYMBOL_opt_version = 171,              /* opt_version  */
  YYSYMBOL_raw_data = 172,                 /* raw_data  */
  YYSYMBOL_raw_elements = 173,             /* raw_elements  */
  YYSYMBOL_file_raw = 174,                 /* file_raw  */
  YYSYMBOL_e_expr = 175,                   /* e_expr  */
  YYSYMBOL_expr = 176,                     /* expr  */
  YYSYMBOL_xpr = 177,                      /* xpr  */
  YYSYMBOL_any_num = 178                   /* any_num  */
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
         || (defined PARSER_STYPE_IS_TRIVIAL && PARSER_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   724

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  258
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  572

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   339


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
       2,     2,     2,     2,     2,     2,     2,     2,    85,     2,
      94,    95,    88,    86,    93,    87,     2,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    83,     2,    90,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    91,    92
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   324,   324,   370,   371,   441,   447,   458,   467,   475,
     475,   517,   523,   530,   540,   541,   550,   551,   552,   574,
     575,   581,   582,   583,   584,   606,   607,   613,   614,   615,
     616,   617,   618,   622,   623,   627,   631,   647,   669,   679,
     687,   695,   699,   703,   707,   712,   717,   726,   749,   750,
     751,   760,   761,   764,   765,   768,   769,   770,   771,   772,
     773,   778,   812,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   833,   835,   836,   837,   838,   839,   840,   841,   842,
     844,   854,   877,   899,   901,   906,   913,   924,   938,   953,
     958,   959,   960,   964,   965,   966,   967,   971,   976,   984,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1049,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1060,
    1070,  1095,  1111,  1137,  1160,  1161,  1164,  1165,  1169,  1176,
    1177,  1181,  1203,  1207,  1208,  1217,  1223,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1253,  1278,  1282,  1283,  1299,
    1305,  1325,  1326,  1330,  1338,  1349,  1350,  1354,  1360,  1368,
    1388,  1426,  1436,  1437,  1471,  1472,  1477,  1493,  1494,  1504,
    1514,  1521,  1528,  1535,  1542,  1552,  1553,  1562,  1570,  1571,
    1580,  1585,  1591,  1600,  1601,  1605,  1628,  1629,  1634,  1643,
    1644,  1654,  1669,  1671,  1673,  1675,  1679,  1681,  1683,  1688,
    1689,  1697,  1705,  1723,  1730,  1734,  1738,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1768,
    1769,  1776,  1777,  1781,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1799,  1800
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
  "\"end of file\"", "error", "\"invalid token\"", "tNL", "tNUMBER",
  "tLNUMBER", "tSTRING", "tIDENT", "tRAWDATA", "tACCELERATORS", "tBITMAP",
  "tCURSOR", "tDIALOG", "tDIALOGEX", "tMENU", "tMENUEX", "tMESSAGETABLE",
  "tRCDATA", "tVERSIONINFO", "tSTRINGTABLE", "tFONT", "tFONTDIR", "tICON",
  "tHTML", "tAUTO3STATE", "tAUTOCHECKBOX", "tAUTORADIOBUTTON", "tCHECKBOX",
  "tDEFPUSHBUTTON", "tPUSHBUTTON", "tRADIOBUTTON", "tSTATE3", "tGROUPBOX",
  "tCOMBOBOX", "tLISTBOX", "tSCROLLBAR", "tCONTROL", "tEDITTEXT", "tRTEXT",
  "tCTEXT", "tLTEXT", "tBLOCK", "tVALUE", "tSHIFT", "tALT", "tASCII",
  "tVIRTKEY", "tGRAYED", "tCHECKED", "tINACTIVE", "tNOINVERT", "tPURE",
  "tIMPURE", "tDISCARDABLE", "tLOADONCALL", "tPRELOAD", "tFIXED",
  "tMOVEABLE", "tCLASS", "tCAPTION", "tCHARACTERISTICS", "tEXSTYLE",
  "tSTYLE", "tVERSION", "tLANGUAGE", "tFILEVERSION", "tPRODUCTVERSION",
  "tFILEFLAGSMASK", "tFILEOS", "tFILETYPE", "tFILEFLAGS", "tFILESUBTYPE",
  "tMENUBARBREAK", "tMENUBREAK", "tMENUITEM", "tPOPUP", "tSEPARATOR",
  "tHELP", "tTOOLBAR", "tBUTTON", "tBEGIN", "tEND", "tDLGINIT", "'|'",
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'~'", "tNOT", "pUPM", "','",
  "'('", "')'", "$accept", "resource_file", "resources", "resource", "$@1",
  "usrcvt", "nameid", "nameid_s", "resource_definition", "filename",
  "bitmap", "cursor", "icon", "font", "fontdir", "messagetable", "html",
  "rcdata", "dlginit", "userres", "usertype", "accelerators", "events",
  "acc_opt", "accs", "acc", "dialog", "dlg_attributes", "ctrls",
  "lab_ctrl", "ctrl_desc", "iconinfo", "gen_ctrl", "opt_font",
  "optional_style_pair", "style", "ctlclass", "dialogex", "dlgex_attribs",
  "exctrls", "gen_exctrl", "lab_exctrl", "exctrl_desc", "opt_data",
  "helpid", "opt_exfont", "opt_expr", "menu", "menu_body",
  "item_definitions", "item_options", "menuex", "menuex_body",
  "itemex_definitions", "itemex_options", "itemex_p_options",
  "stringtable", "stt_head", "strings", "opt_comma", "versioninfo",
  "fix_version", "ver_blocks", "ver_block", "ver_values", "ver_value",
  "ver_words", "toolbar", "toolbar_items", "loadmemopts", "lamo", "lama",
  "opt_lvc", "opt_language", "opt_characts", "opt_version", "raw_data",
  "raw_elements", "file_raw", "e_expr", "expr", "xpr", "any_num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-521)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-243)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -521,     3,     9,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
     282,   282,   282,    36,   282,  -521,  -521,   -69,  -521,   628,
    -521,   371,   667,   282,  -521,  -521,  -521,  -521,   432,  -521,
     371,   282,   282,   282,   282,   282,   282,   282,  -521,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,  -521,  -521,   252,   -66,  -521,   111,  -521,   393,
     255,   241,    90,    90,  -521,  -521,   667,   440,   440,    86,
      86,   667,   667,   440,   440,   667,   440,   440,   440,   440,
      86,   440,   440,   282,   282,   282,  -521,  -521,  -521,   282,
    -521,   -39,    14,  -521,  -521,  -521,   148,  -521,  -521,  -521,
     -37,   -22,   196,   198,  -521,  -521,   337,  -521,  -521,  -521,
    -521,    -1,  -521,  -521,  -521,  -521,    16,  -521,  -521,   101,
    -521,     2,   282,   282,  -521,  -521,  -521,  -521,   282,   282,
     282,   282,   282,   282,   282,  -521,   282,   282,  -521,   214,
    -521,  -521,  -521,  -521,   209,   -23,    38,    40,    73,   119,
      56,    89,  -521,  -521,  -521,  -521,  -521,   -36,  -521,  -521,
     114,  -521,   122,  -521,  -521,  -521,    18,   282,   282,    11,
     160,  -521,    53,   216,  -521,   282,   282,   223,  -521,  -521,
     203,   282,   282,  -521,  -521,  -521,  -521,   236,   145,   153,
     -39,  -521,   486,   159,  -521,   175,   177,   182,   173,  -521,
     199,   199,  -521,  -521,   282,   282,   282,   486,   486,   486,
     486,   486,   486,   486,   218,   282,  -521,   282,   222,   282,
     282,  -521,     7,   660,  -521,  -521,  -521,   201,   486,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,   210,   224,   227,
     224,  -521,   228,   240,   -12,  -521,   282,  -521,  -521,  -521,
    -521,  -521,  -521,  -521,   244,  -521,   381,   282,  -521,  -521,
     282,   282,   282,   282,   303,  -521,  -521,  -521,  -521,   660,
     232,   282,   220,   332,    61,    61,  -521,  -521,  -521,  -521,
    -521,  -521,   396,   577,  -521,   253,   224,  -521,  -521,   258,
    -521,  -521,  -521,  -521,   259,  -521,  -521,  -521,  -521,    36,
      61,   272,  -521,   272,   564,   232,   282,   220,   350,    61,
      61,  -521,  -521,  -521,  -521,  -521,  -521,    97,  -521,   282,
     245,   356,  -521,    35,    61,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   282,   282,   282,   220,   282,
     220,   220,   220,  -521,  -521,   277,  -521,  -521,   272,   272,
     583,  -521,   278,   224,  -521,   284,  -521,  -521,  -521,  -521,
     -39,   -39,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,   286,  -521,  -521,   -39,  -521,  -521,  -521,  -521,
    -521,   360,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   282,   282,   282,   220,   282,   220,   220,   220,
    -521,   282,   282,   282,   282,   282,   282,   297,   -39,   -39,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
     305,  -521,  -521,   -39,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,   307,   316,   318,   319,   282,   282,   282,   282,   282,
     282,   282,   282,   267,   320,   321,   322,   325,   326,   330,
     333,   334,  -521,   335,  -521,   282,   282,   282,   282,   267,
     282,   282,   282,    61,   342,   343,   344,   345,   355,   357,
     358,   359,    21,   282,  -521,   282,   282,   282,    61,   282,
    -521,   282,   282,   282,  -521,   357,   369,   379,    70,   380,
     382,   405,   406,  -521,   282,   282,   282,   282,   282,    61,
    -521,   282,   407,   405,   409,   413,   405,    88,   415,   282,
     201,   282,    61,  -521,    61,   282,   405,   233,   419,    92,
     272,   421,   201,  -521,  -521,   282,    61,   282,   233,   437,
     272,   438,  -521,   282,    61,     0,   272,    61,  -521,   161,
     233,  -521
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,     0,     2,     1,     5,   257,   258,    11,   209,     9,
       0,     0,     0,     0,     0,     4,     8,     0,    11,   243,
     255,     0,   219,     0,   253,   252,   251,   256,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    46,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,     7,    17,    18,    24,
      22,    23,    27,    28,    29,    21,    31,   209,    16,    19,
      20,    25,    26,    32,    30,   215,   218,   214,   216,   212,
     217,   213,   210,   211,   181,     0,   254,     0,     6,   246,
     250,   247,   244,   245,   248,   249,   219,   219,   219,     0,
       0,   219,   219,   219,   219,   187,   219,   219,   219,   219,
       0,   219,   219,     0,     0,     0,   220,   221,   222,     0,
     180,   184,     0,    34,    33,   239,     0,   240,    35,    36,
       0,     0,     0,     0,    40,    42,     0,    38,    39,    37,
      41,     0,    43,    44,   224,   225,     0,    10,   185,     0,
      48,     0,     0,     0,   153,   151,   167,   165,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,   183,     0,
     228,   230,   232,   227,     0,   184,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   190,   194,     0,   219,   223,
       0,    47,     0,   229,   231,   226,     0,     0,     0,     0,
       0,   152,     0,     0,   166,     0,     0,     0,   186,   196,
       0,     0,     0,   234,   236,   238,   233,     0,     0,     0,
     184,   155,   157,   171,   169,   175,     0,     0,     0,   206,
      51,    51,   235,   237,     0,     0,     0,   157,   157,   157,
     157,   157,   157,   157,     0,   241,   168,   241,     0,     0,
       0,   198,     0,     0,    49,    50,    62,   146,   157,   160,
     159,   162,   163,   164,   161,   158,   156,     0,   172,     0,
     176,   170,     0,     0,     0,   208,     0,   205,    57,    56,
      58,    59,    60,    55,    52,    53,     0,     0,   110,   154,
     241,   241,     0,     0,     0,   197,   200,   199,   207,     0,
       0,     0,     0,     0,     0,     0,    72,    66,    69,    70,
      71,   147,     0,   157,   242,     0,   177,   188,   189,     0,
      54,    13,    68,    12,     0,    15,    14,    67,    65,     0,
       0,    64,   105,    63,     0,     0,     0,     0,     0,     0,
       0,   121,   114,   115,   118,   119,   120,   157,   173,   241,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,   117,     0,   116,   113,   112,   111,
       0,   174,     0,   178,   201,   202,   203,    99,   104,   103,
     184,   184,    83,    85,    86,    78,    79,    81,    82,    84,
      80,    76,     0,    75,    77,   184,    73,    74,    89,    88,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,    99,   184,   184,
     132,   134,   135,   127,   128,   130,   131,   133,   129,   125,
       0,   124,   126,   184,   122,   123,   138,   137,   136,   179,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,     0,    93,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
      90,     0,     0,     0,   150,    93,     0,     0,     0,     0,
       0,   100,     0,   139,     0,     0,     0,     0,     0,     0,
      92,     0,     0,   100,     0,    94,   100,   101,     0,     0,
     146,     0,     0,    91,     0,     0,   100,   144,     0,    95,
     102,     0,   146,   143,   145,     0,     0,     0,   144,     0,
      96,    98,   142,     0,     0,   144,    97,     0,   141,   146,
     144,   140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -521,  -521,  -521,  -521,  -521,   456,  -285,  -293,   395,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,  -521,   301,  -521,   237,  -521,  -521,  -521,   314,
     -85,    23,  -521,   229,  -347,  -287,    51,  -521,  -521,  -521,
    -521,   273,   -27,  -335,  -520,  -521,  -521,  -521,   298,  -521,
    -203,  -521,   299,  -521,  -521,  -521,  -521,  -521,  -521,  -174,
    -521,  -521,  -521,   276,  -521,  -521,  -521,  -521,  -521,   588,
    -521,  -521,   -20,  -261,  -255,  -244,  -486,  -521,   554,  -243,
      -2,   534,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    15,    23,    21,   326,   391,    56,   125,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   169,   254,   284,   285,    69,   286,   334,   392,
     401,   510,   406,   307,   530,   331,   483,    70,   312,   380,
     454,   440,   449,   553,   288,   343,   504,    71,   155,   178,
     265,    72,   157,   179,   246,   248,    16,    17,    87,   149,
      73,   136,   187,   209,   274,   297,   385,    74,   252,    22,
      82,    83,   126,   116,   117,   118,   127,   175,   128,   267,
     323,    19,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,   196,    84,     3,   269,   207,   170,   171,   172,   327,
     173,    29,     4,     5,     6,   322,     7,   220,   333,   244,
     547,    85,   213,   214,   215,   308,   216,   119,     8,   207,
     294,   309,   558,    27,   259,   260,   261,   262,   263,   264,
       5,     6,   310,   353,   376,   208,   236,   313,   315,   570,
     374,   344,   378,   379,   148,   289,   152,   345,   195,   223,
    -219,   554,   390,  -219,  -219,     5,     6,   389,   346,   295,
     148,   153,   554,     9,   113,   405,   122,   114,   115,   554,
    -219,   132,   133,   275,   554,   121,   276,   221,   277,   174,
       5,     6,   166,   567,   150,    10,    11,   130,   131,    12,
      13,     5,     6,    14,   354,   217,   382,   168,   141,   167,
     348,   144,   145,   146,   513,     5,     6,   147,   354,   438,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   224,
     388,   197,   453,   198,   439,   439,   439,    75,    76,    77,
      78,    79,    80,    81,   237,   238,   239,   199,   200,   205,
     176,   177,   329,   354,   201,   330,   180,   181,   182,   183,
     184,   185,   186,   526,   188,   189,   222,   192,   210,   240,
     241,   354,    10,    11,   242,   354,    12,    13,    36,    37,
      14,   544,   206,    10,    11,   556,   540,    12,    13,   543,
     243,    14,   120,   202,   203,   218,   219,    10,    11,   552,
     204,    12,    13,   226,   227,    14,   502,   211,   113,   230,
     231,   114,   115,   193,   194,   212,   433,   434,     5,     6,
     190,   518,   225,   562,     5,     6,   325,   321,   151,   228,
     568,   436,   256,   257,   258,   571,     5,     6,   234,   321,
     232,   233,   537,   268,   354,   270,   235,   272,   273,     5,
       6,   384,   245,   251,   287,   549,   113,   550,   113,   114,
     115,   114,   115,   113,   466,   467,   114,   115,   247,   560,
     249,     5,     6,   482,   298,   250,   154,   566,   156,   469,
     569,   403,   404,   229,   407,   311,     5,     6,   314,   316,
     317,   318,   253,  -219,   287,   191,  -219,  -219,   154,   324,
      10,    11,   156,   290,    12,    13,    10,    11,    14,   319,
      12,    13,   113,  -219,    14,   114,   115,  -242,    10,    11,
     291,   292,    12,    13,   332,   332,    14,    34,    35,    36,
      37,    10,    11,   293,   375,    12,    13,   299,   328,    14,
      33,    34,    35,    36,    37,   381,   349,   383,   386,   352,
     332,   350,   351,    10,    11,   354,   377,    12,    13,   332,
     332,    14,   387,   402,   402,   402,   437,   402,    10,    11,
     411,   431,    12,    13,   332,    38,    14,   432,    39,   435,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
     465,    50,    51,    52,    53,   300,   451,   452,   468,   455,
     470,   301,   158,   159,   160,   161,   162,   163,   164,   471,
     335,   472,   473,   485,   486,   487,   336,   165,   488,   489,
     450,   450,   450,   490,   450,    88,   491,   492,   493,   459,
     460,   461,   462,   463,   464,   503,   505,   506,   507,   302,
     303,   113,   304,   305,   114,   115,   123,   124,   508,    54,
     509,   511,   512,    55,   337,   338,   113,   339,   340,   114,
     115,   306,   524,   474,   475,   476,   477,   478,   479,   480,
     481,   484,   525,   527,    30,   528,   341,    32,    33,    34,
      35,    36,    37,   494,   495,   496,   497,   484,   499,   500,
     501,    75,    76,    77,    78,    79,    80,    81,   529,   531,
     539,   514,   541,   515,   516,   517,   542,   519,   545,   520,
     521,   522,   555,   332,   557,    31,    32,    33,    34,    35,
      36,    37,   532,   533,   534,   535,   536,    86,   332,   538,
     563,   564,   255,   237,   238,   239,   320,   546,   523,   548,
     498,   342,   266,   551,    24,    25,    26,   271,    28,   332,
     296,     0,     0,   559,     0,   561,     0,     0,   240,   241,
       0,   565,   332,   242,   332,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,   332,     0,     0,   243,
       0,     0,     0,     0,   332,     0,   355,   332,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   412,     0,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   237,   238,   239,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   373,     0,     0,     0,   240,
     241,     0,   129,     0,   242,   112,     0,   134,   135,     0,
     137,   138,   139,   140,   430,   142,   143,     0,     0,     0,
     347,   393,   394,   395,   396,   397,   398,   399,   400,     0,
       0,     0,     0,     0,   408,   409,   410,   441,   442,   443,
     444,   445,   446,   447,   448,     0,   278,     0,     0,     0,
     456,   457,   458,   279,   280,   281,   282,     0,     0,     0,
     283,    31,    32,    33,    34,    35,    36,    37,    75,    76,
      77,    78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       2,   175,    22,     0,   247,    41,     4,     5,     6,   302,
       8,    80,     3,     4,     5,   300,     7,     6,   305,   222,
     540,    23,     4,     5,     6,   286,     8,    93,    19,    41,
      42,   286,   552,    13,   237,   238,   239,   240,   241,   242,
       4,     5,   286,   330,   337,    81,   220,   290,   291,   569,
     335,   312,   339,   340,    93,   258,    93,   312,    81,     6,
      60,   547,   355,    63,    64,     4,     5,   354,   312,    81,
      93,    93,   558,    64,    60,   368,    96,    63,    64,   565,
      80,   101,   102,    76,   570,    87,    79,    76,    81,    87,
       4,     5,    93,    93,    80,    86,    87,    99,   100,    90,
      91,     4,     5,    94,    83,    87,   349,     6,   110,    93,
     313,   113,   114,   115,    93,     4,     5,   119,    83,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,    76,
      95,    93,   425,    93,   427,   428,   429,    51,    52,    53,
      54,    55,    56,    57,    47,    48,    49,    74,    75,    93,
     152,   153,    91,    83,    81,    94,   158,   159,   160,   161,
     162,   163,   164,    93,   166,   167,     6,   169,   188,    72,
      73,    83,    86,    87,    77,    83,    90,    91,    88,    89,
      94,    93,    93,    86,    87,    93,   533,    90,    91,   536,
      93,    94,    81,    74,    75,   197,   198,    86,    87,   546,
      81,    90,    91,   205,   206,    94,   493,    93,    60,   211,
     212,    63,    64,     4,     5,    93,   390,   391,     4,     5,
       6,   508,     6,   558,     4,     5,     6,     7,    80,     6,
     565,   405,   234,   235,   236,   570,     4,     5,    93,     7,
       4,     5,   529,   245,    83,   247,    93,   249,   250,     4,
       5,     6,    93,    80,    93,   542,    60,   544,    60,    63,
      64,    63,    64,    60,   438,   439,    63,    64,    93,   556,
      93,     4,     5,     6,   276,    93,    80,   564,    80,   453,
     567,   366,   367,    80,   369,   287,     4,     5,   290,   291,
     292,   293,    93,    60,    93,    81,    63,    64,    80,   301,
      86,    87,    80,    93,    90,    91,    86,    87,    94,     6,
      90,    91,    60,    80,    94,    63,    64,    93,    86,    87,
      93,    93,    90,    91,   304,   305,    94,    86,    87,    88,
      89,    86,    87,    93,   336,    90,    91,    93,     6,    94,
      85,    86,    87,    88,    89,   347,    93,   349,   350,   329,
     330,    93,    93,    86,    87,    83,     6,    90,    91,   339,
     340,    94,     6,   365,   366,   367,     6,   369,    86,    87,
      93,    93,    90,    91,   354,     4,    94,    93,     7,    93,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      93,    20,    21,    22,    23,    14,   423,   424,    93,   426,
      93,    20,    65,    66,    67,    68,    69,    70,    71,    93,
      14,    93,    93,    93,    93,    93,    20,    80,    93,    93,
     422,   423,   424,    93,   426,    30,    93,    93,    93,   431,
     432,   433,   434,   435,   436,    93,    93,    93,    93,    58,
      59,    60,    61,    62,    63,    64,     6,     7,    93,    78,
      93,    93,    93,    82,    58,    59,    60,    61,    62,    63,
      64,    80,    93,   465,   466,   467,   468,   469,   470,   471,
     472,   473,    93,    93,    18,    93,    80,    84,    85,    86,
      87,    88,    89,   485,   486,   487,   488,   489,   490,   491,
     492,    51,    52,    53,    54,    55,    56,    57,    93,    93,
      93,   503,    93,   505,   506,   507,    93,   509,    93,   511,
     512,   513,    93,   493,    93,    83,    84,    85,    86,    87,
      88,    89,   524,   525,   526,   527,   528,    95,   508,   531,
      93,    93,   231,    47,    48,    49,   299,   539,   515,   541,
     489,   312,   244,   545,    10,    11,    12,   248,    14,   529,
     274,    -1,    -1,   555,    -1,   557,    -1,    -1,    72,    73,
      -1,   563,   542,    77,   544,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,   556,    -1,    -1,    93,
      -1,    -1,    -1,    -1,   564,    -1,    22,   567,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    47,    48,    49,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    81,    -1,    -1,    -1,    72,
      73,    -1,    98,    -1,    77,    67,    -1,   103,   104,    -1,
     106,   107,   108,   109,    81,   111,   112,    -1,    -1,    -1,
      93,   357,   358,   359,   360,   361,   362,   363,   364,    -1,
      -1,    -1,    -1,    -1,   370,   371,   372,   414,   415,   416,
     417,   418,   419,   420,   421,    -1,    36,    -1,    -1,    -1,
     427,   428,   429,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    83,    84,    85,    86,    87,    88,    89,    51,    52,
      53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,    98,     0,     3,     4,     5,     7,    19,    64,
      86,    87,    90,    91,    94,    99,   152,   153,   176,   177,
     178,   101,   165,   100,   177,   177,   177,   178,   177,    80,
     101,    83,    84,    85,    86,    87,    88,    89,     4,     7,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      20,    21,    22,    23,    78,    82,   104,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   122,
     133,   143,   147,   156,   163,    51,    52,    53,    54,    55,
      56,    57,   166,   167,   168,   176,    95,   154,   104,   177,
     177,   177,   177,   177,   177,   177,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,    60,    63,    64,   169,   170,   171,    93,
      81,   176,   168,     6,     7,   105,   168,   172,   174,   174,
     176,   176,   168,   168,   174,   174,   157,   174,   174,   174,
     174,   176,   174,   174,   176,   176,   176,   176,    93,   155,
      80,    80,    93,    93,    80,   144,    80,   148,    65,    66,
      67,    68,    69,    70,    71,    80,    93,    93,     6,   118,
       4,     5,     6,     8,    87,   173,   176,   176,   145,   149,
     176,   176,   176,   176,   176,   176,   176,   158,   176,   176,
       6,    81,   176,     4,     5,    81,   155,    93,    93,    74,
      75,    81,    74,    75,    81,    93,    93,    41,    81,   159,
     168,    93,    93,     4,     5,     6,     8,    87,   176,   176,
       6,    76,     6,     6,    76,     6,   176,   176,     6,    80,
     176,   176,     4,     5,    93,    93,   155,    47,    48,    49,
      72,    73,    77,    93,   146,    93,   150,    93,   151,    93,
      93,    80,   164,    93,   119,   119,   176,   176,   176,   146,
     146,   146,   146,   146,   146,   146,   144,   175,   176,   175,
     176,   148,   176,   176,   160,    76,    79,    81,    36,    43,
      44,    45,    46,    50,   120,   121,   123,    93,   140,   146,
      93,    93,    93,    93,    42,    81,   159,   161,   176,    93,
      14,    20,    58,    59,    61,    62,    80,   129,   169,   170,
     171,   176,   134,   175,   176,   175,   176,   176,   176,     6,
     121,     7,   102,   176,   176,     6,   102,   103,     6,    91,
      94,   131,   178,   131,   124,    14,    20,    58,    59,    61,
      62,    80,   129,   141,   169,   170,   171,    93,   146,    93,
      93,    93,   178,   131,    83,    22,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    81,   102,   176,   103,     6,   131,   131,
     135,   176,   175,   176,     6,   162,   176,     6,    95,   131,
     103,   103,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   176,   126,   126,   103,   128,   126,   125,   125,
     125,    93,    22,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      81,    93,    93,   155,   155,    93,   155,     6,   103,   103,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     176,   138,   138,   103,   136,   138,   137,   137,   137,   176,
     176,   176,   176,   176,   176,    93,   155,   155,    93,   155,
      93,    93,    93,    93,   176,   176,   176,   176,   176,   176,
     176,   176,     6,   132,   176,    93,    93,    93,    93,    93,
      93,    93,    93,    93,   176,   176,   176,   176,   132,   176,
     176,   176,   131,    93,   142,    93,    93,    93,    93,    93,
     127,    93,    93,    93,   176,   176,   176,   176,   131,   176,
     176,   176,   176,   127,    93,    93,    93,    93,    93,    93,
     130,    93,   176,   176,   176,   176,   176,   131,   176,    93,
     130,    93,    93,   130,    93,    93,   176,   140,   176,   131,
     131,   176,   130,   139,   172,    93,    93,    93,   140,   176,
     131,   176,   139,    93,    93,   176,   131,    93,   139,   131,
     140,   139
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    98,    99,    99,    99,   100,
      99,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   116,   117,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     121,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   126,   127,   127,   127,   127,   128,   128,   129,
     130,   130,   130,   131,   131,   131,   131,   132,   132,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   137,   138,   139,   139,   140,   140,   141,   142,
     142,   143,   144,   145,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   146,   147,   148,   149,   149,   149,
     149,   150,   150,   150,   150,   151,   151,   151,   151,   151,
     152,   153,   154,   154,   155,   155,   156,   157,   157,   157,
     157,   157,   157,   157,   157,   158,   158,   159,   160,   160,
     161,   161,   161,   162,   162,   163,   164,   164,   164,   165,
     165,   165,   166,   166,   166,   166,   167,   167,   167,   168,
     168,   168,   168,   169,   170,   171,   172,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   174,
     174,   175,   175,   176,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   178,   178
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     3,     3,     1,     0,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     6,     0,     5,
       5,     0,     2,     1,     3,     1,     1,     1,     1,     1,
       1,    13,     0,     3,     3,     3,     2,     3,     3,     2,
       2,     2,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      10,    12,    10,     0,     4,     6,     8,    17,    15,     4,
       0,     2,     4,     3,     3,     1,     2,     1,     1,    14,
       0,     3,     3,     3,     2,     2,     3,     3,     2,     2,
       2,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,    10,
      19,    16,    14,    12,     0,     1,     0,     2,     9,     0,
       2,     4,     3,     0,     6,     3,     5,     0,     2,     2,
       2,     2,     2,     2,     2,     4,     3,     0,     4,     3,
       5,     0,     2,     5,     6,     0,     2,     4,     6,     8,
       4,     3,     0,     4,     0,     1,     6,     0,     9,     9,
       3,     3,     3,     3,     3,     0,     2,     5,     0,     2,
       1,     4,     4,     1,     3,     9,     0,     3,     2,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     2,     4,     2,     2,     4,     1,     1,     2,
       1,     2,     1,     3,     3,     4,     3,     4,     3,     1,
       1,     0,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     2,     1,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PARSER_error or PARSER_UNDEF. */
#define YYERRCODE PARSER_UNDEF


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

  yychar = PARSER_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* resource_file: resources  */
#line 324 "tools/wrc/parser.y"
                    {
		resource_t *rsc, *head;
		/* First add stringtables to the resource-list */
		rsc = build_stt_resources(sttres);
		/* 'build_stt_resources' returns a head and $1 is a tail */
		if((yyvsp[0].res))
		{
			(yyvsp[0].res)->next = rsc;
			if(rsc)
				rsc->prev = (yyvsp[0].res);
		}
		else
			(yyvsp[0].res) = rsc;
		/* Find the tail again */
		while((yyvsp[0].res) && (yyvsp[0].res)->next)
			(yyvsp[0].res) = (yyvsp[0].res)->next;
		/* Now add any fontdirectory */
		rsc = build_fontdirs((yyvsp[0].res));
		/* 'build_fontdir' returns a head and $1 is a tail */
		if((yyvsp[0].res))
		{
			(yyvsp[0].res)->next = rsc;
			if(rsc)
				rsc->prev = (yyvsp[0].res);
		}
		else
			(yyvsp[0].res) = rsc;

		/* Final statements before we're done */
                if ((head = get_resource_head((yyvsp[0].res))) != NULL)
                {
                    if (resource_top)  /* append to existing resources */
                    {
                        resource_t *tail = resource_top;
                        while (tail->next) tail = tail->next;
                        tail->next = head;
                        head->prev = tail;
                    }
                    else resource_top = head;
                }
                sttres = NULL;
		}
#line 2092 "tools/wrc/parser.tab.c"
    break;

  case 3: /* resources: %empty  */
#line 370 "tools/wrc/parser.y"
                                { (yyval.res) = NULL; want_id = 1; }
#line 2098 "tools/wrc/parser.tab.c"
    break;

  case 4: /* resources: resources resource  */
#line 371 "tools/wrc/parser.y"
                                {
		if((yyvsp[0].res))
		{
			resource_t *tail = (yyvsp[0].res);
			resource_t *head = (yyvsp[0].res);
			while(tail->next)
				tail = tail->next;
			while(head->prev)
				head = head->prev;
			head->prev = (yyvsp[-1].res);
			if((yyvsp[-1].res))
				(yyvsp[-1].res)->next = head;
			(yyval.res) = tail;
			/* Check for duplicate identifiers */
			while((yyvsp[-1].res) && head)
			{
				resource_t *rsc = (yyvsp[-1].res);
				while(rsc)
				{
					if(rsc->type == head->type
					&& rsc->lan == head->lan
					&& !compare_name_id(rsc->name, head->name)
					&& (rsc->type != res_usr || !compare_name_id(rsc->res.usr->type,head->res.usr->type)))
					{
						yyerror("Duplicate resource name '%s'", get_nameid_str(rsc->name));
					}
					rsc = rsc->prev;
				}
				head = head->next;
			}
		}
		else if((yyvsp[-1].res))
		{
			resource_t *tail = (yyvsp[-1].res);
			while(tail->next)
				tail = tail->next;
			(yyval.res) = tail;
		}
		else
			(yyval.res) = NULL;

		if(!dont_want_id)	/* See comments in language parsing below */
			want_id = 1;
		dont_want_id = 0;
		}
#line 2148 "tools/wrc/parser.tab.c"
    break;

  case 6: /* resource: expr usrcvt resource_definition  */
#line 447 "tools/wrc/parser.y"
                                          {
		(yyval.res) = (yyvsp[0].res);
		if((yyval.res))
		{
			if((yyvsp[-2].num) > 65535 || (yyvsp[-2].num) < -32768)
				yyerror("Resource's ID out of range (%d)", (yyvsp[-2].num));
			(yyval.res)->name = new_name_id();
			(yyval.res)->name->type = name_ord;
			(yyval.res)->name->name.i_name = (yyvsp[-2].num);
			}
			}
#line 2164 "tools/wrc/parser.tab.c"
    break;

  case 7: /* resource: tIDENT usrcvt resource_definition  */
#line 458 "tools/wrc/parser.y"
                                            {
		(yyval.res) = (yyvsp[0].res);
		if((yyval.res))
		{
			(yyval.res)->name = new_name_id();
			(yyval.res)->name->type = name_str;
			(yyval.res)->name->name.s_name = (yyvsp[-2].str);
		}
		}
#line 2178 "tools/wrc/parser.tab.c"
    break;

  case 8: /* resource: stringtable  */
#line 467 "tools/wrc/parser.y"
                      {
		/* Don't do anything, stringtables are converted to
		 * resource_t structures when we are finished parsing and
		 * the final rule of the parser is reduced (see above)
		 */
		(yyval.res) = NULL;
		chat("Got STRINGTABLE\n");
		}
#line 2191 "tools/wrc/parser.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 475 "tools/wrc/parser.y"
                    {want_nl = 1; }
#line 2197 "tools/wrc/parser.tab.c"
    break;

  case 10: /* resource: tLANGUAGE $@1 expr ',' expr  */
#line 475 "tools/wrc/parser.y"
                                                  {
		/* We *NEED* the newline to delimit the expression.
		 * Otherwise, we would not be able to set the next
		 * want_id anymore because of the token-lookahead.
		 *
		 * However, we can test the lookahead-token for
		 * being "non-expression" type, in which case we
		 * continue. Fortunately, tNL is the only token that
		 * will break expression parsing and is implicitly
		 * void, so we just remove it. This scheme makes it
		 * possible to do some (not all) fancy preprocessor
		 * stuff.
		 * BTW, we also need to make sure that the next
		 * reduction of 'resources' above will *not* set
		 * want_id because we already have a lookahead that
		 * cannot be undone.
		 */
		if(yychar != YYEMPTY && yychar != tNL)
			dont_want_id = 1;

		if(yychar == tNL)
			yychar = YYEMPTY;	/* Could use 'yyclearin', but we already need the*/
						/* direct access to yychar in rule 'usrcvt' below. */
		else if(yychar == tIDENT)
			parser_warning("LANGUAGE statement not delimited with newline; next identifier might be wrong\n");

		want_nl = 0;	/* We don't want it anymore if we didn't get it */

		if(!win32)
			parser_warning("LANGUAGE not supported in 16-bit mode\n");
		currentlanguage = MAKELANGID((yyvsp[-2].num), (yyvsp[0].num));
		if (get_language_codepage(currentlanguage) == -1)
			yyerror( "Language %04x is not supported", currentlanguage);
		(yyval.res) = NULL;
		chat("Got LANGUAGE %d,%d (0x%04x)\n", (yyvsp[-2].num), (yyvsp[0].num), currentlanguage);
		}
#line 2238 "tools/wrc/parser.tab.c"
    break;

  case 11: /* usrcvt: %empty  */
#line 517 "tools/wrc/parser.y"
                        { yychar = rsrcid_to_token(yychar); }
#line 2244 "tools/wrc/parser.tab.c"
    break;

  case 12: /* nameid: expr  */
#line 523 "tools/wrc/parser.y"
                {
		if((yyvsp[0].num) > 65535 || (yyvsp[0].num) < -32768)
			yyerror("Resource's ID out of range (%d)", (yyvsp[0].num));
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_ord;
		(yyval.nid)->name.i_name = (yyvsp[0].num);
		}
#line 2256 "tools/wrc/parser.tab.c"
    break;

  case 13: /* nameid: tIDENT  */
#line 530 "tools/wrc/parser.y"
                 {
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_str;
		(yyval.nid)->name.s_name = (yyvsp[0].str);
		}
#line 2266 "tools/wrc/parser.tab.c"
    break;

  case 14: /* nameid_s: nameid  */
#line 540 "tools/wrc/parser.y"
                        { (yyval.nid) = (yyvsp[0].nid); }
#line 2272 "tools/wrc/parser.tab.c"
    break;

  case 15: /* nameid_s: tSTRING  */
#line 541 "tools/wrc/parser.y"
                        {
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_str;
		(yyval.nid)->name.s_name = (yyvsp[0].str);
		}
#line 2282 "tools/wrc/parser.tab.c"
    break;

  case 16: /* resource_definition: accelerators  */
#line 550 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_acc, (yyvsp[0].acc), (yyvsp[0].acc)->memopt, (yyvsp[0].acc)->lvc.language); }
#line 2288 "tools/wrc/parser.tab.c"
    break;

  case 17: /* resource_definition: bitmap  */
#line 551 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_bmp, (yyvsp[0].bmp), (yyvsp[0].bmp)->memopt, (yyvsp[0].bmp)->data->lvc.language); }
#line 2294 "tools/wrc/parser.tab.c"
    break;

  case 18: /* resource_definition: cursor  */
#line 552 "tools/wrc/parser.y"
                 {
		resource_t *rsc;
		if((yyvsp[0].ani)->type == res_anicur)
		{
			(yyval.res) = rsc = new_resource(res_anicur, (yyvsp[0].ani)->u.ani, (yyvsp[0].ani)->u.ani->memopt, (yyvsp[0].ani)->u.ani->data->lvc.language);
		}
		else /* res_curg */
		{
			cursor_t *cur;
			(yyval.res) = rsc = new_resource(res_curg, (yyvsp[0].ani)->u.curg, (yyvsp[0].ani)->u.curg->memopt, (yyvsp[0].ani)->u.curg->lvc.language);
			for(cur = (yyvsp[0].ani)->u.curg->cursorlist; cur; cur = cur->next)
			{
				rsc->prev = new_resource(res_cur, cur, (yyvsp[0].ani)->u.curg->memopt, (yyvsp[0].ani)->u.curg->lvc.language);
				rsc->prev->next = rsc;
				rsc = rsc->prev;
				rsc->name = new_name_id();
				rsc->name->type = name_ord;
				rsc->name->name.i_name = cur->id;
			}
		}
		free((yyvsp[0].ani));
		}
#line 2321 "tools/wrc/parser.tab.c"
    break;

  case 19: /* resource_definition: dialog  */
#line 574 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_dlg, (yyvsp[0].dlg), (yyvsp[0].dlg)->memopt, (yyvsp[0].dlg)->lvc.language); }
#line 2327 "tools/wrc/parser.tab.c"
    break;

  case 20: /* resource_definition: dialogex  */
#line 575 "tools/wrc/parser.y"
                   {
		if(win32)
			(yyval.res) = new_resource(res_dlg, (yyvsp[0].dlg), (yyvsp[0].dlg)->memopt, (yyvsp[0].dlg)->lvc.language);
		else
			(yyval.res) = NULL;
		}
#line 2338 "tools/wrc/parser.tab.c"
    break;

  case 21: /* resource_definition: dlginit  */
#line 581 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_dlginit, (yyvsp[0].dginit), (yyvsp[0].dginit)->memopt, (yyvsp[0].dginit)->data->lvc.language); }
#line 2344 "tools/wrc/parser.tab.c"
    break;

  case 22: /* resource_definition: font  */
#line 582 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_fnt, (yyvsp[0].fnt), (yyvsp[0].fnt)->memopt, (yyvsp[0].fnt)->data->lvc.language); }
#line 2350 "tools/wrc/parser.tab.c"
    break;

  case 23: /* resource_definition: fontdir  */
#line 583 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_fntdir, (yyvsp[0].fnd), (yyvsp[0].fnd)->memopt, (yyvsp[0].fnd)->data->lvc.language); }
#line 2356 "tools/wrc/parser.tab.c"
    break;

  case 24: /* resource_definition: icon  */
#line 584 "tools/wrc/parser.y"
               {
		resource_t *rsc;
		if((yyvsp[0].ani)->type == res_aniico)
		{
			(yyval.res) = rsc = new_resource(res_aniico, (yyvsp[0].ani)->u.ani, (yyvsp[0].ani)->u.ani->memopt, (yyvsp[0].ani)->u.ani->data->lvc.language);
		}
		else /* res_icog */
		{
			icon_t *ico;
			(yyval.res) = rsc = new_resource(res_icog, (yyvsp[0].ani)->u.icog, (yyvsp[0].ani)->u.icog->memopt, (yyvsp[0].ani)->u.icog->lvc.language);
			for(ico = (yyvsp[0].ani)->u.icog->iconlist; ico; ico = ico->next)
			{
				rsc->prev = new_resource(res_ico, ico, (yyvsp[0].ani)->u.icog->memopt, (yyvsp[0].ani)->u.icog->lvc.language);
				rsc->prev->next = rsc;
				rsc = rsc->prev;
				rsc->name = new_name_id();
				rsc->name->type = name_ord;
				rsc->name->name.i_name = ico->id;
			}
		}
		free((yyvsp[0].ani));
		}
#line 2383 "tools/wrc/parser.tab.c"
    break;

  case 25: /* resource_definition: menu  */
#line 606 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_men, (yyvsp[0].men), (yyvsp[0].men)->memopt, (yyvsp[0].men)->lvc.language); }
#line 2389 "tools/wrc/parser.tab.c"
    break;

  case 26: /* resource_definition: menuex  */
#line 607 "tools/wrc/parser.y"
                 {
		if(win32)
			(yyval.res) = new_resource(res_men, (yyvsp[0].men), (yyvsp[0].men)->memopt, (yyvsp[0].men)->lvc.language);
		else
			(yyval.res) = NULL;
		}
#line 2400 "tools/wrc/parser.tab.c"
    break;

  case 27: /* resource_definition: messagetable  */
#line 613 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_msg, (yyvsp[0].msg), WRC_MO_MOVEABLE | WRC_MO_DISCARDABLE, (yyvsp[0].msg)->data->lvc.language); }
#line 2406 "tools/wrc/parser.tab.c"
    break;

  case 28: /* resource_definition: html  */
#line 614 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_html, (yyvsp[0].html), (yyvsp[0].html)->memopt, (yyvsp[0].html)->data->lvc.language); }
#line 2412 "tools/wrc/parser.tab.c"
    break;

  case 29: /* resource_definition: rcdata  */
#line 615 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_rdt, (yyvsp[0].rdt), (yyvsp[0].rdt)->memopt, (yyvsp[0].rdt)->data->lvc.language); }
#line 2418 "tools/wrc/parser.tab.c"
    break;

  case 30: /* resource_definition: toolbar  */
#line 616 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_toolbar, (yyvsp[0].tlbar), (yyvsp[0].tlbar)->memopt, (yyvsp[0].tlbar)->lvc.language); }
#line 2424 "tools/wrc/parser.tab.c"
    break;

  case 31: /* resource_definition: userres  */
#line 617 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_usr, (yyvsp[0].usr), (yyvsp[0].usr)->memopt, (yyvsp[0].usr)->data->lvc.language); }
#line 2430 "tools/wrc/parser.tab.c"
    break;

  case 32: /* resource_definition: versioninfo  */
#line 618 "tools/wrc/parser.y"
                        { (yyval.res) = new_resource(res_ver, (yyvsp[0].veri), WRC_MO_MOVEABLE | WRC_MO_DISCARDABLE, (yyvsp[0].veri)->lvc.language); }
#line 2436 "tools/wrc/parser.tab.c"
    break;

  case 33: /* filename: tIDENT  */
#line 622 "tools/wrc/parser.y"
                        { (yyval.str) = make_filename((yyvsp[0].str)); }
#line 2442 "tools/wrc/parser.tab.c"
    break;

  case 34: /* filename: tSTRING  */
#line 623 "tools/wrc/parser.y"
                        { (yyval.str) = make_filename((yyvsp[0].str)); }
#line 2448 "tools/wrc/parser.tab.c"
    break;

  case 35: /* bitmap: tBITMAP loadmemopts file_raw  */
#line 627 "tools/wrc/parser.y"
                                        { (yyval.bmp) = new_bitmap((yyvsp[0].raw), (yyvsp[-1].iptr)); }
#line 2454 "tools/wrc/parser.tab.c"
    break;

  case 36: /* cursor: tCURSOR loadmemopts file_raw  */
#line 631 "tools/wrc/parser.y"
                                        {
		(yyval.ani) = new_ani_any();
		if((yyvsp[0].raw)->size > 4 && !memcmp((yyvsp[0].raw)->data, riff, sizeof(riff)))
		{
			(yyval.ani)->type = res_anicur;
			(yyval.ani)->u.ani = new_ani_curico(res_anicur, (yyvsp[0].raw), (yyvsp[-1].iptr));
		}
		else
		{
			(yyval.ani)->type = res_curg;
			(yyval.ani)->u.curg = new_cursor_group((yyvsp[0].raw), (yyvsp[-1].iptr));
		}
	}
#line 2472 "tools/wrc/parser.tab.c"
    break;

  case 37: /* icon: tICON loadmemopts file_raw  */
#line 647 "tools/wrc/parser.y"
                                        {
		(yyval.ani) = new_ani_any();
		if((yyvsp[0].raw)->size > 4 && !memcmp((yyvsp[0].raw)->data, riff, sizeof(riff)))
		{
			(yyval.ani)->type = res_aniico;
			(yyval.ani)->u.ani = new_ani_curico(res_aniico, (yyvsp[0].raw), (yyvsp[-1].iptr));
		}
		else
		{
			(yyval.ani)->type = res_icog;
			(yyval.ani)->u.icog = new_icon_group((yyvsp[0].raw), (yyvsp[-1].iptr));
		}
	}
#line 2490 "tools/wrc/parser.tab.c"
    break;

  case 38: /* font: tFONT loadmemopts file_raw  */
#line 669 "tools/wrc/parser.y"
                                        { (yyval.fnt) = new_font((yyvsp[0].raw), (yyvsp[-1].iptr)); }
#line 2496 "tools/wrc/parser.tab.c"
    break;

  case 39: /* fontdir: tFONTDIR loadmemopts file_raw  */
#line 679 "tools/wrc/parser.y"
                                        { (yyval.fnd) = new_fontdir((yyvsp[0].raw), (yyvsp[-1].iptr)); }
#line 2502 "tools/wrc/parser.tab.c"
    break;

  case 40: /* messagetable: tMESSAGETABLE loadmemopts file_raw  */
#line 687 "tools/wrc/parser.y"
                                                {
		if(!win32)
			parser_warning("MESSAGETABLE not supported in 16-bit mode\n");
		(yyval.msg) = new_messagetable((yyvsp[0].raw), (yyvsp[-1].iptr));
		}
#line 2512 "tools/wrc/parser.tab.c"
    break;

  case 41: /* html: tHTML loadmemopts file_raw  */
#line 695 "tools/wrc/parser.y"
                                        { (yyval.html) = new_html((yyvsp[0].raw), (yyvsp[-1].iptr)); }
#line 2518 "tools/wrc/parser.tab.c"
    break;

  case 42: /* rcdata: tRCDATA loadmemopts file_raw  */
#line 699 "tools/wrc/parser.y"
                                        { (yyval.rdt) = new_rcdata((yyvsp[0].raw), (yyvsp[-1].iptr)); }
#line 2524 "tools/wrc/parser.tab.c"
    break;

  case 43: /* dlginit: tDLGINIT loadmemopts file_raw  */
#line 703 "tools/wrc/parser.y"
                                        { (yyval.dginit) = new_dlginit((yyvsp[0].raw), (yyvsp[-1].iptr)); }
#line 2530 "tools/wrc/parser.tab.c"
    break;

  case 44: /* userres: usertype loadmemopts file_raw  */
#line 707 "tools/wrc/parser.y"
                                                {
			(yyval.usr) = new_user((yyvsp[-2].nid), (yyvsp[0].raw), (yyvsp[-1].iptr));
		}
#line 2538 "tools/wrc/parser.tab.c"
    break;

  case 45: /* usertype: tNUMBER  */
#line 712 "tools/wrc/parser.y"
                  {
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_ord;
		(yyval.nid)->name.i_name = (yyvsp[0].num);
		}
#line 2548 "tools/wrc/parser.tab.c"
    break;

  case 46: /* usertype: tIDENT  */
#line 717 "tools/wrc/parser.y"
                 {
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_str;
		(yyval.nid)->name.s_name = (yyvsp[0].str);
		}
#line 2558 "tools/wrc/parser.tab.c"
    break;

  case 47: /* accelerators: tACCELERATORS loadmemopts opt_lvc tBEGIN events tEND  */
#line 726 "tools/wrc/parser.y"
                                                               {
		(yyval.acc) = new_accelerator();
		if((yyvsp[-4].iptr))
		{
			(yyval.acc)->memopt = *((yyvsp[-4].iptr));
			free((yyvsp[-4].iptr));
		}
		else
		{
			(yyval.acc)->memopt = WRC_MO_MOVEABLE | WRC_MO_PURE;
		}
		if(!(yyvsp[-1].event))
			yyerror("Accelerator table must have at least one entry");
		(yyval.acc)->events = get_event_head((yyvsp[-1].event));
		if((yyvsp[-3].lvc))
		{
			(yyval.acc)->lvc = *((yyvsp[-3].lvc));
			free((yyvsp[-3].lvc));
		}
		if(!(yyval.acc)->lvc.language) (yyval.acc)->lvc.language = currentlanguage;
		}
#line 2584 "tools/wrc/parser.tab.c"
    break;

  case 48: /* events: %empty  */
#line 749 "tools/wrc/parser.y"
                                                { (yyval.event)=NULL; }
#line 2590 "tools/wrc/parser.tab.c"
    break;

  case 49: /* events: events tSTRING ',' expr acc_opt  */
#line 750 "tools/wrc/parser.y"
                                                { (yyval.event)=add_string_event((yyvsp[-3].str), (yyvsp[-1].num), (yyvsp[0].num), (yyvsp[-4].event)); }
#line 2596 "tools/wrc/parser.tab.c"
    break;

  case 50: /* events: events expr ',' expr acc_opt  */
#line 751 "tools/wrc/parser.y"
                                                { (yyval.event)=add_event((yyvsp[-3].num), (yyvsp[-1].num), (yyvsp[0].num), (yyvsp[-4].event)); }
#line 2602 "tools/wrc/parser.tab.c"
    break;

  case 51: /* acc_opt: %empty  */
#line 760 "tools/wrc/parser.y"
                        { (yyval.num) = 0; }
#line 2608 "tools/wrc/parser.tab.c"
    break;

  case 52: /* acc_opt: ',' accs  */
#line 761 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 2614 "tools/wrc/parser.tab.c"
    break;

  case 53: /* accs: acc  */
#line 764 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 2620 "tools/wrc/parser.tab.c"
    break;

  case 54: /* accs: accs ',' acc  */
#line 765 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 2626 "tools/wrc/parser.tab.c"
    break;

  case 55: /* acc: tNOINVERT  */
#line 768 "tools/wrc/parser.y"
                        { (yyval.num) = WRC_AF_NOINVERT; }
#line 2632 "tools/wrc/parser.tab.c"
    break;

  case 56: /* acc: tSHIFT  */
#line 769 "tools/wrc/parser.y"
                        { (yyval.num) = WRC_AF_SHIFT; }
#line 2638 "tools/wrc/parser.tab.c"
    break;

  case 57: /* acc: tCONTROL  */
#line 770 "tools/wrc/parser.y"
                        { (yyval.num) = WRC_AF_CONTROL; }
#line 2644 "tools/wrc/parser.tab.c"
    break;

  case 58: /* acc: tALT  */
#line 771 "tools/wrc/parser.y"
                        { (yyval.num) = WRC_AF_ALT; }
#line 2650 "tools/wrc/parser.tab.c"
    break;

  case 59: /* acc: tASCII  */
#line 772 "tools/wrc/parser.y"
                        { (yyval.num) = WRC_AF_ASCII; }
#line 2656 "tools/wrc/parser.tab.c"
    break;

  case 60: /* acc: tVIRTKEY  */
#line 773 "tools/wrc/parser.y"
                        { (yyval.num) = WRC_AF_VIRTKEY; }
#line 2662 "tools/wrc/parser.tab.c"
    break;

  case 61: /* dialog: tDIALOG loadmemopts expr ',' expr ',' expr ',' expr dlg_attributes tBEGIN ctrls tEND  */
#line 779 "tools/wrc/parser.y"
                             {
		if((yyvsp[-11].iptr))
		{
			(yyvsp[-3].dlg)->memopt = *((yyvsp[-11].iptr));
			free((yyvsp[-11].iptr));
		}
		else
			(yyvsp[-3].dlg)->memopt = WRC_MO_MOVEABLE | WRC_MO_PURE | WRC_MO_DISCARDABLE;
		(yyvsp[-3].dlg)->x = (yyvsp[-10].num);
		(yyvsp[-3].dlg)->y = (yyvsp[-8].num);
		(yyvsp[-3].dlg)->width = (yyvsp[-6].num);
		(yyvsp[-3].dlg)->height = (yyvsp[-4].num);
		(yyvsp[-3].dlg)->controls = get_control_head((yyvsp[-1].ctl));
		(yyval.dlg) = (yyvsp[-3].dlg);
		if(!(yyval.dlg)->gotstyle)
		{
			(yyval.dlg)->style = new_style(0,0);
			(yyval.dlg)->style->or_mask = WS_POPUP;
			(yyval.dlg)->gotstyle = TRUE;
		}
		if((yyval.dlg)->title)
			(yyval.dlg)->style->or_mask |= WS_CAPTION;
		if((yyval.dlg)->font)
			(yyval.dlg)->style->or_mask |= DS_SETFONT;

		(yyval.dlg)->style->or_mask &= ~((yyval.dlg)->style->and_mask);
		(yyval.dlg)->style->and_mask = 0;

		if(!(yyval.dlg)->lvc.language) (yyval.dlg)->lvc.language = currentlanguage;
		}
#line 2697 "tools/wrc/parser.tab.c"
    break;

  case 62: /* dlg_attributes: %empty  */
#line 812 "tools/wrc/parser.y"
                                                { (yyval.dlg)=new_dialog(); }
#line 2703 "tools/wrc/parser.tab.c"
    break;

  case 63: /* dlg_attributes: dlg_attributes tSTYLE style  */
#line 813 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_style((yyvsp[0].style),(yyvsp[-2].dlg)); }
#line 2709 "tools/wrc/parser.tab.c"
    break;

  case 64: /* dlg_attributes: dlg_attributes tEXSTYLE style  */
#line 814 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_exstyle((yyvsp[0].style),(yyvsp[-2].dlg)); }
#line 2715 "tools/wrc/parser.tab.c"
    break;

  case 65: /* dlg_attributes: dlg_attributes tCAPTION tSTRING  */
#line 815 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_caption((yyvsp[0].str),(yyvsp[-2].dlg)); }
#line 2721 "tools/wrc/parser.tab.c"
    break;

  case 66: /* dlg_attributes: dlg_attributes opt_font  */
#line 816 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_font((yyvsp[0].fntid),(yyvsp[-1].dlg)); }
#line 2727 "tools/wrc/parser.tab.c"
    break;

  case 67: /* dlg_attributes: dlg_attributes tCLASS nameid_s  */
#line 817 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_class((yyvsp[0].nid),(yyvsp[-2].dlg)); }
#line 2733 "tools/wrc/parser.tab.c"
    break;

  case 68: /* dlg_attributes: dlg_attributes tMENU nameid  */
#line 818 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_menu((yyvsp[0].nid),(yyvsp[-2].dlg)); }
#line 2739 "tools/wrc/parser.tab.c"
    break;

  case 69: /* dlg_attributes: dlg_attributes opt_language  */
#line 819 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_language((yyvsp[0].lan),(yyvsp[-1].dlg)); }
#line 2745 "tools/wrc/parser.tab.c"
    break;

  case 70: /* dlg_attributes: dlg_attributes opt_characts  */
#line 820 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_characteristics((yyvsp[0].chars),(yyvsp[-1].dlg)); }
#line 2751 "tools/wrc/parser.tab.c"
    break;

  case 71: /* dlg_attributes: dlg_attributes opt_version  */
#line 821 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_version((yyvsp[0].ver),(yyvsp[-1].dlg)); }
#line 2757 "tools/wrc/parser.tab.c"
    break;

  case 72: /* ctrls: %empty  */
#line 824 "tools/wrc/parser.y"
                                                { (yyval.ctl) = NULL; }
#line 2763 "tools/wrc/parser.tab.c"
    break;

  case 73: /* ctrls: ctrls tCONTROL gen_ctrl  */
#line 825 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(-1, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2769 "tools/wrc/parser.tab.c"
    break;

  case 74: /* ctrls: ctrls tEDITTEXT ctrl_desc  */
#line 826 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_EDIT, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2775 "tools/wrc/parser.tab.c"
    break;

  case 75: /* ctrls: ctrls tLISTBOX ctrl_desc  */
#line 827 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_LISTBOX, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2781 "tools/wrc/parser.tab.c"
    break;

  case 76: /* ctrls: ctrls tCOMBOBOX ctrl_desc  */
#line 828 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_COMBOBOX, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2787 "tools/wrc/parser.tab.c"
    break;

  case 77: /* ctrls: ctrls tSCROLLBAR ctrl_desc  */
#line 829 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_SCROLLBAR, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2793 "tools/wrc/parser.tab.c"
    break;

  case 78: /* ctrls: ctrls tCHECKBOX lab_ctrl  */
#line 830 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_CHECKBOX, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2799 "tools/wrc/parser.tab.c"
    break;

  case 79: /* ctrls: ctrls tDEFPUSHBUTTON lab_ctrl  */
#line 831 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_DEFPUSHBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2805 "tools/wrc/parser.tab.c"
    break;

  case 80: /* ctrls: ctrls tGROUPBOX lab_ctrl  */
#line 832 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_GROUPBOX, (yyvsp[0].ctl), (yyvsp[-2].ctl));}
#line 2811 "tools/wrc/parser.tab.c"
    break;

  case 81: /* ctrls: ctrls tPUSHBUTTON lab_ctrl  */
#line 833 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_PUSHBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2817 "tools/wrc/parser.tab.c"
    break;

  case 82: /* ctrls: ctrls tRADIOBUTTON lab_ctrl  */
#line 835 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_RADIOBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2823 "tools/wrc/parser.tab.c"
    break;

  case 83: /* ctrls: ctrls tAUTO3STATE lab_ctrl  */
#line 836 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_AUTO3STATE, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2829 "tools/wrc/parser.tab.c"
    break;

  case 84: /* ctrls: ctrls tSTATE3 lab_ctrl  */
#line 837 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_3STATE, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2835 "tools/wrc/parser.tab.c"
    break;

  case 85: /* ctrls: ctrls tAUTOCHECKBOX lab_ctrl  */
#line 838 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_AUTOCHECKBOX, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2841 "tools/wrc/parser.tab.c"
    break;

  case 86: /* ctrls: ctrls tAUTORADIOBUTTON lab_ctrl  */
#line 839 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_AUTORADIOBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2847 "tools/wrc/parser.tab.c"
    break;

  case 87: /* ctrls: ctrls tLTEXT lab_ctrl  */
#line 840 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_STATIC, SS_LEFT, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2853 "tools/wrc/parser.tab.c"
    break;

  case 88: /* ctrls: ctrls tCTEXT lab_ctrl  */
#line 841 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_STATIC, SS_CENTER, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2859 "tools/wrc/parser.tab.c"
    break;

  case 89: /* ctrls: ctrls tRTEXT lab_ctrl  */
#line 842 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_STATIC, SS_RIGHT, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 2865 "tools/wrc/parser.tab.c"
    break;

  case 90: /* ctrls: ctrls tICON nameid_s opt_comma expr ',' expr ',' expr iconinfo  */
#line 844 "tools/wrc/parser.y"
                                                                         {
		(yyvsp[0].ctl)->title = (yyvsp[-7].nid);
		(yyvsp[0].ctl)->id = (yyvsp[-5].num);
		(yyvsp[0].ctl)->x = (yyvsp[-3].num);
		(yyvsp[0].ctl)->y = (yyvsp[-1].num);
		(yyval.ctl) = ins_ctrl(CT_STATIC, SS_ICON, (yyvsp[0].ctl), (yyvsp[-9].ctl));
		}
#line 2877 "tools/wrc/parser.tab.c"
    break;

  case 91: /* lab_ctrl: nameid_s opt_comma expr ',' expr ',' expr ',' expr ',' expr optional_style_pair  */
#line 854 "tools/wrc/parser.y"
                                                                                          {
		(yyval.ctl)=new_control();
		(yyval.ctl)->title = (yyvsp[-11].nid);
		(yyval.ctl)->id = (yyvsp[-9].num);
		(yyval.ctl)->x = (yyvsp[-7].num);
		(yyval.ctl)->y = (yyvsp[-5].num);
		(yyval.ctl)->width = (yyvsp[-3].num);
		(yyval.ctl)->height = (yyvsp[-1].num);
		if((yyvsp[0].styles))
		{
			(yyval.ctl)->style = (yyvsp[0].styles)->style;
			(yyval.ctl)->gotstyle = TRUE;
			if ((yyvsp[0].styles)->exstyle)
			{
			    (yyval.ctl)->exstyle = (yyvsp[0].styles)->exstyle;
			    (yyval.ctl)->gotexstyle = TRUE;
			}
			free((yyvsp[0].styles));
		}
		}
#line 2902 "tools/wrc/parser.tab.c"
    break;

  case 92: /* ctrl_desc: expr ',' expr ',' expr ',' expr ',' expr optional_style_pair  */
#line 877 "tools/wrc/parser.y"
                                                                       {
		(yyval.ctl) = new_control();
		(yyval.ctl)->id = (yyvsp[-9].num);
		(yyval.ctl)->x = (yyvsp[-7].num);
		(yyval.ctl)->y = (yyvsp[-5].num);
		(yyval.ctl)->width = (yyvsp[-3].num);
		(yyval.ctl)->height = (yyvsp[-1].num);
		if((yyvsp[0].styles))
		{
			(yyval.ctl)->style = (yyvsp[0].styles)->style;
			(yyval.ctl)->gotstyle = TRUE;
			if ((yyvsp[0].styles)->exstyle)
			{
			    (yyval.ctl)->exstyle = (yyvsp[0].styles)->exstyle;
			    (yyval.ctl)->gotexstyle = TRUE;
			}
			free((yyvsp[0].styles));
		}
		}
#line 2926 "tools/wrc/parser.tab.c"
    break;

  case 93: /* iconinfo: %empty  */
#line 899 "tools/wrc/parser.y"
                { (yyval.ctl) = new_control(); }
#line 2932 "tools/wrc/parser.tab.c"
    break;

  case 94: /* iconinfo: ',' expr ',' expr  */
#line 901 "tools/wrc/parser.y"
                            {
		(yyval.ctl) = new_control();
		(yyval.ctl)->width = (yyvsp[-2].num);
		(yyval.ctl)->height = (yyvsp[0].num);
		}
#line 2942 "tools/wrc/parser.tab.c"
    break;

  case 95: /* iconinfo: ',' expr ',' expr ',' style  */
#line 906 "tools/wrc/parser.y"
                                      {
		(yyval.ctl) = new_control();
		(yyval.ctl)->width = (yyvsp[-4].num);
		(yyval.ctl)->height = (yyvsp[-2].num);
		(yyval.ctl)->style = (yyvsp[0].style);
		(yyval.ctl)->gotstyle = TRUE;
		}
#line 2954 "tools/wrc/parser.tab.c"
    break;

  case 96: /* iconinfo: ',' expr ',' expr ',' style ',' style  */
#line 913 "tools/wrc/parser.y"
                                                {
		(yyval.ctl) = new_control();
		(yyval.ctl)->width = (yyvsp[-6].num);
		(yyval.ctl)->height = (yyvsp[-4].num);
		(yyval.ctl)->style = (yyvsp[-2].style);
		(yyval.ctl)->gotstyle = TRUE;
		(yyval.ctl)->exstyle = (yyvsp[0].style);
		(yyval.ctl)->gotexstyle = TRUE;
		}
#line 2968 "tools/wrc/parser.tab.c"
    break;

  case 97: /* gen_ctrl: nameid_s opt_comma expr ',' ctlclass ',' style ',' expr ',' expr ',' expr ',' expr ',' style  */
#line 924 "tools/wrc/parser.y"
                                                                                                       {
		(yyval.ctl)=new_control();
		(yyval.ctl)->title = (yyvsp[-16].nid);
		(yyval.ctl)->id = (yyvsp[-14].num);
		(yyval.ctl)->ctlclass = convert_ctlclass((yyvsp[-12].nid));
		(yyval.ctl)->style = (yyvsp[-10].style);
		(yyval.ctl)->gotstyle = TRUE;
		(yyval.ctl)->x = (yyvsp[-8].num);
		(yyval.ctl)->y = (yyvsp[-6].num);
		(yyval.ctl)->width = (yyvsp[-4].num);
		(yyval.ctl)->height = (yyvsp[-2].num);
		(yyval.ctl)->exstyle = (yyvsp[0].style);
		(yyval.ctl)->gotexstyle = TRUE;
		}
#line 2987 "tools/wrc/parser.tab.c"
    break;

  case 98: /* gen_ctrl: nameid_s opt_comma expr ',' ctlclass ',' style ',' expr ',' expr ',' expr ',' expr  */
#line 938 "tools/wrc/parser.y"
                                                                                             {
		(yyval.ctl)=new_control();
		(yyval.ctl)->title = (yyvsp[-14].nid);
		(yyval.ctl)->id = (yyvsp[-12].num);
		(yyval.ctl)->ctlclass = convert_ctlclass((yyvsp[-10].nid));
		(yyval.ctl)->style = (yyvsp[-8].style);
		(yyval.ctl)->gotstyle = TRUE;
		(yyval.ctl)->x = (yyvsp[-6].num);
		(yyval.ctl)->y = (yyvsp[-4].num);
		(yyval.ctl)->width = (yyvsp[-2].num);
		(yyval.ctl)->height = (yyvsp[0].num);
		}
#line 3004 "tools/wrc/parser.tab.c"
    break;

  case 99: /* opt_font: tFONT expr ',' tSTRING  */
#line 953 "tools/wrc/parser.y"
                                        { (yyval.fntid) = new_font_id((yyvsp[-2].num), (yyvsp[0].str), 0, 0); }
#line 3010 "tools/wrc/parser.tab.c"
    break;

  case 100: /* optional_style_pair: %empty  */
#line 958 "tools/wrc/parser.y"
                                { (yyval.styles) = NULL; }
#line 3016 "tools/wrc/parser.tab.c"
    break;

  case 101: /* optional_style_pair: ',' style  */
#line 959 "tools/wrc/parser.y"
                                { (yyval.styles) = new_style_pair((yyvsp[0].style), 0); }
#line 3022 "tools/wrc/parser.tab.c"
    break;

  case 102: /* optional_style_pair: ',' style ',' style  */
#line 960 "tools/wrc/parser.y"
                                { (yyval.styles) = new_style_pair((yyvsp[-2].style), (yyvsp[0].style)); }
#line 3028 "tools/wrc/parser.tab.c"
    break;

  case 103: /* style: style '|' style  */
#line 964 "tools/wrc/parser.y"
                                { (yyval.style) = new_style((yyvsp[-2].style)->or_mask | (yyvsp[0].style)->or_mask, (yyvsp[-2].style)->and_mask | (yyvsp[0].style)->and_mask); free((yyvsp[-2].style)); free((yyvsp[0].style));}
#line 3034 "tools/wrc/parser.tab.c"
    break;

  case 104: /* style: '(' style ')'  */
#line 965 "tools/wrc/parser.y"
                                { (yyval.style) = (yyvsp[-1].style); }
#line 3040 "tools/wrc/parser.tab.c"
    break;

  case 105: /* style: any_num  */
#line 966 "tools/wrc/parser.y"
                                { (yyval.style) = new_style((yyvsp[0].num), 0); }
#line 3046 "tools/wrc/parser.tab.c"
    break;

  case 106: /* style: tNOT any_num  */
#line 967 "tools/wrc/parser.y"
                                { (yyval.style) = new_style(0, (yyvsp[0].num)); }
#line 3052 "tools/wrc/parser.tab.c"
    break;

  case 107: /* ctlclass: expr  */
#line 971 "tools/wrc/parser.y"
                {
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_ord;
		(yyval.nid)->name.i_name = (yyvsp[0].num);
		}
#line 3062 "tools/wrc/parser.tab.c"
    break;

  case 108: /* ctlclass: tSTRING  */
#line 976 "tools/wrc/parser.y"
                  {
		(yyval.nid) = new_name_id();
		(yyval.nid)->type = name_str;
		(yyval.nid)->name.s_name = (yyvsp[0].str);
		}
#line 3072 "tools/wrc/parser.tab.c"
    break;

  case 109: /* dialogex: tDIALOGEX loadmemopts expr ',' expr ',' expr ',' expr helpid dlgex_attribs tBEGIN exctrls tEND  */
#line 985 "tools/wrc/parser.y"
                               {
		if(!win32)
			parser_warning("DIALOGEX not supported in 16-bit mode\n");
		if((yyvsp[-12].iptr))
		{
			(yyvsp[-3].dlg)->memopt = *((yyvsp[-12].iptr));
			free((yyvsp[-12].iptr));
		}
		else
			(yyvsp[-3].dlg)->memopt = WRC_MO_MOVEABLE | WRC_MO_PURE | WRC_MO_DISCARDABLE;
		(yyvsp[-3].dlg)->x = (yyvsp[-11].num);
		(yyvsp[-3].dlg)->y = (yyvsp[-9].num);
		(yyvsp[-3].dlg)->width = (yyvsp[-7].num);
		(yyvsp[-3].dlg)->height = (yyvsp[-5].num);
		if((yyvsp[-4].iptr))
		{
			(yyvsp[-3].dlg)->helpid = *((yyvsp[-4].iptr));
			(yyvsp[-3].dlg)->gothelpid = TRUE;
			free((yyvsp[-4].iptr));
		}
		(yyvsp[-3].dlg)->controls = get_control_head((yyvsp[-1].ctl));
		(yyval.dlg) = (yyvsp[-3].dlg);

		assert((yyval.dlg)->style != NULL);
		if(!(yyval.dlg)->gotstyle)
		{
			(yyval.dlg)->style->or_mask = WS_POPUP;
			(yyval.dlg)->gotstyle = TRUE;
		}
		if((yyval.dlg)->title)
			(yyval.dlg)->style->or_mask |= WS_CAPTION;
		if((yyval.dlg)->font)
			(yyval.dlg)->style->or_mask |= DS_SETFONT;

		(yyval.dlg)->style->or_mask &= ~((yyval.dlg)->style->and_mask);
		(yyval.dlg)->style->and_mask = 0;

		if(!(yyval.dlg)->lvc.language) (yyval.dlg)->lvc.language = currentlanguage;
		}
#line 3116 "tools/wrc/parser.tab.c"
    break;

  case 110: /* dlgex_attribs: %empty  */
#line 1027 "tools/wrc/parser.y"
                                                { (yyval.dlg)=new_dialog(); (yyval.dlg)->is_ex = TRUE; }
#line 3122 "tools/wrc/parser.tab.c"
    break;

  case 111: /* dlgex_attribs: dlgex_attribs tSTYLE style  */
#line 1028 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_style((yyvsp[0].style),(yyvsp[-2].dlg)); }
#line 3128 "tools/wrc/parser.tab.c"
    break;

  case 112: /* dlgex_attribs: dlgex_attribs tEXSTYLE style  */
#line 1029 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_exstyle((yyvsp[0].style),(yyvsp[-2].dlg)); }
#line 3134 "tools/wrc/parser.tab.c"
    break;

  case 113: /* dlgex_attribs: dlgex_attribs tCAPTION tSTRING  */
#line 1030 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_caption((yyvsp[0].str),(yyvsp[-2].dlg)); }
#line 3140 "tools/wrc/parser.tab.c"
    break;

  case 114: /* dlgex_attribs: dlgex_attribs opt_font  */
#line 1031 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_font((yyvsp[0].fntid),(yyvsp[-1].dlg)); }
#line 3146 "tools/wrc/parser.tab.c"
    break;

  case 115: /* dlgex_attribs: dlgex_attribs opt_exfont  */
#line 1032 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_font((yyvsp[0].fntid),(yyvsp[-1].dlg)); }
#line 3152 "tools/wrc/parser.tab.c"
    break;

  case 116: /* dlgex_attribs: dlgex_attribs tCLASS nameid_s  */
#line 1033 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_class((yyvsp[0].nid),(yyvsp[-2].dlg)); }
#line 3158 "tools/wrc/parser.tab.c"
    break;

  case 117: /* dlgex_attribs: dlgex_attribs tMENU nameid  */
#line 1034 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_menu((yyvsp[0].nid),(yyvsp[-2].dlg)); }
#line 3164 "tools/wrc/parser.tab.c"
    break;

  case 118: /* dlgex_attribs: dlgex_attribs opt_language  */
#line 1035 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_language((yyvsp[0].lan),(yyvsp[-1].dlg)); }
#line 3170 "tools/wrc/parser.tab.c"
    break;

  case 119: /* dlgex_attribs: dlgex_attribs opt_characts  */
#line 1036 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_characteristics((yyvsp[0].chars),(yyvsp[-1].dlg)); }
#line 3176 "tools/wrc/parser.tab.c"
    break;

  case 120: /* dlgex_attribs: dlgex_attribs opt_version  */
#line 1037 "tools/wrc/parser.y"
                                                { (yyval.dlg)=dialog_version((yyvsp[0].ver),(yyvsp[-1].dlg)); }
#line 3182 "tools/wrc/parser.tab.c"
    break;

  case 121: /* exctrls: %empty  */
#line 1040 "tools/wrc/parser.y"
                                                { (yyval.ctl) = NULL; }
#line 3188 "tools/wrc/parser.tab.c"
    break;

  case 122: /* exctrls: exctrls tCONTROL gen_exctrl  */
#line 1041 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(-1, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3194 "tools/wrc/parser.tab.c"
    break;

  case 123: /* exctrls: exctrls tEDITTEXT exctrl_desc  */
#line 1042 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_EDIT, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3200 "tools/wrc/parser.tab.c"
    break;

  case 124: /* exctrls: exctrls tLISTBOX exctrl_desc  */
#line 1043 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_LISTBOX, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3206 "tools/wrc/parser.tab.c"
    break;

  case 125: /* exctrls: exctrls tCOMBOBOX exctrl_desc  */
#line 1044 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_COMBOBOX, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3212 "tools/wrc/parser.tab.c"
    break;

  case 126: /* exctrls: exctrls tSCROLLBAR exctrl_desc  */
#line 1045 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_SCROLLBAR, 0, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3218 "tools/wrc/parser.tab.c"
    break;

  case 127: /* exctrls: exctrls tCHECKBOX lab_exctrl  */
#line 1046 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_CHECKBOX, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3224 "tools/wrc/parser.tab.c"
    break;

  case 128: /* exctrls: exctrls tDEFPUSHBUTTON lab_exctrl  */
#line 1047 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_DEFPUSHBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3230 "tools/wrc/parser.tab.c"
    break;

  case 129: /* exctrls: exctrls tGROUPBOX lab_exctrl  */
#line 1048 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_GROUPBOX, (yyvsp[0].ctl), (yyvsp[-2].ctl));}
#line 3236 "tools/wrc/parser.tab.c"
    break;

  case 130: /* exctrls: exctrls tPUSHBUTTON lab_exctrl  */
#line 1049 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_PUSHBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3242 "tools/wrc/parser.tab.c"
    break;

  case 131: /* exctrls: exctrls tRADIOBUTTON lab_exctrl  */
#line 1051 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_RADIOBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3248 "tools/wrc/parser.tab.c"
    break;

  case 132: /* exctrls: exctrls tAUTO3STATE lab_exctrl  */
#line 1052 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_AUTO3STATE, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3254 "tools/wrc/parser.tab.c"
    break;

  case 133: /* exctrls: exctrls tSTATE3 lab_exctrl  */
#line 1053 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_3STATE, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3260 "tools/wrc/parser.tab.c"
    break;

  case 134: /* exctrls: exctrls tAUTOCHECKBOX lab_exctrl  */
#line 1054 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_AUTOCHECKBOX, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3266 "tools/wrc/parser.tab.c"
    break;

  case 135: /* exctrls: exctrls tAUTORADIOBUTTON lab_exctrl  */
#line 1055 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_BUTTON, BS_AUTORADIOBUTTON, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3272 "tools/wrc/parser.tab.c"
    break;

  case 136: /* exctrls: exctrls tLTEXT lab_exctrl  */
#line 1056 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_STATIC, SS_LEFT, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3278 "tools/wrc/parser.tab.c"
    break;

  case 137: /* exctrls: exctrls tCTEXT lab_exctrl  */
#line 1057 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_STATIC, SS_CENTER, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3284 "tools/wrc/parser.tab.c"
    break;

  case 138: /* exctrls: exctrls tRTEXT lab_exctrl  */
#line 1058 "tools/wrc/parser.y"
                                                { (yyval.ctl)=ins_ctrl(CT_STATIC, SS_RIGHT, (yyvsp[0].ctl), (yyvsp[-2].ctl)); }
#line 3290 "tools/wrc/parser.tab.c"
    break;

  case 139: /* exctrls: exctrls tICON nameid_s opt_comma expr ',' expr ',' expr iconinfo  */
#line 1060 "tools/wrc/parser.y"
                                                                           {
		(yyvsp[0].ctl)->title = (yyvsp[-7].nid);
		(yyvsp[0].ctl)->id = (yyvsp[-5].num);
		(yyvsp[0].ctl)->x = (yyvsp[-3].num);
		(yyvsp[0].ctl)->y = (yyvsp[-1].num);
		(yyval.ctl) = ins_ctrl(CT_STATIC, SS_ICON, (yyvsp[0].ctl), (yyvsp[-9].ctl));
		}
#line 3302 "tools/wrc/parser.tab.c"
    break;

  case 140: /* gen_exctrl: nameid_s opt_comma expr ',' ctlclass ',' style ',' expr ',' expr ',' expr ',' expr ',' style helpid opt_data  */
#line 1071 "tools/wrc/parser.y"
                                         {
		(yyval.ctl)=new_control();
		(yyval.ctl)->title = (yyvsp[-18].nid);
		(yyval.ctl)->id = (yyvsp[-16].num);
		(yyval.ctl)->ctlclass = convert_ctlclass((yyvsp[-14].nid));
		(yyval.ctl)->style = (yyvsp[-12].style);
		(yyval.ctl)->gotstyle = TRUE;
		(yyval.ctl)->x = (yyvsp[-10].num);
		(yyval.ctl)->y = (yyvsp[-8].num);
		(yyval.ctl)->width = (yyvsp[-6].num);
		(yyval.ctl)->height = (yyvsp[-4].num);
		if((yyvsp[-2].style))
		{
			(yyval.ctl)->exstyle = (yyvsp[-2].style);
			(yyval.ctl)->gotexstyle = TRUE;
		}
		if((yyvsp[-1].iptr))
		{
			(yyval.ctl)->helpid = *((yyvsp[-1].iptr));
			(yyval.ctl)->gothelpid = TRUE;
			free((yyvsp[-1].iptr));
		}
		(yyval.ctl)->extra = (yyvsp[0].raw);
		}
#line 3331 "tools/wrc/parser.tab.c"
    break;

  case 141: /* gen_exctrl: nameid_s opt_comma expr ',' ctlclass ',' style ',' expr ',' expr ',' expr ',' expr opt_data  */
#line 1095 "tools/wrc/parser.y"
                                                                                                      {
		(yyval.ctl)=new_control();
		(yyval.ctl)->title = (yyvsp[-15].nid);
		(yyval.ctl)->id = (yyvsp[-13].num);
		(yyval.ctl)->style = (yyvsp[-9].style);
		(yyval.ctl)->gotstyle = TRUE;
		(yyval.ctl)->ctlclass = convert_ctlclass((yyvsp[-11].nid));
		(yyval.ctl)->x = (yyvsp[-7].num);
		(yyval.ctl)->y = (yyvsp[-5].num);
		(yyval.ctl)->width = (yyvsp[-3].num);
		(yyval.ctl)->height = (yyvsp[-1].num);
		(yyval.ctl)->extra = (yyvsp[0].raw);
		}
#line 3349 "tools/wrc/parser.tab.c"
    break;

  case 142: /* lab_exctrl: nameid_s opt_comma expr ',' expr ',' expr ',' expr ',' expr optional_style_pair helpid opt_data  */
#line 1111 "tools/wrc/parser.y"
                                                                                                          {
		(yyval.ctl)=new_control();
		(yyval.ctl)->title = (yyvsp[-13].nid);
		(yyval.ctl)->id = (yyvsp[-11].num);
		(yyval.ctl)->x = (yyvsp[-9].num);
		(yyval.ctl)->y = (yyvsp[-7].num);
		(yyval.ctl)->width = (yyvsp[-5].num);
		(yyval.ctl)->height = (yyvsp[-3].num);
		if((yyvsp[-2].styles))
		{
			(yyval.ctl)->style = (yyvsp[-2].styles)->style;
			(yyval.ctl)->gotstyle = TRUE;

			if ((yyvsp[-2].styles)->exstyle)
			{
			    (yyval.ctl)->exstyle = (yyvsp[-2].styles)->exstyle;
			    (yyval.ctl)->gotexstyle = TRUE;
			}
			free((yyvsp[-2].styles));
		}

		(yyval.ctl)->extra = (yyvsp[0].raw);
		}
#line 3377 "tools/wrc/parser.tab.c"
    break;

  case 143: /* exctrl_desc: expr ',' expr ',' expr ',' expr ',' expr optional_style_pair helpid opt_data  */
#line 1137 "tools/wrc/parser.y"
                                                                                       {
		(yyval.ctl) = new_control();
		(yyval.ctl)->id = (yyvsp[-11].num);
		(yyval.ctl)->x = (yyvsp[-9].num);
		(yyval.ctl)->y = (yyvsp[-7].num);
		(yyval.ctl)->width = (yyvsp[-5].num);
		(yyval.ctl)->height = (yyvsp[-3].num);
		if((yyvsp[-2].styles))
		{
			(yyval.ctl)->style = (yyvsp[-2].styles)->style;
			(yyval.ctl)->gotstyle = TRUE;

			if ((yyvsp[-2].styles)->exstyle)
			{
			    (yyval.ctl)->exstyle = (yyvsp[-2].styles)->exstyle;
			    (yyval.ctl)->gotexstyle = TRUE;
			}
			free((yyvsp[-2].styles));
		}
		(yyval.ctl)->extra = (yyvsp[0].raw);
		}
#line 3403 "tools/wrc/parser.tab.c"
    break;

  case 144: /* opt_data: %empty  */
#line 1160 "tools/wrc/parser.y"
                        { (yyval.raw) = NULL; }
#line 3409 "tools/wrc/parser.tab.c"
    break;

  case 145: /* opt_data: raw_data  */
#line 1161 "tools/wrc/parser.y"
                        { (yyval.raw) = (yyvsp[0].raw); }
#line 3415 "tools/wrc/parser.tab.c"
    break;

  case 146: /* helpid: %empty  */
#line 1164 "tools/wrc/parser.y"
                        { (yyval.iptr) = NULL; }
#line 3421 "tools/wrc/parser.tab.c"
    break;

  case 147: /* helpid: ',' expr  */
#line 1165 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int((yyvsp[0].num)); }
#line 3427 "tools/wrc/parser.tab.c"
    break;

  case 148: /* opt_exfont: tFONT expr ',' tSTRING ',' expr ',' expr opt_expr  */
#line 1169 "tools/wrc/parser.y"
                                                             { (yyval.fntid) = new_font_id((yyvsp[-7].num), (yyvsp[-5].str), (yyvsp[-3].num), (yyvsp[-1].num)); }
#line 3433 "tools/wrc/parser.tab.c"
    break;

  case 149: /* opt_expr: %empty  */
#line 1176 "tools/wrc/parser.y"
                        { (yyval.fntid) = NULL; }
#line 3439 "tools/wrc/parser.tab.c"
    break;

  case 150: /* opt_expr: ',' expr  */
#line 1177 "tools/wrc/parser.y"
                        { (yyval.fntid) = NULL; }
#line 3445 "tools/wrc/parser.tab.c"
    break;

  case 151: /* menu: tMENU loadmemopts opt_lvc menu_body  */
#line 1181 "tools/wrc/parser.y"
                                              {
		if(!(yyvsp[0].menitm))
			yyerror("Menu must contain items");
		(yyval.men) = new_menu();
		if((yyvsp[-2].iptr))
		{
			(yyval.men)->memopt = *((yyvsp[-2].iptr));
			free((yyvsp[-2].iptr));
		}
		else
			(yyval.men)->memopt = WRC_MO_MOVEABLE | WRC_MO_PURE | WRC_MO_DISCARDABLE;
		(yyval.men)->items = get_item_head((yyvsp[0].menitm));
		if((yyvsp[-1].lvc))
		{
			(yyval.men)->lvc = *((yyvsp[-1].lvc));
			free((yyvsp[-1].lvc));
		}
		if(!(yyval.men)->lvc.language) (yyval.men)->lvc.language = currentlanguage;
		}
#line 3469 "tools/wrc/parser.tab.c"
    break;

  case 152: /* menu_body: tBEGIN item_definitions tEND  */
#line 1203 "tools/wrc/parser.y"
                                        { (yyval.menitm) = (yyvsp[-1].menitm); }
#line 3475 "tools/wrc/parser.tab.c"
    break;

  case 153: /* item_definitions: %empty  */
#line 1207 "tools/wrc/parser.y"
                        {(yyval.menitm) = NULL;}
#line 3481 "tools/wrc/parser.tab.c"
    break;

  case 154: /* item_definitions: item_definitions tMENUITEM tSTRING opt_comma expr item_options  */
#line 1208 "tools/wrc/parser.y"
                                                                         {
		(yyval.menitm)=new_menu_item();
		(yyval.menitm)->prev = (yyvsp[-5].menitm);
		if((yyvsp[-5].menitm))
			(yyvsp[-5].menitm)->next = (yyval.menitm);
		(yyval.menitm)->id =  (yyvsp[-1].num);
		(yyval.menitm)->state = (yyvsp[0].num);
		(yyval.menitm)->name = (yyvsp[-3].str);
		}
#line 3495 "tools/wrc/parser.tab.c"
    break;

  case 155: /* item_definitions: item_definitions tMENUITEM tSEPARATOR  */
#line 1217 "tools/wrc/parser.y"
                                                {
		(yyval.menitm)=new_menu_item();
		(yyval.menitm)->prev = (yyvsp[-2].menitm);
		if((yyvsp[-2].menitm))
			(yyvsp[-2].menitm)->next = (yyval.menitm);
		}
#line 3506 "tools/wrc/parser.tab.c"
    break;

  case 156: /* item_definitions: item_definitions tPOPUP tSTRING item_options menu_body  */
#line 1223 "tools/wrc/parser.y"
                                                                 {
		(yyval.menitm) = new_menu_item();
		(yyval.menitm)->prev = (yyvsp[-4].menitm);
		if((yyvsp[-4].menitm))
			(yyvsp[-4].menitm)->next = (yyval.menitm);
		(yyval.menitm)->popup = get_item_head((yyvsp[0].menitm));
		(yyval.menitm)->name = (yyvsp[-2].str);
		}
#line 3519 "tools/wrc/parser.tab.c"
    break;

  case 157: /* item_options: %empty  */
#line 1242 "tools/wrc/parser.y"
                                        { (yyval.num) = 0; }
#line 3525 "tools/wrc/parser.tab.c"
    break;

  case 158: /* item_options: ',' item_options  */
#line 1243 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num); }
#line 3531 "tools/wrc/parser.tab.c"
    break;

  case 159: /* item_options: tCHECKED item_options  */
#line 1244 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num) | MF_CHECKED; }
#line 3537 "tools/wrc/parser.tab.c"
    break;

  case 160: /* item_options: tGRAYED item_options  */
#line 1245 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num) | MF_GRAYED; }
#line 3543 "tools/wrc/parser.tab.c"
    break;

  case 161: /* item_options: tHELP item_options  */
#line 1246 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num) | MF_HELP; }
#line 3549 "tools/wrc/parser.tab.c"
    break;

  case 162: /* item_options: tINACTIVE item_options  */
#line 1247 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num) | MF_DISABLED; }
#line 3555 "tools/wrc/parser.tab.c"
    break;

  case 163: /* item_options: tMENUBARBREAK item_options  */
#line 1248 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num) | MF_MENUBARBREAK; }
#line 3561 "tools/wrc/parser.tab.c"
    break;

  case 164: /* item_options: tMENUBREAK item_options  */
#line 1249 "tools/wrc/parser.y"
                                        { (yyval.num) = (yyvsp[0].num) | MF_MENUBREAK; }
#line 3567 "tools/wrc/parser.tab.c"
    break;

  case 165: /* menuex: tMENUEX loadmemopts opt_lvc menuex_body  */
#line 1253 "tools/wrc/parser.y"
                                                        {
		if(!win32)
			parser_warning("MENUEX not supported in 16-bit mode\n");
		if(!(yyvsp[0].menitm))
			yyerror("MenuEx must contain items");
		(yyval.men) = new_menu();
		(yyval.men)->is_ex = TRUE;
		if((yyvsp[-2].iptr))
		{
			(yyval.men)->memopt = *((yyvsp[-2].iptr));
			free((yyvsp[-2].iptr));
		}
		else
			(yyval.men)->memopt = WRC_MO_MOVEABLE | WRC_MO_PURE | WRC_MO_DISCARDABLE;
		(yyval.men)->items = get_item_head((yyvsp[0].menitm));
		if((yyvsp[-1].lvc))
		{
			(yyval.men)->lvc = *((yyvsp[-1].lvc));
			free((yyvsp[-1].lvc));
		}
		if(!(yyval.men)->lvc.language) (yyval.men)->lvc.language = currentlanguage;
		}
#line 3594 "tools/wrc/parser.tab.c"
    break;

  case 166: /* menuex_body: tBEGIN itemex_definitions tEND  */
#line 1278 "tools/wrc/parser.y"
                                         { (yyval.menitm) = (yyvsp[-1].menitm); }
#line 3600 "tools/wrc/parser.tab.c"
    break;

  case 167: /* itemex_definitions: %empty  */
#line 1282 "tools/wrc/parser.y"
                        {(yyval.menitm) = NULL; }
#line 3606 "tools/wrc/parser.tab.c"
    break;

  case 168: /* itemex_definitions: itemex_definitions tMENUITEM tSTRING itemex_options  */
#line 1283 "tools/wrc/parser.y"
                                                              {
		(yyval.menitm) = new_menu_item();
		(yyval.menitm)->prev = (yyvsp[-3].menitm);
		if((yyvsp[-3].menitm))
			(yyvsp[-3].menitm)->next = (yyval.menitm);
		(yyval.menitm)->name = (yyvsp[-1].str);
		(yyval.menitm)->id = (yyvsp[0].exopt)->id;
		(yyval.menitm)->type = (yyvsp[0].exopt)->type;
		(yyval.menitm)->state = (yyvsp[0].exopt)->state;
		(yyval.menitm)->helpid = (yyvsp[0].exopt)->helpid;
		(yyval.menitm)->gotid = (yyvsp[0].exopt)->gotid;
		(yyval.menitm)->gottype = (yyvsp[0].exopt)->gottype;
		(yyval.menitm)->gotstate = (yyvsp[0].exopt)->gotstate;
		(yyval.menitm)->gothelpid = (yyvsp[0].exopt)->gothelpid;
		free((yyvsp[0].exopt));
		}
#line 3627 "tools/wrc/parser.tab.c"
    break;

  case 169: /* itemex_definitions: itemex_definitions tMENUITEM tSEPARATOR  */
#line 1299 "tools/wrc/parser.y"
                                                  {
		(yyval.menitm) = new_menu_item();
		(yyval.menitm)->prev = (yyvsp[-2].menitm);
		if((yyvsp[-2].menitm))
			(yyvsp[-2].menitm)->next = (yyval.menitm);
		}
#line 3638 "tools/wrc/parser.tab.c"
    break;

  case 170: /* itemex_definitions: itemex_definitions tPOPUP tSTRING itemex_p_options menuex_body  */
#line 1305 "tools/wrc/parser.y"
                                                                         {
		(yyval.menitm) = new_menu_item();
		(yyval.menitm)->prev = (yyvsp[-4].menitm);
		if((yyvsp[-4].menitm))
			(yyvsp[-4].menitm)->next = (yyval.menitm);
		(yyval.menitm)->popup = get_item_head((yyvsp[0].menitm));
		(yyval.menitm)->name = (yyvsp[-2].str);
		(yyval.menitm)->id = (yyvsp[-1].exopt)->id;
		(yyval.menitm)->type = (yyvsp[-1].exopt)->type;
		(yyval.menitm)->state = (yyvsp[-1].exopt)->state;
		(yyval.menitm)->helpid = (yyvsp[-1].exopt)->helpid;
		(yyval.menitm)->gotid = (yyvsp[-1].exopt)->gotid;
		(yyval.menitm)->gottype = (yyvsp[-1].exopt)->gottype;
		(yyval.menitm)->gotstate = (yyvsp[-1].exopt)->gotstate;
		(yyval.menitm)->gothelpid = (yyvsp[-1].exopt)->gothelpid;
		free((yyvsp[-1].exopt));
		}
#line 3660 "tools/wrc/parser.tab.c"
    break;

  case 171: /* itemex_options: %empty  */
#line 1325 "tools/wrc/parser.y"
                                        { (yyval.exopt) = new_itemex_opt(0, 0, 0, 0); }
#line 3666 "tools/wrc/parser.tab.c"
    break;

  case 172: /* itemex_options: ',' expr  */
#line 1326 "tools/wrc/parser.y"
                   {
		(yyval.exopt) = new_itemex_opt((yyvsp[0].num), 0, 0, 0);
		(yyval.exopt)->gotid = TRUE;
		}
#line 3675 "tools/wrc/parser.tab.c"
    break;

  case 173: /* itemex_options: ',' e_expr ',' e_expr item_options  */
#line 1330 "tools/wrc/parser.y"
                                             {
		(yyval.exopt) = new_itemex_opt((yyvsp[-3].iptr) ? *((yyvsp[-3].iptr)) : 0, (yyvsp[-1].iptr) ? *((yyvsp[-1].iptr)) : 0, (yyvsp[0].num), 0);
		(yyval.exopt)->gotid = TRUE;
		(yyval.exopt)->gottype = TRUE;
		(yyval.exopt)->gotstate = TRUE;
		free((yyvsp[-3].iptr));
		free((yyvsp[-1].iptr));
		}
#line 3688 "tools/wrc/parser.tab.c"
    break;

  case 174: /* itemex_options: ',' e_expr ',' e_expr ',' expr  */
#line 1338 "tools/wrc/parser.y"
                                         {
		(yyval.exopt) = new_itemex_opt((yyvsp[-4].iptr) ? *((yyvsp[-4].iptr)) : 0, (yyvsp[-2].iptr) ? *((yyvsp[-2].iptr)) : 0, (yyvsp[0].num), 0);
		(yyval.exopt)->gotid = TRUE;
		(yyval.exopt)->gottype = TRUE;
		(yyval.exopt)->gotstate = TRUE;
		free((yyvsp[-4].iptr));
		free((yyvsp[-2].iptr));
		}
#line 3701 "tools/wrc/parser.tab.c"
    break;

  case 175: /* itemex_p_options: %empty  */
#line 1349 "tools/wrc/parser.y"
                                        { (yyval.exopt) = new_itemex_opt(0, 0, 0, 0); }
#line 3707 "tools/wrc/parser.tab.c"
    break;

  case 176: /* itemex_p_options: ',' expr  */
#line 1350 "tools/wrc/parser.y"
                   {
		(yyval.exopt) = new_itemex_opt((yyvsp[0].num), 0, 0, 0);
		(yyval.exopt)->gotid = TRUE;
		}
#line 3716 "tools/wrc/parser.tab.c"
    break;

  case 177: /* itemex_p_options: ',' e_expr ',' expr  */
#line 1354 "tools/wrc/parser.y"
                              {
		(yyval.exopt) = new_itemex_opt((yyvsp[-2].iptr) ? *((yyvsp[-2].iptr)) : 0, (yyvsp[0].num), 0, 0);
		free((yyvsp[-2].iptr));
		(yyval.exopt)->gotid = TRUE;
		(yyval.exopt)->gottype = TRUE;
		}
#line 3727 "tools/wrc/parser.tab.c"
    break;

  case 178: /* itemex_p_options: ',' e_expr ',' e_expr ',' expr  */
#line 1360 "tools/wrc/parser.y"
                                         {
		(yyval.exopt) = new_itemex_opt((yyvsp[-4].iptr) ? *((yyvsp[-4].iptr)) : 0, (yyvsp[-2].iptr) ? *((yyvsp[-2].iptr)) : 0, (yyvsp[0].num), 0);
		free((yyvsp[-4].iptr));
		free((yyvsp[-2].iptr));
		(yyval.exopt)->gotid = TRUE;
		(yyval.exopt)->gottype = TRUE;
		(yyval.exopt)->gotstate = TRUE;
		}
#line 3740 "tools/wrc/parser.tab.c"
    break;

  case 179: /* itemex_p_options: ',' e_expr ',' e_expr ',' e_expr ',' expr  */
#line 1368 "tools/wrc/parser.y"
                                                    {
		(yyval.exopt) = new_itemex_opt((yyvsp[-6].iptr) ? *((yyvsp[-6].iptr)) : 0, (yyvsp[-4].iptr) ? *((yyvsp[-4].iptr)) : 0, (yyvsp[-2].iptr) ? *((yyvsp[-2].iptr)) : 0, (yyvsp[0].num));
		free((yyvsp[-6].iptr));
		free((yyvsp[-4].iptr));
		free((yyvsp[-2].iptr));
		(yyval.exopt)->gotid = TRUE;
		(yyval.exopt)->gottype = TRUE;
		(yyval.exopt)->gotstate = TRUE;
		(yyval.exopt)->gothelpid = TRUE;
		}
#line 3755 "tools/wrc/parser.tab.c"
    break;

  case 180: /* stringtable: stt_head tBEGIN strings tEND  */
#line 1388 "tools/wrc/parser.y"
                                       {
		if(!(yyvsp[-1].stt))
		{
			yyerror("Stringtable must have at least one entry");
		}
		else
		{
			stringtable_t *stt;
			/* Check if we added to a language table or created
			 * a new one.
			 */
			 for(stt = sttres; stt; stt = stt->next)
			 {
				if(stt == tagstt)
					break;
			 }
			 if(!stt)
			 {
				/* It is a new one */
				if(sttres)
				{
					sttres->prev = tagstt;
					tagstt->next = sttres;
					sttres = tagstt;
				}
				else
					sttres = tagstt;
			 }
			 /* Else, we're done */
		}
		free(tagstt_memopt);
		tagstt_memopt = NULL;

		(yyval.stt) = tagstt;
		}
#line 3795 "tools/wrc/parser.tab.c"
    break;

  case 181: /* stt_head: tSTRINGTABLE loadmemopts opt_lvc  */
#line 1426 "tools/wrc/parser.y"
                                           {
		if((tagstt = find_stringtable((yyvsp[0].lvc))) == NULL)
			tagstt = new_stringtable((yyvsp[0].lvc));
		tagstt_memopt = (yyvsp[-1].iptr);
		tagstt_version = (yyvsp[0].lvc)->version;
		tagstt_characts = (yyvsp[0].lvc)->characts;
		free((yyvsp[0].lvc));
		}
#line 3808 "tools/wrc/parser.tab.c"
    break;

  case 182: /* strings: %empty  */
#line 1436 "tools/wrc/parser.y"
                        { (yyval.stt) = NULL; }
#line 3814 "tools/wrc/parser.tab.c"
    break;

  case 183: /* strings: strings expr opt_comma tSTRING  */
#line 1437 "tools/wrc/parser.y"
                                         {
		int i;
		assert(tagstt != NULL);
		if((yyvsp[-2].num) > 65535 || (yyvsp[-2].num) < -32768)
			yyerror("Stringtable entry's ID out of range (%d)", (yyvsp[-2].num));
		/* Search for the ID */
		for(i = 0; i < tagstt->nentries; i++)
		{
			if(tagstt->entries[i].id == (yyvsp[-2].num))
				yyerror("Stringtable ID %d already in use", (yyvsp[-2].num));
		}
		/* If we get here, then we have a new unique entry */
		tagstt->nentries++;
		tagstt->entries = xrealloc(tagstt->entries, sizeof(tagstt->entries[0]) * tagstt->nentries);
		tagstt->entries[tagstt->nentries-1].id = (yyvsp[-2].num);
		tagstt->entries[tagstt->nentries-1].str = (yyvsp[0].str);
		if(tagstt_memopt)
			tagstt->entries[tagstt->nentries-1].memopt = *tagstt_memopt;
		else
			tagstt->entries[tagstt->nentries-1].memopt = WRC_MO_MOVEABLE | WRC_MO_DISCARDABLE | WRC_MO_PURE;
		tagstt->entries[tagstt->nentries-1].version = tagstt_version;
		tagstt->entries[tagstt->nentries-1].characts = tagstt_characts;

		if(pedantic && !(yyvsp[0].str)->size)
			parser_warning("Zero length strings make no sense\n");
		if(!win32 && (yyvsp[0].str)->size > 254)
			yyerror("Stringtable entry more than 254 characters");
		if(win32 && (yyvsp[0].str)->size > 65534) /* Hmm..., does this happen? */
			yyerror("Stringtable entry more than 65534 characters (probably something else that went wrong)");
		(yyval.stt) = tagstt;
		}
#line 3850 "tools/wrc/parser.tab.c"
    break;

  case 186: /* versioninfo: tVERSIONINFO loadmemopts fix_version tBEGIN ver_blocks tEND  */
#line 1477 "tools/wrc/parser.y"
                                                                      {
		(yyval.veri) = (yyvsp[-3].veri);
		if((yyvsp[-4].iptr))
		{
			(yyval.veri)->memopt = *((yyvsp[-4].iptr));
			free((yyvsp[-4].iptr));
		}
		else
			(yyval.veri)->memopt = WRC_MO_MOVEABLE | (win32 ? WRC_MO_PURE : 0);
		(yyval.veri)->blocks = get_ver_block_head((yyvsp[-1].blk));
		/* Set language; there is no version or characteristics */
		(yyval.veri)->lvc.language = currentlanguage;
		}
#line 3868 "tools/wrc/parser.tab.c"
    break;

  case 187: /* fix_version: %empty  */
#line 1493 "tools/wrc/parser.y"
                                        { (yyval.veri) = new_versioninfo(); }
#line 3874 "tools/wrc/parser.tab.c"
    break;

  case 188: /* fix_version: fix_version tFILEVERSION expr ',' expr ',' expr ',' expr  */
#line 1494 "tools/wrc/parser.y"
                                                                   {
		if((yyvsp[-8].veri)->gotit.fv)
			yyerror("FILEVERSION already defined");
		(yyval.veri) = (yyvsp[-8].veri);
		(yyval.veri)->filever_maj1 = (yyvsp[-6].num);
		(yyval.veri)->filever_maj2 = (yyvsp[-4].num);
		(yyval.veri)->filever_min1 = (yyvsp[-2].num);
		(yyval.veri)->filever_min2 = (yyvsp[0].num);
		(yyval.veri)->gotit.fv = 1;
		}
#line 3889 "tools/wrc/parser.tab.c"
    break;

  case 189: /* fix_version: fix_version tPRODUCTVERSION expr ',' expr ',' expr ',' expr  */
#line 1504 "tools/wrc/parser.y"
                                                                      {
		if((yyvsp[-8].veri)->gotit.pv)
			yyerror("PRODUCTVERSION already defined");
		(yyval.veri) = (yyvsp[-8].veri);
		(yyval.veri)->prodver_maj1 = (yyvsp[-6].num);
		(yyval.veri)->prodver_maj2 = (yyvsp[-4].num);
		(yyval.veri)->prodver_min1 = (yyvsp[-2].num);
		(yyval.veri)->prodver_min2 = (yyvsp[0].num);
		(yyval.veri)->gotit.pv = 1;
		}
#line 3904 "tools/wrc/parser.tab.c"
    break;

  case 190: /* fix_version: fix_version tFILEFLAGS expr  */
#line 1514 "tools/wrc/parser.y"
                                      {
		if((yyvsp[-2].veri)->gotit.ff)
			yyerror("FILEFLAGS already defined");
		(yyval.veri) = (yyvsp[-2].veri);
		(yyval.veri)->fileflags = (yyvsp[0].num);
		(yyval.veri)->gotit.ff = 1;
		}
#line 3916 "tools/wrc/parser.tab.c"
    break;

  case 191: /* fix_version: fix_version tFILEFLAGSMASK expr  */
#line 1521 "tools/wrc/parser.y"
                                          {
		if((yyvsp[-2].veri)->gotit.ffm)
			yyerror("FILEFLAGSMASK already defined");
		(yyval.veri) = (yyvsp[-2].veri);
		(yyval.veri)->fileflagsmask = (yyvsp[0].num);
		(yyval.veri)->gotit.ffm = 1;
		}
#line 3928 "tools/wrc/parser.tab.c"
    break;

  case 192: /* fix_version: fix_version tFILEOS expr  */
#line 1528 "tools/wrc/parser.y"
                                   {
		if((yyvsp[-2].veri)->gotit.fo)
			yyerror("FILEOS already defined");
		(yyval.veri) = (yyvsp[-2].veri);
		(yyval.veri)->fileos = (yyvsp[0].num);
		(yyval.veri)->gotit.fo = 1;
		}
#line 3940 "tools/wrc/parser.tab.c"
    break;

  case 193: /* fix_version: fix_version tFILETYPE expr  */
#line 1535 "tools/wrc/parser.y"
                                     {
		if((yyvsp[-2].veri)->gotit.ft)
			yyerror("FILETYPE already defined");
		(yyval.veri) = (yyvsp[-2].veri);
		(yyval.veri)->filetype = (yyvsp[0].num);
		(yyval.veri)->gotit.ft = 1;
		}
#line 3952 "tools/wrc/parser.tab.c"
    break;

  case 194: /* fix_version: fix_version tFILESUBTYPE expr  */
#line 1542 "tools/wrc/parser.y"
                                        {
		if((yyvsp[-2].veri)->gotit.fst)
			yyerror("FILESUBTYPE already defined");
		(yyval.veri) = (yyvsp[-2].veri);
		(yyval.veri)->filesubtype = (yyvsp[0].num);
		(yyval.veri)->gotit.fst = 1;
		}
#line 3964 "tools/wrc/parser.tab.c"
    break;

  case 195: /* ver_blocks: %empty  */
#line 1552 "tools/wrc/parser.y"
                                        { (yyval.blk) = NULL; }
#line 3970 "tools/wrc/parser.tab.c"
    break;

  case 196: /* ver_blocks: ver_blocks ver_block  */
#line 1553 "tools/wrc/parser.y"
                               {
		(yyval.blk) = (yyvsp[0].blk);
		(yyval.blk)->prev = (yyvsp[-1].blk);
		if((yyvsp[-1].blk))
			(yyvsp[-1].blk)->next = (yyval.blk);
		}
#line 3981 "tools/wrc/parser.tab.c"
    break;

  case 197: /* ver_block: tBLOCK tSTRING tBEGIN ver_values tEND  */
#line 1562 "tools/wrc/parser.y"
                                                {
		(yyval.blk) = new_ver_block();
		(yyval.blk)->name = (yyvsp[-3].str);
		(yyval.blk)->values = get_ver_value_head((yyvsp[-1].val));
		}
#line 3991 "tools/wrc/parser.tab.c"
    break;

  case 198: /* ver_values: %empty  */
#line 1570 "tools/wrc/parser.y"
                                        { (yyval.val) = NULL; }
#line 3997 "tools/wrc/parser.tab.c"
    break;

  case 199: /* ver_values: ver_values ver_value  */
#line 1571 "tools/wrc/parser.y"
                               {
		(yyval.val) = (yyvsp[0].val);
		(yyval.val)->prev = (yyvsp[-1].val);
		if((yyvsp[-1].val))
			(yyvsp[-1].val)->next = (yyval.val);
		}
#line 4008 "tools/wrc/parser.tab.c"
    break;

  case 200: /* ver_value: ver_block  */
#line 1580 "tools/wrc/parser.y"
                    {
		(yyval.val) = new_ver_value();
		(yyval.val)->type = val_block;
		(yyval.val)->value.block = (yyvsp[0].blk);
		}
#line 4018 "tools/wrc/parser.tab.c"
    break;

  case 201: /* ver_value: tVALUE tSTRING ',' tSTRING  */
#line 1585 "tools/wrc/parser.y"
                                     {
		(yyval.val) = new_ver_value();
		(yyval.val)->type = val_str;
		(yyval.val)->key = (yyvsp[-2].str);
		(yyval.val)->value.str = (yyvsp[0].str);
		}
#line 4029 "tools/wrc/parser.tab.c"
    break;

  case 202: /* ver_value: tVALUE tSTRING ',' ver_words  */
#line 1591 "tools/wrc/parser.y"
                                       {
		(yyval.val) = new_ver_value();
		(yyval.val)->type = val_words;
		(yyval.val)->key = (yyvsp[-2].str);
		(yyval.val)->value.words = (yyvsp[0].verw);
		}
#line 4040 "tools/wrc/parser.tab.c"
    break;

  case 203: /* ver_words: expr  */
#line 1600 "tools/wrc/parser.y"
                                { (yyval.verw) = new_ver_words((yyvsp[0].num)); }
#line 4046 "tools/wrc/parser.tab.c"
    break;

  case 204: /* ver_words: ver_words ',' expr  */
#line 1601 "tools/wrc/parser.y"
                                { (yyval.verw) = add_ver_words((yyvsp[-2].verw), (yyvsp[0].num)); }
#line 4052 "tools/wrc/parser.tab.c"
    break;

  case 205: /* toolbar: tTOOLBAR loadmemopts expr ',' expr opt_lvc tBEGIN toolbar_items tEND  */
#line 1605 "tools/wrc/parser.y"
                                                                              {
		int nitems;
		toolbar_item_t *items = get_tlbr_buttons_head((yyvsp[-1].tlbarItems), &nitems);
		(yyval.tlbar) = new_toolbar((yyvsp[-6].num), (yyvsp[-4].num), items, nitems);
		if((yyvsp[-7].iptr))
		{
			(yyval.tlbar)->memopt = *((yyvsp[-7].iptr));
			free((yyvsp[-7].iptr));
		}
		else
		{
			(yyval.tlbar)->memopt = WRC_MO_MOVEABLE | WRC_MO_PURE;
		}
		if((yyvsp[-3].lvc))
		{
			(yyval.tlbar)->lvc = *((yyvsp[-3].lvc));
			free((yyvsp[-3].lvc));
		}
		if(!(yyval.tlbar)->lvc.language) (yyval.tlbar)->lvc.language = currentlanguage;
		}
#line 4077 "tools/wrc/parser.tab.c"
    break;

  case 206: /* toolbar_items: %empty  */
#line 1628 "tools/wrc/parser.y"
                                        { (yyval.tlbarItems) = NULL; }
#line 4083 "tools/wrc/parser.tab.c"
    break;

  case 207: /* toolbar_items: toolbar_items tBUTTON expr  */
#line 1629 "tools/wrc/parser.y"
                                        {
		toolbar_item_t *idrec = new_toolbar_item();
		idrec->id = (yyvsp[0].num);
		(yyval.tlbarItems) = ins_tlbr_button((yyvsp[-2].tlbarItems), idrec);
		}
#line 4093 "tools/wrc/parser.tab.c"
    break;

  case 208: /* toolbar_items: toolbar_items tSEPARATOR  */
#line 1634 "tools/wrc/parser.y"
                                        {
		toolbar_item_t *idrec = new_toolbar_item();
		idrec->id = 0;
		(yyval.tlbarItems) = ins_tlbr_button((yyvsp[-1].tlbarItems), idrec);
	}
#line 4103 "tools/wrc/parser.tab.c"
    break;

  case 209: /* loadmemopts: %empty  */
#line 1643 "tools/wrc/parser.y"
                                { (yyval.iptr) = NULL; }
#line 4109 "tools/wrc/parser.tab.c"
    break;

  case 210: /* loadmemopts: loadmemopts lamo  */
#line 1644 "tools/wrc/parser.y"
                           {
		if((yyvsp[-1].iptr))
		{
			*((yyvsp[-1].iptr)) |= *((yyvsp[0].iptr));
			(yyval.iptr) = (yyvsp[-1].iptr);
			free((yyvsp[0].iptr));
		}
		else
			(yyval.iptr) = (yyvsp[0].iptr);
		}
#line 4124 "tools/wrc/parser.tab.c"
    break;

  case 211: /* loadmemopts: loadmemopts lama  */
#line 1654 "tools/wrc/parser.y"
                           {
		if((yyvsp[-1].iptr))
		{
			*((yyvsp[-1].iptr)) &= *((yyvsp[0].iptr));
			(yyval.iptr) = (yyvsp[-1].iptr);
			free((yyvsp[0].iptr));
		}
		else
		{
			*(yyvsp[0].iptr) &= WRC_MO_MOVEABLE | WRC_MO_DISCARDABLE | WRC_MO_PURE;
			(yyval.iptr) = (yyvsp[0].iptr);
		}
		}
#line 4142 "tools/wrc/parser.tab.c"
    break;

  case 212: /* lamo: tPRELOAD  */
#line 1669 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(WRC_MO_PRELOAD);
			  if (win32 && pedantic) parser_warning("PRELOAD is ignored in 32-bit mode\n"); }
#line 4149 "tools/wrc/parser.tab.c"
    break;

  case 213: /* lamo: tMOVEABLE  */
#line 1671 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(WRC_MO_MOVEABLE);
			  if (win32 && pedantic) parser_warning("MOVEABLE is ignored in 32-bit mode\n"); }
#line 4156 "tools/wrc/parser.tab.c"
    break;

  case 214: /* lamo: tDISCARDABLE  */
#line 1673 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(WRC_MO_DISCARDABLE);
			  if (win32 && pedantic) parser_warning("DISCARDABLE is ignored in 32-bit mode\n"); }
#line 4163 "tools/wrc/parser.tab.c"
    break;

  case 215: /* lamo: tPURE  */
#line 1675 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(WRC_MO_PURE);
			  if (win32 && pedantic) parser_warning("PURE is ignored in 32-bit mode\n"); }
#line 4170 "tools/wrc/parser.tab.c"
    break;

  case 216: /* lama: tLOADONCALL  */
#line 1679 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(~WRC_MO_PRELOAD);
			  if (win32 && pedantic) parser_warning("LOADONCALL is ignored in 32-bit mode\n"); }
#line 4177 "tools/wrc/parser.tab.c"
    break;

  case 217: /* lama: tFIXED  */
#line 1681 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(~WRC_MO_MOVEABLE);
			  if (win32 && pedantic) parser_warning("FIXED is ignored in 32-bit mode\n"); }
#line 4184 "tools/wrc/parser.tab.c"
    break;

  case 218: /* lama: tIMPURE  */
#line 1683 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int(~WRC_MO_PURE);
			  if (win32 && pedantic) parser_warning("IMPURE is ignored in 32-bit mode\n"); }
#line 4191 "tools/wrc/parser.tab.c"
    break;

  case 219: /* opt_lvc: %empty  */
#line 1688 "tools/wrc/parser.y"
                                { (yyval.lvc) = new_lvc(); }
#line 4197 "tools/wrc/parser.tab.c"
    break;

  case 220: /* opt_lvc: opt_lvc opt_language  */
#line 1689 "tools/wrc/parser.y"
                               {
		if(!win32)
			parser_warning("LANGUAGE not supported in 16-bit mode\n");
		if((yyvsp[-1].lvc)->language)
			yyerror("Language already defined");
		(yyval.lvc) = (yyvsp[-1].lvc);
		(yyvsp[-1].lvc)->language = (yyvsp[0].lan);
		}
#line 4210 "tools/wrc/parser.tab.c"
    break;

  case 221: /* opt_lvc: opt_lvc opt_characts  */
#line 1697 "tools/wrc/parser.y"
                               {
		if(!win32)
			parser_warning("CHARACTERISTICS not supported in 16-bit mode\n");
		if((yyvsp[-1].lvc)->characts)
			yyerror("Characteristics already defined");
		(yyval.lvc) = (yyvsp[-1].lvc);
		(yyvsp[-1].lvc)->characts = (yyvsp[0].chars);
		}
#line 4223 "tools/wrc/parser.tab.c"
    break;

  case 222: /* opt_lvc: opt_lvc opt_version  */
#line 1705 "tools/wrc/parser.y"
                              {
		if(!win32)
			parser_warning("VERSION not supported in 16-bit mode\n");
		if((yyvsp[-1].lvc)->version)
			yyerror("Version already defined");
		(yyval.lvc) = (yyvsp[-1].lvc);
		(yyvsp[-1].lvc)->version = (yyvsp[0].ver);
		}
#line 4236 "tools/wrc/parser.tab.c"
    break;

  case 223: /* opt_language: tLANGUAGE expr ',' expr  */
#line 1723 "tools/wrc/parser.y"
                                        { (yyval.lan) = MAKELANGID((yyvsp[-2].num), (yyvsp[0].num));
					  if (get_language_codepage((yyval.lan)) == -1)
						yyerror( "Language %04x is not supported", (yyval.lan));
					}
#line 4245 "tools/wrc/parser.tab.c"
    break;

  case 224: /* opt_characts: tCHARACTERISTICS expr  */
#line 1730 "tools/wrc/parser.y"
                                        { (yyval.chars) = (yyvsp[0].num); }
#line 4251 "tools/wrc/parser.tab.c"
    break;

  case 225: /* opt_version: tVERSION expr  */
#line 1734 "tools/wrc/parser.y"
                                        { (yyval.ver) = (yyvsp[0].num); }
#line 4257 "tools/wrc/parser.tab.c"
    break;

  case 226: /* raw_data: opt_lvc tBEGIN raw_elements tEND  */
#line 1738 "tools/wrc/parser.y"
                                           {
		if((yyvsp[-3].lvc))
		{
			(yyvsp[-1].raw)->lvc = *((yyvsp[-3].lvc));
			free((yyvsp[-3].lvc));
		}

		if(!(yyvsp[-1].raw)->lvc.language)
			(yyvsp[-1].raw)->lvc.language = currentlanguage;

		(yyval.raw) = (yyvsp[-1].raw);
		}
#line 4274 "tools/wrc/parser.tab.c"
    break;

  case 227: /* raw_elements: tRAWDATA  */
#line 1753 "tools/wrc/parser.y"
                                        { (yyval.raw) = (yyvsp[0].raw); }
#line 4280 "tools/wrc/parser.tab.c"
    break;

  case 228: /* raw_elements: tNUMBER  */
#line 1754 "tools/wrc/parser.y"
                                        { (yyval.raw) = int2raw_data((yyvsp[0].num)); }
#line 4286 "tools/wrc/parser.tab.c"
    break;

  case 229: /* raw_elements: '-' tNUMBER  */
#line 1755 "tools/wrc/parser.y"
                                        { (yyval.raw) = int2raw_data(-((yyvsp[0].num))); }
#line 4292 "tools/wrc/parser.tab.c"
    break;

  case 230: /* raw_elements: tLNUMBER  */
#line 1756 "tools/wrc/parser.y"
                                        { (yyval.raw) = long2raw_data((yyvsp[0].num)); }
#line 4298 "tools/wrc/parser.tab.c"
    break;

  case 231: /* raw_elements: '-' tLNUMBER  */
#line 1757 "tools/wrc/parser.y"
                                        { (yyval.raw) = long2raw_data(-((yyvsp[0].num))); }
#line 4304 "tools/wrc/parser.tab.c"
    break;

  case 232: /* raw_elements: tSTRING  */
#line 1758 "tools/wrc/parser.y"
                                        { (yyval.raw) = str2raw_data((yyvsp[0].str)); }
#line 4310 "tools/wrc/parser.tab.c"
    break;

  case 233: /* raw_elements: raw_elements opt_comma tRAWDATA  */
#line 1759 "tools/wrc/parser.y"
                                          { (yyval.raw) = merge_raw_data((yyvsp[-2].raw), (yyvsp[0].raw)); free((yyvsp[0].raw)->data); free((yyvsp[0].raw)); }
#line 4316 "tools/wrc/parser.tab.c"
    break;

  case 234: /* raw_elements: raw_elements opt_comma tNUMBER  */
#line 1760 "tools/wrc/parser.y"
                                          { (yyval.raw) = merge_raw_data_int((yyvsp[-2].raw), (yyvsp[0].num)); }
#line 4322 "tools/wrc/parser.tab.c"
    break;

  case 235: /* raw_elements: raw_elements opt_comma '-' tNUMBER  */
#line 1761 "tools/wrc/parser.y"
                                              { (yyval.raw) = merge_raw_data_int((yyvsp[-3].raw), -((yyvsp[0].num))); }
#line 4328 "tools/wrc/parser.tab.c"
    break;

  case 236: /* raw_elements: raw_elements opt_comma tLNUMBER  */
#line 1762 "tools/wrc/parser.y"
                                          { (yyval.raw) = merge_raw_data_long((yyvsp[-2].raw), (yyvsp[0].num)); }
#line 4334 "tools/wrc/parser.tab.c"
    break;

  case 237: /* raw_elements: raw_elements opt_comma '-' tLNUMBER  */
#line 1763 "tools/wrc/parser.y"
                                              { (yyval.raw) = merge_raw_data_long((yyvsp[-3].raw), -((yyvsp[0].num))); }
#line 4340 "tools/wrc/parser.tab.c"
    break;

  case 238: /* raw_elements: raw_elements opt_comma tSTRING  */
#line 1764 "tools/wrc/parser.y"
                                          { (yyval.raw) = merge_raw_data_str((yyvsp[-2].raw), (yyvsp[0].str)); }
#line 4346 "tools/wrc/parser.tab.c"
    break;

  case 239: /* file_raw: filename  */
#line 1768 "tools/wrc/parser.y"
                        { (yyval.raw) = load_file((yyvsp[0].str),currentlanguage); }
#line 4352 "tools/wrc/parser.tab.c"
    break;

  case 240: /* file_raw: raw_data  */
#line 1769 "tools/wrc/parser.y"
                        { (yyval.raw) = (yyvsp[0].raw); }
#line 4358 "tools/wrc/parser.tab.c"
    break;

  case 241: /* e_expr: %empty  */
#line 1776 "tools/wrc/parser.y"
                        { (yyval.iptr) = 0; }
#line 4364 "tools/wrc/parser.tab.c"
    break;

  case 242: /* e_expr: expr  */
#line 1777 "tools/wrc/parser.y"
                        { (yyval.iptr) = new_int((yyvsp[0].num)); }
#line 4370 "tools/wrc/parser.tab.c"
    break;

  case 243: /* expr: xpr  */
#line 1781 "tools/wrc/parser.y"
                { (yyval.num) = ((yyvsp[0].num)); }
#line 4376 "tools/wrc/parser.tab.c"
    break;

  case 244: /* xpr: xpr '+' xpr  */
#line 1784 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) + ((yyvsp[0].num)); }
#line 4382 "tools/wrc/parser.tab.c"
    break;

  case 245: /* xpr: xpr '-' xpr  */
#line 1785 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) - ((yyvsp[0].num)); }
#line 4388 "tools/wrc/parser.tab.c"
    break;

  case 246: /* xpr: xpr '|' xpr  */
#line 1786 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) | ((yyvsp[0].num)); }
#line 4394 "tools/wrc/parser.tab.c"
    break;

  case 247: /* xpr: xpr '&' xpr  */
#line 1787 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) & ((yyvsp[0].num)); }
#line 4400 "tools/wrc/parser.tab.c"
    break;

  case 248: /* xpr: xpr '*' xpr  */
#line 1788 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) * ((yyvsp[0].num)); }
#line 4406 "tools/wrc/parser.tab.c"
    break;

  case 249: /* xpr: xpr '/' xpr  */
#line 1789 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) / ((yyvsp[0].num)); }
#line 4412 "tools/wrc/parser.tab.c"
    break;

  case 250: /* xpr: xpr '^' xpr  */
#line 1790 "tools/wrc/parser.y"
                        { (yyval.num) = ((yyvsp[-2].num)) ^ ((yyvsp[0].num)); }
#line 4418 "tools/wrc/parser.tab.c"
    break;

  case 251: /* xpr: '~' xpr  */
#line 1791 "tools/wrc/parser.y"
                        { (yyval.num) = ~((yyvsp[0].num)); }
#line 4424 "tools/wrc/parser.tab.c"
    break;

  case 252: /* xpr: '-' xpr  */
#line 1792 "tools/wrc/parser.y"
                                { (yyval.num) = -((yyvsp[0].num)); }
#line 4430 "tools/wrc/parser.tab.c"
    break;

  case 253: /* xpr: '+' xpr  */
#line 1793 "tools/wrc/parser.y"
                                { (yyval.num) = (yyvsp[0].num); }
#line 4436 "tools/wrc/parser.tab.c"
    break;

  case 254: /* xpr: '(' xpr ')'  */
#line 1794 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[-1].num); }
#line 4442 "tools/wrc/parser.tab.c"
    break;

  case 255: /* xpr: any_num  */
#line 1795 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 4448 "tools/wrc/parser.tab.c"
    break;

  case 256: /* xpr: tNOT any_num  */
#line 1796 "tools/wrc/parser.y"
                        { (yyval.num) = ~((yyvsp[0].num)); }
#line 4454 "tools/wrc/parser.tab.c"
    break;

  case 257: /* any_num: tNUMBER  */
#line 1799 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 4460 "tools/wrc/parser.tab.c"
    break;

  case 258: /* any_num: tLNUMBER  */
#line 1800 "tools/wrc/parser.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 4466 "tools/wrc/parser.tab.c"
    break;


#line 4470 "tools/wrc/parser.tab.c"

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
  yytoken = yychar == PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= PARSER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == PARSER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
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
  if (yychar != PARSER_EMPTY)
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

#line 1803 "tools/wrc/parser.y"

/* Dialog specific functions */
static dialog_t *dialog_style(style_t * st, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->style == NULL)
	{
		dlg->style = new_style(0,0);
	}

	if(dlg->gotstyle)
	{
		parser_warning("Style already defined, or-ing together\n");
	}
	else
	{
		dlg->style->or_mask = 0;
		dlg->style->and_mask = 0;
	}
	dlg->style->or_mask |= st->or_mask;
	dlg->style->and_mask |= st->and_mask;
	dlg->gotstyle = TRUE;
	free(st);
	return dlg;
}

static dialog_t *dialog_exstyle(style_t *st, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->exstyle == NULL)
	{
		dlg->exstyle = new_style(0,0);
	}

	if(dlg->gotexstyle)
	{
		parser_warning("ExStyle already defined, or-ing together\n");
	}
	else
	{
		dlg->exstyle->or_mask = 0;
		dlg->exstyle->and_mask = 0;
	}
	dlg->exstyle->or_mask |= st->or_mask;
	dlg->exstyle->and_mask |= st->and_mask;
	dlg->gotexstyle = TRUE;
	free(st);
	return dlg;
}

static dialog_t *dialog_caption(string_t *s, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->title)
		yyerror("Caption already defined");
	dlg->title = s;
	return dlg;
}

static dialog_t *dialog_font(font_id_t *f, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->font)
		yyerror("Font already defined");
	dlg->font = f;
	return dlg;
}

static dialog_t *dialog_class(name_id_t *n, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->dlgclass)
		yyerror("Class already defined");
	dlg->dlgclass = n;
	return dlg;
}

static dialog_t *dialog_menu(name_id_t *m, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->menu)
		yyerror("Menu already defined");
	dlg->menu = m;
	return dlg;
}

static dialog_t *dialog_language(language_t l, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->lvc.language)
		yyerror("Language already defined");
	dlg->lvc.language = l;
	return dlg;
}

static dialog_t *dialog_characteristics(characts_t c, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->lvc.characts)
		yyerror("Characteristics already defined");
	dlg->lvc.characts = c;
	return dlg;
}

static dialog_t *dialog_version(version_t v, dialog_t *dlg)
{
	assert(dlg != NULL);
	if(dlg->lvc.version)
		yyerror("Version already defined");
	dlg->lvc.version = v;
	return dlg;
}

/* Controls specific functions */
static control_t *ins_ctrl(int type, int special_style, control_t *ctrl, control_t *prev)
{
	/* Hm... this seems to be jammed in at all time... */
	int defaultstyle = WS_CHILD | WS_VISIBLE;

	assert(ctrl != NULL);
	ctrl->prev = prev;

	if(prev)
		prev->next = ctrl;

	/* Check for duplicate identifiers */
	while (prev)
	{
		if (ctrl->id != -1 && ctrl->id == prev->id)
                        parser_warning("Duplicate dialog control id %d\n", ctrl->id);
		prev = prev->prev;
	}

	if(type != -1)
	{
		ctrl->ctlclass = new_name_id();
		ctrl->ctlclass->type = name_ord;
		ctrl->ctlclass->name.i_name = type;
	}

	switch(type)
	{
	case CT_BUTTON:
		if(special_style != BS_GROUPBOX && special_style != BS_RADIOBUTTON)
			defaultstyle |= WS_TABSTOP;
		break;
	case CT_EDIT:
		defaultstyle |= WS_TABSTOP | WS_BORDER;
		break;
	case CT_LISTBOX:
		defaultstyle |= LBS_NOTIFY | WS_BORDER;
		break;
	case CT_COMBOBOX:
                if (!ctrl->gotstyle || !(ctrl->style->or_mask & (CBS_SIMPLE | CBS_DROPDOWN | CBS_DROPDOWNLIST)))
                    defaultstyle |= CBS_SIMPLE;
		break;
	case CT_STATIC:
		if(special_style == SS_CENTER || special_style == SS_LEFT || special_style == SS_RIGHT)
			defaultstyle |= WS_GROUP;
		break;
	}

	if(!ctrl->gotstyle)	/* Handle default style setting */
	{
		switch(type)
		{
		case CT_EDIT:
			defaultstyle |= ES_LEFT;
			break;
		case CT_LISTBOX:
			defaultstyle |= LBS_NOTIFY;
			break;
		case CT_COMBOBOX:
			defaultstyle |= CBS_SIMPLE | WS_TABSTOP;
			break;
		case CT_SCROLLBAR:
			defaultstyle |= SBS_HORZ;
			break;
		case CT_BUTTON:
			switch(special_style)
			{
			case BS_CHECKBOX:
			case BS_DEFPUSHBUTTON:
			case BS_PUSHBUTTON:
/*			case BS_PUSHBOX:	*/
			case BS_AUTORADIOBUTTON:
			case BS_AUTO3STATE:
			case BS_3STATE:
			case BS_AUTOCHECKBOX:
				defaultstyle |= WS_TABSTOP;
				break;
			default:
				parser_warning("Unknown default button control-style 0x%08x\n", special_style);
			case BS_GROUPBOX:
			case BS_RADIOBUTTON:
				break;
			}
			break;

		case CT_STATIC:
			switch(special_style)
			{
			case SS_LEFT:
			case SS_RIGHT:
			case SS_CENTER:
				defaultstyle |= WS_GROUP;
				break;
			case SS_ICON:	/* Special case */
				break;
			default:
				parser_warning("Unknown default static control-style 0x%08x\n", special_style);
				break;
			}
			break;
		case -1:	/* Generic control */
			goto byebye;

		default:
			yyerror("Internal error (report this): Got weird control type 0x%08x", type);
		}
	}

	/* The SS_ICON flag is always forced in for icon controls */
	if(type == CT_STATIC && special_style == SS_ICON)
		defaultstyle |= SS_ICON;

	if (!ctrl->gotstyle)
		ctrl->style = new_style(0,0);

	/* combine all styles */
	ctrl->style->or_mask = ctrl->style->or_mask | defaultstyle | special_style;
	ctrl->gotstyle = TRUE;
byebye:
	/* combine with NOT mask */
	if (ctrl->gotstyle)
	{
		ctrl->style->or_mask &= ~(ctrl->style->and_mask);
		ctrl->style->and_mask = 0;
	}
	if (ctrl->gotexstyle)
	{
		ctrl->exstyle->or_mask &= ~(ctrl->exstyle->and_mask);
		ctrl->exstyle->and_mask = 0;
	}
	return ctrl;
}

static int get_class_idW(const WCHAR *cc)
{
        static const WCHAR szBUTTON[]    = {'B','U','T','T','O','N',0};
        static const WCHAR szCOMBOBOX[]  = {'C','O','M','B','O','B','O','X',0};
        static const WCHAR szLISTBOX[]   = {'L','I','S','T','B','O','X',0};
        static const WCHAR szEDIT[]      = {'E','D','I','T',0};
        static const WCHAR szSTATIC[]    = {'S','T','A','T','I','C',0};
        static const WCHAR szSCROLLBAR[] = {'S','C','R','O','L','L','B','A','R',0};

        if(!compare_striW(szBUTTON, cc)) return CT_BUTTON;
        if(!compare_striW(szCOMBOBOX, cc)) return CT_COMBOBOX;
        if(!compare_striW(szLISTBOX, cc)) return CT_LISTBOX;
        if(!compare_striW(szEDIT, cc)) return CT_EDIT;
        if(!compare_striW(szSTATIC, cc)) return CT_STATIC;
        if(!compare_striW(szSCROLLBAR, cc)) return CT_SCROLLBAR;
        return -1;
}

static int get_class_idA(const char *cc)
{
        if(!compare_striA("BUTTON", cc)) return CT_BUTTON;
        if(!compare_striA("COMBOBOX", cc)) return CT_COMBOBOX;
        if(!compare_striA("LISTBOX", cc)) return CT_LISTBOX;
        if(!compare_striA("EDIT", cc)) return CT_EDIT;
        if(!compare_striA("STATIC", cc)) return CT_STATIC;
        if(!compare_striA("SCROLLBAR", cc)) return CT_SCROLLBAR;
        return -1;
}


static name_id_t *convert_ctlclass(name_id_t *cls)
{
	int iclass;

	if(cls->type == name_ord)
		return cls;
	assert(cls->type == name_str);
        if(cls->name.s_name->type == str_unicode)
                iclass = get_class_idW(cls->name.s_name->str.wstr);
        else
                iclass = get_class_idA(cls->name.s_name->str.cstr);

        if (iclass == -1)
		return cls;	/* No default, return user controlclass */

	free(cls->name.s_name->str.cstr);
	free(cls->name.s_name);
	cls->type = name_ord;
	cls->name.i_name = iclass;
	return cls;
}

/* Accelerator specific functions */
static event_t *add_event(int key, int id, int flags, event_t *prev)
{
	event_t *ev = new_event();

	if((flags & (WRC_AF_VIRTKEY | WRC_AF_ASCII)) == (WRC_AF_VIRTKEY | WRC_AF_ASCII))
		yyerror("Cannot use both ASCII and VIRTKEY");

	ev->key = key;
	ev->id = id;
	ev->flags = flags & ~WRC_AF_ASCII;
	ev->prev = prev;
	if(prev)
		prev->next = ev;
	return ev;
}

static event_t *add_string_event(string_t *key, int id, int flags, event_t *prev)
{
    event_t *ev = new_event();

    ev->str = key;
    ev->id = id;
    ev->flags = flags & ~WRC_AF_ASCII;
    ev->prev = prev;
    if(prev)
        prev->next = ev;
    return ev;
}

/* MenuEx specific functions */
static itemex_opt_t *new_itemex_opt(int id, int type, int state, int helpid)
{
	itemex_opt_t *opt = xmalloc(sizeof(itemex_opt_t));
	memset( opt, 0, sizeof(*opt) );
	opt->id = id;
	opt->type = type;
	opt->state = state;
	opt->helpid = helpid;
	return opt;
}

/* Raw data functions */
static raw_data_t *load_file(string_t *filename, language_t lang)
{
	FILE *fp = NULL;
	char *path, *name;
	raw_data_t *rd;

	if (filename->type == str_unicode)
		name = convert_string_utf8( filename, 0 );
        else
		name = xstrdup( filename->str.cstr );
	if (!(path = wpp_find_include(name, input_name)))
		yyerror("Cannot open file %s", name);
	if (!(fp = fopen( path, "rb" )))
		yyerror("Cannot open file %s", name);
	free( path );
	rd = new_raw_data();
	fseek(fp, 0, SEEK_END);
	rd->size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (rd->size)
	{
		rd->data = xmalloc(rd->size);
		fread(rd->data, rd->size, 1, fp);
	}
	else rd->data = NULL;
	fclose(fp);
	rd->lvc.language = lang;
	free(name);
	return rd;
}

static raw_data_t *int2raw_data(int i)
{
	raw_data_t *rd;

	if( ( i >= 0 && (int)((unsigned short)i) != i) ||
            ( i < 0  && (int)((short)i) != i) )
		parser_warning("Integer constant out of 16bit range (%d), truncated to %d\n", i, (short)i);

	rd = new_raw_data();
	rd->size = sizeof(short);
	rd->data = xmalloc(rd->size);
        rd->data[0] = i;
        rd->data[1] = i >> 8;
	return rd;
}

static raw_data_t *long2raw_data(int i)
{
	raw_data_t *rd;
	rd = new_raw_data();
	rd->size = sizeof(int);
	rd->data = xmalloc(rd->size);
        rd->data[0] = i;
        rd->data[1] = i >> 8;
        rd->data[2] = i >> 16;
        rd->data[3] = i >> 24;
	return rd;
}

static raw_data_t *str2raw_data(string_t *str)
{
	raw_data_t *rd;
	rd = new_raw_data();
	rd->size = str->size * (str->type == str_char ? 1 : 2);
	rd->data = xmalloc(rd->size);
	switch (str->type)
	{
	case str_char:
		memcpy(rd->data, str->str.cstr, rd->size);
		break;
	case str_unicode:
            {
		int i;
		for(i = 0; i < str->size; i++)
		{
			rd->data[2*i + 0] = str->str.wstr[i];
			rd->data[2*i + 1] = str->str.wstr[i] >> 8;
		}
            }
	}
	return rd;
}

static raw_data_t *merge_raw_data(raw_data_t *r1, raw_data_t *r2)
{
	r1->data = xrealloc(r1->data, r1->size + r2->size);
	memcpy(r1->data + r1->size, r2->data, r2->size);
	r1->size += r2->size;
	return r1;
}

static raw_data_t *merge_raw_data_int(raw_data_t *r1, int i)
{
	raw_data_t *t = int2raw_data(i);
	merge_raw_data(r1, t);
	free(t->data);
	free(t);
	return r1;
}

static raw_data_t *merge_raw_data_long(raw_data_t *r1, int i)
{
	raw_data_t *t = long2raw_data(i);
	merge_raw_data(r1, t);
	free(t->data);
	free(t);
	return r1;
}

static raw_data_t *merge_raw_data_str(raw_data_t *r1, string_t *str)
{
	raw_data_t *t = str2raw_data(str);
	merge_raw_data(r1, t);
	free(t->data);
	free(t);
	return r1;
}

/* Function the go back in a list to get the head */
static menu_item_t *get_item_head(menu_item_t *p)
{
	if(!p)
		return NULL;
	while(p->prev)
		p = p->prev;
	return p;
}

static resource_t *get_resource_head(resource_t *p)
{
	if(!p)
		return NULL;
	while(p->prev)
		p = p->prev;
	return p;
}

static ver_block_t *get_ver_block_head(ver_block_t *p)
{
	if(!p)
		return NULL;
	while(p->prev)
		p = p->prev;
	return p;
}

static ver_value_t *get_ver_value_head(ver_value_t *p)
{
	if(!p)
		return NULL;
	while(p->prev)
		p = p->prev;
	return p;
}

static control_t *get_control_head(control_t *p)
{
	if(!p)
		return NULL;
	while(p->prev)
		p = p->prev;
	return p;
}

static event_t *get_event_head(event_t *p)
{
	if(!p)
		return NULL;
	while(p->prev)
		p = p->prev;
	return p;
}

/* Find a stringtable with given language */
static stringtable_t *find_stringtable(lvc_t *lvc)
{
	stringtable_t *stt;

	assert(lvc != NULL);

	if(!lvc->language)
		lvc->language = currentlanguage;

	for(stt = sttres; stt; stt = stt->next)
	{
		if(stt->lvc.language == lvc->language)
		{
			/* Found a table with the same language */
			/* The version and characteristics are now handled
			 * in the generation of the individual stringtables.
			 * This enables localized analysis.
			if((stt->lvc.version && lvc->version && *(stt->lvc.version) != *(lvc->version))
			|| (!stt->lvc.version && lvc->version)
			|| (stt->lvc.version && !lvc->version))
				parser_warning("Stringtable's versions are not the same, using first definition\n");

			if((stt->lvc.characts && lvc->characts && *(stt->lvc.characts) != *(lvc->characts))
			|| (!stt->lvc.characts && lvc->characts)
			|| (stt->lvc.characts && !lvc->characts))
				parser_warning("Stringtable's characteristics are not the same, using first definition\n");
			*/
			return stt;
		}
	}
	return NULL;
}

/* qsort sorting function for string table entries */
#define STE(p)	((const stt_entry_t *)(p))
static int sort_stt_entry(const void *e1, const void *e2)
{
	return STE(e1)->id - STE(e2)->id;
}
#undef STE

static resource_t *build_stt_resources(stringtable_t *stthead)
{
	stringtable_t *stt;
	stringtable_t *newstt;
	resource_t *rsc;
	resource_t *rsclist = NULL;
	resource_t *rsctail = NULL;
	int i;
	int j;
	unsigned int andsum;
	unsigned int orsum;
	characts_t characts;
	version_t version;

	if(!stthead)
		return NULL;

	/* For all languages defined */
	for(stt = stthead; stt; stt = stt->next)
	{
		assert(stt->nentries > 0);

		/* Sort the entries */
		if(stt->nentries > 1)
			qsort(stt->entries, stt->nentries, sizeof(stt->entries[0]), sort_stt_entry);

		for(i = 0; i < stt->nentries; )
		{
			newstt = new_stringtable(&stt->lvc);
			newstt->entries = xmalloc(16 * sizeof(stt_entry_t));
			memset( newstt->entries, 0, 16 * sizeof(stt_entry_t) );
			newstt->nentries = 16;
			newstt->idbase = stt->entries[i].id & ~0xf;
			for(j = 0; j < 16 && i < stt->nentries; j++)
			{
				if(stt->entries[i].id - newstt->idbase == j)
				{
					newstt->entries[j] = stt->entries[i];
					i++;
				}
			}
			andsum = ~0;
			orsum = 0;
			characts = 0;
			version = 0;
			/* Check individual memory options and get
			 * the first characteristics/version
			 */
			for(j = 0; j < 16; j++)
			{
				if(!newstt->entries[j].str)
					continue;
				andsum &= newstt->entries[j].memopt;
				orsum |= newstt->entries[j].memopt;
				if(!characts)
					characts = newstt->entries[j].characts;
				if(!version)
					version = newstt->entries[j].version;
			}
			if(andsum != orsum)
			{
				warning("Stringtable's memory options are not equal (idbase: %d)\n", newstt->idbase);
			}
			/* Check version and characteristics */
			for(j = 0; j < 16; j++)
			{
				if(characts
				&& newstt->entries[j].characts
				&& newstt->entries[j].characts != characts)
					warning("Stringtable's characteristics are not the same (idbase: %d)\n", newstt->idbase);
				if(version
				&& newstt->entries[j].version
				&& newstt->entries[j].version != version)
					warning("Stringtable's versions are not the same (idbase: %d)\n", newstt->idbase);
			}
			rsc = new_resource(res_stt, newstt, newstt->memopt, newstt->lvc.language);
			rsc->name = new_name_id();
			rsc->name->type = name_ord;
			rsc->name->name.i_name = (newstt->idbase >> 4) + 1;
			rsc->memopt = andsum; /* Set to least common denominator */
			newstt->memopt = andsum;
			newstt->lvc.characts = characts;
			newstt->lvc.version = version;
			if(!rsclist)
			{
				rsclist = rsc;
				rsctail = rsc;
			}
			else
			{
				rsctail->next = rsc;
				rsc->prev = rsctail;
				rsctail = rsc;
			}
		}
	}
	return rsclist;
}


static toolbar_item_t *ins_tlbr_button(toolbar_item_t *prev, toolbar_item_t *idrec)
{
	idrec->prev = prev;
	if(prev)
		prev->next = idrec;

	return idrec;
}

static toolbar_item_t *get_tlbr_buttons_head(toolbar_item_t *p, int *nitems)
{
	if(!p)
	{
		*nitems = 0;
		return NULL;
	}

	*nitems = 1;

	while(p->prev)
	{
		(*nitems)++;
		p = p->prev;
	}

	return p;
}

static string_t *make_filename(string_t *str)
{
    int i;

    if(str->type == str_char)
    {
	char *dst = str->str.cstr;

	/* Remove escaped backslash and convert to forward */
        for (i = 0; i < str->size; i++)
        {
            if (str->str.cstr[i] == '\\')
            {
                if (i < str->size - 1 && str->str.cstr[i + 1] == '\\') i++;
                *dst++ = '/';
            }
            else *dst++ = str->str.cstr[i];
        }
        *dst = 0;
        str->size = dst - str->str.cstr;
    }
    else
    {
	WCHAR *dst = str->str.wstr;

	/* Remove escaped backslash and convert to forward */
        for (i = 0; i < str->size; i++)
        {
            if (str->str.wstr[i] == '\\')
            {
                if (i < str->size - 1 && str->str.wstr[i + 1] == '\\') i++;
                *dst++ = '/';
            }
            else *dst++ = str->str.wstr[i];
        }
        *dst = 0;
        str->size = dst - str->str.wstr;
    }
    return str;
}

/*
 * Process all resources to extract fonts and build
 * a fontdir resource.
 *
 * Note: MS' resource compiler (build 1472) does not
 * handle font resources with different languages.
 * The fontdir is generated in the last active language
 * and font identifiers must be unique across the entire
 * source.
 * This is not logical considering the localization
 * constraints of all other resource types. MS has,
 * most probably, never testet localized fonts. However,
 * using fontresources is rare, so it might not occur
 * in normal applications.
 * Wine does require better localization because a lot
 * of languages are coded into the same executable.
 * Therefore, I will generate fontdirs for *each*
 * localized set of fonts.
 */
static resource_t *build_fontdir(resource_t **fnt, int nfnt)
{
	static int once = 0;
	if(!once)
	{
		warning("Need to parse fonts, not yet implemented (fnt: %p, nfnt: %d)\n", fnt, nfnt);
		once++;
	}
	return NULL;
}

static resource_t *build_fontdirs(resource_t *tail)
{
	resource_t *rsc;
	resource_t *lst = NULL;
	resource_t **fnt = NULL;	/* List of all fonts */
	int nfnt = 0;
	resource_t **fnd = NULL;	/* List of all fontdirs */
	int nfnd = 0;
	resource_t **lanfnt = NULL;
	int nlanfnt = 0;
	int i;
	name_id_t nid;
	string_t str;
	int fntleft;

	nid.type = name_str;
	nid.name.s_name = &str;
	str.type = str_char;
	str.str.cstr = xstrdup("FONTDIR");
	str.size = 7;

	/* Extract all fonts and fontdirs */
	for(rsc = tail; rsc; rsc = rsc->prev)
	{
		if(rsc->type == res_fnt)
		{
			nfnt++;
			fnt = xrealloc(fnt, nfnt * sizeof(*fnt));
			fnt[nfnt-1] = rsc;
		}
		else if(rsc->type == res_fntdir)
		{
			nfnd++;
			fnd = xrealloc(fnd, nfnd * sizeof(*fnd));
			fnd[nfnd-1] = rsc;
		}
	}

	/* Verify the name of the present fontdirs */
	for(i = 0; i < nfnd; i++)
	{
		if(compare_name_id(&nid, fnd[i]->name))
		{
			warning("User supplied FONTDIR entry has an invalid name '%s', ignored\n",
				get_nameid_str(fnd[i]->name));
			fnd[i] = NULL;
		}
	}

	/* Sanity check */
	if(nfnt == 0)
	{
		if(nfnd != 0)
			warning("Found %d FONTDIR entries without any fonts present\n", nfnd);
		goto clean;
	}

	/* Copy space */
	lanfnt = xmalloc(nfnt * sizeof(*lanfnt));
	memset( lanfnt, 0, nfnt * sizeof(*lanfnt));

	/* Get all fonts covered by fontdirs */
	for(i = 0; i < nfnd; i++)
	{
		int j;

		if(!fnd[i])
			continue;
		for(j = 0; j < nfnt; j++)
		{
			if(!fnt[j])
				continue;
			if(fnt[j]->lan == fnd[i]->lan)
			{
				lanfnt[nlanfnt] = fnt[j];
				nlanfnt++;
				fnt[j] = NULL;
			}
		}
	}

	/* We now have fonts left where we need to make a fontdir resource */
	for(i = fntleft = 0; i < nfnt; i++)
	{
		if(fnt[i])
			fntleft++;
	}
	while(fntleft)
	{
		/* Get fonts of same language in lanfnt[] */
		for(i = nlanfnt = 0; i < nfnt; i++)
		{
			if(fnt[i])
			{
				if(!nlanfnt)
				{
			addlanfnt:
					lanfnt[nlanfnt] = fnt[i];
					nlanfnt++;
					fnt[i] = NULL;
					fntleft--;
				}
				else if(fnt[i]->lan == lanfnt[0]->lan)
					goto addlanfnt;
			}
		}
		/* and build a fontdir */
		rsc = build_fontdir(lanfnt, nlanfnt);
		if(rsc)
		{
			if(lst)
			{
				lst->next = rsc;
				rsc->prev = lst;
			}
			lst = rsc;
		}
	}

	free(lanfnt);
clean:
	free(fnt);
	free(fnd);
	free(str.str.cstr);
	return lst;
}

/*
 * This gets invoked to determine whether the next resource
 * is to be of a standard-type (e.g. bitmaps etc.), or should
 * be a user-type resource. This function is required because
 * there is the _possibility_ of a lookahead token in the
 * parser, which is generated from the "expr" state in the
 * "nameid" parsing.
 *
 * The general resource format is:
 * <identifier> <type> <flags> <resourcebody>
 *
 * The <identifier> can either be tIDENT or "expr". The latter
 * will always generate a lookahead, which is the <type> of the
 * resource to parse. Otherwise, we need to get a new token from
 * the scanner to determine the next step.
 *
 * The problem arrises when <type> is numerical. This case should
 * map onto default resource-types and be parsed as such instead
 * of being mapped onto user-type resources.
 *
 * The trick lies in the fact that yacc (bison) doesn't care about
 * intermediate changes of the lookahead while reducing a rule. We
 * simply replace the lookahead with a token that will result in
 * a shift to the appropriate rule for the specific resource-type.
 */
static int rsrcid_to_token(int lookahead)
{
	int token;

	/* Get a token if we don't have one yet */
	if(lookahead == YYEMPTY)
		lookahead = yylex();

	/* Only numbers are possibly interesting */
	switch(lookahead)
	{
	case tNUMBER:
	case tLNUMBER:
		break;
	default:
		return lookahead;
	}

	token = lookahead;

	switch(yylval.num)
	{
	case WRC_RT_CURSOR:
		token = tCURSOR;
		break;
	case WRC_RT_ICON:
		token = tICON;
		break;
	case WRC_RT_BITMAP:
		token = tBITMAP;
		break;
	case WRC_RT_FONT:
		token = tFONT;
		break;
	case WRC_RT_FONTDIR:
		token = tFONTDIR;
		break;
	case WRC_RT_RCDATA:
		token = tRCDATA;
		break;
	case WRC_RT_MESSAGETABLE:
		token = tMESSAGETABLE;
		break;
	case WRC_RT_DLGINIT:
		token = tDLGINIT;
		break;
	case WRC_RT_ACCELERATOR:
		token = tACCELERATORS;
		break;
	case WRC_RT_MENU:
		token = tMENU;
		break;
	case WRC_RT_DIALOG:
		token = tDIALOG;
		break;
	case WRC_RT_VERSION:
		token = tVERSIONINFO;
		break;
	case WRC_RT_TOOLBAR:
		token = tTOOLBAR;
		break;
	case WRC_RT_HTML:
		token = tHTML;
		break;

	case WRC_RT_STRING:
		break;

	case WRC_RT_ANICURSOR:
	case WRC_RT_ANIICON:
	case WRC_RT_GROUP_CURSOR:
	case WRC_RT_GROUP_ICON:
		parser_warning("Usertype uses reserved type ID %d, which is auto-generated\n", yylval.num);
		return lookahead;

	case WRC_RT_DLGINCLUDE:
	case WRC_RT_PLUGPLAY:
	case WRC_RT_VXD:
		parser_warning("Usertype uses reserved type ID %d, which is not supported by wrc yet\n", yylval.num);
	default:
		return lookahead;
	}

	return token;
}
