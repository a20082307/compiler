/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
extern "C"
int yylex();
void yyerror(const char* s);

#include "symbol_table.cpp"
#include "symbol_table.hpp"
using namespace std;

Table* table = new Table();
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 13 "parser.y"
typedef union YYSTYPE {
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TYPE 257
#define ID 258
#define OR 259
#define AND 260
#define EQUAL 261
#define NOT_EQUAL 262
#define GE 263
#define LE 264
#define RS 265
#define LS 266
#define INC 267
#define DEC 268
#define Null 269
#define INT 270
#define FLOAT 271
#define CHAR 272
#define STR 273
#define IF 274
#define ELSE 275
#define SWITCH 276
#define CASE 277
#define DEFAULT 278
#define WHILE 279
#define DO 280
#define FOR 281
#define RETURN 282
#define BREAK 283
#define CONTINUE 284
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    2,    3,    4,    5,    5,
    5,    5,    5,    7,    8,    8,    9,    9,    9,    9,
   10,   11,   11,   12,   12,   12,   12,   13,   13,   14,
   14,   15,   15,   16,   16,   17,   17,   17,   18,   18,
   18,   19,   20,   20,   20,   20,   20,   23,   23,   21,
   22,   22,   22,   22,   28,   28,   29,   29,   29,   29,
   29,   29,   29,   29,   29,   30,   30,   31,   32,   32,
   33,   33,   33,   33,   34,   34,   35,   36,   37,   38,
   39,   24,   24,   25,   25,   25,   25,   25,   25,    6,
    6,   26,   27,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    1,    1,    6,    6,    1,    4,    5,
    2,    3,    0,    3,    3,    1,    4,    3,    2,    1,
    3,    3,    1,    7,    6,    3,    2,    4,    3,    3,
    1,    3,    1,    1,    0,    3,    3,    1,    3,    3,
    1,    1,    3,    4,    1,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    2,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    5,    7,    7,    2,    1,
    4,    3,    3,    2,    5,    7,    5,    5,    3,    2,
    2,    3,    2,    2,    2,    2,    1,    1,    1,    2,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   91,    0,    0,    4,    5,    0,    2,    3,   90,    8,
    0,    0,    0,    0,    0,    0,   11,    0,    0,    6,
    0,    7,    0,   12,    9,    0,   83,   50,    0,   47,
   51,   52,   53,   54,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   87,   88,    0,    0,    0,   41,   42,
    0,   46,   65,    0,   89,   58,   59,   60,   61,   62,
   63,   64,   10,    0,    0,    0,    0,    0,    0,    0,
   80,   81,    0,    0,    0,   16,    0,   23,   57,    0,
    0,    0,    0,    0,   93,   84,   85,   82,   86,   43,
    0,    0,    0,    0,    0,    0,   79,    0,    0,    0,
    0,   14,    0,   21,    0,    0,    0,   39,   40,   49,
    0,    0,    0,    0,    0,    0,    0,   18,    0,    0,
    0,    0,    0,    0,    0,   15,    0,    0,   22,    0,
   44,    0,    0,   75,    0,    0,   77,   29,    0,    0,
   17,    0,    0,    0,   48,    0,    0,    0,    0,   70,
    0,    0,    0,    0,    0,   33,   28,    0,   67,    0,
    0,   68,   69,   76,   78,    0,   25,    0,    0,    0,
    0,   56,   32,   30,   24,    0,   55,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  286,  287,  288,  289,  292,  288,  289,  257,  258,
  290,   40,  291,  292,   44,   41,  258,   42,  292,   59,
  123,  310,  312,  258,  258,   42,  125,  258,   40,  269,
  270,  271,  272,  273,  274,  276,  279,  280,  281,  282,
  283,  284,  292,  293,  296,  302,  303,  304,  305,  306,
  307,  308,  310,  311,  315,  316,  317,  320,  321,  323,
  324,  325,  258,  302,   40,   40,   40,  315,   40,  302,
   59,   59,  258,   42,  294,  295,  297,  298,   59,   43,
   45,   42,   47,   40,  125,  293,  296,  313,  315,   41,
  302,  302,  302,  279,  302,  322,   59,   61,   91,  299,
  258,   59,   44,   59,   44,  304,  304,  305,  305,  302,
  309,   41,   41,   41,   40,   59,   41,  302,  302,   61,
   91,   61,  299,  258,   42,  295,  258,   42,  298,   44,
   41,  310,  123,  315,  302,  302,  315,   93,  123,  302,
  302,   61,  258,  258,  302,  275,  277,  278,  318,  319,
   41,   59,  123,  300,  301,  302,   93,  123,  310,  302,
   58,  125,  319,   59,  302,  300,  125,   44,  300,   58,
  314,  315,  125,  300,  125,  314,  315,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
    3,    4,    5,   11,   13,    6,   44,   75,   76,   45,
   77,   78,  100,  154,  155,   46,   47,   48,   49,   50,
   51,   52,  111,   53,   54,   23,   88,  171,  172,   56,
   57,  149,  150,   58,   59,   96,   60,   61,   62,
};
static const YYINT yysindex[] = {                      -251,
    0,    0, -251,    0,    0, -180,    0,    0,    0,    0,
   18, -251,  -20,  -38, -251,  -44,    0, -228,  -10,    0,
  -53,    0,   28,    0,    0, -158,    0,    0,   74,    0,
    0,    0,    0,    0,   77,   89,   92,   47,   97,   74,
   79,   87,   -8,    0,    0,   88,  -14,  -24,    0,    0,
  108,    0,    0,  -12,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  111,   74,   74,   74, -130,   74,   99,
    0,    0,  -41,  -99,    3,    0,   17,    0,    0,   74,
   74,   74,   74,   74,    0,    0,    0,    0,    0,    0,
  119,  120,  123,  125,  107,  126,    0,   74,   74,  -39,
  -34,    0,   -7,    0,   -6,  -24,  -24,    0,    0,    0,
   50,   49,   51,   47,   74,   74,   47,    0,   76,   52,
   74,   74,  -17,  112,  -81,    0,   90,  -80,    0,   74,
    0,  -96, -155,    0,  141,  124,    0,    0,   64,   91,
    0,   63,  128,   90,    0,   49,   74,  127, -124,    0,
  131,   74,   64,   66,  148,    0,    0,   64,    0,  137,
   47,    0,    0,    0,    0,   72,    0,   64,   73,   47,
   47,    0,    0,    0,    0,   47,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  196,    0,    0,    0,    0,    0,    0,    0,
    0,   58,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,  142,    0,    0,    0,    0,    0,  161,    0,
    0,    0,    0,    0,    0,    0,    0,  142,    0,  142,
    0,    0,    0,    0,    0,    0,    5,  -33,    0,    0,
   -4,    0,    0,  142,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  161,  161,  161,    0,  142,    0,
    0,    0,   21,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   71,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,  110,   42,
   44,    0,    0,    0,    0,   75,   83,    0,    0,    0,
    0,    0,    0,  142,  161,  142,  142,    0,    0,    0,
  110,   38,   46,   21,    0,    0,    0,    0,    0,   71,
    0,  -40,    0,    0,    0,    0,    0,    0,  -30,    0,
    0,    0,   44,    0,    0,    0,  146,    0,    0,    0,
    0,  161,  -30,    0,   80,    0,    0,  -30,    0,    0,
  -56,    0,    0,    0,    0,    0,    0,  -30,    0,  -54,
  -52,    0,    0,    0,    0,  -50,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  203,  204,    0,    0,   30,  156,    0,  109,  157,
    0,  130,  -85, -102,    0,   41,    0,   55,   62,    0,
    0,    0,    0,   -3,    0,    0,    0,   43,  -21,    0,
    0,    0,   65,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 347
static const YYINT yytable[] = {                         66,
  162,   55,   35,   18,   35,    1,   35,   38,   35,   38,
   38,   38,   22,   35,   20,  123,   68,   82,   66,   98,
   16,  120,   83,   15,   38,   38,  122,   29,   80,   24,
   81,   26,   89,   74,  125,  128,   45,   45,   45,   45,
   45,   14,   45,  142,   19,   34,  103,   92,   34,   99,
  166,  121,   43,   45,   45,  169,   99,   12,  123,   38,
  105,  102,   34,   34,   20,  174,   92,   29,   74,   64,
   73,   27,   72,  121,   71,  104,    9,   10,   21,   20,
   70,   35,   66,   43,   66,   27,   29,   19,   45,   26,
  131,   38,  134,  130,   35,  137,   35,   34,   13,   63,
   27,   13,   19,   29,   26,   91,   92,   93,  132,   95,
   21,   35,   85,   29,   35,   36,   65,   36,   36,   36,
   45,  147,  148,   37,  110,   37,   37,   37,   66,   34,
   92,   67,   36,   36,  106,  107,   69,   71,  118,  119,
   37,   37,  159,  108,  109,   72,   79,   84,   94,  177,
   21,   90,  147,  148,  177,  135,  136,   97,  101,  112,
  113,  140,  141,  114,  115,  116,  117,   36,  138,   21,
  145,   21,   98,  133,  139,   37,  143,  144,  146,  156,
   99,  151,  152,  157,  161,  158,  153,  160,  122,  164,
  167,  168,  165,  156,  170,    1,  173,  175,  156,   36,
   35,   35,   35,   35,   31,    7,    8,   37,  156,   86,
   87,  126,  176,  163,    0,    0,   66,   66,    9,   17,
   74,   74,   73,   73,   72,   72,   71,   71,   66,   66,
   66,   66,   66,   66,  129,   66,   66,   66,   66,   66,
   66,   66,   66,   66,    1,   28,    9,   25,    9,   73,
  124,  127,    0,    0,    0,    0,   30,   31,   32,   33,
   34,   35,    0,   36,   92,   92,   37,   38,   39,   40,
   41,   42,    0,    0,    0,    0,   92,   92,   92,   92,
   92,   92,    0,   92,    1,   28,   92,   92,   92,   92,
   92,   92,    0,    0,    0,    0,   30,   31,   32,   33,
   34,   35,    0,   36,   28,    0,   37,   38,   39,   40,
   41,   42,    0,    0,    0,   30,   31,   32,   33,   34,
   35,   28,   36,    0,    0,   37,   38,   39,   40,   41,
   42,   28,   30,   31,   32,   33,   34,    0,    0,    0,
    0,    0,   30,   31,   32,   33,   34,
};
static const YYINT yycheck[] = {                         40,
  125,   23,   59,   42,   59,  257,   59,   41,   59,   43,
   44,   45,   16,   44,   59,  101,   38,   42,   59,   61,
   41,   61,   47,   44,   58,   59,   61,   40,   43,  258,
   45,   42,   54,   42,   42,   42,   41,   42,   43,   44,
   45,   12,   47,   61,   15,   41,   44,   40,   44,   91,
  153,   91,   23,   58,   59,  158,   91,   40,  144,   93,
   44,   59,   58,   59,   44,  168,   59,   40,  125,   29,
  125,  125,  125,   91,  125,   59,  257,  258,  123,   59,
   40,   44,  123,   54,  125,   44,   40,   44,   93,   44,
   41,  125,  114,   44,  125,  117,   59,   93,   41,  258,
   59,   44,   59,   40,   59,   65,   66,   67,  112,   69,
  123,   41,  125,   40,   44,   41,   40,   43,   44,   45,
  125,  277,  278,   41,   84,   43,   44,   45,   40,  125,
  123,   40,   58,   59,   80,   81,   40,   59,   98,   99,
   58,   59,  146,   82,   83,   59,   59,   40,  279,  171,
  123,   41,  277,  278,  176,  115,  116,   59,  258,   41,
   41,  121,  122,   41,   40,   59,   41,   93,   93,  123,
  130,  123,   61,  123,  123,   93,  258,  258,  275,  139,
   91,   41,   59,   93,   58,  123,  123,  147,   61,   59,
  125,   44,  152,  153,   58,    0,  125,  125,  158,  125,
   59,   41,   93,   58,  125,    3,    3,  125,  168,   54,
   54,  103,  170,  149,   -1,   -1,  257,  258,  257,  258,
  277,  278,  277,  278,  277,  278,  277,  278,  269,  270,
  271,  272,  273,  274,  105,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  257,  258,  257,  258,  257,  258,
  258,  258,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,  276,  257,  258,  279,  280,  281,  282,
  283,  284,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,  276,  257,  258,  279,  280,  281,  282,
  283,  284,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,  276,  258,   -1,  279,  280,  281,  282,
  283,  284,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  258,  276,   -1,   -1,  279,  280,  281,  282,  283,
  284,  258,  269,  270,  271,  272,  273,   -1,   -1,   -1,
   -1,   -1,  269,  270,  271,  272,  273,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 326
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'!'",0,
0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","TYPE","ID","OR","AND",
"EQUAL","NOT_EQUAL","GE","LE","RS","LS","INC","DEC","Null","INT","FLOAT","CHAR",
"STR","IF","ELSE","SWITCH","CASE","DEFAULT","WHILE","DO","FOR","RETURN","BREAK",
"CONTINUE","$accept","program","code","func_declaration","func_definition",
"func_symbol","parameters","types","scalar_declaration","scalars","scalar",
"array_declaration","arrays","array","array_shape","array_content_elements",
"array_content_element","expression","expr_4","expr_3","expr_2","expr_1",
"variable","literal","func_call_parameters","compound_statements",
"compound_statement","scope_begin","scope_end","statements","statement",
"if_statement","switch_statement","switch_cases","switch_case",
"while_statement","for_statement","for_parameters","return_statement",
"break_statement","continue_statement","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : code",
"code : code func_declaration",
"code : code func_definition",
"code : func_declaration",
"code : func_definition",
"func_declaration : types func_symbol '(' parameters ')' ';'",
"func_definition : types func_symbol '(' parameters ')' compound_statements",
"func_symbol : ID",
"parameters : parameters ',' types ID",
"parameters : parameters ',' types '*' ID",
"parameters : types ID",
"parameters : types '*' ID",
"parameters :",
"scalar_declaration : types scalars ';'",
"scalars : scalars ',' scalar",
"scalars : scalar",
"scalar : '*' ID '=' expression",
"scalar : ID '=' expression",
"scalar : '*' ID",
"scalar : ID",
"array_declaration : types arrays ';'",
"arrays : arrays ',' array",
"arrays : array",
"array : '*' ID array_shape '=' '{' array_content_elements '}'",
"array : ID array_shape '=' '{' array_content_elements '}'",
"array : '*' ID array_shape",
"array : ID array_shape",
"array_shape : array_shape '[' expression ']'",
"array_shape : '[' expression ']'",
"array_content_elements : array_content_element ',' array_content_elements",
"array_content_elements : array_content_element",
"array_content_element : '{' array_content_elements '}'",
"array_content_element : expression",
"expression : expr_4",
"expression :",
"expr_4 : expr_4 '+' expr_3",
"expr_4 : expr_4 '-' expr_3",
"expr_4 : expr_3",
"expr_3 : expr_3 '*' expr_2",
"expr_3 : expr_3 '/' expr_2",
"expr_3 : expr_2",
"expr_2 : expr_1",
"expr_1 : '(' expression ')'",
"expr_1 : variable '(' func_call_parameters ')'",
"expr_1 : variable",
"expr_1 : literal",
"expr_1 : Null",
"func_call_parameters : func_call_parameters ',' expression",
"func_call_parameters : expression",
"variable : ID",
"literal : INT",
"literal : FLOAT",
"literal : CHAR",
"literal : STR",
"statements : statements statement",
"statements : statement",
"statement : expression ';'",
"statement : if_statement",
"statement : switch_statement",
"statement : while_statement",
"statement : for_statement",
"statement : return_statement",
"statement : break_statement",
"statement : continue_statement",
"statement : compound_statements",
"if_statement : IF '(' expression ')' compound_statements",
"if_statement : IF '(' expression ')' compound_statements ELSE compound_statements",
"switch_statement : SWITCH '(' expression ')' '{' switch_cases '}'",
"switch_cases : switch_cases switch_case",
"switch_cases : switch_case",
"switch_case : CASE expression ':' statements",
"switch_case : DEFAULT ':' statements",
"switch_case : CASE expression ':'",
"switch_case : DEFAULT ':'",
"while_statement : WHILE '(' expression ')' statement",
"while_statement : DO statement WHILE '(' expression ')' ';'",
"for_statement : FOR '(' for_parameters ')' statement",
"for_parameters : expression ';' expression ';' expression",
"return_statement : RETURN expression ';'",
"break_statement : BREAK ';'",
"continue_statement : CONTINUE ';'",
"compound_statements : scope_begin compound_statement scope_end",
"compound_statements : '{' '}'",
"compound_statement : compound_statement scalar_declaration",
"compound_statement : compound_statement array_declaration",
"compound_statement : compound_statement statement",
"compound_statement : scalar_declaration",
"compound_statement : array_declaration",
"compound_statement : statement",
"types : types TYPE",
"types : TYPE",
"scope_begin : '{'",
"scope_end : '}'",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 282 "parser.y"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    cerr << s << endl;
    exit(1);
}
#line 636 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 6:
#line 73 "parser.y"
	{
        generate_code(".global " + string(yystack.l_mark[-4].str) + "\n");
    }
#line 1311 "y.tab.c"
break;
case 7:
#line 77 "parser.y"
	{
        table -> codegen_func_footer();
    }
#line 1318 "y.tab.c"
break;
case 8:
#line 81 "parser.y"
	{
        if (table -> isExist(string(yystack.l_mark[0].str)))
            table -> codegen_func_header(string(yystack.l_mark[0].str));
        else 
            table -> append(new Symbol(string(yystack.l_mark[0].str), Type::Function, table -> get_cur_scope()));
    }
#line 1328 "y.tab.c"
break;
case 13:
#line 92 "parser.y"
	{ yyval.str = strdup(""); }
#line 1333 "y.tab.c"
break;
case 17:
#line 100 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[-2].str), Type::Variable, table -> get_cur_scope()));
    }
