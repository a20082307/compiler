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

#include <iostream>
#include <cstring>
using namespace std;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 11 "parser.y"
typedef union YYSTYPE {
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

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

#define OR 257
#define AND 258
#define EQUAL 259
#define NOT_EQUAL 260
#define GE 261
#define LE 262
#define RS 263
#define LS 264
#define INC 265
#define DEC 266
#define Null 267
#define INT 268
#define FLOAT 269
#define CHAR 270
#define STR 271
#define TYPE 272
#define ID 273
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
    0,    1,    1,    1,    2,    2,    2,   19,   20,   20,
   21,   21,   22,   22,   23,   24,   24,   25,   25,   26,
   26,   27,   27,   28,   28,   29,   30,   31,   31,   32,
   32,    3,    3,    4,    4,    5,    5,    6,    6,    7,
    7,    8,    8,    9,    9,   10,   10,   10,   11,   11,
   11,   11,   11,   12,   12,   12,   13,   13,   13,   14,
   14,   14,   14,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   17,   18,   18,   18,   18,   34,   34,
   35,   35,   36,   36,   33,   33,   33,   33,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    3,    2,    1,
    3,    1,    3,    1,    3,    3,    1,    6,    2,    4,
    3,    3,    1,    3,    1,    3,    4,    3,    1,    2,
    0,    0,    1,    3,    1,    3,    1,    3,    1,    3,
    1,    3,    1,    3,    1,    3,    3,    1,    3,    3,
    3,    3,    1,    3,    3,    1,    3,    3,    1,    3,
    3,    3,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    4,    5,    1,    2,    2,    4,    3,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    1,
    2,    1,    7,   11,    2,    2,    1,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   83,
   85,   86,   87,   88,   10,    0,    0,    0,    0,    3,
    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   63,    0,   81,   82,    5,    0,    6,    7,
    0,   90,   92,   71,   66,   67,   70,   64,   65,   69,
   68,    0,    0,    0,    0,    0,    2,   91,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   75,   76,    0,
    0,    9,    0,    0,   12,    0,   17,    0,   89,   78,
    0,    0,    0,    0,    0,   34,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   60,   61,   62,    0,    0,    0,    0,    0,    8,
    0,   15,    0,   26,    0,   72,   21,    0,    0,   77,
   13,    0,    0,   29,    0,    0,   11,    0,   16,   73,
   20,    0,   30,   27,    0,    0,    0,    0,   28,    0,
   25,    0,    0,    0,   95,    0,   96,    0,   18,    0,
    0,    0,   24,   22,    0,    0,   94,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
   38,   43,   45,   42,  265,  266,  126,   33,   40,  267,
  268,  269,  270,  271,  272,  273,  274,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  302,  303,  304,  305,  306,  309,  315,
  320,  321,  322,  301,  301,  301,  301,  301,  301,  301,
  301,  289,  306,   91,  312,   40,  288,   59,   61,  257,
  258,  124,   94,   38,  259,  260,   60,   62,  261,  262,
  263,  264,   43,   45,   42,   47,   37,  265,  266,  273,
  303,  272,  273,  307,  308,  310,  311,  316,  321,   41,
   42,   41,  289,   91,  289,  290,  292,  293,  294,  295,
  296,  297,  297,  298,  298,  298,  298,  299,  299,  300,
  300,  301,  301,  301,  312,   40,   61,   40,  312,   59,
   44,   59,   44,   59,   41,  301,   93,  289,   41,   41,
  289,  306,  317,  318,   61,  273,  308,  273,  311,  301,
   93,  123,  273,   41,   44,  123,  319,  320,  318,  123,
  289,  313,  314,  125,  305,  306,  309,  313,  125,   44,
  275,  273,  125,  313,  123,  319,  125,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         18,
   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
   84,   85,   39,   86,   87,  119,  152,  153,   40,   88,
  133,  134,  147,  148,   42,   43,
};
static const YYINT yysindex[] = {                       -33,
   37,   37,   37,   37,   37,   37,   37,   37,   12,    0,
    0,    0,    0,    0,    0,  -62,   -7,    0, -232,    0,
    8,    0,  -59, -182,  -41,   13,   82, -170,  -47, -152,
   65,   81,    0, -101,    0,    0,    0, -106,    0,    0,
  -22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   93,  -17,   37,   31,   37,    0,    0,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,    0,    0,  -62,
   85,    0,  -13,   -8,    0,   14,    0,   70,    0,    0,
  103,   37,   69,   37,  127,    0, -182,  -41,   13,   82,
 -170,  -47,  -47, -152, -152, -152, -152,   65,   65,   81,
   81,    0,    0,    0,   31,  135,   37, -232,  -35,    0,
  -88,    0,  -87,    0,   37,    0,    0,   94,   66,    0,
    0, -102,   21,    0,   67,   90,    0,  -62,    0,    0,
    0,  -22,    0,    0, -232,   26, -122,  -22,    0,   26,
    0,   68,  144,  -79,    0,  -91,    0,   74,    0,   26,
   77,  -30,    0,    0,  -22, -111,    0,
};
static const YYINT yyrindex[] = {                       142,
    0,    0,    0,    0,    0,    0,    0,    0,  163,    0,
    0,    0,    0,    0,    0,   54,    0,    0,  205,    0,
    0,    0,   -6,   44,  593,  466,  282,  136,  698,  514,
  408,  341,    0,  287,    0,    0,    0,    0,    0,    0,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  118,   98,  163,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  173,
    0,    0,   50,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  118,    0,    0,  811,  780,  776,  771,
  766,  709,  755,  526,  585,  673,  684,  436,  444,  354,
  398,    0,    0,    0,  165,    0,   58,   40,   62,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   50,    0,    0,    0,    0,
    0,  -53,    0,    0,   40,  -25,    0,  -51,    0,  -25,
    0,    0,   91,    1,    0,    0,    0,    0,    0,  -25,
    0,   50,    0,    0,  -53,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  198,  831,  159,    0,  160,  167,  169,  179,  186,
   88,   63,   84,  110,  907,    0,  219,    0, -119,   28,
    0,  133, -117,    0,  134,    6, -118,    0,    0,    0,
    0,  111,   97,  263,  -24,    0,
};
#define YYTABLESIZE 1068
static const YYINT yytable[] = {                          8,
   93,   59,  154,    4,    1,   32,    9,   32,    4,    2,
    8,    3,   67,  167,   68,    1,   89,    9,   32,    4,
    2,   55,    3,   92,   91,  135,  118,  155,   54,  157,
  117,  158,   56,   93,   35,  121,   53,   35,   93,   15,
   93,  164,   93,   93,    8,   93,  155,  117,  157,    1,
  120,    9,   35,    4,    2,   94,    3,  123,    8,   93,
   54,  144,   32,    1,  145,    9,   58,    4,    2,    8,
    3,   98,  122,   97,    1,   61,    9,   54,    4,    2,
   31,    3,   62,   31,   37,  115,   35,   37,   65,   66,
   84,   84,    7,   14,   84,   84,   84,   84,   84,   32,
   84,   32,   37,    7,   37,   19,   63,   73,   14,   74,
   71,   72,   84,   84,   84,   84,   32,   77,   35,   64,
   19,   94,   75,   89,  116,   93,   93,   76,  124,  104,
  105,  106,  107,   90,   80,   80,   37,    7,   80,   80,
   80,   80,   80,  125,   80,  132,   84,   84,  150,   15,
  117,    7,  102,  103,  108,  109,   80,   80,   80,   80,
   15,  127,    7,   78,   79,   82,   83,  129,   37,   82,
  143,   80,  132,   45,  156,  130,   45,   84,   84,   45,
   82,  162,  110,  111,  136,  138,  141,  160,  142,  146,
   80,   80,  159,  156,   45,  161,   45,   60,  163,  165,
   32,   79,   79,   32,    1,   79,   79,   79,   79,   79,
   32,   79,   84,   69,   70,   23,   57,   96,   98,   97,
   97,   80,   80,   79,   79,   79,   79,   98,   45,   45,
   99,    5,    6,   10,   11,   12,   13,   14,   15,   16,
   17,  100,    5,    6,   10,   11,   12,   13,   14,  101,
   16,   17,   81,  137,   82,  149,  139,   79,   79,   45,
   45,  166,   41,    0,    0,   93,   93,   93,   93,   93,
   93,   93,   93,   93,   93,    4,    5,    6,   10,   11,
   12,   13,   14,   15,   16,    0,    0,    0,   79,   79,
    5,    6,   10,   11,   12,   13,   14,    0,   16,    0,
   37,    5,    6,   10,   11,   12,   13,   14,    0,   16,
   84,   84,   84,   84,   84,   84,   84,   84,   84,   84,
    0,    0,   43,   74,   74,   43,   84,   74,   74,   74,
   74,   74,    0,   74,    0,    0,    0,    0,    0,    0,
   43,    0,   43,    0,    0,   74,   74,   74,   74,    0,
    0,    0,    0,    0,   80,   80,   80,   80,   80,   80,
   80,   80,   80,   80,    0,    0,    0,    0,    0,    0,
   80,    0,    0,    0,   43,   43,    0,    0,   59,   74,
   74,   59,    0,   59,   59,   59,    0,    0,    0,    0,
    0,   57,   45,   45,   57,    0,   57,   57,   57,   59,
   59,   59,   59,    0,    0,   43,   43,    0,    0,    0,
   74,   74,   57,   57,   57,   57,    0,    0,    0,    0,
    0,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79,    0,    0,   59,   59,   58,    0,   79,   58,    0,
   58,   58,   58,    0,    0,   56,   57,   57,   56,    0,
    0,   56,    0,    0,    0,    0,   58,   58,   58,   58,
    0,    0,    0,    0,   59,   59,   56,   56,   56,   56,
    0,    0,    0,   54,    0,    0,   54,   57,   57,   54,
    0,   55,    0,    0,   55,    0,    0,   55,    0,    0,
   58,   58,    0,    0,   54,   54,   54,   54,    0,    0,
   56,   56,   55,   55,   55,   55,   41,    0,    0,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   58,   58,    0,   41,    0,   41,    0,   54,   54,
    0,   56,   56,    0,    0,    0,   55,   55,   43,   43,
    0,    0,    0,   74,   74,   74,   74,   74,   74,   74,
   74,   53,    0,    0,   53,    0,    0,   53,   41,   54,
   54,    0,    0,   49,    0,    0,   49,   55,   55,   49,
    0,    0,   53,   53,   53,   53,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   49,   49,   49,    0,   41,
   41,    0,    0,    0,    0,    0,    0,   59,   59,   59,
   59,   59,   59,   59,   59,    0,   53,   53,    0,    0,
   57,   57,   57,   57,   57,   57,   57,   57,   49,   49,
    0,    0,   50,    0,    0,   50,    0,    0,   50,    0,
    0,    0,    0,   39,    0,    0,   39,   53,   53,    0,
    0,    0,    0,   50,   50,   50,   50,    0,    0,   49,
   49,   39,    0,   39,   58,   58,   58,   58,   58,   58,
   58,   58,    0,    0,   56,   56,   56,   56,   56,   56,
   56,   56,    0,    0,    0,    0,    0,   50,   50,    0,
    0,    0,    0,    0,    0,   39,    0,    0,    0,    0,
    0,    0,   54,   54,   54,   54,   54,   54,   54,   54,
   55,   55,   55,   55,   55,   55,   55,   55,   50,   50,
   51,    0,    0,   51,    0,    0,   51,   39,    0,    0,
    0,   52,   41,   41,   52,    0,    0,   52,    0,    0,
    0,   51,   51,   51,   51,   48,    0,    0,   48,    0,
    0,   48,   52,   52,   52,   52,   46,    0,    0,   46,
    0,    0,   46,    0,    0,    0,   48,    0,   48,    0,
    0,    0,    0,    0,    0,   51,   51,   46,    0,   46,
   53,   53,   53,   53,   53,   53,   52,   52,    0,    0,
    0,    0,   49,   49,   49,   49,   49,   49,    0,    0,
   48,   48,   47,    0,    0,   47,   51,   51,   47,    0,
    0,   46,   46,   44,    0,    0,   44,   52,   52,   44,
    0,   42,    0,   47,   42,   47,   40,    0,    0,   40,
   38,   48,   48,   38,   44,    0,   44,    0,    0,   42,
    0,   42,   46,   46,   40,    0,   40,    0,   38,   52,
   38,   50,   50,   50,   50,   50,   50,   47,   47,   39,
   39,   36,    0,    0,   36,    0,    0,    0,   44,   44,
    0,    0,    0,   42,   42,    0,    0,    0,   40,   36,
    0,   36,   38,    0,    0,    0,    0,    0,   47,   47,
    0,    0,    0,    0,   93,    0,   95,    0,    0,   44,
   44,    0,    0,    0,   42,   42,    0,    0,    0,   40,
   40,    0,    0,   36,   38,    0,    0,   44,   45,   46,
   47,   48,   49,   50,   51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  128,    0,    0,    0,    0,   51,
   51,   51,   51,   51,   51,   36,    0,    0,    0,    0,
   52,   52,   52,   52,   52,   52,    0,  131,    0,    0,
    0,    0,    0,    0,   48,   48,   48,   48,    0,    0,
    0,    0,    0,    0,    0,   46,   46,   46,   46,    0,
    0,    0,    0,    0,    0,    0,  151,    0,    0,    0,
  151,  112,  113,  114,    0,    0,    0,    0,    0,    0,
  151,    0,    0,    0,    0,    0,    0,    0,  126,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   47,   47,   47,   47,    0,    0,    0,    0,    0,
    0,    0,   44,   44,    0,    0,    0,   42,   42,    0,
    0,  140,   40,   40,    0,    0,   38,   38,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,
};
static const YYINT yycheck[] = {                         33,
    0,   61,  125,    0,   38,   59,   40,   59,   42,   43,
   33,   45,   60,  125,   62,   38,   41,   40,   44,   42,
   43,   16,   45,   41,   42,   61,   40,  147,   91,  147,
   61,  150,   40,   33,   41,   44,    9,   44,   38,  272,
   40,  160,   42,   43,   33,   45,  166,   61,  166,   38,
   59,   40,   59,   42,   43,   91,   45,   44,   33,   59,
   91,   41,   59,   38,   44,   40,   59,   42,   43,   33,
   45,  125,   59,  125,   38,  258,   40,   91,   42,   43,
   41,   45,  124,   44,   41,   80,   93,   44,  259,  260,
   37,   38,  126,   44,   41,   42,   43,   44,   45,  125,
   47,   44,   59,  126,   61,   44,   94,   43,   59,   45,
  263,  264,   59,   60,   61,   62,   59,   37,  125,   38,
   59,   91,   42,  148,   40,  125,  126,   47,   59,   67,
   68,   69,   70,   41,   37,   38,   93,  126,   41,   42,
   43,   44,   45,   41,   47,  118,   93,   94,  123,  272,
   61,  126,   65,   66,   71,   72,   59,   60,   61,   62,
  272,   93,  126,  265,  266,  272,  273,   41,  125,  272,
  273,  273,  145,   38,  147,   41,   41,  124,  125,   44,
  272,  273,   73,   74,  273,  273,   93,   44,  123,  123,
   93,   94,  125,  166,   59,  275,   61,  257,  125,  123,
   59,   37,   38,   41,    0,   41,   42,   43,   44,   45,
   93,   47,   40,  261,  262,  125,   19,   59,  272,   60,
  272,  124,  125,   59,   60,   61,   62,   61,   93,   94,
   62,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,   63,  265,  266,  267,  268,  269,  270,  271,   64,
  273,  274,   34,  121,  272,  145,  123,   93,   94,  124,
  125,  165,    0,   -1,   -1,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  272,  265,  266,  267,  268,
  269,  270,  271,  272,  273,   -1,   -1,   -1,  124,  125,
  265,  266,  267,  268,  269,  270,  271,   -1,  273,   -1,
  257,  265,  266,  267,  268,  269,  270,  271,   -1,  273,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
   -1,   -1,   41,   37,   38,   44,  273,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   -1,   61,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,   -1,   -1,   -1,   -1,   -1,   -1,
  273,   -1,   -1,   -1,   93,   94,   -1,   -1,   38,   93,
   94,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   -1,   38,  257,  258,   41,   -1,   43,   44,   45,   59,
   60,   61,   62,   -1,   -1,  124,  125,   -1,   -1,   -1,
  124,  125,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,  261,  262,  263,  264,  265,
  266,   -1,   -1,   93,   94,   38,   -1,  273,   41,   -1,
   43,   44,   45,   -1,   -1,   38,   93,   94,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   59,   60,   61,   62,
   -1,   -1,   -1,   -1,  124,  125,   59,   60,   61,   62,
   -1,   -1,   -1,   38,   -1,   -1,   41,  124,  125,   44,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   93,   94,   -1,   -1,   59,   60,   61,   62,   -1,   -1,
   93,   94,   59,   60,   61,   62,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,  125,   -1,   59,   -1,   61,   -1,   93,   94,
   -1,  124,  125,   -1,   -1,   -1,   93,   94,  257,  258,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,   38,   -1,   -1,   41,   -1,   -1,   44,   93,  124,
  125,   -1,   -1,   38,   -1,   -1,   41,  124,  125,   44,
   -1,   -1,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,  124,
  125,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,   93,   94,   -1,   -1,
  257,  258,  259,  260,  261,  262,  263,  264,   93,   94,
   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   44,  124,  125,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   -1,   -1,  124,
  125,   59,   -1,   61,  257,  258,  259,  260,  261,  262,
  263,  264,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,  263,  264,
  257,  258,  259,  260,  261,  262,  263,  264,  124,  125,
   38,   -1,   -1,   41,   -1,   -1,   44,  125,   -1,   -1,
   -1,   38,  257,  258,   41,   -1,   -1,   44,   -1,   -1,
   -1,   59,   60,   61,   62,   38,   -1,   -1,   41,   -1,
   -1,   44,   59,   60,   61,   62,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   59,   -1,   61,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   94,   59,   -1,   61,
  257,  258,  259,  260,  261,  262,   93,   94,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,   -1,
   93,   94,   38,   -1,   -1,   41,  124,  125,   44,   -1,
   -1,   93,   94,   38,   -1,   -1,   41,  124,  125,   44,
   -1,   41,   -1,   59,   44,   61,   41,   -1,   -1,   44,
   41,  124,  125,   44,   59,   -1,   61,   -1,   -1,   59,
   -1,   61,  124,  125,   59,   -1,   61,   -1,   59,    9,
   61,  257,  258,  259,  260,  261,  262,   93,   94,  257,
  258,   41,   -1,   -1,   44,   -1,   -1,   -1,   93,   94,
   -1,   -1,   -1,   93,   94,   -1,   -1,   -1,   93,   59,
   -1,   61,   93,   -1,   -1,   -1,   -1,   -1,  124,  125,
   -1,   -1,   -1,   -1,   54,   -1,   56,   -1,   -1,  124,
  125,   -1,   -1,   -1,  124,  125,   -1,   -1,   -1,  124,
  125,   -1,   -1,   93,  125,   -1,   -1,    1,    2,    3,
    4,    5,    6,    7,    8,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  125,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,  262,   -1,  117,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  146,   -1,   -1,   -1,
  150,   75,   76,   77,   -1,   -1,   -1,   -1,   -1,   -1,
  160,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   92,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,   -1,   -1,   -1,  257,  258,   -1,
   -1,  125,  257,  258,   -1,   -1,  257,  258,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 18
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 323
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"' '",
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","OR","AND","EQUAL",
"NOT_EQUAL","GE","LE","RS","LS","INC","DEC","Null","INT","FLOAT","CHAR","STR",
"TYPE","ID","IF","ELSE","SWITCH","CASE","DEFAULT","WHILE","DO","FOR","RETURN",
"BREAK","CONTINUE","$accept","program","code","declaration","expression",
"expr_14","expr_12","expr_11","expr_10","expr_9","expr_8","expr_7","expr_6",
"expr_5","expr_4","expr_3","expr_2","expr_1","variable","literal",
"scalar_declaration","scalar_type","scalar_ids","scalar_id","array_declaration",
"arrays","array","array_shape","array_content_elements","array_content_element",
"func_declaration","function","func_parameters","func_parameter",
"compound_statements","statements","statement","if_statement","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : code",
"code : code declaration",
"code : declaration",
"code : statements",
"declaration : scalar_declaration",
"declaration : array_declaration",
"declaration : func_declaration",
"scalar_declaration : scalar_type scalar_ids ';'",
"scalar_type : scalar_type TYPE",
"scalar_type : TYPE",
"scalar_ids : scalar_ids ',' scalar_id",
"scalar_ids : scalar_id",
"scalar_id : ID '=' expression",
"scalar_id : ID",
"array_declaration : scalar_type arrays ';'",
"arrays : arrays ',' array",
"arrays : array",
"array : ID array_shape '=' '{' array_content_elements '}'",
"array : ID array_shape",
"array_shape : array_shape '[' expression ']'",
"array_shape : '[' expression ']'",
"array_content_elements : array_content_element ',' array_content_elements",
"array_content_elements : array_content_element",
"array_content_element : '{' array_content_elements '}'",
"array_content_element : expression",
"func_declaration : scalar_type function ';'",
"function : ID '(' func_parameters ')'",
"func_parameters : func_parameters ',' func_parameter",
"func_parameters : func_parameter",
"func_parameter : scalar_type ID",
"func_parameter :",
"expression :",
"expression : expr_14",
"expr_14 : expr_12 '=' expr_14",
"expr_14 : expr_12",
"expr_12 : expr_12 OR expr_11",
"expr_12 : expr_11",
"expr_11 : expr_11 AND expr_10",
"expr_11 : expr_10",
"expr_10 : expr_10 '|' expr_9",
"expr_10 : expr_9",
"expr_9 : expr_9 '^' expr_8",
"expr_9 : expr_8",
"expr_8 : expr_8 '&' expr_7",
"expr_8 : expr_7",
"expr_7 : expr_7 EQUAL expr_6",
"expr_7 : expr_7 NOT_EQUAL expr_6",
"expr_7 : expr_6",
"expr_6 : expr_6 '<' expr_5",
"expr_6 : expr_6 '>' expr_5",
"expr_6 : expr_6 GE expr_5",
"expr_6 : expr_6 LE expr_5",
"expr_6 : expr_5",
"expr_5 : expr_5 RS expr_4",
"expr_5 : expr_5 LS expr_4",
"expr_5 : expr_4",
"expr_4 : expr_4 '+' expr_3",
"expr_4 : expr_4 '-' expr_3",
"expr_4 : expr_3",
"expr_3 : expr_3 '*' expr_2",
"expr_3 : expr_3 '/' expr_2",
"expr_3 : expr_3 '%' expr_2",
"expr_3 : expr_2",
"expr_2 : INC expr_2",
"expr_2 : DEC expr_2",
"expr_2 : '+' expr_2",
"expr_2 : '-' expr_2",
"expr_2 : '!' expr_2",
"expr_2 : '~' expr_2",
"expr_2 : '*' expr_2",
"expr_2 : '&' expr_2",
"expr_2 : '(' scalar_type ')' expr_2",
"expr_2 : '(' scalar_type '*' ')' expr_2",
"expr_2 : expr_1",
"expr_1 : expr_1 INC",
"expr_1 : expr_1 DEC",
"expr_1 : expr_1 variable '(' ')'",
"expr_1 : '(' expression ')'",
"expr_1 : expr_1 ID array_shape",
"expr_1 : ID array_shape",
"expr_1 : variable",
"expr_1 : literal",
"expr_1 : Null",
"variable : ID",
"literal : INT",
"literal : FLOAT",
"literal : CHAR",
"literal : STR",
"statements : statements statement",
"statements : statement",
"statement : expression ';'",
"statement : if_statement",
"if_statement : IF '(' expression ')' '{' compound_statements '}'",
"if_statement : IF '(' expression ')' '{' compound_statements '}' ELSE '{' compound_statements '}'",
"compound_statements : compound_statements scalar_declaration",
"compound_statements : compound_statements array_declaration",
"compound_statements : statements",
"compound_statements :",

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
#line 414 "parser.y"

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    cerr << s << endl;
    exit(1);
}
#line 845 "y.tab.c"

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
case 1:
#line 75 "parser.y"
	{ cout << yystack.l_mark[0].str; }
