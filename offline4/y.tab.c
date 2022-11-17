/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1805009.y" /* yacc.c:339  */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include "symboltable.cpp"
#include "optimize.cpp"

    using namespace std;

    int yyparse(void);
    int yylex(void);
    extern FILE *yyin;
    FILE *fout,*errorout,*assemblyout;
    SymbolInfo temp("","");
    string temps;
    int flag=0;
    int ismain=0;
    int ismainreturn=0;
    extern int line_count;
    extern int err;
    extern int yylineno;

    SymbolTable st(30);
    vector<string>args_type;
    stack<string>labels;
    int offset;
    int label_no=0;
    void yyerror(char *s)
    {
        fprintf(fout,"Error at line %d: %s\n",line_count,s);
        fprintf(errorout,"Error at line %d: %s\n",line_count,s);
        err++;
        //write your code
    }
    string newLabel()
    {
        label_no++;
        stringstream ss;
        ss<<"L"<<label_no;
        return ss.str();
    }



#line 113 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PRINTLN = 258,
    ADDOP = 259,
    MULOP = 260,
    DECOP = 261,
    INCOP = 262,
    RELOP = 263,
    ASSIGNOP = 264,
    LOGICOP = 265,
    NOT = 266,
    LPAREN = 267,
    RPAREN = 268,
    LCURL = 269,
    RCURL = 270,
    LTHIRD = 271,
    RTHIRD = 272,
    COMMA = 273,
    SEMICOLON = 274,
    IF = 275,
    FOR = 276,
    DO = 277,
    INT = 278,
    FLOAT = 279,
    VOID = 280,
    SWITCH = 281,
    DEFAULT = 282,
    ELSE = 283,
    WHILE = 284,
    BREAK = 285,
    CHAR = 286,
    DOUBLE = 287,
    RETURN = 288,
    CASE = 289,
    CONTINUE = 290,
    CONST_INT = 291,
    CONST_FLOAT = 292,
    CONST_CHAR = 293,
    ID = 294,
    STRING = 295,
    LOWER_THAN_ELSE = 296
  };
#endif
/* Tokens.  */
#define PRINTLN 258
#define ADDOP 259
#define MULOP 260
#define DECOP 261
#define INCOP 262
#define RELOP 263
#define ASSIGNOP 264
#define LOGICOP 265
#define NOT 266
#define LPAREN 267
#define RPAREN 268
#define LCURL 269
#define RCURL 270
#define LTHIRD 271
#define RTHIRD 272
#define COMMA 273
#define SEMICOLON 274
#define IF 275
#define FOR 276
#define DO 277
#define INT 278
#define FLOAT 279
#define VOID 280
#define SWITCH 281
#define DEFAULT 282
#define ELSE 283
#define WHILE 284
#define BREAK 285
#define CHAR 286
#define DOUBLE 287
#define RETURN 288
#define CASE 289
#define CONTINUE 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define CONST_CHAR 293
#define ID 294
#define STRING 295
#define LOWER_THAN_ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "1805009.y" /* yacc.c:355  */

    SymbolInfo* symbolinfo;
    complex_obj *obj;

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,   131,   153,   169,   184,   197,   214,
     265,   303,   302,   444,   443,   558,   600,   622,   654,   670,
     679,   678,   725,   751,   802,   807,   812,   820,   854,   897,
     919,   952,   975,   988,   995,  1008,  1028,  1034,  1046,  1059,
    1072,  1073,  1075,  1072,  1127,  1164,  1164,  1224,  1225,  1224,
    1266,  1311,  1354,  1360,  1366,  1375,  1393,  1428,  1489,  1497,
    1511,  1570,  1583,  1583,  1630,  1644,  1644,  1710,  1724,  1724,
    1766,  1780,  1780,  1854,  1876,  1897,  1913,  1938,  2019,  2035,
    2045,  2055,  2087,  2123,  2137,  2146,  2166
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINTLN", "ADDOP", "MULOP", "DECOP",
  "INCOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "IF", "FOR",
  "DO", "INT", "FLOAT", "VOID", "SWITCH", "DEFAULT", "ELSE", "WHILE",
  "BREAK", "CHAR", "DOUBLE", "RETURN", "CASE", "CONTINUE", "CONST_INT",
  "CONST_FLOAT", "CONST_CHAR", "ID", "STRING", "LOWER_THAN_ELSE",
  "$accept", "start", "$@1", "program", "unit", "func_declaration",
  "func_definition", "$@2", "$@3", "parameter_list", "compound_statement",
  "$@4", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "X", "expression_statement", "variable", "expression",
  "logic_expression", "$@11", "rel_expression", "$@12",
  "simple_expression", "$@13", "term", "$@14", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -78,    13,   100,   -78,   -78,   -78,   -78,   100,   -78,   -78,
     -78,   -78,   -25,   -78,    42,     8,    79,     9,   -78,   -23,
     -78,     2,    71,    -6,    21,    43,    47,   -78,    69,   -78,
      66,   100,   -78,   -78,   -78,    19,    93,   -78,   -78,    69,
      55,    89,    97,   -78,   107,   -78,   -78,   -78,   -78,   105,
      25,    25,    25,   -78,   117,   121,   126,     7,   -78,   -78,
      70,   -78,   -78,   102,    76,   -78,   -78,   128,   120,   -78,
     132,   112,   140,   -78,   -78,   108,    67,   -78,   -78,   135,
      25,    20,   -78,   -78,   130,    25,    11,   134,   -78,   -78,
     -78,   -78,   -78,    25,   -78,   -78,   -78,   -78,   -78,   138,
     -78,   139,   -78,    25,   -78,   -78,   141,   137,   136,   142,
     -78,    25,    25,    25,    25,   143,   -78,    20,   -78,   -78,
      25,   -78,   -78,   -78,   140,   152,   -78,   -78,   107,   -78,
     144,   -78,   133,    25,   107,   -78,   145,   -78,   107,   -78,
     -78,   107,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    24,    25,    26,     3,     5,     7,
       8,     6,     0,     4,    29,     0,     0,     0,    33,     0,
      23,    13,     0,    18,     0,     0,    27,    10,     0,    19,
      11,     0,    17,    32,    30,     0,    20,    14,     9,     0,
      16,     0,     0,    22,     0,    12,    15,    31,    28,     0,
       0,     0,     0,    54,     0,     0,     0,     0,    79,    80,
      56,    39,    37,     0,     0,    34,    38,    76,     0,    59,
      61,    64,    67,    70,    75,     0,    76,    73,    74,     0,
       0,     0,    47,    52,     0,    84,     0,    29,    36,    21,
      35,    82,    81,     0,    55,    62,    68,    65,    71,     0,
      78,     0,    40,     0,    51,    86,     0,    83,     0,     0,
      60,     0,     0,     0,     0,     0,    53,     0,    48,    77,
       0,    58,    57,    63,    69,    66,    72,    50,     0,    41,
       0,    85,    44,     0,     0,    45,     0,    49,     0,    42,
      46,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   -78,   153,   -78,   -78,   -78,   -78,   -78,
      14,   -78,    28,    91,   -78,   -78,   -63,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -77,   -44,   -52,   -68,   -78,    52,
     -78,    51,   -78,    53,   -78,   -48,   -78,   -78,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    10,    39,    28,    22,
      61,    44,    62,    63,    15,    64,    65,   117,   133,   141,
     138,   103,   130,   128,    66,    67,    68,    69,   111,    70,
     113,    71,   112,    72,   114,    73,    74,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      79,    90,    77,    78,   102,    84,    76,    76,    83,    18,
      24,    50,   108,     3,    14,    50,    26,   105,    51,    52,
      41,    27,    51,    52,    50,   110,    19,    20,   101,    50,
      11,    51,    52,    32,   109,    11,    51,    52,    33,    53,
     129,    76,    37,    58,    59,    25,    60,    58,    59,    76,
      60,   118,   131,    45,    16,    42,    58,    59,    17,    60,
      34,    58,    59,    35,    60,   132,   126,    76,    76,    76,
      76,   137,    29,    91,    92,   140,    76,    88,   142,    49,
      50,   136,    85,    36,    30,    38,    86,    51,    52,    31,
      36,    89,    21,    12,    46,    53,    54,    55,    12,     4,
       5,     6,     4,     5,     6,    56,    47,    23,    43,    57,
      49,    50,    58,    59,    48,    60,    96,    75,    51,    52,
      97,    36,    40,     4,     5,     6,    53,    54,    55,    80,
       4,     5,     6,    81,    91,    92,    56,    93,    82,    94,
      57,    87,    95,    58,    59,    98,    60,    99,   100,   104,
      17,   115,   116,   121,   119,   120,    96,   134,   139,   122,
      13,   135,   127,   123,   125,   124
};

