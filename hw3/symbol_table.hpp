#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

enum Type {
    Int,
    Variable,
    Array,
    String,
    Function,
};

enum Mode {
    Argument,
    Local,
    Global
};

class Symbol {
friend class Table;
friend ostream& operator<<(ostream&, const Symbol&);

private:
    string name;
    int scope; 
    int offset;
    int id;
    int variant;
    int type;
    int total_args;
    int total_locals;
    int mode;

public:
    Symbol(string name = "", int type = 0, int scope = -1) {
        this -> name = name;
        this -> scope = scope;
        this -> offset = 0;
        this -> id = 0;
        this -> variant = 0;
        this -> type = type;
        this -> total_args = 0;
        this -> total_locals = 0;
        this -> mode = 0;
    }

    string get_name() { return this -> name; }
    int get_scope() { return this -> scope; }
    int get_offset() { return this -> offset; }
    int get_id() { return this -> id; }
    int get_variant() { return this -> variant; }
    int get_type() { return this -> type; }
    int get_total_args() { return this -> total_args; }
    int get_total_locals() { return this -> total_locals; }
    int get_mode() { return this -> mode; }

    void set_name(string n) { this -> name = n; }
    void set_scope(int s) { this -> scope = s; }
    void set_offset(int o) { this -> offset = o; }
    void set_id(int i) { this -> id = i; }
    void set_variant(int v) { this -> variant = v; }
    void set_type(Type t) { this -> type = t; }
    void set_total_args(int ta) { this -> total_args = ta; }
    void set_total_locals(int tl) { this -> total_locals = tl; }
    void set_mode(int m) { this -> mode = m; }
    
    bool operator==(const Symbol& s) const;
    void operator=(const Symbol& s);
};


class Table {
friend void generate_code(string);

private: 
    int cur_scope;
    int cur_symbol_num;
    int index;
    void init();
    
public:
    Symbol* entry;

    Table(): entry(NULL), cur_scope(0), cur_symbol_num(0), index(0) {
        init();
    }

    int get_cur_scope() { return this -> cur_scope; }
    int get_cur_symbol_num() { return this -> cur_symbol_num; }

    void append(Symbol*);
    void enter_new_scope();
    void leave_cur_scope();
    void setup_parameters(string);
    void codegen_func_header(string);
    void codegen_func_footer();
    bool isExist(string);
    int find(string);
};

ofstream risc_V;
void generate_code(string);
void generate_digitalWrite_code(int, string);
void generate_delay_code(int);

#endif