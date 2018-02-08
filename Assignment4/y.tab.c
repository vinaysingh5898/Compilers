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
#line 1 "ass4_15CS30038.y" /* yacc.c:339  */
 
 	
	#include <string.h>
	#include <stdio.h>
	#include "ass4_15CS30038_translator.h"
	extern	int yylex();
	void yyerror(const char *s);
	extern type_e TYPE;
	extern int gDebug;


#line 78 "y.tab.c" /* yacc.c:339  */

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR = 258,
    SHORT = 259,
    INT = 260,
    LONG = 261,
    SIGNED = 262,
    UNSIGNED = 263,
    FLOAT = 264,
    DOUBLE = 265,
    VOID = 266,
    BOOL = 267,
    BREAK = 268,
    CASE = 269,
    CONTINUE = 270,
    DEFAULT = 271,
    DO = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    GOTO = 276,
    WHILE = 277,
    SWITCH = 278,
    RETURN = 279,
    MATRIX = 280,
    PLUS_ASSIGN = 281,
    MINUS_ASSIGN = 282,
    RIGHT_ASSIGN = 283,
    LEFT_ASSIGN = 284,
    MULTIPLY_ASSIGN = 285,
    PUNCTUATORS = 286,
    STRING_LITERAL = 287,
    IDENTIFIER = 288,
    INT_CONSTANT = 289,
    FLOAT_CONSTANT = 290,
    CHAR_CONSTANT = 291,
    MODULUS_ASSIGN = 292,
    AND_ASSIGN = 293,
    DIVIDE_ASSIGN = 294,
    XOR_ASSIGN = 295,
    POINTER_OP = 296,
    AND_OP = 297,
    OR_ASSIGN = 298,
    RIGHT_OP = 299,
    LEFT_OP = 300,
    INCREMENT_OP = 301,
    DECREMENT_OP = 302,
    EQ_OP = 303,
    NE_OP = 304,
    ZERO_CONSTANT = 305,
    POINTCOL = 306,
    OR_OP = 307,
    LE_OP = 308,
    GE_OP = 309
  };
#endif
/* Tokens.  */
#define CHAR 258
#define SHORT 259
#define INT 260
#define LONG 261
#define SIGNED 262
#define UNSIGNED 263
#define FLOAT 264
#define DOUBLE 265
#define VOID 266
#define BOOL 267
#define BREAK 268
#define CASE 269
#define CONTINUE 270
#define DEFAULT 271
#define DO 272
#define IF 273
#define ELSE 274
#define FOR 275
#define GOTO 276
#define WHILE 277
#define SWITCH 278
#define RETURN 279
#define MATRIX 280
#define PLUS_ASSIGN 281
#define MINUS_ASSIGN 282
#define RIGHT_ASSIGN 283
#define LEFT_ASSIGN 284
#define MULTIPLY_ASSIGN 285
#define PUNCTUATORS 286
#define STRING_LITERAL 287
#define IDENTIFIER 288
#define INT_CONSTANT 289
#define FLOAT_CONSTANT 290
#define CHAR_CONSTANT 291
#define MODULUS_ASSIGN 292
#define AND_ASSIGN 293
#define DIVIDE_ASSIGN 294
#define XOR_ASSIGN 295
#define POINTER_OP 296
#define AND_OP 297
#define OR_ASSIGN 298
#define RIGHT_OP 299
#define LEFT_OP 300
#define INCREMENT_OP 301
#define DECREMENT_OP 302
#define EQ_OP 303
#define NE_OP 304
#define ZERO_CONSTANT 305
#define POINTCOL 306
#define OR_OP 307
#define LE_OP 308
#define GE_OP 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "ass4_15CS30038.y" /* yacc.c:355  */

	int intvalue;
	int instr;
	sym* symt;
	expr* expAttr;
	char* strval;
	float floatvalue;
	lint* nl;
	statement* statm;
	unary* A;
	char uoptr;
	sym_type* stp;
		

#line 241 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   669

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  299

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    75,    58,     2,
      55,    56,    61,    59,    57,    60,    62,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    74,
      65,    68,    66,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    69,    73,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   108,   111,   117,   124,   137,   138,   154,
     158,   162,   166,   171,   175,   182,   184,   186,   188,   193,
     199,   200,   201,   206,   207,   224,   240,   253,   269,   277,
     280,   285,   333,   353,   354,   362,   374,   375,   387,   398,
     409,   426,   435,   439,   440,   454,   457,   468,   480,   484,
     485,   490,   503,   509,   523,   526,   534,   540,   558,   562,
     574,   580,   583,   584,   589,   590,   598,   609,   612,   616,
     622,   625,   631,   632,   639,   645,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   663,   664,   668,
     673,   676,   677,   695,   710,   723,   738,   749,   752,   759,
     764,   768,   773,   774,   779,   780,   781,   782,   788,   789,
     793,   796,   803,   804,   808,   809,   812,   816,   819,   822,
     828,   829,   830,   834,   844,   851,   858,   868,   871,   879,
     880,   886,   887,   896,   907,   910,   916,   917,   923,   932,
     940,   948,   960,   964,   965,   970,   971,   972,   979,   980,
     984,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   998,   999,  1005,  1006
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "SHORT", "INT", "LONG", "SIGNED",
  "UNSIGNED", "FLOAT", "DOUBLE", "VOID", "BOOL", "BREAK", "CASE",
  "CONTINUE", "DEFAULT", "DO", "IF", "ELSE", "FOR", "GOTO", "WHILE",
  "SWITCH", "RETURN", "MATRIX", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "MULTIPLY_ASSIGN", "PUNCTUATORS",
  "STRING_LITERAL", "IDENTIFIER", "INT_CONSTANT", "FLOAT_CONSTANT",
  "CHAR_CONSTANT", "MODULUS_ASSIGN", "AND_ASSIGN", "DIVIDE_ASSIGN",
  "XOR_ASSIGN", "POINTER_OP", "AND_OP", "OR_ASSIGN", "RIGHT_OP", "LEFT_OP",
  "INCREMENT_OP", "DECREMENT_OP", "EQ_OP", "NE_OP", "ZERO_CONSTANT",
  "POINTCOL", "OR_OP", "LE_OP", "GE_OP", "'('", "')'", "','", "'&'", "'+'",
  "'-'", "'*'", "'.'", "'['", "']'", "'<'", "'>'", "'^'", "'='", "'|'",
  "'?'", "':'", "'{'", "'}'", "';'", "'%'", "'/'", "$accept",
  "primary_expression", "equality_expression", "constant",
  "argument_expression_list", "unary_operator", "postfix_expression",
  "cast_expression", "unary_expression", "additive_expression",
  "relational_expression", "and_expression", "exclusive_or_expression",
  "init_declarator", "inclusive_or_expression", "declaration_specifiers",
  "logical_and_expression", "logical_or_expression", "N", "M",
  "conditional_expression", "assignment_expression", "initializer",
  "shift_expression", "expression", "constant_expression", "declaration",
  "init_declarator_list", "declarator", "assignment_operator",
  "parameter_list", "direct_declarator", "CST", "pointer",
  "parameter_type_list", "parameter_declaration", "identifier_list",
  "initializer_list", "designator_list", "function_definition",
  "designator", "statement", "labeled_statement",
  "multiplicative_expression", "block_item_list", "expression_statement",
  "selection_statement", "block_item", "compound_statement",
  "iteration_statement", "designation", "jump_statement",
  "external_declaration", "type_specifier", "translation_unit",
  "declaration_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    40,    41,    44,    38,    43,
      45,    42,    46,    91,    93,    60,    62,    94,    61,   124,
      63,    58,   123,   125,    59,    37,    47
};
# endif

