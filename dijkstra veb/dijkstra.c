#include "dijkstra.h"

void dijkstra(vertex *vertices, vEB **V, int u){
	int min_vertex, old_cost, new_cost, adjacent;
	listNode *node;
	while(*V){
		min_vertex = vEB_tree_extract_min(V, u);
		edge *aux = vertices[min_vertex].adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = vertices[min_vertex].cost + aux->cost;
			if(new_cost < vertices[adjacent].cost){
				if(vertices[adjacent].cost == INF){
					node = &(vertices[adjacent].node);
					node->next = node;
				    node->prev = node;
					*V = vEB_tree_add(*V, new_cost, node, u);
				}
				else{
					old_cost = vertices[adjacent].cost;
					vEB_tree_decrease_key(V, old_cost, new_cost, &(vertices[adjacent].node), u);
				}
				vertices[adjacent].predecessor = min_vertex;
				vertices[adjacent].cost = new_cost;
			}
			aux = aux->next;
		}
	}
}
