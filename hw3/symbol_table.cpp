#include <iostream>
#include <string>
#include <cstring>
#include "symbol_table.hpp"
using namespace std;

#define MAX_TABLE_SIZE 5000

ostream& operator<<(ostream& os, const Symbol& s) {
    os << endl << "==============================" << endl;
    os << "Name: " << s.name << endl;
    os << "Type: " << s.type << endl;
    os << "Scope: " << s.scope << endl;
    os << "Offset: " << s.offset << endl;
    os << "ID: " << s.id << endl;
    os << "Variant: " << s.variant << endl;
    os << "Total args: " << s.total_args << endl;
    os << "Total locals: " << s.total_locals << endl;
    os << "Mode: " << s.mode << endl;
    os << "==============================" << endl;

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
    this -> scope = s.scope;
    this -> offset = s.offset;
    this -> id = s.id;
    this -> variant = s.variant;
    this -> total_args = s.total_args;
    this -> total_locals = s.total_locals;
    this -> mode = s.mode;
}

void Table::init() {
    risc_V.open("codegen.S");
    if (!risc_V.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return;
    }

    this -> entry = new Symbol[MAX_TABLE_SIZE];
    this -> append(new Symbol("digitalWrite", Type::Function, -1));
    this -> append(new Symbol("delay", Type::Function, -1));
    this -> append(new Symbol("HIGH", Type::Int, -1));
    this -> append(new Symbol("LOW", Type::Int, -1));
    // cout << "Table initialized \n";
}

bool Table::isExist(string name) {
    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) 
        if (this -> entry[i].name == name && this -> entry[i].scope != -1)
            return true;
    
    return false;
}

void Table::append(Symbol *s) {
    // cout << "Appending symbol " << *s << endl;
    if (this -> cur_symbol_num >= MAX_TABLE_SIZE)
        cerr << "Symbol table full" << endl;
    else {
        this -> entry[this -> cur_symbol_num] = *s;
        this -> cur_symbol_num ++;
        // cout << this -> entry[this -> cur_symbol_num - 1] << " ";
    }
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

void Table::enter_new_scope() {
    this -> cur_scope ++;
}

void Table::leave_cur_scope() {
    if (this -> cur_symbol_num == 0)
        return;
    
    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) {
        if (this -> entry[i].scope < this -> cur_scope) {
            this -> cur_symbol_num = i;
            this -> cur_scope --;
            return;
        }
    }

    this -> cur_symbol_num = 0;
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

void Table::codegen_func_header(string name) {
    risc_V << name << ":" << endl;
    risc_V << "    //BEGIN FUNCTION PROLOGUE" << endl;
    risc_V << "    sw s0, -4(sp)      // save sp" << endl;
    risc_V << "    addi sp, sp ,-4" << endl;
    risc_V << "    addi s0, sp, 0     // set new sp" << endl;
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
    risc_V << "    //END FUNCTION PROLOGUE" << endl << endl;
}

void Table::codegen_func_footer() {
    risc_V << endl << "    //BEGIN FUNCTION EPILOGUE" << endl;
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
    risc_V << "    //END FUNCTION EPILOGUE" << endl << endl;
    risc_V << "    jalr zero, 0(ra)   // return" << endl;
}

void generate_code(string code) {
    risc_V << code;
}

void generate_digitalWrite_code(int pin, string value) {
    generate_code("\n    // digitalWrite(" + to_string(pin) + ", " + value + ")\n");
    generate_code("    addi sp, sp, -4\n");
    generate_code("    sw ra, 0(sp)\n");
    generate_code("    li a0, " + to_string(pin) + "\n");
    generate_code("    li a1, " + to_string(int(value == "HIGH")) + "\n");
    generate_code("    jal ra, digitalWrite\n");
    generate_code("    lw ra, 0(sp)\n");
    generate_code("    addi sp, sp, 4\n\n");
}

void generate_delay_code(int ms) {
    generate_code("\n    // delay(" + to_string(ms) + ")\n");
    generate_code("    addi sp, sp, -4\n");
    generate_code("    sw ra, 0(sp)\n");
    generate_code("    li a0, " + to_string(ms) + "\n");
    generate_code("    jal ra, delay\n");
    generate_code("    lw ra, 0(sp)\n");
    generate_code("    addi sp, sp, 4\n\n");
}