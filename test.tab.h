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
    NAME = 260,                    /* NAME  */
    YIELD = 261,                   /* YIELD  */
    FROM = 262,                    /* FROM  */
    ELIF = 263,                    /* ELIF  */
    AWAIT = 264,                   /* AWAIT  */
    ASYNC = 265,                   /* ASYNC  */
    TRUE = 266,                    /* TRUE  */
    FALSE = 267,                   /* FALSE  */
    NONE = 268,                    /* NONE  */
    IMPORT = 269,                  /* IMPORT  */
    PASS = 270,                    /* PASS  */
    BREAK = 271,                   /* BREAK  */
    EXCEPT = 272,                  /* EXCEPT  */
    RAISE = 273,                   /* RAISE  */
    CLASS = 274,                   /* CLASS  */
    FINALLY = 275,                 /* FINALLY  */
    RETURN = 276,                  /* RETURN  */
    CONTINUE = 277,                /* CONTINUE  */
    FOR = 278,                     /* FOR  */
    LAMBDA = 279,                  /* LAMBDA  */
    TRY = 280,                     /* TRY  */
    AS = 281,                      /* AS  */
    DEF = 282,                     /* DEF  */
    NONLOCAL = 283,                /* NONLOCAL  */
    WHILE = 284,                   /* WHILE  */
    ASSERT = 285,                  /* ASSERT  */
    DEL = 286,                     /* DEL  */
    GLOBAL = 287,                  /* GLOBAL  */
    WITH = 288,                    /* WITH  */
    INTEGER = 289,                 /* INTEGER  */
    FLOAT = 290,                   /* FLOAT  */
    STRING = 291,                  /* STRING  */
    POW = 292,                     /* POW  */
    FLOOR_DIV = 293,               /* FLOOR_DIV  */
    DIV = 294,                     /* DIV  */
    MUL = 295,                     /* MUL  */
    ADD = 296,                     /* ADD  */
    SUB = 297,                     /* SUB  */
    MOD = 298,                     /* MOD  */
    EQUAL = 299,                   /* EQUAL  */
    SHIFT_LEFT = 300,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 301,             /* SHIFT_RIGHT  */
    BITWISE_AND = 302,             /* BITWISE_AND  */
    BITWISE_XOR = 303,             /* BITWISE_XOR  */
    BITWISE_OR = 304,              /* BITWISE_OR  */
    TILDE = 305,                   /* TILDE  */
    AT = 306,                      /* AT  */
    COMMA = 307,                   /* COMMA  */
    WAL_OP = 308,                  /* WAL_OP  */
    COLON = 309,                   /* COLON  */
    SEMI_COLON = 310,              /* SEMI_COLON  */
    SMALL_OPEN = 311,              /* SMALL_OPEN  */
    SMALL_CLOSE = 312,             /* SMALL_CLOSE  */
    BOX_OPEN = 313,                /* BOX_OPEN  */
    BOX_CLOSE = 314,               /* BOX_CLOSE  */
    CURLY_OPEN = 315,              /* CURLY_OPEN  */
    CURLY_CLOSE = 316,             /* CURLY_CLOSE  */
    DOT = 317,                     /* DOT  */
    ARROW = 318,                   /* ARROW  */
    DOUBLE_EQUAL = 319,            /* DOUBLE_EQUAL  */
    NE = 320,                      /* NE  */
    LT = 321,                      /* LT  */
    GT = 322,                      /* GT  */
    LE = 323,                      /* LE  */
    GE = 324,                      /* GE  */
    IN = 325,                      /* IN  */
    IS = 326,                      /* IS  */
    IF = 327,                      /* IF  */
    ELSE = 328,                    /* ELSE  */
    AND = 329,                     /* AND  */
    OR = 330,                      /* OR  */
    NOT = 331,                     /* NOT  */
    TYPE_HINT = 332,               /* TYPE_HINT  */
    FUNC_TYPE_HINT = 333,          /* FUNC_TYPE_HINT  */
    ADD_EQUAL = 334,               /* ADD_EQUAL  */
    SUB_EQUAL = 335,               /* SUB_EQUAL  */
    MUL_EQUAL = 336,               /* MUL_EQUAL  */
    AT_EQUAL = 337,                /* AT_EQUAL  */
    DIV_EQUAL = 338,               /* DIV_EQUAL  */
    MOD_EQUAL = 339,               /* MOD_EQUAL  */
    BITWISE_AND_EQUAL = 340,       /* BITWISE_AND_EQUAL  */
    BITWISE_OR_EQUAL = 341,        /* BITWISE_OR_EQUAL  */
    BITWISE_XOR_EQUAL = 342,       /* BITWISE_XOR_EQUAL  */
    SHIFT_LEFT_EQUAL = 343,        /* SHIFT_LEFT_EQUAL  */
    SHIFT_RIGHT_EQUAL = 344,       /* SHIFT_RIGHT_EQUAL  */
    POW_EQUAL = 345,               /* POW_EQUAL  */
    FLOOR_DIV_EQUAL = 346,         /* FLOOR_DIV_EQUAL  */
    INDENT = 347,                  /* INDENT  */
    DEDENT = 348                   /* DEDENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "test.y"

    NODE *elem;

#line 161 "test.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TEST_TAB_H_INCLUDED  */
