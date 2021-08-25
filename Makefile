stack.o: stack.c stack.h
	gcc -c stack.c

solver.o: stack.h solver.c solver.h
	gcc -c solver.c

build: stack.o solver.o
	gcc stack.o solver.o -o solver

run: build
	./solver < board1.csv