#define YYPACT_NINF -201

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-201)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     644,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  -201,   -15,  -201,  -201,  -201,   644,   634,  -201,   -14,
     -23,  -201,  -201,   -20,   362,   -29,   -10,  -201,  -201,  -201,
     -26,  -201,   -14,  -201,   502,   -15,  -201,    -6,   644,    48,
     532,   -29,  -201,  -201,    19,  -201,  -201,  -201,  -201,  -201,
     572,   572,  -201,   572,  -201,  -201,  -201,  -201,   470,    36,
       9,  -201,   572,    51,  -201,   232,    55,    56,    71,    45,
      47,   103,   -41,  -201,  -201,  -201,    89,    -8,   231,  -201,
    -201,    -6,  -201,   440,    80,    86,    97,  -201,  -201,  -201,
      83,   132,   572,  -201,   -25,   -35,  -201,   502,   572,   572,
     572,  -201,  -201,   134,  -201,  -201,  -201,   565,   135,  -201,
    -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     127,   -31,   572,   572,   572,   572,   572,    98,   572,    99,
     100,  -201,   119,   122,   143,  -201,   123,   361,   108,  -201,
    -201,    -5,  -201,  -201,  -201,   109,  -201,  -201,  -201,  -201,
    -201,  -201,  -201,  -201,   -14,   124,   128,  -201,  -201,   150,
     130,   129,  -201,   572,  -201,  -201,   131,   428,  -201,  -201,
    -201,  -201,    54,    56,    56,  -201,  -201,    85,  -201,  -201,
    -201,    -8,    -8,    89,    89,    89,    89,     9,    71,    45,
    -201,  -201,  -201,    55,    55,  -201,  -201,  -201,  -201,   114,
    -201,   368,   368,   572,   421,   112,   136,   572,  -201,    33,
     368,  -201,  -201,   303,  -201,   644,  -201,  -201,  -201,   572,
    -201,  -201,  -201,  -201,   502,   133,  -201,   572,   572,   572,
     572,   368,  -201,  -201,   140,  -201,  -201,   572,    87,  -201,
    -201,  -201,  -201,   139,  -201,   572,  -201,    47,   103,   140,
    -201,   165,   148,   421,    91,   368,  -201,    60,   138,   144,
    -201,   149,  -201,  -201,  -201,  -201,   572,   368,  -201,   572,
     368,   572,    95,  -201,   368,   140,  -201,  -201,   137,   187,
    -201,   156,  -201,  -201,  -201,   368,   368,  -201,  -201
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   152,   150,   155,   151,   154,   157,   158,   156,   153,
     160,   159,     0,   149,   148,   161,    49,     0,    89,     0,
      97,    70,    72,     0,    45,    75,     0,    50,     1,   162,
       0,    98,     0,    71,     0,     0,   163,     0,    96,    96,
       0,    74,    90,    73,    45,     4,     2,     9,    11,    10,
       0,     0,    12,     0,    15,    16,    17,    18,     0,    19,
      42,     5,     0,    29,   123,    28,    64,     7,    43,    48,
      52,    54,    58,    60,    61,    46,    36,    33,     0,   111,
     164,     0,   102,     0,     0,     0,     0,    30,    32,    67,
       0,     0,     0,   104,     0,     0,   108,     0,     0,     0,
       0,    31,    28,     0,    24,    25,    27,     0,     0,    80,
      82,    83,    85,    79,    76,    86,    78,    81,    84,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,    56,     0,     0,     2,   136,
     129,     0,   135,   134,   114,    56,   116,   117,   127,   115,
     118,   119,   110,    94,   101,    99,     0,    87,    91,     0,
       0,     0,     3,     0,   113,    69,     0,     0,    62,   142,
     109,   105,     0,     8,     6,    23,    20,     0,    13,    21,
      59,    34,    35,    40,    38,    37,    39,    41,    44,    47,
      56,    56,    56,    66,    65,   124,   125,   126,   145,     0,
     143,     0,     0,     0,     0,     0,     0,     0,   147,     0,
       0,   130,   137,     0,   100,     0,    95,   103,    93,     0,
      68,   112,    63,   106,     0,     0,    22,     0,     0,     0,
       0,     0,   122,    56,    55,    56,   146,     0,     0,   144,
     120,   128,    88,     0,   107,     0,    14,    51,    53,    55,
     121,     0,     0,     0,     0,     0,    92,     0,     0,     0,
      56,    56,    56,   131,    26,    56,     0,     0,    56,     0,
       0,     0,     0,    55,     0,    55,   138,    57,     0,   132,
     139,     0,   140,    56,    56,     0,     0,   133,   141
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,    88,  -201,  -201,  -201,  -201,   -40,   -50,    23,
      58,    90,    84,   185,   -19,     8,   -18,  -201,   -69,  -140,
     -83,   -27,   -54,     2,   -47,    82,   -22,  -201,    -2,  -201,
    -201,   196,   121,   203,  -201,    -1,  -201,  -201,  -201,  -201,
     155,  -176,  -201,    42,  -201,  -200,  -201,     3,   -17,  -201,
      50,  -201,   208,  -201,  -201,  -201
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    59,    60,    61,   187,    62,    63,    64,    65,    66,
      67,    68,    69,    22,    70,    35,    71,    72,   130,   212,
      73,    89,    75,    76,   151,   176,    13,    23,    44,   120,
     165,    25,    37,    26,   166,   167,    84,    94,    95,    14,
      96,   153,   154,    77,   155,   156,   157,   158,   159,   160,
      97,   161,    15,    16,    17,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    88,    36,   131,    93,   216,    90,    74,    12,   175,
      24,   -55,   102,    86,   245,   223,    80,    30,    18,    18,
      79,   201,   101,    18,    27,    12,    39,    91,    92,   -55,
      42,    74,   177,   179,    40,   242,   243,    32,    20,   202,
      19,    19,   102,   181,   250,    19,    20,    20,   178,   102,
     102,   182,   173,   134,    33,   175,   152,    99,   100,    21,
     238,   239,   240,   271,   162,   260,    78,   135,   136,   221,
      74,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     188,    82,   102,   102,   102,   102,   102,    34,   102,   273,
     173,   164,   103,   190,   205,   206,   207,   104,   105,    98,
     219,   283,   106,   261,   286,   263,   107,   249,   290,   123,
     124,   173,   128,   108,   121,   122,   129,   173,   235,   297,
     298,   125,   126,   233,   274,   193,   194,   195,   196,   127,
     277,   279,   280,   132,   133,   281,   168,   169,   284,   172,
     173,   236,   237,   265,   173,   -55,   230,   272,   173,   170,
      74,   288,   173,   295,   296,   203,   204,   183,   184,    81,
      83,   171,   224,   191,   192,   174,   244,   185,   189,   200,
     248,   211,   208,   210,   213,   262,   215,   214,   217,   220,
     254,   225,   222,   227,   226,   241,   246,   269,   102,   102,
     268,   247,   229,   259,   228,   231,   255,   173,   287,   276,
     264,   152,   253,   266,   270,   278,   293,    74,   267,   275,
     256,   292,   294,   199,   289,   197,   291,    43,   198,   257,
     209,   258,    41,    31,   252,    29,   251,   234,     0,   282,
       0,   102,   285,   164,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,   137,   138,   139,   140,   141,   142,
     180,   143,   144,   145,   146,   147,    11,     0,   109,   110,
     111,   112,   113,    45,   148,    47,    48,    49,     0,   114,
     115,   116,   117,     0,     0,   118,     0,    50,    51,     0,
       0,    52,     0,     0,     0,     0,    53,     0,     0,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,    78,   149,   150,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,   146,   147,    11,     0,
       0,     0,     0,     0,     0,    45,   148,    47,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,     0,     0,    52,     0,     0,     0,     0,    53,     0,
       0,    54,    55,    56,    57,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    78,     0,   150,     0,     0,
       0,   137,   138,   139,   140,   141,   142,    11,   143,   144,
     145,   146,   147,    45,    46,    47,    48,    49,     0,     0,
      45,   148,    47,    48,    49,     0,     0,    50,    51,     0,
       0,    52,     0,     0,    50,    51,    53,     0,    52,    54,
      55,    56,    57,    53,     0,     0,    54,    55,    56,    57,
      34,     0,     0,     0,   -96,   218,     0,     0,     0,     0,
      78,     0,   150,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    45,    46,    47,    48,    49,     0,     0,
      45,    46,    47,    48,    49,    11,     0,    50,    51,     0,
       0,    52,     0,     0,    50,    51,    53,     0,    52,    54,
      55,    56,    57,    53,     0,     0,    54,    55,    56,    57,
      91,    92,     0,     0,     0,   150,   163,     0,     0,     0,
      58,   232,    45,    46,    47,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,     0,     0,
      52,     0,     0,     0,     0,    53,     0,     0,    54,    55,
      56,    57,    91,    92,    45,    46,    47,    48,    49,     0,
       0,     0,    58,     0,     0,     0,     0,     0,    50,    51,
       0,     0,    52,     0,     0,     0,     0,    53,     0,     0,
      54,    55,    56,    57,    45,    46,    47,    48,    49,     0,
       0,     0,     0,     0,    58,     0,     0,     0,    50,    51,
       0,     0,    52,     0,     0,     0,     0,    53,     0,     0,
      54,    55,    56,    57,     0,     0,    85,    45,    46,    47,
      48,    49,     0,     0,    45,    46,    47,    48,    49,     0,
       0,    50,    51,     0,     0,    52,     0,     0,    50,    51,
      53,   186,    52,    54,    55,    56,    57,    53,     0,     0,
      54,    55,    56,    57,    28,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11
};

