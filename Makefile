CC = g++
CXXFLAGS = -std=c++11 -ggdb -g

datastructures.o: datastructures.c datastructures.h
	gcc -g -c datastructures.c

solver.o: datastructures.h solver.c solver.h
	gcc -g -c solver.c

build: datastructures.o solver.o
	gcc -g datastructures.o solver.o -o solver

run: build
	./solver < board_hard.csv