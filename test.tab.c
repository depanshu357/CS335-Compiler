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
    #include "data.h"
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    extern stack<int> indent_stack;
    NODE *start_node;
	fstream fout;
	extern FILE *yyin;

    


#line 87 "test.tab.c"

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
  YYSYMBOL_NAME = 5,                       /* NAME  */
  YYSYMBOL_YIELD = 6,                      /* YIELD  */
  YYSYMBOL_FROM = 7,                       /* FROM  */
  YYSYMBOL_ELIF = 8,                       /* ELIF  */
  YYSYMBOL_AWAIT = 9,                      /* AWAIT  */
  YYSYMBOL_ASYNC = 10,                     /* ASYNC  */
  YYSYMBOL_TRUE = 11,                      /* TRUE  */
  YYSYMBOL_FALSE = 12,                     /* FALSE  */
  YYSYMBOL_NONE = 13,                      /* NONE  */
  YYSYMBOL_IMPORT = 14,                    /* IMPORT  */
  YYSYMBOL_PASS = 15,                      /* PASS  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_EXCEPT = 17,                    /* EXCEPT  */
  YYSYMBOL_RAISE = 18,                     /* RAISE  */
  YYSYMBOL_CLASS = 19,                     /* CLASS  */
  YYSYMBOL_FINALLY = 20,                   /* FINALLY  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 22,                  /* CONTINUE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_LAMBDA = 24,                    /* LAMBDA  */
  YYSYMBOL_TRY = 25,                       /* TRY  */
  YYSYMBOL_AS = 26,                        /* AS  */
  YYSYMBOL_DEF = 27,                       /* DEF  */
  YYSYMBOL_NONLOCAL = 28,                  /* NONLOCAL  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_ASSERT = 30,                    /* ASSERT  */
  YYSYMBOL_DEL = 31,                       /* DEL  */
  YYSYMBOL_GLOBAL = 32,                    /* GLOBAL  */
  YYSYMBOL_WITH = 33,                      /* WITH  */
  YYSYMBOL_INTEGER = 34,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_STRING = 36,                    /* STRING  */
  YYSYMBOL_POW = 37,                       /* POW  */
  YYSYMBOL_FLOOR_DIV = 38,                 /* FLOOR_DIV  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_MUL = 40,                       /* MUL  */
  YYSYMBOL_ADD = 41,                       /* ADD  */
  YYSYMBOL_SUB = 42,                       /* SUB  */
  YYSYMBOL_MOD = 43,                       /* MOD  */
  YYSYMBOL_EQUAL = 44,                     /* EQUAL  */
  YYSYMBOL_SHIFT_LEFT = 45,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 46,               /* SHIFT_RIGHT  */
  YYSYMBOL_BITWISE_AND = 47,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_XOR = 48,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_OR = 49,                /* BITWISE_OR  */
  YYSYMBOL_TILDE = 50,                     /* TILDE  */
  YYSYMBOL_AT = 51,                        /* AT  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_WAL_OP = 53,                    /* WAL_OP  */
  YYSYMBOL_COLON = 54,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 55,                /* SEMI_COLON  */
  YYSYMBOL_SMALL_OPEN = 56,                /* SMALL_OPEN  */
  YYSYMBOL_SMALL_CLOSE = 57,               /* SMALL_CLOSE  */
  YYSYMBOL_BOX_OPEN = 58,                  /* BOX_OPEN  */
  YYSYMBOL_BOX_CLOSE = 59,                 /* BOX_CLOSE  */
  YYSYMBOL_CURLY_OPEN = 60,                /* CURLY_OPEN  */
  YYSYMBOL_CURLY_CLOSE = 61,               /* CURLY_CLOSE  */
  YYSYMBOL_DOT = 62,                       /* DOT  */
  YYSYMBOL_ARROW = 63,                     /* ARROW  */
  YYSYMBOL_DOUBLE_EQUAL = 64,              /* DOUBLE_EQUAL  */
  YYSYMBOL_NE = 65,                        /* NE  */
  YYSYMBOL_LT = 66,                        /* LT  */
  YYSYMBOL_GT = 67,                        /* GT  */
  YYSYMBOL_LE = 68,                        /* LE  */
  YYSYMBOL_GE = 69,                        /* GE  */
  YYSYMBOL_IN = 70,                        /* IN  */
  YYSYMBOL_IS = 71,                        /* IS  */
  YYSYMBOL_IF = 72,                        /* IF  */
  YYSYMBOL_ELSE = 73,                      /* ELSE  */
  YYSYMBOL_AND = 74,                       /* AND  */
  YYSYMBOL_OR = 75,                        /* OR  */
  YYSYMBOL_NOT = 76,                       /* NOT  */
  YYSYMBOL_TYPE_HINT = 77,                 /* TYPE_HINT  */
  YYSYMBOL_FUNC_TYPE_HINT = 78,            /* FUNC_TYPE_HINT  */
  YYSYMBOL_ADD_EQUAL = 79,                 /* ADD_EQUAL  */
  YYSYMBOL_SUB_EQUAL = 80,                 /* SUB_EQUAL  */
  YYSYMBOL_MUL_EQUAL = 81,                 /* MUL_EQUAL  */
  YYSYMBOL_AT_EQUAL = 82,                  /* AT_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 83,                 /* DIV_EQUAL  */
  YYSYMBOL_MOD_EQUAL = 84,                 /* MOD_EQUAL  */
  YYSYMBOL_BITWISE_AND_EQUAL = 85,         /* BITWISE_AND_EQUAL  */
  YYSYMBOL_BITWISE_OR_EQUAL = 86,          /* BITWISE_OR_EQUAL  */
  YYSYMBOL_BITWISE_XOR_EQUAL = 87,         /* BITWISE_XOR_EQUAL  */
  YYSYMBOL_SHIFT_LEFT_EQUAL = 88,          /* SHIFT_LEFT_EQUAL  */
  YYSYMBOL_SHIFT_RIGHT_EQUAL = 89,         /* SHIFT_RIGHT_EQUAL  */
  YYSYMBOL_POW_EQUAL = 90,                 /* POW_EQUAL  */
  YYSYMBOL_FLOOR_DIV_EQUAL = 91,           /* FLOOR_DIV_EQUAL  */
  YYSYMBOL_INDENT = 92,                    /* INDENT  */
  YYSYMBOL_DEDENT = 93,                    /* DEDENT  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_start = 95,                     /* start  */
  YYSYMBOL_file_input = 96,                /* file_input  */
  YYSYMBOL_stmt = 97,                      /* stmt  */
  YYSYMBOL_compound_stmt = 98,             /* compound_stmt  */
  YYSYMBOL_async_stmt = 99,                /* async_stmt  */
  YYSYMBOL_if_stmt = 100,                  /* if_stmt  */
  YYSYMBOL_elif_namedexpr_test_colon_suite_star = 101, /* elif_namedexpr_test_colon_suite_star  */
  YYSYMBOL_while_stmt = 102,               /* while_stmt  */
  YYSYMBOL_for_stmt = 103,                 /* for_stmt  */
  YYSYMBOL_try_stmt = 104,                 /* try_stmt  */
  YYSYMBOL_except_clause_colon_suite = 105, /* except_clause_colon_suite  */
  YYSYMBOL_try_stmt_options = 106,         /* try_stmt_options  */
  YYSYMBOL_except_clause = 107,            /* except_clause  */
  YYSYMBOL_test_as_name_optional = 108,    /* test_as_name_optional  */
  YYSYMBOL_funcdef = 109,                  /* funcdef  */
  YYSYMBOL_parameters = 110,               /* parameters  */
  YYSYMBOL_typedlist_argument = 111,       /* typedlist_argument  */
  YYSYMBOL_typedlist_arguments = 112,      /* typedlist_arguments  */
  YYSYMBOL_comma_option_argument_star = 113, /* comma_option_argument_star  */
  YYSYMBOL_typedarglist = 114,             /* typedarglist  */
  YYSYMBOL_tfpdef = 115,                   /* tfpdef  */
  YYSYMBOL_func_body_suite = 116,          /* func_body_suite  */
  YYSYMBOL_suite = 117,                    /* suite  */
  YYSYMBOL_stmt_plus = 118,                /* stmt_plus  */
  YYSYMBOL_simple_stmt = 119,              /* simple_stmt  */
  YYSYMBOL_semi_colon_small_stmt_star = 120, /* semi_colon_small_stmt_star  */
  YYSYMBOL_small_stmt = 121,               /* small_stmt  */
  YYSYMBOL_flow_stmt = 122,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 123,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 124,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 125,              /* return_stmt  */
  YYSYMBOL_raise_stmt = 126,               /* raise_stmt  */
  YYSYMBOL_global_stmt = 127,              /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 128,            /* nonlocal_stmt  */
  YYSYMBOL_comma_name_star = 129,          /* comma_name_star  */
  YYSYMBOL_assert_stmt = 130,              /* assert_stmt  */
  YYSYMBOL_expr_stmt = 131,                /* expr_stmt  */
  YYSYMBOL_testlist = 132,                 /* testlist  */
  YYSYMBOL_symbol_test_star = 133,         /* symbol_test_star  */
  YYSYMBOL_expr_stmt_option1_plus = 134,   /* expr_stmt_option1_plus  */
  YYSYMBOL_annassign = 135,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 136,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_option1_star = 137, /* testlist_star_expr_option1_star  */
  YYSYMBOL_augassign = 138,                /* augassign  */
  YYSYMBOL_expr = 139,                     /* expr  */
  YYSYMBOL_star_expr = 140,                /* star_expr  */
  YYSYMBOL_symbol_xor_expr_star = 141,     /* symbol_xor_expr_star  */
  YYSYMBOL_xor_expr = 142,                 /* xor_expr  */
  YYSYMBOL_symbol_and_expr_star = 143,     /* symbol_and_expr_star  */
  YYSYMBOL_and_expr = 144,                 /* and_expr  */
  YYSYMBOL_symbol_shift_expr_star = 145,   /* symbol_shift_expr_star  */
  YYSYMBOL_shift_expr = 146,               /* shift_expr  */
  YYSYMBOL_shift_arith_expr_star = 147,    /* shift_arith_expr_star  */
  YYSYMBOL_arith_expr = 148,               /* arith_expr  */
  YYSYMBOL_symbol_term_star = 149,         /* symbol_term_star  */
  YYSYMBOL_term = 150,                     /* term  */
  YYSYMBOL_symbol_factor_star = 151,       /* symbol_factor_star  */
  YYSYMBOL_symbol_factor = 152,            /* symbol_factor  */
  YYSYMBOL_factor = 153,                   /* factor  */
  YYSYMBOL_power = 154,                    /* power  */
  YYSYMBOL_atom_expr = 155,                /* atom_expr  */
  YYSYMBOL_trailer_star = 156,             /* trailer_star  */
  YYSYMBOL_trailer = 157,                  /* trailer  */
  YYSYMBOL_classdef = 158,                 /* classdef  */
  YYSYMBOL_bracket_arglist_optional = 159, /* bracket_arglist_optional  */
  YYSYMBOL_arglist = 160,                  /* arglist  */
  YYSYMBOL_argument_list = 161,            /* argument_list  */
  YYSYMBOL_subscriptlist = 162,            /* subscriptlist  */
  YYSYMBOL_subscript_list = 163,           /* subscript_list  */
  YYSYMBOL_subscript = 164,                /* subscript  */
  YYSYMBOL_argument = 165,                 /* argument  */
  YYSYMBOL_optional_test = 166,            /* optional_test  */
  YYSYMBOL_comp_iter = 167,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 168,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 169,                 /* comp_for  */
  YYSYMBOL_comp_if = 170,                  /* comp_if  */
  YYSYMBOL_test_nocond = 171,              /* test_nocond  */
  YYSYMBOL_or_test = 172,                  /* or_test  */
  YYSYMBOL_or_and_test_star = 173,         /* or_and_test_star  */
  YYSYMBOL_and_test = 174,                 /* and_test  */
  YYSYMBOL_and_not_test_star = 175,        /* and_not_test_star  */
  YYSYMBOL_not_test = 176,                 /* not_test  */
  YYSYMBOL_comparison = 177,               /* comparison  */
  YYSYMBOL_comp_op_expr_plus = 178,        /* comp_op_expr_plus  */
  YYSYMBOL_comp_op = 179,                  /* comp_op  */
  YYSYMBOL_exprlist = 180,                 /* exprlist  */
  YYSYMBOL_expr_star_expr_option = 181,    /* expr_star_expr_option  */
  YYSYMBOL_expr_star_expr_option_list = 182, /* expr_star_expr_option_list  */
  YYSYMBOL_testlist_comp = 183,            /* testlist_comp  */
  YYSYMBOL_namedexpr_test_star_expr_option_list = 184, /* namedexpr_test_star_expr_option_list  */
  YYSYMBOL_namedexpr_test_star_expr_option = 185, /* namedexpr_test_star_expr_option  */
  YYSYMBOL_namedexpr_test = 186,           /* namedexpr_test  */
  YYSYMBOL_test = 187,                     /* test  */
  YYSYMBOL_atom = 188,                     /* atom  */
  YYSYMBOL_number = 189,                   /* number  */
  YYSYMBOL_string_plus = 190               /* string_plus  */
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
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   800

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  374

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
       0,    38,    38,    41,    42,    43,    47,    48,    51,    52,
      53,    54,    55,    56,    57,    60,    61,    64,    65,    68,
      69,    72,    73,    76,    77,    80,    81,    84,    85,    88,
      89,    90,    91,    94,    96,    97,    98,   102,   103,   107,
     108,   112,   113,   116,   118,   119,   123,   126,   127,   128,
     131,   132,   134,   135,   138,   139,   142,   145,   146,   147,
     150,   151,   152,   153,   154,   157,   158,   159,   160,   163,
     165,   167,   168,   171,   172,   173,   176,   178,   180,   181,
     184,   185,   188,   189,   190,   191,   194,   196,   197,   198,
     203,   205,   208,   209,   212,   213,   216,   217,   218,   219,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   237,   239,   241,   242,   245,   247,   248,
     251,   253,   254,   257,   259,   260,   261,   264,   266,   267,
     268,   271,   273,   274,   277,   278,   279,   280,   281,   284,
     285,   286,   287,   290,   291,   294,   295,   298,   299,   303,
     304,   305,   306,   307,   311,   313,   314,   315,   318,   319,
     322,   323,   326,   327,   330,   331,   335,   336,   340,   341,
     342,   343,   344,   347,   348,   351,   352,   355,   356,   360,
     361,   364,   365,   368,   370,   372,   373,   376,   378,   379,
     382,   383,   387,   388,   391,   392,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   411,   414,   415,   418,
     419,   420,   423,   424,   428,   429,   430,   433,   434,   437,
     439,   440,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   457,   458,   461,   462
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
  "NAME", "YIELD", "FROM", "ELIF", "AWAIT", "ASYNC", "TRUE", "FALSE",
  "NONE", "IMPORT", "PASS", "BREAK", "EXCEPT", "RAISE", "CLASS", "FINALLY",
  "RETURN", "CONTINUE", "FOR", "LAMBDA", "TRY", "AS", "DEF", "NONLOCAL",
  "WHILE", "ASSERT", "DEL", "GLOBAL", "WITH", "INTEGER", "FLOAT", "STRING",
  "POW", "FLOOR_DIV", "DIV", "MUL", "ADD", "SUB", "MOD", "EQUAL",
  "SHIFT_LEFT", "SHIFT_RIGHT", "BITWISE_AND", "BITWISE_XOR", "BITWISE_OR",
  "TILDE", "AT", "COMMA", "WAL_OP", "COLON", "SEMI_COLON", "SMALL_OPEN",
  "SMALL_CLOSE", "BOX_OPEN", "BOX_CLOSE", "CURLY_OPEN", "CURLY_CLOSE",
  "DOT", "ARROW", "DOUBLE_EQUAL", "NE", "LT", "GT", "LE", "GE", "IN", "IS",
  "IF", "ELSE", "AND", "OR", "NOT", "TYPE_HINT", "FUNC_TYPE_HINT",
  "ADD_EQUAL", "SUB_EQUAL", "MUL_EQUAL", "AT_EQUAL", "DIV_EQUAL",
  "MOD_EQUAL", "BITWISE_AND_EQUAL", "BITWISE_OR_EQUAL",
  "BITWISE_XOR_EQUAL", "SHIFT_LEFT_EQUAL", "SHIFT_RIGHT_EQUAL",
  "POW_EQUAL", "FLOOR_DIV_EQUAL", "INDENT", "DEDENT", "$accept", "start",
  "file_input", "stmt", "compound_stmt", "async_stmt", "if_stmt",
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

