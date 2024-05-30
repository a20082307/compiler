#!/bin/bash

flex scanner.l
g++ -o scanner lex.yy.c -lfl
./scanner < ${1:-test.c}