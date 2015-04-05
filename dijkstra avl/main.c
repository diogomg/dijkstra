#include <stdio.h>
#include "dijkstra.h"

int main(){

    int n_ver, n_edge, i, from, to, cost, source;
    float f_cost;

    //freopen("../ger_in.txt","r", stdin);

    struct avl_tree cand_tree;
    avl_init(&cand_tree);

    scanf("%d%d%d", &n_ver, &n_edge, &source);
    vertex *vertices = (vertex*)calloc(n_ver, sizeof(vertex));
    initGraph(vertices, n_ver, source);
    vertices[source].cand_tree_node.key = 0;
    avl_insert(&cand_tree, &(vertices[source].cand_tree_node), AVL_DUP);

    for(i=0; i<n_edge; i++){
        scanf("%d%d%f", &from, &to, &f_cost);
        cost = (int)(f_cost*100);
        insertEdge(vertices, from, to, cost);
        insertEdge(vertices, to, from, cost);
    }
    dijkstra(vertices, &cand_tree);
    for (i=0; i<n_ver; i++) {
        if ((vertices[i].cand_tree_node).key != INF)
            printf("%d\n", vertices[i].cand_tree_node.key);
        else
            printf("INFINITY\n");
    }
    freeGraph(vertices, n_ver);
    free(vertices);
    return 0;
}