#line 1340 "y.tab.c"
break;
case 18:
#line 103 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[-2].str), Type::Variable, table -> get_cur_scope()));
    }
#line 1347 "y.tab.c"
break;
case 19:
#line 106 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[0].str), Type::Variable, table -> get_cur_scope()));
    }
#line 1354 "y.tab.c"
break;
case 20:
#line 109 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[0].str), Type::Variable, table -> get_cur_scope()));
    }
#line 1361 "y.tab.c"
break;
case 24:
#line 119 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[-5].str), Type::Array, table -> get_cur_scope()));
    }
#line 1368 "y.tab.c"
break;
case 25:
#line 122 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[-5].str), Type::Array, table -> get_cur_scope()));
    }
#line 1375 "y.tab.c"
break;
case 26:
#line 125 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[-1].str), Type::Array, table -> get_cur_scope()));
    }
#line 1382 "y.tab.c"
break;
case 27:
#line 128 "parser.y"
	{
        table -> append(new Symbol(string(yystack.l_mark[-1].str), Type::Array, table -> get_cur_scope()));
    }
#line 1389 "y.tab.c"
break;
case 35:
#line 143 "parser.y"
	{ yyval.str = strdup(""); }
#line 1394 "y.tab.c"
break;
case 44:
#line 156 "parser.y"
	{
        string *func_name = new string(string(yystack.l_mark[-3].str));

        if (*func_name == "digitalWrite") {
            string *parameters = new string(yystack.l_mark[-1].str);
            int pin = atoi(parameters -> substr(0, parameters -> find(",")).c_str());
            string value = parameters -> substr(parameters -> find(",") + 1);

            generate_digitalWrite_code(pin, value);
        }
        else if (*func_name == "delay") {
            generate_delay_code(atoi(yystack.l_mark[-1].str));
        }
        else if (table -> isExist(*func_name)) {

        }
    }
