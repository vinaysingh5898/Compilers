a.out: lex.yy.o y.tab.o ass3_15CS30038_parser.o ass3_15CS30038_lexer.o
	gcc lex.yy.o y.tab.o ass3_15CS30038_parser.o -o parser.out -lfl
	gcc lex.yy.o y.tab.o ass3_15CS30038_lexer.o -o lexer.out -lfl

ass3_15CS30038_parser.o: ass3_15CS30038_parser.c
	gcc -c ass3_15CS30038_parser.c

ass3_15CS30038_lexer.o: ass3_15CS30038_lexer.c
	gcc -c ass3_15CS30038_lexer.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.c: ass3_15CS30038.l y.tab.h
	flex ass3_15CS30038.l

y.tab.c: ass3_15CS30038.y
	yacc -dtv ass3_15CS30038.y -W

y.tab.h: ass3_15CS30038.y
	yacc -dtv ass3_15CS30038.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass3_15CS30038_parser.o ass3_15CS30038_lexer.o y.output parser.out lexer.out

test: 
	./lexer.out < ass3_test_1.mm > ass3_test_1_tokens_15CS30038
	./lexer.out < ass3_test_1.mm > ass3_test_2_tokens_15CS30038
	./parser.out < ass3_test_1.mm > ass3_test_1_dr_15CS30038
	./parser.out < ass3_test_2.mm > ass3_test_2_dr_15CS30038
