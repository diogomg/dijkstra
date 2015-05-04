CC = gcc

all: compile run

compile: main.c graph.c avl.c
	$(CC) -g main.c dijkstra.c graph.c avl.c -o dijkstra

valgrind: compile
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: main.c graph.c avl.c
	$(CC) -fprofile-arcs -ftest-coverage -g main.c dijkstra.c graph.c avl.c -o dijkstra

coverage: main.gcda dijkstra.gcda graph.gcda avl.gcda
	gcov main.gcda dijkstra.gcda graph.gcda avl.gcda

run:
	./dijkstra

clean: *.o
	rm *.o *.gc*
