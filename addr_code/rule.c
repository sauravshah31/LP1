/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yaccrule.y"

  #include "codegen.cpp"
/**
  @file yaccrule.y
  @brief This file includes grammar rule and their semantic action(s).
  @author sonu kumar , Roll no 127159 , section : A , Course B.tech(3/4) 
  @version 1.0
*/
  #define EMPTY -1
  using namespace std;
  extern FILE* yyin;
  extern int lineno;
  extern int colum;
  extern char *stream;
  int yylex(void);
  void yyerror(const char *);
  extern int nextInstr;
  int type;
  vector<YYSTYPE::BackpatchList*> breaklist;
  vector<YYSTYPE::BackpatchList*> continuelist;
  int break_current    = -1;
  int continue_current = -1;
  extern bool assign ;

#line 95 "rule.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_RULE_H_INCLUDED
# define YY_YY_RULE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    SWITCH = 261,
    CASE = 262,
    DEFAULT = 263,
    INT = 264,
    FLOAT = 265,
    BOOL = 266,
    UNSIGNED = 267,
    SIGNED = 268,
    ASSIGN = 269,
    PLUSEQ = 270,
    MINUSEQ = 271,
    TIMESEQ = 272,
    DIVIDEQ = 273,
    PLUS = 274,
    MINUS = 275,
    TIMES = 276,
    DIVIDE = 277,
    EXP = 278,
    IOR = 279,
    IAND = 280,
    INOT = 281,
    XOR = 282,
    OR = 283,
    AND = 284,
    NOT = 285,
    EQ = 286,
    NEQ = 287,
    LT = 288,
    LEQ = 289,
    GT = 290,
    GEQ = 291,
    LP = 292,
    RP = 293,
    LB = 294,
    RB = 295,
    COMMA = 296,
    SEMICOLON = 297,
    COLON = 298,
    DOUBLENUM = 299,
    INTNUM = 300,
    TRUE = 301,
    FALSE = 302,
    ID = 303,
    PLUSPLUS = 304,
    MINUSMINUS = 305,
    CONTINUE = 306,
    BREAK = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "yaccrule.y"

  int type;
  struct marks{
    int instr;
  }mark;
  struct BackpatchList{
    int ins;
    BackpatchList *next;
  };
  struct info{
    char *addr;
    short  type;
    BackpatchList *tlist;
    BackpatchList *flist;
  }exp;
  struct nextL{
      int instr; /**Instruction number */
      BackpatchList *nextList; /**Linked list of Backpatch*/
  }List;
  /**
    Linked list of switch instruction which have to backpatch
  */
  struct switchL{
    int instr;     /**Instruction number*/
    int lineno;    /**Line number where this list was found*/
    switchL *next; /**Next pointer of switch list*/
    bool stype;    /**default or case statement*/
    char *val;     /**Case value*/
  };
  switchL *switchList;
  char *str;

