a.out: lex.yy.o y.tab.o ass4_15CS30038_translator.o
	g++ lex.yy.o y.tab.o ass4_15CS30038_translator.o -lfl

ass4_15CS30038_translator.o: ass4_15CS30038_translator.cxx ass4_15CS30038_translator.h
	g++ -c ass4_15CS30038_translator.h
	g++ -c ass4_15CS30038_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass4_15CS30038.l y.tab.h ass4_15CS30038_translator.h
	flex ass4_15CS30038.l

y.tab.c: ass4_15CS30038.y
	yacc -dtv ass4_15CS30038.y -W

y.tab.h: ass4_15CS30038.y
	yacc -dtv ass4_15CS30038.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass4_15CS30038_translator.o y.output a.out ass4_15CS30038_translator.h.gch

test: 
	./a.out < ass4_15CS30038_test1.mm > ass4_15CS30038_quad1.out
	./a.out < ass4_15CS30038_test2.mm > ass4_15CS30038_quad2.out
	./a.out < ass4_15CS30038_test3.mm > ass4_15CS30038_quad3.out
	./a.out < ass4_15CS30038_test4.mm > ass4_15CS30038_quad4.out
	./a.out < ass4_15CS30038_test5.mm > ass4_15CS30038_quad5.out
	

