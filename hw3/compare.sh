#!/bin/bash

flex scanner.l
byacc -d parser.y
g++ -o parser lex.yy.c y.tab.c -lfl
diff <(./parser < ${1:-test.c}) <(./golden_parser_static < ${1:-test.c})