#line 233 "rule.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RULE_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    96,    97,   101,   102,   103,   108,   120,
     124,   128,   129,   135,   138,   141,   144,   147,   150,   159,
     160,   167,   168,   171,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   185,   188,   192,   195,   203,   207,   213,
     239,   259,   260,   263,   266,   271,   276,   279,   290,   299,
     298,   325,   331,   340,   352,   368,   370,   376,   382,   393,
     407,   421,   436,   453,   459,   459,   480,   486,   486,   508,
     515,   526,   532,   542,   548,   558,   564,   570,   579,   585,
     595,   596,   597,   598,   602,   608,   615,   625,   631,   638,
     648,   654,   665,   670,   677,   684,   689,   695,   701,   715,
     720,   727,   737,   751,   756,   767,   777,   782,   795,   811
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "SWITCH", "CASE",
  "DEFAULT", "INT", "FLOAT", "BOOL", "UNSIGNED", "SIGNED", "ASSIGN",
  "PLUSEQ", "MINUSEQ", "TIMESEQ", "DIVIDEQ", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "EXP", "IOR", "IAND", "INOT", "XOR", "OR", "AND", "NOT", "EQ",
  "NEQ", "LT", "LEQ", "GT", "GEQ", "LP", "RP", "LB", "RB", "COMMA",
  "SEMICOLON", "COLON", "DOUBLENUM", "INTNUM", "TRUE", "FALSE", "ID",
  "PLUSPLUS", "MINUSMINUS", "CONTINUE", "BREAK", "$accept", "Program",
  "translation-unit", "external-declaration", "function",
  "compound-statement", "statement-list", "statement", "expression-list",
  "declaration-list", "declaration", "var-type", "init-declarator-list",
  "selection-statement", "if_prefix", "switch-statement",
  "default-statement", "case-list", "Next", "iteration-statement", "$@1",
  "break-marker", "continue-marker", "jump-statement", "expression",
  "assignment-expression", "logical-OR-expression", "$@2",
  "logical-AND-expression", "$@3", "inclusive-OR-expression",
  "exclusive-OR-expression", "inclusive-AND-expression",
  "equality-expression", "relational-expression", "RELOP",
  "additive-expression", "multiplicative-expression",
  "exponentiation-expression", "unary-expression", "postfix-expression",
  "primary-expression", "Literals", "marker", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      72,  -151,  -151,  -151,    11,    86,   104,   104,   104,   104,
     104,  -151,  -151,  -151,  -151,  -151,  -151,   104,   104,     7,
      72,  -151,  -151,  -151,   164,  -151,   -34,    87,   166,    16,
      17,    24,    32,    37,   100,    70,   118,   143,  -151,    41,
      90,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,     1,  -151,  -151,  -151,  -151,  -151,    29,    -1,   126,
     104,  -151,   104,   104,   104,   104,   104,    52,    58,   104,
     104,   104,   104,   104,  -151,  -151,  -151,  -151,   104,   104,
     104,   104,   104,   104,  -151,  -151,  -151,    76,   104,    77,
      79,  -151,   166,   166,   166,   166,   166,   166,  -151,  -151,
      32,    37,   100,    70,    70,   118,   143,   143,  -151,  -151,
    -151,   166,    94,   111,   104,   104,    21,  -151,   104,    17,
      24,   155,  -151,   156,   105,   136,  -151,   151,  -151,  -151,
     164,  -151,  -151,  -151,  -151,   166,   104,   157,  -151,  -151,
    -151,  -151,    21,    21,   128,   104,   104,  -151,   191,  -151,
     166,   141,  -151,   158,   159,    21,  -151,  -151,  -151,  -151,
     162,    21,    66,   160,   161,   190,   178,  -151,   163,  -151,
    -151,   192,    66,   190,  -151,    21,  -151,   165,   192,    21,
      -5,  -151,    -2,    21,     2
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    24,    29,    32,    27,    25,     0,     0,     0,     0,
       0,    19,   106,   105,   107,   108,   102,     0,     0,     0,
       2,     3,     5,     7,     6,    21,     0,     0,    55,    57,
      63,    66,    69,    71,    73,    75,    78,    84,    87,    90,
      92,    99,   103,    28,    31,    26,    30,    95,    96,    97,
      98,     0,    93,    94,     1,     4,    22,     0,    33,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    80,    81,     0,     0,
       0,     0,     0,     0,   100,   101,   104,    33,     0,     0,
       0,    23,    56,    58,    59,    60,    61,    62,   109,   109,
      70,    72,    74,    76,    77,    79,    85,    86,    88,    89,
      91,    34,     0,    35,     0,     0,    12,     8,     0,    65,
      68,     0,    52,     0,     0,     0,    15,   109,    11,    13,
      14,    16,   109,    17,    18,    36,     0,     0,    48,    54,
      53,     9,     0,     0,     0,     0,     0,    10,    37,    40,
      49,     0,    48,     0,     0,     0,   109,    51,    38,    51,
       0,     0,     0,     0,     0,     0,    41,    50,     0,   109,
      48,    43,     0,    42,   109,    12,    39,     0,    44,    12,
     109,   109,   109,    12,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,   180,  -151,    92,   -86,   -67,     8,    23,
     -23,    25,  -151,  -151,  -151,  -151,    36,  -116,  -141,  -151,
    -151,    46,  -151,  -151,  -151,   -10,  -151,  -151,    93,  -151,
      95,   140,   142,   144,   115,  -151,   133,   110,    18,   154,
    -151,  -151,  -150,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,   126,   127,   128,   129,   130,
      25,    57,    59,   131,   132,   164,   165,   166,   146,   133,
     153,   160,   137,   134,    27,    28,    29,    67,    30,    68,
      31,    32,    33,    34,    35,    78,    36,    37,    38,    39,
      40,    41,    42,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    56,   -45,   114,   115,   -46,   -46,    54,    23,   -47,
     -47,   155,   168,    88,    58,    62,    63,    64,    65,    66,
      43,    44,   177,    24,   121,    26,   122,   123,    23,   176,
       1,     2,     3,     4,     5,   -45,    89,   143,   -46,    86,
       6,     7,   -47,    24,   -64,    26,   -67,     8,    69,   171,
      92,     9,    93,    94,    95,    96,    97,   178,    10,    70,
     116,   159,    71,    11,    83,    12,    13,    14,    15,    16,
      17,    18,   124,   125,   175,   147,   148,    87,   111,   179,
      98,     1,     2,     3,     4,     5,   183,    99,   158,   180,
      88,     6,     7,   182,   167,    45,    46,   184,     8,   108,
     109,   110,     9,    74,    75,    76,    77,    56,   135,    10,
      12,    13,    14,    15,    11,   112,    12,    13,    14,    15,
      16,    17,    18,     6,     7,   118,   144,   113,    60,    61,
       8,    72,    73,   116,     9,   150,   151,    79,    80,    84,
      85,    10,    62,    63,    64,    65,    66,   139,    12,    13,
      14,    15,    16,    17,    18,    62,    63,    64,    65,    66,
      47,    48,    49,    50,    81,    82,   149,    90,    91,   162,
     163,    52,    53,     1,     2,     3,     4,     5,   140,   154,
      62,    63,    64,    65,    66,   172,   163,   103,   104,   106,
     107,   141,   136,   138,   145,   152,   156,   162,   157,   172,
      55,   170,   173,   169,   117,   161,   174,   119,   181,   100,
     120,   105,   101,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      10,    24,     7,    98,    99,     7,     8,     0,     0,     7,
       8,   152,   162,    14,    48,    14,    15,    16,    17,    18,
       9,    10,   172,     0,     3,     0,     5,     6,    20,   170,
       9,    10,    11,    12,    13,    40,    37,   132,    40,    38,
      19,    20,    40,    20,    28,    20,    29,    26,    24,   165,
      60,    30,    62,    63,    64,    65,    66,   173,    37,    27,
      39,   156,    25,    42,    23,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   169,   142,   143,    48,    88,   174,
      28,     9,    10,    11,    12,    13,   181,    29,   155,   175,
      14,    19,    20,   179,   161,     9,    10,   183,    26,    81,
      82,    83,    30,    33,    34,    35,    36,   130,   118,    37,
      44,    45,    46,    47,    42,    38,    44,    45,    46,    47,
      48,    49,    50,    19,    20,    14,   136,    48,    41,    42,
      26,    31,    32,    39,    30,   145,   146,    19,    20,    49,
      50,    37,    14,    15,    16,    17,    18,    42,    44,    45,
      46,    47,    48,    49,    50,    14,    15,    16,    17,    18,
       6,     7,     8,     9,    21,    22,    38,    41,    42,     7,
       8,    17,    18,     9,    10,    11,    12,    13,    42,    38,
      14,    15,    16,    17,    18,     7,     8,    72,    73,    79,
      80,    40,    37,    37,    37,     4,    38,     7,    39,     7,
      20,    40,   166,    43,   112,   159,    43,   114,    43,    69,
     115,    78,    70,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    19,    20,    26,    30,
      37,    42,    44,    45,    46,    47,    48,    49,    50,    54,
      55,    56,    57,    61,    62,    63,    64,    77,    78,    79,
      81,    83,    84,    85,    86,    87,    89,    90,    91,    92,
      93,    94,    95,     9,    10,     9,    10,    92,    92,    92,
      92,    78,    92,    92,     0,    56,    63,    64,    48,    65,
      41,    42,    14,    15,    16,    17,    18,    80,    82,    24,
      27,    25,    31,    32,    33,    34,    35,    36,    88,    19,
      20,    21,    22,    23,    49,    50,    38,    48,    14,    37,
      41,    42,    78,    78,    78,    78,    78,    78,    28,    29,
      84,    85,    86,    87,    87,    89,    90,    90,    91,    91,
      91,    78,    38,    48,    96,    96,    39,    58,    14,    81,
      83,     3,     5,     6,    51,    52,    58,    59,    60,    61,
      62,    66,    67,    72,    76,    78,    37,    75,    37,    42,
      42,    40,    96,    96,    78,    37,    71,    60,    60,    38,
      78,    78,     4,    73,    38,    71,    38,    39,    60,    96,
      74,    74,     7,     8,    68,    69,    70,    60,    95,    43,
      40,    70,     7,    69,    43,    96,    71,    95,    70,    96,
      59,    43,    59,    96,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    57,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      67,    68,    68,    68,    68,    69,    70,    70,    71,    73,
      72,    74,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    79,    80,    79,    81,    82,    81,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    88,    88,    89,    89,    89,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     5,     3,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     2,     1,     2,     1,
       2,     2,     1,     1,     3,     3,     5,     3,     6,    10,
       4,     1,     2,     2,     3,     4,     5,     6,     0,     0,
       9,     0,     0,     2,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     1,     0,     5,     1,     0,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     1,     3,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 92 "yaccrule.y"
                {}
