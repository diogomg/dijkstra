#include <stdio.h>
#include "dijkstra.h"

int main(){

    int n_ver, n_edge, i, from, to, cost, source, u=INF;
    float f_cost;
    vEB *veb = NULL;
    char opt;

    //freopen("../ger_in.txt","r", stdin);
    n_ver = 355;
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));

    while(scanf("%d", &n_edge) != EOF){
        scanf("%d%d%f", &from, &to, &f_cost);
        cost = (int)(f_cost);
        source = from;
        initGraph(vertices, n_ver, source);
        insertEdge(vertices, from, to, cost);
        insertEdge(vertices, to, from, cost);

        (vertices[source].node).prev = (vertices[source].node).next = &(vertices[source].node);
        veb = vEB_tree_add(veb, 0, &(vertices[source].node), u);
        for(i=1; i<n_edge; i++){
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
    }
    free(vertices);
    return 0;
}
