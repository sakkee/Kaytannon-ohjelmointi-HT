makefile : program.o tiedosto.o tietorakenne.o funktio.o
	gcc -o makefile program.o tiedosto.o tietorakenne.o funktio.o

program.o : program.c 
	gcc -c program.c

tiedosto.o : tiedosto.c tiedosto.h
	gcc -c tiedosto.c

tietorakenne.o : tietorakenne.c tietorakenne.h
	gcc -c tietorakenne.c
    
funktio.o : funktio.c funktio.h
	gcc -c funktio.c