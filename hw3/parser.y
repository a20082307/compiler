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
%type <str> array_declaration arrays array array_shape

%type <str> expression
%type <str> expr_14 expr_7 expr_6 expr_4 expr_3 expr_2 expr_1
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
%type <str> if_statement if_body 
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
        generate_code(".global " + string($2));
    }
func_definition
    : types func_symbol '(' parameters ')' {
        table -> cur_new_symbol.push(0);
    } compound_statements {
        codegen_func_footer();
    }
func_symbol
    : ID {
        int index = table -> find(string($1));

        if (index != -1) {
            table -> func_index.emplace(index);
            table -> entry[index].set_total_locals(1);
            codegen_func_header(string($1));
        }
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
        generate_code("    // Pointer definition " + string($2) + "\n");
        bool success_append = table -> append(new Symbol(string($2), Type::Pointer, table -> get_cur_scope()));

        if (!success_append) {
            string id_name = string($2);
            int index = table -> find(id_name);
            int offset = table -> entry[index].get_offset() * (-4) - 48;

            generate_code("    // Assignment with pointer when the pointer is already declared");
            generate_code("    addi t0, sp, " + to_string(offset) + "    // get the address of the pointer");
            generate_code("    lw t0, 0(t0)    // get the pointed address");
            generate_code("    lw t1, 0(sp)    // get the value of the right hand side");
            generate_code("    sw t1, 0(t0)    // store the value into the pointed address");
            generate_code("    addi sp, sp, 4");
            generate_code("");
        }
        else {
            // Set the mode of this new symbol
            int index = table -> get_cur_symbol_num() - 1;
            table -> entry[index].set_mode(Mode::Local);

            // Let the number of local variables in this function increase by 1
            // So that we can calculate the offset of this new symbol
            int cur_func_index = table -> func_index.top();
            int cur_func_locals = table -> entry[cur_func_index].get_total_locals();
            table -> entry[cur_func_index].set_total_locals(cur_func_locals + 1);
            table -> entry[index].set_offset(cur_func_locals);
        }

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();
        table -> cur_new_symbol.push(cur_new_symbol_num + 1);
    }
    | ID '=' expression {
        generate_code("    // Scalar definition " + string($1) + "\n");
        bool success_append = table -> append(new Symbol(string($1), Type::Variable, table -> get_cur_scope()));

        if (!success_append) {  // There is already a symbol with the same name
            string id_name = string($1);
            int index = table -> find(id_name);
            int offset = table -> entry[index].get_offset() * (-4) - 48;

            generate_code("    // Assignment with ID when the ID is already declared");
            generate_code("    addi t0, sp, " + to_string(offset) + "    // get the address of the ID");
            generate_code("    lw t1, 0(sp)    // get the value of the right hand side");
            generate_code("    sw t1, 0(t0)    // store the value into the ID");
            generate_code("    addi sp, sp, 4");
            generate_code("");
        }
        else {
            // Set the mode of this new symbol
            int index = table -> get_cur_symbol_num() - 1;
            table -> entry[index].set_mode(Mode::Local);

            // Let the number of local variables in this function increase by 1
            // So that we can calculate the offset of this new symbol
            int cur_func_index = table -> func_index.top();
            int cur_func_locals = table -> entry[cur_func_index].get_total_locals();
            table -> entry[cur_func_index].set_total_locals(cur_func_locals + 1);
            table -> entry[index].set_offset(cur_func_locals);

            // Set the value of this new symbol to the right-hand side value
            table -> entry[index].set_value(string($3));
        }

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();
        table -> cur_new_symbol.push(cur_new_symbol_num + 1);
    }
    | '*' ID {
        generate_code("    // Pointer declaration " + string($2) + "\n");
        generate_code("    li t0, 0");
        generate_code("    addi sp, sp, -4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");
        table -> append(new Symbol(string($2), Type::Pointer, table -> get_cur_scope()));

        // Set the mode of this new symbol
        int index = table -> get_cur_symbol_num() - 1;
        table -> entry[index].set_mode(Mode::Local);

        // Let the number of local variables in this function increase by 1
        // So that we can calculate the offset of this new symbol
        int cur_func_index = table -> func_index.top();
        int cur_func_locals = table -> entry[cur_func_index].get_total_locals();
        table -> entry[cur_func_index].set_total_locals(cur_func_locals + 1);
        table -> entry[index].set_offset(cur_func_locals);

        // Initialize the value of this new symbol to 0
        table -> entry[index].set_value("0");

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();
        table -> cur_new_symbol.push(cur_new_symbol_num + 1);
    }
    | ID {
        generate_code("    // Scalar declaration " + string($1));
        generate_code("    li t0, 0");
        generate_code("    addi sp, sp, -4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");
        table -> append(new Symbol(string($1), Type::Variable, table -> get_cur_scope()));

        // Set the mode of this new symbol
        int index = table -> get_cur_symbol_num() - 1;
        table -> entry[index].set_mode(Mode::Local);

        // Let the number of local variables in this function increase by 1
        // So that we can calculate the offset of this new symbol
        int cur_func_index = table -> func_index.top();
        int cur_func_locals = table -> entry[cur_func_index].get_total_locals();
        table -> entry[cur_func_index].set_total_locals(cur_func_locals + 1);
        table -> entry[index].set_offset(cur_func_locals);

        // Initialize the value of this new symbol to 0
        table -> entry[index].set_value("0");

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();
        table -> cur_new_symbol.push(cur_new_symbol_num + 1);
    }

