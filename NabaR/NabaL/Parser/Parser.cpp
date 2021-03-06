/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"

#define YY_NO_UNISTD_H 1
#define YYERROR_VERBOSE 1



#include "Ast/Block.h"
#include "Ast/Identifier.h"
#include "Ast/Struct.h"
#include "Ast/StructVariable.h"
#include "Ast/ExpressionStatement.h"
#include "Ast/Function.h"
#include "Ast/FunctionParameter.h"
#include "Ast/Integer32.h"
#include "Ast/Integer64.h"
#include "Ast/Double.h"
#include "Ast/VariableDeclaration.h"
#include "Ast/MethodCall.h"
#include "Ast/Assignment.h"
#include "Ast/While.h"
#include "Ast/For.h"

#include "Ast/BinaryOperator.h"
#include "Tk/SharedPtr.h"
#include "Ast/Node.h"
#include "CompileError.h"

#include "Parser/Parser.hpp"
#include "Parser/Tokens.h"


extern void 
    ReportError(
        YYLTYPE* location,
        const filesystem::path& pathFile, 
        Tk::Sp<const Naba::Lng::CCompileError>& errorOut, 
        Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope,
        const char* msg
        );

int yyerror (
    YYLTYPE* location,
    yyscan_t scanner, 
    const filesystem::path& pathFile, 
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut, 
    Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope,
    const char* msg
    )
{
    ReportError( location, pathFile, errorOut, fileScope, msg );
    return 0;
}



/* Line 371 of yacc.c  */
#line 124 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "Parser.hpp".  */
#ifndef YY_YY_C_DEV_NABAX_NABAR_NABAL_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_C_DEV_NABAX_NABAR_NABAL_PARSER_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 57 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"


#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif



/* Line 387 of yacc.c  */
#line 166 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENTIFIER = 258,
     T_I32 = 259,
     T_I64 = 260,
     TDOUBLE = 261,
     TSTRUCT = 262,
     TCEQ = 263,
     TCNE = 264,
     TCLT = 265,
     TCLE = 266,
     TCGT = 267,
     TCGE = 268,
     TEQUAL = 269,
     TWHILE = 270,
     TFOR = 271,
     TVAR = 272,
     TLPAREN = 273,
     TRPAREN = 274,
     TLBRACE = 275,
     TRBRACE = 276,
     TCOMMA = 277,
     TDOT = 278,
     TPLUS = 279,
     TMINUS = 280,
     TMUL = 281,
     TDIV = 282,
     TSEMICOLON = 283,
     TCOLON = 284
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 75 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"

    Naba::Lng::Ast::CBlock* block;
    Naba::Lng::Ast::CBlock* blockParts;
    Naba::Lng::Ast::CExpression* expr;
    Naba::Lng::Ast::CBlockPart* blockPart;
    Naba::Lng::Ast::CIdentifier* ident;
    Naba::Lng::Ast::CVariableDeclaration* var_decl;
    Naba::Lng::Ast::CFunctionParameter* func_param;
    Tk::SpList<const Naba::Lng::Ast::CVariableDeclaration>* varvec;
    Tk::SpList<const Naba::Lng::Ast::CFunctionParameter>* funcParList;
    Tk::SpList<const Naba::Lng::Ast::CExpression>* exprvec;
    StringToken* stringToken;
    int token;

    Naba::Lng::Ast::CStructPart*     structPart;
    Tk::SpList<const Naba::Lng::Ast::CStructPart>* structParts;


