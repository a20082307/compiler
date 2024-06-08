#include <iostream>
#include <cstring>
#include "symbol_table.hpp"
using namespace std;

#define MAX_TABLE_SIZE 5000
bool Symbol::operator==(const Symbol& s) const {
    bool isScopeEqual = this -> scope == s.scope;
    bool isNameEqual = this -> name == s.name;

    return isScopeEqual && isNameEqual;
}

void Table::init() {
    this -> entry = new Symbol[MAX_TABLE_SIZE];
    // cout << "Table initialized" << endl;
}

bool Table::isExist(Symbol s) {
    for (int i = this -> cur_symbol_num - 1; i >= 0; i --) 
        if (s == this -> entry[i])
            return true;
    
    return false;
}

void Table::append(Symbol s) {
    if (this -> cur_symbol_num >= MAX_TABLE_SIZE)
        cerr << "Symbol table full" << endl;
    else if (this -> isExist(s))
        cerr << "Symbol already exists" << endl;
    else {
        this -> entry[this -> cur_symbol_num] = s;
        this -> cur_symbol_num ++;
    }
}