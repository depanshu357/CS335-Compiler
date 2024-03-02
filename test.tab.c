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

#line 84 "test.tab.c"

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
  YYSYMBOL_atom_expr = 95,                 /* atom_expr  */
  YYSYMBOL_expr = 96,                      /* expr  */
  YYSYMBOL_star_expr = 97,                 /* star_expr  */
  YYSYMBOL_symbol_xor_expr_star = 98,      /* symbol_xor_expr_star  */
  YYSYMBOL_xor_expr = 99,                  /* xor_expr  */
  YYSYMBOL_symbol_and_expr_star = 100,     /* symbol_and_expr_star  */
  YYSYMBOL_and_expr = 101,                 /* and_expr  */
  YYSYMBOL_symbol_shift_expr_star = 102,   /* symbol_shift_expr_star  */
  YYSYMBOL_shift_expr = 103,               /* shift_expr  */
  YYSYMBOL_shift_arith_expr_star = 104,    /* shift_arith_expr_star  */
  YYSYMBOL_arith_expr = 105,               /* arith_expr  */
  YYSYMBOL_symbol_term_star = 106,         /* symbol_term_star  */
  YYSYMBOL_term = 107,                     /* term  */
  YYSYMBOL_symbol_factor_star = 108,       /* symbol_factor_star  */
  YYSYMBOL_symbol_factor = 109,            /* symbol_factor  */
  YYSYMBOL_factor = 110,                   /* factor  */
  YYSYMBOL_power = 111,                    /* power  */
  YYSYMBOL_trailer_star = 112,             /* trailer_star  */
  YYSYMBOL_trailer = 113,                  /* trailer  */
  YYSYMBOL_arglist = 114,                  /* arglist  */
  YYSYMBOL_argument_list = 115,            /* argument_list  */
  YYSYMBOL_subscriptlist = 116,            /* subscriptlist  */
  YYSYMBOL_subscript_list = 117,           /* subscript_list  */
  YYSYMBOL_subscript = 118,                /* subscript  */
  YYSYMBOL_argument = 119,                 /* argument  */
  YYSYMBOL_optional_test = 120,            /* optional_test  */
  YYSYMBOL_comp_iter = 121,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 122,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 123,                 /* comp_for  */
  YYSYMBOL_comp_if = 124,                  /* comp_if  */
  YYSYMBOL_test_nocond = 125,              /* test_nocond  */
  YYSYMBOL_or_test = 126,                  /* or_test  */
  YYSYMBOL_or_and_test_star = 127,         /* or_and_test_star  */
  YYSYMBOL_and_test = 128,                 /* and_test  */
  YYSYMBOL_and_not_test_star = 129,        /* and_not_test_star  */
  YYSYMBOL_not_test = 130,                 /* not_test  */
  YYSYMBOL_comparison = 131,               /* comparison  */
  YYSYMBOL_comp_op_expr_plus = 132,        /* comp_op_expr_plus  */
  YYSYMBOL_comp_op = 133,                  /* comp_op  */
  YYSYMBOL_exprlist = 134,                 /* exprlist  */
  YYSYMBOL_expr_star_expr_option = 135,    /* expr_star_expr_option  */
  YYSYMBOL_expr_star_expr_option_list = 136, /* expr_star_expr_option_list  */
  YYSYMBOL_testlist_comp = 137,            /* testlist_comp  */
  YYSYMBOL_namedexpr_test_star_expr_option_list = 138, /* namedexpr_test_star_expr_option_list  */
  YYSYMBOL_namedexpr_test_star_expr_option = 139, /* namedexpr_test_star_expr_option  */
  YYSYMBOL_namedexpr_test = 140,           /* namedexpr_test  */
  YYSYMBOL_test = 141,                     /* test  */
  YYSYMBOL_atom = 142,                     /* atom  */
  YYSYMBOL_number = 143,                   /* number  */
  YYSYMBOL_string_plus = 144               /* string_plus  */
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
       0,    33,    33,    34,   238,   240,   242,   243,   246,   248,
     249,   252,   254,   255,   258,   260,   261,   262,   265,   267,
     268,   269,   272,   274,   275,   278,   279,   280,   281,   282,
     285,   286,   287,   288,   291,   292,   299,   300,   304,   305,
     306,   307,   308,   319,   320,   323,   324,   327,   328,   331,
     332,   336,   337,   341,   342,   343,   344,   345,   348,   349,
     352,   353,   356,   357,   361,   362,   365,   366,   369,   371,
     373,   374,   377,   379,   380,   383,   384,   388,   389,   392,
     393,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   412,   415,   416,   419,   420,   421,   424,   425,   428,
     429,   430,   433,   434,   437,   439,   440,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   457,
     458,   461,   462
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
  "POW_EQUAL", "FLOOR_DIV_EQUAL", "INDENT", "DEDENT", "$accept",
  "atom_expr", "expr", "star_expr", "symbol_xor_expr_star", "xor_expr",
  "symbol_and_expr_star", "and_expr", "symbol_shift_expr_star",
  "shift_expr", "shift_arith_expr_star", "arith_expr", "symbol_term_star",
  "term", "symbol_factor_star", "symbol_factor", "factor", "power",
  "trailer_star", "trailer", "arglist", "argument_list", "subscriptlist",
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

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     323,   -65,   314,   -99,   -99,   -99,   -99,   -99,    -7,    72,
      83,   -30,    20,   -28,   -99,   -99,   -99,   -28,   -99,   273,
     273,   273,   273,   -99,   212,    -4,   275,   -99,     3,    11,
      16,   -35,     1,   -16,   -99,    -6,   -10,    -1,   -99,    12,
     -99,    -2,   -99,   -99,   -99,    17,   -99,   -99,     4,   212,
      63,   -99,   -28,   -99,   -99,   -99,   -99,   -99,   -99,   273,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,     6,     0,   -99,
     273,   273,   -99,   273,   -99,   273,   -99,   273,   273,   -99,
     273,   273,   -99,   273,   273,   273,   273,   273,   -99,   -16,
     212,   212,   -99,   212,   -99,   -99,    48,   262,   151,   -99,
     -99,   -99,   212,   212,   -99,    29,    35,   -99,     9,    31,
      39,   -99,    43,    44,    22,   -99,   -99,   -99,   -99,   275,
       3,    11,    16,   -35,   -35,     1,     1,   -99,   -99,   -99,
     -99,   -99,   -99,    30,   -10,    -1,   -99,   -99,   -99,    23,
      50,   -99,   -99,    57,   -99,   -99,   -99,   140,   212,   -99,
     -99,   201,   212,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   212,   -99,   -99,   212,   262,   -99,   -99,   -99,
     -99,   -99,   -99,    -5,   -99,   212,   -99,   -99,   -99,    -5,
     -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   112,     0,   116,   117,   118,   119,   120,   122,     0,
       0,     0,     0,    37,   114,   115,   113,    37,   121,     0,
       0,     0,     0,   108,     0,    34,    78,   103,     7,    10,
      13,    15,    19,    23,    33,   105,    71,    74,    76,     0,
      98,   101,   102,   104,   110,     0,   111,     1,     0,    59,
       0,     3,    37,     2,     5,    30,    31,    32,    75,     0,
      83,    86,    81,    82,    85,    84,    87,    89,     0,    77,
       0,     0,     4,     0,     8,     0,    11,     0,     0,    14,
       0,     0,    18,     0,     0,     0,     0,     0,    22,    23,
       0,     0,    69,     0,    72,   107,     0,     0,   100,    64,
      97,   109,     0,     0,    39,     0,    44,    46,    53,     0,
      48,    50,     0,    51,    42,    36,    35,    90,    88,    80,
       7,    10,    13,    15,    15,    19,    19,    28,    27,    25,
      29,    26,    24,     0,    71,    74,    65,    92,    93,     0,
      96,    91,    99,   101,    56,    57,    38,    43,     0,    54,
      40,    47,    59,    41,    79,     6,     9,    12,    16,    17,
      20,    21,     0,    70,    73,     0,    95,    45,    55,    49,
      52,    58,   106,    62,    94,     0,    63,    60,    61,    66,
      68,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   110,   -19,   -94,    -9,    45,     5,    47,    13,    46,
     -98,   -41,   -78,   -23,    38,   -99,   145,   -99,    -3,   -99,
     -99,   -99,   -99,   -99,   -20,   -13,   -15,   -43,    42,   -34,
     -99,   -99,   -86,    10,    49,    15,   -18,   -99,    27,   -99,
     -99,   -99,   -12,   147,    60,    70,   -99,   -47,   153,   -99,
     161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    72,    28,    74,    29,    76,    30,
      79,    31,    82,    32,    88,    89,    33,    34,    51,    52,
     105,   106,   109,   110,   111,   107,   112,   176,    99,   177,
     178,   179,    35,    92,    36,    94,    37,    38,    69,    70,
     139,   140,   141,    39,    40,    41,    42,    43,    13,    14,
      15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   108,   113,   138,   133,    96,    58,   100,    96,     1,
      77,    78,    16,     2,    53,     3,     4,     5,    97,    96,
      47,    97,    83,    84,    85,   158,   159,    86,    48,     8,
      49,    46,    97,    59,    50,    87,   123,   124,     6,     7,
       8,   102,    80,    81,   103,    20,    21,   160,   161,   115,
      98,   119,    71,   148,    22,   144,   145,   125,   126,    73,
       9,   104,    10,    75,    11,    91,    90,   175,   114,    95,
     118,    97,   138,    93,   149,   135,   101,     1,   137,   173,
      24,     2,   117,     3,     4,     5,   146,   147,     1,   180,
     150,   151,     2,   165,     3,     4,     5,   152,   -58,   153,
     108,   168,   166,   162,   113,   171,     6,     7,     8,    98,
      12,   155,    19,    20,    21,   172,   120,     6,     7,     8,
     121,   122,    22,    19,    20,    21,   156,   132,     9,    23,
      10,   169,    11,    22,   167,   157,   181,   170,   136,     9,
     134,    10,    44,    11,   163,     1,   154,   137,    24,     2,
     164,     3,     4,     5,   174,    17,     1,    45,   142,    24,
       2,     0,     3,     4,     5,    55,    56,    57,   143,    18,
       0,     0,     0,     0,     6,     7,     8,   102,     0,     0,
     103,    20,    21,     0,     0,     6,     7,     8,     0,     0,
      22,    19,    20,    21,     0,     0,     9,     0,    10,     0,
      11,    22,     0,     0,   116,     0,     1,     9,     0,    10,
       2,    11,     3,     4,     5,     0,    24,     1,     0,     0,
       0,     2,     0,     3,     4,     5,     0,    24,   127,   128,
     129,   130,   131,     0,     0,     6,     7,     8,     0,     0,
       0,     0,    20,    21,     0,     0,     6,     7,     8,     0,
       0,    22,     0,    20,    21,   -59,     0,     9,     0,    10,
       0,    11,    22,     0,     0,     0,     0,     1,     9,     0,
      10,     2,    11,     3,     4,     5,     0,    24,     1,     0,
       0,     0,     2,     0,     3,     4,     5,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     0,
       0,     0,    19,    20,    21,     0,     0,     6,     7,     8,
       0,     0,    22,     0,    20,    21,     0,     0,     9,     1,
      10,     0,    11,    22,     0,     3,     4,     5,     1,     9,
       0,    10,     2,    11,     3,     4,     5,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,     0,     6,     7,
       8,    68,     0,     0,     0,     0,     0,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    10,     0,    11,     0,     0,     0,     0,     9,
       0,    10,     0,    11
};

