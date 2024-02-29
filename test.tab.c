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
  YYSYMBOL_file_input = 93,                /* file_input  */
  YYSYMBOL_stmt = 94,                      /* stmt  */
  YYSYMBOL_simple_stmt = 95,               /* simple_stmt  */
  YYSYMBOL_semi_colon_small_stmt_star = 96, /* semi_colon_small_stmt_star  */
  YYSYMBOL_small_stmt = 97,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 98,                 /* expr_stmt  */
  YYSYMBOL_testlist = 99,                  /* testlist  */
  YYSYMBOL_symbol_test_star = 100,         /* symbol_test_star  */
  YYSYMBOL_expr_stmt_option1_star = 101,   /* expr_stmt_option1_star  */
  YYSYMBOL_annassign = 102,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 103,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_option1_star = 104, /* testlist_star_expr_option1_star  */
  YYSYMBOL_augassign = 105,                /* augassign  */
  YYSYMBOL_expr = 106,                     /* expr  */
  YYSYMBOL_star_expr = 107,                /* star_expr  */
  YYSYMBOL_symbol_xor_expr_star = 108,     /* symbol_xor_expr_star  */
  YYSYMBOL_xor_expr = 109,                 /* xor_expr  */
  YYSYMBOL_symbol_and_expr_star = 110,     /* symbol_and_expr_star  */
  YYSYMBOL_and_expr = 111,                 /* and_expr  */
  YYSYMBOL_symbol_shift_expr_star = 112,   /* symbol_shift_expr_star  */
  YYSYMBOL_shift_expr = 113,               /* shift_expr  */
  YYSYMBOL_shift_arith_expr_star = 114,    /* shift_arith_expr_star  */
  YYSYMBOL_arith_expr = 115,               /* arith_expr  */
  YYSYMBOL_symbol_term_star = 116,         /* symbol_term_star  */
  YYSYMBOL_term = 117,                     /* term  */
  YYSYMBOL_symbol_factor_star = 118,       /* symbol_factor_star  */
  YYSYMBOL_symbol_factor = 119,            /* symbol_factor  */
  YYSYMBOL_factor = 120,                   /* factor  */
  YYSYMBOL_power = 121,                    /* power  */
  YYSYMBOL_atom_expr = 122,                /* atom_expr  */
  YYSYMBOL_trailer_star = 123,             /* trailer_star  */
  YYSYMBOL_trailer = 124,                  /* trailer  */
  YYSYMBOL_arglist = 125,                  /* arglist  */
  YYSYMBOL_argument_list = 126,            /* argument_list  */
  YYSYMBOL_subscriptlist = 127,            /* subscriptlist  */
  YYSYMBOL_subscript_list = 128,           /* subscript_list  */
  YYSYMBOL_subscript = 129,                /* subscript  */
  YYSYMBOL_argument = 130,                 /* argument  */
  YYSYMBOL_optional_test = 131,            /* optional_test  */
  YYSYMBOL_comp_iter = 132,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 133,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 134,                 /* comp_for  */
  YYSYMBOL_comp_if = 135,                  /* comp_if  */
  YYSYMBOL_test_nocond = 136,              /* test_nocond  */
  YYSYMBOL_or_test = 137,                  /* or_test  */
  YYSYMBOL_or_and_test_star = 138,         /* or_and_test_star  */
  YYSYMBOL_and_test = 139,                 /* and_test  */
  YYSYMBOL_and_not_test_star = 140,        /* and_not_test_star  */
  YYSYMBOL_not_test = 141,                 /* not_test  */
  YYSYMBOL_comparison = 142,               /* comparison  */
  YYSYMBOL_comp_op_expr_star = 143,        /* comp_op_expr_star  */
  YYSYMBOL_comp_op = 144,                  /* comp_op  */
  YYSYMBOL_exprlist = 145,                 /* exprlist  */
  YYSYMBOL_expr_star_expr_option = 146,    /* expr_star_expr_option  */
  YYSYMBOL_expr_star_expr_option_list = 147, /* expr_star_expr_option_list  */
  YYSYMBOL_testlist_comp = 148,            /* testlist_comp  */
  YYSYMBOL_namedexpr_test_star_expr_option_list = 149, /* namedexpr_test_star_expr_option_list  */
  YYSYMBOL_namedexpr_test_star_expr_option = 150, /* namedexpr_test_star_expr_option  */
  YYSYMBOL_namedexpr_test = 151,           /* namedexpr_test  */
  YYSYMBOL_test = 152,                     /* test  */
  YYSYMBOL_atom = 153,                     /* atom  */
  YYSYMBOL_number = 154,                   /* number  */
  YYSYMBOL_string_plus = 155               /* string_plus  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   433

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

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
       0,    28,    28,    29,    30,    32,    35,    38,    39,    40,
      54,    56,    57,    58,    59,    60,    63,    65,    66,    67,
      77,    78,    81,    82,    85,    86,    89,    90,    91,    92,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   121,   123,   125,   126,   129,   131,   132,
     135,   137,   138,   141,   143,   144,   145,   148,   150,   151,
     152,   155,   157,   158,   161,   162,   163,   164,   167,   168,
     169,   170,   173,   174,   177,   178,   181,   182,   185,   186,
     187,   188,   191,   192,   195,   196,   199,   200,   203,   204,
     208,   209,   213,   214,   215,   216,   217,   220,   221,   224,
     225,   228,   229,   233,   234,   237,   238,   241,   243,   245,
     246,   249,   251,   252,   255,   256,   259,   261,   262,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   280,
     283,   284,   287,   288,   289,   292,   293,   296,   297,   298,
     301,   302,   305,   307,   308,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   324,   325,   328,   329
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
  "file_input", "stmt", "simple_stmt", "semi_colon_small_stmt_star",
  "small_stmt", "expr_stmt", "testlist", "symbol_test_star",
  "expr_stmt_option1_star", "annassign", "testlist_star_expr",
  "testlist_star_expr_option1_star", "augassign", "expr", "star_expr",
  "symbol_xor_expr_star", "xor_expr", "symbol_and_expr_star", "and_expr",
  "symbol_shift_expr_star", "shift_expr", "shift_arith_expr_star",
  "arith_expr", "symbol_term_star", "term", "symbol_factor_star",
  "symbol_factor", "factor", "power", "atom_expr", "trailer_star",
  "trailer", "arglist", "argument_list", "subscriptlist", "subscript_list",
  "subscript", "argument", "optional_test", "comp_iter", "sync_comp_for",
  "comp_for", "comp_if", "test_nocond", "or_test", "or_and_test_star",
  "and_test", "and_not_test_star", "not_test", "comparison",
  "comp_op_expr_star", "comp_op", "exprlist", "expr_star_expr_option",
  "expr_star_expr_option_list", "testlist_comp",
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

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,     8,  -111,   371,  -111,  -111,  -111,  -111,  -111,   -22,
     330,   330,   330,   330,   132,   197,   -30,   269,    40,     8,
    -111,    -8,  -111,   331,   159,    -1,    16,    28,    20,   -23,
       4,   -11,  -111,    32,    17,    15,    18,  -111,    -1,   -21,
    -111,  -111,  -111,   -21,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    35,  -111,     2,  -111,  -111,  -111,    34,  -111,  -111,
    -111,  -111,    21,    92,   269,    21,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    23,
    -111,   269,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    22,
      26,  -111,   330,    21,  -111,   330,  -111,   330,  -111,   330,
    -111,   330,   330,  -111,   330,   330,  -111,   330,   330,   330,
     330,  -111,   -11,   330,   269,   269,  -111,   269,  -111,  -111,
     120,   269,    95,  -111,   -21,  -111,  -111,    78,   319,    21,
    -111,  -111,  -111,    -8,  -111,    43,    44,  -111,  -111,    60,
    -111,  -111,   159,    -1,    -1,    16,    28,    20,   -23,   -23,
       4,     4,  -111,  -111,  -111,  -111,  -111,  -111,    45,    15,
      18,   269,   269,  -111,    66,    72,  -111,    29,    67,    75,
    -111,    74,    76,  -111,  -111,  -111,  -111,  -111,    65,    83,
    -111,  -111,    84,  -111,    21,  -111,   269,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   269,  -111,
    -111,  -111,  -111,  -111,   208,   269,  -111,  -111,   258,   269,
     269,   319,  -111,    60,  -111,  -111,  -111,  -111,  -111,  -111,
       1,  -111,  -111,   269,  -111,  -111,  -111,     1,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     4,   150,     0,   154,   155,   153,   156,   157,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     9,    10,    13,   118,    29,    46,    49,    52,    54,
      58,    62,    71,    72,   143,   110,   113,   115,    29,    77,
     151,   152,     2,    77,   158,    44,    68,    69,    70,   146,
     141,     0,   136,   139,   140,   142,   148,     0,   149,   114,
       1,     3,     8,     0,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    14,
      11,     0,   121,   124,   119,   120,   123,   122,   125,   127,
       0,   116,     0,    28,    25,     0,    43,     0,    47,     0,
      50,     0,     0,    53,     0,     0,    57,     0,     0,     0,
       0,    61,    62,     0,     0,     0,   108,     0,   111,    24,
       0,    98,     0,    75,    77,    74,   145,     0,     0,   138,
     103,   135,   147,     9,     6,    22,    21,    15,    12,    19,
     128,   126,   118,    29,    29,    46,    49,    52,    54,    54,
      58,    58,    67,    66,    64,    65,    63,    73,     0,   110,
     113,     0,     0,    79,     0,    83,    85,    92,     0,    87,
      89,     0,    90,    81,    76,   104,   130,   131,     0,   134,
     129,   137,   139,     7,     0,    20,    18,    16,   117,    27,
      26,    45,    48,    51,    55,    56,    59,    60,     0,   109,
     112,    95,    96,    78,    82,     0,    93,    80,    86,    98,
       0,   133,    23,    19,   144,    84,    94,    88,    91,    97,
     101,   132,    17,     0,   102,    99,   100,   105,   107,   106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,    19,  -111,  -111,     7,    79,  -111,  -111,   -71,    12,
    -111,   -62,   -20,  -111,   -10,   -13,     5,    49,     3,    54,
      13,    55,   -87,   -25,   -64,   -16,    53,  -111,    -3,  -111,
    -111,   -32,  -111,  -111,  -111,  -111,  -111,   -53,   -43,   -42,
     -61,    46,   -46,  -111,  -111,  -110,    24,    56,    25,     0,
    -111,    39,  -111,  -111,  -111,   -24,   171,    59,    64,  -111,
      -9,   199,  -111,   194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    18,    19,    20,    63,    21,    22,   138,   187,    79,
      80,    23,    94,    81,    24,    25,    96,    26,    98,    27,
     100,    28,   103,    29,   106,    30,   111,   112,    31,    32,
      33,   123,   124,   164,   165,   168,   169,   170,   166,   171,
     224,   130,   225,   226,   227,    34,   116,    35,   118,    36,
      37,    91,    92,   178,   179,   180,    51,    52,    53,    54,
      38,    39,    40,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    50,    50,   136,   158,    55,    55,   131,    46,    47,
      48,   125,     1,   127,   127,     2,     9,    59,   119,     3,
      42,     4,     5,     6,   101,   102,   128,   128,     2,   107,
     108,   109,     3,    58,     4,     5,     6,   120,    61,   121,
      60,   127,   110,   122,     7,     8,     9,   104,   105,    62,
      10,    11,    12,    93,   128,   135,   129,     7,     8,     9,
      13,   194,   195,    10,    11,    12,    14,    95,    15,    99,
      16,   113,   139,    13,   223,   205,   148,   149,    97,    14,
     143,    15,   142,    16,   144,    17,   196,   197,   150,   151,
     114,   115,   174,   117,   126,   132,   134,   141,    17,   140,
     220,   137,   173,   128,   152,   153,   154,   155,   184,    65,
     157,   167,   172,   228,   186,   177,    50,   160,   176,   198,
      55,   206,   212,   189,   190,   203,   204,     2,   207,   208,
     209,     3,   -97,     4,     5,     6,   210,   211,   129,     2,
     183,   133,   222,     3,   145,     4,     5,     6,   185,   192,
     191,   146,   201,   202,   147,   217,     7,     8,     9,   161,
     193,   215,   162,    11,    12,   156,   229,   218,     7,     8,
       9,   159,    13,   175,    10,    11,    12,   213,    14,   163,
      15,   188,    16,   199,    13,   200,    57,   221,   181,   214,
      14,    49,    15,   182,    16,   167,   216,    17,   177,   172,
     219,   176,    43,    44,     2,     0,     0,     0,     3,    17,
       4,     5,     6,     0,     0,     2,     0,     0,     0,     3,
       0,     4,     5,     6,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     7,     8,     9,    90,     0,     0,    10,
      11,    12,     0,     0,     7,     8,     9,   161,     0,    13,
     162,    11,    12,     0,     0,    14,     0,    15,    56,    16,
      13,     0,     0,     0,     0,     2,    14,     0,    15,     3,
      16,     4,     5,     6,    17,     0,     2,     0,     0,     0,
       3,     0,     4,     5,     6,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    11,    12,     0,     0,     7,     8,     9,     0,     0,
      13,     0,    11,    12,   -98,     0,    14,     0,    15,     0,
      16,    13,     0,     0,     0,     0,     2,    14,     0,    15,
       3,    16,     4,     5,     6,    17,     0,     2,     0,     0,
       0,     3,     0,     4,     5,     6,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,    10,    11,    12,     0,     0,     7,     8,     9,     0,
       0,    13,     0,    11,    12,     0,     0,    14,     2,    15,
       0,    16,    13,     0,     4,     5,     6,    64,    14,     0,
      15,     0,    16,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,     0,    14,
       0,    15,     0,    16
};

static const yytype_int16 yycheck[] =
{
      10,    14,    15,    65,   114,    14,    15,    53,    11,    12,
      13,    43,     4,    12,    12,     7,    38,    17,    38,    11,
       1,    13,    14,    15,    47,    48,    25,    25,     7,    40,
      41,    42,    11,    63,    13,    14,    15,    58,    19,    60,
       0,    12,    53,    64,    36,    37,    38,    43,    44,    57,
      42,    43,    44,    54,    25,    64,    54,    36,    37,    38,
      52,   148,   149,    42,    43,    44,    58,    51,    60,    49,
      62,    39,    81,    52,    73,    46,   101,   102,    50,    58,
      93,    60,    92,    62,    93,    77,   150,   151,   104,   105,
      73,    76,   124,    75,    59,    61,     4,    71,    77,    77,
     210,    78,     7,    25,   107,   108,   109,   110,    65,    65,
     113,   120,   121,   223,    54,   128,   129,   117,   128,    74,
     129,   167,   184,   143,   144,    59,    54,     7,    61,    54,
      56,    11,    56,    13,    14,    15,    71,    54,    54,     7,
     133,    62,   213,    11,    95,    13,    14,    15,   136,   146,
     145,    97,   161,   162,    99,   208,    36,    37,    38,    39,
     147,   204,    42,    43,    44,   112,   227,   209,    36,    37,
      38,   115,    52,   127,    42,    43,    44,   186,    58,    59,
      60,   142,    62,   159,    52,   160,    15,   211,   129,   198,
      58,    59,    60,   129,    62,   204,   205,    77,   211,   208,
     209,   211,     3,     9,     7,    -1,    -1,    -1,    11,    77,
      13,    14,    15,    -1,    -1,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    36,    37,    38,    77,    -1,    -1,    42,
      43,    44,    -1,    -1,    36,    37,    38,    39,    -1,    52,
      42,    43,    44,    -1,    -1,    58,    -1,    60,    61,    62,
      52,    -1,    -1,    -1,    -1,     7,    58,    -1,    60,    11,
      62,    13,    14,    15,    77,    -1,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    36,    37,    38,    -1,    -1,
      52,    -1,    43,    44,    56,    -1,    58,    -1,    60,    -1,
      62,    52,    -1,    -1,    -1,    -1,     7,    58,    -1,    60,
      11,    62,    13,    14,    15,    77,    -1,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    36,    37,    38,    -1,
      -1,    52,    -1,    43,    44,    -1,    -1,    58,     7,    60,
      -1,    62,    52,    -1,    13,    14,    15,    56,    58,    -1,
      60,    -1,    62,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,    11,    13,    14,    15,    36,    37,    38,
      42,    43,    44,    52,    58,    60,    62,    77,    93,    94,
      95,    97,    98,   103,   106,   107,   109,   111,   113,   115,
     117,   120,   121,   122,   137,   139,   141,   142,   152,   153,
     154,   155,    93,   153,   155,   106,   120,   120,   120,    59,
     107,   148,   149,   150,   151,   152,    61,   148,    63,   141,
       0,    93,    57,    96,    56,    65,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   101,
     102,   105,    65,    66,    67,    68,    69,    70,    71,    72,
      77,   143,   144,    54,   104,    51,   108,    50,   110,    49,
     112,    47,    48,   114,    43,    44,   116,    40,    41,    42,
      53,   118,   119,    39,    73,    76,   138,    75,   140,   104,
      58,    60,    64,   123,   124,   123,    59,    12,    25,    54,
     133,   134,    61,    97,     4,   152,   103,    78,    99,   152,
      77,    71,   106,   107,   152,   109,   111,   113,   115,   115,
     117,   117,   120,   120,   120,   120,   118,   120,   137,   139,
     141,    39,    42,    59,   125,   126,   130,   152,   127,   128,
     129,   131,   152,     7,   123,   133,   106,   107,   145,   146,
     147,   149,   150,    96,    65,   101,    54,   100,   143,   104,
     104,   108,   110,   112,   114,   114,   116,   116,    74,   138,
     140,   152,   152,    59,    54,    46,   134,    61,    54,    56,
      71,    54,   103,   152,   152,   130,   152,   129,   131,   152,
     137,   147,   100,    73,   132,   134,   135,   136,   137,   132
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    94,    95,    96,    96,    96,
      97,    98,    98,    98,    98,    98,    99,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   106,   107,   108,   108,   109,   110,   110,
     111,   112,   112,   113,   114,   114,   114,   115,   116,   116,
     116,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   137,   138,
     138,   139,   140,   140,   141,   141,   142,   143,   143,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   145,
     146,   146,   147,   147,   147,   148,   148,   149,   149,   149,
     150,   150,   151,   152,   152,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   154,   154,   155,   155
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     3,     3,     1,     0,
       1,     2,     3,     1,     2,     3,     2,     3,     1,     0,
       3,     2,     2,     4,     2,     2,     3,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     0,     2,     3,     0,
       2,     3,     0,     2,     0,     3,     3,     2,     0,     3,
       3,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     3,     3,     2,     2,     0,     3,     2,
       3,     2,     2,     1,     3,     1,     2,     1,     3,     1,
       1,     3,     1,     2,     3,     2,     2,     1,     0,     1,
       1,     4,     5,     1,     2,     2,     3,     1,     2,     3,
       0,     2,     3,     0,     2,     1,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       1,     1,     1,     1,     5,     3,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1
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

#line 1453 "test.tab.c"

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

#line 335 "test.y"


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