#line 1557 "rule.c"
    break;

  case 3:
#line 96 "yaccrule.y"
                      {}
#line 1563 "rule.c"
    break;

  case 4:
#line 97 "yaccrule.y"
                                        {}
#line 1569 "rule.c"
    break;

  case 5:
#line 101 "yaccrule.y"
          {/**Function definition*/}
#line 1575 "rule.c"
    break;

  case 6:
#line 102 "yaccrule.y"
                   {/** Global declaration*/}
#line 1581 "rule.c"
    break;

  case 7:
#line 103 "yaccrule.y"
                   {/*Gloabal initiliazation*/}
#line 1587 "rule.c"
    break;

  case 8:
#line 108 "yaccrule.y"
                                       {
  	  /*ResetSymbolTable();*/
	  backpatch((yyvsp[0].List).nextList,nextInstr);
	  genCode("ret",0);
  }
#line 1597 "rule.c"
    break;

  case 9:
#line 120 "yaccrule.y"
                       {(yyval.List).nextList = (yyvsp[-1].List).nextList;}
#line 1603 "rule.c"
    break;

  case 10:
#line 124 "yaccrule.y"
                                 {
    backpatch((yyvsp[-2].List).nextList,(yyvsp[-1].mark).instr);
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1612 "rule.c"
    break;

  case 11:
#line 128 "yaccrule.y"
             {(yyval.List).nextList = (yyvsp[0].List).nextList;}
#line 1618 "rule.c"
    break;

  case 12:
#line 129 "yaccrule.y"
   {/**Suffice for empty block statement*/
       (yyval.List).nextList = NULL;
  }
#line 1626 "rule.c"
    break;

  case 13:
#line 135 "yaccrule.y"
                 {
    (yyval.List).nextList=NULL;
  }
#line 1634 "rule.c"
    break;

  case 14:
#line 138 "yaccrule.y"
                   {
    (yyval.List).nextList=NULL;
  }
#line 1642 "rule.c"
    break;

  case 15:
#line 141 "yaccrule.y"
                     {
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1650 "rule.c"
    break;

  case 16:
#line 144 "yaccrule.y"
                      {
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1658 "rule.c"
    break;

  case 17:
#line 147 "yaccrule.y"
                      {
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1666 "rule.c"
    break;

  case 18:
#line 150 "yaccrule.y"
                 {
    (yyval.List).nextList = NULL;
  }
#line 1674 "rule.c"
    break;

  case 19:
#line 159 "yaccrule.y"
            { }
#line 1680 "rule.c"
    break;

  case 20:
#line 160 "yaccrule.y"
                       {}
#line 1686 "rule.c"
    break;

  case 21:
#line 167 "yaccrule.y"
             {}
#line 1692 "rule.c"
    break;

  case 22:
#line 168 "yaccrule.y"
                               {}
#line 1698 "rule.c"
    break;

  case 23:
#line 171 "yaccrule.y"
                                          {}
#line 1704 "rule.c"
    break;

  case 24:
#line 174 "yaccrule.y"
      {type = 1;}
#line 1710 "rule.c"
    break;

  case 25:
#line 175 "yaccrule.y"
          {type = 2;}
#line 1716 "rule.c"
    break;

  case 26:
#line 176 "yaccrule.y"
              {type= 3;}
#line 1722 "rule.c"
    break;

  case 27:
#line 177 "yaccrule.y"
            {type = 4;}
#line 1728 "rule.c"
    break;

  case 28:
#line 178 "yaccrule.y"
                { type=5;}
#line 1734 "rule.c"
    break;

  case 29:
#line 179 "yaccrule.y"
         {type=6;}
#line 1740 "rule.c"
    break;

  case 30:
#line 180 "yaccrule.y"
               {type=7; }
#line 1746 "rule.c"
    break;

  case 31:
#line 181 "yaccrule.y"
                 {type=8; }
#line 1752 "rule.c"
    break;

  case 32:
#line 182 "yaccrule.y"
        { type=9;}
#line 1758 "rule.c"
    break;

  case 33:
#line 185 "yaccrule.y"
     {
  	InsertId((yyvsp[0].exp).addr,lineno,type);
  }
#line 1766 "rule.c"
    break;

  case 34:
#line 188 "yaccrule.y"
                                   {
  	InsertId((yyvsp[-2].exp).addr,lineno,type);
  	genCode((yyvsp[-2].exp).addr,(yyvsp[0].exp).addr);
  }
#line 1775 "rule.c"
    break;

  case 35:
#line 192 "yaccrule.y"
                                 {
  	InsertId((yyvsp[0].exp).addr,lineno,type);
  }
#line 1783 "rule.c"
    break;

  case 36:
#line 195 "yaccrule.y"
                                                              {
  	InsertId((yyvsp[-2].exp).addr,lineno,type);
  	genCode((yyvsp[-2].exp).addr,(yyvsp[0].exp).addr);
  }
#line 1792 "rule.c"
    break;

  case 37:
#line 203 "yaccrule.y"
                                   {
	  backpatch((yyvsp[-2].exp).tlist,(yyvsp[-1].mark).instr);
	  (yyval.List).nextList = mergeList((yyvsp[-2].exp).flist,(yyvsp[0].List).nextList);
	}
#line 1801 "rule.c"
    break;

  case 38:
#line 207 "yaccrule.y"
                                                        {
	    backpatch((yyvsp[-5].exp).tlist,(yyvsp[-4].mark).instr);
	    backpatch((yyvsp[-5].exp).flist,(yyvsp[-1].List).instr);
	    YYSTYPE::BackpatchList *temp = mergeList((yyvsp[-3].List).nextList,(yyvsp[-1].List).nextList);
	    (yyval.List).nextList = mergeList(temp,(yyvsp[0].List).nextList);
	}
#line 1812 "rule.c"
    break;

  case 39:
#line 213 "yaccrule.y"
                                                                                         {
	  YYSTYPE::switchL *l=NULL;
	  YYSTYPE::switchL *ll;
	  int in=nextInstr;
	  while((yyvsp[-2].switchList)!=NULL){
	    if((yyvsp[-2].switchList)->stype == true){
	      ll = (yyvsp[-2].switchList);
	      genCode("if",(yyvsp[-6].exp).addr," == ",(yyvsp[-2].switchList)->val,"goto",(yyvsp[-2].switchList)->instr);
	      delete ll;
	    }
	    else{
	       l = (yyvsp[-2].switchList);
	    }
	    (yyvsp[-2].switchList)=(yyvsp[-2].switchList)->next;
	  }
	  if(l!=NULL){
	    genCode("goto",l->instr);
	    delete l;
	  }
	  backpatch((yyvsp[-7].List).nextList,in); //Backpatch start of switch-statement
	  backpatch((yyvsp[0].List).nextList,nextInstr);//Backpatch end of switch-statement
	  backpatch(breaklist[break_current],nextInstr); //Backpatch break statement(s)
	  break_current--;
	}
#line 1841 "rule.c"
    break;

  case 40:
#line 239 "yaccrule.y"
                                          {
  /**
  	Special case when expression is just ID or some arithmatic expression
  */
    if((yyvsp[-1].exp).flist  ==  NULL  && (yyvsp[-1].exp).tlist  ==  NULL ){
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-1].exp).addr,"!=","0","goto",EMPTY);
      genCode("goto",EMPTY);
   }
   else{
     (yyval.exp).tlist = (yyvsp[-1].exp).tlist;
     (yyval.exp).flist = (yyvsp[-1].exp).flist;
   }
}
#line 1861 "rule.c"
    break;

  case 41:
#line 259 "yaccrule.y"
           {(yyval.switchList)=(yyvsp[0].switchList);}
#line 1867 "rule.c"
    break;

  case 42:
#line 260 "yaccrule.y"
                               {
  	(yyval.switchList) = mergeSwitchList((yyvsp[-1].switchList),(yyvsp[0].switchList));
  }
#line 1875 "rule.c"
    break;

  case 43:
#line 263 "yaccrule.y"
                               {
  	(yyval.switchList) = mergeSwitchList((yyvsp[-1].switchList),(yyvsp[0].switchList));
  }
#line 1883 "rule.c"
    break;

  case 44:
#line 266 "yaccrule.y"
                                        {
  	(yyval.switchList) = mergeSwitchList(mergeSwitchList((yyvsp[-2].switchList),(yyvsp[-1].switchList)),(yyvsp[0].switchList));
  }
#line 1891 "rule.c"
    break;

  case 45:
#line 271 "yaccrule.y"
                                      {
    (yyval.switchList)=makeList((yyvsp[-1].mark).instr,false,NULL,EMPTY);
  }
#line 1899 "rule.c"
    break;

  case 46:
#line 276 "yaccrule.y"
                                             {
    (yyval.switchList)=makeList((yyvsp[-1].mark).instr,true,(yyvsp[-3].exp).addr,lineno);
  }
#line 1907 "rule.c"
    break;

  case 47:
#line 279 "yaccrule.y"
                                                       {
    (yyval.switchList) = makeList((yyvsp[-1].mark).instr,true,(yyvsp[-3].exp).addr,lineno);
    int line;
    if( (line=IsDuplicateCaseLabel((yyvsp[-5].switchList),(yyvsp[-3].exp).addr)) != -1 ){
      AddError("duplicate case label",lineno,ERROR);
      AddError("previously used here",line,ERROR);
    }
    (yyval.switchList) = mergeSwitchList((yyvsp[-5].switchList),(yyval.switchList));
  }
#line 1921 "rule.c"
    break;

  case 48:
#line 290 "yaccrule.y"
     {
  (yyval.List).nextList = makeList(nextInstr);
  genCode("goto",EMPTY);
  (yyval.List).instr = nextInstr;
}
#line 1931 "rule.c"
    break;

  case 49:
#line 299 "yaccrule.y"
                        {
    /**
      Special case when programmar has used
      while(a)
      while(a+b)
    */
    if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist  ==  NULL ){
      (yyvsp[0].exp).tlist = makeList(nextInstr);
      genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
      (yyvsp[0].exp).flist = makeList(nextInstr);
      genCode("goto",EMPTY);
    }
  }