static const yytype_uint8 yycheck[] =
{
      52,    64,    50,    51,    81,    57,    50,    51,     1,     1,
       1,     4,     1,     0,    39,     4,    39,    85,    11,    12,
       1,    19,    11,    12,     4,    93,    18,    19,    80,     4,
       2,    11,    12,    39,    86,     7,    11,    12,    17,    19,
     117,    85,    28,    36,    37,    36,    39,    36,    37,    93,
      39,   103,   120,    39,    12,    36,    36,    37,    16,    39,
      17,    36,    37,    16,    39,   128,   114,   111,   112,   113,
     114,   134,     1,     6,     7,   138,   120,     1,   141,     3,
       4,   133,    12,    14,    13,    19,    16,    11,    12,    18,
      14,    15,    13,     2,    39,    19,    20,    21,     7,    23,
      24,    25,    23,    24,    25,    29,    17,    16,    15,    33,
       3,     4,    36,    37,    17,    39,     4,    12,    11,    12,
       8,    14,    31,    23,    24,    25,    19,    20,    21,    12,
      23,    24,    25,    12,     6,     7,    29,     9,    12,    19,
      33,    39,    10,    36,    37,     5,    39,    39,    13,    19,
      16,    13,    13,    17,    13,    18,     4,    13,    13,    17,
       7,    28,    19,   111,   113,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,     0,    23,    24,    25,    45,    46,    47,
      48,    54,    55,    46,    39,    56,    12,    16,     1,    18,
      19,    13,    51,    55,     1,    36,    39,    19,    50,     1,
      13,    18,    39,    17,    17,    16,    14,    52,    19,    49,
      55,     1,    36,    15,    53,    52,    39,    17,    17,     3,
       4,    11,    12,    19,    20,    21,    29,    33,    36,    37,
      39,    52,    54,    55,    57,    58,    66,    67,    68,    69,
      71,    73,    75,    77,    78,    12,    67,    77,    77,    68,
      12,    12,    12,     1,    68,    12,    16,    39,     1,    15,
      58,     6,     7,     9,    19,    10,     4,     8,     5,    39,
      13,    68,    66,    63,    19,    69,    79,    80,     1,    68,
      69,    70,    74,    72,    76,    13,    13,    59,    68,    13,
      18,    17,    17,    71,    75,    73,    77,    19,    65,    66,
      64,    69,    58,    60,    13,    28,    68,    58,    62,    13,
      58,    61,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    46,    46,    46,    47,
      47,    49,    48,    50,    48,    51,    51,    51,    51,    51,
      53,    52,    52,    54,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    58,
      59,    60,    61,    58,    58,    62,    58,    63,    64,    58,
      58,    58,    58,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    70,    69,    71,    72,    71,    73,    74,    73,
      75,    76,    75,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     6,
       5,     0,     7,     0,     6,     4,     3,     2,     1,     2,
       0,     4,     2,     3,     1,     1,     1,     3,     6,     1,
       4,     6,     4,     2,     1,     2,     2,     1,     1,     1,
       0,     0,     0,    10,     6,     0,     9,     0,     0,     7,
       5,     3,     2,     0,     1,     2,     1,     4,     4,     1,
       3,     1,     0,     4,     1,     0,     4,     1,     0,     4,
       1,     0,     4,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 63 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(assemblyout,".model small\n.stack 100h\n.data\ncr equ 0Dh\nlf equ 0Ah\nnumber db \"00000$\"\n");
}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: start : program\n",line_count);
    fprintf(fout,"%s\n",st.Print_All_ScopeTable().c_str());
    fprintf(fout,"Total lines: %d\n",yylineno);
    fprintf(fout,"Total errors: %d\n",err);
    fprintf(fout,"\n");

    fprintf(assemblyout,"new_line proc\n\
    push ax\n\
    push dx\n\
    mov ah,2\n\
    mov dl,cr\n\
    int 21h\n\
    mov ah,2\n\
    mov dl,lf\n\
    int 21h\n\
    pop dx\n\
    pop ax\n\
    ret\n\
    new_line endp\n");
    fprintf(assemblyout,"print_output proc  ;print what is in ax\n\
    push ax\n\
    push bx\n\
    push cx\n\
    push dx\n\
    push si\n\
    lea si,number\n\
    mov bx,10\n\
    add si,4\n\
    cmp ax,0\n\
    jnge negate\n\
    print:\n\
    xor dx,dx\n\
    div bx\n\
    mov [si],dl\n\
    add [si],'0'\n\
    dec si\n\
    cmp ax,0\n\
    jne print\n\
    inc si\n\
    lea dx,si\n\
    mov ah,9\n\
    int 21h\n\
    pop si\n\
    pop dx\n\
    pop cx\n\
    pop bx\n\
    pop ax\n\
    ret\n\
    negate:\n\
    push ax\n\
    mov ah,2\n\
    mov dl,'-'\n\
    int 21h\n\
    pop ax\n\
    neg ax\n\
    jmp print\n\
    print_output endp\n");
    fprintf(assemblyout,"end main\n");

}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: program : program unit\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
    }

    (yyval.obj)->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    fprintf(fout,"\n");
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");

}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 154 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: program : unit\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    
    fprintf(fout,"\n");

}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 170 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: unit : var_declaration\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");


}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 185 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: unit : func_declaration\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");
}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 198 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: unit : func_definition\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");


}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 215 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[-4].symbolinfo)->getName(),"ID",(yyvsp[-5].symbolinfo)->getName()))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-4].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-4].symbolinfo)->getName().c_str());
        err++;
    }
    SymbolInfo* obj=st.Look_up((yyvsp[-4].symbolinfo)->getName());
    obj->num_of_param=0;
    obj->isdeclared=1;
    for(int i=0; i<(yyvsp[-2].obj)->vec->size(); i++)
    {
        if ((yyvsp[-2].obj)->vec->at(i)->getName()=="int" || (yyvsp[-2].obj)->vec->at(i)->getName()=="float")
        {
            obj->parameter_list.push_back(new SymbolInfo((yyvsp[-2].obj)->vec->at(i)->getName(),(yyvsp[-2].obj)->vec->at(i)->getType(),(yyvsp[-2].obj)->vec->at(i)->getName()));
            obj->num_of_param++;
        }

    }
    fprintf(fout,"Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
    
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-5].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str());
    
    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    
    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());
    
    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
   
    for(int i=0; i<(yyvsp[-2].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-2].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-2].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    
    st.Enter_Scope();
    st.Exit_Scope();
    temp.parameter_list.clear();
}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 266 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[-3].symbolinfo)->getName(),"ID",(yyvsp[-4].symbolinfo)->getName()))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        err++;
    }
    SymbolInfo* obj=st.Look_up((yyvsp[-3].symbolinfo)->getName());
    obj->num_of_param=0;
    obj->isdeclared=1;
    (yyvsp[-3].symbolinfo)->setDataType((yyvsp[-4].symbolinfo)->getName());
    fprintf(fout,"Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());

    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());

    fprintf(fout,"\n");


    st.Enter_Scope();
    st.Exit_Scope();
}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 303 "1805009.y" /* yacc.c:1646  */
    {   
	if (!st.Insert((yyvsp[-3].symbolinfo)->getName(),"ID",(yyvsp[-4].symbolinfo)->getName()))
    {
        SymbolInfo* obj=st.Look_up((yyvsp[-3].symbolinfo)->getName());
        if (!obj->isdeclared || obj->isdefined)
        {
            fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            err++;
        }
    }

    SymbolInfo* obj=st.Look_up((yyvsp[-3].symbolinfo)->getName());
    obj->isdefined=1;
    if (obj->isdeclared)
    {
        if (obj->getDataType()!=(yyvsp[-4].symbolinfo)->getName())
        {
            fprintf(fout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            //err++;
        }

        int k=0;
        for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
        {
            if ((yyvsp[-1].obj)->vec->at(i)->getType()=="ID")
            {
                if (k>=obj->parameter_list.size())
                {
                    fprintf(fout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
                    fprintf(errorout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
                    err++;
                    break;
                }
                else if ((yyvsp[-1].obj)->vec->at(i-2)->getName()!=obj->parameter_list[k]->getName())
                {
                    fprintf(fout,"Error at line %d: Type Mismatch\n",line_count);
                    fprintf(errorout,"Error at line %d: Type Mismatch\n",line_count);
                    err++;
                }
                k++;
            }

        }
        if (k<obj->parameter_list.size())
        {
            fprintf(fout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            err++;
        }
    }
    else
    {
        obj->num_of_param=0;
        obj->isdeclared=1;
        obj->isdefined=1;
        for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
        {
            if ((yyvsp[-1].obj)->vec->at(i)->getType()=="ID")
            {
                obj->parameter_list.push_back(new SymbolInfo((yyvsp[-1].obj)->vec->at(i)->getName(),(yyvsp[-1].obj)->vec->at(i)->getType(),(yyvsp[-1].obj)->vec->at(i-2)->getName()));
                obj->num_of_param++;

            }

        }
    }
    fprintf(assemblyout,";");  //print statement
    fprintf(assemblyout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());  //print statement
    fprintf(assemblyout," ");  //print statement
    fprintf(assemblyout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());  //print statement
     fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());  //print statement
     for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        fprintf(assemblyout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());  //print statement
    }
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());  //print statement
    fprintf(assemblyout,"\n");  //print statement
    if (flag==0) {flag=1;fprintf(assemblyout,".code\n");}
    fprintf(assemblyout,"%s proc\npush bp\nmov bp,sp\n",(yyvsp[-3].symbolinfo)->getName().c_str());
    int temp_int=(obj->num_of_param+1)*2;
    for(int i=2;temp_int>2;i+=2)
    {
        fprintf(assemblyout,"mov bx,[bp+%d]\n",temp_int);
        fprintf(assemblyout,"mov [bp-%d],bx\n",i);
        temp_int-=2;
    }
offset=0;

}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 394 "1805009.y" /* yacc.c:1646  */
    {
    SymbolInfo* obj=st.Look_up((yyvsp[-5].symbolinfo)->getName());
    if (obj->getDataType()!=(yyvsp[0].obj)->return_type)
    {
        fprintf(fout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        fprintf(errorout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        //err++;
    }
    fprintf(fout,"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-6].symbolinfo));

    fprintf(fout,"%s",(yyvsp[-6].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    (yyval.obj)->vec->push_back((yyvsp[-5].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str());


    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());

    }
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    if ((yyvsp[-6].symbolinfo)->getName()=="void")
    {for(int i=0;i<offset;i+=2)
    {
        fprintf(assemblyout,"add sp,2\n");
    }
    fprintf(assemblyout,"pop bp\nret\n%s endp\n",(yyvsp[-5].symbolinfo)->getName().c_str());}
     else
    {
        fprintf(assemblyout,"%s endp\n",(yyvsp[-5].symbolinfo)->getName().c_str());
    }


}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 444 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[-2].symbolinfo)->getName(),"ID",(yyvsp[-3].symbolinfo)->getName()))
    {
        SymbolInfo* obj=st.Look_up((yyvsp[-2].symbolinfo)->getName());
        if (!obj->isdeclared || obj->isdefined)
            {fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
            }
    }

    SymbolInfo* obj=st.Look_up((yyvsp[-2].symbolinfo)->getName());
    if (obj->isdeclared)
    {
        if (obj->getDataType()!=(yyvsp[-3].symbolinfo)->getName() && (yyvsp[-2].symbolinfo)->getName()!="main")
        {
            fprintf(fout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
            //err++;
        }
        if (obj->parameter_list.size()>0)
        {
            fprintf(fout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
            err++;
        }
    }

    obj->isdefined=1;
    obj->isdeclared=1;
    obj->num_of_param=0;
    fprintf(assemblyout,";"); //print statement
    fprintf(assemblyout,"%s ",(yyvsp[-3].symbolinfo)->getName().c_str());  //print statement
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());  //print statement
    fprintf(assemblyout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());  //print statement
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());  //print statement
    fprintf(assemblyout,"\n");  //print statement
    if (flag==0) {flag=1;fprintf(assemblyout,".code\n");}
    if ((yyvsp[-2].symbolinfo)->getName()=="main")
    {
        fprintf(assemblyout,"main proc\nmov ax,@data\nmov ds,ax\nmov bp,sp\n");
        ismain=1;
    }
    else
    {
        fprintf(assemblyout,"%s proc\npush bp\nmov bp,sp\n",(yyvsp[-2].symbolinfo)->getName().c_str());
    }
    int temp_int=(obj->num_of_param+1)*2;
    for(int i=2;temp_int>2;i+=2)
    {
        fprintf(assemblyout,"mov bx,[bp+%d]\n",temp_int);
        fprintf(assemblyout,"mov [bp-%d],bx\n",i);
        temp_int-=2;
    }
offset=0;

}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 500 "1805009.y" /* yacc.c:1646  */
    {
    SymbolInfo* obj=st.Look_up((yyvsp[-4].symbolinfo)->getName());
    if (obj->getDataType()!=(yyvsp[0].obj)->return_type && (yyvsp[-4].symbolinfo)->getName()!="main")
    {
        fprintf(fout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        fprintf(errorout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        //err++;
    }
    fprintf(fout,"Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-5].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str());

    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());


    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    
  
    
            if ((yyvsp[-5].symbolinfo)->getName()=="void")
    {for(int i=0;i<offset;i+=2)
    {
        fprintf(assemblyout,"add sp,2\n");
    }
    fprintf(assemblyout,"pop bp\nret\n%s endp\n",(yyvsp[-4].symbolinfo)->getName().c_str());}
    else if ((yyvsp[-4].symbolinfo)->getName()!="main")
    {
        fprintf(assemblyout,"%s endp\n",(yyvsp[-4].symbolinfo)->getName().c_str());
    }
    else if ((yyvsp[-4].symbolinfo)->getName()=="main" && ismainreturn==0)
    {
        fprintf(assemblyout,"mov ah,4Ch\nint 21h\nmain endp\n");
    }
    



}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 559 "1805009.y" /* yacc.c:1646  */
    {
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getName()==(yyvsp[0].symbolinfo)->getName())
        {
            fprintf(fout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
            err++;
        }

    }
    temp.parameter_list.push_back((yyvsp[-1].symbolinfo));
    temp.parameter_list.push_back((yyvsp[0].symbolinfo));
    if ((yyvsp[-1].symbolinfo)->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s ",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));

    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());


    fprintf(fout,"\n");
    


}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 601 "1805009.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].symbolinfo)->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : parameter_list COMMA type_specifier\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-2].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-2].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-2].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());

    fprintf(fout,"\n");
}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 623 "1805009.y" /* yacc.c:1646  */
    {
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getName()==(yyvsp[0].symbolinfo)->getName())
        {
            fprintf(fout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
            err++;
        }

    }
    if ((yyvsp[-1].symbolinfo)->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : type_specifier ID\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s ",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    temp.parameter_list.push_back((yyvsp[-1].symbolinfo));
    temp.parameter_list.push_back((yyvsp[0].symbolinfo));
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());

    fprintf(fout,"\n");


}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 655 "1805009.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].symbolinfo)->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : type_specifier\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());

    fprintf(fout,"\n");

}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 671 "1805009.y" /* yacc.c:1646  */
    {

}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 679 "1805009.y" /* yacc.c:1646  */
    {

    st.Enter_Scope();
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getType()=="ID" && temp.parameter_list[i-1]->getName()!="void")
        {
            st.Insert(temp.parameter_list[i]->getName(),"ID",temp.parameter_list[i-1]->getName());
            SymbolInfo* element=st.Look_up(temp.parameter_list[i]->getName());
            offset+=2;
            fprintf(assemblyout,"sub sp,2\n");
            element->offset=offset;
            //fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,temp.parameter_list[i]->getName().c_str());

        }
    }
	temp.parameter_list.clear();

}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 698 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: compound_statement : LCURL statements RCURL\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s ",(yyvsp[-3].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back(new SymbolInfo("\n","NEWLINE"));
    fprintf(fout,"\n");

    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());

    }
    (yyval.obj)->vec->push_back(new SymbolInfo("\n","NEWLINE"));
    fprintf(fout,"\n");
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());

    fprintf(fout,"\n");
    fprintf(fout,"%s\n",st.Print_All_ScopeTable().c_str());
    st.Exit_Scope();


    (yyval.obj)->return_type=(yyvsp[-1].obj)->return_type;
  
}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 726 "1805009.y" /* yacc.c:1646  */
    {
	fprintf(fout,"Line %d: compound_statement : LCURL RCURL\n",line_count);
    st.Enter_Scope();
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getType()=="ID" && temp.parameter_list[i-1]->getName()!="void")
        {
            st.Insert(temp.parameter_list[i]->getName(),"ID",temp.parameter_list[i-1]->getName());
            //fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,temp.parameter_list[i]->getName().c_str());
        }
    }
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s ",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    temp.parameter_list.clear();
    fprintf(fout,"%s\n",st.Print_All_ScopeTable().c_str());
    st.Exit_Scope();

}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 752 "1805009.y" /* yacc.c:1646  */
    {

    fprintf(fout,"Line %d: var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ((yyvsp[-2].symbolinfo)->getDataType()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s ",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s ",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement

    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str()); //print statement

        if ((yyvsp[-1].obj)->vec->at(i)->getType()=="ID")
        {
            //st.Insert($2->vec->at(i)->getName(),"ID",$1->getName());
            SymbolInfo* element=st.Look_up((yyvsp[-1].obj)->vec->at(i)->getName());
            if ((yyvsp[-2].symbolinfo)->getDataType()=="void")
                st.Remove((yyvsp[-1].obj)->vec->at(i)->getName());
            if (element!=NULL && element->getDataType()=="array")
            {
                element->setDataType((yyvsp[-2].symbolinfo)->getName()+"_array");
            }
            else if (element!=NULL && element->getDataType()=="ID")
                element->setDataType((yyvsp[-2].symbolinfo)->getName());
        }

    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str()); //print statement
    
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement


}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 803 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: type_specifier : INT\n",line_count);
    fprintf(fout,"%s \n",(yyvsp[0].symbolinfo)->getName().c_str());
}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 808 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: type_specifier : FLOAT\n",line_count);
    fprintf(fout,"%s \n",(yyvsp[0].symbolinfo)->getName().c_str());
}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 813 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: type_specifier : VOID\n",line_count);
    fprintf(fout,"%s \n",(yyvsp[0].symbolinfo)->getName().c_str());
}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 821 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: declaration_list : declaration_list COMMA ID\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-2].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-2].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-2].obj)->vec->at(i)->getName().c_str());
    }

    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    if (!st.Insert((yyvsp[0].symbolinfo)->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
        err++;
    }
    
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    offset+=2;
    SymbolInfo* element=st.Look_up((yyvsp[0].symbolinfo)->getName());
    element->offset=offset;
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());

    fprintf(fout,"\n");
    if (element->global==true)
    fprintf(assemblyout,"%s dw ?\n",element->getName().c_str());
    else
    fprintf(assemblyout,"sub sp,2\n");


}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 855 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[-3].symbolinfo)->getName(),"ID","array"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        err++;
    }
    fprintf(fout,"Line %d: declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-5].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-5].obj)->vec->at(i));
        fprintf(fout,"%s",((yyvsp[-5].obj)->vec->at(i)->getName()).c_str());
    }

    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());


    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());

    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    SymbolInfo* element=st.Look_up((yyvsp[-3].symbolinfo)->getName());
    offset+=2;
    element->offset=offset;
    if (element->global==true)
    fprintf(assemblyout,"%s dw %s dup (?)\n",(yyvsp[-3].symbolinfo)->getName().c_str(),(yyvsp[-1].symbolinfo)->getName().c_str());
    else
    fprintf(assemblyout,"push ax\nmov ax,2\nmov bx,%s\nmul bx\nsub sp,ax\npop ax\n",(yyvsp[-1].symbolinfo)->getName().c_str());
    stringstream ss;
    int temp_int;
    ss<<(yyvsp[-1].symbolinfo)->getName();
    ss>>temp_int;
    offset+=(2*temp_int-2);
}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 898 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[0].symbolinfo)->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
        err++;
    }
    fprintf(fout,"Line %d: declaration_list: ID\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    SymbolInfo* element=st.Look_up((yyvsp[0].symbolinfo)->getName());
    offset+=2;
    element->offset=offset;
    if (element->global==true)
    fprintf(assemblyout,"%s dw ?\n",element->getName().c_str());
    else
    fprintf(assemblyout,"sub sp,2\n");
}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 920 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[-3].symbolinfo)->getName(),"ID","array"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        err++;
    }

    fprintf(fout,"Line %d: declaration_list: ID LTHIRD CONST_INT RTHIRD\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    SymbolInfo* element=st.Look_up((yyvsp[-3].symbolinfo)->getName());
    offset+=2;
    element->offset=offset;
    if (element->global==true)
    fprintf(assemblyout,"%s dw %s dup (?)\n",(yyvsp[-3].symbolinfo)->getName().c_str(),(yyvsp[-1].symbolinfo)->getName().c_str());
    else
    fprintf(assemblyout,"push ax\nmov ax,2\nmov bx,%s\nmul bx\nsub sp,ax\npop ax\n",(yyvsp[-1].symbolinfo)->getName().c_str());
    stringstream ss;
    int temp_int;
    ss<<(yyvsp[-1].symbolinfo)->getName();
    ss>>temp_int;
    offset+=(2*temp_int-2);
}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 953 "1805009.y" /* yacc.c:1646  */
    {   if (!st.Insert((yyvsp[-3].symbolinfo)->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        err++;
    }
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-5].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-5].obj)->vec->at(i));
        fprintf(fout,"%s",((yyvsp[-5].obj)->vec->at(i)->getName()).c_str());
    }

    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());


    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");

}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 976 "1805009.y" /* yacc.c:1646  */
    {
    if (!st.Insert((yyvsp[-3].symbolinfo)->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        err++;
    }
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 989 "1805009.y" /* yacc.c:1646  */
    {

}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 996 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statements : statement\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",((yyvsp[0].obj)->vec->at(i)->getName()).c_str());
    }

    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;
}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1009 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statements : statements statement\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",((yyvsp[-1].obj)->vec->at(i)->getName()).c_str());
    }
    (yyval.obj)->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    fprintf(fout,"\n");
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",((yyvsp[0].obj)->vec->at(i)->getName()).c_str());
    }
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;

    fprintf(fout,"\n");
}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1029 "1805009.y" /* yacc.c:1646  */
    {

}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1035 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : var_declaration\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");

}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1047 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : expression_statement\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;

}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1060 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : compound_statement\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;

}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1072 "1805009.y" /* yacc.c:1646  */
    {labels.push(newLabel()); fprintf(assemblyout,"%s:\n",labels.top().c_str());}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1073 "1805009.y" /* yacc.c:1646  */
    {fprintf(assemblyout,"cmp bx,0\nje end_%s\n",labels.top().c_str());
labels.push(newLabel());fprintf(assemblyout,"jmp end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1075 "1805009.y" /* yacc.c:1646  */
    {temps=labels.top(); labels.pop(); fprintf(assemblyout,"jmp %s\nend_%s:\n",labels.top().c_str(),temps.c_str()); labels.push(temps);}
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1076 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-9].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-9].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-9].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->vec->push_back((yyvsp[-8].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-8].symbolinfo)->getName().c_str());
     fprintf(assemblyout,"%s",(yyvsp[-8].symbolinfo)->getName().c_str()); //print statement

    for(int i=0; i<(yyvsp[-7].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-7].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-7].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-7].obj)->vec->at(i)->getName().c_str()); //print statement
    }

    for(int i=0; i<(yyvsp[-5].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-5].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-5].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-5].obj)->vec->at(i)->getName().c_str()); //print statement
    }

    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str()); //print statement
    }

    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement

    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    
    fprintf(assemblyout,"jmp %s\n",labels.top().c_str());
    labels.pop();
    fprintf(assemblyout,"end_%s:\n",labels.top().c_str());
    labels.pop();

}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1128 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : IF LPAREN expression RPAREN statement\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-5].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str()); //print statement
    }


    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement

    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement

    fprintf(assemblyout,"%s:\n",labels.top().c_str());
    labels.pop();


}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1164 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(assemblyout,"jmp end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
    fprintf(assemblyout,";"); //print statement
    fprintf(assemblyout,"%s",(yyvsp[-6].symbolinfo)->getName().c_str()); //print statement
    fprintf(assemblyout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[-4].obj)->vec->size(); i++)
    {
        fprintf(assemblyout,"%s",(yyvsp[-4].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(assemblyout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str()); //print statement
    fprintf(assemblyout,"\n");

    }
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1177 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-8].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-8].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-8].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->vec->push_back((yyvsp[-7].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-7].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-7].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[-6].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-6].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-6].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-6].obj)->vec->at(i)->getName().c_str()); //print statement
    }


    (yyval.obj)->vec->push_back((yyvsp[-5].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str()); //print statement

    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    (yyval.obj)->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"end_%s:\n",labels.top().c_str());
    labels.pop();
    

}
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1224 "1805009.y" /* yacc.c:1646  */
    {labels.push(newLabel()); fprintf(assemblyout,"%s:\n",labels.top().c_str());}
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1225 "1805009.y" /* yacc.c:1646  */
    {fprintf(assemblyout,"cmp bx,0\nje end_%s\n",labels.top().c_str());
fprintf(assemblyout,";"); //print statement
fprintf(assemblyout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str()); //print statement
fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(assemblyout,")\n"); //print statement
}
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1235 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : WHILE LPAREN expression RPAREN statement\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-6].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-6].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-5].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-5].symbolinfo)->getName().c_str());

    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
    }


    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());

    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");

    fprintf(assemblyout,"jmp %s\nend_%s:\n",labels.top().c_str(),labels.top().c_str());
    labels.pop();


}
#line 2811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1267 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);
    fprintf(assemblyout,";"); //print statement;
    SymbolInfo* obj=st.Look_up((yyvsp[-2].symbolinfo)->getName());
    if (obj==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared variable %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared variable %s\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
        err++;
    }
    else if(obj->getDataType().find("array")!=string::npos)
    {
        fprintf(fout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,(yyvsp[-2].symbolinfo)->getName().c_str());
        err++;
    }
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-4].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-4].symbolinfo)->getName().c_str()); //print statement;
    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str()); //print statement;

    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement;

    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str()); //print statement;
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str()); //print statement;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement;
    if (obj->global==true)
    fprintf(assemblyout,"mov ax,%s\ncall print_output\ncall new_line\n",obj->getName().c_str());
    else

    fprintf(assemblyout,"mov ax,[bp-%d]\ncall print_output\ncall new_line\n",obj->offset);


}
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1312 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: statement : RETURN expression SEMICOLON\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    fprintf(assemblyout," "); //print statement
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str()); //print statement
    }


    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str()); //print statement


    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    (yyval.obj)->return_type=(yyvsp[-1].obj)->return_type;
    if (ismain==0)
   {for(int i=0;i<offset;i+=2)
    {
        fprintf(assemblyout,"add sp,2\n");
    }
    fprintf(assemblyout,"pop bp\nret\n");}
    else
    {   
    
        fprintf(assemblyout,"mov ah,4Ch\nint 21h\nmain endp\n");
        ismainreturn=1;
    

    }
}
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1355 "1805009.y" /* yacc.c:1646  */
    {
	(yyval.obj)=new complex_obj();
}
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1360 "1805009.y" /* yacc.c:1646  */
    {labels.push(newLabel());
    fprintf(assemblyout,"cmp bx,0\nje %s\n",labels.top().c_str());

}
#line 2923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1367 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: expression_statement : SEMICOLON\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");

}
#line 2936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1376 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: expression_statement : expression SEMICOLON\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
}
#line 2953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1394 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: variable : ID\n",line_count);
    (yyval.obj)=new complex_obj();
    SymbolInfo* element=st.Look_up((yyvsp[0].symbolinfo)->getName());
    if (element==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared variable %s\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared variable %s\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
        err++;
        (yyval.obj)->return_type="int";
    }
    else
    {
        if(element->getDataType().size()>=6 && element->getDataType().substr(element->getDataType().size()-6,element->getDataType().size())=="_array")
        {
            fprintf(fout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,(yyvsp[0].symbolinfo)->getName().c_str());
            err++;
            (yyval.obj)->return_type=element->getDataType();
            (yyval.obj)->offset=element->offset;
        }
        else
            {(yyval.obj)->return_type=element->getDataType();
            (yyval.obj)->offset=element->offset;
            }
    }
   (yyvsp[0].symbolinfo)->global=element->global;
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    


}
#line 2992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1429 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
    (yyval.obj)=new complex_obj();
    SymbolInfo* element=st.Look_up((yyvsp[-3].symbolinfo)->getName());
    if (element==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared variable %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared variable %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        (yyval.obj)->return_type="int";
        err++;
    }
    else
    {
        if (element->getDataType().find("array")==string::npos)
        {
            fprintf(fout,"Error at line %d:  %s is not an array\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d:  %s is not an array\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            err++;
            (yyval.obj)->return_type=element->getDataType();
            (yyval.obj)->offset=element->offset;
        }
        else
        {
            (yyval.obj)->return_type=element->getDataType().substr(0,element->getDataType().size()-6);
            (yyval.obj)->DataType=element->getDataType();
            (yyval.obj)->offset=element->offset;
        }
    }

    if ((yyvsp[-1].obj)->return_type!="int")
    {
        fprintf(fout,"Error at line %d: Expression inside third brackets not an integer\n",line_count);
        fprintf(errorout,"Error at line %d: Expression inside third brackets not an integer\n",line_count);
        err++;
    }
    

    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
    (yyvsp[-3].symbolinfo)->global=element->global;
    if (element->global==true)
    fprintf(assemblyout,"push ax\nmov ax,2\nmul bx\n");
    else
    fprintf(assemblyout,"push ax\nmov ax,2\nmul bx\nadd ax,%d\n",element->offset);
    
    



}
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1490 "1805009.y" /* yacc.c:1646  */
    {
	(yyval.obj)=new complex_obj();
	(yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
}
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1498 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: expression : logic_expression\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;


}
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1512 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: expression : variable ASSIGNOP logic_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    if ((yyvsp[-2].obj)->return_type!=(yyvsp[0].obj)->return_type)
    {
        if ((yyvsp[-2].obj)->return_type=="float" && (yyvsp[0].obj)->return_type=="int") ;
        else if ((yyvsp[0].obj)->return_type=="void")
        {
            fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
            fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
            err++;
        }
        else if((yyvsp[-2].obj)->return_type.find("array")==string::npos && (yyvsp[0].obj)->return_type.find("array")==string::npos)
        {
            fprintf(fout,"Error at line %d: Type Mismatch\n",line_count);
            fprintf(errorout,"Error at line %d: Type Mismatch\n",line_count);
            err++;
        }

    }
    for(int i=0; i<(yyvsp[-2].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-2].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-2].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-2].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    (yyval.obj)->return_type=(yyvsp[-2].obj)->return_type;
    if ((yyvsp[-2].obj)->getDataType().find("array")==string::npos)
    {
        if ((yyvsp[-2].obj)->vec->at(0)->global==true)
    {fprintf(assemblyout,"mov %s,bx\n",(yyvsp[-2].obj)->vec->at(0)->getName().c_str());
    
    }
    else
    fprintf(assemblyout,"mov [bp-%d],bx\n",(yyvsp[-2].obj)->offset);}
    else
    {
        if ((yyvsp[-2].obj)->vec->at(0)->global==true)
        fprintf(assemblyout,"push si\nmov si,ax\nmov [%s+si],bx\npop si\npop ax\n",(yyvsp[-2].obj)->vec->at(0)->getName().c_str());
        else
fprintf(assemblyout,"sub bp,ax\nmov [bp],bx\nadd bp,ax\npop ax\n");
    }
}
#line 3144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1571 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: logic_expression : rel_expression\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;

}
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1583 "1805009.y" /* yacc.c:1646  */
    {
if ((yyvsp[0].symbolinfo)->getName()=="||")
{labels.push(newLabel());
fprintf(assemblyout,"cmp bx,0\njne end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
}
else if ((yyvsp[0].symbolinfo)->getName()=="&&")
{labels.push(newLabel());
fprintf(assemblyout,"cmp bx,0\nje end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
}
}
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1593 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ((yyvsp[-3].obj)->return_type=="void" || (yyvsp[0].obj)->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    (yyval.obj)->return_type="int";

    fprintf(assemblyout,"end_%s:\n",labels.top().c_str());
    labels.pop();

}
#line 3215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1631 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: rel_expression	: simple_expression\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;

}
#line 3233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1644 "1805009.y" /* yacc.c:1646  */
    {fprintf(assemblyout,"push ax\nmov ax,bx\n");}
#line 3239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1645 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: rel_expression	: simple_expression RELOP simple_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ((yyvsp[-3].obj)->return_type=="void" || (yyvsp[0].obj)->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    (yyval.obj)->return_type="int";
    if ((yyvsp[-2].symbolinfo)->getName()==">=")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njnge %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ((yyvsp[-2].symbolinfo)->getName()=="<=")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njnle %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ((yyvsp[-2].symbolinfo)->getName()==">")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njng %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ((yyvsp[-2].symbolinfo)->getName()=="<")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njnl %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ((yyvsp[-2].symbolinfo)->getName()=="==")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njne %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ((yyvsp[-2].symbolinfo)->getName()=="!=")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\nje %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }


}
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1711 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: simple_expression : term\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;


}
#line 3324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1724 "1805009.y" /* yacc.c:1646  */
    {fprintf(assemblyout,"push ax\nmov ax,bx\n");}
