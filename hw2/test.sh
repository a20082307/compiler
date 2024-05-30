#!/bin/bash


flex scanner.l
byacc -d -v parser.y
g++ -o parser lex.yy.c y.tab.c -lfl
./parser < ${1:-test.c}