#line 1949 "rule.c"
    break;

  case 50:
#line 312 "yaccrule.y"
                                   {
    backpatch((yyvsp[0].List).nextList,(yyvsp[-7].mark).instr);
    backpatch((yyvsp[-5].exp).tlist,(yyvsp[-2].mark).instr);
    backpatch(continuelist[continue_current],(yyvsp[-7].mark).instr);
    (yyval.List).nextList = (yyvsp[-5].exp).flist;
    genCode("goto",(yyvsp[-7].mark).instr);
    backpatch(breaklist[break_current],nextInstr);
    break_current--;
    continue_current--;
}
#line 1964 "rule.c"
    break;

  case 51:
#line 325 "yaccrule.y"
{
  break_current++;
  breaklist.push_back(NULL);
}
#line 1973 "rule.c"
    break;

  case 52:
#line 331 "yaccrule.y"
{
(yyval.mark).instr = nextInstr;
continue_current++;
continuelist.push_back(NULL);
}
#line 1983 "rule.c"
    break;

  case 53:
#line 340 "yaccrule.y"
                   {
    if(break_current!=EMPTY){
      genCode("goto",EMPTY);
      if( (breaklist.size() == 0) || ( (signed)breaklist.size() == break_current-1) )
        breaklist.push_back(makeList(nextInstr-1));
      else
        breaklist[break_current]=mergeList(makeList(nextInstr-1),breaklist[break_current]);
    }
    else{
      AddError("break is not in loop or switch statement",lineno,ERROR);
    }
  }
