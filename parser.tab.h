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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KEYWORD = 258,                 /* KEYWORD  */
    NEWLINE = 259,                 /* NEWLINE  */
    INDENT = 260,                  /* INDENT  */
    DEDENT = 261,                  /* DEDENT  */
    NAME = 262,                    /* NAME  */
    YIELD = 263,                   /* YIELD  */
    FROM = 264,                    /* FROM  */
    ELIF = 265,                    /* ELIF  */
    POW = 266,                     /* POW  */
    FLOOR_DIV = 267,               /* FLOOR_DIV  */
    DIV = 268,                     /* DIV  */
    MUL = 269,                     /* MUL  */
    ADD = 270,                     /* ADD  */
    SUB = 271,                     /* SUB  */
    MOD = 272,                     /* MOD  */
    EQUAL = 273,                   /* EQUAL  */
    SHIFT_LEFT = 274,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 275,             /* SHIFT_RIGHT  */
    BITWISE_AND = 276,             /* BITWISE_AND  */
    BITWISE_XOR = 277,             /* BITWISE_XOR  */
    BITWISE_OR = 278,              /* BITWISE_OR  */
    TILDE = 279,                   /* TILDE  */
    AT = 280,                      /* AT  */
    COMMA = 281,                   /* COMMA  */
    WAL_OP = 282,                  /* WAL_OP  */
    COLON = 283,                   /* COLON  */
    SEMI_COLON = 284,              /* SEMI_COLON  */
    EQ = 285,                      /* EQ  */
    NE = 286,                      /* NE  */
    LT = 287,                      /* LT  */
    GT = 288,                      /* GT  */
    LE = 289,                      /* LE  */
    GE = 290,                      /* GE  */
    IN = 291,                      /* IN  */
    IS = 292,                      /* IS  */
    IF = 293,                      /* IF  */
    ELSE = 294,                    /* ELSE  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    NOT = 297                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    int num;

#line 110 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
