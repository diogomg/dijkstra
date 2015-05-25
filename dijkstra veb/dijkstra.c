#include "dijkstra.h"

void dijkstra(vertex *vertices, vEB **V, int u){
	int old_cost, new_cost, adjacent;
	vertex *min_vertex, *adjacent_vertex;
	listNode *node;
	while(*V){
		min_vertex = vEB_tree_extract_min(V, u);
		edge *aux = min_vertex->adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = min_vertex->cost + aux->cost;
			adjacent_vertex = &(vertices[adjacent]);
			if(new_cost < adjacent_vertex->cost){
				if(adjacent_vertex->cost == INF){
					node = &(adjacent_vertex->node);
					node->next = node;
				    node->prev = node;
					*V = vEB_tree_add(*V, new_cost, node, u);
				}
				else{
					old_cost = adjacent_vertex->cost;
					vEB_tree_decrease_key(V, old_cost, new_cost, &(adjacent_vertex->node), u);
				}
				adjacent_vertex->predecessor = min_vertex->node.key;
				adjacent_vertex->cost = new_cost;
			}
			aux = aux->next;
		}
	}
	// vEB_tree_print(*V);
}
