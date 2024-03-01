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
#line 1 "test.y"

    #include <bits/stdc++.h>
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    extern stack<int> indent_stack;

#line 80 "test.tab.c"

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

#include "test.tab.h"
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
  YYSYMBOL_ARROW = 65,                     /* ARROW  */
  YYSYMBOL_DOUBLE_EQUAL = 66,              /* DOUBLE_EQUAL  */
  YYSYMBOL_NE = 67,                        /* NE  */
  YYSYMBOL_LT = 68,                        /* LT  */
  YYSYMBOL_GT = 69,                        /* GT  */
  YYSYMBOL_LE = 70,                        /* LE  */
  YYSYMBOL_GE = 71,                        /* GE  */
  YYSYMBOL_IN = 72,                        /* IN  */
  YYSYMBOL_IS = 73,                        /* IS  */
  YYSYMBOL_IF = 74,                        /* IF  */
  YYSYMBOL_ELSE = 75,                      /* ELSE  */
  YYSYMBOL_AND = 76,                       /* AND  */
  YYSYMBOL_OR = 77,                        /* OR  */
  YYSYMBOL_NOT = 78,                       /* NOT  */
  YYSYMBOL_TYPE_HINT = 79,                 /* TYPE_HINT  */
  YYSYMBOL_FUNC_TYPE_HINT = 80,            /* FUNC_TYPE_HINT  */
  YYSYMBOL_ADD_EQUAL = 81,                 /* ADD_EQUAL  */
  YYSYMBOL_SUB_EQUAL = 82,                 /* SUB_EQUAL  */
  YYSYMBOL_MUL_EQUAL = 83,                 /* MUL_EQUAL  */
  YYSYMBOL_AT_EQUAL = 84,                  /* AT_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 85,                 /* DIV_EQUAL  */
  YYSYMBOL_MOD_EQUAL = 86,                 /* MOD_EQUAL  */
  YYSYMBOL_BITWISE_AND_EQUAL = 87,         /* BITWISE_AND_EQUAL  */
  YYSYMBOL_BITWISE_OR_EQUAL = 88,          /* BITWISE_OR_EQUAL  */
  YYSYMBOL_BITWISE_XOR_EQUAL = 89,         /* BITWISE_XOR_EQUAL  */
  YYSYMBOL_SHIFT_LEFT_EQUAL = 90,          /* SHIFT_LEFT_EQUAL  */
  YYSYMBOL_SHIFT_RIGHT_EQUAL = 91,         /* SHIFT_RIGHT_EQUAL  */
  YYSYMBOL_POW_EQUAL = 92,                 /* POW_EQUAL  */
  YYSYMBOL_FLOOR_DIV_EQUAL = 93,           /* FLOOR_DIV_EQUAL  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_file_input = 95,                /* file_input  */
  YYSYMBOL_stmt = 96,                      /* stmt  */
  YYSYMBOL_compound_stmt = 97,             /* compound_stmt  */
  YYSYMBOL_async_stmt = 98,                /* async_stmt  */
  YYSYMBOL_if_stmt = 99,                   /* if_stmt  */
  YYSYMBOL_elif_namedexpr_test_colon_suite_star = 100, /* elif_namedexpr_test_colon_suite_star  */
  YYSYMBOL_while_stmt = 101,               /* while_stmt  */
  YYSYMBOL_for_stmt = 102,                 /* for_stmt  */
  YYSYMBOL_try_stmt = 103,                 /* try_stmt  */
  YYSYMBOL_except_clause_colon_suite = 104, /* except_clause_colon_suite  */
  YYSYMBOL_try_stmt_options = 105,         /* try_stmt_options  */
  YYSYMBOL_except_clause = 106,            /* except_clause  */
  YYSYMBOL_test_as_name_optional = 107,    /* test_as_name_optional  */
  YYSYMBOL_funcdef = 108,                  /* funcdef  */
  YYSYMBOL_parameters = 109,               /* parameters  */
  YYSYMBOL_typedlist_argument = 110,       /* typedlist_argument  */
  YYSYMBOL_typedlist_arguments = 111,      /* typedlist_arguments  */
  YYSYMBOL_comma_option_argument_star = 112, /* comma_option_argument_star  */
  YYSYMBOL_typedarglist = 113,             /* typedarglist  */
  YYSYMBOL_tfpdef = 114,                   /* tfpdef  */
  YYSYMBOL_func_body_suite = 115,          /* func_body_suite  */
  YYSYMBOL_suite = 116,                    /* suite  */
  YYSYMBOL_stmt_plus = 117,                /* stmt_plus  */
  YYSYMBOL_simple_stmt = 118,              /* simple_stmt  */
  YYSYMBOL_semi_colon_small_stmt_star = 119, /* semi_colon_small_stmt_star  */
  YYSYMBOL_small_stmt = 120,               /* small_stmt  */
  YYSYMBOL_flow_stmt = 121,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 122,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 123,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 124,              /* return_stmt  */
  YYSYMBOL_raise_stmt = 125,               /* raise_stmt  */
  YYSYMBOL_global_stmt = 126,              /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 127,            /* nonlocal_stmt  */
  YYSYMBOL_comma_name_star = 128,          /* comma_name_star  */
  YYSYMBOL_assert_stmt = 129,              /* assert_stmt  */
  YYSYMBOL_expr_stmt = 130,                /* expr_stmt  */
  YYSYMBOL_testlist = 131,                 /* testlist  */
  YYSYMBOL_symbol_test_star = 132,         /* symbol_test_star  */
  YYSYMBOL_expr_stmt_option1_plus = 133,   /* expr_stmt_option1_plus  */
  YYSYMBOL_annassign = 134,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 135,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_option1_star = 136, /* testlist_star_expr_option1_star  */
  YYSYMBOL_augassign = 137,                /* augassign  */
  YYSYMBOL_expr = 138,                     /* expr  */
  YYSYMBOL_star_expr = 139,                /* star_expr  */
  YYSYMBOL_symbol_xor_expr_star = 140,     /* symbol_xor_expr_star  */
  YYSYMBOL_xor_expr = 141,                 /* xor_expr  */
  YYSYMBOL_symbol_and_expr_star = 142,     /* symbol_and_expr_star  */
  YYSYMBOL_and_expr = 143,                 /* and_expr  */
  YYSYMBOL_symbol_shift_expr_star = 144,   /* symbol_shift_expr_star  */
  YYSYMBOL_shift_expr = 145,               /* shift_expr  */
  YYSYMBOL_shift_arith_expr_star = 146,    /* shift_arith_expr_star  */
  YYSYMBOL_arith_expr = 147,               /* arith_expr  */
  YYSYMBOL_symbol_term_star = 148,         /* symbol_term_star  */
  YYSYMBOL_term = 149,                     /* term  */
  YYSYMBOL_symbol_factor_star = 150,       /* symbol_factor_star  */
  YYSYMBOL_symbol_factor = 151,            /* symbol_factor  */
  YYSYMBOL_factor = 152,                   /* factor  */
  YYSYMBOL_power = 153,                    /* power  */
  YYSYMBOL_atom_expr = 154,                /* atom_expr  */
  YYSYMBOL_trailer_star = 155,             /* trailer_star  */
  YYSYMBOL_trailer = 156,                  /* trailer  */
  YYSYMBOL_classdef = 157,                 /* classdef  */
  YYSYMBOL_bracket_arglist_optional = 158, /* bracket_arglist_optional  */
  YYSYMBOL_arglist = 159,                  /* arglist  */
  YYSYMBOL_argument_list = 160,            /* argument_list  */
  YYSYMBOL_subscriptlist = 161,            /* subscriptlist  */
  YYSYMBOL_subscript_list = 162,           /* subscript_list  */
  YYSYMBOL_subscript = 163,                /* subscript  */
  YYSYMBOL_argument = 164,                 /* argument  */
  YYSYMBOL_optional_test = 165,            /* optional_test  */
  YYSYMBOL_comp_iter = 166,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 167,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 168,                 /* comp_for  */
  YYSYMBOL_comp_if = 169,                  /* comp_if  */
  YYSYMBOL_test_nocond = 170,              /* test_nocond  */
  YYSYMBOL_or_test = 171,                  /* or_test  */
  YYSYMBOL_or_and_test_star = 172,         /* or_and_test_star  */
  YYSYMBOL_and_test = 173,                 /* and_test  */
  YYSYMBOL_and_not_test_star = 174,        /* and_not_test_star  */
  YYSYMBOL_not_test = 175,                 /* not_test  */
  YYSYMBOL_comparison = 176,               /* comparison  */
  YYSYMBOL_comp_op_expr_plus = 177,        /* comp_op_expr_plus  */
  YYSYMBOL_comp_op = 178,                  /* comp_op  */
  YYSYMBOL_exprlist = 179,                 /* exprlist  */
  YYSYMBOL_expr_star_expr_option = 180,    /* expr_star_expr_option  */
  YYSYMBOL_expr_star_expr_option_list = 181, /* expr_star_expr_option_list  */
  YYSYMBOL_testlist_comp = 182,            /* testlist_comp  */
  YYSYMBOL_namedexpr_test_star_expr_option_list = 183, /* namedexpr_test_star_expr_option_list  */
  YYSYMBOL_namedexpr_test_star_expr_option = 184, /* namedexpr_test_star_expr_option  */
  YYSYMBOL_namedexpr_test = 185,           /* namedexpr_test  */
  YYSYMBOL_test = 186,                     /* test  */
  YYSYMBOL_atom = 187,                     /* atom  */
  YYSYMBOL_number = 188,                   /* number  */
  YYSYMBOL_string_plus = 189               /* string_plus  */
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
#define YYFINAL  108
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   799

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   348


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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    26,    26,    27,    28,    31,    32,    35,    36,    37,
      38,    39,    40,    41,    44,    45,    48,    49,    52,    53,
      56,    57,    60,    61,    64,    65,    68,    69,    72,    73,
      74,    75,    78,    80,    81,    82,    86,    87,    97,    98,
     102,   105,   108,   110,   111,   123,   150,   151,   152,   155,
     156,   158,   159,   162,   163,   166,   169,   170,   171,   182,
     183,   184,   185,   186,   189,   190,   191,   192,   195,   197,
     199,   200,   203,   204,   205,   208,   210,   212,   213,   216,
     217,   220,   221,   222,   223,   226,   228,   229,   230,   240,
     242,   245,   246,   249,   250,   253,   254,   255,   256,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   283,   283,
     283,   283,   285,   287,   289,   290,   293,   295,   296,   299,
     301,   302,   305,   307,   308,   309,   312,   314,   315,   316,
     319,   321,   322,   325,   326,   327,   328,   329,   332,   333,
     334,   335,   338,   339,   342,   343,   346,   347,   357,   358,
     359,   360,   361,   365,   367,   368,   369,   372,   373,   376,
     377,   380,   381,   384,   385,   389,   390,   394,   395,   396,
     397,   398,   401,   402,   405,   406,   409,   410,   414,   415,
     418,   419,   422,   424,   426,   427,   430,   432,   433,   436,
     437,   441,   442,   445,   446,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   471,   474,   475,   478,   479,
     480,   483,   484,   487,   488,   489,   492,   493,   496,   498,
     499,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   516,   517,   520,   521
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
  "CURLY_CLOSE", "DOT", "ARROW", "DOUBLE_EQUAL", "NE", "LT", "GT", "LE",
  "GE", "IN", "IS", "IF", "ELSE", "AND", "OR", "NOT", "TYPE_HINT",
  "FUNC_TYPE_HINT", "ADD_EQUAL", "SUB_EQUAL", "MUL_EQUAL", "AT_EQUAL",
  "DIV_EQUAL", "MOD_EQUAL", "BITWISE_AND_EQUAL", "BITWISE_OR_EQUAL",
  "BITWISE_XOR_EQUAL", "SHIFT_LEFT_EQUAL", "SHIFT_RIGHT_EQUAL",
  "POW_EQUAL", "FLOOR_DIV_EQUAL", "$accept", "file_input", "stmt",
  "compound_stmt", "async_stmt", "if_stmt",
  "elif_namedexpr_test_colon_suite_star", "while_stmt", "for_stmt",
  "try_stmt", "except_clause_colon_suite", "try_stmt_options",
  "except_clause", "test_as_name_optional", "funcdef", "parameters",
  "typedlist_argument", "typedlist_arguments",
  "comma_option_argument_star", "typedarglist", "tfpdef",
  "func_body_suite", "suite", "stmt_plus", "simple_stmt",
  "semi_colon_small_stmt_star", "small_stmt", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "raise_stmt", "global_stmt",
  "nonlocal_stmt", "comma_name_star", "assert_stmt", "expr_stmt",
  "testlist", "symbol_test_star", "expr_stmt_option1_plus", "annassign",
  "testlist_star_expr", "testlist_star_expr_option1_star", "augassign",
  "expr", "star_expr", "symbol_xor_expr_star", "xor_expr",
  "symbol_and_expr_star", "and_expr", "symbol_shift_expr_star",
  "shift_expr", "shift_arith_expr_star", "arith_expr", "symbol_term_star",
  "term", "symbol_factor_star", "symbol_factor", "factor", "power",
  "atom_expr", "trailer_star", "trailer", "classdef",
  "bracket_arglist_optional", "arglist", "argument_list", "subscriptlist",
  "subscript_list", "subscript", "argument", "optional_test", "comp_iter",
  "sync_comp_for", "comp_for", "comp_if", "test_nocond", "or_test",
  "or_and_test_star", "and_test", "and_not_test_star", "not_test",
  "comparison", "comp_op_expr_plus", "comp_op", "exprlist",
  "expr_star_expr_option", "expr_star_expr_option_list", "testlist_comp",
  "namedexpr_test_star_expr_option_list",
  "namedexpr_test_star_expr_option", "namedexpr_test", "test", "atom",
  "number", "string_plus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-269)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-174)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,    67,   -43,   177,    16,  -269,  -269,  -269,  -269,   662,
      35,   601,  -269,   712,   -12,    39,    44,   662,   662,    66,
    -269,  -269,    48,   723,   723,   723,   723,   522,   533,    26,
     662,   662,    93,    67,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,    38,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,   706,   139,    46,    51,    58,    72,    17,    11,
       7,  -269,    84,  -269,    52,    53,    55,  -269,    46,   -21,
    -269,  -269,  -269,  -269,   -21,  -269,  -269,   119,    74,  -269,
    -269,  -269,    61,    81,  -269,   218,    79,    85,    82,  -269,
      86,    85,  -269,  -269,  -269,  -269,  -269,  -269,  -269,    90,
    -269,    15,  -269,  -269,    83,  -269,    94,  -269,  -269,  -269,
     411,   147,   601,   662,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,   662,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,    76,    89,  -269,
     723,   601,  -269,   723,  -269,   723,  -269,   723,  -269,   723,
     723,  -269,   723,   723,  -269,   723,   723,   723,   723,   723,
    -269,     7,   723,   662,   662,  -269,   662,  -269,  -269,   461,
     662,   148,  -269,   -21,  -269,   662,   472,   100,   662,   712,
     152,    31,  -269,    24,   -24,   151,  -269,   218,   662,  -269,
    -269,   140,   712,   601,  -269,  -269,  -269,   218,    38,  -269,
     118,   120,  -269,   113,  -269,  -269,   139,    46,    46,    51,
      58,    72,    17,    17,    11,    11,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,    95,    53,    55,   662,   662,  -269,   114,
     128,  -269,    13,   111,   129,  -269,   133,   146,   106,  -269,
    -269,  -269,   115,   218,   160,  -269,   359,   662,   162,     2,
     165,   -22,  -269,  -269,  -269,   136,   157,   307,   167,    85,
     149,  -269,  -269,   154,  -269,   173,   220,  -269,  -269,   601,
     662,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,   662,  -269,  -269,  -269,  -269,  -269,   590,   662,
    -269,  -269,   651,   662,  -269,  -269,  -269,   218,   359,   222,
    -269,   206,   218,   187,   188,  -269,   218,   662,  -269,   191,
    -269,   662,   242,  -269,  -269,   307,  -269,   193,   662,   662,
     176,  -269,   113,  -269,  -269,  -269,  -269,  -269,  -269,   178,
    -269,  -269,   251,  -269,   218,   218,   240,  -269,   258,  -269,
     359,  -269,   218,    10,   210,   211,  -269,   212,  -269,  -269,
     247,  -269,  -269,   265,  -269,   662,  -269,  -269,  -269,   218,
     218,   218,   216,  -269,    10,  -269,   220,  -269,  -269,   218,
    -269,  -269,  -269
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     4,   226,     0,     0,   230,   231,   232,    68,    72,
       0,    71,    69,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     6,    13,     7,     8,     9,    10,
      11,     5,    58,    60,    64,    65,    66,    67,    61,    62,
      63,    59,    83,   192,    98,   115,   118,   121,   123,   127,
     131,   141,   142,    12,   219,   185,   188,   190,    98,   147,
     228,   229,     2,   227,   147,    15,    14,    73,   156,    70,
     206,   207,     0,   210,   205,     0,     0,    78,     0,   218,
      80,    78,   235,   113,   138,   139,   140,   222,   217,     0,
     212,   215,   216,   224,     0,   225,     0,   189,     1,     3,
      57,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    84,    81,     0,
     197,   200,   195,   196,   199,   198,   201,   203,     0,   191,
       0,    97,    94,     0,   112,     0,   116,     0,   119,     0,
       0,   122,     0,     0,   126,     0,     0,     0,     0,     0,
     130,   131,     0,     0,     0,   183,     0,   186,    93,     0,
     173,     0,   145,   147,   144,     0,     0,     0,     0,   209,
       0,     0,    51,     0,     0,     0,    76,     0,     0,    75,
     221,     0,     0,   214,   178,   211,   223,     0,    58,    55,
      90,    91,    82,    88,   204,   202,   194,    98,    98,   115,
     118,   121,   123,   123,   127,   127,   136,   135,   133,   137,
     134,   132,   143,     0,   185,   188,     0,     0,   149,     0,
     158,   160,   167,     0,   162,   164,     0,   165,   152,   146,
      74,   154,     0,     0,     0,   208,     0,    35,     0,    31,
       0,    46,    39,    44,    45,     0,    40,     0,     0,    78,
      21,    79,   179,     0,   213,   215,    19,    56,    89,     0,
      87,    85,   193,    96,    95,   114,   117,   120,   124,   125,
     128,   129,     0,   184,   187,   170,   171,   148,   157,     0,
     168,   150,   161,   173,   151,   155,   153,     0,    54,     0,
      32,    33,     0,     0,     0,    25,     0,     0,    47,    42,
      38,     0,     0,    37,    49,     0,    77,     0,     0,     0,
      17,    92,    88,   220,   159,   169,   163,   166,   172,    23,
      53,    52,     0,    24,     0,     0,    27,    48,     0,    41,
       0,    36,     0,   176,     0,     0,    86,     0,    34,    30,
      29,    26,    43,     0,    20,     0,   177,   174,   175,     0,
       0,     0,     0,    50,   180,   182,    19,    16,    22,     0,
     181,    18,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -269,    25,  -228,  -269,  -269,  -269,   -93,  -269,   270,  -269,
     -59,  -269,  -269,  -269,   275,  -269,   -55,  -269,  -269,  -269,
    -269,   -31,  -182,  -268,     0,    91,   180,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,   -83,  -269,  -269,   109,   -34,    92,
    -269,    -5,   -61,  -269,    -4,     1,    88,   150,    96,   156,
      80,   155,  -150,   -74,  -101,   -35,   134,  -269,    42,  -269,
    -269,   -57,  -269,  -269,  -269,   123,  -269,  -269,  -269,    18,
       6,    14,   -56,   112,   -89,  -269,  -269,  -159,    99,   145,
     101,   -18,  -269,   107,  -269,   124,  -269,   138,   291,   131,
     135,   -14,    -7,   326,  -269,   310
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,    36,   320,    37,    38,    39,
     249,   305,   250,   300,    40,   184,   253,   254,   309,   255,
     256,   313,   181,   299,   182,   111,    42,    43,    44,    45,
      46,    47,    48,    49,   186,    50,    51,   202,   271,   127,
     128,    52,   142,   129,    53,    54,   144,    55,   146,    56,
     148,    57,   151,    58,   154,    59,   160,   161,    60,    61,
      62,   172,   173,    63,   177,   229,   230,   233,   234,   235,
     231,   236,   356,   194,   357,   358,   364,    64,   165,    65,
     167,    66,    67,   139,   140,    82,    83,    84,    99,   100,
     101,   102,    68,    69,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    41,    77,    88,   223,   260,    79,   168,   189,    80,
      89,    90,   195,   107,    81,   266,   106,   174,   298,    93,
      89,    89,   191,    89,   303,   191,    72,   191,    98,    98,
     330,   251,   257,    41,   307,   192,    73,   169,   192,   170,
     192,    13,    78,   171,    85,    15,    86,   155,   156,   157,
     247,    87,   158,   248,   152,   153,   258,   308,   109,   289,
     159,   296,   278,   279,   149,   150,    94,    95,    96,   193,
     298,     1,   353,    91,     2,   212,   213,   304,     3,     4,
       5,     6,     7,   252,   355,     8,    22,     9,    10,   105,
      11,    12,    13,   108,    14,   110,    15,    16,    17,    18,
     141,    19,   143,    20,    21,    22,   201,   200,   145,    23,
      24,    25,   298,   280,   281,   329,   239,   214,   215,    26,
     333,   147,   203,   162,   336,    27,   163,    28,   175,    29,
     164,   166,   176,   178,   208,   179,   206,   183,   187,   185,
     188,    30,   207,   290,   196,    31,   273,   274,   225,   190,
     197,   199,   349,   350,   204,   238,   243,   246,   259,   343,
     354,   205,   232,   237,   112,   192,   269,   270,   240,   232,
     282,   203,   291,   287,   295,    80,   316,   366,   367,   368,
      81,   261,   288,   292,     2,   294,    89,   372,    80,   293,
       5,     6,     7,    81,    98,   310,   365,   216,   217,   218,
     219,   220,  -172,   311,   222,   130,   131,   132,   133,   134,
     135,   136,   137,    20,    21,    22,   297,   138,   302,   285,
     286,   306,   180,   315,   317,     2,   318,   193,   331,     3,
     319,     5,     6,     7,   332,    27,     8,    28,     9,    29,
     301,    11,    12,   334,   335,   338,    41,   340,    16,   342,
      18,   345,    19,   347,    20,    21,    22,   314,   348,   247,
      23,    24,    25,   322,   321,   251,   359,   360,   361,   362,
      26,   363,   369,   371,    75,   323,    27,   351,    28,    76,
      29,   232,   325,   352,   341,   237,   328,   244,   346,   267,
     198,   277,   268,   209,   324,   221,    31,   275,    41,   242,
     337,   210,   211,   262,   339,   344,   276,   327,   370,   224,
     326,   312,    89,   272,     2,   314,   263,   245,     3,   104,
       5,     6,     7,   283,   264,     8,   284,     9,   265,    74,
      11,    12,    92,     0,     0,     0,     0,    16,     0,    18,
      41,    19,     0,    20,    21,    22,     0,     0,     0,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    27,     2,    28,     0,    29,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     9,
      10,     0,    11,    12,    13,    31,    14,     0,    15,    16,
      17,    18,     0,    19,     0,    20,    21,    22,     0,     0,
       0,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    27,     2,    28,
       0,    29,     3,     0,     5,     6,     7,     0,     0,     8,
       0,     9,     0,    30,    11,    12,     0,    31,     0,     0,
       0,    16,     0,    18,     0,    19,     0,    20,    21,    22,
       0,     0,     0,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     2,    27,
       0,    28,     3,    29,     5,     6,     7,     0,     0,     2,
       0,     0,     0,     3,     0,     5,     6,     7,     0,    31,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
     226,     0,     0,   227,    24,    25,     0,     0,    20,    21,
      22,   226,     0,    26,   227,    24,    25,     0,     0,    27,
     228,    28,     0,    29,    26,     0,     0,     0,     0,     2,
      27,   241,    28,     3,    29,     5,     6,     7,     0,    31,
       2,     0,     0,     0,     3,     0,     5,     6,     7,     0,
      31,     0,     0,     0,     0,     0,     0,     0,    20,    21,
      22,     0,     0,     0,    23,    24,    25,     0,     0,    20,
      21,    22,     0,     0,    26,    23,    24,    25,     0,     0,
      27,    97,    28,     0,    29,    26,     0,     0,     0,     0,
       0,    27,     0,    28,   103,    29,     0,     2,     0,     0,
      31,     3,     0,     5,     6,     7,     0,     0,     2,     0,
       0,    31,     3,     0,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,    22,   226,
       0,     0,   227,    24,    25,     0,     0,    20,    21,    22,
       0,     0,    26,    23,    24,    25,     0,     0,    27,     0,
      28,     0,    29,    26,     0,     0,     0,     0,     2,    27,
       0,    28,     3,    29,     5,     6,     7,     0,    31,     2,
       0,     0,     0,     3,     0,     5,     6,     7,     0,    31,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
       0,     0,     0,     0,    24,    25,     0,     0,    20,    21,
      22,     0,     0,    26,     0,    24,    25,  -173,     0,    27,
       0,    28,     0,    29,    26,     0,     0,     0,     0,     2,
      27,     0,    28,     3,    29,     5,     6,     7,     0,    31,
       2,     0,     0,     0,     3,     0,     5,     6,     7,     0,
      31,     0,     0,     0,     0,     0,     0,     0,    20,    21,
      22,     0,   112,     0,    23,    24,    25,     0,     0,    20,
      21,    22,   113,     0,    26,     0,    24,    25,     0,     0,
      27,     0,    28,     0,    29,    26,     0,     0,     0,     0,
       0,    27,     0,    28,     0,    29,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
       0,     1,     9,    17,   163,   187,    11,    68,    91,    13,
      17,    18,   101,    31,    13,   197,    30,    74,   246,    23,
      27,    28,    12,    30,    22,    12,     1,    12,    27,    28,
     298,     7,    56,    33,    56,    25,    79,    58,    25,    60,
      25,    25,     7,    64,    56,    29,     7,    40,    41,    42,
      19,     7,    45,    22,    43,    44,    80,    79,    33,    46,
      53,   243,   212,   213,    47,    48,    24,    25,    26,    54,
     298,     4,   340,     7,     7,   149,   150,    75,    11,    12,
      13,    14,    15,    59,    74,    18,    38,    20,    21,    63,
      23,    24,    25,     0,    27,    57,    29,    30,    31,    32,
      54,    34,    51,    36,    37,    38,   113,   112,    50,    42,
      43,    44,   340,   214,   215,   297,   173,   152,   153,    52,
     302,    49,   129,    39,   306,    58,    74,    60,     9,    62,
      77,    76,    58,    72,   141,    54,   140,    58,    56,    54,
      54,    74,   141,   232,    61,    78,   207,   208,   166,    59,
      56,     4,   334,   335,    78,     7,    56,     5,     7,   318,
     342,    72,   169,   170,    46,    25,    46,    54,   175,   176,
      75,   178,    61,    59,    59,   179,   259,   359,   360,   361,
     179,   188,    54,    54,     7,    79,   193,   369,   192,    56,
      13,    14,    15,   192,   193,    59,   355,   155,   156,   157,
     158,   159,    56,    46,   162,    66,    67,    68,    69,    70,
      71,    72,    73,    36,    37,    38,    56,    78,    56,   226,
     227,    56,     4,    56,    75,     7,    72,    54,     6,    11,
      10,    13,    14,    15,    28,    58,    18,    60,    20,    62,
     247,    23,    24,    56,    56,    54,   246,     5,    30,    56,
      32,    75,    34,    75,    36,    37,    38,   257,     7,    19,
      42,    43,    44,   270,   269,     7,    56,    56,    56,    22,
      52,     6,    56,   366,     4,   282,    58,   336,    60,     4,
      62,   288,   289,   338,   315,   292,   293,   178,   322,   198,
     110,   211,   200,   143,   288,   161,    78,   209,   298,   176,
     307,   145,   147,   191,   311,   319,   210,   293,   364,   164,
     292,     4,   319,   206,     7,   315,   192,   179,    11,    28,
      13,    14,    15,   224,   193,    18,   225,    20,   193,     3,
      23,    24,    22,    -1,    -1,    -1,    -1,    30,    -1,    32,
     340,    34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,     7,    60,    -1,    62,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    23,    24,    25,    78,    27,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    36,    37,    38,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    58,     7,    60,
      -1,    62,    11,    -1,    13,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    74,    23,    24,    -1,    78,    -1,    -1,
      -1,    30,    -1,    32,    -1,    34,    -1,    36,    37,    38,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,     7,    58,
      -1,    60,    11,    62,    13,    14,    15,    -1,    -1,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    -1,    -1,    42,    43,    44,    -1,    -1,    36,    37,
      38,    39,    -1,    52,    42,    43,    44,    -1,    -1,    58,
      59,    60,    -1,    62,    52,    -1,    -1,    -1,    -1,     7,
      58,    59,    60,    11,    62,    13,    14,    15,    -1,    78,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    36,
      37,    38,    -1,    -1,    52,    42,    43,    44,    -1,    -1,
      58,    59,    60,    -1,    62,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    61,    62,    -1,     7,    -1,    -1,
      78,    11,    -1,    13,    14,    15,    -1,    -1,     7,    -1,
      -1,    78,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    36,    37,    38,
      -1,    -1,    52,    42,    43,    44,    -1,    -1,    58,    -1,
      60,    -1,    62,    52,    -1,    -1,    -1,    -1,     7,    58,
      -1,    60,    11,    62,    13,    14,    15,    -1,    78,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    36,    37,
      38,    -1,    -1,    52,    -1,    43,    44,    56,    -1,    58,
      -1,    60,    -1,    62,    52,    -1,    -1,    -1,    -1,     7,
      58,    -1,    60,    11,    62,    13,    14,    15,    -1,    78,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    46,    -1,    42,    43,    44,    -1,    -1,    36,
      37,    38,    56,    -1,    52,    -1,    43,    44,    -1,    -1,
      58,    -1,    60,    -1,    62,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    -1,    62,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,    11,    12,    13,    14,    15,    18,    20,
      21,    23,    24,    25,    27,    29,    30,    31,    32,    34,
      36,    37,    38,    42,    43,    44,    52,    58,    60,    62,
      74,    78,    95,    96,    97,    98,    99,   101,   102,   103,
     108,   118,   120,   121,   122,   123,   124,   125,   126,   127,
     129,   130,   135,   138,   139,   141,   143,   145,   147,   149,
     152,   153,   154,   157,   171,   173,   175,   176,   186,   187,
     188,   189,    95,    79,   187,   102,   108,   186,     7,   135,
     138,   139,   179,   180,   181,    56,     7,     7,   185,   186,
     186,     7,   189,   138,   152,   152,   152,    59,   139,   182,
     183,   184,   185,    61,   182,    63,   185,   175,     0,    95,
      57,   119,    46,    56,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,   133,   134,   137,
      66,    67,    68,    69,    70,    71,    72,    73,    78,   177,
     178,    54,   136,    51,   140,    50,   142,    49,   144,    47,
      48,   146,    43,    44,   148,    40,    41,    42,    45,    53,
     150,   151,    39,    74,    77,   172,    76,   174,   136,    58,
      60,    64,   155,   156,   155,     9,    58,   158,    72,    54,
       4,   116,   118,    58,   109,    54,   128,    56,    54,   128,
      59,    12,    25,    54,   167,   168,    61,    56,   120,     4,
     135,   186,   131,   186,    78,    72,   138,   139,   186,   141,
     143,   145,   147,   147,   149,   149,   152,   152,   152,   152,
     152,   150,   152,   171,   173,   175,    39,    42,    59,   159,
     160,   164,   186,   161,   162,   163,   165,   186,     7,   155,
     186,    59,   159,    56,   131,   181,     5,    19,    22,   104,
     106,     7,    59,   110,   111,   113,   114,    56,    80,     7,
     116,   186,   167,   179,   183,   184,   116,   119,   133,    46,
      54,   132,   177,   136,   136,   140,   142,   144,   146,   146,
     148,   148,    75,   172,   174,   186,   186,    59,    54,    46,
     168,    61,    54,    56,    79,    59,   116,    56,    96,   117,
     107,   186,    56,    22,    75,   105,    56,    56,    79,   112,
      59,    46,     4,   115,   118,    56,   128,    75,    72,    10,
     100,   135,   186,   186,   164,   186,   163,   165,   186,   116,
     117,     6,    28,   116,    56,    56,   116,   186,    54,   186,
       5,   115,    56,   171,   185,    75,   132,    75,     7,   116,
     116,   104,   110,   117,   116,    74,   166,   168,   169,    56,
      56,    56,    22,     6,   170,   171,   116,   116,   116,    56,
     166,   100,   116
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   106,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   112,   112,   113,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   119,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   122,   123,
     124,   124,   125,   125,   125,   126,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   136,   136,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   139,   140,   140,   141,   142,   142,   143,
     144,   144,   145,   146,   146,   146,   147,   148,   148,   148,
     149,   150,   150,   151,   151,   151,   151,   151,   152,   152,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   156,   157,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   171,   172,   172,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   179,   180,   180,   181,   181,
     181,   182,   182,   183,   183,   183,   184,   184,   185,   186,
     186,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   188,   188,   189,   189
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     8,     5,     5,     0,
       7,     4,     9,     6,     6,     5,     4,     3,     6,     3,
       3,     0,     2,     1,     3,     0,     6,     5,     3,     2,
       1,     3,     2,     3,     0,     1,     1,     2,     3,     1,
       4,     1,     4,     2,     1,     3,     3,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     4,     3,     3,     3,     0,     4,
       2,     2,     3,     1,     2,     2,     3,     1,     0,     3,
       2,     2,     4,     2,     2,     3,     3,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     0,     2,     3,     0,     2,
       3,     0,     2,     0,     3,     3,     2,     0,     3,     3,
       2,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     3,     3,     2,     2,     0,     3,     2,
       3,     3,     2,     5,     2,     3,     0,     2,     1,     3,
       1,     2,     1,     3,     1,     1,     3,     1,     2,     3,
       2,     2,     1,     0,     1,     1,     4,     5,     1,     2,
       2,     3,     1,     2,     3,     0,     2,     3,     0,     2,
       1,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     3,     2,
       1,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       5,     3,     2,     3,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1
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
  case 37: /* funcdef: DEF NAME parameters COLON func_body_suite  */
#line 87 "test.y"
                                                  {cout<<"line 84";}
#line 1646 "test.tab.c"
    break;

  case 40: /* typedlist_argument: tfpdef  */
#line 102 "test.y"
                            {cout<<"line 99"<<endl;}
#line 1652 "test.tab.c"
    break;

  case 41: /* typedlist_argument: tfpdef EQUAL test  */
#line 105 "test.y"
                          {cout << "yes";}
#line 1658 "test.tab.c"
    break;

  case 46: /* tfpdef: NAME  */
#line 150 "test.y"
             {cout<<"tfpdef is first used here";}
#line 1664 "test.tab.c"
    break;

  case 47: /* tfpdef: NAME TYPE_HINT  */
#line 151 "test.y"
                     {cout<<"tfpdef is begin used here";}
#line 1670 "test.tab.c"
    break;

  case 48: /* tfpdef: NAME COLON test  */
#line 152 "test.y"
                      {cout<<"tfpdef is begin used here";}
#line 1676 "test.tab.c"
    break;


#line 1680 "test.tab.c"

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

#line 527 "test.y"


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
