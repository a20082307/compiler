%{
extern "C" int yylex();
#include <iostream>
#include <cstring>
#include "y.tab.h"

using namespace std;

char* word(char* str, int len) {
    // cout << "received: '" << str << "' length: " << len << endl;
    str = strtok(str, " \t");
    char* wanted = new char[len + 1]();
    while (str != NULL) {
        strcat(wanted, str);
        str = strtok(NULL, " \t");
    }
    strcat(wanted, "\0");
    cout << "pass to parser: '" << wanted << "'" << endl;
    return wanted;
}
%}

keystr for|do|while|break|continue|if|else|return|struct|switch|case|default|void|int|double|float|char|const|signed|unsigned|short|long

macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN

id (("_"|[[:alpha:]]+)+)(([[:alnum:]]|"_")*)

op1 "+"|"-"|"*"|"/"|"%"|"<"|">"|"!"|"="|"&"|"|"|"~"|"^"|"("|")"|"["|"]"
op2 "++"|"--"|"=="|"&&"|"||"|"<="|">="|"!="|"<<"|">>"

punc ":"|","|"."|"["|"]"|"("|")"|"{"|"}"

int "-"([[:digit:]])+|"+"([[:digit:]])+|([[:digit:]])+

float [0-9]+"."[0-9]*|[0-9]*"."[0-9]+|"-"[0-9]+"."[0-9]*|"-"[0-9]*"."[0-9]+|"+"[0-9]+"."[0-9]*|"+"[0-9]*"."[0-9]+

valid_char "\'"([^"\\"]|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?"|"\\"([0-7]{1,3})|"\\x"([[:digit:]]|[a-fA-F])+|"\\u"([[:digit:]]|[a-fA-F]){4,4}|"\\U"([[:digit:]]|[a-fA-F]){8,8})"\'"

string "\""([^"\\"]|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?"|"\\"([0-7]{1,3})|"\\x"([[:digit:]]|[a-fA-F])+|"\\u"([[:digit:]]|[a-fA-F]){4,4}|"\\U"([[:digit:]]|[a-fA-F]){8,8})*"\""

%x COMMENT_START
comment "//".*


src_on ([ ]|\t)*("#pragma")([ ]|\t)*("source")([ ]|\t)*("on")
src_off ([ ]|\t)*("#pragma")([ ]|\t)*("source")([ ]|\t)*("off")
token_on ([ ]|\t)*("#pragma")([ ]|\t)*("token")([ ]|\t)*("on")
token_off ([ ]|\t)*("#pragma")([ ]|\t)*("token")([ ]|\t)*("off")

space " "|\t

type "const"|"signed"|"unsigned"|"long"|"short"|"int"|"char"|"float"|"double"|"void"

%%

{space}*";"{space}* { yylval.str = word(yytext, yyleng); return ';'; }
\n {}

{space}*"="{space}* { yylval.str = word(yytext, yyleng); return '='; }
{space}*"||"{space}* { yylval.str = word(yytext, yyleng); return OR; }
{space}*"&&"{space}* { yylval.str = word(yytext, yyleng); return AND; }
{space}*"|"{space}* { yylval.str = word(yytext, yyleng); return '|'; }
{space}*"^"{space}* { yylval.str = word(yytext, yyleng); return '^'; }
{space}*"&"{space}* { yylval.str = word(yytext, yyleng); return '&'; }
{space}*"=="{space}* { yylval.str = word(yytext, yyleng); return EQUAL; }
{space}*"!="{space}* { yylval.str = word(yytext, yyleng); return NOT_EQUAL; }
{space}*"<"{space}* { yylval.str = word(yytext, yyleng); return '<'; }
{space}*">"{space}* { yylval.str = word(yytext, yyleng); return '>'; }
{space}*">="{space}* { yylval.str = word(yytext, yyleng); return GE; }
{space}*"<="{space}* { yylval.str = word(yytext, yyleng); return LE; }
{space}*">>"{space}* { yylval.str = word(yytext, yyleng); return RS; }
{space}*"<<"{space}* { yylval.str = word(yytext, yyleng); return LS; }
{space}*"+"{space}* { yylval.str = word(yytext, yyleng); return '+'; }
{space}*"-"{space}* { yylval.str = word(yytext, yyleng); return '-'; }
({space}*)("*")({space}*) { yylval.str = word(yytext, yyleng); return '*'; }
{space}*"/"{space}* { yylval.str = word(yytext, yyleng); return '/'; }
{space}*"%"{space}* { yylval.str = word(yytext, yyleng); return '%'; }
{space}*"++"{space}* { yylval.str = word(yytext, yyleng); return INC; }
{space}*"--"{space}* { yylval.str = word(yytext, yyleng); return DEC; }
{space}*"!"{space}* { yylval.str = word(yytext, yyleng); return '!'; }
{space}*"~"{space}* { yylval.str = word(yytext, yyleng); return '~'; }
{space}*"("{space}* { yylval.str = word(yytext, yyleng); return '('; }
{space}*")"{space}* { yylval.str = word(yytext, yyleng); return ')'; }
{space}*"["{space}* { yylval.str = word(yytext, yyleng); return '['; }
{space}*"]"{space}* { yylval.str = word(yytext, yyleng); return ']'; }
{space}*"{"{space}* { yylval.str = word(yytext, yyleng); return '{'; }
{space}*"}"{space}* { yylval.str = word(yytext, yyleng); return '}'; }

{space}*"if"{space}* { yylval.str = word(yytext, yyleng); return IF; }
{space}*"else"{space}* { yylval.str = word(yytext, yyleng); return ELSE; }
{space}*"switch"{space}* { yylval.str = word(yytext, yyleng); return SWITCH; }
{space}*"case"{space}* { yylval.str = word(yytext, yyleng); return CASE; }
{space}*"default"{space}* { yylval.str = word(yytext, yyleng); return DEFAULT; }
{space}*"while"{space}* { yylval.str = word(yytext, yyleng); return WHILE; }
{space}*"do"{space}* { yylval.str = word(yytext, yyleng); return DO; }
{space}*"for"{space}* { yylval.str = word(yytext, yyleng); return FOR; }

{space}*{int}{space}* { yylval.str = word(yytext, yyleng); return INT; }
{space}*{float}{space}* { yylval.str = word(yytext, yyleng); return FLOAT; }
{space}*{valid_char}{space}* { yylval.str = word(yytext, yyleng); return CHAR; }
{space}*{string}{space}* { yylval.str = word(yytext, yyleng); return STR; }
{space}*"NULL"{space}* { yylval.str = word(yytext, yyleng); return Null; }

{space}*{type}{space}* { yylval.str = word(yytext, yyleng); return TYPE; }
{space}*","{space}* { yylval.str = word(yytext, yyleng); return ','; }
{space}*"*"?{space}*{id} { yylval.str = word(yytext, yyleng); return ID; }


%%