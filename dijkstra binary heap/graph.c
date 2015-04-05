#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void initGraph(vertex *vertices, int size, int source){

    int i;
    for(i=0; i<size; i++) {
        vertices[i].predecessor = -1;
        vertices[i].adjacent = NULL;
        vertices[i].key = i;
        vertices[i].heap_node.key = INF;
        vertices[i].heap_node.parent = NULL;
        vertices[i].heap_node.left = NULL;
        vertices[i].heap_node.right = NULL;
    }
    vertices[source].heap_node.key = 0;
}

void showVertices(vertex *vertices, int size){

    int i;
    for(i = 0; i < size; i++){
        printf("vertex: %d\tpredecessor: %d\n", i, vertices[i].predecessor);
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
        printf("vertex: %d\t predecessor: %d\tcost: %d\n", i, vertices[i].predecessor, vertices[i].heap_node.key);
        while(aux){
            printf("Edge from %d to %d having %d as cost\n", i, aux->head_vertex, aux->cost);
            aux = aux->next;
        }
    }
}

void removeEdge(vertex *vertices, int tail, int head){

    edge *aux = vertices[tail].adjacent;
    if(aux->head_vertex == head){
        vertices[tail].adjacent = vertices[tail].adjacent->next;
        free(aux);
    }
    else{
        edge *aux2 = aux->next;
        while(aux2){
            if(aux2->head_vertex == head){
                aux->next = aux2->next;
                free(aux2);
                break;
            }
            aux = aux2;
            aux2 = aux2->next;
        }
    }
}

int checkEdge(vertex *vertices, int tail, int head){

    edge *aux = vertices[tail].adjacent;
    while(aux){
        if(aux->head_vertex == head){
            return aux->cost;
        }
        aux = aux->next;
    }
    return 0;
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