#line 2000 "rule.c"
    break;

  case 54:
#line 352 "yaccrule.y"
                     {
    if(continue_current!=-1){
      genCode("goto",EMPTY);
      if( (continuelist.size() == 0) || ( (signed)continuelist.size() == continue_current-1) )
        continuelist.push_back(makeList(nextInstr-1));
      else
        continuelist[continue_current]=mergeList(makeList(nextInstr-1),continuelist[continue_current]);
    }
    else{
      AddError("continue is not in loop statement",lineno,ERROR);
    }
  }
#line 2017 "rule.c"
    break;

  case 55:
#line 368 "yaccrule.y"
                       {
  }
#line 2024 "rule.c"
    break;

  case 56:
#line 370 "yaccrule.y"
                                         {
  }
#line 2031 "rule.c"
    break;

  case 57:
#line 376 "yaccrule.y"
                       {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
  }
#line 2042 "rule.c"
    break;

  case 58:
#line 382 "yaccrule.y"
                                                      {
        /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        genCode((yyvsp[-2].exp).addr,(yyvsp[0].exp).addr);
        (yyval.exp).flist = NULL;
        (yyval.exp).tlist = NULL;
  }
#line 2058 "rule.c"
    break;

  case 59:
#line 393 "yaccrule.y"
                                                      {
        /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).flist = NULL;
        (yyval.exp).tlist = NULL;
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"+",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 2077 "rule.c"
    break;

  case 60:
#line 407 "yaccrule.y"
                                                       {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;
        /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"-",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 2096 "rule.c"
    break;

  case 61:
#line 421 "yaccrule.y"
                                                       {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;

       /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"*",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 2116 "rule.c"
    break;

  case 62:
#line 436 "yaccrule.y"
                                                       {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;
       /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"/",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 2135 "rule.c"
    break;

  case 63:
#line 453 "yaccrule.y"
                        {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2146 "rule.c"
    break;

  case 64:
#line 459 "yaccrule.y"
                         {
	    if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
	        genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
	            genCode("goto",EMPTY);
	            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
	            (yyvsp[0].exp).flist = makeList(nextInstr-1);
	    }
    }
#line 2159 "rule.c"
    break;

  case 65:
#line 466 "yaccrule.y"
                                     {
      if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
      }
      backpatch((yyvsp[-4].exp).flist,(yyvsp[-1].mark).instr);
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = mergeList((yyvsp[-4].exp).tlist,(yyvsp[0].exp).tlist);
  }
#line 2175 "rule.c"
    break;

  case 66:
#line 480 "yaccrule.y"
                         {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2186 "rule.c"
    break;

  case 67:
#line 486 "yaccrule.y"
                          {
        if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
            genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
    	}

    }
#line 2200 "rule.c"
    break;

  case 68:
#line 494 "yaccrule.y"
                                        {
      if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
            genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
      }
      backpatch((yyvsp[-4].exp).tlist,(yyvsp[-1].mark).instr);
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
      (yyval.exp).flist = mergeList((yyvsp[-4].exp).flist,(yyvsp[0].exp).flist);
  }
#line 2216 "rule.c"
    break;

  case 69:
#line 508 "yaccrule.y"
                         {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2228 "rule.c"
    break;

  case 70:
#line 515 "yaccrule.y"
                                                      {
      (yyval.exp).addr  = newTemp();
      (yyval.exp).type  = (yyvsp[-2].exp).type;
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      genCode((yyval.exp).addr ,(yyvsp[-2].exp).addr,"|",(yyvsp[0].exp).addr);
  }
#line 2240 "rule.c"
    break;

  case 71:
#line 526 "yaccrule.y"
                        {
    (yyval.exp).addr  = (yyvsp[0].exp).addr;
    (yyval.exp).type  = (yyvsp[0].exp).type;
    (yyval.exp).flist = (yyvsp[0].exp).flist;
    (yyval.exp).tlist = (yyvsp[0].exp).tlist;
}
#line 2251 "rule.c"
    break;

  case 72:
#line 532 "yaccrule.y"
                                                     {
    (yyval.exp).addr  = newTemp();
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
    genCode((yyval.exp).addr ,(yyvsp[-2].exp).addr,"XOR",(yyvsp[0].exp).addr);
}
#line 2262 "rule.c"
    break;

  case 73:
#line 542 "yaccrule.y"
                     {
    (yyval.exp).addr  = (yyvsp[0].exp).addr;
    (yyval.exp).type  = (yyvsp[0].exp).type;
    (yyval.exp).flist = (yyvsp[0].exp).flist;
    (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2273 "rule.c"
    break;

  case 74:
#line 548 "yaccrule.y"
                                                     {
      (yyval.exp).addr  = newTemp();
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      genCode((yyval.exp).addr ,(yyvsp[-2].exp).addr,"&",(yyvsp[0].exp).addr);
  }
#line 2284 "rule.c"
    break;

  case 75:
#line 558 "yaccrule.y"
                       {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).type   = (yyvsp[0].exp).type;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2295 "rule.c"
    break;

  case 76:
#line 564 "yaccrule.y"
                                               {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-2].exp).addr," == ",(yyvsp[0].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
#line 2306 "rule.c"
    break;

  case 77:
#line 570 "yaccrule.y"
                                                {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-2].exp).addr,"!=",(yyvsp[0].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
#line 2317 "rule.c"
    break;

  case 78:
#line 579 "yaccrule.y"
                     {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).type   = (yyvsp[0].exp).type;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2328 "rule.c"
    break;

  case 79:
#line 585 "yaccrule.y"
                                                   {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-2].exp).addr,(yyvsp[-1].str),(yyvsp[0].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
#line 2339 "rule.c"
    break;

  case 80:
#line 595 "yaccrule.y"
         {(yyval.str)=(char*)">";}
#line 2345 "rule.c"
    break;

  case 81:
#line 596 "yaccrule.y"
         {(yyval.str) =(char*)">=";}
#line 2351 "rule.c"
    break;

  case 82:
#line 597 "yaccrule.y"
         {(yyval.str) =(char*)"<";}
#line 2357 "rule.c"
    break;

  case 83:
#line 598 "yaccrule.y"
         {(yyval.str) =(char*)"<=";}
#line 2363 "rule.c"
    break;

  case 84:
#line 602 "yaccrule.y"
                           {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).type   = (yyvsp[0].exp).type;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2374 "rule.c"
    break;

  case 85:
#line 608 "yaccrule.y"
                                                     {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"+",(yyvsp[0].exp).addr);
  }
#line 2386 "rule.c"
    break;

  case 86:
#line 615 "yaccrule.y"
                                                      {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"-",(yyvsp[0].exp).addr);
  }
#line 2398 "rule.c"
    break;

  case 87:
#line 625 "yaccrule.y"
                             {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).type   = (yyvsp[0].exp).type;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2409 "rule.c"
    break;

  case 88:
#line 631 "yaccrule.y"
                                                             {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"*",(yyvsp[0].exp).addr);
  }
#line 2421 "rule.c"
    break;

  case 89:
#line 638 "yaccrule.y"
                                                              {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"/",(yyvsp[0].exp).addr);
  }