#line 3330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1725 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: simple_expression : simple_expression ADDOP term\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ((yyvsp[-3].obj)->return_type=="void" || (yyvsp[0].obj)->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ((yyvsp[-3].obj)->return_type=="float" || (yyvsp[0].obj)->return_type=="float")
        (yyval.obj)->return_type="float";
    else
        (yyval.obj)->return_type=(yyvsp[-3].obj)->return_type;
    if ((yyvsp[-2].symbolinfo)->getName()=="+")
        fprintf(assemblyout,"add bx,ax\npop ax\n");
    else if ((yyvsp[-2].symbolinfo)->getName()=="-")
        fprintf(assemblyout,"sub ax,bx\nmov bx,ax\npop ax\n");

}
#line 3372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1767 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: term :	unary_expression\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;


}
#line 3390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1780 "1805009.y" /* yacc.c:1646  */
    {fprintf(assemblyout,"push ax\nmov ax,bx\n");}
#line 3396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1781 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: term : term MULOP unary_expression\n",line_count);
fprintf(assemblyout,";"); //print statement
    if ((yyvsp[-2].symbolinfo)->getName()=="%")
    {
        if ((yyvsp[-3].obj)->return_type!="int")
        {
            fprintf(fout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            fprintf(errorout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            err++;
        }

        else if ((yyvsp[0].obj)->return_type!="int")
        {
            fprintf(fout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            fprintf(errorout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            err++;
        }

        if ((yyvsp[0].obj)->vec->at(0)->getName()=="0")
        {
            fprintf(fout,"Error at line %d: Modulus by Zero\n",line_count);
            fprintf(errorout,"Error at line %d: Modulus by Zero\n",line_count);
            err++;
        }


    }
    if ((yyvsp[-3].obj)->return_type=="void" || (yyvsp[0].obj)->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-3].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-3].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-3].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    if ((yyvsp[-2].symbolinfo)->getName()=="%")
        (yyval.obj)->return_type="int";
    else if ((yyvsp[-3].obj)->return_type=="float" || (yyvsp[0].obj)->return_type=="float")
        (yyval.obj)->return_type="float";
    else
        (yyval.obj)->return_type=(yyvsp[-3].obj)->return_type;
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ((yyvsp[-2].symbolinfo)->getName()=="*")
    {fprintf(assemblyout,"imul bx\nmov bx,ax\npop ax\n");}
    else if ((yyvsp[-2].symbolinfo)->getName()=="%")
    {
     fprintf(assemblyout,"xor dx,dx\nidiv bx\nmov bx,dx\npop ax\n");
    }
    else
    {
      fprintf(assemblyout,"xor dx,dx\nidiv bx\nmov bx,ax\npop ax\n");
    }
}
#line 3471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1855 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: unary_expression : ADDOP unary_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ((yyvsp[-1].symbolinfo)->getName()=="-")
    fprintf(assemblyout,"neg bx\n");


}
#line 3497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1877 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: unary_expression : NOT unary_expression\n",line_count);
     fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str()); //print statement
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
         fprintf(assemblyout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;
    labels.push(newLabel());
    fprintf(assemblyout,"cmp bx,0\njne %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\n",labels.top().c_str(),labels.top().c_str(),labels.top().c_str(),labels.top().c_str());
    labels.pop();
}
#line 3522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1898 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: unary_expression : factor\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;
}
#line 3538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1914 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor	: variable\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->return_type=(yyvsp[0].obj)->return_type;
    fprintf(fout,"\n");
    if ((yyvsp[0].obj)->getDataType().find("array")==string::npos)
    {if ((yyvsp[0].obj)->vec->at(0)->global==true)
    fprintf(assemblyout,"mov bx,%s\n",(yyvsp[0].obj)->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"mov bx,[bp-%d]\n",(yyvsp[0].obj)->offset);}
    else
    {if ((yyvsp[0].obj)->vec->at(0)->global==true)
        fprintf(assemblyout,"push si\nmov si,ax\nmov bx,[%s+si]\npop si\npop ax\n",(yyvsp[0].obj)->vec->at(0)->getName().c_str());
    else
        fprintf(assemblyout,"sub bp,ax\nmov bx,[bp]\nadd bp,ax\npop ax\n");
    }


}
#line 3567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1939 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor : ID LPAREN argument_list RPAREN\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    SymbolInfo* element=st.Look_up((yyvsp[-3].symbolinfo)->getName());
    if (element==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        (yyval.obj)->return_type="int";
        err++;
    }
    else
    {
        if (element->num_of_param==-1)
        {
            fprintf(fout,"Error at line %d: %s is not a function\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            fprintf(errorout,"Error at line %d: %s is not a function\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
            err++;
        }
        (yyval.obj)->return_type=element->getDataType();
    }
    if (element!=NULL && element->num_of_param!=args_type.size())
    {
        fprintf(fout,"Error at line %d: Total number of arguments mismatch in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        fprintf(errorout,"Error at line %d: Total number of arguments mismatch in function %s\n",line_count,(yyvsp[-3].symbolinfo)->getName().c_str());
        err++;
    }
    for(int i=0; i<args_type.size(); i++)
    {
        if (element!=NULL && element->parameter_list[i]->getDataType()!=args_type[i])
        {
            if (args_type[i].size()>=6 && args_type[i].substr(args_type[i].size()-6,args_type[i].size())=="_array")
            {
                /*int k=0,j;
                for(j=0;j<$3->vec->size();j++)
                {if (k==i) break;
                	if ($3->vec->at(j)->getName()==",")
                k++;

                }
                fprintf(fout,"Error at line %d: Type Mismatch,%s is an array\n",line_count,$3->vec->at(j)->getName().c_str());*/
                break;
            }
            else
            {
                fprintf(fout,"Error at line %d: %dth argument mismatch in function %s\n",line_count,i+1,(yyvsp[-3].symbolinfo)->getName().c_str());
                fprintf(errorout,"Error at line %d: %dth argument mismatch in function %s\n",line_count,i+1,(yyvsp[-3].symbolinfo)->getName().c_str());
                err++;
            }
            break;
        }
    }

    (yyval.obj)->vec->push_back((yyvsp[-3].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-3].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str()); //print statement

    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str()); //print statement
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    
    fprintf(assemblyout,"call %s\n",(yyvsp[-3].symbolinfo)->getName().c_str());
    for(int i=0;i<args_type.size();i++)
    {
        fprintf(assemblyout,"pop cx\n");
    }
    args_type.clear();
}
#line 3652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 2020 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor : LPAREN expression RPAREN\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[-2].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-2].symbolinfo)->getName().c_str());
    (yyval.obj)->return_type=(yyvsp[-1].obj)->return_type;
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(fout,"\n");
}
#line 3672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 2036 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor : CONST_INT\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    (yyval.obj)->return_type="int";
    fprintf(fout,"\n");
    fprintf(assemblyout,"mov bx,%s\n",(yyvsp[0].symbolinfo)->getName().c_str());
}
#line 3686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 2046 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor : CONST_FLOAT\n",line_count);
    (yyval.obj)=new complex_obj();
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    (yyval.obj)->return_type="float";
    fprintf(fout,"\n");

}
#line 3700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 2056 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor : variable INCOP\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str()); //print statement
    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->return_type=(yyvsp[-1].obj)->return_type;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
   
    if ((yyvsp[-1].obj)->getDataType().find("array")==string::npos)
    {if ((yyvsp[-1].obj)->vec->at(0)->global==true)
    fprintf(assemblyout,"mov bx,%s\ninc %s\n",(yyvsp[-1].obj)->vec->at(0)->getName().c_str(),(yyvsp[-1].obj)->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"mov bx,[bp-%d]\ninc [bp-%d]\n",(yyvsp[-1].obj)->offset,(yyvsp[-1].obj)->offset);}
    else
    {
    if ((yyvsp[-1].obj)->vec->at(0)->global==true)
    fprintf(assemblyout,"push si\nmov si,ax\nmov bx,[%s+si]\ninc [%s+si]\npop si\npop ax\n",(yyvsp[-1].obj)->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"sub bp,ax\nmov bx,[bp]\ninc [bp]\nadd bp,ax\npop ax\n");
    }

}
#line 3736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 2088 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: factor : variable DECOP\n",line_count);
    fprintf(assemblyout,";"); //print statement
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-1].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-1].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",(yyvsp[-1].obj)->vec->at(i)->getName().c_str()); //print statement
        
    }
    (yyval.obj)->vec->push_back((yyvsp[0].symbolinfo));
    fprintf(fout,"%s",(yyvsp[0].symbolinfo)->getName().c_str());
    fprintf(assemblyout,"%s",(yyvsp[0].symbolinfo)->getName().c_str()); //print statement
    (yyval.obj)->return_type=(yyvsp[-1].obj)->return_type;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ((yyvsp[-1].obj)->getDataType().find("array")==string::npos)
    {if ((yyvsp[-1].obj)->vec->at(0)->global==true)
    fprintf(assemblyout,"mov bx,%s\npush bx\ndec bx\nmov %s,bx\npop bx\n",(yyvsp[-1].obj)->vec->at(0)->getName().c_str(),(yyvsp[-1].obj)->vec->at(0)->getName().c_str());
    else
   fprintf(assemblyout,"mov bx,[bp-%d]\npush bx\ndec bx\nmov [bp-%d],bx\npop bx\n",(yyvsp[-1].obj)->offset,(yyvsp[-1].obj)->offset);}
   else
   {if ((yyvsp[-1].obj)->vec->at(0)->global==true)
    fprintf(assemblyout,"push si\nmov si,ax\nmov bx,[%s+si]\npush bx\ndec bx\nmov [%s+si],bx\npop bx\npop si\npop ax\n",(yyvsp[-1].obj)->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"sub bp,ax\nmov bx,[bp]\npush bx\ndec bx\nmov [bp],bx\nadd bp,ax\npop bx\npop ax\n");
   }


}
#line 3772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 2124 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: argument_list : arguments\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");


}
#line 3789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 2137 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: argument_list :\n",line_count);
    (yyval.obj)=new complex_obj();
    fprintf(fout,"\n");

}
#line 3800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2147 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: arguments : arguments COMMA logic_expression\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[-2].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[-2].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[-2].obj)->vec->at(i)->getName().c_str());
    }
    (yyval.obj)->vec->push_back((yyvsp[-1].symbolinfo));
    fprintf(fout,"%s",(yyvsp[-1].symbolinfo)->getName().c_str());
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    args_type.push_back((yyvsp[0].obj)->return_type);
    fprintf(assemblyout,"push bx\n");
}
#line 3824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2167 "1805009.y" /* yacc.c:1646  */
    {
    fprintf(fout,"Line %d: arguments : logic_expression\n",line_count);
    (yyval.obj)=new complex_obj();
    for(int i=0; i<(yyvsp[0].obj)->vec->size(); i++)
    {
        (yyval.obj)->vec->push_back((yyvsp[0].obj)->vec->at(i));
        fprintf(fout,"%s",(yyvsp[0].obj)->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    args_type.push_back((yyvsp[0].obj)->return_type);
    fprintf(assemblyout,"push bx\n");
}
#line 3841 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3845 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 2182 "1805009.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
    FILE *fp;
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Cannot Open Input File.\n");
        exit(1);
    }

    fout= fopen("log.txt","w");
    errorout= fopen("error.txt","w");
    assemblyout=fopen("code.asm","w");


    yyin=fp;
    yyparse();
    if (err!=0)
    {
        fclose(assemblyout);
        assemblyout=fopen("code.asm","w");
    }
    

    fclose(fp);
    fclose(fout);
    fclose(errorout);
    fclose(assemblyout);
    optimize_code();

    return 0;
}
