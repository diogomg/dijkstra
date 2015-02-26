#include <stdio.h>
#include "dijkstra.h"

int main(){

    int n_ver, n_edge, i, from, to, cost;
    heap *root = heapCreateRoot();

    scanf("%d%d", &n_ver, &n_edge);
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));
    initGraph(vertices, n_ver);
    vertices[0].heap_node = heapInsert(root, 0, 0);
    for(i=0; i<n_edge; i++){
        scanf("%d%d%d", &from, &to, &cost);
        insertEdge(vertices, from, to, cost);
    }
    dijkstra(vertices, root);
    for (i=0; i<n_ver; i++) {
        if (vertices[i].cost != INF)
        printf("%d\n", vertices[i].cost);
        else
        printf("INFINITY\n");
    }
    freeGraph(vertices, n_ver);
    free(vertices);
    free(root);
    return 0;
}
