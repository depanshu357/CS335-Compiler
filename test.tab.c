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
  YYSYMBOL_TYPE_COMMENT = 79,              /* TYPE_COMMENT  */
  YYSYMBOL_ADD_ASSIGN = 80,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 81,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 82,                /* MUL_ASSIGN  */
  YYSYMBOL_AT_ASSIGN = 83,                 /* AT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 84,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 85,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 86,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 87,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 88,                /* XOR_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 89,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 90,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_POW_ASSIGN = 91,                /* POW_ASSIGN  */
  YYSYMBOL_FLOOR_DIV_ASSIGN = 92,          /* FLOOR_DIV_ASSIGN  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_file_input = 94,                /* file_input  */
  YYSYMBOL_stmt = 95,                      /* stmt  */
  YYSYMBOL_compound_stmt = 96,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 97,                   /* if_stmt  */
  YYSYMBOL_elif_namedexpr_test_colon_suite_star = 98, /* elif_namedexpr_test_colon_suite_star  */
  YYSYMBOL_while_stmt = 99,                /* while_stmt  */
  YYSYMBOL_for_stmt = 100,                 /* for_stmt  */
  YYSYMBOL_try_stmt = 101,                 /* try_stmt  */
  YYSYMBOL_except_clause_colon_suite = 102, /* except_clause_colon_suite  */
  YYSYMBOL_try_stmt_options = 103,         /* try_stmt_options  */
  YYSYMBOL_except_clause = 104,            /* except_clause  */
  YYSYMBOL_test_as_name_optional = 105,    /* test_as_name_optional  */
  YYSYMBOL_funcdef = 106,                  /* funcdef  */
  YYSYMBOL_parameters = 107,               /* parameters  */
  YYSYMBOL_func_body_suite = 108,          /* func_body_suite  */
  YYSYMBOL_suite = 109,                    /* suite  */
  YYSYMBOL_stmt_plus = 110,                /* stmt_plus  */
  YYSYMBOL_simple_stmt = 111,              /* simple_stmt  */
  YYSYMBOL_semi_colon_small_stmt_star = 112, /* semi_colon_small_stmt_star  */
  YYSYMBOL_small_stmt = 113,               /* small_stmt  */
  YYSYMBOL_flow_stmt = 114,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 115,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 116,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 117,              /* return_stmt  */
  YYSYMBOL_raise_stmt = 118,               /* raise_stmt  */
  YYSYMBOL_global_stmt = 119,              /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 120,            /* nonlocal_stmt  */
  YYSYMBOL_comma_name_star = 121,          /* comma_name_star  */
  YYSYMBOL_assert_stmt = 122,              /* assert_stmt  */
  YYSYMBOL_expr_stmt = 123,                /* expr_stmt  */
  YYSYMBOL_testlist = 124,                 /* testlist  */
  YYSYMBOL_symbol_test_star = 125,         /* symbol_test_star  */
  YYSYMBOL_expr_stmt_option1_plus = 126,   /* expr_stmt_option1_plus  */
  YYSYMBOL_annassign = 127,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 128,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_option1_star = 129, /* testlist_star_expr_option1_star  */
  YYSYMBOL_augassign = 130,                /* augassign  */
  YYSYMBOL_expr = 131,                     /* expr  */
  YYSYMBOL_star_expr = 132,                /* star_expr  */
  YYSYMBOL_symbol_xor_expr_star = 133,     /* symbol_xor_expr_star  */
  YYSYMBOL_xor_expr = 134,                 /* xor_expr  */
  YYSYMBOL_symbol_and_expr_star = 135,     /* symbol_and_expr_star  */
  YYSYMBOL_and_expr = 136,                 /* and_expr  */
  YYSYMBOL_symbol_shift_expr_star = 137,   /* symbol_shift_expr_star  */
  YYSYMBOL_shift_expr = 138,               /* shift_expr  */
  YYSYMBOL_shift_arith_expr_star = 139,    /* shift_arith_expr_star  */
  YYSYMBOL_arith_expr = 140,               /* arith_expr  */
  YYSYMBOL_symbol_term_star = 141,         /* symbol_term_star  */
  YYSYMBOL_term = 142,                     /* term  */
  YYSYMBOL_symbol_factor_star = 143,       /* symbol_factor_star  */
  YYSYMBOL_symbol_factor = 144,            /* symbol_factor  */
  YYSYMBOL_factor = 145,                   /* factor  */
  YYSYMBOL_power = 146,                    /* power  */
  YYSYMBOL_atom_expr = 147,                /* atom_expr  */
  YYSYMBOL_trailer_star = 148,             /* trailer_star  */
  YYSYMBOL_trailer = 149,                  /* trailer  */
  YYSYMBOL_classdef = 150,                 /* classdef  */
  YYSYMBOL_bracket_arglist_optional = 151, /* bracket_arglist_optional  */
  YYSYMBOL_arglist = 152,                  /* arglist  */
  YYSYMBOL_argument_list = 153,            /* argument_list  */
  YYSYMBOL_subscriptlist = 154,            /* subscriptlist  */
  YYSYMBOL_subscript_list = 155,           /* subscript_list  */
  YYSYMBOL_subscript = 156,                /* subscript  */
  YYSYMBOL_argument = 157,                 /* argument  */
  YYSYMBOL_optional_test = 158,            /* optional_test  */
  YYSYMBOL_comp_iter = 159,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 160,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 161,                 /* comp_for  */
  YYSYMBOL_comp_if = 162,                  /* comp_if  */
  YYSYMBOL_test_nocond = 163,              /* test_nocond  */
  YYSYMBOL_or_test = 164,                  /* or_test  */
  YYSYMBOL_or_and_test_star = 165,         /* or_and_test_star  */
  YYSYMBOL_and_test = 166,                 /* and_test  */
  YYSYMBOL_and_not_test_star = 167,        /* and_not_test_star  */
  YYSYMBOL_not_test = 168,                 /* not_test  */
  YYSYMBOL_comparison = 169,               /* comparison  */
  YYSYMBOL_comp_op_expr_plus = 170,        /* comp_op_expr_plus  */
  YYSYMBOL_comp_op = 171,                  /* comp_op  */
  YYSYMBOL_exprlist = 172,                 /* exprlist  */
  YYSYMBOL_expr_star_expr_option = 173,    /* expr_star_expr_option  */
  YYSYMBOL_expr_star_expr_option_list = 174, /* expr_star_expr_option_list  */
  YYSYMBOL_testlist_comp = 175,            /* testlist_comp  */
  YYSYMBOL_namedexpr_test_star_expr_option_list = 176, /* namedexpr_test_star_expr_option_list  */
  YYSYMBOL_namedexpr_test_star_expr_option = 177, /* namedexpr_test_star_expr_option  */
  YYSYMBOL_namedexpr_test = 178,           /* namedexpr_test  */
  YYSYMBOL_test = 179,                     /* test  */
  YYSYMBOL_atom = 180,                     /* atom  */
  YYSYMBOL_number = 181,                   /* number  */
  YYSYMBOL_string_plus = 182               /* string_plus  */
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
#define YYFINAL  103
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   973

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   347


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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    28,    28,    29,    30,    32,    33,    36,    37,    38,
      39,    40,    41,    44,    45,    48,    49,    52,    53,    56,
      57,    58,    59,    62,    63,    66,    67,    70,    71,    72,
      73,    76,    78,    79,    80,    83,    84,    85,    86,    90,
      92,    93,    94,    96,    97,   100,   101,   104,   107,   108,
     109,   120,   121,   122,   123,   124,   127,   128,   129,   130,
     133,   135,   137,   138,   141,   142,   143,   146,   148,   150,
     151,   154,   155,   158,   159,   160,   161,   162,   165,   167,
     168,   169,   179,   180,   183,   184,   187,   188,   191,   192,
     193,   194,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   221,   221,   221,   221,   223,   225,   227,   228,   231,
     233,   234,   237,   239,   240,   243,   245,   246,   247,   250,
     252,   253,   254,   257,   259,   260,   263,   264,   265,   266,
     269,   270,   271,   272,   275,   276,   279,   280,   283,   284,
     287,   288,   289,   290,   293,   295,   296,   297,   300,   301,
     304,   305,   308,   309,   312,   313,   317,   318,   322,   323,
     324,   325,   326,   329,   330,   333,   334,   337,   338,   342,
     343,   346,   347,   350,   352,   354,   355,   358,   360,   361,
     364,   365,   369,   370,   373,   374,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   399,   402,   403,   406,
     407,   408,   411,   412,   415,   416,   417,   420,   421,   424,
     426,   427,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   443,   444,   447,   448
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
  "GE", "IN", "IS", "IF", "ELSE", "AND", "OR", "NOT", "TYPE_COMMENT",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "AT_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN",
  "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN", "POW_ASSIGN",
  "FLOOR_DIV_ASSIGN", "$accept", "file_input", "stmt", "compound_stmt",
  "if_stmt", "elif_namedexpr_test_colon_suite_star", "while_stmt",
  "for_stmt", "try_stmt", "except_clause_colon_suite", "try_stmt_options",
  "except_clause", "test_as_name_optional", "funcdef", "parameters",
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

