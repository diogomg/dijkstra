CC = gcc

all: compile clean run

compile: main.c graph.c heap.c
	$(CC) main.c dijkstra.c graph.c heap.c -lm -o dijkstra

valgrind: compile clean
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: test.c graph.c heap.c
	$(CC) -fprofile-arcs -ftest-coverage -g test.c dijkstra.c graph.c heap.c -o test
	./test

coverage: dijkstra.gcda
	gcov dijkstra.gcda

run:
	./dijkstra

clean: *.o
	rm *.o *.gc*
