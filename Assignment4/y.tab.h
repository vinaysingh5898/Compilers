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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR = 258,
    SHORT = 259,
    INT = 260,
    LONG = 261,
    SIGNED = 262,
    UNSIGNED = 263,
    FLOAT = 264,
    DOUBLE = 265,
    VOID = 266,
    BOOL = 267,
    BREAK = 268,
    CASE = 269,
    CONTINUE = 270,
    DEFAULT = 271,
    DO = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    GOTO = 276,
    WHILE = 277,
    SWITCH = 278,
    RETURN = 279,
    MATRIX = 280,
    PLUS_ASSIGN = 281,
    MINUS_ASSIGN = 282,
    RIGHT_ASSIGN = 283,
    LEFT_ASSIGN = 284,
    MULTIPLY_ASSIGN = 285,
    PUNCTUATORS = 286,
    STRING_LITERAL = 287,
    IDENTIFIER = 288,
    INT_CONSTANT = 289,
    FLOAT_CONSTANT = 290,
    CHAR_CONSTANT = 291,
    MODULUS_ASSIGN = 292,
    AND_ASSIGN = 293,
    DIVIDE_ASSIGN = 294,
    XOR_ASSIGN = 295,
    POINTER_OP = 296,
    AND_OP = 297,
    OR_ASSIGN = 298,
    RIGHT_OP = 299,
    LEFT_OP = 300,
    INCREMENT_OP = 301,
    DECREMENT_OP = 302,
    EQ_OP = 303,
    NE_OP = 304,
    ZERO_CONSTANT = 305,
    POINTCOL = 306,
    OR_OP = 307,
    LE_OP = 308,
    GE_OP = 309
  };
#endif
/* Tokens.  */
#define CHAR 258
#define SHORT 259
#define INT 260
#define LONG 261
#define SIGNED 262
#define UNSIGNED 263
#define FLOAT 264
#define DOUBLE 265
#define VOID 266
#define BOOL 267
#define BREAK 268
#define CASE 269
#define CONTINUE 270
#define DEFAULT 271
#define DO 272
#define IF 273
#define ELSE 274
#define FOR 275
#define GOTO 276
#define WHILE 277
#define SWITCH 278
#define RETURN 279
#define MATRIX 280
#define PLUS_ASSIGN 281
#define MINUS_ASSIGN 282
#define RIGHT_ASSIGN 283
#define LEFT_ASSIGN 284
#define MULTIPLY_ASSIGN 285
#define PUNCTUATORS 286
#define STRING_LITERAL 287
#define IDENTIFIER 288
#define INT_CONSTANT 289
#define FLOAT_CONSTANT 290
#define CHAR_CONSTANT 291
#define MODULUS_ASSIGN 292
#define AND_ASSIGN 293
#define DIVIDE_ASSIGN 294
#define XOR_ASSIGN 295
#define POINTER_OP 296
#define AND_OP 297
#define OR_ASSIGN 298
#define RIGHT_OP 299
#define LEFT_OP 300
#define INCREMENT_OP 301
#define DECREMENT_OP 302
#define EQ_OP 303
#define NE_OP 304
#define ZERO_CONSTANT 305
#define POINTCOL 306
#define OR_OP 307
#define LE_OP 308
#define GE_OP 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "ass4_15CS30038.y" /* yacc.c:1909  */

	int intvalue;
	int instr;
	sym* symt;
	expr* expAttr;
	char* strval;
	float floatvalue;
	lint* nl;
	statement* statm;
	unary* A;
	char uoptr;
	sym_type* stp;
		

#line 177 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
