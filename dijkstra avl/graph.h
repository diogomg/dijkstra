#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "avl.h"

#define INF 100000

typedef struct edge{
    int head_vertex, cost;
    struct edge *next;
} edge;

typedef struct vertex{
    avl_node cand_tree_node;
    int key;
    struct vertex *predecessor;
    edge *adjacent;
} vertex;

void freeGraph(vertex *vertices, int size);

void initGraph(vertex *vertices, int size, int source);

void showVertices(vertex *vertices, int size);

void showEdges(vertex *vertices, int size);

void printGraph(vertex *vertices, int size);

void removeEdge(vertex *vertices, int tail, int head);

void insertEdge(vertex *vertices, int tail, int head, int cost);

int checkEdge(vertex *vertices, int tail, int head);

#endif
