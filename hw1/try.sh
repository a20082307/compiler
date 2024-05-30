#!/bin/bash

flex test.l
g++ -o test lex.yy.c -lfl
./test < ${1:-test.c}