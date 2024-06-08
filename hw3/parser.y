%{
extern "C"
int yylex();
void yyerror(const char* s);

#include <iostream>
#include <cstring>
using namespace std;
%}

%union {
    char* str;
}

%type <str> code
%type <str> declaration
/* %type <str> definition */
%type <str> expression
/* %type <str> statement */

%type <str> expr_14
%type <str> expr_12
%type <str> expr_11
%type <str> expr_10
%type <str> expr_9
%type <str> expr_8
%type <str> expr_7
%type <str> expr_6
%type <str> expr_5
%type <str> expr_4
%type <str> expr_3
%type <str> expr_2
%type <str> expr_1
%type <str> variable
%type <str> literal
%type <str> func_call_parameters
%token <str> '='
%token <str> OR
%token <str> AND
%token <str> '|'
%token <str> '^'
%token <str> '&'
%token <str> EQUAL NOT_EQUAL
%token <str> '<' '>' GE LE
%token <str> RS LS
%token <str> '+' '-'
%token <str> '*' '/' '%'
%token <str> INC DEC '~' '!' '&'
%token <str> '(' ')' '[' ']' '{' '}' Null
%token <str> INT FLOAT CHAR STR

%type <str> scalar_declaration scalar_type scalar_ids scalar_id
%type <str> array_declaration arrays array array_shape array_content_elements array_content_element
%type <str> func_declaration function func_parameters func_parameter
%type <str> compound_statements compound_statement
%token <str> TYPE ID 
%token <str> ';' ',' ' '


%type <str> statements statement
%type <str> if_statement 
%type <str> switch_statement switch_cases switch_case 
%type <str> while_statement
%type <str> for_statement for_parameters
%type <str> return_statement
%type <str> break_statement
%type <str> continue_statement
%token <str> IF ELSE
%token <str> SWITCH CASE DEFAULT
%token <str> WHILE DO
%token <str> FOR
%token <str> RETURN BREAK CONTINUE
%start program
%%
program: code { cout << $1; } 

