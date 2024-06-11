#ifndef _yy_defines_h_
#define _yy_defines_h_

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