#line 1415 "y.tab.c"
break;
case 45:
#line 173 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1420 "y.tab.c"
break;
case 48:
#line 177 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-2].str) + "," + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1428 "y.tab.c"
break;
case 49:
#line 181 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1433 "y.tab.c"
break;
case 50:
#line 183 "parser.y"
	{
        string id_name = string(yystack.l_mark[0].str);
        int index = table -> find(id_name);
        if (index == -1) {
            cerr << "Variable " << id_name << " not declared" << endl;
            exit(1);
        }
        else if (index == -2) {
            yyval.str = strdup(id_name.c_str());
        }
        else if (index >= 0) {
            int offset = table -> entry[index].get_offset() * (-4) - 48;
            generate_code(id_name + "\n");
            generate_code("    lw t0, " + to_string(offset) + "(sp)\n");
            generate_code("    addi sp, sp, -4\n");
            generate_code("    sw t0, 0(sp)\n");
        }
    }
#line 1455 "y.tab.c"
break;
case 84:
#line 250 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1463 "y.tab.c"
break;
case 85:
#line 254 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1471 "y.tab.c"
break;
case 86:
#line 258 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1479 "y.tab.c"
break;
case 87:
#line 262 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1484 "y.tab.c"
break;
case 88:
#line 263 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1489 "y.tab.c"
break;
case 89:
#line 264 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1494 "y.tab.c"
break;
case 90:
#line 267 "parser.y"
	{
        string *type = new string(string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str));
        yyval.str = strdup(type -> c_str());   delete type;
    }
#line 1502 "y.tab.c"
break;
case 92:
#line 273 "parser.y"
	{
        table -> enter_new_scope();
    }
#line 1509 "y.tab.c"
break;
case 93:
#line 277 "parser.y"
	{
        table -> leave_cur_scope();
    }
#line 1516 "y.tab.c"
break;
#line 1518 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