array_declaration
    : types arrays ';'
arrays
    : arrays ',' array
    | array
array
    : ID array_shape {
        table -> append(new Symbol(string($1), Type::Array, table -> get_cur_scope()));

        generate_code("    // Array declaration " + string($1) + "[" + string($2) + "]");
        generate_code("    sw x0, 0(sp)");

        int size = atoi(string($2).c_str());
        for (int i = 0; i < size - 1; i ++) {
            generate_code("    addi sp, sp, -4");
            generate_code("    sw x0, 0(sp)");
        }
        generate_code("");

        // Set the mode of this new symbol
        int index = table -> get_cur_symbol_num() - 1;
        table -> entry[index].set_mode(Mode::Local);

        // Let the number of local variables in this function increase by 1
        // So that we can calculate the offset of this new symbol
        int cur_func_index = table -> func_index.top();
        int cur_func_locals = table -> entry[cur_func_index].get_total_locals();
        table -> entry[cur_func_index].set_total_locals(cur_func_locals + size);
        table -> entry[index].set_offset(cur_func_locals);
        
        // Initialize the elements of this new symbol to 0
        table -> entry[index].init_args(size);

        // Set the size of this new symbol
        table -> entry[index].set_total_args(size);
    }
array_shape
    : '[' expression ']' { $$ = $2; }

expression
    : expr_14
    | { $$ = strdup(""); }
