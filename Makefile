compile: parser.y lexer.l
		bison -t -d -v -Wcounterexamples parser.y 
		flex lexer.l
		g++ parser.tab.c lex.yy.c -o main

clean:	
		rm -f main parser.tab.c parser.tab.h lex.yy.c *.dot *.png graph.pdf *.output