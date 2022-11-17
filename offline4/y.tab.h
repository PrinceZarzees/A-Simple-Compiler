/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINTLN = 258,
    ADDOP = 259,
    MULOP = 260,
    DECOP = 261,
    INCOP = 262,
    RELOP = 263,
    ASSIGNOP = 264,
    LOGICOP = 265,
    NOT = 266,
    LPAREN = 267,
    RPAREN = 268,
    LCURL = 269,
    RCURL = 270,
    LTHIRD = 271,
    RTHIRD = 272,
    COMMA = 273,
    SEMICOLON = 274,
    IF = 275,
    FOR = 276,
    DO = 277,
    INT = 278,
    FLOAT = 279,
    VOID = 280,
    SWITCH = 281,
    DEFAULT = 282,
    ELSE = 283,
    WHILE = 284,
    BREAK = 285,
    CHAR = 286,
    DOUBLE = 287,
    RETURN = 288,
    CASE = 289,
    CONTINUE = 290,
    CONST_INT = 291,
    CONST_FLOAT = 292,
    CONST_CHAR = 293,
    ID = 294,
    STRING = 295,
    LOWER_THAN_ELSE = 296
  };
#endif
/* Tokens.  */
#define PRINTLN 258
#define ADDOP 259
#define MULOP 260
#define DECOP 261
#define INCOP 262
#define RELOP 263
#define ASSIGNOP 264
#define LOGICOP 265
#define NOT 266
#define LPAREN 267
#define RPAREN 268
#define LCURL 269
#define RCURL 270
#define LTHIRD 271
#define RTHIRD 272
#define COMMA 273
#define SEMICOLON 274
#define IF 275
#define FOR 276
#define DO 277
#define INT 278
#define FLOAT 279
#define VOID 280
#define SWITCH 281
#define DEFAULT 282
#define ELSE 283
#define WHILE 284
#define BREAK 285
#define CHAR 286
#define DOUBLE 287
#define RETURN 288
#define CASE 289
#define CONTINUE 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define CONST_CHAR 293
#define ID 294
#define STRING 295
#define LOWER_THAN_ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "1805009.y" /* yacc.c:1909  */

    SymbolInfo* symbolinfo;
    complex_obj *obj;

#line 141 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
