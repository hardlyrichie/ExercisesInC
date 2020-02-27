trout.o: trout.h trout.c util.h
	gcc -c trout.c

util.o: util.h util.c trout.c
	gcc -c util.c

main.o: main.c util.h trout.h
	gcc -c main.c

trout: trout.o util.o main.c
	gcc -Wall -g -o trout trout.o util.o main.o