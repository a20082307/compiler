#include <iostream>
#include <string>
#include <cstring>
#include "symbol_table.hpp"
using namespace std;

#define MAX_TABLE_SIZE 5000

// ===================== Symbol =====================  //
ostream& operator<<(ostream& os, const Symbol& s) {
    os << "==============================" << endl;
    os << "Name: " << s.name << endl;
    os << "Type: " << s.type << endl;
    os << "Args: ";
    for (int i = 0; i < s.total_args; i ++)
        os << s.args[i] << ", ";
    os << endl;
    os << "Scope: " << s.scope << endl;
    os << "Offset: " << s.offset << endl;
    os << "Value: " << s.value << endl;
    os << "Total args: " << s.total_args << endl;
    os << "Total locals: " << s.total_locals << endl;
    os << "Total labels: " << s.total_labels << endl;
    os << "Mode: " << s.mode << endl;
    os << "==============================";

    return os;
}

bool Symbol::operator==(const Symbol& s) const {
    bool isScopeEqual = this -> scope == s.scope;
    bool isNameEqual = this -> name == s.name;

    return isScopeEqual && isNameEqual;
}

void Symbol::operator=(const Symbol& s) {
    this -> name = s.name;
    this -> type = s.type;
    this -> args = s.args;
    this -> scope = s.scope;
    this -> offset = s.offset;
    this -> value = s.value;
    this -> total_args = s.total_args;
    this -> total_locals = s.total_locals;
    this -> total_labels = s.total_labels;
    this -> mode = s.mode;
}
// =================================================  //

// ===================== Table =====================  //
void Table::init() {
    risc_V.open("codegen.S");
    if (!risc_V.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return;
    }

    this -> entry = new Symbol[MAX_TABLE_SIZE];
    this -> append(new Symbol("digitalWrite", Type::Function, -2));
    this -> append(new Symbol("delay", Type::Function, -2));
    this -> append(new Symbol("HIGH", Type::Int, -2));
    this -> append(new Symbol("LOW", Type::Int, -2));

    // cout << "Table initialized \n";
}

bool Table::append(Symbol *s) {
    // cout << "Appending symbol " << *s << endl;
    if (this -> cur_symbol_num >= MAX_TABLE_SIZE) {
        cerr << "Symbol table full" << endl;
        return false;
    }
    else {
        for (int i = this -> cur_symbol_num - 1; i >= 0; i --) 
            if (this -> entry[i] == *s)
                return false;
        
        this -> entry[this -> cur_symbol_num] = *s;
        this -> cur_symbol_num ++;
        return true;
        // cout << this -> top() << endl;
    }
}

void Table::enter_new_scope() {
    this -> cur_scope ++;
}

void Table::leave_cur_scope() {
    if (this -> cur_symbol_num == 0)
        return;
    
    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) {
        if (this -> entry[i].scope < this -> cur_scope) {
            this -> cur_symbol_num = i + 1;
            this -> cur_scope --;
            return;
        }
    }
}

void Table::setup_parameters(string name) {
    int index = this -> find(name);
    if (index == -1) {
        cerr << "Error: function not found" << endl;
        return;
    }

    this -> entry[index].type = Type::Function;
    this -> entry[index].total_args = this -> cur_symbol_num - index - 1; 
    for (int i = this -> cur_symbol_num - 1, j = this -> entry[index].total_args; i > index; i --, j --) {
        this -> entry[i].scope = this -> cur_scope;
        this -> entry[i].offset = j;
        this -> entry[i].mode = Mode::Argument;
    }
}

bool Table::isExist(string name) {
    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) 
        if (this -> entry[i].name == name && this -> entry[i].scope != -1)
            return true;
    
    return false;
}


int Table::find(string name) {
    if (this -> cur_symbol_num == 0)
        return -1;

    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) 
        if (this -> entry[i].name == name && this -> entry[i].scope != -1)
            return i;
        else if (this -> entry[i].name == name && this -> entry[i].scope == -1)
            return -2;

    return -1;
}