code
    : code declaration {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | declaration { $$ = $1; }


declaration
    : scalar_declaration { $$ = $1; }
    | array_declaration { $$ = $1; }
    | func_declaration { $$ = $1; }

    
scalar_declaration
    : scalar_type scalar_ids ';' {
        string *s = new string("<scalar_decl>" + string($1) + string($2) + ";</scalar_decl>");
        $$ = strdup(s -> c_str()); delete s;
    }
scalar_type
    : scalar_type TYPE { 
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | TYPE { $$ = $1; }
scalar_ids
    : scalar_ids ',' scalar_id {
        string *s = new string(string($1) + ',' + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | scalar_id { $$ = $1; }
scalar_id
    : ID '=' expression {
        string *s = new string(string($1) + "=" + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | '*' ID '=' expression {
        string *s = new string("*" + string($2) + "=" + string($4));
        $$ = strdup(s -> c_str()); delete s;
    }
    | ID { $$ = $1; }
    | '*' ID {
        string *s = new string("*" + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }

array_declaration
    : scalar_type arrays ';' {
        string *s = new string("<array_decl>" + string($1) + string($2) + ";</array_decl>");
        $$ = strdup(s -> c_str()); delete s;
    }
arrays
    : arrays ',' array {
        string *s = new string(string($1) + ',' +  string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | array { $$ = $1; }
array
    : ID array_shape '=' '{' array_content_elements '}' {
        string *s = new string(string($1) + string($2) + "=" + "{" + string($5) + "}");
        $$ = strdup(s -> c_str()); delete s;
    }
    | ID array_shape {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
array_shape
    : array_shape '[' expression ']' {
        string *s = new string(string($1) + "[" + string($3) + "]");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '[' expression ']' {
        string *s = new string("[" + string($2) + "]");
        $$ = strdup(s -> c_str()); delete s;
    }
array_content_elements
    : array_content_element ',' array_content_elements {
        string *s = new string(string($1) + ',' + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | array_content_element { $$ = $1; }
array_content_element
    : '{' array_content_elements '}' {
        string *s = new string("{" + string($2) + "}");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expression { $$ = $1; }

func_declaration
    : scalar_type function ';' {
        string *s = new string("<func_decl>" + string($1) + string($2) + ";</func_decl>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | scalar_type function compound_statements {
        string *s = new string("<func_def>" + string($1) + string($2) + string($3) + "</func_def>");
        $$ = strdup(s -> c_str()); delete s;
    }
function
    : ID '(' func_parameters ')' {
        string *s = new string(string($1) + "(" + string($3) + ")");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '*' ID '(' func_parameters ')' {
        string *s = new string("*" + string($2) + "(" + string($4) + ")");
        $$ = strdup(s -> c_str()); delete s;
    }
func_parameters
    : func_parameters ',' func_parameter {
        string *s = new string(string($1) + "," + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | func_parameter { $$ = $1; }
func_parameter
    : scalar_type ID {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | scalar_type '*' ID {
        string *s = new string(string($1) + "*" + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | { $$ = strdup(""); }

expression
    : { $$ = strdup(""); }
    | expr_14 { $$ = $1; }
expr_14
    : expr_12 '=' expr_14 {
        string *s = new string("<expr>" + string($1) + "=" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_12 { $$ = $1; }
expr_12
    : expr_12 OR expr_11 {
        string *s = new string("<expr>" + string($1) + "||" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_11 { $$ = $1; }
expr_11
    : expr_11 AND expr_10 {
        string *s = new string("<expr>" + string($1) + "&&" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_10 { $$ = $1; }
expr_10
    : expr_10 '|' expr_9 {
        string *s = new string("<expr>" + string($1) + "|" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_9 { $$ = $1; }
expr_9
    : expr_9 '^' expr_8 {
        string *s = new string("<expr>" + string($1) + "^" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_8 { $$ = $1; }
expr_8
    : expr_8 '&' expr_7 {
        string *s = new string("<expr>" + string($1) + "&" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_7 { $$ = $1; }
expr_7
    : expr_7 EQUAL expr_6 {
        string *s = new string("<expr>" + string($1) + "==" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_7 NOT_EQUAL expr_6 {
        string *s = new string("<expr>" + string($1) + "!=" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 { $$ = $1; }
expr_6
    : expr_6 '<' expr_5 {
        string *s = new string("<expr>" + string($1) + "<" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 '>' expr_5 {
        string *s = new string("<expr>" + string($1) + ">" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 GE expr_5 {
        string *s = new string("<expr>" + string($1) + ">=" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 LE expr_5 {
        string *s = new string("<expr>" + string($1) + "<=" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_5 { $$ = $1; }
expr_5
    : expr_5 RS expr_4 {
        string *s = new string("<expr>" + string($1) + ">>" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_5 LS expr_4 {
        string *s = new string("<expr>" + string($1) + "<<" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_4 { $$ = $1; }
expr_4
    : expr_4 '+' expr_3 {
        string *s = new string("<expr>" + string($1) + "+" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_4 '-' expr_3 {
        string *s = new string("<expr>" + string($1) + "-" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_3 { $$ = $1; }
expr_3
    : expr_3 '*' expr_2 {
        string *s = new string("<expr>" + string($1) + "*" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_3 '/' expr_2 {
        string *s = new string("<expr>" + string($1) + "/" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_3 '%' expr_2 {
        string *s = new string("<expr>" + string($1) + "%" + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_2 { $$ = $1; }
expr_2
    : INC expr_2 {
        string *s = new string("<expr>++" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | DEC expr_2 {
        string *s = new string("<expr>--" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '+' expr_2 {
        string *s = new string("<expr>+" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '-' expr_2 {
        string *s = new string("<expr>-" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '!' expr_2 {
        string *s = new string("<expr>!" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '~' expr_2 {
        string *s = new string("<expr>~" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '*' expr_2 {
        string *s = new string("<expr>*" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '&' expr_2 {
        string *s = new string("<expr>&" + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '(' scalar_type ')' expr_2 {
        string *s = new string("<expr>(" + string($2) + ")" + string($4) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '(' scalar_type '*' ')' expr_2 {
        string *s = new string("<expr>(" + string($2) + "*)" + string($5) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_1 { $$ = $1; }
expr_1
    : expr_1 INC {
        string *s = new string("<expr>" + string($1) + "++" + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_1 DEC {
        string *s = new string("<expr>" + string($1) + "--" + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_1 variable '(' ')' {
        string *s = new string("<expr>" + string($1) + string($2) + "()" + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '(' expression ')' {
        string *s = new string("<expr>(" + string($2) + ")</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_1 ID array_shape {
        string *s = new string("<expr>" + string($1) + string($2) + string($3) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | ID array_shape {
        string *s = new string("<expr>" + string($1) + string($2) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_1 '(' func_call_parameters ')' {
        string *s = new string("<expr>" + string($1) + "(" + string($3) + ")" + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | variable { $$ = $1; }
    | literal { $$ = $1; }
    | Null { $$ = strdup("<expr>0</expr>"); }
func_call_parameters
    : func_call_parameters ',' expression {
        string *s = new string(string($1) + "," + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expression { $$ = $1; }
variable
    : ID {
        string *s = new string("<expr>" + string($1) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
literal
    : INT {
        string *s = new string("<expr>" + string($1) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | FLOAT {
        string *s = new string("<expr>" + string($1) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | CHAR {
        string *s = new string("<expr>" + string($1) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | STR {
        string *s = new string("<expr>" + string($1) + "</expr>");
        $$ = strdup(s -> c_str()); delete s;
    }

statements
    : statements statement {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | statement { $$ = $1; }
statement
    : expression ';' {
        string *s = new string("<stmt>" + string($1) + ";</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | if_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | switch_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | while_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | for_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | return_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | break_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | continue_statement {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }
    | compound_statements {
        string *s = new string("<stmt>" + string($1) + "</stmt>");
        $$ = strdup(s -> c_str()); delete s;
    }

if_statement
    : IF '(' expression ')' compound_statements {
        string *s = new string("if(" + string($3) + ")" + string($5));
        $$ = strdup(s -> c_str()); delete s;
    }
    | IF '(' expression ')' compound_statements ELSE compound_statements {
        string *s = new string("if(" + string($3) + ")" + string($5) + "else" + string($7));
        $$ = strdup(s -> c_str()); delete s;
    }

switch_statement
    : SWITCH '(' expression ')' '{' switch_cases '}' {
        string *s = new string("switch(" + string($3) + "){" + string($6) + "}");
        $$ = strdup(s -> c_str()); delete s;
    }
switch_cases
    : switch_cases switch_case {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | switch_case { $$ = $1; }
switch_case
    : CASE expression ':' statements {
        string *s = new string("case" + string($2) + ":" + string($4));
        $$ = strdup(s -> c_str()); delete s;
    }
    | DEFAULT ':' statements {
        string *s = new string("default:" + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | CASE expression ':' {
        string *s = new string("case" + string($2) + ":");
        $$ = strdup(s -> c_str()); delete s;
    }
    | DEFAULT ':' {
        string *s = new string("default:");
        $$ = strdup(s -> c_str()); delete s;
    }

while_statement
    : WHILE '(' expression ')' statement {
        string *s = new string("while(" + string($3) + ")" + string($5));
        $$ = strdup(s -> c_str()); delete s;
    }
    | DO statement WHILE '(' expression ')' ';' {
        string *s = new string("do" + string($2) + "while(" + string($5) + ");");
        $$ = strdup(s -> c_str()); delete s;
    }

for_statement
    : FOR '(' for_parameters ')' statement {
        string *s = new string("for(" + string($3) + ")" + string($5));
        $$ = strdup(s -> c_str()); delete s;
    }
for_parameters
    : expression ';' expression ';' expression {
        string *s = new string(string($1) + ";" + string($3) + ";" + string($5));
        $$ = strdup(s -> c_str()); delete s;
    }

return_statement
    : RETURN expression ';' {
        string *s = new string("return" + string($2) + ";");
        $$ = strdup(s -> c_str()); delete s;
    }

break_statement
    : BREAK ';' {
        string *s = new string("break;");
        $$ = strdup(s -> c_str()); delete s;
    }

continue_statement
    : CONTINUE ';' {
        string *s = new string("continue;");
        $$ = strdup(s -> c_str()); delete s;
    }

compound_statements
    : '{' compound_statement '}' {
        string *s = new string("{" + string($2) + "}");
        $$ = strdup(s -> c_str()); delete s;
    }
    | '{' '}' {
        string *s = new string("{}");
        $$ = strdup(s -> c_str()); delete s;
    }
compound_statement
    : compound_statement scalar_declaration {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | compound_statement array_declaration {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | compound_statement statement {
        string *s = new string(string($1) + string($2));
        $$ = strdup(s -> c_str()); delete s;
    }
    | scalar_declaration { $$ = $1; }
    | array_declaration { $$ = $1; }
    | statement { $$ = $1; }
%%

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