static const yytype_int16 yycheck[] =
{
      19,    48,    49,    97,    90,    10,    24,    41,    10,     5,
      45,    46,    77,     9,    17,    11,    12,    13,    23,    10,
       0,    23,    38,    39,    40,   123,   124,    43,    56,    36,
      58,    61,    23,    37,    62,    51,    77,    78,    34,    35,
      36,    37,    41,    42,    40,    41,    42,   125,   126,    52,
      52,    70,    49,    44,    50,   102,   103,    80,    81,    48,
      56,    57,    58,    47,    60,    75,    72,    72,     5,    57,
      70,    23,   166,    74,   108,    93,    59,     5,    97,   165,
      76,     9,    76,    11,    12,    13,    57,    52,     5,   175,
      59,    52,     9,    70,    11,    12,    13,    54,    54,    77,
     147,   148,    52,    73,   151,   152,    34,    35,    36,    52,
       0,   120,    40,    41,    42,   162,    71,    34,    35,    36,
      73,    75,    50,    40,    41,    42,   121,    89,    56,    57,
      58,   151,    60,    50,   147,   122,   179,   152,    96,    56,
      91,    58,    59,    60,   134,     5,   119,   166,    76,     9,
     135,    11,    12,    13,   166,     2,     5,    10,    98,    76,
       9,    -1,    11,    12,    13,    20,    21,    22,    98,     8,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    -1,    -1,    34,    35,    36,    -1,    -1,
      50,    40,    41,    42,    -1,    -1,    56,    -1,    58,    -1,
      60,    50,    -1,    -1,    59,    -1,     5,    56,    -1,    58,
       9,    60,    11,    12,    13,    -1,    76,     5,    -1,    -1,
      -1,     9,    -1,    11,    12,    13,    -1,    76,    83,    84,
      85,    86,    87,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    34,    35,    36,    -1,
      -1,    50,    -1,    41,    42,    54,    -1,    56,    -1,    58,
      -1,    60,    50,    -1,    -1,    -1,    -1,     5,    56,    -1,
      58,     9,    60,    11,    12,    13,    -1,    76,     5,    -1,
      -1,    -1,     9,    -1,    11,    12,    13,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    34,    35,    36,
      -1,    -1,    50,    -1,    41,    42,    -1,    -1,    56,     5,
      58,    -1,    60,    50,    -1,    11,    12,    13,     5,    56,
      -1,    58,     9,    60,    11,    12,    13,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    34,    35,
      36,    76,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    56,
      -1,    58,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    11,    12,    13,    34,    35,    36,    56,
      58,    60,    95,   142,   143,   144,    77,   142,   144,    40,
      41,    42,    50,    57,    76,    95,    96,    97,    99,   101,
     103,   105,   107,   110,   111,   126,   128,   130,   131,   137,
     138,   139,   140,   141,    59,   137,    61,     0,    56,    58,
      62,   112,   113,   112,    96,   110,   110,   110,   130,    37,
      64,    65,    66,    67,    68,    69,    70,    71,    76,   132,
     133,    49,    98,    48,   100,    47,   102,    45,    46,   104,
      41,    42,   106,    38,    39,    40,    43,    51,   108,   109,
      72,    75,   127,    74,   129,    57,    10,    23,    52,   122,
     123,    59,    37,    40,    57,   114,   115,   119,   141,   116,
     117,   118,   120,   141,     5,   112,   110,    76,    70,    96,
      99,   101,   103,   105,   105,   107,   107,   110,   110,   110,
     110,   110,   108,   126,   128,   130,   122,    96,    97,   134,
     135,   136,   138,   139,   141,   141,    57,    52,    44,   123,
      59,    52,    54,    77,   132,    98,   100,   102,   104,   104,
     106,   106,    73,   127,   129,    70,    52,   119,   141,   118,
     120,   141,   141,   126,   136,    72,   121,   123,   124,   125,
     126,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    96,    97,    98,    98,    99,   100,
     100,   101,   102,   102,   103,   104,   104,   104,   105,   106,
     106,   106,   107,   108,   108,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   126,
     127,   127,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   135,   135,   136,   136,   136,   137,   137,   138,
     138,   138,   139,   139,   140,   141,   141,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   143,
     143,   144,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     2,     3,     0,     2,     3,
       0,     2,     3,     0,     2,     0,     3,     3,     2,     0,
       3,     3,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     3,     2,     0,     3,     2,
       3,     3,     2,     2,     1,     3,     1,     2,     1,     3,
       1,     1,     3,     1,     2,     3,     2,     2,     1,     0,
       1,     1,     4,     5,     1,     2,     2,     3,     1,     2,
       3,     0,     2,     3,     0,     2,     1,     2,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     3,     2,     1,     2,     1,     3,
       2,     1,     1,     1,     1,     1,     5,     3,     2,     3,
       2,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1
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
  case 3: /* atom_expr: atom trailer_star  */
#line 34 "test.y"
                       {start_node=(yyvsp[-1].elem);}
#line 1412 "test.tab.c"
    break;

  case 4: /* expr: xor_expr symbol_xor_expr_star  */
#line 238 "test.y"
                                    {(yyval.elem) = create_node(3,"expr",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1418 "test.tab.c"
    break;

  case 5: /* star_expr: MUL expr  */
#line 240 "test.y"
                    {(yyval.elem) = create_node(3,"star_expr",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1424 "test.tab.c"
    break;

  case 6: /* symbol_xor_expr_star: BITWISE_OR xor_expr symbol_xor_expr_star  */
#line 242 "test.y"
                                                               {(yyval.elem) = create_node(3,"symbol_xor_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1430 "test.tab.c"
    break;

  case 8: /* xor_expr: and_expr symbol_and_expr_star  */
#line 246 "test.y"
                                        {(yyval.elem) = create_node(3,"xor_expr",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1436 "test.tab.c"
    break;

  case 9: /* symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star  */
#line 248 "test.y"
                                                                {(yyval.elem) = create_node(3,"symbol_and_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1442 "test.tab.c"
    break;

  case 11: /* and_expr: shift_expr symbol_shift_expr_star  */
#line 252 "test.y"
                                            {(yyval.elem) = create_node(3,"and_expr",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1448 "test.tab.c"
    break;

  case 12: /* symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star  */
#line 254 "test.y"
                                                                      {(yyval.elem) = create_node(3,"symbol_shift_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1454 "test.tab.c"
    break;

  case 14: /* shift_expr: arith_expr shift_arith_expr_star  */
#line 258 "test.y"
                                             {(yyval.elem) = create_node(3,"shift_expr",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1460 "test.tab.c"
    break;

  case 16: /* shift_arith_expr_star: SHIFT_LEFT arith_expr shift_arith_expr_star  */
#line 261 "test.y"
                                                  {(yyval.elem) = create_node(3,"shift_arith_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1466 "test.tab.c"
    break;

  case 17: /* shift_arith_expr_star: SHIFT_RIGHT arith_expr shift_arith_expr_star  */
#line 262 "test.y"
                                                   {(yyval.elem) = create_node(3,"shift_arith_expr",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1472 "test.tab.c"
    break;

  case 18: /* arith_expr: term symbol_term_star  */
#line 265 "test.y"
                                   {(yyval.elem) = create_node(3,"arith_expr",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1478 "test.tab.c"
    break;

  case 20: /* symbol_term_star: ADD term symbol_term_star  */
#line 268 "test.y"
                                {(yyval.elem) = create_node(3,"symbol_term",(yyvsp[-2].elem),(yyvsp[-1].elem));}
#line 1484 "test.tab.c"
    break;

  case 21: /* symbol_term_star: SUB term symbol_term_star  */
#line 269 "test.y"
                                {(yyval.elem) = create_node(3,"symbol_term",(yyvsp[-2].elem),(yyvsp[-1].elem));}
#line 1490 "test.tab.c"
    break;

  case 22: /* term: factor symbol_factor_star  */
#line 272 "test.y"
                                {(yyval.elem) = create_node(3,"term",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1496 "test.tab.c"
    break;

  case 24: /* symbol_factor_star: symbol_factor symbol_factor_star  */
#line 275 "test.y"
                                       {(yyval.elem) = create_node(3,"symbol_factor",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1502 "test.tab.c"
    break;

  case 25: /* symbol_factor: MUL factor  */
#line 278 "test.y"
                          {(yyval.elem) = create_node(3,"symbol_factor",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1508 "test.tab.c"
    break;

  case 26: /* symbol_factor: AT factor  */
#line 279 "test.y"
                {(yyval.elem) = create_node(3,"symbol_factor",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1514 "test.tab.c"
    break;

  case 27: /* symbol_factor: DIV factor  */
#line 280 "test.y"
                 {(yyval.elem) = create_node(3,"symbol_factor",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1520 "test.tab.c"
    break;

  case 28: /* symbol_factor: FLOOR_DIV factor  */
#line 281 "test.y"
                       {(yyval.elem) = create_node(3,"symbol_factor",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1526 "test.tab.c"
    break;

  case 29: /* symbol_factor: MOD factor  */
#line 282 "test.y"
                 {(yyval.elem) = create_node(3,"symbol_factor",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1532 "test.tab.c"
    break;

  case 30: /* factor: ADD factor  */
#line 285 "test.y"
                   {(yyval.elem) = create_node(3,(yyvsp[0].elem)->val,(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1538 "test.tab.c"
    break;

  case 31: /* factor: SUB factor  */
#line 286 "test.y"
                 {(yyval.elem) = create_node(3,(yyvsp[0].elem)->val,(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1544 "test.tab.c"
    break;

  case 32: /* factor: TILDE factor  */
#line 287 "test.y"
                   {(yyval.elem) = create_node(3,(yyvsp[0].elem)->val,(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1550 "test.tab.c"
    break;

  case 33: /* factor: power  */
#line 288 "test.y"
            {(yyval.elem) = (yyvsp[0].elem);}
#line 1556 "test.tab.c"
    break;

  case 34: /* power: atom_expr  */
#line 291 "test.y"
                 {(yyval.elem) = (yyvsp[0].elem);}
#line 1562 "test.tab.c"
    break;

  case 35: /* power: atom_expr POW factor  */
#line 292 "test.y"
                           {(yyval.elem) = create_node(3,(yyvsp[-1].elem)->val,(yyvsp[-2].elem),(yyvsp[0].elem));}
#line 1568 "test.tab.c"
    break;

  case 80: /* comp_op_expr_plus: comp_op expr  */
#line 393 "test.y"
                   {}
#line 1574 "test.tab.c"
    break;

  case 81: /* comp_op: LT  */
#line 397 "test.y"
            {(yyval.elem)=(yyvsp[0].elem);}
#line 1580 "test.tab.c"
    break;

  case 82: /* comp_op: GT  */
#line 398 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 1586 "test.tab.c"
    break;

  case 83: /* comp_op: DOUBLE_EQUAL  */
#line 399 "test.y"
                  {(yyval.elem)=(yyvsp[0].elem);}
#line 1592 "test.tab.c"
    break;

  case 84: /* comp_op: GE  */
#line 400 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 1598 "test.tab.c"
    break;

  case 85: /* comp_op: LE  */
#line 401 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 1604 "test.tab.c"
    break;

  case 86: /* comp_op: NE  */
#line 402 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 1610 "test.tab.c"
    break;

  case 87: /* comp_op: IN  */
#line 403 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 1616 "test.tab.c"
    break;

  case 88: /* comp_op: NOT IN  */
#line 404 "test.y"
             {(yyval.elem)=create_node(3, "Not In", (yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1622 "test.tab.c"
    break;

  case 89: /* comp_op: IS  */
#line 405 "test.y"
        {(yyval.elem)=(yyvsp[0].elem);}
#line 1628 "test.tab.c"
    break;

  case 90: /* comp_op: IS NOT  */
#line 406 "test.y"
            {(yyval.elem)=create_node(3, "Is Not", (yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1634 "test.tab.c"
    break;

  case 91: /* exprlist: expr_star_expr_option_list  */
#line 412 "test.y"
                                {(yyval.elem)=(yyvsp[0].elem);}
#line 1640 "test.tab.c"
    break;

  case 92: /* expr_star_expr_option: expr  */
#line 415 "test.y"
                            {(yyval.elem)=(yyvsp[0].elem);}
#line 1646 "test.tab.c"
    break;

  case 93: /* expr_star_expr_option: star_expr  */
#line 416 "test.y"
                {(yyval.elem)=(yyvsp[0].elem);}
#line 1652 "test.tab.c"
    break;

  case 94: /* expr_star_expr_option_list: expr_star_expr_option COMMA expr_star_expr_option_list  */
#line 419 "test.y"
                                                                                   {(yyval.elem)=create_node(4,"expr_star_expr_option_list",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1658 "test.tab.c"
    break;

  case 95: /* expr_star_expr_option_list: expr_star_expr_option COMMA  */
#line 420 "test.y"
                                  {(yyval.elem)=create_node(3,"expr_star_expr_option",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1664 "test.tab.c"
    break;

  case 96: /* expr_star_expr_option_list: expr_star_expr_option  */
#line 421 "test.y"
                            {(yyval.elem)=(yyvsp[0].elem);}
#line 1670 "test.tab.c"
    break;

  case 97: /* testlist_comp: namedexpr_test_star_expr_option comp_for  */
#line 424 "test.y"
                                                        {(yyval.elem)=create_node(3,"testlist_comp",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1676 "test.tab.c"
    break;

  case 98: /* testlist_comp: namedexpr_test_star_expr_option_list  */
#line 425 "test.y"
                                            {(yyval.elem)=(yyvsp[0].elem);}
#line 1682 "test.tab.c"
    break;

  case 99: /* namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA namedexpr_test_star_expr_option_list  */
#line 428 "test.y"
                                                                                                                 {(yyval.elem)=create_node(4,"namedexpr_test_star_expr_option_list",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1688 "test.tab.c"
    break;

  case 100: /* namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA  */
#line 429 "test.y"
                                            {(yyval.elem)=create_node(3,"namedexpr_test_star_expr_option",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1694 "test.tab.c"
    break;

  case 101: /* namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option  */
#line 430 "test.y"
                                      {(yyval.elem)=(yyvsp[0].elem);}
#line 1700 "test.tab.c"
    break;

  case 102: /* namedexpr_test_star_expr_option: namedexpr_test  */
#line 433 "test.y"
                                                {(yyval.elem)=(yyvsp[0].elem);}
#line 1706 "test.tab.c"
    break;

  case 103: /* namedexpr_test_star_expr_option: star_expr  */
#line 434 "test.y"
                {(yyval.elem)=(yyvsp[0].elem);}
#line 1712 "test.tab.c"
    break;

  case 104: /* namedexpr_test: test  */
#line 437 "test.y"
                     {(yyval.elem)=(yyvsp[0].elem);}
#line 1718 "test.tab.c"
    break;

  case 105: /* test: or_test  */
#line 439 "test.y"
              {(yyval.elem)=(yyvsp[0].elem);}
#line 1724 "test.tab.c"
    break;

  case 106: /* test: or_test IF or_test ELSE test  */
#line 440 "test.y"
                                  {(yyval.elem)=create_node(6,"test",(yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1730 "test.tab.c"
    break;

  case 107: /* atom: SMALL_OPEN testlist_comp SMALL_CLOSE  */
#line 442 "test.y"
                                           {(yyval.elem)=create_node(4,"Atom",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1736 "test.tab.c"
    break;

  case 108: /* atom: SMALL_OPEN SMALL_CLOSE  */
#line 443 "test.y"
                             {(yyval.elem)=create_node(3,"Atom",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1742 "test.tab.c"
    break;

  case 109: /* atom: BOX_OPEN testlist_comp BOX_CLOSE  */
#line 444 "test.y"
                                       {(yyval.elem)=create_node(4,"Atom",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1748 "test.tab.c"
    break;

  case 110: /* atom: BOX_OPEN BOX_CLOSE  */
#line 445 "test.y"
                         {(yyval.elem)=create_node(3,"Atom",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1754 "test.tab.c"
    break;

  case 111: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 446 "test.y"
                             {(yyval.elem)=create_node(3,"Atom",(yyvsp[-1].elem),(yyvsp[0].elem));}
#line 1760 "test.tab.c"
    break;

  case 112: /* atom: NAME  */
#line 447 "test.y"
           {(yyval.elem)=(yyvsp[0].elem);}
#line 1766 "test.tab.c"
    break;

  case 113: /* atom: NAME TYPE_HINT  */
#line 448 "test.y"
                     {(yyval.elem)=create_node(3,"Atom", (yyvsp[-1].elem), (yyvsp[0].elem));}
#line 1772 "test.tab.c"
    break;

  case 114: /* atom: number  */
#line 449 "test.y"
             {(yyval.elem)=(yyvsp[0].elem);}
#line 1778 "test.tab.c"
    break;

  case 115: /* atom: string_plus  */
#line 450 "test.y"
                  {(yyval.elem)=(yyvsp[0].elem);}
#line 1784 "test.tab.c"
    break;

  case 116: /* atom: TRUE  */
#line 451 "test.y"
           {(yyval.elem)=(yyvsp[0].elem);}
#line 1790 "test.tab.c"
    break;

  case 117: /* atom: FALSE  */
#line 452 "test.y"
            {(yyval.elem)=(yyvsp[0].elem);}
#line 1796 "test.tab.c"
    break;

  case 118: /* atom: NONE  */
#line 453 "test.y"
           {(yyval.elem)=(yyvsp[0].elem);}
#line 1802 "test.tab.c"
    break;

  case 119: /* number: INTEGER  */
#line 457 "test.y"
                {(yyval.elem) = (yyvsp[0].elem);}
#line 1808 "test.tab.c"
    break;

  case 120: /* number: FLOAT  */
#line 458 "test.y"
            {(yyval.elem) = (yyvsp[0].elem);}
#line 1814 "test.tab.c"
    break;

  case 121: /* string_plus: STRING string_plus  */
#line 461 "test.y"
                                {(yyval.elem)=create_node(3,"string", (yyvsp[-1].elem), (yyvsp[0].elem));}
#line 1820 "test.tab.c"
    break;

  case 122: /* string_plus: STRING  */
#line 462 "test.y"
             {(yyval.elem)=(yyvsp[0].elem);}
#line 1826 "test.tab.c"
    break;


#line 1830 "test.tab.c"

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
    fout << "\t" << cell->id << "\t\t[ style = solid label = \"" + value + "\"  ];" << endl;
    for(int i=0;i<cell->children.size();i++)
    {
        if(!cell->children[i])
            continue;
        fout << "\t" << cell->id << " -> " << cell->children[i]->id << endl;
        MakeDOTFile(cell->children[i]);
    }
}


int main(){
    indent_stack.push(0);
    /* yylex(); */
    string output_file = "";
    output_file = "output.dot";
    /* ofstream fout("output.dot", ios::app); */

    yyparse();
 
    // Open the output file
	fout.open(output_file.c_str(),ios::out);
    ifstream infile("./DOT_Template.txt");

    MakeDOTFile(start_node);
    cout<<"}";
    fout<<"}";
    /* fout.close(); */

    return 0;
}
int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}
