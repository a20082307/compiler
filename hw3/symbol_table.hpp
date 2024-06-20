#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

enum Type {
    Int,
    Variable,
    Pointer,
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
    string value;
    string *args;
    int scope; 
    int offset;
    int type;
    int total_args;
    int total_locals;
    int total_labels;
    int mode;

public:
    Symbol(string name = "", int type = 0, int scope = -1) {
        this -> name = name;
        this -> value = "";
        this -> args = nullptr;
        this -> scope = scope;
        this -> offset = 0;
        this -> type = type;
        this -> total_args = 0;
        this -> total_locals = 0;
        this -> total_labels = 0;
        this -> mode = 0;
    }

    string get_name() { return this -> name; }
    string get_value() { return this -> value; }
    string* get_args() { return this -> args; }
    int get_scope() { return this -> scope; }
    int get_offset() { return this -> offset; }
    int get_type() { return this -> type; }
    int get_total_args() { return this -> total_args; }
    int get_total_locals() { return this -> total_locals; }
    int get_total_labels() { return this -> total_labels; }
    int get_mode() { return this -> mode; }

    void set_name(string n) { this -> name = n; }
    void set_value(string i) { this -> value = i; }
    void set_args(int idx, string arg) { this -> args[idx] = arg; }
    void set_scope(int s) { this -> scope = s; }
    void set_offset(int o) { this -> offset = o; }
    void set_type(Type t) { this -> type = t; }
    void set_total_args(int ta) { this -> total_args = ta; }
    void set_total_locals(int tl) { this -> total_locals = tl; }
    void set_total_labels(int tl) { this -> total_labels = tl; }
    void set_mode(int m) { this -> mode = m; }
    
    void init_args(int n) { 
        this -> args = new string[n]; 
        for (int i = 0; i < n; i++) {
            this -> args[i] = "";
        }    
    }

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
    stack<int> func_index;
    stack<int> cur_label;
    stack<int> cur_new_symbol;

    Table(): entry(NULL), cur_scope(0), cur_symbol_num(0), index(0) {
        init();
    }

    int get_cur_scope() { return this -> cur_scope; }
    int get_cur_symbol_num() { return this -> cur_symbol_num; }

    bool append(Symbol*);
    void enter_new_scope();
    void leave_cur_scope();
    void setup_parameters(string);
    bool isExist(string);
    int find(string);
    string calculate(string, char, string);
    string comparison(string, string, string);
    Symbol top();
};

ofstream risc_V;
void codegen_func_header(string);
void codegen_func_footer();
void generate_code(string);
void generate_digitalWrite_code(string, string);
void generate_delay_code(string);


#endif