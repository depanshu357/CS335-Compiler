compile: parser.y lexer.l
		bison -t -d -v parser.y 
		flex lexer.l
		g++ parser.tab.c lex.yy.c -o main
clean:	
		rm -f main parser.tab.c parser.tab.h lex.yy.c *.dot *.png graph.pdf *.output *.csv *.o 

run: outputfile
	./outputfile

outputfile: $(file)
	@echo $(file)
	gcc -g -no-pie $(file) -o outputfile 

temporary: 
		bison -t -d -v parser.y 
		flex lexer.l
		g++ parser.tab.c lex.yy.c -o main
		./main --input=./testcases/temp3.py --output=temp3
		gcc -g -no-pie ./output/temp3.s -o temp3.o
		./temp3.o


# clean:
# 	rm -f outputfile
