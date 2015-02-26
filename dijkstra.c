#include "dijkstra.h"

void dijkstra(vertex *vertices, vEB **V, int u){
	int min_vertex, old_cost, new_cost, adjacent;
	while(*V){
		min_vertex = vEB_tree_extract_min(V, u);
		edge *aux = vertices[min_vertex].adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = vertices[min_vertex].cost + aux->cost;
			if(new_cost < vertices[adjacent].cost){
				if(vertices[adjacent].cost == INF){
					*V = vEB_tree_insert(*V, new_cost, adjacent, u);
				}
				else{
					old_cost = vertices[adjacent].cost;
					vEB_tree_decrease_key(V, old_cost, new_cost, adjacent, u);
				}
				vertices[adjacent].predecessor = min_vertex;
				vertices[adjacent].cost = new_cost;
			}
			aux = aux->next;
		}
	}
}
