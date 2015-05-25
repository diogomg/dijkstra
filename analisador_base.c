#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){

    int n_ver, n_edge, i, from, to, cost, source, u=INF;
    int snapshots = 0;
    int total_vertices = 0;
    freopen("in.txt","r", stdin);
    n_ver = 355;
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));

    while(scanf("%d", &n_edge) != EOF){
        scanf("%d%d%d", &from, &to, &cost);
        printf("%.2f\n", (float)cost/(float)100);
        /*total_vertices++;
        source = from;
        initGraph(vertices, n_ver);
        insertEdge(vertices, from, to, cost);
        // insertEdge(vertices, to, from, cost);*/
        for(i=1; i<n_edge; i++){
            scanf("%d%d%d", &from, &to, &cost);
            printf("%.2f\n", (float)cost/(float)100);
            /*insertEdge(vertices, from, to, cost);
            // insertEdge(vertices, to, from, cost);
            total_vertices++;
            vertices[from].n_are++;*/
        }
        /*snapshots++;
        for(i=0; i<n_ver; i++){
            if(vertices[i].n_are)
                printf("%d\n", vertices[i].n_are);
        }*/
        //freeGraph(vertices, n_ver);
    }
    free(vertices);
    return 0;
}
