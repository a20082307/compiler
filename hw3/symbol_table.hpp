#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class Symbol {
friend class Table;

private:
    int scope; 
    string name;
    string type;
    string value;

public:
    Symbol(int scope = 0, string name = "", string type = "", string value = ""): 
        scope(scope), name(name), type(type), value(value) {}

    int get_scope() { return this -> scope; }
    string get_name() { return this -> name; }
    string get_type() { return this -> type; }
    string get_value() { return this -> value; }
    
    bool operator==(const Symbol& s) const;
};

class Table {
private: 
    int cur_scope;
    int cur_symbol_num;
    Symbol* entry;

public:
    Table(): entry(NULL), cur_scope(0), cur_symbol_num(0) {}

    int get_cur_scope() { return this -> cur_scope; }
    int get_cur_symbol_num() { return this -> cur_symbol_num; }

    void init();
    bool isExist(Symbol);
    void append(Symbol);
};

#endif