/* Line 387 of yacc.c  */
#line 229 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (yyscan_t scanner, const filesystem::path& pathFile, Tk::Sp<const Naba::Lng::CCompileError>& errorOut, Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_C_DEV_NABAX_NABAR_NABAL_PARSER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 269 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    29,    33,    36,    43,    49,    55,
      64,    72,    83,    87,    93,    95,    98,   105,   106,   108,
     112,   115,   120,   126,   133,   135,   137,   139,   141,   146,
     148,   150,   152,   156,   160,   165,   166,   168,   172,   174,
     176,   178,   180,   182,   184,   186,   188,   190
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    32,    -1,    33,    -1,    32,    33,    -1,
      44,    -1,    41,    -1,    36,    -1,    34,    -1,    47,    -1,
      35,    -1,    37,    -1,    38,    -1,    48,    28,    -1,    20,
      32,    21,    -1,    20,    21,    -1,     7,    45,    20,    40,
      21,    28,    -1,     7,    45,    20,    21,    28,    -1,    15,
      18,    48,    19,    35,    -1,    17,    45,    14,    15,    18,
      48,    19,    35,    -1,    16,    18,    45,    29,    48,    19,
      35,    -1,    17,    45,    14,    16,    18,    45,    29,    48,
      19,    35,    -1,    45,    45,    28,    -1,    45,    45,    14,
      48,    28,    -1,    39,    -1,    40,    39,    -1,    45,    45,
      18,    42,    19,    35,    -1,    -1,    43,    -1,    42,    22,
      43,    -1,    45,    45,    -1,    17,    45,    45,    28,    -1,
      17,    45,    14,    48,    28,    -1,    17,    45,    45,    14,
      48,    28,    -1,     3,    -1,     5,    -1,     4,    -1,     6,
      -1,    45,    14,    48,    28,    -1,    49,    -1,    45,    -1,
      46,    -1,    48,    51,    48,    -1,    18,    48,    19,    -1,
      45,    18,    50,    19,    -1,    -1,    48,    -1,    50,    22,
      48,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   123,   123,   127,   128,   132,   133,   134,   135,   136,
     137,   138,   139,   143,   146,   147,   151,   152,   156,   157,
     160,   161,   164,   165,   169,   170,   174,   178,   179,   180,
     184,   188,   189,   190,   194,   198,   199,   200,   204,   209,
     210,   211,   212,   213,   220,   223,   224,   225,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "T_I32", "T_I64",
  "TDOUBLE", "TSTRUCT", "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE",
  "TEQUAL", "TWHILE", "TFOR", "TVAR", "TLPAREN", "TRPAREN", "TLBRACE",
  "TRBRACE", "TCOMMA", "TDOT", "TPLUS", "TMINUS", "TMUL", "TDIV",
  "TSEMICOLON", "TCOLON", "$accept", "fileScope", "blockParts",
  "blockPart", "exprStatement", "block", "struct", "while", "for",
  "structPart", "structParts", "func_decl", "func_decl_args", "func_param",
  "var_decl", "ident", "numeric", "assignment", "expr", "functionCall",
  "call_args", "binaryOperation", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    35,    35,    36,    36,    37,    37,
      38,    38,    39,    39,    40,    40,    41,    42,    42,    42,
      43,    44,    44,    44,    45,    46,    46,    46,    47,    48,
      48,    48,    48,    48,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     6,     5,     5,     8,
       7,    10,     3,     5,     1,     2,     6,     0,     1,     3,
       2,     4,     5,     6,     1,     1,     1,     1,     4,     1,
       1,     1,     3,     3,     4,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    36,    35,    37,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     8,    10,     7,    11,    12,     6,
       5,    40,    41,     9,     0,    39,     0,     0,     0,     0,
      40,     0,    15,     0,     1,     4,     0,    45,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    13,
       0,     0,     0,     0,     0,     0,    43,    14,     0,    46,
       0,    27,    42,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    38,    44,     0,     0,    28,     0,
      17,     0,    25,     0,    18,     0,     0,     0,    32,     0,
      47,     0,     0,    30,    16,     0,    22,     0,     0,     0,
      33,    26,    29,     0,    20,     0,     0,    23,    19,     0,
       0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    64,
      65,    19,    77,    78,    20,    30,    22,    23,    24,    25,
      60,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
     293,   -63,   -63,   -63,   -63,     1,   -12,    -4,     1,    52,
     267,    17,   293,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,    16,   -63,   -63,    90,   -63,    13,    52,     1,     7,
      24,   154,   -63,   286,   -63,   -63,    52,    52,    28,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
      52,    -1,   174,   -13,    34,    -5,   -63,   -63,    96,   254,
      25,     1,   254,    23,   -63,     4,     1,    33,    52,    42,
      48,   117,    52,   -63,   -63,   -63,    52,    43,   -63,     1,
     -63,    44,   -63,    -2,   -63,   194,    52,     1,   -63,   123,
     254,    33,     1,   -63,   -63,    52,   -63,    33,   214,    32,
     -63,   -63,   -63,   144,   -63,    33,    52,   -63,   -63,   234,
      33,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,    61,   -11,   -63,   -62,   -63,   -63,   -63,     8,
     -63,   -63,   -63,   -18,   -63,     3,   -63,   -63,    -9,   -63,
     -63,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    35,     1,    21,     1,    84,    27,     1,    26,    72,
       1,    29,    95,    21,    28,    21,    68,    34,    52,     1,
      63,    54,    35,    73,    38,    81,    96,    58,    59,   101,
      36,    53,    55,    51,    37,   104,    21,     1,     2,     3,
       4,    62,    37,   108,    75,    71,    61,    76,   111,    69,
      70,    80,     9,    10,    66,     1,     2,     3,     4,    85,
      86,   106,    91,    89,    79,    92,    87,    90,    66,    83,
       9,    33,    94,    82,   102,     0,     0,    98,     0,     0,
       0,     0,    93,     0,     0,     0,   103,     0,     0,     0,
      99,     0,     0,     0,     0,    79,     0,   109,    39,    40,
      41,    42,    43,    44,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,    45,    46,    47,    48,    49,     0,
      45,    46,    47,    48,    74,    39,    40,    41,    42,    43,
      44,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,    45,    46,    47,    48,    88,     0,    45,    46,    47,
      48,   100,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   107,    56,     0,     0,     0,     0,    45,    46,
      47,    48,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,    45,    46,
      47,    48,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,    45,    46,
      47,    48,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,    45,    46,
      47,    48,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,    45,    46,
      47,    48,    39,    40,    41,    42,    43,    44,     0,     0,
       1,     2,     3,     4,     5,     0,     0,     0,    45,    46,
      47,    48,     6,     7,     8,     9,     0,    10,    32,     1,
       2,     3,     4,     5,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    57,     6,     7,
       8,     9,     0,    10
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       9,    12,     3,     0,     3,    67,    18,     3,     5,    14,
       3,     8,    14,    10,    18,    12,    29,     0,    27,     3,
      21,    14,    33,    28,    21,    21,    28,    36,    37,    91,
      14,    28,    29,    20,    18,    97,    33,     3,     4,     5,
       6,    50,    18,   105,    19,    54,    18,    22,   110,    15,
      16,    28,    18,    20,    51,     3,     4,     5,     6,    68,
      18,    29,    19,    72,    61,    22,    18,    76,    65,    66,
      18,    10,    28,    65,    92,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    92,    -1,   106,     8,     9,
      10,    11,    12,    13,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    -1,
      24,    25,    26,    27,    28,     8,     9,    10,    11,    12,
      13,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    -1,    24,    25,    26,
      27,    28,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    24,    25,
      26,    27,    28,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,     8,     9,    10,    11,    12,    13,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    24,    25,
      26,    27,    15,    16,    17,    18,    -1,    20,    21,     3,
       4,     5,     6,     7,    -1,    -1,     3,     4,     5,     6,
       7,    15,    16,    17,    18,    -1,    20,    21,    15,    16,
      17,    18,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    15,    16,    17,    18,
      20,    31,    32,    33,    34,    35,    36,    37,    38,    41,
      44,    45,    46,    47,    48,    49,    45,    18,    18,    45,
      45,    48,    21,    32,     0,    33,    14,    18,    45,     8,
       9,    10,    11,    12,    13,    24,    25,    26,    27,    28,
      51,    20,    48,    45,    14,    45,    19,    21,    48,    48,
      50,    18,    48,    21,    39,    40,    45,    19,    29,    15,
      16,    48,    14,    28,    28,    19,    22,    42,    43,    45,
      28,    21,    39,    45,    35,    48,    18,    18,    28,    48,
      48,    19,    22,    45,    28,    14,    28,    19,    48,    45,
      28,    35,    43,    48,    35,    19,    29,    28,    35,    48,
      19,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (&yylloc, scanner, pathFile, errorOut, fileScope, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, scanner, pathFile, errorOut, fileScope); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, const filesystem::path& pathFile, Tk::Sp<const Naba::Lng::CCompileError>& errorOut, Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, pathFile, errorOut, fileScope)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    yyscan_t scanner;
    const filesystem::path& pathFile;
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut;
    Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (pathFile);
  YYUSE (errorOut);
  YYUSE (fileScope);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, const filesystem::path& pathFile, Tk::Sp<const Naba::Lng::CCompileError>& errorOut, Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, pathFile, errorOut, fileScope)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    yyscan_t scanner;
    const filesystem::path& pathFile;
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut;
    Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, pathFile, errorOut, fileScope);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, const filesystem::path& pathFile, Tk::Sp<const Naba::Lng::CCompileError>& errorOut, Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, scanner, pathFile, errorOut, fileScope)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    yyscan_t scanner;
    const filesystem::path& pathFile;
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut;
    Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , scanner, pathFile, errorOut, fileScope);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, scanner, pathFile, errorOut, fileScope); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, const filesystem::path& pathFile, Tk::Sp<const Naba::Lng::CCompileError>& errorOut, Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, scanner, pathFile, errorOut, fileScope)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    yyscan_t scanner;
    const filesystem::path& pathFile;
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut;
    Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (pathFile);
  YYUSE (errorOut);
  YYUSE (fileScope);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (yyscan_t scanner, const filesystem::path& pathFile, Tk::Sp<const Naba::Lng::CCompileError>& errorOut, Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope)