#define YYPACT_NINF (-262)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-175)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     221,   221,   -41,   299,    59,  -262,  -262,  -262,  -262,   665,
      38,   604,  -262,   715,    46,    53,    93,   665,   665,    97,
    -262,  -262,    13,   726,   726,   726,   726,   525,   536,    45,
     665,   665,   110,  -262,   221,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,    56,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,   709,    63,    61,    65,    67,    69,   -15,
      47,     2,  -262,    81,  -262,    48,    49,    51,  -262,    61,
     -12,  -262,  -262,  -262,  -262,   -12,  -262,  -262,   114,    80,
    -262,  -262,  -262,    68,    85,  -262,    43,    84,    89,    88,
    -262,    94,    89,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
      95,  -262,    14,  -262,  -262,    86,  -262,    96,  -262,  -262,
    -262,   414,   147,   604,   665,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     665,  -262,  -262,  -262,  -262,  -262,  -262,  -262,    82,    87,
    -262,   726,   604,  -262,   726,  -262,   726,  -262,   726,  -262,
     726,   726,  -262,   726,   726,  -262,   726,   726,   726,   726,
     726,  -262,     2,   726,   665,   665,  -262,   665,  -262,  -262,
     464,   665,   151,  -262,   -12,  -262,   665,   475,   106,   665,
     715,    73,    70,  -262,    17,     3,   156,  -262,    43,   665,
    -262,  -262,   143,   715,   604,  -262,  -262,  -262,    43,    56,
    -262,   123,   124,  -262,   119,  -262,  -262,    63,    61,    61,
      65,    67,    69,   -15,   -15,    47,    47,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   101,    49,    51,   665,   665,  -262,
     118,   125,  -262,    16,   117,   126,  -262,   129,   130,   109,
    -262,  -262,  -262,   131,    43,   136,  -262,   362,   665,   137,
      -1,   139,   -26,  -262,  -262,  -262,   138,   150,   310,   152,
      89,   135,  -262,  -262,   127,  -262,   157,   202,  -262,  -262,
     604,   665,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,   665,  -262,  -262,  -262,  -262,  -262,   593,
     665,  -262,  -262,   654,   665,  -262,  -262,  -262,    43,   362,
     120,  -262,   185,    43,   158,   160,  -262,    43,   665,  -262,
     163,  -262,   665,   132,  -262,  -262,   310,  -262,   162,   665,
     665,   144,  -262,   119,  -262,  -262,  -262,  -262,  -262,  -262,
     145,  -262,  -262,   214,  -262,    43,    43,   205,  -262,   218,
    -262,   362,  -262,    43,     4,   173,   174,  -262,   175,  -262,
    -262,   215,  -262,  -262,   159,  -262,   665,  -262,  -262,  -262,
      43,    43,    43,   182,  -262,     4,  -262,   202,  -262,  -262,
      43,  -262,  -262,  -262
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     5,   227,     0,     0,   231,   232,   233,    69,    73,
       0,    72,    70,     0,     0,     0,     0,     0,     0,     0,
     234,   235,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     5,     7,    14,     8,     9,    10,
      11,    12,     6,    59,    61,    65,    66,    67,    68,    62,
      63,    64,    60,    84,   193,    99,   116,   119,   122,   124,
     128,   132,   142,   143,    13,   220,   186,   189,   191,    99,
     148,   229,   230,     3,   228,   148,    16,    15,    74,   157,
      71,   207,   208,     0,   211,   206,     0,     0,    79,     0,
     219,    81,    79,   236,   114,   139,   140,   141,   223,   218,
       0,   213,   216,   217,   225,     0,   226,     0,   190,     1,
       4,    58,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    85,    82,
       0,   198,   201,   196,   197,   200,   199,   202,   204,     0,
     192,     0,    98,    95,     0,   113,     0,   117,     0,   120,
       0,     0,   123,     0,     0,   127,     0,     0,     0,     0,
       0,   131,   132,     0,     0,     0,   184,     0,   187,    94,
       0,   174,     0,   146,   148,   145,     0,     0,     0,     0,
     210,     0,     0,    52,     0,     0,     0,    77,     0,     0,
      76,   222,     0,     0,   215,   179,   212,   224,     0,    59,
      56,    91,    92,    83,    89,   205,   203,   195,    99,    99,
     116,   119,   122,   124,   124,   128,   128,   137,   136,   134,
     138,   135,   133,   144,     0,   186,   189,     0,     0,   150,
       0,   159,   161,   168,     0,   163,   165,     0,   166,   153,
     147,    75,   155,     0,     0,     0,   209,     0,    36,     0,
      32,     0,    47,    40,    45,    46,     0,    41,     0,     0,
      79,    22,    80,   180,     0,   214,   216,    20,    57,    90,
       0,    88,    86,   194,    97,    96,   115,   118,   121,   125,
     126,   129,   130,     0,   185,   188,   171,   172,   149,   158,
       0,   169,   151,   162,   174,   152,   156,   154,     0,    55,
       0,    33,    34,     0,     0,     0,    26,     0,     0,    48,
      43,    39,     0,     0,    38,    50,     0,    78,     0,     0,
       0,    18,    93,    89,   221,   160,   170,   164,   167,   173,
      24,    54,    53,     0,    25,     0,     0,    28,    49,     0,
      42,     0,    37,     0,   177,     0,     0,    87,     0,    35,
      31,    30,    27,    44,     0,    21,     0,   178,   175,   176,
       0,     0,     0,     0,    51,   181,   183,    20,    17,    23,
       0,   182,    19,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,    28,  -232,  -262,  -262,  -262,  -129,  -262,   241,
    -262,   -83,  -262,  -262,  -262,   255,  -262,   -79,  -262,  -262,
    -262,  -262,   -50,  -181,  -261,     0,    71,   161,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   -87,  -262,  -262,    90,   -55,
      66,  -262,    -5,   -60,  -262,    12,     5,    64,   134,    62,
     142,    72,   141,  -122,   -56,  -119,   -49,   113,  -262,    44,
    -262,  -262,   -62,  -262,  -262,  -262,   103,  -262,  -262,  -262,
      -8,     1,    -3,   -73,   102,   -90,  -262,  -262,  -160,    75,
     133,    76,   -23,  -262,   100,  -262,   115,  -262,   116,   267,
     149,   153,   -14,    -7,   300,  -262,   287
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,    36,    37,   321,    38,    39,
      40,   250,   306,   251,   301,    41,   185,   254,   255,   310,
     256,   257,   314,   182,   300,   183,   112,    43,    44,    45,
      46,    47,    48,    49,    50,   187,    51,    52,   203,   272,
     128,   129,    53,   143,   130,    54,    55,   145,    56,   147,
      57,   149,    58,   152,    59,   155,    60,   161,   162,    61,
      62,    63,   173,   174,    64,   178,   230,   231,   234,   235,
     236,   232,   237,   357,   195,   358,   359,   365,    65,   166,
      66,   168,    67,    68,   140,   141,    83,    84,    85,   100,
     101,   102,   103,    69,    70,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    42,    78,    89,   224,   190,    80,   261,   108,   169,
      90,    91,   196,   175,   192,   299,   107,   267,    82,   304,
      90,    90,   252,    90,   192,    81,   192,   193,   308,    73,
     150,   151,    99,    99,    42,    94,    74,   193,   331,   193,
     156,   157,   158,    79,   170,   159,   171,   181,     2,    22,
     172,   309,     3,   160,     5,     6,     7,   258,    87,     8,
     290,     9,   110,   297,    11,    12,   194,   299,    95,    96,
      97,    16,   305,    18,   253,    19,   356,    20,    21,    22,
     354,   259,    13,    23,    24,    25,    15,   248,   153,   154,
     249,   279,   280,    26,   213,   214,   281,   282,    88,    27,
      86,    28,    92,    29,   215,   216,   106,   202,   201,   299,
     109,   111,   240,   142,   144,   146,   148,   330,   163,    31,
     164,   176,   334,   204,   165,   167,   337,   131,   132,   133,
     134,   135,   136,   137,   138,   209,   177,   180,   179,   139,
     184,   186,   188,   291,   226,   197,   189,   208,   274,   275,
     198,   200,   191,   207,   350,   351,   239,   206,   205,   344,
     244,   260,   355,   233,   238,   247,   193,   113,   270,   241,
     233,   271,   204,   317,   283,   288,   292,   289,   293,   367,
     368,   369,   262,   294,  -173,    82,   295,    90,   296,   373,
     298,   303,    81,   307,   312,   311,   366,   319,    82,    99,
     217,   218,   219,   220,   221,    81,   316,   223,   318,   194,
     320,   333,   335,   332,   336,   339,   343,   346,   348,   349,
     286,   287,   248,   252,   341,     1,     2,   360,   361,   362,
       3,     4,     5,     6,     7,   363,   370,     8,   372,     9,
      10,   302,    11,    12,    13,    76,    14,    42,    15,    16,
      17,    18,   364,    19,   352,    20,    21,    22,   315,    77,
     353,    23,    24,    25,   323,   322,   342,   269,   347,   245,
     268,    26,   199,   277,   276,   222,   324,    27,   210,    28,
     243,    29,   233,   326,   278,   327,   238,   329,   211,   212,
     325,   328,   371,    30,   263,   105,   246,    31,   225,    42,
     284,   338,   285,    75,     2,   340,   345,   273,   264,    93,
       5,     6,     7,    90,   313,     2,   315,     0,     0,     3,
       0,     5,     6,     7,     0,     0,     8,     0,     9,     0,
       0,    11,    12,    20,    21,    22,     0,     0,    16,     0,
      18,    42,    19,   265,    20,    21,    22,   266,     0,     0,
      23,    24,    25,     0,     0,    27,     0,    28,     0,    29,
      26,     0,     0,     0,     0,     0,    27,     2,    28,     0,
      29,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       9,    10,     0,    11,    12,    13,    31,    14,     0,    15,
      16,    17,    18,     0,    19,     0,    20,    21,    22,     0,
       0,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,    27,     2,
      28,     0,    29,     3,     0,     5,     6,     7,     0,     0,
       8,     0,     9,     0,    30,    11,    12,     0,    31,     0,
       0,     0,    16,     0,    18,     0,    19,     0,    20,    21,
      22,     0,     0,     0,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     2,
      27,     0,    28,     3,    29,     5,     6,     7,     0,     0,
       2,     0,     0,     0,     3,     0,     5,     6,     7,     0,
      31,     0,     0,     0,     0,     0,     0,     0,    20,    21,
      22,   227,     0,     0,   228,    24,    25,     0,     0,    20,
      21,    22,   227,     0,    26,   228,    24,    25,     0,     0,
      27,   229,    28,     0,    29,    26,     0,     0,     0,     0,
       2,    27,   242,    28,     3,    29,     5,     6,     7,     0,
      31,     2,     0,     0,     0,     3,     0,     5,     6,     7,
       0,    31,     0,     0,     0,     0,     0,     0,     0,    20,
      21,    22,     0,     0,     0,    23,    24,    25,     0,     0,
      20,    21,    22,     0,     0,    26,    23,    24,    25,     0,
       0,    27,    98,    28,     0,    29,    26,     0,     0,     0,
       0,     0,    27,     0,    28,   104,    29,     0,     2,     0,
       0,    31,     3,     0,     5,     6,     7,     0,     0,     2,
       0,     0,    31,     3,     0,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
     227,     0,     0,   228,    24,    25,     0,     0,    20,    21,
      22,     0,     0,    26,    23,    24,    25,     0,     0,    27,
       0,    28,     0,    29,    26,     0,     0,     0,     0,     2,
      27,     0,    28,     3,    29,     5,     6,     7,     0,    31,
       2,     0,     0,     0,     3,     0,     5,     6,     7,     0,
      31,     0,     0,     0,     0,     0,     0,     0,    20,    21,
      22,     0,     0,     0,     0,    24,    25,     0,     0,    20,
      21,    22,     0,     0,    26,     0,    24,    25,  -174,     0,
      27,     0,    28,     0,    29,    26,     0,     0,     0,     0,
       2,    27,     0,    28,     3,    29,     5,     6,     7,     0,
      31,     2,     0,     0,     0,     3,     0,     5,     6,     7,
       0,    31,     0,     0,     0,     0,     0,     0,     0,    20,
      21,    22,     0,   113,     0,    23,    24,    25,     0,     0,
      20,    21,    22,   114,     0,    26,     0,    24,    25,     0,
       0,    27,     0,    28,     0,    29,    26,     0,     0,     0,
       0,     0,    27,     0,    28,     0,    29,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127
};

