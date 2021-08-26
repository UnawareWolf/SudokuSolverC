CC = g++
CXXFLAGS = -std=c++11 -ggdb -g

stack.o: stack.c stack.h
	gcc -g -c stack.c

solver.o: stack.h solver.c solver.h
	gcc -g -c solver.c

build: stack.o solver.o
	gcc -g stack.o solver.o -o solver

run: build
	./solver < board_hard.csv