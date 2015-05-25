#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void initGraph(vertex *vertices, int size){

    int i;
    for(i=0; i<size; i++) {
        vertices[i].adjacent = NULL;
        vertices[i].n_are = 0;
        vertices[i].sum_custo_are = 0;
    }
}

void showEdges(vertex *vertices, int size){

    edge *aux;
    int i;
    for(i=0; i<size; i++){
        aux = vertices[i].adjacent;
        while(aux){
            printf("Edge from %d to %d having %d as cost\n", i, aux->head_vertex, aux->cost);
            aux = aux->next;
        }
    }
}

void printGraph(vertex *vertices, int size){
    int i;
    edge *aux;
    for (i = 0; i < size; i++) {
        aux = vertices[i].adjacent;
        printf("vertex: %d\t n_are: %d\tsum_custo_are: %d\n", i, vertices[i].n_are, vertices[i].sum_custo_are);
        while(aux){
            printf("Edge from %d to %d having %d as cost\n", i, aux->head_vertex, aux->cost);
            aux = aux->next;
        }
    }
}

void insertEdge(vertex *vertices, int tail, int head, int cost){

    edge *new_edge = (edge*)malloc(sizeof(edge));
    new_edge->next = vertices[tail].adjacent;
    new_edge->head_vertex = head;
    new_edge->cost = cost;
    vertices[tail].adjacent = new_edge;
}

void freeGraph(vertex *vertices, int size){

    int i;
    edge *aux, *aux2;
    if(!vertices)
        return;
    for(i=0; i<size; i++){
        aux = vertices[i].adjacent;
        while(aux){
            aux2 = aux->next;
            free(aux);
            aux = aux2;
        }
    }
}