static const yytype_int16 yycheck[] =
{
       0,     1,     9,    17,   164,    92,    11,   188,    31,    69,
      17,    18,   102,    75,    10,   247,    30,   198,    13,    20,
      27,    28,     5,    30,    10,    13,    10,    23,    54,     1,
      45,    46,    27,    28,    34,    23,    77,    23,   299,    23,
      38,    39,    40,     5,    56,    43,    58,     4,     5,    36,
      62,    77,     9,    51,    11,    12,    13,    54,     5,    16,
      44,    18,    34,   244,    21,    22,    52,   299,    24,    25,
      26,    28,    73,    30,    57,    32,    72,    34,    35,    36,
     341,    78,    23,    40,    41,    42,    27,    17,    41,    42,
      20,   213,   214,    50,   150,   151,   215,   216,     5,    56,
      54,    58,     5,    60,   153,   154,    61,   114,   113,   341,
       0,    55,   174,    52,    49,    48,    47,   298,    37,    76,
      72,     7,   303,   130,    75,    74,   307,    64,    65,    66,
      67,    68,    69,    70,    71,   142,    56,    52,    70,    76,
      56,    52,    54,   233,   167,    59,    52,   142,   208,   209,
      54,     4,    57,   141,   335,   336,     5,    70,    76,   319,
      54,     5,   343,   170,   171,    92,    23,    44,    44,   176,
     177,    52,   179,   260,    73,    57,    59,    52,    52,   360,
     361,   362,   189,    54,    54,   180,    77,   194,    57,   370,
      54,    54,   180,    54,    44,    57,   356,    70,   193,   194,
     156,   157,   158,   159,   160,   193,    54,   163,    73,    52,
       8,    26,    54,    93,    54,    52,    54,    73,    73,     5,
     227,   228,    17,     5,    92,     4,     5,    54,    54,    54,
       9,    10,    11,    12,    13,    20,    54,    16,   367,    18,
      19,   248,    21,    22,    23,     4,    25,   247,    27,    28,
      29,    30,    93,    32,   337,    34,    35,    36,   258,     4,
     339,    40,    41,    42,   271,   270,   316,   201,   323,   179,
     199,    50,   111,   211,   210,   162,   283,    56,   144,    58,
     177,    60,   289,   290,   212,   293,   293,   294,   146,   148,
     289,   294,   365,    72,   192,    28,   180,    76,   165,   299,
     225,   308,   226,     3,     5,   312,   320,   207,   193,    22,
      11,    12,    13,   320,     4,     5,   316,    -1,    -1,     9,
      -1,    11,    12,    13,    -1,    -1,    16,    -1,    18,    -1,
      -1,    21,    22,    34,    35,    36,    -1,    -1,    28,    -1,
      30,   341,    32,   194,    34,    35,    36,   194,    -1,    -1,
      40,    41,    42,    -1,    -1,    56,    -1,    58,    -1,    60,
      50,    -1,    -1,    -1,    -1,    -1,    56,     5,    58,    -1,
      60,     9,    10,    11,    12,    13,    -1,    -1,    16,    -1,
      18,    19,    -1,    21,    22,    23,    76,    25,    -1,    27,
      28,    29,    30,    -1,    32,    -1,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,     5,
      58,    -1,    60,     9,    -1,    11,    12,    13,    -1,    -1,
      16,    -1,    18,    -1,    72,    21,    22,    -1,    76,    -1,
      -1,    -1,    28,    -1,    30,    -1,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,     5,
      56,    -1,    58,     9,    60,    11,    12,    13,    -1,    -1,
       5,    -1,    -1,    -1,     9,    -1,    11,    12,    13,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    -1,    -1,    34,
      35,    36,    37,    -1,    50,    40,    41,    42,    -1,    -1,
      56,    57,    58,    -1,    60,    50,    -1,    -1,    -1,    -1,
       5,    56,    57,    58,     9,    60,    11,    12,    13,    -1,
      76,     5,    -1,    -1,    -1,     9,    -1,    11,    12,    13,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      34,    35,    36,    -1,    -1,    50,    40,    41,    42,    -1,
      -1,    56,    57,    58,    -1,    60,    50,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    -1,     5,    -1,
      -1,    76,     9,    -1,    11,    12,    13,    -1,    -1,     5,
      -1,    -1,    76,     9,    -1,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    -1,    -1,    34,    35,
      36,    -1,    -1,    50,    40,    41,    42,    -1,    -1,    56,
      -1,    58,    -1,    60,    50,    -1,    -1,    -1,    -1,     5,
      56,    -1,    58,     9,    60,    11,    12,    13,    -1,    76,
       5,    -1,    -1,    -1,     9,    -1,    11,    12,    13,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    34,
      35,    36,    -1,    -1,    50,    -1,    41,    42,    54,    -1,
      56,    -1,    58,    -1,    60,    50,    -1,    -1,    -1,    -1,
       5,    56,    -1,    58,     9,    60,    11,    12,    13,    -1,
      76,     5,    -1,    -1,    -1,     9,    -1,    11,    12,    13,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    44,    -1,    40,    41,    42,    -1,    -1,
      34,    35,    36,    54,    -1,    50,    -1,    41,    42,    -1,
      -1,    56,    -1,    58,    -1,    60,    50,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    -1,    60,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    12,    13,    16,    18,
      19,    21,    22,    23,    25,    27,    28,    29,    30,    32,
      34,    35,    36,    40,    41,    42,    50,    56,    58,    60,
      72,    76,    95,    96,    97,    98,    99,   100,   102,   103,
     104,   109,   119,   121,   122,   123,   124,   125,   126,   127,
     128,   130,   131,   136,   139,   140,   142,   144,   146,   148,
     150,   153,   154,   155,   158,   172,   174,   176,   177,   187,
     188,   189,   190,    96,    77,   188,   103,   109,   187,     5,
     136,   139,   140,   180,   181,   182,    54,     5,     5,   186,
     187,   187,     5,   190,   139,   153,   153,   153,    57,   140,
     183,   184,   185,   186,    59,   183,    61,   186,   176,     0,
      96,    55,   120,    44,    54,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   134,   135,
     138,    64,    65,    66,    67,    68,    69,    70,    71,    76,
     178,   179,    52,   137,    49,   141,    48,   143,    47,   145,
      45,    46,   147,    41,    42,   149,    38,    39,    40,    43,
      51,   151,   152,    37,    72,    75,   173,    74,   175,   137,
      56,    58,    62,   156,   157,   156,     7,    56,   159,    70,
      52,     4,   117,   119,    56,   110,    52,   129,    54,    52,
     129,    57,    10,    23,    52,   168,   169,    59,    54,   121,
       4,   136,   187,   132,   187,    76,    70,   139,   140,   187,
     142,   144,   146,   148,   148,   150,   150,   153,   153,   153,
     153,   153,   151,   153,   172,   174,   176,    37,    40,    57,
     160,   161,   165,   187,   162,   163,   164,   166,   187,     5,
     156,   187,    57,   160,    54,   132,   182,    92,    17,    20,
     105,   107,     5,    57,   111,   112,   114,   115,    54,    78,
       5,   117,   187,   168,   180,   184,   185,   117,   120,   134,
      44,    52,   133,   178,   137,   137,   141,   143,   145,   147,
     147,   149,   149,    73,   173,   175,   187,   187,    57,    52,
      44,   169,    59,    52,    54,    77,    57,   117,    54,    97,
     118,   108,   187,    54,    20,    73,   106,    54,    54,    77,
     113,    57,    44,     4,   116,   119,    54,   129,    73,    70,
       8,   101,   136,   187,   187,   165,   187,   164,   166,   187,
     117,   118,    93,    26,   117,    54,    54,   117,   187,    52,
     187,    92,   116,    54,   172,   186,    73,   133,    73,     5,
     117,   117,   105,   111,   118,   117,    72,   167,   169,   170,
      54,    54,    54,    20,    93,   171,   172,   117,   117,   117,
      54,   167,   101,   117
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   106,   107,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   113,   113,   114,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   120,   120,   120,
     121,   121,   121,   121,   121,   122,   122,   122,   122,   123,
     124,   125,   125,   126,   126,   126,   127,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   132,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   139,   140,   141,   141,   142,   143,   143,
     144,   145,   145,   146,   147,   147,   147,   148,   149,   149,
     149,   150,   151,   151,   152,   152,   152,   152,   152,   153,
     153,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   157,   157,   157,   158,   159,   159,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   164,   164,   165,   165,
     165,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   172,   173,   173,   174,   175,   175,
     176,   176,   177,   177,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   180,   181,   181,   182,
     182,   182,   183,   183,   184,   184,   184,   185,   185,   186,
     187,   187,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   189,   190,   190
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     8,     5,     5,
       0,     7,     4,     9,     6,     6,     5,     4,     3,     6,
       3,     3,     0,     2,     1,     3,     0,     6,     5,     3,
       2,     1,     3,     2,     3,     0,     1,     1,     2,     3,
       1,     4,     1,     4,     2,     1,     3,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     4,     3,     3,     3,     0,
       4,     2,     2,     3,     1,     2,     2,     3,     1,     0,
       3,     2,     2,     4,     2,     2,     3,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     0,     2,     3,     0,
       2,     3,     0,     2,     0,     3,     3,     2,     0,     3,
       3,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     3,     3,     2,     2,     0,     3,
       2,     3,     3,     2,     5,     2,     3,     0,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     3,     1,     2,
       3,     2,     2,     1,     0,     1,     1,     4,     5,     1,
       2,     2,     3,     1,     2,     3,     0,     2,     3,     0,
       2,     1,     2,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3,
       2,     1,     2,     1,     3,     2,     1,     1,     1,     1,
       1,     5,     3,     2,     3,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1
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
  case 2: /* start: file_input  */
#line 38 "test.y"
                   {(yyval.elem) = create_node(2,"START", (yyvsp[0].elem)); start_node=(yyval.elem);}
#line 1656 "test.tab.c"
    break;

  case 3: /* file_input: NEWLINE file_input  */
#line 41 "test.y"
                               {(yyval.elem) = (yyvsp[0].elem);}
#line 1662 "test.tab.c"
    break;

  case 4: /* file_input: stmt file_input  */
#line 42 "test.y"
                      {(yyval.elem) = create_node(3,"File Input",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1668 "test.tab.c"
    break;

  case 5: /* file_input: %empty  */
#line 43 "test.y"
      {(yyval.elem) = NULL;}
#line 1674 "test.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 47 "test.y"
                   {(yyval.elem) = (yyvsp[0].elem);}
#line 1680 "test.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 48 "test.y"
                   {(yyval.elem) = (yyvsp[0].elem);}
#line 1686 "test.tab.c"
    break;

  case 8: /* compound_stmt: if_stmt  */
#line 51 "test.y"
                       { (yyval.elem) = (yyvsp[0].elem);}
#line 1692 "test.tab.c"
    break;

  case 9: /* compound_stmt: while_stmt  */
#line 52 "test.y"
                  { (yyval.elem) = (yyvsp[0].elem);}
#line 1698 "test.tab.c"
    break;

  case 10: /* compound_stmt: for_stmt  */
#line 53 "test.y"
               { (yyval.elem) = (yyvsp[0].elem);}
#line 1704 "test.tab.c"
    break;

  case 11: /* compound_stmt: try_stmt  */
#line 54 "test.y"
               { (yyval.elem) = (yyvsp[0].elem);}
#line 1710 "test.tab.c"
    break;

  case 12: /* compound_stmt: funcdef  */
#line 55 "test.y"
               {  (yyval.elem) = (yyvsp[0].elem);}
#line 1716 "test.tab.c"
    break;

  case 13: /* compound_stmt: classdef  */
#line 56 "test.y"
               { (yyval.elem) = (yyvsp[0].elem);}
#line 1722 "test.tab.c"
    break;

  case 14: /* compound_stmt: async_stmt  */
#line 57 "test.y"
                 { (yyval.elem) = (yyvsp[0].elem);}
#line 1728 "test.tab.c"
    break;

  case 15: /* async_stmt: ASYNC funcdef  */
#line 60 "test.y"
                          { (yyval.elem) = create_node(3,"Async_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1734 "test.tab.c"
    break;

  case 16: /* async_stmt: ASYNC for_stmt  */
#line 61 "test.y"
                     { (yyval.elem) = create_node(3,"Async_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1740 "test.tab.c"
    break;

  case 17: /* if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star ELSE COLON suite  */
#line 64 "test.y"
                                                                                             { (yyval.elem) = create_node(9,"If_stmt",(yyvsp[-7].elem),(yyvsp[-6].elem),(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1746 "test.tab.c"
    break;

  case 18: /* if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star  */
#line 65 "test.y"
                                                                         { (yyval.elem) = create_node(6,"If_stmt",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1752 "test.tab.c"
    break;

  case 19: /* elif_namedexpr_test_colon_suite_star: ELIF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star  */
#line 68 "test.y"
                                                                                                           {(yyval.elem) = create_node(5,"Elif_block",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem));}
#line 1758 "test.tab.c"
    break;

  case 20: /* elif_namedexpr_test_colon_suite_star: %empty  */
#line 69 "test.y"
      { (yyval.elem) = NULL;}
#line 1764 "test.tab.c"
    break;

  case 21: /* while_stmt: WHILE namedexpr_test COLON suite ELSE COLON suite  */
#line 72 "test.y"
                                                              { (yyval.elem) = create_node(8,"While_stmt",(yyvsp[-6].elem),(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1770 "test.tab.c"
    break;

  case 22: /* while_stmt: WHILE namedexpr_test COLON suite  */
#line 73 "test.y"
                                       {(yyval.elem) = create_node(5,"While_stmt",(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1776 "test.tab.c"
    break;

  case 23: /* for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite  */
#line 76 "test.y"
                                                                 { (yyval.elem) = create_node(10,"For_stmt",(yyvsp[-8].elem),(yyvsp[-7].elem),(yyvsp[-6].elem),(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1782 "test.tab.c"
    break;

  case 24: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 77 "test.y"
                                           {(yyval.elem) = create_node(7,"For_stmt",(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1788 "test.tab.c"
    break;

  case 25: /* try_stmt: TRY COLON suite FINALLY COLON suite  */
#line 80 "test.y"
                                              {(yyval.elem) = create_node(7,"Try_stmt",(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1794 "test.tab.c"
    break;

  case 26: /* try_stmt: TRY COLON suite except_clause_colon_suite try_stmt_options  */
#line 81 "test.y"
                                                                 { (yyval.elem) = create_node(6,"Try_stmt",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1800 "test.tab.c"
    break;

  case 27: /* except_clause_colon_suite: except_clause COLON suite except_clause_colon_suite  */
#line 84 "test.y"
                                                                               {(yyval.elem) = create_node(5,"Except_block",(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1806 "test.tab.c"
    break;

  case 28: /* except_clause_colon_suite: except_clause COLON suite  */
#line 85 "test.y"
                                { (yyval.elem) = create_node(4,"Except_block",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1812 "test.tab.c"
    break;

  case 29: /* try_stmt_options: ELSE COLON suite FINALLY COLON suite  */
#line 88 "test.y"
                                                       { (yyval.elem) = create_node(7,"Else_finally_block",(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1818 "test.tab.c"
    break;

  case 30: /* try_stmt_options: ELSE COLON suite  */
#line 89 "test.y"
                       {(yyval.elem) = create_node(4,"Else_block",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1824 "test.tab.c"
    break;

  case 31: /* try_stmt_options: FINALLY COLON suite  */
#line 90 "test.y"
                          { (yyval.elem) = create_node(4,"Finally_block",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1830 "test.tab.c"
    break;

  case 32: /* try_stmt_options: %empty  */
#line 91 "test.y"
      { (yyval.elem) = NULL;{}}
#line 1836 "test.tab.c"
    break;

  case 33: /* except_clause: EXCEPT test_as_name_optional  */
#line 94 "test.y"
                                            {(yyval.elem) = create_node(3,"Except_block",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1842 "test.tab.c"
    break;

  case 34: /* test_as_name_optional: test  */
#line 96 "test.y"
                            {(yyval.elem)=(yyvsp[0].elem);}
#line 1848 "test.tab.c"
    break;

  case 35: /* test_as_name_optional: test AS NAME  */
#line 97 "test.y"
                   {(yyval.elem) = create_node(4,"Expressions_block",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1854 "test.tab.c"
    break;

  case 36: /* test_as_name_optional: %empty  */
#line 98 "test.y"
      {(yyval.elem) = NULL;}
#line 1860 "test.tab.c"
    break;

  case 37: /* funcdef: DEF NAME parameters FUNC_TYPE_HINT COLON func_body_suite  */
#line 102 "test.y"
                                                                     { (yyval.elem) = create_node(7,"Func_def",(yyvsp[-5].elem),(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1866 "test.tab.c"
    break;

  case 38: /* funcdef: DEF NAME parameters COLON func_body_suite  */
#line 103 "test.y"
                                                  { (yyval.elem) = create_node(6,"Func_def",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1872 "test.tab.c"
    break;

  case 39: /* parameters: SMALL_OPEN typedarglist SMALL_CLOSE  */
#line 107 "test.y"
                                                {(yyval.elem) = create_node(4,"Arguments",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1878 "test.tab.c"
    break;

  case 40: /* parameters: SMALL_OPEN SMALL_CLOSE  */
#line 108 "test.y"
                            {(yyval.elem) = create_node(3,"Parantheses",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1884 "test.tab.c"
    break;

  case 41: /* typedlist_argument: tfpdef  */
#line 112 "test.y"
                            { (yyval.elem) = (yyvsp[0].elem);}
#line 1890 "test.tab.c"
    break;

  case 42: /* typedlist_argument: tfpdef EQUAL test  */
#line 113 "test.y"
                          { (yyval.elem) = create_node(4,"Assign_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1896 "test.tab.c"
    break;

  case 43: /* typedlist_arguments: typedlist_argument comma_option_argument_star  */
#line 116 "test.y"
                                                                   {(yyval.elem) = create_node(3,"Arguments",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1902 "test.tab.c"
    break;

  case 44: /* comma_option_argument_star: comma_option_argument_star COMMA typedlist_argument  */
#line 118 "test.y"
                                                                                {(yyval.elem) = create_node(4,"Arguments",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1908 "test.tab.c"
    break;

  case 45: /* comma_option_argument_star: %empty  */
#line 119 "test.y"
      { (yyval.elem) = NULL;}
#line 1914 "test.tab.c"
    break;

  case 46: /* typedarglist: typedlist_arguments  */
#line 123 "test.y"
                        {(yyval.elem) = (yyvsp[0].elem);}
#line 1920 "test.tab.c"
    break;

  case 47: /* tfpdef: NAME  */
#line 126 "test.y"
             { (yyval.elem) = (yyvsp[0].elem);}
#line 1926 "test.tab.c"
    break;

  case 48: /* tfpdef: NAME TYPE_HINT  */
#line 127 "test.y"
                     { (yyval.elem) = create_node(3,"Identifier",(yyvsp[-1].elem),(yyvsp[0].elem)); }
#line 1932 "test.tab.c"
    break;

  case 49: /* tfpdef: NAME COLON test  */
#line 128 "test.y"
                      {(yyval.elem) = create_node(4,"Identifier",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1938 "test.tab.c"
    break;

  case 50: /* func_body_suite: simple_stmt  */
#line 131 "test.y"
                             {(yyval.elem) = (yyvsp[0].elem);}
#line 1944 "test.tab.c"
    break;

  case 51: /* func_body_suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 132 "test.y"
                                      { (yyval.elem) = (yyvsp[-1].elem);}
#line 1950 "test.tab.c"
    break;

  case 52: /* suite: simple_stmt  */
#line 134 "test.y"
                   {(yyval.elem) = (yyvsp[0].elem);}
#line 1956 "test.tab.c"
    break;

  case 53: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 135 "test.y"
                                      { (yyval.elem) = (yyvsp[-1].elem);}
#line 1962 "test.tab.c"
    break;

  case 54: /* stmt_plus: stmt stmt_plus  */
#line 138 "test.y"
                          {(yyval.elem) = create_node(3,"Stmts",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1968 "test.tab.c"
    break;

  case 55: /* stmt_plus: stmt  */
#line 139 "test.y"
           {(yyval.elem) = (yyvsp[0].elem);}
#line 1974 "test.tab.c"
    break;

  case 56: /* simple_stmt: small_stmt semi_colon_small_stmt_star NEWLINE  */
#line 142 "test.y"
                                                           {(yyval.elem) = create_node(3,"Simple_stmts",(yyvsp[-2].elem),(yyvsp[-1].elem));}
#line 1980 "test.tab.c"
    break;

  case 57: /* semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star  */
#line 145 "test.y"
                                                                             {(yyval.elem) = create_node(4,"Small_stmts",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1986 "test.tab.c"
    break;

  case 58: /* semi_colon_small_stmt_star: SEMI_COLON  */
#line 146 "test.y"
                 {(yyval.elem) = (yyvsp[0].elem);}
#line 1992 "test.tab.c"
    break;

  case 59: /* semi_colon_small_stmt_star: %empty  */
#line 147 "test.y"
      { (yyval.elem) = NULL;}
#line 1998 "test.tab.c"
    break;

  case 60: /* small_stmt: expr_stmt  */
#line 150 "test.y"
                      {(yyval.elem) = (yyvsp[0].elem);}
#line 2004 "test.tab.c"
    break;

  case 61: /* small_stmt: flow_stmt  */
#line 151 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 2010 "test.tab.c"
    break;

  case 62: /* small_stmt: global_stmt  */
#line 152 "test.y"
                  {(yyval.elem) = (yyvsp[0].elem);}
#line 2016 "test.tab.c"
    break;

  case 63: /* small_stmt: nonlocal_stmt  */
#line 153 "test.y"
                    {(yyval.elem) = (yyvsp[0].elem);}
#line 2022 "test.tab.c"
    break;

  case 64: /* small_stmt: assert_stmt  */
#line 154 "test.y"
                  {(yyval.elem) = (yyvsp[0].elem);}
#line 2028 "test.tab.c"
    break;

  case 65: /* flow_stmt: break_stmt  */
#line 157 "test.y"
                      {(yyval.elem) = (yyvsp[0].elem);}
#line 2034 "test.tab.c"
    break;

  case 66: /* flow_stmt: continue_stmt  */
#line 158 "test.y"
                    {(yyval.elem) = (yyvsp[0].elem);}
#line 2040 "test.tab.c"
    break;

  case 67: /* flow_stmt: return_stmt  */
#line 159 "test.y"
                  {(yyval.elem) = (yyvsp[0].elem);}
#line 2046 "test.tab.c"
    break;

  case 68: /* flow_stmt: raise_stmt  */
#line 160 "test.y"
                 {(yyval.elem) = (yyvsp[0].elem);}
#line 2052 "test.tab.c"
    break;

  case 69: /* break_stmt: BREAK  */
#line 163 "test.y"
                  {(yyval.elem)  = (yyvsp[0].elem);}
#line 2058 "test.tab.c"
    break;

  case 70: /* continue_stmt: CONTINUE  */
#line 165 "test.y"
                        {(yyval.elem) = (yyvsp[0].elem);}
#line 2064 "test.tab.c"
    break;

  case 71: /* return_stmt: RETURN testlist_star_expr  */
#line 167 "test.y"
                                       {(yyval.elem) = create_node(3,"Return_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2070 "test.tab.c"
    break;

  case 72: /* return_stmt: RETURN  */
#line 168 "test.y"
             {(yyval.elem) = (yyvsp[0].elem);}
#line 2076 "test.tab.c"
    break;

  case 73: /* raise_stmt: RAISE  */
#line 171 "test.y"
                  {(yyval.elem) = (yyvsp[0].elem);}
#line 2082 "test.tab.c"
    break;

  case 74: /* raise_stmt: RAISE test  */
#line 172 "test.y"
                 {(yyval.elem) = create_node(3,"Raise_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2088 "test.tab.c"
    break;

  case 75: /* raise_stmt: RAISE test FROM test  */
#line 173 "test.y"
                           {(yyval.elem) = create_node(5,"Raise_stmt",(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2094 "test.tab.c"
    break;

  case 76: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 176 "test.y"
                                         {(yyval.elem) = create_node(4,"Global_stmt",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2100 "test.tab.c"
    break;

  case 77: /* nonlocal_stmt: NONLOCAL NAME comma_name_star  */
#line 178 "test.y"
                                             {(yyval.elem) = create_node(4,"Nonlocal_stmt",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2106 "test.tab.c"
    break;

  case 78: /* comma_name_star: COMMA NAME comma_name_star  */
#line 180 "test.y"
                                            {(yyval.elem) = create_node(4,"Identifiers",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2112 "test.tab.c"
    break;

  case 79: /* comma_name_star: %empty  */
#line 181 "test.y"
      { (yyval.elem) = NULL;}
#line 2118 "test.tab.c"
    break;

  case 80: /* assert_stmt: ASSERT test COMMA test  */
#line 184 "test.y"
                                    {(yyval.elem) = create_node(5,"Assert_stmt",(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2124 "test.tab.c"
    break;

  case 81: /* assert_stmt: ASSERT test  */
#line 185 "test.y"
                  {(yyval.elem) = create_node(3,"Assert_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2130 "test.tab.c"
    break;

  case 82: /* expr_stmt: testlist_star_expr annassign  */
#line 188 "test.y"
                                        {(yyval.elem) = create_node(3,"Expr_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2136 "test.tab.c"
    break;

  case 83: /* expr_stmt: testlist_star_expr augassign testlist  */
#line 189 "test.y"
                                            {(yyval.elem) = create_node(4,"Expr_stmt",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2142 "test.tab.c"
    break;

  case 84: /* expr_stmt: testlist_star_expr  */
#line 190 "test.y"
                         {(yyval.elem) = (yyvsp[0].elem);}
#line 2148 "test.tab.c"
    break;

  case 85: /* expr_stmt: testlist_star_expr expr_stmt_option1_plus  */
#line 191 "test.y"
                                                {(yyval.elem) = create_node(3,"Expr_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2154 "test.tab.c"
    break;

  case 86: /* testlist: test symbol_test_star  */
#line 194 "test.y"
                                  {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2160 "test.tab.c"
    break;

  case 87: /* symbol_test_star: COMMA test symbol_test_star  */
#line 196 "test.y"
                                              {(yyval.elem) = create_node(4,"Expressions",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2166 "test.tab.c"
    break;

  case 88: /* symbol_test_star: COMMA  */
#line 197 "test.y"
            {(yyval.elem) = (yyvsp[0].elem);}
#line 2172 "test.tab.c"
    break;

  case 89: /* symbol_test_star: %empty  */
#line 198 "test.y"
     {(yyval.elem)=NULL;}
#line 2178 "test.tab.c"
    break;

  case 90: /* expr_stmt_option1_plus: EQUAL testlist_star_expr expr_stmt_option1_plus  */
#line 203 "test.y"
                                                                       {(yyval.elem) = create_node(4,"Expr_stmt",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2184 "test.tab.c"
    break;

  case 91: /* expr_stmt_option1_plus: EQUAL testlist_star_expr  */
#line 205 "test.y"
                               {(yyval.elem) = create_node(3,"Expr_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2190 "test.tab.c"
    break;

  case 92: /* annassign: COLON test  */
#line 208 "test.y"
                      {(yyval.elem) = create_node(3,"Identifiers",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2196 "test.tab.c"
    break;

  case 93: /* annassign: COLON test EQUAL testlist_star_expr  */
#line 209 "test.y"
                                          {(yyval.elem) = create_node(5,"Identifiers",(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2202 "test.tab.c"
    break;

  case 94: /* testlist_star_expr: test testlist_star_expr_option1_star  */
#line 212 "test.y"
                                                         {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2208 "test.tab.c"
    break;

  case 95: /* testlist_star_expr: star_expr testlist_star_expr_option1_star  */
#line 213 "test.y"
                                                {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2214 "test.tab.c"
    break;

  case 96: /* testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star  */
#line 216 "test.y"
                                                                            {(yyval.elem) = create_node(4,"Expressions",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2220 "test.tab.c"
    break;

  case 97: /* testlist_star_expr_option1_star: COMMA star_expr testlist_star_expr_option1_star  */
#line 217 "test.y"
                                                      {(yyval.elem) = create_node(4,"Expressions",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2226 "test.tab.c"
    break;

  case 98: /* testlist_star_expr_option1_star: COMMA  */
#line 218 "test.y"
            {(yyval.elem) = (yyvsp[0].elem);}
#line 2232 "test.tab.c"
    break;

  case 99: /* testlist_star_expr_option1_star: %empty  */
#line 219 "test.y"
     {(yyval.elem)=NULL;}
#line 2238 "test.tab.c"
    break;

  case 100: /* augassign: ADD_EQUAL  */
#line 222 "test.y"
                     {(yyval.elem) = (yyvsp[0].elem);}
#line 2244 "test.tab.c"
    break;

  case 101: /* augassign: SUB_EQUAL  */
#line 223 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 2250 "test.tab.c"
    break;

  case 102: /* augassign: MUL_EQUAL  */
#line 224 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 2256 "test.tab.c"
    break;

  case 103: /* augassign: AT_EQUAL  */
#line 225 "test.y"
               {(yyval.elem) = (yyvsp[0].elem);}
#line 2262 "test.tab.c"
    break;

  case 104: /* augassign: DIV_EQUAL  */
#line 226 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 2268 "test.tab.c"
    break;

  case 105: /* augassign: MOD_EQUAL  */
#line 227 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 2274 "test.tab.c"
    break;

  case 106: /* augassign: BITWISE_AND_EQUAL  */
#line 228 "test.y"
                        {(yyval.elem) = (yyvsp[0].elem);}
#line 2280 "test.tab.c"
    break;

  case 107: /* augassign: BITWISE_OR_EQUAL  */
#line 229 "test.y"
                       {(yyval.elem) = (yyvsp[0].elem);}
#line 2286 "test.tab.c"
    break;

  case 108: /* augassign: BITWISE_XOR_EQUAL  */
#line 230 "test.y"
                        {(yyval.elem) = (yyvsp[0].elem);}
#line 2292 "test.tab.c"
    break;

  case 109: /* augassign: SHIFT_LEFT_EQUAL  */
#line 231 "test.y"
                       {(yyval.elem) = (yyvsp[0].elem);}
#line 2298 "test.tab.c"
    break;

  case 110: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 232 "test.y"
                        {(yyval.elem) = (yyvsp[0].elem);}
#line 2304 "test.tab.c"
    break;

  case 111: /* augassign: POW_EQUAL  */
#line 233 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 2310 "test.tab.c"
    break;

  case 112: /* augassign: FLOOR_DIV_EQUAL  */
#line 234 "test.y"
                      {(yyval.elem) = (yyvsp[0].elem);}
#line 2316 "test.tab.c"
    break;

  case 113: /* expr: xor_expr symbol_xor_expr_star  */
#line 237 "test.y"
                                    {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2322 "test.tab.c"
    break;

  case 114: /* star_expr: MUL expr  */
#line 239 "test.y"
                    {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2328 "test.tab.c"
    break;

  case 115: /* symbol_xor_expr_star: BITWISE_OR xor_expr symbol_xor_expr_star  */
#line 241 "test.y"
                                                               {(yyval.elem) = create_node(4,"Or_exprs",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2334 "test.tab.c"
    break;

  case 116: /* symbol_xor_expr_star: %empty  */
#line 242 "test.y"
                {(yyval.elem)=NULL;}
#line 2340 "test.tab.c"
    break;

  case 117: /* xor_expr: and_expr symbol_and_expr_star  */
#line 245 "test.y"
                                        {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2346 "test.tab.c"
    break;

  case 118: /* symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star  */
#line 247 "test.y"
                                                                {(yyval.elem) = create_node(4,"Xor_exprs",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2352 "test.tab.c"
    break;

  case 119: /* symbol_and_expr_star: %empty  */
#line 248 "test.y"
                {(yyval.elem)=NULL;}
#line 2358 "test.tab.c"
    break;

  case 120: /* and_expr: shift_expr symbol_shift_expr_star  */
#line 251 "test.y"
                                            {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2364 "test.tab.c"
    break;

  case 121: /* symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star  */
#line 253 "test.y"
                                                                      {(yyval.elem) = create_node(4,"And_exprs",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2370 "test.tab.c"
    break;

  case 122: /* symbol_shift_expr_star: %empty  */
#line 254 "test.y"
                {(yyval.elem)=NULL;}
#line 2376 "test.tab.c"
    break;

  case 123: /* shift_expr: arith_expr shift_arith_expr_star  */
#line 257 "test.y"
                                             {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2382 "test.tab.c"
    break;

  case 124: /* shift_arith_expr_star: %empty  */
#line 259 "test.y"
                                 {(yyval.elem)=NULL;}
#line 2388 "test.tab.c"
    break;

  case 125: /* shift_arith_expr_star: SHIFT_LEFT arith_expr shift_arith_expr_star  */
#line 260 "test.y"
                                                  {(yyval.elem) = create_node(4,"Shift_left_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2394 "test.tab.c"
    break;

  case 126: /* shift_arith_expr_star: SHIFT_RIGHT arith_expr shift_arith_expr_star  */
#line 261 "test.y"
                                                   {(yyval.elem) = create_node(4,"Shift_right_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2400 "test.tab.c"
    break;

  case 127: /* arith_expr: term symbol_term_star  */
#line 264 "test.y"
                                   {(yyval.elem) = create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2406 "test.tab.c"
    break;

  case 128: /* symbol_term_star: %empty  */
#line 266 "test.y"
                            {(yyval.elem)=NULL;}
#line 2412 "test.tab.c"
    break;

  case 129: /* symbol_term_star: ADD term symbol_term_star  */
#line 267 "test.y"
                                {(yyval.elem) = create_node(4,"Operator_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2418 "test.tab.c"
    break;

  case 130: /* symbol_term_star: SUB term symbol_term_star  */
#line 268 "test.y"
                                {(yyval.elem) = create_node(4,"Operator_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2424 "test.tab.c"
    break;

  case 131: /* term: factor symbol_factor_star  */
#line 271 "test.y"
                                {(yyval.elem) = create_node(3,"Terms",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2430 "test.tab.c"
    break;

  case 132: /* symbol_factor_star: %empty  */
#line 273 "test.y"
                              {(yyval.elem)=NULL;}
#line 2436 "test.tab.c"
    break;

  case 133: /* symbol_factor_star: symbol_factor symbol_factor_star  */
#line 274 "test.y"
                                       {(yyval.elem) = create_node(3,"Terms",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2442 "test.tab.c"
    break;

  case 134: /* symbol_factor: MUL factor  */
#line 277 "test.y"
                          {(yyval.elem) = create_node(3,"Mul_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2448 "test.tab.c"
    break;

  case 135: /* symbol_factor: AT factor  */
#line 278 "test.y"
                {(yyval.elem) = create_node(3,"At_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2454 "test.tab.c"
    break;

  case 136: /* symbol_factor: DIV factor  */
#line 279 "test.y"
                 {(yyval.elem) = create_node(3,"Div_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2460 "test.tab.c"
    break;

  case 137: /* symbol_factor: FLOOR_DIV factor  */
#line 280 "test.y"
                       {(yyval.elem) = create_node(3,"Div_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2466 "test.tab.c"
    break;

  case 138: /* symbol_factor: MOD factor  */
#line 281 "test.y"
                 {(yyval.elem) = create_node(3,"Mod_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2472 "test.tab.c"
    break;

  case 139: /* factor: ADD factor  */
#line 284 "test.y"
                   {(yyval.elem) = create_node(3,"Add_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2478 "test.tab.c"
    break;

  case 140: /* factor: SUB factor  */
#line 285 "test.y"
                 {(yyval.elem) = create_node(3,"Sub_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2484 "test.tab.c"
    break;

  case 141: /* factor: TILDE factor  */
#line 286 "test.y"
                   {(yyval.elem) = create_node(3,"Tilde_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2490 "test.tab.c"
    break;

  case 142: /* factor: power  */
#line 287 "test.y"
            {(yyval.elem) = (yyvsp[0].elem);}
#line 2496 "test.tab.c"
    break;

  case 143: /* power: atom_expr  */
#line 290 "test.y"
                 {(yyval.elem) = (yyvsp[0].elem);}
#line 2502 "test.tab.c"
    break;

  case 144: /* power: atom_expr POW factor  */
#line 291 "test.y"
                           {(yyval.elem) = create_node(4,"Power_term",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2508 "test.tab.c"
    break;

  case 145: /* atom_expr: AWAIT atom trailer_star  */
#line 294 "test.y"
                                   {(yyval.elem)=create_node(4,"Await_stmt",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2514 "test.tab.c"
    break;

  case 146: /* atom_expr: atom trailer_star  */
#line 295 "test.y"
                       {(yyval.elem)=create_node(3,"Terms", (yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2520 "test.tab.c"
    break;

  case 147: /* trailer_star: trailer trailer_star  */
#line 298 "test.y"
                                     {(yyval.elem) = create_node(3,"Stmts",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2526 "test.tab.c"
    break;

  case 148: /* trailer_star: %empty  */
#line 299 "test.y"
               {(yyval.elem)=NULL;}
#line 2532 "test.tab.c"
    break;

  case 149: /* trailer: SMALL_OPEN arglist SMALL_CLOSE  */
#line 303 "test.y"
                                         {(yyval.elem) = create_node(4,"Arguments",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2538 "test.tab.c"
    break;

  case 150: /* trailer: SMALL_OPEN SMALL_CLOSE  */
#line 304 "test.y"
                            { (yyval.elem) = create_node(3,"Parantheses",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2544 "test.tab.c"
    break;

  case 151: /* trailer: BOX_OPEN subscriptlist BOX_CLOSE  */
#line 305 "test.y"
                                      {(yyval.elem) = create_node(4,"Square_bracket",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2550 "test.tab.c"
    break;

  case 152: /* trailer: DOT NAME TYPE_HINT  */
#line 306 "test.y"
                        {(yyval.elem) = create_node(4,"Identifier",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2556 "test.tab.c"
    break;

  case 153: /* trailer: DOT NAME  */
#line 307 "test.y"
              { (yyval.elem) = create_node(3,"Identifier",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2562 "test.tab.c"
    break;

  case 154: /* classdef: CLASS NAME bracket_arglist_optional COLON suite  */
#line 311 "test.y"
                                                          {(yyval.elem)=create_node(6,"Class_def",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2568 "test.tab.c"
    break;

  case 155: /* bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE  */
#line 313 "test.y"
                                                 {(yyval.elem)=create_node(3,"Parantheses",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2574 "test.tab.c"
    break;

  case 156: /* bracket_arglist_optional: SMALL_OPEN arglist SMALL_CLOSE  */
#line 314 "test.y"
                                     {(yyval.elem)=create_node(4,"Arguments",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2580 "test.tab.c"
    break;

  case 157: /* bracket_arglist_optional: %empty  */
#line 315 "test.y"
      {(yyval.elem)=NULL;}
#line 2586 "test.tab.c"
    break;

  case 158: /* arglist: argument_list COMMA  */
#line 318 "test.y"
                             {(yyval.elem)=create_node(3,"Arguments",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2592 "test.tab.c"
    break;

  case 159: /* arglist: argument_list  */
#line 319 "test.y"
                    {(yyval.elem)=(yyvsp[0].elem);}
#line 2598 "test.tab.c"
    break;

  case 160: /* argument_list: argument_list COMMA argument  */
#line 322 "test.y"
                                            { (yyval.elem)=create_node(4,"Arguments",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2604 "test.tab.c"
    break;

  case 161: /* argument_list: argument  */
#line 323 "test.y"
               { (yyval.elem)=(yyvsp[0].elem);}
#line 2610 "test.tab.c"
    break;

  case 162: /* subscriptlist: subscript_list COMMA  */
#line 326 "test.y"
                                    {(yyval.elem)=create_node(3,"Terms",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2616 "test.tab.c"
    break;

  case 163: /* subscriptlist: subscript_list  */
#line 327 "test.y"
                     { (yyval.elem)=(yyvsp[0].elem);}
#line 2622 "test.tab.c"
    break;

  case 164: /* subscript_list: subscript_list COMMA subscript  */
#line 330 "test.y"
                                               { (yyval.elem)=create_node(4,"Terms",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2628 "test.tab.c"
    break;

  case 165: /* subscript_list: subscript  */
#line 331 "test.y"
                { (yyval.elem)=(yyvsp[0].elem);}
#line 2634 "test.tab.c"
    break;

  case 166: /* subscript: test  */
#line 335 "test.y"
                {(yyval.elem)=(yyvsp[0].elem);}
#line 2640 "test.tab.c"
    break;

  case 167: /* subscript: optional_test COLON optional_test  */
#line 336 "test.y"
                                       { (yyval.elem)=create_node(4,"Terms",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2646 "test.tab.c"
    break;

  case 168: /* argument: test  */
#line 340 "test.y"
               { (yyval.elem) = (yyvsp[0].elem);}
#line 2652 "test.tab.c"
    break;

  case 169: /* argument: test comp_for  */
#line 341 "test.y"
                    {(yyval.elem)=create_node(3,"Terms",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2658 "test.tab.c"
    break;

  case 170: /* argument: test EQUAL test  */
#line 342 "test.y"
                       {(yyval.elem)=create_node(4,"Assign_term",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2664 "test.tab.c"
    break;

  case 171: /* argument: POW test  */
#line 343 "test.y"
               {(yyval.elem)=create_node(3,"Power_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2670 "test.tab.c"
    break;

  case 172: /* argument: MUL test  */
#line 344 "test.y"
               {(yyval.elem)=create_node(3,"Mul_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2676 "test.tab.c"
    break;

  case 173: /* optional_test: test  */
#line 347 "test.y"
                    {(yyval.elem)=(yyvsp[0].elem);}
#line 2682 "test.tab.c"
    break;

  case 174: /* optional_test: %empty  */
#line 348 "test.y"
                {(yyval.elem)=NULL;}
#line 2688 "test.tab.c"
    break;

  case 175: /* comp_iter: comp_for  */
#line 351 "test.y"
                    {(yyval.elem)=(yyvsp[0].elem);}
#line 2694 "test.tab.c"
    break;

  case 176: /* comp_iter: comp_if  */
#line 352 "test.y"
              {(yyval.elem)=(yyvsp[0].elem);}
#line 2700 "test.tab.c"
    break;

  case 177: /* sync_comp_for: FOR exprlist IN or_test  */
#line 355 "test.y"
                                       {(yyval.elem)=create_node(5,"For_stmt",(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2706 "test.tab.c"
    break;

  case 178: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 356 "test.y"
                                        {(yyval.elem)=create_node(6,"For_stmt",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2712 "test.tab.c"
    break;

  case 179: /* comp_for: sync_comp_for  */
#line 360 "test.y"
                         {(yyval.elem)=(yyvsp[0].elem);}
#line 2718 "test.tab.c"
    break;

  case 180: /* comp_for: ASYNC sync_comp_for  */
#line 361 "test.y"
                          {(yyval.elem)=create_node(3,"Async_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2724 "test.tab.c"
    break;

  case 181: /* comp_if: IF test_nocond  */
#line 364 "test.y"
                        {(yyval.elem)=create_node(3,"IF_stmt",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2730 "test.tab.c"
    break;

  case 182: /* comp_if: IF test_nocond comp_iter  */
#line 365 "test.y"
                               {(yyval.elem) = create_node(4,"IF_stmt",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2736 "test.tab.c"
    break;

  case 183: /* test_nocond: or_test  */
#line 368 "test.y"
                     {(yyval.elem)=(yyvsp[0].elem);}
#line 2742 "test.tab.c"
    break;

  case 184: /* or_test: and_test or_and_test_star  */
#line 370 "test.y"
                                  {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2748 "test.tab.c"
    break;

  case 185: /* or_and_test_star: OR and_test or_and_test_star  */
#line 372 "test.y"
                                              {(yyval.elem)=create_node(4,"OR_term",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2754 "test.tab.c"
    break;

  case 186: /* or_and_test_star: %empty  */
#line 373 "test.y"
      { (yyval.elem) = NULL;}
#line 2760 "test.tab.c"
    break;

  case 187: /* and_test: not_test and_not_test_star  */
#line 376 "test.y"
                                     {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2766 "test.tab.c"
    break;

  case 188: /* and_not_test_star: AND not_test and_not_test_star  */
#line 378 "test.y"
                                                  {(yyval.elem)=create_node(4,"And_term",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2772 "test.tab.c"
    break;

  case 189: /* and_not_test_star: %empty  */
#line 379 "test.y"
      { (yyval.elem) = NULL;}
#line 2778 "test.tab.c"
    break;

  case 190: /* not_test: NOT not_test  */
#line 382 "test.y"
                       {(yyval.elem)=create_node(3,"Not_term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2784 "test.tab.c"
    break;

  case 191: /* not_test: comparison  */
#line 383 "test.y"
                 {(yyval.elem)=(yyvsp[0].elem);}
#line 2790 "test.tab.c"
    break;

  case 192: /* comparison: expr comp_op_expr_plus  */
#line 387 "test.y"
                                   {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2796 "test.tab.c"
    break;

  case 193: /* comparison: expr  */
#line 388 "test.y"
          {(yyval.elem)=(yyvsp[0].elem);}
#line 2802 "test.tab.c"
    break;

  case 194: /* comp_op_expr_plus: comp_op expr comp_op_expr_plus  */
#line 391 "test.y"
                                                  {(yyval.elem)=create_node(3,"Expresions",(yyvsp[-2].elem),(yyvsp[-1].elem));}
#line 2808 "test.tab.c"
    break;

  case 195: /* comp_op_expr_plus: comp_op expr  */
#line 392 "test.y"
                   {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2814 "test.tab.c"
    break;

  case 196: /* comp_op: LT  */
#line 396 "test.y"
            {(yyval.elem)=(yyvsp[0].elem);}
#line 2820 "test.tab.c"
    break;

  case 197: /* comp_op: GT  */
#line 397 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 2826 "test.tab.c"
    break;

  case 198: /* comp_op: DOUBLE_EQUAL  */
#line 398 "test.y"
                  {(yyval.elem)=(yyvsp[0].elem);}
#line 2832 "test.tab.c"
    break;

  case 199: /* comp_op: GE  */
#line 399 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 2838 "test.tab.c"
    break;

  case 200: /* comp_op: LE  */
#line 400 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 2844 "test.tab.c"
    break;

  case 201: /* comp_op: NE  */
#line 401 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 2850 "test.tab.c"
    break;

  case 202: /* comp_op: IN  */
#line 402 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 2856 "test.tab.c"
    break;

  case 203: /* comp_op: NOT IN  */
#line 403 "test.y"
             {(yyval.elem)=create_node(3, "Not In", (yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2862 "test.tab.c"
    break;

  case 204: /* comp_op: IS  */
#line 404 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 2868 "test.tab.c"
    break;

  case 205: /* comp_op: IS NOT  */
#line 405 "test.y"
            {(yyval.elem)=create_node(3, "Is Not", (yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2874 "test.tab.c"
    break;

  case 206: /* exprlist: expr_star_expr_option_list  */
#line 411 "test.y"
                                {(yyval.elem)=(yyvsp[0].elem);}
#line 2880 "test.tab.c"
    break;

  case 207: /* expr_star_expr_option: expr  */
#line 414 "test.y"
                            {(yyval.elem)=(yyvsp[0].elem);}
#line 2886 "test.tab.c"
    break;

  case 208: /* expr_star_expr_option: star_expr  */
#line 415 "test.y"
                {(yyval.elem)=(yyvsp[0].elem);}
#line 2892 "test.tab.c"
    break;

  case 209: /* expr_star_expr_option_list: expr_star_expr_option COMMA expr_star_expr_option_list  */
#line 418 "test.y"
                                                                                   {(yyval.elem)=create_node(4,"Expressions",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2898 "test.tab.c"
    break;

  case 210: /* expr_star_expr_option_list: expr_star_expr_option COMMA  */
#line 419 "test.y"
                                  {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2904 "test.tab.c"
    break;

  case 211: /* expr_star_expr_option_list: expr_star_expr_option  */
#line 420 "test.y"
                            {(yyval.elem)=(yyvsp[0].elem);}
#line 2910 "test.tab.c"
    break;

  case 212: /* testlist_comp: namedexpr_test_star_expr_option comp_for  */
#line 423 "test.y"
                                                        {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2916 "test.tab.c"
    break;

  case 213: /* testlist_comp: namedexpr_test_star_expr_option_list  */
#line 424 "test.y"
                                            {(yyval.elem)=(yyvsp[0].elem);}
#line 2922 "test.tab.c"
    break;

  case 214: /* namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA namedexpr_test_star_expr_option_list  */
#line 428 "test.y"
                                                                                                                 {(yyval.elem)=create_node(4,"Expressions",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2928 "test.tab.c"
    break;

  case 215: /* namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA  */
#line 429 "test.y"
                                            {(yyval.elem)=create_node(3,"Expressions",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2934 "test.tab.c"
    break;

  case 216: /* namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option  */
#line 430 "test.y"
                                      {(yyval.elem)=(yyvsp[0].elem);}
#line 2940 "test.tab.c"
    break;

  case 217: /* namedexpr_test_star_expr_option: namedexpr_test  */
#line 433 "test.y"
                                                {(yyval.elem)=(yyvsp[0].elem);}
#line 2946 "test.tab.c"
    break;

  case 218: /* namedexpr_test_star_expr_option: star_expr  */
#line 434 "test.y"
                {(yyval.elem)=(yyvsp[0].elem);}
#line 2952 "test.tab.c"
    break;

  case 219: /* namedexpr_test: test  */
#line 437 "test.y"
                     {(yyval.elem)=(yyvsp[0].elem);}
#line 2958 "test.tab.c"
    break;

  case 220: /* test: or_test  */
#line 439 "test.y"
              {(yyval.elem)=(yyvsp[0].elem);}
#line 2964 "test.tab.c"
    break;

  case 221: /* test: or_test IF or_test ELSE test  */
#line 440 "test.y"
                                  {(yyval.elem)=create_node(6,"Expressions",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2970 "test.tab.c"
    break;

  case 222: /* atom: SMALL_OPEN testlist_comp SMALL_CLOSE  */
#line 442 "test.y"
                                           {(yyval.elem)=create_node(4,"Arguments",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2976 "test.tab.c"
    break;

  case 223: /* atom: SMALL_OPEN SMALL_CLOSE  */
#line 443 "test.y"
                             {(yyval.elem)=create_node(3,"Parantheses",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2982 "test.tab.c"
    break;

  case 224: /* atom: BOX_OPEN testlist_comp BOX_CLOSE  */
#line 444 "test.y"
                                       {(yyval.elem)=create_node(4,"Square_bracket",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2988 "test.tab.c"
    break;

  case 225: /* atom: BOX_OPEN BOX_CLOSE  */
#line 445 "test.y"
                         {(yyval.elem)=create_node(3,"Square_bracket",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 2994 "test.tab.c"
    break;

  case 226: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 446 "test.y"
                             {(yyval.elem)=create_node(3,"Curly_bracket",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 3000 "test.tab.c"
    break;

  case 227: /* atom: NAME  */
#line 447 "test.y"
           {(yyval.elem)=(yyvsp[0].elem);}
#line 3006 "test.tab.c"
    break;

  case 228: /* atom: NAME TYPE_HINT  */
#line 448 "test.y"
                     {(yyval.elem)=create_node(3,"Identifier", (yyvsp[-1].elem), (yyvsp[0].elem));}
#line 3012 "test.tab.c"
    break;

  case 229: /* atom: number  */
#line 449 "test.y"
             {(yyval.elem)=(yyvsp[0].elem);}
#line 3018 "test.tab.c"
    break;

  case 230: /* atom: string_plus  */
#line 450 "test.y"
                  {(yyval.elem)=(yyvsp[0].elem);}
#line 3024 "test.tab.c"
    break;

  case 231: /* atom: TRUE  */
#line 451 "test.y"
           {(yyval.elem)=(yyvsp[0].elem);}
#line 3030 "test.tab.c"
    break;

  case 232: /* atom: FALSE  */
#line 452 "test.y"
            {(yyval.elem)=(yyvsp[0].elem);}
#line 3036 "test.tab.c"
    break;

  case 233: /* atom: NONE  */
#line 453 "test.y"
           {(yyval.elem)=(yyvsp[0].elem);}
#line 3042 "test.tab.c"
    break;

  case 234: /* number: INTEGER  */
#line 457 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 3048 "test.tab.c"
    break;

  case 235: /* number: FLOAT  */
#line 458 "test.y"
            {(yyval.elem) = (yyvsp[0].elem);}
#line 3054 "test.tab.c"
    break;

  case 236: /* string_plus: STRING string_plus  */
#line 461 "test.y"
                                {(yyval.elem)=create_node(3,"Strings", (yyvsp[-1].elem), (yyvsp[0].elem));}
#line 3060 "test.tab.c"
    break;

  case 237: /* string_plus: STRING  */
#line 462 "test.y"
             {(yyval.elem)=(yyvsp[0].elem);}
#line 3066 "test.tab.c"
    break;


#line 3070 "test.tab.c"

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

#line 468 "test.y"


NODE* convertParseTreeToAST(NODE* parseTree) {
    if (parseTree == nullptr) {
        return nullptr;
    }

    // If the node is a non-terminal, then skip this node and directly return the AST of the child.
    if (parseTree != start_node){
        NODE* temp = NULL;
        int temp_count = 0;
        for(int i=0;i<parseTree->children.size();i++)
        {
            if(parseTree->children[i]!=NULL){
                temp = parseTree->children[i];
                temp_count++;
            }
        }
        if(temp_count==1){
            //delete the current node and return the child node
            parseTree = NULL;
            return convertParseTreeToAST(temp);
        }
    }

    NODE* astNode = new NODE;
    astNode->id = parseTree->id;
    astNode->val = parseTree->val;
    astNode->is_terminal = parseTree->is_terminal;

    for (NODE* child : parseTree->children) {
        NODE* astChild = convertParseTreeToAST(child);
        astNode->children.push_back(astChild);

    }

    return astNode;
}


void MakeDOTFile(NODE*cell)
{
    if(!cell)
        return;
    
    string value = string(cell->val);
    if(value.length()>2 && value[0]=='"' && value[value.length()-1]=='"')
    {
        value = value.substr(1,value.length()-2);
        value="\\\""+value+"\\\"";
    }
    
    if(cell->is_terminal){
        fout << "\t" << cell->id << "\t\t[ style = solid label = \"" + value + "\" color = red shape = rectangle ];" << endl;
    }
    else
        fout << "\t" << cell->id << "\t\t[ style = solid label = \"" + value + "\"  ];" << endl;

    for(int i=0;i<cell->children.size();i++)
    {
        if(!cell->children[i])
            continue;
        
        fout << "\t" << cell->id << " -> " << cell->children[i]->id << endl;
        MakeDOTFile(cell->children[i]);
    }
} 

int main(int argc, char* argv[]){
    indent_stack.push(0);
    /* yylex(); */

	string output_file = "";
    string input_file = "input.txt";

    if(argc < 2 || argc > 4) {
		cout << "Usage: ./main <input file> <output file> <debug>" << endl;
		cout << "Example: ./main --input=input.py --output=output.dot --verbose" << endl;
		cout<<endl;
		cout << "For more help, run ./main --help" << endl;
		return 0;
	}

	yydebug = 0;
	bool debug = false;
	bool noInputFile = true;

	for(int i=1;i<argc;i++){
		string arg = argv[i];
		if(arg == "--help"){
			cout << "--input : Add this flag for specifying a input file to the parser. This is a required flag." << endl;
			cout << "Example: ./main --input=input.py" << endl;
			cout<<endl;
			cout << "--output Add this flag for specifying a output file to the parser which would contain the output i.e a AST in graphical form. This flag is optional. Default value is output.dot" << endl;
			cout << "Example: ./main --input=input.py --output=result.dot" << endl;
			cout<<endl;
			cout << "--verbose Add this flag for switching on the debug mode in the parser. This flag is optional." << endl;
			cout << "Example: ./main --input=input.py --output=result.dot --verbose" << endl;
			return 0;
		}
		else if(arg.substr(0,8) == "--input="){
			input_file = arg.substr(8);
			noInputFile = false;
		}
		else if(arg.substr(0,9) == "--output="){
			output_file = arg.substr(9);
		}
		else if(arg == "--verbose"){
			debug = true;
		}

		else{
			cout << "Invalid argument: " << arg << endl;
			return 0;
		}
	}

	if(input_file == "" || noInputFile){
		cout << "Please specify an input file." << endl;
		return 0;
	}
	if(output_file == ""){
		output_file = "output.dot";
	}
	if(debug){
		cout << "Input file: " << input_file << endl;
		cout << "Output file: " << output_file << endl;
		cout << "Debug: " << debug << endl;
		yydebug = 1;
	}

    //  Open the input file
	FILE* fp = fopen(("./" + input_file).c_str(), "r");

	if(!fp){
		cout << "Error opening file: " << input_file << endl;
		return 0;
	}
	yyin = fp;
    
    yyparse();
 
    // Close the input file
	fclose(fp);
    
    // Open the output file
    output_file = "output.dot";
	fout.open(output_file.c_str() , ios::out | ios::trunc);
    

    fout<<"digraph G{"<<endl;
    fout << endl;
    fout<<"label     = \"AST\""<<endl;
    fout<<"fontname  = \"Cascadia code\""<<endl;
    fout<<"fontsize  = 30"<<endl;
    fout<<"labelloc  = t"<<endl;
    fout << endl;
    fout<<"node   [ fontname=\"Cascadia code\" ]"<<endl;
    
    NODE* ast = convertParseTreeToAST(start_node);

    MakeDOTFile(ast);

    fout<<"}";
    fout.close();

    return 0;
}


int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}
