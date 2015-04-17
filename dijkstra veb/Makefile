CC = gcc

all: compile run

compile: main.c graph.c veb.c list.c
	$(CC) main.c dijkstra.c graph.c veb.c list.c -lm -o dijkstra

valgrind: compile
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: main.c graph.c veb.c list.c
	$(CC) -fprofile-arcs -ftest-coverage main.c dijkstra.c graph.c veb.c list.c -lm -o dijkstra

coverage: dijkstra.gcda
	gcov dijkstra.gcda

run:
	./dijkstra

clean: *.o
	rm *.o
