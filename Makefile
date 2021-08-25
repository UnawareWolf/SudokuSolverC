solver.o: solver.c solver.h
	gcc -c solver.c

build: solver.o
	gcc solver.o -o solver

run: build
	./solver < board1.csv