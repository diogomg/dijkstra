CC = gcc

all: compile run

compile: main.c graph.c avl.c
	$(CC) main.c dijkstra.c graph.c avl.c -o dijkstra

valgrind: compile
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: test.c graph.c avl.c
	$(CC) -fprofile-arcs -ftest-coverage -g test.c dijkstra.c graph.c avl.c -o test
	./test

coverage: dijkstra.gcda
	gcov dijkstra.gcda

run:
	./dijkstra

clean: *.o
	rm *.o *.gc*
