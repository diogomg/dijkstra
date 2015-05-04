CC = gcc

all: compile run

compile: main.c graph.c heap.c
	$(CC) -g main.c dijkstra.c graph.c heap.c -lm -o dijkstra

valgrind: compile
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: main.c graph.c heap.c
	$(CC) -fprofile-arcs -ftest-coverage -g main.c dijkstra.c graph.c heap.c -lm -o dijkstra

coverage: main.gcda dijkstra.gcda graph.gcda heap.gcda
	gcov main.gcda dijkstra.gcda graph.gcda heap.gcda

run:
	./dijkstra

clean: *.o
	rm *.o *.gc*
