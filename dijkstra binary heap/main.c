#include <stdio.h>
#include "dijkstra.h"

int main(){

    int n_ver, n_edge, i, from, to, cost, source;
    float f_cost;
    heap *root = heapCreateRoot();

    // freopen("../ger_in.txt","r", stdin);

    n_ver = 20000;
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));

    while(scanf("%d%d", &n_ver, &n_edge) != EOF){
        scanf("%d%d%f", &from, &to, &f_cost);
        cost = (int)(f_cost);
        source = from;
        initGraph(vertices, n_ver, source);
        insertEdge(vertices, from, to, cost);
        // insertEdge(vertices, to, from, cost);

        heapInsert(root, &(vertices[source].heap_node));
        for(i=1; i<n_edge; i++){
            scanf("%d%d%f", &from, &to, &f_cost);
            cost = (int)(f_cost);
            insertEdge(vertices, from, to, cost);
            // insertEdge(vertices, to, from, cost);
        }
        //printGraph(vertices, n_ver);
        dijkstra(vertices, root);
        for (i=0; i<n_ver; i++) {
            if (vertices[i].heap_node.key != INF)
                printf("%d\n", vertices[i].heap_node.key);
            else
                printf("INFINITY\n");
        }
        freeGraph(vertices, n_ver);
    }
    free(vertices);
    free(root);
    return 0;
}
