%{
extern "C" int yylex();
#include <iostream>
#include <string>
using namespace std;

bool source = true;
bool token = true;
bool committing = false;

string cur_line = "";
long long int line_number = 0;

string cout_token(string type, char* text, int len) {
    string str = "";
    for (int i = 0; i < len; i ++) 
        str += *(text + i);

    if (token && !type.empty())
        cout << "#" << type << ":" << str << endl;

    return str;
}
%}

keystr for|do|while|break|continue|if|else|return|struct|switch|case|default|void|int|double|float|char|const|signed|unsigned|short|long

macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN

id (("_"|[[:alpha:]]+)+)(([[:alnum:]]|"_")*)

op1 "+"|"-"|"*"|"/"|"%"|"<"|">"|"!"|"="|"&"|"|"|"!"
op2 "++"|"--"|"=="|"&&"|"||"|"<="|">="|"!="

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

semicolon ";"

space [ ]|\t
%%

{space} {
    cur_line += cout_token("", yytext, yyleng);
}
{keystr} {
    cur_line += cout_token("key", yytext, yyleng);
}
{macros} {
    cur_line += cout_token("macro", yytext, yyleng);
}
{id} {
    cur_line += cout_token("id", yytext, yyleng);
}
{op2} {
    cur_line += cout_token("op", yytext, yyleng);
}
{op1} {
    cur_line += cout_token("op", yytext, yyleng);
}
{punc}|{semicolon} {
    cur_line += cout_token("punc", yytext, yyleng);
}
{int} {
    cur_line += cout_token("integer", yytext, yyleng);
}
{float} {
    cur_line += cout_token("float", yytext, yyleng);
}
{valid_char} {
    cur_line += cout_token("char", yytext, yyleng);
}
{string} {
    cur_line += cout_token("string", yytext, yyleng);
}

{src_on} {
    source = true;
    cur_line += cout_token("", yytext, yyleng);
}
{src_off} {
    source = false;
    cur_line += cout_token("", yytext, yyleng);
}
{token_on} {
    token = true;
    cur_line += cout_token("", yytext, yyleng);
}
{token_off} {
    token = false;
    cur_line += cout_token("", yytext, yyleng);
}

"/*" {
    cur_line += cout_token("", yytext, yyleng);
    BEGIN COMMENT_START;
    committing = true;
}
<COMMENT_START>"*/" {
    cur_line += cout_token("", yytext, yyleng);    
    if (committing) {
        BEGIN 0;
        committing = false;
    }
}
<COMMENT_START>\n {
    line_number ++;
    if (source) 
        cout << line_number << ":" << cur_line << endl;
    cur_line = "";
}
<COMMENT_START>. {
    cur_line += cout_token("", yytext, yyleng);
}
{comment} {
    cur_line += cout_token("", yytext, yyleng);
}

\n {
    line_number ++;
    if (source) 
        cout << line_number << ":" << cur_line << endl;
    cur_line = "";
}

%%

int main(int argc, char* argv[]) {
    yylex();
    return 0;
}