#line 1518 "y.tab.c"
break;
case 2:
#line 78 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1526 "y.tab.c"
break;
case 3:
#line 82 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1531 "y.tab.c"
break;
case 4:
#line 83 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1536 "y.tab.c"
break;
case 5:
#line 87 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1541 "y.tab.c"
break;
case 6:
#line 88 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1546 "y.tab.c"
break;
case 7:
#line 89 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1551 "y.tab.c"
break;
case 8:
#line 93 "parser.y"
	{
        string *s = new string("<scalar_decl>" + string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + ";</scalar_decl>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1559 "y.tab.c"
break;
case 9:
#line 98 "parser.y"
	{ 
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1567 "y.tab.c"
break;
case 10:
#line 102 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1572 "y.tab.c"
break;
case 11:
#line 104 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-2].str) + ',' + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1580 "y.tab.c"
break;
case 12:
#line 108 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1585 "y.tab.c"
break;
case 13:
#line 110 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-2].str) + "=" + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1593 "y.tab.c"
break;
case 14:
#line 114 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1598 "y.tab.c"
break;
case 15:
#line 117 "parser.y"
	{
        string *s = new string("<array_decl>" + string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + ";</array_decl>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1606 "y.tab.c"
break;
case 16:
#line 122 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-2].str) + ',' +  string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1614 "y.tab.c"
break;
case 17:
#line 126 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1619 "y.tab.c"
break;
case 18:
#line 128 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-5].str) + string(yystack.l_mark[-4].str) + "=" + "{" + string(yystack.l_mark[-1].str) + "}");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1627 "y.tab.c"
break;
case 19:
#line 132 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1635 "y.tab.c"
break;
case 20:
#line 137 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-3].str) + "[" + string(yystack.l_mark[-1].str) + "]");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1643 "y.tab.c"
break;
case 21:
#line 141 "parser.y"
	{
        string *s = new string("[" + string(yystack.l_mark[-1].str) + "]");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1651 "y.tab.c"
break;
case 22:
#line 146 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-2].str) + ',' + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1659 "y.tab.c"
break;
case 23:
#line 150 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1664 "y.tab.c"
break;
case 24:
#line 152 "parser.y"
	{
        string *s = new string("{" + string(yystack.l_mark[-1].str) + "}");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1672 "y.tab.c"
break;
case 25:
#line 156 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1677 "y.tab.c"
break;
case 26:
#line 159 "parser.y"
	{
        string *s = new string("<func_decl>" + string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + ";</func_decl>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1685 "y.tab.c"
break;
case 27:
#line 165 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-3].str) + "(" + string(yystack.l_mark[-1].str) + ")");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1693 "y.tab.c"
break;
case 28:
#line 170 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-2].str) + "," + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1701 "y.tab.c"
break;
case 29:
#line 174 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1706 "y.tab.c"
break;
case 30:
#line 176 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1714 "y.tab.c"
break;
case 31:
#line 180 "parser.y"
	{ yyval.str = strdup(""); }
#line 1719 "y.tab.c"
break;
case 32:
#line 185 "parser.y"
	{ yyval.str = strdup(""); }
#line 1724 "y.tab.c"
break;
case 33:
#line 186 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1729 "y.tab.c"
break;
case 34:
#line 188 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "=" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1737 "y.tab.c"
break;
case 35:
#line 192 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1742 "y.tab.c"
break;
case 36:
#line 194 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "||" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1750 "y.tab.c"
break;
case 37:
#line 198 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1755 "y.tab.c"
break;
case 38:
#line 200 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "&&" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1763 "y.tab.c"
break;
case 39:
#line 204 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1768 "y.tab.c"
break;
case 40:
#line 206 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "|" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1776 "y.tab.c"
break;
case 41:
#line 210 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1781 "y.tab.c"
break;
case 42:
#line 212 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "^" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1789 "y.tab.c"
break;
case 43:
#line 216 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1794 "y.tab.c"
break;
case 44:
#line 218 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "&" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1802 "y.tab.c"
break;
case 45:
#line 222 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1807 "y.tab.c"
break;
case 46:
#line 224 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "==" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1815 "y.tab.c"
break;
case 47:
#line 228 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "!=" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1823 "y.tab.c"
break;
case 48:
#line 232 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1828 "y.tab.c"
break;
case 49:
#line 234 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "<" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1836 "y.tab.c"
break;
case 50:
#line 238 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + ">" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1844 "y.tab.c"
break;
case 51:
#line 242 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + ">=" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1852 "y.tab.c"
break;
case 52:
#line 246 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "<=" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1860 "y.tab.c"
break;
case 53:
#line 250 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1865 "y.tab.c"
break;
case 54:
#line 252 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + ">>" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1873 "y.tab.c"
break;
case 55:
#line 256 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "<<" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1881 "y.tab.c"
break;
case 56:
#line 260 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1886 "y.tab.c"
break;
case 57:
#line 262 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "+" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1894 "y.tab.c"
break;
case 58:
#line 266 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "-" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1902 "y.tab.c"
break;
case 59:
#line 270 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1907 "y.tab.c"
break;
case 60:
#line 272 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "*" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1915 "y.tab.c"
break;
case 61:
#line 276 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "/" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1923 "y.tab.c"
break;
case 62:
#line 280 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + "%" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1931 "y.tab.c"
break;
case 63:
#line 284 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 1936 "y.tab.c"
break;
case 64:
#line 286 "parser.y"
	{
        string *s = new string("<expr>++" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1944 "y.tab.c"
break;
case 65:
#line 290 "parser.y"
	{
        string *s = new string("<expr>--" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1952 "y.tab.c"
break;
case 66:
#line 294 "parser.y"
	{
        string *s = new string("<expr>+" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1960 "y.tab.c"
break;
case 67:
#line 298 "parser.y"
	{
        string *s = new string("<expr>-" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1968 "y.tab.c"
break;
case 68:
#line 302 "parser.y"
	{
        string *s = new string("<expr>!" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1976 "y.tab.c"
break;
case 69:
#line 306 "parser.y"
	{
        string *s = new string("<expr>~" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1984 "y.tab.c"
break;
case 70:
#line 310 "parser.y"
	{
        string *s = new string("<expr>*" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 1992 "y.tab.c"
break;
case 71:
#line 314 "parser.y"
	{
        string *s = new string("<expr>&" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2000 "y.tab.c"
break;
case 72:
#line 318 "parser.y"
	{
        string *s = new string("<expr>(" + string(yystack.l_mark[-2].str) + ")" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2008 "y.tab.c"
break;
case 73:
#line 322 "parser.y"
	{
        string *s = new string("<expr>(" + string(yystack.l_mark[-3].str) + "*)" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2016 "y.tab.c"
break;
case 74:
#line 326 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 2021 "y.tab.c"
break;
case 75:
#line 328 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-1].str) + "++" + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2029 "y.tab.c"
break;
case 76:
#line 332 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-1].str) + "--" + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2037 "y.tab.c"
break;
case 77:
#line 336 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-3].str) + string(yystack.l_mark[-2].str) + "()" + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2045 "y.tab.c"
break;
case 78:
#line 340 "parser.y"
	{
        string *s = new string("<expr>(" + string(yystack.l_mark[-1].str) + ")</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2053 "y.tab.c"
break;
case 79:
#line 344 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2061 "y.tab.c"
break;
case 80:
#line 348 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2069 "y.tab.c"
break;
case 81:
#line 352 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 2074 "y.tab.c"
break;
case 82:
#line 353 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 2079 "y.tab.c"
break;
case 83:
#line 354 "parser.y"
	{ yyval.str = strdup("<expr>0</expr>"); }
#line 2084 "y.tab.c"
break;
case 84:
#line 356 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2092 "y.tab.c"
break;
case 85:
#line 361 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2100 "y.tab.c"
break;
case 86:
#line 365 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2108 "y.tab.c"
break;
case 87:
#line 369 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2116 "y.tab.c"
break;
case 88:
#line 373 "parser.y"
	{
        string *s = new string("<expr>" + string(yystack.l_mark[0].str) + "</expr>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2124 "y.tab.c"
break;
case 89:
#line 379 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2132 "y.tab.c"
break;
case 90:
#line 383 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 2137 "y.tab.c"
break;
case 91:
#line 385 "parser.y"
	{
        string *s = new string("<stmt>" + string(yystack.l_mark[-1].str) + ";</stmt>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2145 "y.tab.c"
break;
case 92:
#line 389 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 2150 "y.tab.c"
break;
case 93:
#line 392 "parser.y"
	{
        string *s = new string("<stmt>if(" + string(yystack.l_mark[-4].str) + "){" + string(yystack.l_mark[-1].str) + "}</stmt>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2158 "y.tab.c"
break;
case 94:
#line 396 "parser.y"
	{
        string *s = new string("<stmt>if(" + string(yystack.l_mark[-8].str) + "){" + string(yystack.l_mark[-5].str) + "}else{" + string(yystack.l_mark[-1].str) + "}</stmt>");
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2166 "y.tab.c"
break;
case 95:
#line 403 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2174 "y.tab.c"
break;
case 96:
#line 407 "parser.y"
	{
        string *s = new string(string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str));
        yyval.str = strdup(s -> c_str()); delete s;
    }
#line 2182 "y.tab.c"
break;
case 97:
#line 411 "parser.y"
	{ yyval.str = yystack.l_mark[0].str; }
#line 2187 "y.tab.c"
break;
case 98:
#line 412 "parser.y"
	{ yyval.str = strdup(""); }
#line 2192 "y.tab.c"
break;
#line 2194 "y.tab.c"
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
