CC = gcc -Wall

all: compile run

compile: main.c graph.c veb.c list.c
	$(CC) -g main.c dijkstra.c graph.c veb.c list.c -lm -o dijkstra

valgrind: compile
	valgrind --tool=memcheck --leak-check=yes -v ./dijkstra

test: main.c graph.c veb.c list.c
	$(CC) -fprofile-arcs -ftest-coverage -g main.c dijkstra.c graph.c veb.c list.c -lm -o dijkstra

coverage: main.gcda dijkstra.gcda graph.gcda veb.gcda list.gcda
	gcov main.gcda dijkstra.gcda graph.gcda veb.gcda list.gcda

run:
	./dijkstra

clean: *.o
	rm *.o