#line 2433 "rule.c"
    break;

  case 90:
#line 648 "yaccrule.y"
                   {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).type   = (yyvsp[0].exp).type;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
  }
#line 2444 "rule.c"
    break;

  case 91:
#line 654 "yaccrule.y"
                                                  {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).type   = (yyvsp[-2].exp).type;
    (yyval.exp).tlist  = NULL;
    (yyval.exp).flist  = NULL;
    genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"@",(yyvsp[0].exp).addr);
  }
#line 2456 "rule.c"
    break;

  case 92:
#line 665 "yaccrule.y"
                    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2466 "rule.c"
    break;

  case 93:
#line 670 "yaccrule.y"
                            {
     (yyval.exp).addr   = newTemp();
     (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
     (yyval.exp).flist  = (yyvsp[0].exp).flist;
     genCode((yyval.exp).addr ,(yyvsp[0].exp).addr,"+","1");
     genCode((yyvsp[0].exp).addr,(yyval.exp).addr );
  }
#line 2478 "rule.c"
    break;

  case 94:
#line 677 "yaccrule.y"
                              {
     (yyval.exp).addr   = newTemp();
     (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
     (yyval.exp).flist  = (yyvsp[0].exp).flist;
     genCode((yyval.exp).addr ,(yyvsp[0].exp).addr,"-","1");
     genCode((yyvsp[0].exp).addr,(yyval.exp).addr );
  }
#line 2490 "rule.c"
    break;

  case 95:
#line 684 "yaccrule.y"
                        {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
    }
#line 2500 "rule.c"
    break;

  case 96:
#line 689 "yaccrule.y"
                         {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
      genCode((yyval.exp).addr ,"-1","*",(yyvsp[0].exp).addr);
  }
#line 2511 "rule.c"
    break;

  case 97:
#line 695 "yaccrule.y"
                         {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
      genCode((yyval.exp).addr ,"~",(yyvsp[0].exp).addr);
  }
#line 2522 "rule.c"
    break;

  case 98:
#line 701 "yaccrule.y"
                       {
      if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
    }
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[0].exp).flist;
      (yyval.exp).flist  = (yyvsp[0].exp).tlist;
  }
