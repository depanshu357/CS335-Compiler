# flex ./lexer.l
# g++  -o lexer lex.yy.c -lfl
# ./lexer < input.txt > result.txt

# bison -t -d -v test.y -Wcounterexamples
# flex lexer_for_parser.l
# g++ lex.yy.c test.tab.c 
# ./a.out < input.txt > result.txt

bison -t -d -v test.y
flex lexer_for_parser.l
g++ test.tab.c lex.yy.c -o main