expr_14
    : expr_7 '=' expr_14 { cout << string($1) << " = " << string($3) << endl;
        string left_operand = string($1);
        string left_type = left_operand.substr(0, 1);
        string left_name = left_operand.substr(1);
        bool isArray = left_name.find(",") != string::npos;

        if (left_type == "@" && !isArray) {  // left is ID
            int left_index = table -> find(left_name);
            int left_offset = table -> entry[left_index].get_offset() * (-4) - 48;

            generate_code("    // Assignment with ID");
            generate_code("    lw t0, 0(sp)");
            generate_code("    sw t0, " + to_string(left_offset) + "(fp)");
            generate_code("    addi sp, sp, 8");
            generate_code("");
        }
        else if (left_type == "@" && isArray) {  // left is array
            string left_id = left_name.substr(0, left_name.find(","));
            string left_index = left_name.substr(left_name.find(",") + 1);
            string index_type = left_index.substr(0, 1);

            if (index_type == "@") {    // @ID,@ID
                int left_id_index = table -> find(left_id);
                int left_id_offset = table -> entry[left_id_index].get_offset() * (-4) - 48;
                int left_arr_index = table -> find(left_index.substr(1));
                int left_arr_offset = table -> entry[left_arr_index].get_offset() * (-4) - 48;

                generate_code("    // Assignment with array " + left_id + "[" + left_index + "]");
                generate_code("    addi t0, fp, " + to_string(left_id_offset) + "    // get the base address of the array");
                generate_code("    lw t1, " + to_string(left_arr_offset) + "(fp)    // get the value of the index");
                generate_code("    li t2, -4");
                generate_code("    mul t1, t1, t2");
                generate_code("    add t0, t0, t1");
                generate_code("    lw t1, 0(sp)    // get the value of the right hand side");
                generate_code("    sw t1, 0(t0)    // store the value into the array");
                generate_code("    addi sp, sp, 8");
                generate_code("");
                
            }
            else {      // ID[expression]
                int left_id_index = table -> find(left_id);
                int left_id_offset = table -> entry[left_id_index].get_offset() * (-4) - 48;
                int left_arr_index = atoi(left_index.c_str());
                int left_offset = (table -> entry[left_id_index].get_offset() + left_arr_index) * (-4) - 48;

                generate_code("    // Assignment with array " + left_id + "[" + left_index + "]");
                generate_code("    lw t0, 0(sp)");
                generate_code("    sw t0, " + to_string(left_offset) + "(fp)");
                generate_code("    addi sp, sp, 8");
                generate_code("");
            }
        }
        else if (left_type == "*") {  // left is pointer
            int left_index = table -> find(left_name);
            int left_offset = table -> entry[left_index].get_offset() * (-4) - 48;

            generate_code("    // Assignment with pointer");
            generate_code("    lw t0, 0(sp)    // get the value of the right hand side");
            generate_code("    lw t1, " + to_string(left_offset) + "(fp)");
            generate_code("    sw t0, 0(t1)");
            generate_code("    addi sp, sp, 8");
            generate_code("");
        }

        string *s = new string(table -> calculate(string($1), '=', string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_7
expr_7
    : expr_7 EQUAL expr_6 {  // only ID == expression in the testcases
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);
        
        generate_code("    // ID == expression");
        generate_code("    lw t0, 4(sp)    // t0 is the value of the ID");
        generate_code("    lw t1, 0(sp)    // t1 is the value of the expression");
        generate_code("    beq t0, t1, EQUAL_" + to_string(cur_func_labels));
        generate_code("    j NOT_EQUAL_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 1");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("NOT_EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 0");
        generate_code("");
        
        generate_code("continue_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");

        string *s = new string(table -> comparison(string($1), "==", string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_7 NOT_EQUAL expr_6 {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);
        
        generate_code("    // ID == expression");
        generate_code("    lw t0, 4(sp)    // t0 is the value of the ID");
        generate_code("    lw t1, 0(sp)    // t1 is the value of the expression");
        generate_code("    beq t0, t1, EQUAL_" + to_string(cur_func_labels));
        generate_code("    j NOT_EQUAL_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 0");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("NOT_EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 1");
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");

        string *s = new string(table -> comparison(string($1), "!=", string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6
expr_6
    : expr_6 '<' expr_4 {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);

        generate_code("    // Less than");
        generate_code("    lw t0, 4(sp)");
        generate_code("    lw t1, 0(sp)");
        generate_code("    blt t0, t1, LESS_THAN_" + to_string(cur_func_labels));
        generate_code("    j GREATER_THAN_EQUAL_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("LESS_THAN_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 1");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");
        generate_code("GREATER_THAN_EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 0");
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");

        string *s = new string(table -> comparison(string($1), "<", string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 '>' expr_4 {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);

        generate_code("    // Greater than");
        generate_code("    lw t0, 0(sp)");
        generate_code("    lw t1, 4(sp)");
        generate_code("    blt t0, t1, LESS_THAN_" + to_string(cur_func_labels));
        generate_code("    j GREATER_THAN_EQUAL_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("LESS_THAN_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 1");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("GREATER_THAN_EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 0");
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");

        string *s = new string(table -> comparison(string($1), ">", string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 LE expr_4 {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);

        generate_code("    // Less than or equal");
        generate_code("    lw t0, 0(sp)");
        generate_code("    lw t1, 4(sp)");
        generate_code("    bge t0, t1, GREATER_THAN_EQUAL_" + to_string(cur_func_labels));
        generate_code("    j LESS_THAN_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("GREATER_THAN_EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 1");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("LESS_THAN_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 0");
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");

        string *s = new string(table -> comparison(string($1), "<=", string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_6 GE expr_4 {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);

        generate_code("    // Greater than or equal");
        generate_code("    lw t0, 4(sp)");
        generate_code("    lw t1, 0(sp)");
        generate_code("    bge t0, t1, GREATER_THAN_EQUAL_" + to_string(cur_func_labels));
        generate_code("    j LESS_THAN_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("GREATER_THAN_EQUAL_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 1");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("LESS_THAN_" + to_string(cur_func_labels) + ":");
        generate_code("    li t0, 0");
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");

        string *s = new string(table -> comparison(string($1), ">=", string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_4
expr_4
    : expr_4 '+' expr_3 {
        string left_type = string($1).substr(0, 1);
        bool isArray = string($1).find(",") != string::npos;

        if (left_type == "@" && !isArray) {
            string id_name = string($1).substr(1);
            int index = table -> find(id_name);

            if (table -> entry[index].get_type() == Type::Array) {    // left is a pointer points to array[0]
                int offset = table -> entry[index].get_offset() * (-4) - 48;

                string right_type = string($3).substr(0, 1);
                if (right_type == "@") {    // right is ID
                    string right_name = string($3).substr(1);
                    int right_index = table -> find(right_name);
                    int right_offset = table -> entry[right_index].get_offset() * (-4) - 48;

                    generate_code("    // Addition with pointer");
                    generate_code("    addi t0, fp, " + to_string(offset) + "    // get the base address of the array");
                    generate_code("    lw t1, " + to_string(right_offset) + "(fp)    // get the value of the index");
                    generate_code("    li t2, -4");
                    generate_code("    mul t1, t1, t2");
                    generate_code("    add t0, t0, t1");
                    generate_code("    add sp, sp, 4");
                    generate_code("    sw t0, 0(sp)    // store the final address into stack");
                    generate_code("");

                    string *s = new string("@" + id_name + ",@" + right_name);
                    $$ = strdup(s -> c_str()); delete s;
                }
                else {      // right is a number
                    generate_code("    // Addition with pointer");
                    generate_code("    addi t0, fp, " + to_string(offset));
                    generate_code("    addi t0, t0, " + to_string(atoi(string($3).c_str()) * -4));
                    generate_code("    add sp, sp, 4");
                    generate_code("    sw t0, 0(sp)");
                    generate_code("");
                    
                    string *s = new string("@" + string($1).substr(1) + "," + string($3));
                    $$ = strdup(s -> c_str()); delete s;
                }
            }
            else {
                generate_code("    // Addition");
                generate_code("    lw t0, 4(sp)");
                generate_code("    lw t1, 0(sp)");
                generate_code("    add t0, t0, t1");
                generate_code("    addi sp, sp, 4");
                generate_code("    sw t0, 0(sp)");
                generate_code("");

                string *s = new string(table -> calculate(string($1), '+', string($3)));
                $$ = strdup(s -> c_str()); delete s;
            }
        }
        else {
            generate_code("    // Addition");
            generate_code("    lw t0, 4(sp)");
            generate_code("    lw t1, 0(sp)");
            generate_code("    add t0, t0, t1");
            generate_code("    addi sp, sp, 4");
            generate_code("    sw t0, 0(sp)");
            generate_code("");

            string *s = new string(table -> calculate(string($1), '+', string($3)));
            $$ = strdup(s -> c_str()); delete s;
        }
    }
    | expr_4 '-' expr_3 {
        generate_code("    // Subtraction");
        generate_code("    lw t0, 4(sp)");
        generate_code("    lw t1, 0(sp)");
        generate_code("    sub t0, t0, t1");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");

        string *s = new string(table -> calculate(string($1), '-', string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_3
expr_3
    : expr_3 '*' expr_2 {
        generate_code("    // Multiplication");
        generate_code("    lw t0, 4(sp)");
        generate_code("    lw t1, 0(sp)");
        generate_code("    mul t0, t0, t1");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");

        string *s = new string(table -> calculate(string($1), '*', string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_3 '/' expr_2 {
        generate_code("    // Division");
        generate_code("    lw t0, 4(sp)");
        generate_code("    lw t1, 0(sp)");
        generate_code("    div t0, t0, t1");
        generate_code("    addi sp, sp, 4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");

        string *s = new string(table -> calculate(string($1), '/', string($3)));
        $$ = strdup(s -> c_str()); delete s;
    }
    | expr_2
expr_2
    : expr_1
    | '&' ID {
        string id_name = string($2);
        int index = table -> find(id_name);
        int offset = table -> entry[index].get_offset() * (-4) - 48;

        generate_code("    // expression &ID");
        generate_code("    addi t0, fp, " + to_string(offset) + "    // store the memory addr into t0");
        generate_code("    addi sp, sp, -4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");     

        string *s = new string("&" + id_name);
        $$ = strdup(s -> c_str()); delete s;
    }
    | '*' expr_2 {
        bool isArray = string($2).find(",") != string::npos;
        int offset = 0;
        if (!isArray) {
            string id_name = string($2).substr(1);
            int index = table -> find(id_name);
            
            offset = table -> entry[index].get_offset() * (-4) - 48;

            generate_code("    // expression *ID");
            generate_code("    lw t0, " + to_string(offset) + "(fp)    // t0 is the pointed address");
            generate_code("    lw t1, 0(t0)    // t1 is the value pointed by t0");
            generate_code("    sw t1, 0(sp)    // store the value pointed by t0 into stack");
            generate_code("");

            string *s = new string("*" + id_name);
            $$ = strdup(s -> c_str()); delete s;
        }
        else {
            generate_code("    // expression *(ID + expression)");
            generate_code("    lw t0, 0(sp)    // t0 is the memory addr of ID[expression]");
            generate_code("    lw t1, 0(t0)    // t1 is the value pointed by t0");
            generate_code("    sw t1, 0(sp)    // store the value pointed by t0 into stack");
            generate_code("");

            $$ = $2;
        }
    }
    | '-' expr_2 {
        generate_code("    // Negation");
        generate_code("    lw t0, 0(sp)");
        generate_code("    sub t0, x0, t0");
        generate_code("    sw t0, 0(sp)");
        generate_code("");

        if ($2[0] != '@' && $2[0] != '*') {  // $2 is a number
            int value = -1 * atoi($2);
            string *s = new string(to_string(value));
            $$ = strdup(s -> c_str()); delete s;
        }
        else {  // $2 is an ID or a pointer
            string *s = new string("-" + string($2));
            $$ = strdup(s -> c_str()); delete s;
        }
    }
expr_1
    : '(' expression ')' { $$ = $2; }
    | ID '(' func_call_parameters ')' {
        string *func_name = new string(string($1));

        if (*func_name == "digitalWrite") {
            string *parameters = new string($3);
            string pin = (parameters -> substr(0, parameters -> find(",")));
            string value = (parameters -> substr(parameters -> find(",") + 1)).substr(1);

            generate_digitalWrite_code(pin, value);
        }
        else if (*func_name == "delay") {
            generate_delay_code(string($3).substr(1));
        }
        else if (table -> isExist(*func_name)) {

        }
    }
    | variable
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
        int scope = table -> entry[index].get_scope();
        if (index == -1) {
            cerr << "Variable " << id_name << " not declared" << endl;
            exit(1);
        }
        else if (scope == -2) {
            string *s = new string("@" + id_name);
            $$ = strdup(s -> c_str()); delete s;
        }
        else if (scope >= 0) {
            int offset = table -> entry[index].get_offset() * (-4) - 48;
            generate_code("    // expression ID " + id_name);
            generate_code("    lw t0, " + to_string(offset) + "(fp)");
            generate_code("    addi sp, sp, -4");
            generate_code("    sw t0, 0(sp)");
            generate_code("");

            string *s = new string("@" + id_name);
            $$ = strdup(s -> c_str()); delete s;
        }
    }
    | ID '[' expression ']' {
        string id_name = string($1);
        int index = table -> find(id_name);
        int offset = 0;

        string type = string($3).substr(0, 1);
        if (type == "@") {
            string arr_name = string($3).substr(1);
            int arr_index = table -> find(arr_name);
            int arr_offset = table -> entry[arr_index].get_offset() * (-4) - 48;
            int base_offset = table -> entry[index].get_offset() * (-4) - 48;


            generate_code("    // expression ID[expression] " + id_name + "[" + arr_name + "]");
            generate_code("    addi t0, fp, " + to_string(base_offset) + "    // get the base address of " + id_name);
            generate_code("    lw t1, " + to_string(arr_offset) + "(fp)    // get the value of " + arr_name);
            generate_code("    li t2, -4");
            generate_code("    mul t1, t1, t2");
            generate_code("    add t0, t0, t1");
            generate_code("    lw t0, 0(t0)    // get the value of " + id_name + "[" + arr_name + "]");
            generate_code("    sw t0, 0(sp)    // replace the expr with the value of the array element");
            generate_code("");

            string *s = new string("@" + id_name + ",@" + arr_name);
            $$ = strdup(s -> c_str()); delete s;
        }
        else {
            int arr_index = atoi(string($3).c_str());
            offset = (table -> entry[index].get_offset() + arr_index) * (-4) - 48;

            generate_code("    // expression ID[expression] " + id_name + "[" + string($3) + "]");
            generate_code("    lw t0, " + to_string(offset) + "(fp)");
            generate_code("    sw t0, 0(sp)    // replace the expr with the value of the array element");
            generate_code("");

            string *s = new string("@" + id_name + "," + string($3));
            $$ = strdup(s -> c_str()); delete s;
        }

    }
literal
    : INT {
        generate_code("    // expression INT " + string($1));
        generate_code("    li t0, " + string($1));
        generate_code("    addi sp, sp, -4");
        generate_code("    sw t0, 0(sp)");
        generate_code("");

        $$ = $1;
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
    : IF '(' expression ')' {
        int cur_func_index = table -> func_index.top(); 
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);
        table -> cur_label.emplace(cur_func_labels);

        generate_code("    // If statement");
        generate_code("    bne t0, x0, IF_" + to_string(cur_func_labels));
        generate_code("    j ELSE_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("IF_" + to_string(cur_func_labels) + ":");

        table -> cur_new_symbol.push(0);
    } compound_statements if_body 
if_body
    : ELSE {
        int cur_func_labels = table -> cur_label.top();

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();

        generate_code("    addi sp, sp, " + to_string(cur_new_symbol_num * 4) + "    // pop the new symbols");
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        table -> cur_new_symbol.push(0);
        generate_code("ELSE_" + to_string(cur_func_labels) + ":");
    } compound_statements {
        int cur_func_labels = table -> cur_label.top();
        table -> cur_label.pop();

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();

        generate_code("    addi sp, sp, " + to_string(cur_new_symbol_num * 4) + "    // pop the new symbols");
        generate_code("continue_" + to_string(cur_func_labels) + ":");
    }
    | {
        int cur_func_labels = table -> cur_label.top();
        table -> cur_label.pop();

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();

        generate_code("    addi sp, sp, " + to_string(cur_new_symbol_num * 4) + "    // pop the new symbols");
        generate_code("ELSE_" + to_string(cur_func_labels) + ":");
        generate_code("    addi sp, sp, 4");
    }
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
    : WHILE {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);
        table -> cur_label.emplace(cur_func_labels);

        generate_code("    // While statement");
        generate_code("WHILE_" + to_string(cur_func_labels) + ":");
        generate_code("");

        generate_code("CONDITION_" + to_string(cur_func_labels) + ":");

        table -> cur_new_symbol.push(0);
    } '(' expression ')' {
        int cur_func_labels = table -> cur_label.top();

        generate_code("    addi sp, sp, 4");
        generate_code("    bne t0, x0, WHILE_STMT_" + to_string(cur_func_labels));
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("WHILE_STMT_" + to_string(cur_func_labels) + ":");
    } statement {
        int cur_func_labels = table -> cur_label.top();
        table -> cur_label.pop();

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();

        generate_code("    addi sp, sp, " + to_string(cur_new_symbol_num * 4) + "    // pop the new symbols");
        generate_code("    j CONDITION_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
    } 
    | DO statement WHILE '(' expression ')' ';'
for_statement
    : FOR '(' for_parameters ')' statement {
        int cur_func_labels = table -> cur_label.top();
        table -> cur_label.pop();

        int cur_new_symbol_num = table -> cur_new_symbol.top();
        table -> cur_new_symbol.pop();

        generate_code("    addi sp, sp, " + to_string(cur_new_symbol_num * 4) + "    // pop the new symbols");
        generate_code("    j LOOP_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("continue_" + to_string(cur_func_labels) + ":");
    }
for_parameters
    : expression {
        int cur_func_index = table -> func_index.top();
        int cur_func_labels = table -> entry[cur_func_index].get_total_labels();
        table -> entry[cur_func_index].set_total_labels(cur_func_labels + 1);
        table -> cur_label.emplace(cur_func_labels);

        generate_code("    // For statement");
        generate_code("FOR_" + to_string(cur_func_labels) + ":");
        generate_code("");

        generate_code("CONDITION_" + to_string(cur_func_labels) + ":");
    } ';' expression {
        int cur_func_labels = table -> cur_label.top();

        generate_code("    addi sp, sp, 4");
        generate_code("    bne t0, x0, FOR_STMT_" + to_string(cur_func_labels));
        generate_code("    j continue_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("LOOP_" + to_string(cur_func_labels) + ":");
    } ';' expression {
        int cur_func_labels = table -> cur_label.top();

        generate_code("    j CONDITION_" + to_string(cur_func_labels));
        generate_code("");

        generate_code("FOR_STMT_" + to_string(cur_func_labels) + ":");

        table -> cur_new_symbol.push(0);
    }
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
    cerr << "Error: " << s << endl;
    exit(1);
}