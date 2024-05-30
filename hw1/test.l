%{
extern "C" int yylex();
#include <iostream>
#include <string>
using namespace std;
%}

int ("+"|"-"){0,1}[0-9]*
dot "."
%%
{dot} {}
{int} {
    ECHO;
    cout << "." << endl;
}

%%

int main() {
    yylex();
    return 0;
}