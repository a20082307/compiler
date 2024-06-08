%{
extern "C" int yylex();
#include <iostream>
#include <cstring>
#include <sstream>
#include "y.tab.h"

using namespace std;

bool committing = false;

char* word(char* str, int len, int str_or_char = 0) {
    // cout << "received: '" << str << "' length: " << len << endl;
    char* wanted = new char[len + 1]();

    if (str_or_char == 0) {
        str = strtok(str, " \t");
        while (str != NULL) {
            strcat(wanted, str);
            str = strtok(NULL, " \t");
        }
    }
    else if (str_or_char == 1) {
        for (int i = 0; i < len; i ++) {
            if (str[i] != '"')
                continue;

            strcat(wanted, &str[i]);
            break;
        }
    }
    else {
        for (int i = 0; i < len; i ++) {
            if (str[i] != '\'')
                continue;
            
            strcat(wanted, &str[i]);
            break;
        }
    }

    strcat(wanted, "\0");    
    // cout << "pass to parser: '" << wanted << "'" << endl;
    return wanted;
}
%}

id (("_"|[[:alpha:]]+)+)(([[:alnum:]]|"_")*)
int ([[:digit:]])+
float [0-9]+"."[0-9]*|[0-9]*"."[0-9]+
valid_char "\'"(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?"|"\\"([0-7]{1,3})|"\\x"([[:digit:]]|[a-fA-F])+|"\\u"([[:digit:]]|[a-fA-F]){4,4}|"\\U"([[:digit:]]|[a-fA-F]){8,8})"\'"
string "\""([^"\\"]|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?"|"\\"([0-7]{1,3})|"\\x"([[:digit:]]|[a-fA-F])+|"\\u"([[:digit:]]|[a-fA-F]){4,4}|"\\U"([[:digit:]]|[a-fA-F]){8,8})*"\""
space " "|\t
type "const"|"signed"|"unsigned"|"long"|"short"|"int"|"char"|"float"|"double"|"void"

%x COMMENT_START
comment "//".*
src_on ([ ]|\t)*("#pragma")([ ]|\t)*("source")([ ]|\t)*("on")
src_off ([ ]|\t)*("#pragma")([ ]|\t)*("source")([ ]|\t)*("off")
token_on ([ ]|\t)*("#pragma")([ ]|\t)*("token")([ ]|\t)*("on")
token_off ([ ]|\t)*("#pragma")([ ]|\t)*("token")([ ]|\t)*("off")
%%

{space}*";"{space}* { yylval.str = word(yytext, yyleng); return ';'; }
\n {}
{space} {}

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
{space}*"*"{space}* { yylval.str = word(yytext, yyleng); return '*'; }
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
{space}*"return"{space}* { yylval.str = word(yytext, yyleng); return RETURN; }
{space}*"break"{space}* { yylval.str = word(yytext, yyleng); return BREAK; }
{space}*"continue"{space}* { yylval.str = word(yytext, yyleng); return CONTINUE; }

{space}*":"{space}* { yylval.str = word(yytext, yyleng); return ':'; }

{space}*{int}{space}* { sprintf(yylval.str, "%d", atoi(word(yytext, yyleng))); return INT; }
{space}*{float}{space}* { sprintf(yylval.str, "%f", atof(word(yytext, yyleng))); return FLOAT; }
{space}*{valid_char} { yylval.str = word(yytext, yyleng, 2); return CHAR; }
{space}*{string} { yylval.str = word(yytext, yyleng, 1); return STR; }
{space}*"NULL"{space}* { yylval.str = word(yytext, yyleng); return Null; }

{space}*{type}{space}* { yylval.str = word(yytext, yyleng); return TYPE; }
{space}*","{space}* { yylval.str = word(yytext, yyleng); return ','; }
{space}*{id}{space}* { yylval.str = word(yytext, yyleng); return ID; }

"/*" {
    BEGIN COMMENT_START;
    committing = true;
}
<COMMENT_START>"*/" {
    if (committing) {
        BEGIN 0;
        committing = false;
    }
}
<COMMENT_START>\n {}
<COMMENT_START>. {}
{space}*{comment}{space}* {}
{src_on} {}
{src_off} {}
{token_on} {}
{token_off} {}
%%