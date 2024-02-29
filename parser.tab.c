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




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <bits/stdc++.h>
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    extern stack<int> indent_stack;

#line 80 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KEYWORD = 3,                    /* KEYWORD  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_INDENT = 5,                     /* INDENT  */
  YYSYMBOL_DEDENT = 6,                     /* DEDENT  */
  YYSYMBOL_NAME = 7,                       /* NAME  */
  YYSYMBOL_YIELD = 8,                      /* YIELD  */
  YYSYMBOL_FROM = 9,                       /* FROM  */
  YYSYMBOL_ELIF = 10,                      /* ELIF  */
  YYSYMBOL_AWAIT = 11,                     /* AWAIT  */
  YYSYMBOL_ASYNC = 12,                     /* ASYNC  */
  YYSYMBOL_TRUE = 13,                      /* TRUE  */
  YYSYMBOL_FALSE = 14,                     /* FALSE  */
  YYSYMBOL_NONE = 15,                      /* NONE  */
  YYSYMBOL_IMPORT = 16,                    /* IMPORT  */
  YYSYMBOL_PASS = 17,                      /* PASS  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_EXCEPT = 19,                    /* EXCEPT  */
  YYSYMBOL_RAISE = 20,                     /* RAISE  */
  YYSYMBOL_CLASS = 21,                     /* CLASS  */
  YYSYMBOL_FINALLY = 22,                   /* FINALLY  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 24,                  /* CONTINUE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_LAMBDA = 26,                    /* LAMBDA  */
  YYSYMBOL_TRY = 27,                       /* TRY  */
  YYSYMBOL_AS = 28,                        /* AS  */
  YYSYMBOL_DEF = 29,                       /* DEF  */
  YYSYMBOL_NONLOCAL = 30,                  /* NONLOCAL  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_ASSERT = 32,                    /* ASSERT  */
  YYSYMBOL_DEL = 33,                       /* DEL  */
  YYSYMBOL_GLOBAL = 34,                    /* GLOBAL  */
  YYSYMBOL_WITH = 35,                      /* WITH  */
  YYSYMBOL_INTEGER = 36,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 37,                     /* FLOAT  */
  YYSYMBOL_STRING = 38,                    /* STRING  */
  YYSYMBOL_POW = 39,                       /* POW  */
  YYSYMBOL_FLOOR_DIV = 40,                 /* FLOOR_DIV  */
  YYSYMBOL_DIV = 41,                       /* DIV  */
  YYSYMBOL_MUL = 42,                       /* MUL  */
  YYSYMBOL_ADD = 43,                       /* ADD  */
  YYSYMBOL_SUB = 44,                       /* SUB  */
  YYSYMBOL_MOD = 45,                       /* MOD  */
  YYSYMBOL_EQUAL = 46,                     /* EQUAL  */
  YYSYMBOL_SHIFT_LEFT = 47,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 48,               /* SHIFT_RIGHT  */
  YYSYMBOL_BITWISE_AND = 49,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_XOR = 50,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_OR = 51,                /* BITWISE_OR  */
  YYSYMBOL_TILDE = 52,                     /* TILDE  */
  YYSYMBOL_AT = 53,                        /* AT  */
  YYSYMBOL_COMMA = 54,                     /* COMMA  */
  YYSYMBOL_WAL_OP = 55,                    /* WAL_OP  */
  YYSYMBOL_COLON = 56,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 57,                /* SEMI_COLON  */
  YYSYMBOL_SMALL_OPEN = 58,                /* SMALL_OPEN  */
  YYSYMBOL_SMALL_CLOSE = 59,               /* SMALL_CLOSE  */
  YYSYMBOL_BOX_OPEN = 60,                  /* BOX_OPEN  */
  YYSYMBOL_BOX_CLOSE = 61,                 /* BOX_CLOSE  */
  YYSYMBOL_CURLY_OPEN = 62,                /* CURLY_OPEN  */
  YYSYMBOL_CURLY_CLOSE = 63,               /* CURLY_CLOSE  */
  YYSYMBOL_DOT = 64,                       /* DOT  */
  YYSYMBOL_EQ = 65,                        /* EQ  */
  YYSYMBOL_NE = 66,                        /* NE  */
  YYSYMBOL_LT = 67,                        /* LT  */
  YYSYMBOL_GT = 68,                        /* GT  */
  YYSYMBOL_LE = 69,                        /* LE  */
  YYSYMBOL_GE = 70,                        /* GE  */
  YYSYMBOL_IN = 71,                        /* IN  */
  YYSYMBOL_IS = 72,                        /* IS  */
  YYSYMBOL_IF = 73,                        /* IF  */
  YYSYMBOL_ELSE = 74,                      /* ELSE  */
  YYSYMBOL_AND = 75,                       /* AND  */
  YYSYMBOL_OR = 76,                        /* OR  */
  YYSYMBOL_NOT = 77,                       /* NOT  */
  YYSYMBOL_TYPE_COMMENT = 78,              /* TYPE_COMMENT  */
  YYSYMBOL_ADD_ASSIGN = 79,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 80,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 81,                /* MUL_ASSIGN  */
  YYSYMBOL_AT_ASSIGN = 82,                 /* AT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 83,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 84,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 85,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 86,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 87,                /* XOR_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 88,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 89,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_POW_ASSIGN = 90,                /* POW_ASSIGN  */
  YYSYMBOL_FLOOR_DIV_ASSIGN = 91,          /* FLOOR_DIV_ASSIGN  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_single_input = 93,              /* single_input  */
  YYSYMBOL_decorator = 94,                 /* decorator  */
  YYSYMBOL_decorators = 95,                /* decorators  */
  YYSYMBOL_decorated = 96,                 /* decorated  */
  YYSYMBOL_async_funcdef = 97,             /* async_funcdef  */
  YYSYMBOL_funcdef = 98,                   /* funcdef  */
  YYSYMBOL_parameters = 99,                /* parameters  */
  YYSYMBOL_typedargslist = 100,            /* typedargslist  */
  YYSYMBOL_stmt = 101,                     /* stmt  */
  YYSYMBOL_simple_stmt = 102,              /* simple_stmt  */
  YYSYMBOL_semi_colon_small_stmt_star = 103, /* semi_colon_small_stmt_star  */
  YYSYMBOL_small_stmt = 104,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 105,                /* expr_stmt  */
  YYSYMBOL_expr_stmt_option1_star = 106,   /* expr_stmt_option1_star  */
  YYSYMBOL_annassign = 107,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 108,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_option1_star = 109, /* testlist_star_expr_option1_star  */
  YYSYMBOL_augassign = 110,                /* augassign  */
  YYSYMBOL_del_stmt = 111,                 /* del_stmt  */
  YYSYMBOL_pass_stmt = 112,                /* pass_stmt  */
  YYSYMBOL_flow_stmt = 113,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 114,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 115,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 116,              /* return_stmt  */
  YYSYMBOL_yield_stmt = 117,               /* yield_stmt  */
  YYSYMBOL_raise_stmt = 118,               /* raise_stmt  */
  YYSYMBOL_dotted_name = 119,              /* dotted_name  */
  YYSYMBOL_dot_name_star = 120,            /* dot_name_star  */
  YYSYMBOL_global_stmt = 121,              /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 122,            /* nonlocal_stmt  */
  YYSYMBOL_comma_name_star = 123,          /* comma_name_star  */
  YYSYMBOL_assert_stmt = 124,              /* assert_stmt  */
  YYSYMBOL_compound_stmt = 125,            /* compound_stmt  */
  YYSYMBOL_async_stmt = 126,               /* async_stmt  */
  YYSYMBOL_if_stmt = 127,                  /* if_stmt  */
  YYSYMBOL_elif_namedexpr_test_colon_suite_star = 128, /* elif_namedexpr_test_colon_suite_star  */
  YYSYMBOL_while_stmt = 129,               /* while_stmt  */
  YYSYMBOL_for_stmt = 130,                 /* for_stmt  */
  YYSYMBOL_try_stmt = 131,                 /* try_stmt  */
  YYSYMBOL_except_clause_colon_suite = 132, /* except_clause_colon_suite  */
  YYSYMBOL_try_stmt_options = 133,         /* try_stmt_options  */
  YYSYMBOL_with_stmt = 134,                /* with_stmt  */
  YYSYMBOL_comma_with_item_star = 135,     /* comma_with_item_star  */
  YYSYMBOL_with_item = 136,                /* with_item  */
  YYSYMBOL_except_clause = 137,            /* except_clause  */
  YYSYMBOL_test_as_name_optional = 138,    /* test_as_name_optional  */
  YYSYMBOL_suite = 139,                    /* suite  */
  YYSYMBOL_stmt_plus = 140,                /* stmt_plus  */
  YYSYMBOL_namedexpr_test = 141,           /* namedexpr_test  */
  YYSYMBOL_test = 142,                     /* test  */
  YYSYMBOL_test_nocond = 143,              /* test_nocond  */
  YYSYMBOL_or_test = 144,                  /* or_test  */
  YYSYMBOL_or_and_test_star = 145,         /* or_and_test_star  */
  YYSYMBOL_and_test = 146,                 /* and_test  */
  YYSYMBOL_and_not_test_star = 147,        /* and_not_test_star  */
  YYSYMBOL_not_test = 148,                 /* not_test  */
  YYSYMBOL_comparison = 149,               /* comparison  */
  YYSYMBOL_comp_op_expr_star = 150,        /* comp_op_expr_star  */
  YYSYMBOL_comp_op = 151,                  /* comp_op  */
  YYSYMBOL_star_expr = 152,                /* star_expr  */
  YYSYMBOL_expr = 153,                     /* expr  */
  YYSYMBOL_symbol_xor_expr_star = 154,     /* symbol_xor_expr_star  */
  YYSYMBOL_xor_expr = 155,                 /* xor_expr  */
  YYSYMBOL_symbol_and_expr_star = 156,     /* symbol_and_expr_star  */
  YYSYMBOL_and_expr = 157,                 /* and_expr  */
  YYSYMBOL_symbol_shift_expr_star = 158,   /* symbol_shift_expr_star  */
  YYSYMBOL_shift_expr = 159,               /* shift_expr  */
  YYSYMBOL_shift_arith_expr_star = 160,    /* shift_arith_expr_star  */
  YYSYMBOL_arith_expr = 161,               /* arith_expr  */
  YYSYMBOL_symbol_term_star = 162,         /* symbol_term_star  */
  YYSYMBOL_term = 163,                     /* term  */
  YYSYMBOL_symbol_factor_star = 164,       /* symbol_factor_star  */
  YYSYMBOL_symbol_factor = 165,            /* symbol_factor  */
  YYSYMBOL_factor = 166,                   /* factor  */
  YYSYMBOL_power = 167,                    /* power  */
  YYSYMBOL_atom_expr = 168,                /* atom_expr  */
  YYSYMBOL_trailer_star = 169,             /* trailer_star  */
  YYSYMBOL_atom = 170,                     /* atom  */
  YYSYMBOL_number = 171,                   /* number  */
  YYSYMBOL_string_plus = 172,              /* string_plus  */
  YYSYMBOL_yield_expr_testlist_comp_optional = 173, /* yield_expr_testlist_comp_optional  */
  YYSYMBOL_testlist_comp = 174,            /* testlist_comp  */
  YYSYMBOL_namedexpr_test_star_expr_option = 175, /* namedexpr_test_star_expr_option  */
  YYSYMBOL_namedexpr_test_star_expr_option_star = 176, /* namedexpr_test_star_expr_option_star  */
  YYSYMBOL_trailer = 177,                  /* trailer  */
  YYSYMBOL_subscriptlist = 178,            /* subscriptlist  */
  YYSYMBOL_symbol_subscript_star = 179,    /* symbol_subscript_star  */
  YYSYMBOL_subscript = 180,                /* subscript  */
  YYSYMBOL_optional_test = 181,            /* optional_test  */
  YYSYMBOL_exprlist = 182,                 /* exprlist  */
  YYSYMBOL_expr_star_expr_option = 183,    /* expr_star_expr_option  */
  YYSYMBOL_symbol_expr_star_expr_option_star = 184, /* symbol_expr_star_expr_option_star  */
  YYSYMBOL_testlist = 185,                 /* testlist  */
  YYSYMBOL_symbol_test_star = 186,         /* symbol_test_star  */
  YYSYMBOL_dictorsetmaker = 187,           /* dictorsetmaker  */
  YYSYMBOL_dictorsetmaker_option1 = 188,   /* dictorsetmaker_option1  */
  YYSYMBOL_dictorsetmaker_option1_star = 189, /* dictorsetmaker_option1_star  */
  YYSYMBOL_dictorsetmaker_option2 = 190,   /* dictorsetmaker_option2  */
  YYSYMBOL_classdef = 191,                 /* classdef  */
  YYSYMBOL_bracket_arglist_optional = 192, /* bracket_arglist_optional  */
  YYSYMBOL_arglist = 193,                  /* arglist  */
  YYSYMBOL_comma_arg_star = 194,           /* comma_arg_star  */
  YYSYMBOL_argument = 195,                 /* argument  */
  YYSYMBOL_comp_iter = 196,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 197,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 198,                 /* comp_for  */
  YYSYMBOL_comp_if = 199,                  /* comp_if  */
  YYSYMBOL_yield_expr = 200,               /* yield_expr  */
  YYSYMBOL_yield_arg = 201,                /* yield_arg  */
  YYSYMBOL_func_body_suite = 202           /* func_body_suite  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
#define YYFINAL  132
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  281
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  464

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


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
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    27,    27,    28,    29,    41,    42,    43,    46,    47,
      50,    51,    52,    55,    57,    58,    59,    60,    64,    66,
      71,    72,    75,    76,    79,    80,    83,    84,    85,    86,
      87,    88,    89,    92,    93,    94,    95,    96,    97,   100,
     101,   102,   103,   106,   107,   108,   111,   112,   113,   114,
     117,   118,   119,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   123,   123,   125,   126,   127,   128,
     129,   130,   131,   134,   136,   138,   139,   142,   144,   145,
     146,   171,   173,   174,   177,   179,   181,   182,   185,   186,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   200,
     201,   202,   203,   206,   207,   210,   211,   214,   215,   218,
     219,   220,   221,   224,   225,   228,   229,   232,   233,   234,
     235,   239,   240,   243,   244,   247,   248,   251,   253,   254,
     255,   258,   259,   262,   263,   267,   269,   270,   272,   274,
     276,   277,   280,   282,   283,   286,   287,   290,   292,   293,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     308,   310,   312,   313,   316,   318,   319,   322,   324,   325,
     328,   330,   331,   332,   335,   337,   338,   339,   342,   344,
     345,   348,   349,   350,   351,   354,   355,   356,   357,   360,
     361,   366,   367,   370,   371,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   387,   388,   391,   392,
     395,   396,   397,   401,   402,   403,   406,   407,   410,   411,
     415,   416,   417,   418,   421,   422,   425,   426,   429,   430,
     433,   434,   437,   438,   441,   442,   445,   446,   449,   450,
     453,   454,   457,   458,   459,   460,   461,   462,   465,   466,
     469,   470,   473,   474,   477,   479,   480,   481,   484,   485,
     488,   489,   494,   495,   496,   497,   498,   501,   502,   505,
     506,   509,   510,   514,   515,   520,   521,   524,   525,   528,
     529,   530
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KEYWORD", "NEWLINE",
  "INDENT", "DEDENT", "NAME", "YIELD", "FROM", "ELIF", "AWAIT", "ASYNC",
  "TRUE", "FALSE", "NONE", "IMPORT", "PASS", "BREAK", "EXCEPT", "RAISE",
  "CLASS", "FINALLY", "RETURN", "CONTINUE", "FOR", "LAMBDA", "TRY", "AS",
  "DEF", "NONLOCAL", "WHILE", "ASSERT", "DEL", "GLOBAL", "WITH", "INTEGER",
  "FLOAT", "STRING", "POW", "FLOOR_DIV", "DIV", "MUL", "ADD", "SUB", "MOD",
  "EQUAL", "SHIFT_LEFT", "SHIFT_RIGHT", "BITWISE_AND", "BITWISE_XOR",
  "BITWISE_OR", "TILDE", "AT", "COMMA", "WAL_OP", "COLON", "SEMI_COLON",
  "SMALL_OPEN", "SMALL_CLOSE", "BOX_OPEN", "BOX_CLOSE", "CURLY_OPEN",
  "CURLY_CLOSE", "DOT", "EQ", "NE", "LT", "GT", "LE", "GE", "IN", "IS",
  "IF", "ELSE", "AND", "OR", "NOT", "TYPE_COMMENT", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "AT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LEFT_SHIFT_ASSIGN",
  "RIGHT_SHIFT_ASSIGN", "POW_ASSIGN", "FLOOR_DIV_ASSIGN", "$accept",
  "single_input", "decorator", "decorators", "decorated", "async_funcdef",
  "funcdef", "parameters", "typedargslist", "stmt", "simple_stmt",
  "semi_colon_small_stmt_star", "small_stmt", "expr_stmt",
  "expr_stmt_option1_star", "annassign", "testlist_star_expr",
  "testlist_star_expr_option1_star", "augassign", "del_stmt", "pass_stmt",
  "flow_stmt", "break_stmt", "continue_stmt", "return_stmt", "yield_stmt",
  "raise_stmt", "dotted_name", "dot_name_star", "global_stmt",
  "nonlocal_stmt", "comma_name_star", "assert_stmt", "compound_stmt",
  "async_stmt", "if_stmt", "elif_namedexpr_test_colon_suite_star",
  "while_stmt", "for_stmt", "try_stmt", "except_clause_colon_suite",
  "try_stmt_options", "with_stmt", "comma_with_item_star", "with_item",
  "except_clause", "test_as_name_optional", "suite", "stmt_plus",
  "namedexpr_test", "test", "test_nocond", "or_test", "or_and_test_star",
  "and_test", "and_not_test_star", "not_test", "comparison",
  "comp_op_expr_star", "comp_op", "star_expr", "expr",
  "symbol_xor_expr_star", "xor_expr", "symbol_and_expr_star", "and_expr",
  "symbol_shift_expr_star", "shift_expr", "shift_arith_expr_star",
  "arith_expr", "symbol_term_star", "term", "symbol_factor_star",
  "symbol_factor", "factor", "power", "atom_expr", "trailer_star", "atom",
  "number", "string_plus", "yield_expr_testlist_comp_optional",
  "testlist_comp", "namedexpr_test_star_expr_option",
  "namedexpr_test_star_expr_option_star", "trailer", "subscriptlist",
  "symbol_subscript_star", "subscript", "optional_test", "exprlist",
  "expr_star_expr_option", "symbol_expr_star_expr_option_star", "testlist",
  "symbol_test_star", "dictorsetmaker", "dictorsetmaker_option1",
  "dictorsetmaker_option1_star", "dictorsetmaker_option2", "classdef",
  "bracket_arglist_optional", "arglist", "comma_arg_star", "argument",
  "comp_iter", "sync_comp_for", "comp_for", "comp_if", "yield_expr",
  "yield_arg", "func_body_suite", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-343)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-231)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     625,  -343,  -343,   927,   119,    84,  -343,  -343,  -343,  -343,
    -343,  1178,    39,  1061,  -343,  1189,   -16,    56,    63,  1178,
    1178,  1189,    68,  1178,  -343,  -343,    -2,  1239,  1239,  1239,
    1239,    92,   983,   994,    58,  1178,  1178,   106,    15,    38,
    -343,  -343,  -343,    -1,  -343,  1179,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,   104,  -343,  -343,
    -343,  -343,  -343,  -343,    57,    51,    46,    52,  -343,    57,
     243,    85,    93,    96,    37,    49,    11,  -343,   109,    65,
    -343,  -343,  -343,  -343,  1178,  -343,  -343,    65,  -343,  -343,
    -343,   141,   103,  -343,  -343,  -343,    91,   111,   686,   105,
     112,   114,  -343,   113,  -343,   112,   117,   140,  -343,  -343,
    -343,  -343,  -343,   108,    29,  -343,  -343,   115,  -343,    35,
    -343,  -343,   121,  1239,  -343,   120,  -343,   110,    36,    36,
     122,  -343,  -343,  -343,   146,  -343,  -343,  -343,   241,    31,
    1178,   983,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,   107,  -343,  1117,  -343,  1061,
     129,  1178,  1178,  -343,  1178,  -343,   130,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,   116,   118,  -343,  1239,  1239,  -343,
    1239,  -343,  1239,  -343,  1239,  1239,  -343,  1239,  1239,  -343,
    1239,  1239,  1239,  1239,  -343,    11,  1239,   855,  1178,   179,
    -343,    65,  -343,  -343,  1178,   866,   134,  1178,  1189,   137,
     191,  -343,    61,   195,    10,   197,  -343,   686,  1178,  -343,
    1178,   153,  1239,   205,  -343,  -343,   916,  -343,   189,  1189,
    1061,  -343,  -343,  -343,  -343,  1178,  -343,  1128,   163,  -343,
     164,  -343,   686,  -343,    -1,  -343,   215,   156,   157,   157,
    -343,   169,  -343,  -343,    57,    57,  -343,   150,    46,    52,
    -343,  -343,  -343,   243,    85,    93,    96,    37,    37,    49,
      49,  -343,  -343,  -343,  -343,  -343,  -343,  1178,  1178,  -343,
      33,   167,   174,   176,   181,   183,   190,  -343,  -343,  -343,
    -343,   188,   686,   204,   111,  -343,   805,  1178,   206,    12,
     207,   112,   192,   185,   353,   112,   196,  -343,   117,   421,
    -343,   108,   262,   210,  -343,   201,  1061,   222,  -343,   120,
     226,  -343,  -343,   272,  -343,  -343,   983,  -343,  -343,  1178,
     232,  -343,  -343,  1178,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,  1178,  -343,  -343,  1050,
     234,  -343,  1178,   235,  1178,  -343,  -343,   489,  -343,   805,
    -343,  -343,   284,  -343,   263,   686,   236,   238,  -343,   686,
     244,  -343,  1178,    25,   747,  -343,  -343,  -343,   239,  -343,
     686,  -343,  -343,  -343,   296,  1178,  -343,  -343,  -343,  1178,
     228,  -343,  -343,   169,  -343,  -343,  -343,   174,  -343,   183,
    -343,  -343,  -343,   686,   231,  -343,  -343,   300,  -343,   686,
     686,   297,   276,   266,   805,   320,  -343,   686,  -343,  -343,
      32,   269,   270,  -343,  -343,  -343,   254,   273,  -343,  -343,
     308,  -343,  -343,   557,   325,   327,  -343,  1178,  -343,  -343,
    -343,   686,   686,   277,   686,   278,   747,  -343,  -343,   805,
      32,  -343,   272,  -343,   686,  -343,   686,  -343,   329,  -343,
    -343,  -343,  -343,  -343
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     2,   200,   275,     0,     0,   204,   205,   203,    67,
      73,    78,     0,    76,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   206,   207,   209,     0,     0,     0,
       0,     0,   212,     0,     0,     0,     0,     0,     9,     0,
      97,    95,     3,    25,    26,    36,    27,    28,    29,    68,
      69,    70,    72,    71,    30,    31,    32,     0,    98,    90,
      91,    92,    93,    94,    52,   136,   141,   144,   146,    52,
     149,   163,   166,   169,   171,   175,   179,   188,   189,   194,
     201,   202,    96,    77,     0,   278,   276,   194,    99,   101,
     100,    79,   257,    75,   235,   234,     0,   237,     0,     0,
      87,     0,   135,    89,    66,    87,   124,   125,   208,   160,
     185,   186,   187,    83,     0,   216,   217,     0,   211,     0,
     210,   197,     0,     0,   199,   252,   253,     0,   251,   251,
       0,   145,     1,     8,     0,    12,    11,    10,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    37,    33,     0,     4,     0,
      46,     0,     0,   139,     0,   142,    48,   152,   155,   150,
     151,   154,   153,   156,   158,     0,   147,     0,     0,   161,
       0,   164,     0,   167,     0,     0,   170,     0,     0,   174,
       0,     0,     0,     0,   178,   179,     0,     0,   231,     0,
     192,   194,   277,   191,     0,     0,     0,     0,     0,   233,
       0,   131,     0,     0,     0,     0,    85,     0,     0,    84,
       0,     0,     0,     0,    81,     7,     0,   195,     0,     0,
     219,   271,   213,   196,   249,     0,   198,     0,   243,   242,
     246,   245,     0,    13,    25,    23,     0,    43,    42,    41,
      38,   241,    35,    34,    52,    52,    47,     0,   141,   144,
      49,   159,   157,   149,   163,   166,   169,   171,   171,   175,
     175,   184,   183,   181,   182,   180,   190,     0,     0,   221,
     262,     0,   261,   228,     0,   226,     0,   223,   193,    80,
     255,     0,     0,     0,   237,   232,     0,   130,     0,   120,
       0,     0,     0,     0,     0,    87,   108,    88,   124,     0,
     126,    83,     0,     0,   272,     0,   219,   214,   248,     0,
     251,   244,   247,   106,    24,    22,     0,    40,    39,     0,
     239,    50,    51,     0,   140,   143,   148,   162,   165,   168,
     172,   173,   176,   177,   265,   266,     0,   263,   220,     0,
     258,   222,   231,   224,   231,   256,   254,     0,   236,   134,
      20,    21,     0,   127,   128,     0,     0,     0,   114,     0,
       0,    18,     0,     0,     0,   279,    17,    86,     0,   123,
       0,   121,    82,     6,     0,     0,   218,   215,   250,     0,
     104,    45,    44,   241,   238,   137,   264,   261,   259,   226,
     225,   230,   229,     0,   112,   133,   132,     0,   113,     0,
       0,   116,     0,     0,     0,     0,    16,     0,   122,     5,
     269,     0,     0,   240,   260,   227,   111,     0,   129,   119,
     118,   115,    19,     0,     0,     0,   107,     0,   270,   267,
     268,     0,     0,     0,     0,     0,     0,    15,   280,     0,
     273,   138,   106,   103,     0,   110,     0,    14,     0,   274,
     105,   109,   117,   281
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -343,  -343,  -343,   299,  -343,  -343,     3,  -343,  -343,  -343,
       0,    94,   202,  -343,  -134,  -343,     1,   -54,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,    30,  -343,
    -343,   -94,  -343,   343,  -343,  -343,  -107,  -343,   341,  -343,
     -64,  -343,   344,    40,   131,  -343,  -343,  -211,  -332,   -17,
     -10,  -343,  -156,    95,   193,    97,   -20,  -343,    87,  -343,
       5,    28,    88,   180,    89,   198,    99,   187,  -129,   -44,
    -110,   -35,   168,  -343,    48,  -343,  -343,   -70,   371,  -343,
     354,  -343,   348,  -209,    66,  -343,  -343,   -15,    41,    34,
     -14,   184,   100,   194,     6,  -343,   161,  -117,  -343,   361,
    -343,  -164,     7,    53,   -47,   178,  -100,  -343,   -29,  -343,
    -342
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    37,    38,    39,    40,   135,    41,   214,   302,   359,
     211,   139,    43,    44,   155,   156,    45,   160,   157,    46,
      47,    48,    49,    50,    51,    52,    53,   114,   224,    54,
      55,   216,    56,   361,    58,    59,   390,    60,    61,    62,
     299,   368,    63,   221,   106,   300,   363,   212,   362,   115,
      64,   450,    65,   163,    66,   165,    67,    68,   176,   177,
      69,    70,   179,    71,   181,    72,   183,    73,   186,    74,
     189,    75,   194,   195,    76,    77,    78,   200,    79,    80,
      81,   117,   118,   119,   317,   201,   284,   353,   285,   286,
      96,    97,   209,   252,   330,   127,   128,   238,   129,    82,
     206,   281,   350,   282,   438,   231,   439,   440,    83,    86,
     376
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    91,   101,   120,    85,   257,   306,   104,    88,   102,
     103,   219,   240,   107,    93,   166,   131,   203,   130,   232,
      94,   316,   102,   102,   125,   102,    94,   405,   239,   241,
     414,   323,   416,   225,   366,   245,    26,   116,   116,   126,
      98,   291,   136,    95,   228,   228,    92,   228,   228,    95,
     134,   190,   191,   192,   303,   109,   138,   229,   229,    12,
     229,   229,   313,    99,   193,     2,   304,    17,    31,     4,
     100,     6,     7,     8,   202,   105,   110,   111,   112,   346,
     297,   356,   434,   298,   184,   185,   367,   226,   246,   230,
     237,   447,   187,   188,    24,    25,    26,   123,   381,   113,
      27,    28,    29,   415,   457,   437,   132,   316,   158,    15,
      30,   159,   249,    17,   327,   328,    32,   458,    33,    23,
      34,   124,   162,   197,   161,   198,     2,   164,   253,   199,
     247,   288,     6,     7,     8,    36,   178,   243,   340,   341,
     267,   268,   248,   180,   259,   182,   404,   251,   196,   254,
     204,   234,   269,   270,   408,    24,    25,    26,   411,   342,
     343,   205,   207,   213,   255,   208,   215,   218,   222,   418,
     217,   220,   223,   236,   227,    17,   235,    32,   242,    33,
     347,    34,   233,   256,   260,   250,   287,   280,   283,   262,
     292,   295,   426,   261,   289,   280,   296,   251,   429,   430,
     331,   332,   301,   388,   305,   263,   436,   370,   307,   309,
     107,   377,   311,    94,   229,   315,   280,   321,   322,   325,
     102,   326,   141,   329,   333,   318,   348,   319,   349,   420,
     452,   453,  -230,   455,    94,   116,    95,   352,   271,   272,
     273,   274,   351,   461,   276,   462,   354,   355,     2,     3,
     310,   371,     4,   372,     6,     7,     8,    95,     9,    10,
     357,    11,   365,   369,    13,    14,   383,   344,   345,   384,
     378,    18,   385,    20,    21,    22,   387,    24,    25,    26,
     237,   451,   389,    27,    28,    29,   394,   364,   398,   400,
     406,   407,   409,    30,   410,   417,   360,   392,   412,    32,
     419,    33,   422,    34,   375,   427,   102,   428,   167,   168,
     169,   170,   171,   172,   173,   174,   297,   432,    36,   393,
     175,   116,   433,   395,   435,   441,   442,   391,   443,   444,
     445,   448,   449,   454,   456,   463,   396,   133,   324,   280,
     244,   382,   283,    57,   401,   460,    89,   431,   379,    90,
     336,   308,   337,   334,   338,   258,   335,   373,   264,   360,
       2,     3,   413,   275,     4,   339,     6,     7,     8,   266,
       9,    10,   421,    11,   375,    87,    13,    14,   265,   102,
     108,   122,   386,    18,   425,    20,    21,    22,   402,    24,
      25,    26,   294,   399,   358,    27,    28,    29,   320,   423,
     137,   293,   397,   459,   424,    30,   314,     0,     0,     0,
       0,    32,     0,    33,   360,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,     0,     0,     2,     3,
      36,   374,     4,   375,     6,     7,     8,     0,     9,    10,
       0,    11,     0,     0,    13,    14,   375,     0,     0,   360,
       0,    18,     0,    20,    21,    22,     0,    24,    25,    26,
       0,     0,     0,    27,    28,    29,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,    32,
       0,    33,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,     0,     0,     2,     3,    36,   380,
       4,     0,     6,     7,     8,     0,     9,    10,     0,    11,
       0,     0,    13,    14,     0,     0,     0,     0,     0,    18,
       0,    20,    21,    22,     0,    24,    25,    26,     0,     0,
       0,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,    32,     0,    33,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     2,     3,    36,   403,     4,     0,
       6,     7,     8,     0,     9,    10,     0,    11,     0,     0,
      13,    14,     0,     0,     0,     0,     0,    18,     0,    20,
      21,    22,     0,    24,    25,    26,     0,     0,     0,    27,
      28,    29,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,    32,     0,    33,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     2,     3,    36,   446,     4,     5,     6,     7,
       8,     0,     9,    10,     0,    11,    12,     0,    13,    14,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
       0,     0,     0,    32,     0,    33,     0,    34,     0,     0,
     210,     0,     0,     2,     3,     0,     0,     4,    35,     6,
       7,     8,    36,     9,    10,     0,    11,     0,     0,    13,
      14,     0,     0,     0,     0,     0,    18,     0,    20,    21,
      22,     0,    24,    25,    26,     0,     0,     0,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,    32,     0,    33,     0,    34,     0,
       0,   373,     0,     0,     2,     3,     0,     0,     4,     0,
       6,     7,     8,    36,     9,    10,     0,    11,     0,     0,
      13,    14,     0,     0,     0,     0,     0,    18,     0,    20,
      21,    22,     0,    24,    25,    26,     0,     0,     0,    27,
      28,    29,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,    32,     0,    33,     0,    34,
       0,     0,     2,     3,     0,     0,     4,     5,     6,     7,
       8,     0,     9,    10,    36,    11,    12,     0,    13,    14,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
       0,     0,     2,    32,     0,    33,     4,    34,     6,     7,
       8,     0,     0,     2,     0,     0,     0,     4,    35,     6,
       7,     8,    36,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,    26,   277,     0,     0,   278,    28,    29,
       0,     0,    24,    25,    26,   277,     0,    30,   278,    28,
      29,     0,     0,    32,   279,    33,     0,    34,    30,     0,
       0,     0,     0,     2,    32,   290,    33,     4,    34,     6,
       7,     8,    36,     0,     2,     0,    84,     0,     4,     0,
       6,     7,     8,    36,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,   277,     0,     0,   278,    28,
      29,     0,     0,    24,    25,    26,     0,     0,    30,    27,
      28,    29,     0,     0,    32,   312,    33,     0,    34,    30,
       0,     0,     0,     0,     0,    32,     0,    33,     0,    34,
       2,     3,     0,    36,     4,     0,     6,     7,     8,     0,
       0,     2,     0,     0,    36,     4,     0,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    26,     0,     0,     0,    27,    28,    29,     0,     0,
      24,    25,    26,     0,     0,    30,    27,    28,    29,     0,
       0,    32,     0,    33,     0,    34,    30,     0,     0,     0,
       0,     0,    32,     0,    33,   121,    34,     2,     0,     0,
      36,     4,     0,     6,     7,     8,     0,     0,     2,     0,
       0,    36,     4,     0,     6,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    26,   277,
       0,     0,   278,    28,    29,     0,     0,    24,    25,    26,
       0,     0,    30,    27,    28,    29,     0,     0,    32,     0,
      33,     0,    34,    30,     0,     0,     0,     0,     0,    32,
       0,    33,     0,    34,     2,     3,     0,    36,     4,     0,
       6,     7,     8,     0,     0,     2,     0,     0,    36,     4,
       0,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,     0,     0,     0,     0,
      28,    29,     0,     0,    24,    25,    26,   123,     0,    30,
       0,    28,    29,     0,     0,    32,     0,    33,     0,    34,
      30,     0,     0,     0,     0,     2,    32,     0,    33,     4,
      34,     6,     7,     8,    36,     0,     2,     0,     0,     0,
       4,     0,     6,     7,     8,    36,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,    26,     0,     0,     0,
       0,    28,    29,     0,     0,    24,    25,    26,     0,     0,
      30,    27,    28,    29,     0,   140,    32,     0,    33,     0,
      34,    30,     0,     0,   141,     0,     2,    32,     0,    33,
       4,    34,     6,     7,     8,    36,     0,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,    24,    25,    26,     0,     0,
       0,     0,    28,    29,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,    32,     0,    33,
       0,    34
};

static const yytype_int16 yycheck[] =
{
       0,    11,    19,    32,     3,   161,   217,    21,     5,    19,
      20,   105,   129,    23,    13,    69,    36,    87,    35,   119,
      15,   230,    32,    33,    34,    35,    21,   359,   128,   129,
       5,   242,   374,     4,    22,     4,    38,    32,    33,    34,
      56,   205,    39,    15,    12,    12,     7,    12,    12,    21,
      12,    40,    41,    42,    44,    27,    57,    25,    25,    21,
      25,    25,   226,     7,    53,     7,    56,    29,    53,    11,
       7,    13,    14,    15,    84,     7,    28,    29,    30,    46,
      19,   292,   414,    22,    47,    48,    74,    58,    57,    54,
      54,   433,    43,    44,    36,    37,    38,    39,   309,     7,
      42,    43,    44,    78,   446,    73,     0,   316,     4,    25,
      52,    54,   141,    29,   248,   249,    58,   449,    60,    35,
      62,    63,    76,    58,    73,    60,     7,    75,   157,    64,
     140,   201,    13,    14,    15,    77,    51,   134,   267,   268,
     184,   185,   141,    50,   164,    49,   357,   157,    39,   159,
       9,   123,   187,   188,   365,    36,    37,    38,   369,   269,
     270,    58,    71,    58,   159,    54,    54,    54,    28,   380,
      56,    54,    64,    63,    59,    29,    56,    58,    56,    60,
     280,    62,    61,    54,    54,    78,     7,   197,   198,    71,
      56,    54,   403,    77,   204,   205,     5,   207,   409,   410,
     254,   255,     7,   320,     7,   177,   417,   301,   218,    56,
     220,   305,     7,   208,    25,   229,   226,    54,    54,     4,
     230,    65,    65,    54,    74,   235,    59,   237,    54,   385,
     441,   442,    56,   444,   229,   230,   208,    54,   190,   191,
     192,   193,    61,   454,   196,   456,    56,    59,     7,     8,
     222,    59,    11,    68,    13,    14,    15,   229,    17,    18,
      56,    20,    56,    56,    23,    24,     4,   277,   278,    59,
      74,    30,    71,    32,    33,    34,    54,    36,    37,    38,
      54,   437,    10,    42,    43,    44,    54,   297,    54,    54,
       6,    28,    56,    52,    56,    56,   296,   326,    54,    58,
       4,    60,    74,    62,   304,    74,   316,     7,    65,    66,
      67,    68,    69,    70,    71,    72,    19,    41,    77,   329,
      77,   316,    56,   333,     4,    56,    56,   326,    74,    56,
      22,     6,     5,    56,    56,     6,   346,    38,   244,   349,
     138,   311,   352,     0,   354,   452,     5,   411,   308,     5,
     263,   220,   264,   258,   265,   162,   259,     4,   178,   359,
       7,     8,   372,   195,    11,   266,    13,    14,    15,   182,
      17,    18,   389,    20,   374,     4,    23,    24,   180,   389,
      26,    33,   316,    30,   399,    32,    33,    34,   354,    36,
      37,    38,   208,   352,   294,    42,    43,    44,   237,   393,
      39,   207,   349,   450,   397,    52,   228,    -1,    -1,    -1,
      -1,    58,    -1,    60,   414,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,     7,     8,
      77,    78,    11,   433,    13,    14,    15,    -1,    17,    18,
      -1,    20,    -1,    -1,    23,    24,   446,    -1,    -1,   449,
      -1,    30,    -1,    32,    33,    34,    -1,    36,    37,    38,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,    -1,     7,     8,    77,    78,
      11,    -1,    13,    14,    15,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    -1,    36,    37,    38,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,     7,     8,    77,    78,    11,    -1,
      13,    14,    15,    -1,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,     7,     8,    77,    78,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,
       4,    -1,    -1,     7,     8,    -1,    -1,    11,    73,    13,
      14,    15,    77,    17,    18,    -1,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    62,    -1,
      -1,     4,    -1,    -1,     7,     8,    -1,    -1,    11,    -1,
      13,    14,    15,    77,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    62,
      -1,    -1,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    77,    20,    21,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,     7,    58,    -1,    60,    11,    62,    13,    14,
      15,    -1,    -1,     7,    -1,    -1,    -1,    11,    73,    13,
      14,    15,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      -1,    -1,    36,    37,    38,    39,    -1,    52,    42,    43,
      44,    -1,    -1,    58,    59,    60,    -1,    62,    52,    -1,
      -1,    -1,    -1,     7,    58,    59,    60,    11,    62,    13,
      14,    15,    77,    -1,     7,    -1,     9,    -1,    11,    -1,
      13,    14,    15,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    36,    37,    38,    -1,    -1,    52,    42,
      43,    44,    -1,    -1,    58,    59,    60,    -1,    62,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    62,
       7,     8,    -1,    77,    11,    -1,    13,    14,    15,    -1,
      -1,     7,    -1,    -1,    77,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,
      36,    37,    38,    -1,    -1,    52,    42,    43,    44,    -1,
      -1,    58,    -1,    60,    -1,    62,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60,    61,    62,     7,    -1,    -1,
      77,    11,    -1,    13,    14,    15,    -1,    -1,     7,    -1,
      -1,    77,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    36,    37,    38,
      -1,    -1,    52,    42,    43,    44,    -1,    -1,    58,    -1,
      60,    -1,    62,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    -1,    62,     7,     8,    -1,    77,    11,    -1,
      13,    14,    15,    -1,    -1,     7,    -1,    -1,    77,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    36,    37,    38,    39,    -1,    52,
      -1,    43,    44,    -1,    -1,    58,    -1,    60,    -1,    62,
      52,    -1,    -1,    -1,    -1,     7,    58,    -1,    60,    11,
      62,    13,    14,    15,    77,    -1,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    36,    37,    38,    -1,    -1,
      52,    42,    43,    44,    -1,    56,    58,    -1,    60,    -1,
      62,    52,    -1,    -1,    65,    -1,     7,    58,    -1,    60,
      11,    62,    13,    14,    15,    77,    -1,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,     8,    11,    12,    13,    14,    15,    17,
      18,    20,    21,    23,    24,    25,    27,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    42,    43,    44,
      52,    53,    58,    60,    62,    73,    77,    93,    94,    95,
      96,    98,   102,   104,   105,   108,   111,   112,   113,   114,
     115,   116,   117,   118,   121,   122,   124,   125,   126,   127,
     129,   130,   131,   134,   142,   144,   146,   148,   149,   152,
     153,   155,   157,   159,   161,   163,   166,   167,   168,   170,
     171,   172,   191,   200,     9,   108,   201,   170,    98,   130,
     134,   142,     7,   108,   152,   153,   182,   183,    56,     7,
       7,   141,   142,   142,   182,     7,   136,   142,   172,   153,
     166,   166,   166,     7,   119,   141,   152,   173,   174,   175,
     200,    61,   174,    39,    63,   142,   152,   187,   188,   190,
     141,   148,     0,    95,    12,    97,    98,   191,    57,   103,
      56,    65,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   106,   107,   110,     4,    54,
     109,    73,    76,   145,    75,   147,   109,    65,    66,    67,
      68,    69,    70,    71,    72,    77,   150,   151,    51,   154,
      50,   156,    49,   158,    47,    48,   160,    43,    44,   162,
      40,    41,    42,    53,   164,   165,    39,    58,    60,    64,
     169,   177,   142,   169,     9,    58,   192,    71,    54,   184,
       4,   102,   139,    58,    99,    54,   123,    56,    54,   123,
      54,   135,    28,    64,   120,     4,    58,    59,    12,    25,
      54,   197,   198,    61,   153,    56,    63,    54,   189,   198,
     189,   198,    56,    98,   104,     4,    57,   142,   108,   200,
      78,   142,   185,   200,   142,   152,    54,   144,   146,   148,
      54,    77,    71,   153,   155,   157,   159,   161,   161,   163,
     163,   166,   166,   166,   166,   164,   166,    39,    42,    59,
     142,   193,   195,   142,   178,   180,   181,     7,   169,   142,
      59,   193,    56,   185,   183,    54,     5,    19,    22,   132,
     137,     7,   100,    44,    56,     7,   139,   142,   136,    56,
     153,     7,    59,   193,   197,   182,   175,   176,   142,   142,
     188,    54,    54,   139,   103,     4,    65,   106,   106,    54,
     186,   109,   109,    74,   145,   147,   150,   154,   156,   158,
     160,   160,   162,   162,   142,   142,    46,   198,    59,    54,
     194,    61,    54,   179,    56,    59,   139,    56,   184,   101,
     102,   125,   140,   138,   142,    56,    22,    74,   133,    56,
     123,    59,    68,     4,    78,   102,   202,   123,    74,   135,
      78,   139,   120,     4,    59,    71,   176,    54,   189,    10,
     128,   108,   200,   142,    54,   142,   142,   195,    54,   180,
      54,   142,   181,    78,   139,   140,     6,    28,   139,    56,
      56,   139,    54,   142,     5,    78,   202,    56,   139,     4,
     144,   141,    74,   186,   194,   179,   139,    74,     7,   139,
     139,   132,    41,    56,   140,     4,   139,    73,   196,   198,
     199,    56,    56,    74,    56,    22,    78,   202,     6,     5,
     143,   144,   139,   139,    56,   139,    56,   202,   140,   196,
     128,   139,   139,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    94,    94,    94,    95,    95,
      96,    96,    96,    97,    98,    98,    98,    98,    99,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   107,   107,   107,   108,   108,   108,   108,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   112,   113,   113,
     113,   113,   113,   114,   115,   116,   116,   117,   118,   118,
     118,   119,   120,   120,   121,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   138,   138,
     138,   139,   139,   140,   140,   141,   142,   142,   143,   144,
     145,   145,   146,   147,   147,   148,   148,   149,   150,   150,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     152,   153,   154,   154,   155,   156,   156,   157,   158,   158,
     159,   160,   160,   160,   161,   162,   162,   162,   163,   164,
     164,   165,   165,   165,   165,   166,   166,   166,   166,   167,
     167,   168,   168,   169,   169,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     173,   173,   173,   174,   174,   174,   175,   175,   176,   176,
     177,   177,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181,   182,   182,   183,   183,   184,   184,   185,   185,
     186,   186,   187,   187,   187,   187,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   195,   195,   195,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   202
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     5,     3,     2,     1,
       2,     2,     2,     2,     9,     8,     6,     5,     3,     4,
       1,     1,     4,     3,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     1,     2,     3,     3,
       3,     2,     2,     2,     4,     4,     2,     3,     2,     3,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       4,     2,     3,     0,     3,     3,     3,     0,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     8,     5,     5,     0,     7,     4,    10,
       9,     7,     6,     6,     5,     4,     3,     6,     3,     3,
       0,     5,     6,     3,     0,     1,     3,     2,     1,     3,
       0,     1,     4,     2,     1,     1,     1,     5,     1,     2,
       3,     0,     2,     3,     0,     2,     1,     2,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       2,     2,     3,     0,     2,     3,     0,     2,     3,     0,
       2,     0,     3,     3,     2,     0,     3,     3,     2,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     2,     2,     0,     3,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     0,     2,     3,     4,     1,     1,     2,     0,
       3,     2,     3,     2,     2,     3,     0,     3,     1,     3,
       1,     0,     3,     2,     1,     1,     3,     0,     3,     2,
       3,     0,     2,     2,     3,     2,     2,     3,     3,     2,
       3,     0,     1,     1,     5,     2,     3,     0,     2,     3,
       3,     0,     1,     2,     3,     2,     2,     1,     1,     4,
       5,     1,     2,     2,     3,     1,     2,     2,     1,     1,
       4,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
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
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

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
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
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
  yychar = YYEMPTY;
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

#line 1807 "parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (yychar != YYEMPTY)
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

#line 557 "parser.y"


int main(){
    indent_stack.push(0);
    /* yylex(); */
    yyparse();
    return 0;
}
int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}
