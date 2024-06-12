%{
extern "C"
int yylex();
void yyerror(const char* s);

#include "symbol_table.cpp"
#include "symbol_table.hpp"
using namespace std;

Table* table = new Table();
%}

%union {
    char* str;
}

%start program
%type <str> code

%type <str> func_declaration func_definition 
%type <str> func_symbol parameters
%type <str> types
%token <str> TYPE ID
%token <str> ';' ',' 

%type <str> scalar_declaration scalars scalar
%type <str> array_declaration arrays array array_shape array_content_elements array_content_element

%type <str> expression
%type <str> expr_4 expr_3 expr_2 expr_1
%type <str> variable literal func_call_parameters
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
 
%type <str> compound_statements compound_statement
%type <str> scope_begin scope_end
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

%%
program : code 

code
    : code func_declaration
    | code func_definition
    | func_declaration 
    | func_definition

func_declaration
    : types func_symbol '(' parameters ')' ';' {
        generate_code(".global " + string($2) + "\n");
    }
func_definition
    : types func_symbol '(' parameters ')' compound_statements {
        table -> codegen_func_footer();
    }
func_symbol
    : ID {
        if (table -> isExist(string($1)))
            table -> codegen_func_header(string($1));
        else 
            table -> append(new Symbol(string($1), Type::Function, table -> get_cur_scope()));
    }
parameters
    : parameters ',' types ID
    | parameters ',' types '*' ID
    | types ID
    | types '*' ID
    | { $$ = strdup(""); }

scalar_declaration
    : types scalars ';' 
scalars
    : scalars ',' scalar
    | scalar
scalar
    : '*' ID '=' expression {
        table -> append(new Symbol(string($2), Type::Variable, table -> get_cur_scope()));
    }
    | ID '=' expression {
        table -> append(new Symbol(string($1), Type::Variable, table -> get_cur_scope()));
    }
    | '*' ID {
        table -> append(new Symbol(string($2), Type::Variable, table -> get_cur_scope()));
    }
    | ID {
        table -> append(new Symbol(string($1), Type::Variable, table -> get_cur_scope()));
    }

array_declaration
    : types arrays ';'
arrays
    : arrays ',' array
    | array
array
    : '*' ID array_shape '=' '{' array_content_elements '}' {
        table -> append(new Symbol(string($2), Type::Array, table -> get_cur_scope()));
    }
    | ID array_shape '=' '{' array_content_elements '}' {
        table -> append(new Symbol(string($1), Type::Array, table -> get_cur_scope()));
    }
    | '*' ID array_shape {
        table -> append(new Symbol(string($2), Type::Array, table -> get_cur_scope()));
    }
    | ID array_shape {
        table -> append(new Symbol(string($1), Type::Array, table -> get_cur_scope()));
    }
array_shape
    : array_shape '[' expression ']'
    | '[' expression ']'
array_content_elements
    : array_content_element ',' array_content_elements 
    | array_content_element
array_content_element
    : '{' array_content_elements '}' 
    | expression 

expression
    : expr_4
    | { $$ = strdup(""); }
expr_4
    : expr_4 '+' expr_3 {
        generate_code("    lw t0, 4(sp)\n");
        generate_code("    lw t1, 0(sp)\n");
        generate_code("    add t0, t0, t1\n");
        generate_code("    addi sp, sp, 4\n");
        generate_code("    sw t0, 0(sp)\n");
    }
    | expr_4 '-' expr_3 {
        generate_code("    lw t0, 4(sp)\n");
        generate_code("    lw t1, 0(sp)\n");
        generate_code("    sub t0, t0, t1\n");
        generate_code("    addi sp, sp, 4\n");
        generate_code("    sw t0, 0(sp)\n");
    }
    | expr_3
expr_3
    : expr_3 '*' expr_2 {
        generate_code("    lw t0, 4(sp)\n");
        generate_code("    lw t1, 0(sp)\n");
        generate_code("    mul t0, t0, t1\n");
        generate_code("    addi sp, sp, 4\n");
        generate_code("    sw t0, 0(sp)\n");
    }
    | expr_3 '/' expr_2 {
        generate_code("    lw t0, 4(sp)\n");
        generate_code("    lw t1, 0(sp)\n");
        generate_code("    div t0, t0, t1\n");
        generate_code("    addi sp, sp, 4\n");
        generate_code("    sw t0, 0(sp)\n");
    }
    | expr_2
expr_2
    : expr_1
expr_1
    : '(' expression ')'
    | variable '(' func_call_parameters ')' {
        string *func_name = new string(string($1));

        if (*func_name == "digitalWrite") {
            string *parameters = new string($3);
            int pin = atoi(parameters -> substr(0, parameters -> find(",")).c_str());
            string value = parameters -> substr(parameters -> find(",") + 1);

            generate_digitalWrite_code(pin, value);
        }
        else if (*func_name == "delay") {
            generate_delay_code(atoi($3));
        }
        else if (table -> isExist(*func_name)) {

        }
    }
    | variable { $$ = $1; }
    | literal
    | Null
func_call_parameters
    : func_call_parameters ',' expression {
        string *s = new string(string($1) + "," + string($3));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expression { $$ = $1; }
variable
    : ID {
        string id_name = string($1);
        int index = table -> find(id_name);
        if (index == -1) {
            cerr << "Variable " << id_name << " not declared" << endl;
            exit(1);
        }
        else if (index == -2) {
            $$ = strdup(id_name.c_str());
        }
        else if (index >= 0) {
            int offset = table -> entry[index].get_offset() * (-4) - 48;
            generate_code(id_name + "\n");
            generate_code("    lw t0, " + to_string(offset) + "(sp)\n");
            generate_code("    addi sp, sp, -4\n");
            generate_code("    sw t0, 0(sp)\n");
        }
    }
literal
    : INT {
        generate_code("    li t0, " + string($1) + "\n");
        generate_code("    addi sp, sp, -4\n");
        generate_code("    sw t0, 0(sp)\n");
    }
    | FLOAT
    | CHAR
    | STR

statements
    : statements statement
    | statement
statement
    : expression ';'
    | if_statement
    | switch_statement 
    | while_statement 
    | for_statement 
    | return_statement 
    | break_statement 
    | continue_statement 
    | compound_statements
if_statement
    : IF '(' expression ')' compound_statements 
    | IF '(' expression ')' compound_statements ELSE compound_statements 
switch_statement
    : SWITCH '(' expression ')' '{' switch_cases '}'
switch_cases
    : switch_cases switch_case 
    | switch_case
switch_case
    : CASE expression ':' statements
    | DEFAULT ':' statements 
    | CASE expression ':' 
    | DEFAULT ':'
while_statement
    : WHILE '(' expression ')' statement 
    | DO statement WHILE '(' expression ')' ';'
for_statement
    : FOR '(' for_parameters ')' statement 
for_parameters
    : expression ';' expression ';' expression 
return_statement
    : RETURN expression ';'
break_statement
    : BREAK ';' 
continue_statement
    : CONTINUE ';'
compound_statements
    : scope_begin compound_statement scope_end
    | '{' '}'
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

types
    : types TYPE {
        string *type = new string(string($1) + " " + string($2));
        $$ = strdup(type -> c_str());   delete type;
    }
    | TYPE
scope_begin
    : '{' {
        table -> enter_new_scope();
    }
scope_end
    : '}' {
        table -> leave_cur_scope();
    }

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