#include <iostream>
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
    this -> risc_V.open("codegen.S");
    if (!this -> risc_V.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return;
    }
    this -> risc_V << "test" << endl;

    this -> entry = new Symbol[MAX_TABLE_SIZE];
    // cout << "Table initialized \n";
}

bool Table::isExist(Symbol *s) {
    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) 
        if (*s == this -> entry[i])
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
        if (this -> entry[i].name == name)
            return i;

    return -1;
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

void Table::codegen_func_header() {

}