string Table::calculate(string left, char op, string right) {
    if (op == '=') {
        string value;
        
        char type = right[0];
        switch (type) {
            case '@': {
                bool isArray = right.find(",") != string::npos;
                
                if (!isArray) {
                    string right_name = right.substr(1);
                    int index = this -> find(right_name);
                    value = this -> entry[index].value;
                }
                else {
                    string right_name = right.substr(1, right.find(",") - 1);
                    int index = this -> find(right_name);
                    int arr_index = atoi(right.substr(right.find(",") + 1).c_str());
                    value = this -> entry[index].args[arr_index];
                }
            }
                break;

            case '&': {
                string right_name = right.substr(1);
                int index = this -> find(right_name);
                value = to_string(index);
            }
                break;

            case '*': {
                string right_name = right.substr(1);
                int index = this -> find(right_name);
                int pointed_index = atoi((this -> entry[index].value).c_str());
                value = this -> entry[pointed_index].value;
            }
                break;

            default:
                value = right;
                break;
        }

        type = left[0];
        switch (type) {
            case '@': {
                bool isArray = left.find(",") != string::npos;

                if (!isArray) {
                    string left_name = left.substr(1);
                    int index = this -> find(left_name);
                    this -> entry[index].value = value;
                    // cout << "Assign ID: " << this -> entry[index] << endl;
                }
                else {
                    string left_name = left.substr(1, left.find(",") - 1);
                    int index = this -> find(left_name);
                    int arr_index = atoi(left.substr(left.find(",") + 1).c_str());
                    this -> entry[index].set_args(arr_index, value);
                }
            }
                break;

            case '*': {
                string left_name = left.substr(1);
                int index = this -> find(left_name);
                int pointed_index = atoi((this -> entry[index].value).c_str());
                this -> entry[pointed_index].value = value;
                // cout << "Assign Pointer: " << this -> entry[pointed_index] << endl;
            }
                break;

            default: 
                break;
        }

        return "";
    }

    int left_value, right_value;

    // "@" means ID
    // "*" means pointer
    // Otherwise, it is a number

    // Find the value of left operand
    char type = left[0];
    switch (type) {
        case '@': {
            bool isArray = left.find(",") != string::npos;

            if (!isArray) {
                string left_name = left.substr(1);
                int index = this -> find(left_name);
                left_value = atoi((this -> entry[index].value).c_str());
            }
            else {
                string left_name = left.substr(1, left.find(",") - 1);
                int index = this -> find(left_name);
                int arr_index = atoi(left.substr(left.find(",") + 1).c_str());
                left_value = atoi(this -> entry[index].args[arr_index].c_str());
            }
        }
            break;

        case '*': {
            string left_name = left.substr(1);
            int index = this -> find(left_name);
            int pointed_index = atoi((this -> entry[index].value).c_str());
            left_value = atoi((this -> entry[pointed_index].value).c_str());
        }
            break;

        default:
            left_value = atoi(left.c_str());
            break;
    }

    type = right[0];
    switch (type) {
        case '@': {
            bool isArray = right.find(",") != string::npos;

            if (!isArray) {
                string right_name = right.substr(1);
                int index = this -> find(right_name);
                right_value = atoi(this -> entry[index].value.c_str());
            }
            else {
                string right_name = right.substr(1, right.find(",") - 1);
                int index = this -> find(right_name);
                int arr_index = atoi(right.substr(right.find(",") + 1).c_str());
                right_value = atoi(this -> entry[index].args[arr_index].c_str());
            }
        }
            break;

        case '*': {
            string right_name = right.substr(1);
            int index = this -> find(right_name);
            int pointed_index = atoi((this -> entry[index].value).c_str());
            right_value = atoi((this -> entry[pointed_index].value).c_str());
        }
            break;

        default:
            right_value = atoi(right.c_str());
            break;
    }

    switch (op) {
        case '+':
            return to_string(left_value + right_value);
        case '-':
            return to_string(left_value - right_value);
        case '*':
            return to_string(left_value * right_value);
        case '/':
            return to_string(left_value / right_value);
        default:
            return "";
    }
}

string Table::comparison(string left, string op, string right) {
    int left_value, right_value;

    string type = left.substr(0, 1);
    if (type == "@") {
        bool isArray = left.find(",") != string::npos;
        if (!isArray) {     // ID
            string left_name = left.substr(1);
            int index = this -> find(left_name);
            left_value = atoi(this -> entry[index].value.c_str());
        }
        else {      // Array
            string left_name = left.substr(1, left.find(",") - 1);
            int index = this -> find(left_name);
            int arr_index = atoi(left.substr(left.find(",") + 1).c_str());
            left_value = atoi(this -> entry[index].args[arr_index].c_str());
        }
        
    }
    else if (type == "*") {     // Pointer
        string left_name = left.substr(1);
        int index = this -> find(left_name);
        int pointed_index = atoi((this -> entry[index].value).c_str());
        left_value = atoi((this -> entry[pointed_index].value).c_str());
    }
    else {      // Number
        left_value = atoi(left.c_str());
    }

    type = right.substr(0, 1);
    if (type == "@") {
        bool isArray = right.find(",") != string::npos;
        if (!isArray) {     // ID
            string right_name = right.substr(1);
            int index = this -> find(right_name);
            right_value = atoi(this -> entry[index].value.c_str());
        }
        else {      // Array
            string right_name = right.substr(1, right.find(",") - 1);
            int index = this -> find(right_name);
            int arr_index = atoi(right.substr(right.find(",") + 1).c_str());
            right_value = atoi(this -> entry[index].args[arr_index].c_str());
        }
    }
    else if (type == "*") {     // Pointer
        string right_name = right.substr(1);
        int index = this -> find(right_name);
        int pointed_index = atoi((this -> entry[index].value).c_str());
        right_value = atoi((this -> entry[pointed_index].value).c_str());
    }
    else {      // Number
        right_value = atoi(right.c_str());
    }

    if (op == "==")
        return to_string((int)left_value == right_value) + ",==," + left + "," + right;
    else if (op == "!=")
        return to_string((int)left_value != right_value) + ",!=," + left + "," + right;
    else if (op == ">")
        return to_string((int)left_value > right_value) + ",>," + left + "," + right;
    else if (op == "<")
        return to_string((int)left_value < right_value) + ",<," + left + "," + right;
    else if (op == ">=")
        return to_string((int)left_value >= right_value) + ",>=," + left + "," + right;
    else if (op == "<=")
        return to_string((int)left_value <= right_value) + ",<=," + left + "," + right;
    else
        return "";
}

