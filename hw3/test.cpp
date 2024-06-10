#include "symbol_table.hpp"
#include "symbol_table.cpp"

int main() {
    Table t;

    t.append(new Symbol("a", 0, 0));
    t.append(new Symbol("b", 0, 0));
    t.append(new Symbol("c", 0, 0));

    cout << t.find("b") << endl;
    cout << t.find("d") << endl;
}