static const yytype_int16 yycheck[] =
{
      50,    51,    24,    72,    58,   145,    53,    34,     0,    92,
      12,    52,    62,    40,   214,   155,    38,    19,    33,    33,
      37,    52,    62,    33,    16,    17,    55,    62,    63,    70,
      56,    58,    57,    68,    63,   211,   212,    57,    61,    70,
      55,    55,    92,    97,   220,    55,    61,    61,    73,    99,
     100,    98,    57,    61,    74,   138,    78,    48,    49,    74,
     200,   201,   202,   263,    81,   241,    72,    75,    76,    74,
      97,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     107,    33,   132,   133,   134,   135,   136,    68,   138,   265,
      57,    83,    41,   120,   134,   135,   136,    46,    47,    63,
     147,   277,    51,   243,   280,   245,    55,    74,   284,    53,
      54,    57,    67,    62,    59,    60,    69,    57,    64,   295,
     296,    65,    66,   177,    64,   123,   124,   125,   126,    58,
     270,   271,   272,    44,    45,   275,    56,    57,   278,    56,
      57,    56,    57,    56,    57,    42,   173,    56,    57,    63,
     177,    56,    57,   293,   294,   132,   133,    99,   100,    38,
      39,    64,   164,   121,   122,    33,   213,    33,    33,    42,
     217,    71,    74,    74,    55,   244,    33,    55,    55,    71,
     234,    57,    73,    33,    56,    71,    74,    22,   238,   239,
     259,    55,    63,   240,    64,    64,    63,    57,   281,    55,
     247,   223,   229,    64,    56,    56,    19,   234,   255,    71,
     237,    74,    56,   129,   283,   127,   285,    32,   128,   238,
     138,   239,    26,    20,   225,    17,   223,   177,    -1,   276,
      -1,   281,   279,   225,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      95,    20,    21,    22,    23,    24,    25,    -1,    26,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    -1,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    46,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    72,    73,    74,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    60,    61,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    72,    -1,    74,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    25,    20,    21,
      22,    23,    24,    32,    33,    34,    35,    36,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    46,    47,    -1,
      -1,    50,    -1,    -1,    46,    47,    55,    -1,    50,    58,
      59,    60,    61,    55,    -1,    -1,    58,    59,    60,    61,
      68,    -1,    -1,    -1,    72,    74,    -1,    -1,    -1,    -1,
      72,    -1,    74,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    32,    33,    34,    35,    36,    -1,    -1,
      32,    33,    34,    35,    36,    25,    -1,    46,    47,    -1,
      -1,    50,    -1,    -1,    46,    47,    55,    -1,    50,    58,
      59,    60,    61,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    74,    56,    -1,    -1,    -1,
      72,    73,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,
      60,    61,    62,    63,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    60,    61,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    46,    47,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    64,    32,    33,    34,
      35,    36,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    46,    47,    -1,    -1,    50,    -1,    -1,    46,    47,
      55,    56,    50,    58,    59,    60,    61,    55,    -1,    -1,
      58,    59,    60,    61,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    25,    92,   103,   116,   129,   130,   131,    33,    55,
      61,    74,    90,   104,   105,   108,   110,    92,     0,   129,
     105,   110,    57,    74,    68,    92,   103,   109,   132,    55,
      63,   108,    56,    90,   105,    32,    33,    34,    35,    36,
      46,    47,    50,    55,    58,    59,    60,    61,    72,    78,
      79,    80,    82,    83,    84,    85,    86,    87,    88,    89,
      91,    93,    94,    97,    98,    99,   100,   120,    72,   125,
     103,   109,    33,   109,   113,    64,    98,    85,    85,    98,
     101,    62,    63,    99,   114,   115,   117,   127,    63,    48,
      49,    84,    85,    41,    46,    47,    51,    55,    62,    26,
      27,    28,    29,    30,    37,    38,    39,    40,    43,    68,
     106,    59,    60,    53,    54,    65,    66,    58,    67,    69,
      95,    95,    44,    45,    61,    75,    76,    13,    14,    15,
      16,    17,    18,    20,    21,    22,    23,    24,    33,    73,
      74,   101,   103,   118,   119,   121,   122,   123,   124,   125,
     126,   128,   125,    56,    92,   107,   111,   112,    56,    57,
      63,    64,    56,    57,    33,    97,   102,    57,    73,    68,
     117,    99,   101,    87,    87,    33,    56,    81,    98,    33,
      98,   120,   120,   100,   100,   100,   100,    79,    88,    89,
      42,    52,    70,    86,    86,    84,    84,    84,    74,   102,
      74,    71,    96,    55,    55,    33,    96,    55,    74,   101,
      71,    74,    73,    96,   105,    57,    56,    33,    64,    63,
      98,    64,    73,    99,   127,    64,    56,    57,    96,    96,
      96,    71,   118,   118,   101,   122,    74,    55,   101,    74,
     118,   124,   112,    98,    99,    63,    98,    91,    93,   101,
     118,    96,    95,    96,   101,    56,    64,   101,    95,    22,
      56,   122,    56,   118,    64,    71,    55,    96,    56,    96,
      96,    96,   101,   118,    96,   101,   118,    97,    56,    95,
     118,    95,    74,    19,    56,    96,    96,   118,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    96,    97,    97,    98,
      98,    99,    99,    99,   100,   100,   100,   101,   101,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   109,   110,   110,   111,
     112,   112,   113,   113,   114,   114,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   126,   127,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   131,   131,   132,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     4,     3,     2,     2,     7,     2,     1,     1,
       2,     2,     2,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     1,     3,     3,     1,     1,
       2,     5,     1,     5,     1,     0,     0,     9,     1,     3,
       1,     1,     3,     4,     1,     3,     3,     1,     3,     1,
       2,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     4,     7,     5,     4,     5,     0,     1,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     1,     2,
       5,     4,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     1,     3,     3,     3,     1,     3,     1,
       2,     5,     8,    11,     1,     1,     2,     3,     7,     8,
       9,    11,     2,     2,     3,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2
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
#line 103 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = new expr();
		(yyval.expAttr)->symt = (yyvsp[0].symt);
		(yyval.expAttr)->isbool = false;
	}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = (yyvsp[-1].expAttr);
	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = new expr();
		(yyval.expAttr)->symt = gentemp(PTR, (yyvsp[0].strval));
		(yyval.expAttr)->symt->initialize((yyvsp[0].strval));
		(yyval.expAttr)->symt->type->ptr = new sym_type(_CHAR);
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = new expr();
		(yyval.expAttr)->symt = (yyvsp[0].symt);
	}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// If any is bool get its value
			con_from_bool ((yyvsp[0].expAttr));
			con_from_bool ((yyvsp[-2].expAttr));
			(yyval.expAttr) = new expr();string isexpr;
			(yyval.expAttr)->falselist = makelist (nextinstr()+1);
			(yyval.expAttr)->isbool = true;
			(yyval.expAttr)->truelist = makelist (nextinstr());
			emit (GOTOOP, "");
			emit (NEOP, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}else cout << "Type-Error"<< endl;
	}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 137 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 138 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// If any is bool get its value
			con_from_bool ((yyvsp[0].expAttr));
			con_from_bool ((yyvsp[-2].expAttr));
			(yyval.expAttr) = new expr();
			(yyval.expAttr)->falselist = makelist (nextinstr()+1);
			(yyval.expAttr)->truelist = makelist (nextinstr());
			(yyval.expAttr)->isbool = true;
			emit (GOTOOP, "");
			emit (EQOP, "", (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}else cout << "Type-Error"<< endl;
	}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 154 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = gentemp(_INT, num_to_string((yyvsp[0].intvalue)));
		emit(EQUAL, (yyval.symt)->name, (yyvsp[0].intvalue));
	}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 158 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = gentemp(_CHAR);
		emit(EQUAL, (yyval.symt)->name, "a");
	}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 162 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = gentemp(_DOUBLE, *new string ((yyvsp[0].strval)));
		emit(EQUAL, (yyval.symt)->name, *new string((yyvsp[0].strval)));
	}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	/* Ignored */
	}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 171 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		emit (PARAM, (yyvsp[0].expAttr)->symt->name);
		(yyval.intvalue) = 1;
	}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 175 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		emit (PARAM, (yyvsp[0].expAttr)->symt->name);
		(yyval.intvalue) = (yyvsp[-2].intvalue)+1;
	}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.uoptr) = '&';
	}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.uoptr) = '+';
	}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 186 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.uoptr) = '-';
	}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 188 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.uoptr) = '*';
	}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary ();
		(yyval.A)->symt = (yyvsp[0].expAttr)->symt;
		(yyval.A)->loc = (yyval.A)->symt;
		(yyval.A)->type = (yyvsp[0].expAttr)->symt->type;
	}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 201 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		(yyval.A)->symt = gentemp((yyvsp[-3].A)->type->cat);
		emit(CALL, (yyval.A)->symt->name, (yyvsp[-3].A)->symt->name, tostr((yyvsp[-1].intvalue)));
	}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 207 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		if((yyvsp[-1].A)->is_matrix){
			(yyval.A)->symt = gentemp(_DOUBLE);
			sym *vartemp = gentemp(_DOUBLE);
			emit(ARRR , vartemp->name , (yyvsp[-1].A)->symt->name , (yyvsp[-1].A)->loc->name);
			sym *tempvar1=gentemp(_DOUBLE);
			emit(EQUAL,(yyval.A)->symt->name,vartemp->name);
			sym *tempvar2=gentemp(_DOUBLE);
			emit (ADD, vartemp->name, vartemp->name, "1");	
			emit(ARRL , (yyvsp[-1].A)->symt->name,(yyvsp[-1].A)->loc->name,vartemp->name);
		}else{
		(yyval.A)->symt = gentemp((yyvsp[-1].A)->symt->type->cat);
		emit (EQUAL, (yyval.A)->symt->name, (yyvsp[-1].A)->symt->name);string unarys;
		emit (ADD, (yyvsp[-1].A)->symt->name, (yyvsp[-1].A)->symt->name, "1");
		}
	}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 224 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		if((yyvsp[-1].A)->is_matrix ){
			(yyval.A)->symt= gentemp(_DOUBLE);
			sym *vartemp = gentemp(_DOUBLE);
			emit(ARRR, vartemp->name , (yyvsp[-1].A)->symt->name , (yyvsp[-1].A)->loc->name);
			sym *tempvar1=gentemp(_DOUBLE);
			emit(EQUAL,(yyval.A)->symt->name,vartemp->name);string unarys;
			sym *tempvar2=gentemp(_DOUBLE);
			emit( SUB, vartemp->name , vartemp->name , "1");	
			emit(ARRL, (yyvsp[-1].A)->symt->name,(yyvsp[-1].A)->loc->name,vartemp->name);	
		}else
		{(yyval.A)->symt = gentemp((yyvsp[-1].A)->symt->type->cat);
		emit (EQUAL, (yyval.A)->symt->name, (yyvsp[-1].A)->symt->name);string unarys;
		emit (SUB, (yyvsp[-1].A)->symt->name, (yyvsp[-1].A)->symt->name, "1");}
	}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 240 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		(yyval.A)->symt = (yyvsp[-6].expAttr)->symt;
		(yyval.A)->is_matrix=true;
		sym* t = gentemp(_DOUBLE);
		emit(MULT,t->name,t->name,num_to_string((yyvsp[-6].expAttr)->symt->type->len));
		emit(MULT, t->name, (yyvsp[-4].expAttr)->symt->name, num_to_string(8));
		sym* temvar = gentemp(_DOUBLE);
 		emit(ADD, t->name, temvar->name, t->name);
    	emit(MULT,temvar->name, (yyvsp[-1].expAttr)->symt->name, num_to_string(8));
    	(yyval.A)->loc=gentemp(_DOUBLE);
 		emit (EQUAL, (yyval.A)->loc->name, t->name );
	}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 253 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
			(yyval.A)->symt = gentemp(_DOUBLE);
			sym *vartemp = gentemp(_DOUBLE);
			sym *tempvar1=gentemp(_DOUBLE);
			emit(ARRR, vartemp->name , (yyvsp[-1].A)->symt->name , (yyvsp[-1].A)->loc->name);
			emit(EQUAL,(yyval.A)->symt->name,vartemp->name);sym *tempvar2=gentemp(_DOUBLE);
			sym* tp = gentemp(_DOUBLE);
			emit(MULT,tp->name,num_to_string((yyvsp[-1].A)->symt->type->len),num_to_string((yyvsp[-1].A)->symt->type->width));
			emit(SUB,tp->name,tp->name,(yyvsp[-1].A)->loc->name);sym *tempvar3=gentemp(_DOUBLE);
			emit(ARRR,tp->name,(yyvsp[-1].A)->symt->name,tp->name);sym *tempvar4=gentemp(_DOUBLE);
			emit(ARRL,(yyvsp[-1].A)->symt->name,(yyvsp[-1].A)->loc->name,tp->name);
	}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 269 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[0].A);
	}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 277 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[0].A);
	}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 280 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		// Increment value $1
		emit (ADD, (yyvsp[0].A)->symt->name, (yyvsp[0].A)->symt->name, "1");
		(yyval.A) = (yyvsp[0].A);
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 285 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		
		if((yyvsp[-1].uoptr)=='&'){
			if((yyvsp[0].A)->is_matrix){
					(yyval.A)->symt = gentemp(PTR);
					(yyval.A)->symt->type->ptr = (yyvsp[0].A)->symt->type;
					sym* temp = gentemp(_DOUBLE);
					emit(ARRR, temp->name , (yyvsp[0].A)->symt->name , (yyvsp[0].A)->loc->name);
					emit (ADDRESS, (yyval.A)->symt->name, temp->name);
				}else{
				(yyval.A)->symt = gentemp(PTR);
				(yyval.A)->symt->type->ptr = (yyvsp[0].A)->symt->type; 
				emit (ADDRESS, (yyval.A)->symt->name, (yyvsp[0].A)->symt->name);}

		}else if((yyvsp[-1].uoptr)=='*'){
				if((yyvsp[0].A)->is_matrix){
						(yyval.A)->symt = gentemp(_DOUBLE);
						(yyval.A)->symt->type->ptr = (yyvsp[0].A)->symt->type;
						sym* temp = gentemp(_DOUBLE);
						emit(ARRR, temp->name , (yyvsp[0].A)->symt->name , (yyvsp[0].A)->loc->name);
						emit (PTRR, (yyval.A)->symt->name, temp->name);
					//offset++;
						break;
					}else{
				(yyval.A)->cat = PTR;
				(yyval.A)->loc = gentemp ((yyvsp[0].A)->symt->type->ptr);
				emit (PTRR, (yyval.A)->loc->name, (yyvsp[0].A)->symt->name);
				(yyval.A)->symt = (yyvsp[0].A)->symt;	}

		}else if((yyvsp[-1].uoptr)=='+'){
				if((yyvsp[0].A)->is_matrix){
					(yyval.A)->symt = gentemp(_DOUBLE);
					emit(ARRR, (yyval.A)->symt->name , (yyvsp[0].A)->symt->name , (yyvsp[0].A)->loc->name);	
				}else{
					(yyval.A) = (yyvsp[0].A);	}
		
		}else if((yyvsp[-1].uoptr)=='-'){
				if((yyvsp[0].A)->is_matrix){
					sym* temp = gentemp(_DOUBLE);
					(yyval.A)->symt = gentemp(_DOUBLE);
					emit(ARRR, temp->name , (yyvsp[0].A)->symt->name , (yyvsp[0].A)->loc->name);
					emit (UMINUS, (yyval.A)->symt->name, temp->name);
				}else{
					(yyval.A)->symt = gentemp((yyvsp[0].A)->symt->type->cat);
					emit (UMINUS, (yyval.A)->symt->name, (yyvsp[0].A)->symt->name);	}
		}
	}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 333 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].A)->is_matrix){
			(yyval.A) = new unary();
			(yyval.A)->symt = gentemp(_DOUBLE);
			emit(ARRR, (yyval.A)->symt->name , (yyvsp[0].A)->symt->name , (yyvsp[0].A)->loc->name);
			emit( SUB, (yyval.A)->symt->name , (yyval.A)->symt->name , "1");	
			emit(ARRL, (yyvsp[0].A)->symt->name , (yyvsp[0].A)->loc->name  , (yyval.A)->symt->name);
		}else{

		// Decrement $1
		emit (SUB, (yyvsp[0].A)->symt->name, (yyvsp[0].A)->symt->name, "1");

		// Use the same value
		(yyval.A) = (yyvsp[0].A);}
	}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 353 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 354 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt)) {
			(yyval.expAttr) = new expr();string generatemp;
			(yyval.expAttr)->symt = gentemp((yyvsp[-2].expAttr)->symt->type->cat);
			emit (ADD, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 362 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt)) {
			(yyval.expAttr) = new expr();string generatemp;
			(yyval.expAttr)->symt = gentemp((yyvsp[-2].expAttr)->symt->type->cat);
			emit (SUB, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 374 "ass4_15CS30038.y" /* yacc.c:1646  */
    { (yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 375 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// New bool
			(yyval.expAttr) = new expr();
			(yyval.expAttr)->isbool = true;bool checkbool;
			(yyval.expAttr)->falselist = makelist(nextinstr()+1);
			(yyval.expAttr)->truelist = makelist(nextinstr());
			emit (GOTOOP, "");
			emit(LT, "", (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 387 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			(yyval.expAttr) = new expr();bool ifbool;
			string falselistk;(yyval.expAttr)->isbool = true;
			(yyval.expAttr)->falselist = makelist (nextinstr()+1);
			(yyval.expAttr)->truelist = makelist (nextinstr());
			emit (GOTOOP, "");
			emit(LE, "", (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 398 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// New bool
			(yyval.expAttr) = new expr();(yyval.expAttr)->isbool = true;
			(yyval.expAttr)->falselist = makelist (nextinstr()+1);
			(yyval.expAttr)->truelist = makelist (nextinstr());
			emit (GOTOOP, "");
			emit(GT, "", (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 409 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// New bool
			(yyval.expAttr) = new expr();(yyval.expAttr)->isbool = true;
			(yyval.expAttr)->falselist = makelist (nextinstr()+1);
			(yyval.expAttr)->truelist = makelist (nextinstr()); 
			emit (GOTOOP, "");
			emit(LE, "", (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			(yyval.expAttr) = new expr();
			(yyval.expAttr)->isbool = false;
			int ifbool;
			(yyval.expAttr)->symt = gentemp (_INT);
			emit (BAND, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}else cout << "Type Error"<< endl;
	}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 435 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 439 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 440 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// If any is bool get its value
			con_from_bool ((yyvsp[0].expAttr));
			con_from_bool ((yyvsp[-2].expAttr));
			(yyval.expAttr) = new expr();
			(yyval.expAttr)->symt = gentemp (_INT);
			(yyval.expAttr)->isbool = false;
			emit (XOR, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}else cout << "Type Error"<< endl;
	}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 454 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = (yyvsp[0].symt);
	}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 457 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		debug ((yyvsp[-2].symt)->name);
		debug ((yyvsp[0].symt)->name);
		debug ((yyvsp[0].symt)->init);
		debug ("here init");
		if ((yyvsp[0].symt)->init!="") (yyvsp[-2].symt)->initialize((yyvsp[0].symt)->init);
		emit (EQUAL, (yyvsp[-2].symt)->name, (yyvsp[0].symt)->name);
	}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 468 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].expAttr)->symt) ) {
			// If any is bool get its value
			con_from_bool ((yyvsp[-2].expAttr));
			con_from_bool ((yyvsp[0].expAttr));
			(yyval.expAttr) = new expr();string backpat;
			(yyval.expAttr)->isbool = false;
			(yyval.expAttr)->symt = gentemp (_INT);
			emit (INOR, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type Error"<< endl;
	}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 480 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 486 "ass4_15CS30038.y" /* yacc.c:1646  */
    {printf("declaration_specifiers\n");}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 490 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		con_to_bool((yyvsp[0].expAttr));

		// N to convert $1 to bool
		backpatch((yyvsp[-3].expAttr)->nextlist, nextinstr());
		con_to_bool((yyvsp[-4].expAttr));

		(yyval.expAttr) = new expr();
		(yyval.expAttr)->isbool = true;string backpat;
		backpatch((yyvsp[-4].expAttr)->truelist, (yyvsp[-1].instr));
		(yyval.expAttr)->truelist = (yyvsp[0].expAttr)->truelist;
		(yyval.expAttr)->falselist = merge ((yyvsp[-4].expAttr)->falselist, (yyvsp[0].expAttr)->falselist);
	}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 503 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 509 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		con_to_bool((yyvsp[0].expAttr));

		// N to convert $1 to bool
		backpatch((yyvsp[-3].expAttr)->nextlist, nextinstr());
		con_to_bool((yyvsp[-4].expAttr));

		(yyval.expAttr) = new expr();
		(yyval.expAttr)->isbool = true;

		backpatch ((yyval.expAttr)->falselist, (yyvsp[-1].instr));
		(yyval.expAttr)->falselist = (yyvsp[0].expAttr)->falselist;
		(yyval.expAttr)->truelist = merge ((yyvsp[-4].expAttr)->truelist, (yyvsp[0].expAttr)->truelist);
	}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 523 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 526 "ass4_15CS30038.y" /* yacc.c:1646  */
    { 	// Non terminal to prevent fallthrough by emitting a goto
		debug ("n");
		(yyval.expAttr)  = new expr();
		(yyval.expAttr)->nextlist = makelist(nextinstr());
		emit (GOTOOP,"");
		debug ("n2");
	}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 534 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	// To store the address of the next instruction for further use.
		(yyval.instr) = nextinstr();
	}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 540 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr)->symt->update((yyvsp[-4].expAttr)->symt->type);
		(yyval.expAttr)->symt = gentemp();
		emit(EQUAL, (yyval.expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		emit (GOTOOP, "");
		lint l = makelist(nextinstr());

		backpatch((yyvsp[-3].expAttr)->nextlist, nextinstr());
		lint m = makelist(nextinstr());
		emit (GOTOOP, "");
		emit(EQUAL, (yyval.expAttr)->symt->name, (yyvsp[-4].expAttr)->symt->name);
		l = merge (l, m);
		backpatch((yyvsp[-7].expAttr)->nextlist, nextinstr());string con_bool;
		con_to_bool ((yyvsp[-8].expAttr));
		backpatch (l, nextinstr());
		backpatch ((yyvsp[-8].expAttr)->falselist, (yyvsp[-1].instr));
		backpatch ((yyvsp[-8].expAttr)->truelist, (yyvsp[-5].instr));
	}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 558 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 562 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].A)->cat==ARR){
				(yyvsp[0].expAttr)->symt = conv((yyvsp[0].expAttr)->symt, (yyvsp[-2].A)->type->cat);
				emit(ARRL, (yyvsp[-2].A)->symt->name, (yyvsp[-2].A)->loc->name, (yyvsp[0].expAttr)->symt->name);
		}else if((yyvsp[-2].A)->cat==PTR){
			emit(PTRL, (yyvsp[-2].A)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}else {
			(yyvsp[0].expAttr)->symt = conv((yyvsp[0].expAttr)->symt, (yyvsp[-2].A)->symt->type->cat);
			emit(EQUAL, (yyvsp[-2].A)->symt->name, (yyvsp[0].expAttr)->symt->name);
			}
		(yyval.expAttr) = (yyvsp[0].expAttr);
	}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 574 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = (yyvsp[0].expAttr);
	}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 580 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = (yyvsp[0].expAttr)->symt;
	}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 583 "ass4_15CS30038.y" /* yacc.c:1646  */
    {}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 585 "ass4_15CS30038.y" /* yacc.c:1646  */
    {printf("initializer\n");}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 589 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.expAttr) = (yyvsp[0].expAttr);}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 590 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].expAttr)->symt->type->cat == _INT) {
			(yyval.expAttr) = new expr();
			(yyval.expAttr)->symt = gentemp (_INT);
			emit (LEFTOP, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 598 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].expAttr)->symt->type->cat == _INT) {
			(yyval.expAttr) = new expr();
			(yyval.expAttr)->symt = gentemp (_INT);
			emit (RIGHTOP, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].expAttr)->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 609 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = (yyvsp[0].expAttr);
	}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 617 "ass4_15CS30038.y" /* yacc.c:1646  */
    {printf("constant_expression\n");}
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 622 "ass4_15CS30038.y" /* yacc.c:1646  */
    {

	}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 625 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		debug ("declaration");
	}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 632 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		debug("init_declarator_list");
	}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 639 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		sym_type * t = (yyvsp[-1].stp);
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = (yyvsp[0].symt)->type;
		(yyval.symt) = (yyvsp[0].symt)->update((yyvsp[-1].stp));
	}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 668 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = (yyvsp[0].symt)->update(TYPE);
		debug ("currsym: "<< (yyval.symt)->name);
		currsym = (yyval.symt);
	}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 673 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.symt) = (yyvsp[-1].symt);
	}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 676 "ass4_15CS30038.y" /* yacc.c:1646  */
    { /* Ignored */}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 677 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		sym_type * t = (yyvsp[-6].symt) -> type;string assignexp;
		sym_type * prev = NULL;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}if (prev==NULL) {
			int x = atoi((yyvsp[-4].expAttr)->symt->init.c_str());
			int y= atoi((yyvsp[-1].expAttr)->symt->init.c_str());
			sym_type* s = new sym_type(ARR, (yyvsp[-6].symt)->type, x,y);
			y = size_type(s);
			(yyval.symt) = (yyvsp[-6].symt)->update(s);
		}
		else {
			prev->ptr =  new sym_type(ARR, t, atoi((yyvsp[-4].expAttr)->symt->init.c_str()),atoi((yyvsp[-1].expAttr)->symt->init.c_str()));
			(yyval.symt) = (yyvsp[-6].symt)->update ((yyvsp[-6].symt)->type);
		}
	}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 695 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		sym_type * prev = NULL;
		sym_type * t = (yyvsp[-4].symt) -> type;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}if (prev==NULL) {
			sym_type* s = new sym_type(ARR, (yyvsp[-4].symt)->type, 0);
			(yyval.symt) = (yyvsp[-4].symt)->update(s);
			int y = size_type(s);
		}else {
			prev->ptr =  new sym_type(ARR, t, 0);
			(yyval.symt) = (yyvsp[-4].symt)->update ((yyvsp[-4].symt)->type);
		}
	}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 710 "ass4_15CS30038.y" /* yacc.c:1646  */
    {		
		table->tname = (yyvsp[-3].symt)->name;		
		if ((yyvsp[-3].symt)->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");// Update type of return value
			s->update((yyvsp[-3].symt)->type);
		}
		(yyvsp[-3].symt) = (yyvsp[-3].symt)->linkst(table);		// Update type of function in global table
		int r=0;
		table->parent = gTable;
		changeTable (gTable,r);				
		currsym = (yyval.symt);
		debug ("currsym: "<< (yyval.symt)->name);
	}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 723 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		table->tname = (yyvsp[-4].symt)->name;
		if ((yyvsp[-4].symt)->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");
			s->update((yyvsp[-4].symt)->type);		
		}
		(yyvsp[-4].symt) = (yyvsp[-4].symt)->linkst(table);
		int r=0;
		table->parent = gTable;
		changeTable (gTable,r);			
		currsym = (yyval.symt);						
		debug ("currsym: "<< (yyval.symt)->name);
	}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 738 "ass4_15CS30038.y" /* yacc.c:1646  */
    { // Used for changing to symbol table for a function
		int r=0;
		if (currsym->nest==NULL) changeTable(new sym_table(""),r);	
		else {
			changeTable (currsym ->nest,r);				
			emit (LABEL, table->tname);
		}
	}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 749 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.stp) = new sym_type(PTR);
	}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 752 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.stp) = new sym_type(PTR, (yyvsp[0].stp));
	}
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 764 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		debug ("here");
		(yyvsp[0].symt)->category = "param";
	}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 769 "ass4_15CS30038.y" /* yacc.c:1646  */
    {printf("parameter_declaration\n");}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 775 "ass4_15CS30038.y" /* yacc.c:1646  */
    {printf("identifier_list\n");}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 783 "ass4_15CS30038.y" /* yacc.c:1646  */
    {printf("initializer_list\n");}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 793 "ass4_15CS30038.y" /* yacc.c:1646  */
    {

	}
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 796 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		int declrs=0;table->parent = gTable;
		changeTable (gTable,declrs);
	}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 809 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);
	}
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 812 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = new statement();
		(yyval.statm)->nextlist = (yyvsp[0].expAttr)->nextlist;
	}
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 816 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);
	}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 819 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);
	}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 822 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);
	}
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 828 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.statm) = new statement();}
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 829 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.statm) = new statement();}
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 830 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.statm) = new statement();}
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 834 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = new expr();
		if ((yyvsp[0].A)->cat==ARR) { 
			string generatemp;(yyval.expAttr)->symt = gentemp((yyvsp[0].A)->loc->type);
			emit(ARRR, (yyval.expAttr)->symt->name, (yyvsp[0].A)->symt->name, (yyvsp[0].A)->loc->name);
		}else if ((yyvsp[0].A)->cat == PTR) { // Pointer
				(yyval.expAttr)->symt = (yyvsp[0].A)->loc;
		}else { (yyval.expAttr)->symt = (yyvsp[0].A)->symt;
		}
	}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 844 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].A)->symt) ) {
			string generatemp;(yyval.expAttr) = new expr();
			(yyval.expAttr)->symt = gentemp((yyvsp[-2].expAttr)->symt->type->cat);
			emit (MULT, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].A)->symt->name);
		}else cout << "Type-Errors"<< endl;
	}
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 851 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].A)->symt) ) {
			string generatemp;(yyval.expAttr) = new expr();
			(yyval.expAttr)->symt = gentemp((yyvsp[-2].expAttr)->symt->type->cat);
			emit (MODOP, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].A)->symt->name);
		}else cout << "Type-Errors"<< endl;
	}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 858 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].expAttr)->symt, (yyvsp[0].A)->symt) ) {
			string generatemp;(yyval.expAttr) = new expr();
			(yyval.expAttr)->symt = gentemp((yyvsp[-2].expAttr)->symt->type->cat);
			emit (DIVIDE, (yyval.expAttr)->symt->name, (yyvsp[-2].expAttr)->symt->name, (yyvsp[0].A)->symt->name);
		}else cout << "Type-Errors"<< endl;
	}
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 868 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);		
	}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 871 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);
		backpatch ((yyvsp[-2].statm)->nextlist, (yyvsp[-1].instr));
	}
