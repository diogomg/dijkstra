#include "dijkstra.h"

void dijkstra(vertex *vertices, heap *root){
	int min_vertex, old_cost, new_cost, adjacent;
	node *min_node;
	while(root->root_node){
		min_node = heapExtractMin(root);
		min_vertex = min_node->vertex;
		free(min_node);
		vertices[min_vertex].heap_node = NULL;
		edge *aux = vertices[min_vertex].adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = vertices[min_vertex].cost + aux->cost;
			if(new_cost < vertices[adjacent].cost){
				if(!vertices[adjacent].heap_node){
					vertices[adjacent].heap_node = heapInsert(root, new_cost, adjacent);
				}
				else{
					heapDecreaseKey(root, vertices[adjacent].heap_node, new_cost);
				}
				vertices[adjacent].predecessor = min_vertex;
				vertices[adjacent].cost = new_cost;
			}
			aux = aux->next;
		}
	}
}
