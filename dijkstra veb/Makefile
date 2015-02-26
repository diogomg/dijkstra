CC = gcc

all: compile clean run

compile: main.c graph.c veb.c list.c
	$(CC) -g -fprofile-arcs -ftest-coverage main.c dijkstra.c graph.c veb.c list.c -lm -o dijkstra

valgrind: compile clean
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: test.c graph.c veb.c list.c
	$(CC) -fprofile-arcs -ftest-coverage -g test.c dijkstra.c graph.c veb.c list.c -lm -o test
	./test

coverage: dijkstra.gcda
	gcov dijkstra.gcda

run:
	./dijkstra

clean: *.o
	rm *.o *.gc*
