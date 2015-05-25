#include "dijkstra.h"

void dijkstra(vertex *vertices, heap *root){
	int old_cost, new_cost, adjacent;
	node *min_node, *heap_node;
	vertex *min_vertex, *adjacent_vertex;
	while(root->root_node){
		min_node = heapExtractMin(root);
		min_vertex = (vertex*)min_node;
		edge *aux = min_vertex->adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = min_vertex->heap_node.key + aux->cost;
			adjacent_vertex = &(vertices[adjacent]);
			if(new_cost < adjacent_vertex->heap_node.key){
				if(adjacent_vertex->heap_node.key == INF){
					adjacent_vertex->heap_node.key = new_cost;
					heapInsert(root, &(adjacent_vertex->heap_node));
				}
				else{
					heapDecreaseKey(root, &(adjacent_vertex->heap_node), new_cost);
				}
				adjacent_vertex->predecessor = min_vertex->key;
				adjacent_vertex->heap_node.key = new_cost;
			}
			aux = aux->next;
		}
	}
}
