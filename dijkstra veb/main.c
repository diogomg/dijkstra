#include <stdio.h>
#include "dijkstra.h"

int main(){

    int n_ver, n_edge, i, from, to, cost, source, u=INF;
    float f_cost;
    vEB *veb = NULL;
    char opt;

    scanf("%d%d", &n_ver, &n_edge);
    source = 0;
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));
    initGraph(vertices, n_ver, source);
    veb = vEB_tree_insert(veb, 0, source, u);
    for(i=0; i<n_edge; i++){
        scanf("%d%d%f", &from, &to, &f_cost);
        cost = (int)(f_cost);
        insertEdge(vertices, from, to, cost);
        insertEdge(vertices, to, from, cost);
    }
    dijkstra(vertices, &veb, u);
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
