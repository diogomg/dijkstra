#ifndef _GRAPH_H
#define _GRAPH_H

#define INF 65536

typedef struct edge{
    int head_vertex, cost;
    struct edge *next;
} edge;

typedef struct vertex{
    int n_are;
    int sum_custo_are;
    edge *adjacent;
} vertex;

void freeGraph(vertex *vertices, int size);

void initGraph(vertex *vertices, int size);

void showEdges(vertex *vertices, int size);

void printGraph(vertex *vertices, int size);

void insertEdge(vertex *vertices, int tail, int head, int cost);

#endif
