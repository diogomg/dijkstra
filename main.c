#include <stdio.h>
#include "dijkstra.h"

int main(){

    int n_ver, n_edge, i, from, to, cost, u=INF;
    vEB *V = NULL;
    char opt;

    scanf("%d%d", &n_ver, &n_edge);
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));
    initGraph(vertices, n_ver);
    V = vEB_tree_insert(V, 0, 1, u);
    for(i=0; i<n_edge; i++){
        scanf("%d%d%d", &from, &to, &cost);
        insertEdge(vertices, from, to, cost);
    }
    dijkstra(vertices, &V, u);
    for (i=0; i<n_ver; i++) {
        if (vertices[i].cost != INF)
            printf("%d\n", vertices[i].cost);
        else
            printf("INFINITY\n");
    }
    freeGraph(vertices, n_ver);
    free(vertices);
    return 0;
}
