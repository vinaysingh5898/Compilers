a.out: mainPrintInt.o libprintInt.a
	gcc mainPrintInt.o -L. -lprintInt

mainPrintInt.o: mainPrintInt.c myl.h
	gcc -Wall -c mainPrintInt.c

libprintInt.a: ass2_15CS30038.o
	ar -rcs libprintInt.a ass2_15CS30038.o

ass2_15CS30038.o: ass2_15CS30038.c myl.h
	gcc -Wall -c ass2_15CS30038.c

clean:
	rm a.out mainPrintInt.o libprintInt.a ass2_15CS30038.o

