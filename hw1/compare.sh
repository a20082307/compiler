#!/bin/bash

flex scanner.l
g++ -o scanner lex.yy.c -lfl
diff <(./scanner < ${1:-test.c}) <(golden_scanner < ${1:-test.c}) -y -W 100