#line 2538 "rule.c"
    break;

  case 99:
#line 715 "yaccrule.y"
                    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2548 "rule.c"
    break;

  case 100:
#line 720 "yaccrule.y"
                              {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).tlist  = (yyvsp[-1].exp).tlist;
    (yyval.exp).flist  = (yyvsp[-1].exp).flist;
    genCode((yyval.exp).addr ,(yyvsp[-1].exp).addr);
    genCode((yyvsp[-1].exp).addr,(yyval.exp).addr ,"+","1");
  }
#line 2560 "rule.c"
    break;

  case 101:
#line 727 "yaccrule.y"
                                {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).tlist  = (yyvsp[-1].exp).tlist;
    (yyval.exp).flist  = (yyvsp[-1].exp).flist;
    genCode((yyval.exp).addr ,(yyvsp[-1].exp).addr);
    genCode((yyvsp[-1].exp).addr,(yyval.exp).addr ,"-","1");
  }
#line 2572 "rule.c"
    break;

  case 102:
#line 737 "yaccrule.y"
   {
  (yyval.exp).addr   = (yyvsp[0].exp).addr;
  (yyval.exp).tlist  = NULL;
  (yyval.exp).flist  = NULL;
  if(!IsPresent((yyvsp[0].exp).addr)){
    char *errmsg =  new char[256];
    strcpy(errmsg,"'");
    strcat(errmsg,(yyval.exp).addr);
    strcat(errmsg,"' was not declared");
    AddError(errmsg,lineno,ERROR);
    delete errmsg;
  }

 }
#line 2591 "rule.c"
    break;

  case 103:
#line 751 "yaccrule.y"
           {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2601 "rule.c"
    break;

  case 104:
#line 756 "yaccrule.y"
                              {
    (yyval.exp).addr  = (yyvsp[-1].exp).addr;
    (yyval.exp).flist  = (yyvsp[-1].exp).flist;
    (yyval.exp).tlist  = (yyvsp[-1].exp).tlist;
  }
#line 2611 "rule.c"
    break;

  case 105:
#line 767 "yaccrule.y"
         {
    /**
      This temp contains value of the const
      e.g. 5
      temp->5
    */
    (yyval.exp).type  = INTNUM;
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
  }
#line 2626 "rule.c"
    break;

  case 106:
#line 777 "yaccrule.y"
              {
    (yyval.exp).type  = DOUBLENUM;
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
  }
#line 2636 "rule.c"
    break;

  case 107:
#line 782 "yaccrule.y"
         {
    (yyval.exp).addr = new char[2];
    (yyval.exp).addr = (char*)"1";
    (yyval.exp).type = BOOL;
    if(!assign){
    	 (yyval.exp).tlist = makeList(nextInstr);
	     (yyval.exp).flist = NULL;
	     genCode("goto",EMPTY);
    }
    else{
		assign = false;
	}
  }
#line 2654 "rule.c"
    break;

  case 108:
#line 795 "yaccrule.y"
          {
    (yyval.exp).addr = new char[2];
    (yyval.exp).addr = (char*)"0";
    (yyval.exp).type   = BOOL;
    if(!assign){
	    (yyval.exp).flist = makeList(nextInstr);
	    (yyval.exp).tlist = NULL;
	    genCode("goto",EMPTY);
	}
	else{
		assign = false;
	}
  }
#line 2672 "rule.c"
    break;

  case 109:
#line 811 "yaccrule.y"
{(yyval.mark).instr = nextInstr;}
#line 2678 "rule.c"
    break;


#line 2682 "rule.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 813 "yaccrule.y"


void yyerror(const char *s){
  AddError((char*)" ... is missing",lineno,ERROR);
}

int main(int argc,char *argv[ ]){

  FILE* fp=NULL;
  if(argc<2){
    fprintf(stderr,"No input file\n");
    return 0;
  }
  if(argc == 2){
    fp=fopen(argv[1],"r");
  }
  if(fp==NULL){
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 0;
  }
  yyin=fp;
  InitializeSymbolTable();
  Error = NULL;

  while(!feof(yyin)){
    yyparse();
  }
  fclose(fp);

  DeleteSymbolTable();

  if(Error  ==  NULL ) printCode();
  else{
    printError();
  }
  return 0;
}
