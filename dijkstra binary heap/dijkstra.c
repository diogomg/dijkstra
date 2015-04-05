#include "dijkstra.h"

void dijkstra(vertex *vertices, heap *root){
	int old_cost, new_cost, adjacent;
	node *min_node;
	vertex *min_vertex;
	while(root->root_node){
		min_node = heapExtractMin(root);
		min_vertex = (vertex*)min_node;
		edge *aux = min_vertex->adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = min_vertex->heap_node.key + aux->cost;
			if(new_cost < vertices[adjacent].heap_node.key){
				if(vertices[adjacent].heap_node.key == INF){
					vertices[adjacent].heap_node.key = new_cost;
					heapInsert(root, &(vertices[adjacent].heap_node));
				}
				else{
					heapDecreaseKey(root, &(vertices[adjacent].heap_node), new_cost);
				}
				vertices[adjacent].predecessor = min_vertex->key;
				vertices[adjacent].heap_node.key = new_cost;
			}
			aux = aux->next;
		}
	}
}