#define YYPACT_NINF (-267)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-165)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     444,   444,  -267,    91,  -267,  -267,  -267,  -267,   848,    17,
     787,  -267,   206,   -27,    30,    34,   848,   848,    39,  -267,
    -267,    12,   898,   898,   898,   898,   708,   719,   -15,   848,
     848,    85,   444,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
      33,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
     881,   138,    43,    48,    51,    59,    63,    14,    42,  -267,
      86,  -267,    19,    47,    50,  -267,    43,    36,  -267,  -267,
    -267,    36,   122,    74,  -267,  -267,  -267,    61,    80,  -267,
     496,    77,    82,    83,  -267,    84,    82,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,    93,  -267,    26,  -267,  -267,    94,
    -267,    88,  -267,  -267,  -267,    29,   152,   787,   848,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,    81,  -267,   848,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,    87,    89,  -267,   898,   787,  -267,   898,  -267,
     898,  -267,   898,  -267,   898,   898,  -267,   898,   898,  -267,
     898,   898,   898,   898,  -267,    42,   898,   848,   848,  -267,
     848,  -267,  -267,   646,   848,   155,  -267,    36,  -267,   848,
     658,   103,   848,   206,   163,    56,  -267,   848,   -26,   162,
    -267,   496,   848,  -267,  -267,   145,   206,   787,  -267,  -267,
    -267,   496,    33,  -267,   126,   127,  -267,  -267,   125,  -267,
    -267,   138,    43,    43,    48,    51,    59,    63,    63,    14,
      14,  -267,  -267,  -267,  -267,  -267,  -267,   107,    47,    50,
     848,   848,  -267,   124,   130,  -267,    10,   128,   131,  -267,
     136,   143,  -267,  -267,  -267,  -267,   141,   496,   146,  -267,
     596,   848,   147,     4,   156,   159,   270,   848,    82,   112,
    -267,  -267,   150,  -267,   169,   214,  -267,  -267,   787,   848,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,   848,  -267,  -267,  -267,  -267,  -267,   776,   848,  -267,
    -267,   837,   848,  -267,  -267,   332,   596,   219,  -267,   198,
     496,   171,   172,  -267,   496,  -267,     9,   546,  -267,  -267,
     173,  -267,   174,   848,   848,   157,  -267,   125,  -267,  -267,
    -267,  -267,  -267,  -267,   496,   158,  -267,  -267,   224,  -267,
     496,   496,   215,   596,   232,  -267,   382,   496,     3,   181,
     182,  -267,   164,   189,  -267,  -267,   225,  -267,   245,   247,
     546,  -267,  -267,   848,  -267,  -267,  -267,   496,   496,   199,
     496,   200,  -267,   596,  -267,     3,  -267,   214,  -267,   496,
    -267,   496,   251,  -267,  -267,  -267,  -267,  -267
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     4,   217,     0,   221,   222,   220,    60,    64,     0,
      63,    61,     0,     0,     0,     0,     0,     0,     0,   223,
     224,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     6,     7,     8,     9,    10,    11,     5,
      50,    52,    56,    57,    58,    59,    53,    54,    55,    51,
      75,   183,    91,   108,   111,   114,   116,   120,   124,   133,
     134,    12,   210,   176,   179,   181,    91,   139,   218,   219,
       2,   139,    65,   147,    62,   197,   198,     0,   201,   196,
       0,     0,    70,     0,   209,    72,    70,   225,   106,   130,
     131,   132,   213,   208,     0,   203,   206,   207,   215,     0,
     216,     0,   180,     1,     3,    49,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    76,    73,     0,   188,   191,   186,   187,   190,
     189,   192,   194,     0,   182,     0,    90,    87,     0,   105,
       0,   109,     0,   112,     0,     0,   115,     0,     0,   119,
       0,     0,     0,     0,   123,   124,     0,     0,     0,   174,
       0,   177,    86,     0,   164,     0,   137,   139,   136,     0,
       0,     0,     0,   200,     0,     0,    43,     0,     0,     0,
      68,     0,     0,    67,   212,     0,     0,   205,   169,   202,
     214,     0,    50,    47,    83,    84,    77,    74,    81,   195,
     193,   185,    91,    91,   108,   111,   114,   116,   116,   120,
     120,   129,   128,   126,   127,   125,   135,     0,   176,   179,
       0,     0,   141,     0,   149,   151,   158,     0,   153,   155,
       0,   156,   143,   138,    66,   145,     0,     0,     0,   199,
       0,    34,     0,    30,     0,     0,     0,     0,    70,    18,
      71,   170,     0,   204,   206,    16,    48,    82,     0,    80,
      78,   184,    89,    88,   107,   110,   113,   117,   118,   121,
     122,     0,   175,   178,   161,   162,   140,   148,     0,   159,
     142,   152,   164,   146,   144,     0,    46,     0,    31,    32,
       0,     0,     0,    24,     0,    39,     0,     0,    38,    40,
       0,    69,     0,     0,     0,    14,    85,    81,   211,   150,
     160,   154,   157,   163,     0,    22,    45,    44,     0,    23,
       0,     0,    26,     0,     0,    37,     0,     0,   167,     0,
       0,    79,    21,     0,    33,    29,    28,    25,     0,     0,
       0,    36,    17,     0,   168,   165,   166,     0,     0,     0,
       0,     0,    41,     0,    35,   171,   173,    16,    13,     0,
      20,     0,     0,   172,    15,    19,    27,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -267,    44,    54,  -267,  -267,   -98,  -267,  -267,  -267,   -62,
    -267,  -267,  -267,  -267,  -267,  -266,  -173,  -261,     0,    69,
     165,  -267,  -267,  -267,  -267,  -267,  -267,  -267,   -81,  -267,
    -267,    90,   -44,    73,  -267,    -4,   -57,  -267,     5,     7,
      65,   135,    75,   139,    72,   140,   -94,   -29,   -90,   -25,
     132,  -267,    45,  -267,  -267,   -58,  -267,  -267,  -267,   119,
    -267,  -267,  -267,    11,    18,    21,   -59,   114,   -89,  -267,
    -267,  -153,    92,   151,    96,   -18,  -267,   100,  -267,   133,
    -267,   144,   278,   129,   134,   -13,    -6,   308,  -267,   297
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    31,   286,    33,    34,   305,    35,    36,    37,   243,
     293,   244,   288,    38,   178,   298,   175,   287,   176,   106,
      40,    41,    42,    43,    44,    45,    46,    47,   180,    48,
      49,   197,   260,   122,   123,    50,   137,   124,    51,    52,
     139,    53,   141,    54,   143,    55,   146,    56,   149,    57,
     154,   155,    58,    59,    60,   166,   167,    61,   171,   223,
     224,   227,   228,   229,   225,   230,   344,   188,   345,   346,
     355,    62,   159,    63,   161,    64,    65,   134,   135,    77,
      78,    79,    94,    95,    96,    97,    66,    67,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    39,    72,    83,   217,   183,    74,   189,   249,   162,
      84,    85,   102,   168,   323,   185,   101,    75,   255,    76,
      84,    84,   185,    84,    73,   316,   291,    88,   186,    80,
     246,   325,    39,    93,    93,   186,     2,    81,   185,   247,
       3,    82,     4,     5,     6,    70,    86,     7,   100,     8,
      21,   186,    10,    11,    32,    32,   278,   147,   148,    15,
     341,    17,   338,    18,   284,    19,    20,    21,    89,    90,
      91,    22,    23,    24,   354,   241,   104,   343,   242,   292,
     187,    25,   150,   151,   152,   103,    32,    26,   324,    27,
     105,    28,   362,   157,   163,   153,   164,   136,     2,   138,
     165,   140,   195,   194,     4,     5,     6,    30,   142,   233,
     144,   145,   315,   267,   268,   207,   208,   319,   198,   269,
     270,   322,   209,   210,   158,   156,   160,    19,    20,    21,
     203,   169,   170,   172,   173,   177,   179,   279,   182,   181,
     201,   332,   219,   202,   191,   262,   263,   335,   336,    26,
     328,    27,   184,    28,   342,   190,   193,   226,   231,   237,
     196,   200,   232,   234,   226,   199,   198,   301,   240,   248,
     186,   245,   107,   258,   357,   358,   250,   360,    75,   259,
      76,    84,   271,   276,   277,   281,   365,   302,   366,   280,
     356,    75,   282,    76,    93,   211,   212,   213,   214,  -163,
     283,   216,   285,   290,   125,   126,   127,   128,   129,   130,
     131,   132,   294,     2,   274,   275,   133,     3,   295,     4,
       5,     6,   303,   187,   304,   317,   318,   320,   321,   326,
     327,   334,   330,   333,   241,   289,   339,   347,   348,   349,
      39,   300,    19,    20,    21,   350,   299,   351,    22,    23,
      24,   352,   353,   307,   306,   359,   361,   367,    25,   364,
     337,   256,   238,   331,    26,   308,    27,   257,    28,   264,
     192,   226,   310,   204,   296,   231,   313,     2,   266,   205,
     265,     3,   206,     4,     5,     6,    39,   215,     7,   236,
       8,   329,   311,    10,    11,   309,   363,   299,    84,   251,
      15,   261,    17,   312,    18,    99,    19,    20,    21,   218,
     272,    71,    22,    23,    24,   273,   253,   239,    87,   252,
       0,   254,    25,    39,     0,     0,   299,     0,    26,     0,
      27,     0,    28,     0,     0,     0,   174,     0,     0,     2,
     299,     0,     0,     3,     0,     4,     5,     6,    30,   297,
       7,     0,     8,    39,     0,    10,    11,     0,     0,     0,
       0,     0,    15,     0,    17,     0,    18,     0,    19,    20,
      21,     0,     0,     0,    22,    23,    24,     0,     0,     0,
       0,     0,     0,     0,    25,     0,   296,     0,     0,     2,
      26,     0,    27,     3,    28,     4,     5,     6,     0,     0,
       7,     0,     8,     0,     0,    10,    11,     0,     0,     0,
      30,   314,    15,     0,    17,     0,    18,     0,    19,    20,
      21,     0,     0,     0,    22,    23,    24,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,     0,     0,     0,     1,     0,
       0,     2,     0,     0,     0,     3,     0,     4,     5,     6,
      30,   340,     7,     0,     8,     9,     0,    10,    11,    12,
       0,    13,     0,    14,    15,    16,    17,     0,    18,     0,
      19,    20,    21,     0,     0,     0,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
     174,     0,    26,     2,    27,     0,    28,     3,     0,     4,
       5,     6,     0,     0,     7,     0,     8,     0,    29,    10,
      11,     0,    30,     0,     0,     0,    15,     0,    17,     0,
      18,     0,    19,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,    25,     0,
     296,     0,     0,     2,    26,     0,    27,     3,    28,     4,
       5,     6,     0,     0,     7,     0,     8,     0,     0,    10,
      11,     0,     0,     0,    30,     0,    15,     0,    17,     0,
      18,     0,    19,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     2,    26,     0,    27,     3,    28,     4,
       5,     6,     0,     0,     7,     0,     8,     9,     0,    10,
      11,    12,     0,    13,    30,    14,    15,    16,    17,     0,
      18,     0,    19,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     2,    26,     0,    27,     3,    28,     4,
       5,     6,     0,     0,     0,     2,     0,     0,     0,     3,
      29,     4,     5,     6,    30,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    21,   220,     0,     0,   221,    23,
      24,     0,     0,     0,    19,    20,    21,   220,    25,     0,
     221,    23,    24,     0,    26,   222,    27,     0,    28,     0,
      25,     0,     0,     0,     0,     2,    26,   235,    27,     3,
      28,     4,     5,     6,    30,     0,     2,     0,     0,     0,
       3,     0,     4,     5,     6,     0,    30,     0,     0,     0,
       0,     0,     0,     0,    19,    20,    21,     0,     0,     0,
      22,    23,    24,     0,     0,    19,    20,    21,     0,     0,
      25,    22,    23,    24,     0,     0,    26,    92,    27,     0,
      28,    25,     0,     0,     0,     0,     0,    26,     0,    27,
      98,    28,     0,     2,     0,     0,    30,     3,     0,     4,
       5,     6,     0,     0,     2,     0,     0,    30,     3,     0,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    21,   220,     0,     0,   221,    23,
      24,     0,     0,    19,    20,    21,     0,     0,    25,    22,
      23,    24,     0,     0,    26,     0,    27,     0,    28,    25,
       0,     0,     0,     0,     2,    26,     0,    27,     3,    28,
       4,     5,     6,     0,    30,     2,     0,     0,     0,     3,
       0,     4,     5,     6,     0,    30,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     0,     0,     0,
      23,    24,     0,     0,    19,    20,    21,     0,     0,    25,
       0,    23,    24,  -164,     0,    26,     0,    27,     0,    28,
      25,     0,     0,     0,     0,     2,    26,     0,    27,     3,
      28,     4,     5,     6,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,   107,     0,     0,
       0,     0,     0,     0,    19,    20,    21,   108,     0,     0,
       0,    23,    24,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
       0,     1,     8,    16,   157,    86,    10,    96,   181,    66,
      16,    17,    30,    71,     5,    12,    29,    12,   191,    12,
      26,    27,    12,    29,     7,   286,    22,    22,    25,    56,
      56,   297,    32,    26,    27,    25,     7,     7,    12,    65,
      11,     7,    13,    14,    15,     1,     7,    18,    63,    20,
      38,    25,    23,    24,     0,     1,    46,    43,    44,    30,
     326,    32,   323,    34,   237,    36,    37,    38,    23,    24,
      25,    42,    43,    44,   340,    19,    32,    74,    22,    75,
      54,    52,    40,    41,    42,     0,    32,    58,    79,    60,
      57,    62,   353,    74,    58,    53,    60,    54,     7,    51,
      64,    50,   108,   107,    13,    14,    15,    78,    49,   167,
      47,    48,   285,   207,   208,   144,   145,   290,   124,   209,
     210,   294,   147,   148,    77,    39,    76,    36,    37,    38,
     136,     9,    58,    72,    54,    58,    54,   226,    54,    56,
     135,   314,   160,   136,    56,   202,   203,   320,   321,    58,
     303,    60,    59,    62,   327,    61,     4,   163,   164,    56,
      79,    72,     7,   169,   170,    78,   172,   248,     5,     7,
      25,   177,    46,    46,   347,   348,   182,   350,   173,    54,
     173,   187,    75,    59,    54,    54,   359,    75,   361,    61,
     343,   186,    56,   186,   187,   150,   151,   152,   153,    56,
      59,   156,    56,    56,    66,    67,    68,    69,    70,    71,
      72,    73,    56,     7,   220,   221,    78,    11,    59,    13,
      14,    15,    72,    54,    10,     6,    28,    56,    56,    56,
      56,     7,    75,    75,    19,   241,     4,    56,    56,    75,
     240,   247,    36,    37,    38,    56,   246,    22,    42,    43,
      44,     6,     5,   259,   258,    56,    56,     6,    52,   357,
     322,   192,   172,   307,    58,   271,    60,   194,    62,   204,
     105,   277,   278,   138,     4,   281,   282,     7,   206,   140,
     205,    11,   142,    13,    14,    15,   286,   155,    18,   170,
      20,   304,   281,    23,    24,   277,   355,   297,   304,   185,
      30,   201,    32,   282,    34,    27,    36,    37,    38,   158,
     218,     3,    42,    43,    44,   219,   187,   173,    21,   186,
      -1,   187,    52,   323,    -1,    -1,   326,    -1,    58,    -1,
      60,    -1,    62,    -1,    -1,    -1,     4,    -1,    -1,     7,
     340,    -1,    -1,    11,    -1,    13,    14,    15,    78,    79,
      18,    -1,    20,   353,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    -1,    34,    -1,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,     4,    -1,    -1,     7,
      58,    -1,    60,    11,    62,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      78,    79,    30,    -1,    32,    -1,    34,    -1,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    -1,     4,    -1,
      -1,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      78,    79,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    29,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
       4,    -1,    58,     7,    60,    -1,    62,    11,    -1,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    74,    23,
      24,    -1,    78,    -1,    -1,    -1,    30,    -1,    32,    -1,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
       4,    -1,    -1,     7,    58,    -1,    60,    11,    62,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    78,    -1,    30,    -1,    32,    -1,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,     7,    58,    -1,    60,    11,    62,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    78,    29,    30,    31,    32,    -1,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,     7,    58,    -1,    60,    11,    62,    13,
      14,    15,    -1,    -1,    -1,     7,    -1,    -1,    -1,    11,
      74,    13,    14,    15,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    36,    37,    38,    39,    52,    -1,
      42,    43,    44,    -1,    58,    59,    60,    -1,    62,    -1,
      52,    -1,    -1,    -1,    -1,     7,    58,    59,    60,    11,
      62,    13,    14,    15,    78,    -1,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    36,    37,    38,    -1,    -1,
      52,    42,    43,    44,    -1,    -1,    58,    59,    60,    -1,
      62,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    62,    -1,     7,    -1,    -1,    78,    11,    -1,    13,
      14,    15,    -1,    -1,     7,    -1,    -1,    78,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    36,    37,    38,    -1,    -1,    52,    42,
      43,    44,    -1,    -1,    58,    -1,    60,    -1,    62,    52,
      -1,    -1,    -1,    -1,     7,    58,    -1,    60,    11,    62,
      13,    14,    15,    -1,    78,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    36,    37,    38,    -1,    -1,    52,
      -1,    43,    44,    56,    -1,    58,    -1,    60,    -1,    62,
      52,    -1,    -1,    -1,    -1,     7,    58,    -1,    60,    11,
      62,    13,    14,    15,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    56,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,
      62,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,    11,    13,    14,    15,    18,    20,    21,
      23,    24,    25,    27,    29,    30,    31,    32,    34,    36,
      37,    38,    42,    43,    44,    52,    58,    60,    62,    74,
      78,    94,    95,    96,    97,    99,   100,   101,   106,   111,
     113,   114,   115,   116,   117,   118,   119,   120,   122,   123,
     128,   131,   132,   134,   136,   138,   140,   142,   145,   146,
     147,   150,   164,   166,   168,   169,   179,   180,   181,   182,
      94,   180,   179,     7,   128,   131,   132,   172,   173,   174,
      56,     7,     7,   178,   179,   179,     7,   182,   131,   145,
     145,   145,    59,   132,   175,   176,   177,   178,    61,   175,
      63,   178,   168,     0,    94,    57,   112,    46,    56,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   126,   127,   130,    66,    67,    68,    69,    70,
      71,    72,    73,    78,   170,   171,    54,   129,    51,   133,
      50,   135,    49,   137,    47,    48,   139,    43,    44,   141,
      40,    41,    42,    53,   143,   144,    39,    74,    77,   165,
      76,   167,   129,    58,    60,    64,   148,   149,   148,     9,
      58,   151,    72,    54,     4,   109,   111,    58,   107,    54,
     121,    56,    54,   121,    59,    12,    25,    54,   160,   161,
      61,    56,   113,     4,   128,   179,    79,   124,   179,    78,
      72,   131,   132,   179,   134,   136,   138,   140,   140,   142,
     142,   145,   145,   145,   145,   143,   145,   164,   166,   168,
      39,    42,    59,   152,   153,   157,   179,   154,   155,   156,
     158,   179,     7,   148,   179,    59,   152,    56,   124,   174,
       5,    19,    22,   102,   104,   179,    56,    65,     7,   109,
     179,   160,   172,   176,   177,   109,   112,   126,    46,    54,
     125,   170,   129,   129,   133,   135,   137,   139,   139,   141,
     141,    75,   165,   167,   179,   179,    59,    54,    46,   161,
      61,    54,    56,    59,   109,    56,    95,   110,   105,   179,
      56,    22,    75,   103,    56,    59,     4,    79,   108,   111,
     179,   121,    75,    72,    10,    98,   128,   179,   179,   157,
     179,   156,   158,   179,    79,   109,   110,     6,    28,   109,
      56,    56,   109,     5,    79,   108,    56,    56,   164,   178,
      75,   125,   109,    75,     7,   109,   109,   102,   110,     4,
      79,   108,   109,    74,   159,   161,   162,    56,    56,    75,
      56,    22,     6,     5,   108,   163,   164,   109,   109,    56,
     109,    56,   110,   159,    98,   109,   109,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   103,
     103,   104,   105,   105,   105,   106,   106,   106,   106,   107,
     108,   108,   108,   109,   109,   110,   110,   111,   112,   112,
     112,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     115,   116,   117,   117,   118,   118,   118,   119,   120,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   124,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   131,   132,   133,   133,   134,
     135,   135,   136,   137,   137,   138,   139,   139,   139,   140,
     141,   141,   141,   142,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   149,   150,   151,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     157,   157,   157,   158,   158,   159,   159,   160,   160,   161,
     161,   162,   162,   163,   164,   165,   165,   166,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   172,   173,   173,   174,
     174,   174,   175,   175,   176,   176,   176,   177,   177,   178,
     179,   179,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   181,   181,   182,   182
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     8,     5,     5,     0,     7,     4,    10,
       9,     7,     6,     6,     5,     4,     3,     6,     3,     3,
       0,     2,     1,     3,     0,     8,     7,     6,     5,     3,
       1,     4,     6,     1,     4,     2,     1,     3,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     4,     3,     3,     3,
       0,     4,     2,     2,     3,     1,     2,     3,     2,     3,
       1,     0,     3,     2,     2,     4,     2,     2,     3,     3,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     0,     2,
       3,     0,     2,     3,     0,     2,     0,     3,     3,     2,
       0,     3,     3,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     3,     3,     2,     2,     0,
       3,     2,     3,     2,     5,     2,     3,     0,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     3,     1,     2,
       3,     2,     2,     1,     0,     1,     1,     4,     5,     1,
       2,     2,     3,     1,     2,     3,     0,     2,     3,     0,
       2,     1,     2,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3,
       2,     1,     2,     1,     3,     2,     1,     1,     1,     1,
       1,     5,     3,     2,     3,     2,     2,     1,     1,     1,
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

#line 1662 "test.tab.c"

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

#line 454 "test.y"


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