Symbol Table::top() {
    return this -> entry[this -> cur_symbol_num - 1];
}
// ===================================================  //

// ===================== Codegen =====================  //
void codegen_func_header(string name) {
    risc_V << name << ":" << endl;
    risc_V << "    // BEGIN FUNCTION PROLOGUE" << endl;
    risc_V << "    sw s0, -4(sp)      // save sp" << endl;
    risc_V << "    addi sp, sp ,-4" << endl;
    risc_V << "    addi s0, sp, 0     // set new fp" << endl;
    risc_V << "    sw sp, -4(s0)" << endl;
    risc_V << "    sw s1, -8(s0)" << endl;
    risc_V << "    sw s2, -12(s0)" << endl;
    risc_V << "    sw s3, -16(s0)" << endl;
    risc_V << "    sw s4, -20(s0)" << endl;
    risc_V << "    sw s5, -24(s0)" << endl;
    risc_V << "    sw s6, -28(s0)" << endl;
    risc_V << "    sw s7, -32(s0)" << endl;
    risc_V << "    sw s8, -36(s0)" << endl;
    risc_V << "    sw s9, -40(s0)" << endl;
    risc_V << "    sw s10, -44(s0)" << endl;
    risc_V << "    sw s11, -48(s0)" << endl;
    risc_V << "    addi sp, s0, -48   // update sp" << endl;
    risc_V << "    // END FUNCTION PROLOGUE" << endl << endl;
}

void codegen_func_footer() {
    risc_V << "    // BEGIN FUNCTION EPILOGUE" << endl;
    risc_V << "    lw s11, -48(s0)" << endl;
    risc_V << "    lw s10, -44(s0)" << endl;
    risc_V << "    lw s9, -40(s0)" << endl;
    risc_V << "    lw s8, -36(s0)" << endl;
    risc_V << "    lw s7, -32(s0)" << endl;
    risc_V << "    lw s6, -28(s0)" << endl;
    risc_V << "    lw s5, -24(s0)" << endl;
    risc_V << "    lw s4, -20(s0)" << endl;
    risc_V << "    lw s3, -16(s0)" << endl;
    risc_V << "    lw s2, -12(s0)" << endl;
    risc_V << "    lw s1, -8(s0)" << endl;
    risc_V << "    lw sp, -4(s0)" << endl;
    risc_V << "    addi sp, sp, 4" << endl;
    risc_V << "    lw s0, -4(sp)" << endl;
    risc_V << "    // END FUNCTION EPILOGUE" << endl << endl;
    risc_V << "    jalr zero, 0(ra)   // return" << endl;
}

void generate_code(string code) {
    risc_V << code << endl;
}

void generate_digitalWrite_code(string pin, string value) {
    risc_V << "    // digitalWrite(" << pin << ", " << value << ")" << endl;
    risc_V << "    addi sp, sp, -4" << endl;
    risc_V << "    sw ra, 0(sp)" << endl;
    risc_V << "    li a0, " << pin << endl;
    risc_V << "    li a1, " << to_string(int(value == "HIGH")) << endl;
    risc_V << "    jal ra, digitalWrite" << endl;
    risc_V << "    lw ra, 0(sp)" << endl;
    risc_V << "    addi sp, sp, 8" << endl << endl;
}

void generate_delay_code(string ms) {
    risc_V << "    // delay(" << ms << ")" << endl;
    risc_V << "    lw a0, 0(sp)" << endl;
    risc_V << "    addi sp, sp, -4" << endl;
    risc_V << "    sw ra, 0(sp)" << endl;
    risc_V << "    jal ra, delay" << endl;
    risc_V << "    lw ra, 0(sp)" << endl;
    risc_V << "    addi sp, sp, 8" << endl << endl;
}

// =================================================  //