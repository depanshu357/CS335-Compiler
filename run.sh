# flex ./lexer.l
# g++  -o lexer lex.yy.c -lfl
# ./lexer < input.txt > result.txt

bison -d -t parser.y -Wcounterexamples
flex lexer_for_parser.l
g++ lex.yy.c parser.tab.c 
./a.out < input.txt > result.txt