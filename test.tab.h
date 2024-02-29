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

#ifndef YY_YY_TEST_TAB_H_INCLUDED
# define YY_YY_TEST_TAB_H_INCLUDED
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
    AWAIT = 266,                   /* AWAIT  */
    ASYNC = 267,                   /* ASYNC  */
    TRUE = 268,                    /* TRUE  */
    FALSE = 269,                   /* FALSE  */
    NONE = 270,                    /* NONE  */
    IMPORT = 271,                  /* IMPORT  */
    PASS = 272,                    /* PASS  */
    BREAK = 273,                   /* BREAK  */
    EXCEPT = 274,                  /* EXCEPT  */
    RAISE = 275,                   /* RAISE  */
    CLASS = 276,                   /* CLASS  */
    FINALLY = 277,                 /* FINALLY  */
    RETURN = 278,                  /* RETURN  */
    CONTINUE = 279,                /* CONTINUE  */
    FOR = 280,                     /* FOR  */
    LAMBDA = 281,                  /* LAMBDA  */
    TRY = 282,                     /* TRY  */
    AS = 283,                      /* AS  */
    DEF = 284,                     /* DEF  */
    NONLOCAL = 285,                /* NONLOCAL  */
    WHILE = 286,                   /* WHILE  */
    ASSERT = 287,                  /* ASSERT  */
    DEL = 288,                     /* DEL  */
    GLOBAL = 289,                  /* GLOBAL  */
    WITH = 290,                    /* WITH  */
    INTEGER = 291,                 /* INTEGER  */
    FLOAT = 292,                   /* FLOAT  */
    STRING = 293,                  /* STRING  */
    POW = 294,                     /* POW  */
    FLOOR_DIV = 295,               /* FLOOR_DIV  */
    DIV = 296,                     /* DIV  */
    MUL = 297,                     /* MUL  */
    ADD = 298,                     /* ADD  */
    SUB = 299,                     /* SUB  */
    MOD = 300,                     /* MOD  */
    EQUAL = 301,                   /* EQUAL  */
    SHIFT_LEFT = 302,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 303,             /* SHIFT_RIGHT  */
    BITWISE_AND = 304,             /* BITWISE_AND  */
    BITWISE_XOR = 305,             /* BITWISE_XOR  */
    BITWISE_OR = 306,              /* BITWISE_OR  */
    TILDE = 307,                   /* TILDE  */
    AT = 308,                      /* AT  */
    COMMA = 309,                   /* COMMA  */
    WAL_OP = 310,                  /* WAL_OP  */
    COLON = 311,                   /* COLON  */
    SEMI_COLON = 312,              /* SEMI_COLON  */
    SMALL_OPEN = 313,              /* SMALL_OPEN  */
    SMALL_CLOSE = 314,             /* SMALL_CLOSE  */
    BOX_OPEN = 315,                /* BOX_OPEN  */
    BOX_CLOSE = 316,               /* BOX_CLOSE  */
    CURLY_OPEN = 317,              /* CURLY_OPEN  */
    CURLY_CLOSE = 318,             /* CURLY_CLOSE  */
    DOT = 319,                     /* DOT  */
    EQ = 320,                      /* EQ  */
    NE = 321,                      /* NE  */
    LT = 322,                      /* LT  */
    GT = 323,                      /* GT  */
    LE = 324,                      /* LE  */
    GE = 325,                      /* GE  */
    IN = 326,                      /* IN  */
    IS = 327,                      /* IS  */
    IF = 328,                      /* IF  */
    ELSE = 329,                    /* ELSE  */
    AND = 330,                     /* AND  */
    OR = 331,                      /* OR  */
    NOT = 332,                     /* NOT  */
    TYPE_COMMENT = 333,            /* TYPE_COMMENT  */
    ADD_ASSIGN = 334,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 335,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 336,              /* MUL_ASSIGN  */
    AT_ASSIGN = 337,               /* AT_ASSIGN  */
    DIV_ASSIGN = 338,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 339,              /* MOD_ASSIGN  */
    AND_ASSIGN = 340,              /* AND_ASSIGN  */
    OR_ASSIGN = 341,               /* OR_ASSIGN  */
    XOR_ASSIGN = 342,              /* XOR_ASSIGN  */
    LEFT_SHIFT_ASSIGN = 343,       /* LEFT_SHIFT_ASSIGN  */
    RIGHT_SHIFT_ASSIGN = 344,      /* RIGHT_SHIFT_ASSIGN  */
    POW_ASSIGN = 345,              /* POW_ASSIGN  */
    FLOOR_DIV_ASSIGN = 346         /* FLOOR_DIV_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "test.y"

    int num;

#line 159 "test.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TEST_TAB_H_INCLUDED  */
