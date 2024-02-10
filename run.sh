flex ./lexer.l
g++  -o lexer lex.yy.c -lfl
./lexer < input.txt > result.txt