#else
int
yyparse (scanner, pathFile, errorOut, fileScope)
    yyscan_t scanner;
    const filesystem::path& pathFile;
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut;
    Tk::Sp<Naba::Lng::Ast::CBlock>& fileScope;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc = yyloc_default;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 123 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { fileScope = Tk::AttachSp((yyvsp[(1) - (1)].blockParts)); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 127 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockParts) = new Naba::Lng::Ast::CBlock(); (yyval.blockParts)->AddBlockPart((yyvsp[(1) - (1)].blockPart)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 128 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyvsp[(1) - (2)].blockParts)->AddBlockPart((yyvsp[(2) - (2)].blockPart)); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 143 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CExpressionStatement((yyvsp[(1) - (2)].expr)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 146 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = (yyvsp[(2) - (3)].blockParts); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 147 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CBlock(); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 151 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CStruct((yyvsp[(2) - (6)].ident), (yyvsp[(4) - (6)].structParts)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 152 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CStruct((yyvsp[(2) - (5)].ident), nullptr); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 156 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CWhile(nullptr, (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].blockPart)); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 157 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CWhile((yyvsp[(2) - (8)].ident), (yyvsp[(6) - (8)].expr), (yyvsp[(8) - (8)].blockPart)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 160 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CFor(nullptr, (yyvsp[(3) - (7)].ident), (yyvsp[(5) - (7)].expr), (yyvsp[(7) - (7)].blockPart) ); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 161 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CFor((yyvsp[(2) - (10)].ident), (yyvsp[(6) - (10)].ident), (yyvsp[(8) - (10)].expr), (yyvsp[(10) - (10)].blockPart) ); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 164 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.structPart) = new Naba::Lng::Ast::CStructVariable((yyvsp[(1) - (3)].ident), (yyvsp[(2) - (3)].ident), nullptr); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 165 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.structPart) = new Naba::Lng::Ast::CStructVariable((yyvsp[(1) - (5)].ident), (yyvsp[(2) - (5)].ident), (yyvsp[(4) - (5)].expr)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 169 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.structParts) = new Tk::SpList<const Naba::Lng::Ast::CStructPart>; (yyval.structParts)->push_back(Tk::AttachSp((yyvsp[(1) - (1)].structPart))); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 170 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyvsp[(1) - (2)].structParts)->push_back(Tk::AttachSp((yyvsp[(2) - (2)].structPart))); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 174 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CFunction((yyvsp[(1) - (6)].ident), (yyvsp[(2) - (6)].ident), (yyvsp[(4) - (6)].funcParList), (Naba::Lng::Ast::CBlock*)(yyvsp[(6) - (6)].blockPart)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 178 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.funcParList) = new Tk::SpList<const Naba::Lng::Ast::CFunctionParameter>; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 179 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.funcParList) = new Tk::SpList<const Naba::Lng::Ast::CFunctionParameter>; (yyval.funcParList)->push_back(Tk::AttachSp((yyvsp[(1) - (1)].func_param))); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 180 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyvsp[(1) - (3)].funcParList)->push_back(Tk::AttachSp((yyvsp[(3) - (3)].func_param))); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 184 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.func_param) = new Naba::Lng::Ast::CFunctionParameter((yyvsp[(1) - (2)].ident), (yyvsp[(2) - (2)].ident)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 188 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CVariableDeclaration((yyvsp[(2) - (4)].ident), (yyvsp[(3) - (4)].ident), nullptr); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 189 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CVariableDeclaration(nullptr, (yyvsp[(2) - (5)].ident), (yyvsp[(4) - (5)].expr)); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 190 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CVariableDeclaration((yyvsp[(2) - (6)].ident), (yyvsp[(3) - (6)].ident), (yyvsp[(5) - (6)].expr)); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 194 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.ident) = new Naba::Lng::Ast::CIdentifier((yyvsp[(1) - (1)].stringToken)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 198 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.expr) = new Naba::Lng::Ast::CInteger64((yyvsp[(1) - (1)].stringToken));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 199 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.expr) = new Naba::Lng::Ast::CInteger32((yyvsp[(1) - (1)].stringToken));}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 200 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.expr) = new Naba::Lng::Ast::CDouble((yyvsp[(1) - (1)].stringToken));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 204 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.blockPart) = new Naba::Lng::Ast::CAssignment((yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].expr)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 210 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.ident) = (yyvsp[(1) - (1)].ident); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 212 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.expr) = new Naba::Lng::Ast::CBinaryOperator((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].token), (yyvsp[(3) - (3)].expr)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 213 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 220 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.expr) = new Naba::Lng::Ast::CMethodCall((yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].exprvec)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 223 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.exprvec) = new Tk::SpList<const Naba::Lng::Ast::CExpression>; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 224 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyval.exprvec) = new Tk::SpList<const Naba::Lng::Ast::CExpression>; (yyval.exprvec)->push_back(Tk::AttachSp((yyvsp[(1) - (1)].expr))); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 225 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
    { (yyvsp[(1) - (3)].exprvec)->push_back(Tk::AttachSp((yyvsp[(3) - (3)].expr)) ); }
    break;


/* Line 1792 of yacc.c  */
#line 1968 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.cpp"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, pathFile, errorOut, fileScope, YY_("syntax error"));
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
        yyerror (&yylloc, scanner, pathFile, errorOut, fileScope, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc, scanner, pathFile, errorOut, fileScope);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, scanner, pathFile, errorOut, fileScope);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, scanner, pathFile, errorOut, fileScope, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, pathFile, errorOut, fileScope);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, scanner, pathFile, errorOut, fileScope);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 241 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"
