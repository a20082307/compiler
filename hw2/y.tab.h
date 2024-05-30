#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