#line 2715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 879 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	(yyval.expAttr) = new expr();}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 880 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.expAttr) = (yyvsp[-1].expAttr);
	}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 886 "ass4_15CS30038.y" /* yacc.c:1646  */
    {}
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 887 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		backpatch ((yyvsp[-4].expAttr)->nextlist, nextinstr());
		con_to_bool((yyvsp[-5].expAttr));string con_bool;
		(yyval.statm) = new statement();
		backpatch ((yyvsp[-5].expAttr)->truelist, (yyvsp[-2].instr));
		lint temp = merge ((yyvsp[-5].expAttr)->falselist, (yyvsp[-1].statm)->nextlist);
		(yyval.statm)->nextlist = merge ((yyvsp[0].expAttr)->nextlist, temp);
		
	}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 896 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		backpatch ((yyvsp[-7].expAttr)->nextlist, nextinstr());string con_bool;
		con_to_bool((yyvsp[-8].expAttr));
		backpatch ((yyvsp[-8].expAttr)->falselist, (yyvsp[-1].instr));
		backpatch ((yyvsp[-8].expAttr)->truelist, (yyvsp[-5].instr));
		lint temp = merge ((yyvsp[-4].statm)->nextlist, (yyvsp[-3].expAttr)->nextlist);
		(yyval.statm)->nextlist = merge (temp, (yyvsp[0].statm)->nextlist);
	}
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 907 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[0].statm);
	}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 910 "ass4_15CS30038.y" /* yacc.c:1646  */
    { 
		(yyval.statm) = new statement();
	}
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 916 "ass4_15CS30038.y" /* yacc.c:1646  */
    { (yyval.statm) = new statement();}
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 917 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = (yyvsp[-1].statm);
	}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 923 "ass4_15CS30038.y" /* yacc.c:1646  */
    { 
		(yyval.statm) = new statement();
		con_to_bool((yyvsp[-3].expAttr));
		backpatch((yyvsp[-3].expAttr)->truelist, (yyvsp[-1].instr));
		(yyval.statm)->nextlist = (yyvsp[-3].expAttr)->falselist;
		backpatch((yyvsp[0].statm)->nextlist, (yyvsp[-5].instr));
		// Emit to prevent fallthrough
		emit (GOTOOP, tostr((yyvsp[-5].instr)));
	}
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 932 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = new statement();
		con_to_bool((yyvsp[-3].expAttr));
		backpatch ((yyvsp[-3].expAttr)->truelist, (yyvsp[-1].instr));
		backpatch ((yyvsp[0].statm)->nextlist, (yyvsp[-4].instr));
		emit (GOTOOP, tostr((yyvsp[-4].instr)));
		(yyval.statm)->nextlist = (yyvsp[-3].expAttr)->falselist;
	}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 940 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = new statement();
		con_to_bool((yyvsp[-2].expAttr));
		backpatch ((yyvsp[-2].expAttr)->truelist, (yyvsp[-7].instr));
		backpatch ((yyvsp[-6].statm)->nextlist, (yyvsp[-5].instr));
		(yyval.statm)->nextlist = (yyvsp[-2].expAttr)->falselist;

	}
#line 2832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 948 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = new statement();
		con_to_bool((yyvsp[-6].expAttr));
		backpatch ((yyvsp[-6].expAttr)->truelist, (yyvsp[-1].instr));
		backpatch ((yyvsp[-3].expAttr)->nextlist, (yyvsp[-7].instr));
		backpatch ((yyvsp[0].statm)->nextlist, (yyvsp[-5].instr));
		emit (GOTOOP, tostr((yyvsp[-5].instr)));
		(yyval.statm)->nextlist = (yyvsp[-6].expAttr)->falselist;
	}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 964 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.statm) = new statement();}
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 965 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = new statement();
			emit(_RETURN,(yyvsp[-1].expAttr)->symt->name);			

	}
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 970 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.statm) = new statement();}
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 971 "ass4_15CS30038.y" /* yacc.c:1646  */
    {(yyval.statm) = new statement();}
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 972 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
		(yyval.statm) = new statement();
		emit(_RETURN,"");
	}
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 986 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	TYPE = _CHAR;	}
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 987 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	TYPE = _VOID;	}
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 989 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	TYPE = _INT;	}
#line 2901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 990 "ass4_15CS30038.y" /* yacc.c:1646  */
    {	TYPE = _DOUBLE;	}
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 999 "ass4_15CS30038.y" /* yacc.c:1646  */
    {
	}
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2918 "y.tab.c" /* yacc.c:1646  */
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
#line 1009 "ass4_15CS30038.y" /* yacc.c:1906  */


void yyerror(const char *s) {
	printf ("ERROR: %s",s);
}
