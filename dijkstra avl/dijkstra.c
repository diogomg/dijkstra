#include "dijkstra.h"

void dijkstra(vertex *vertices, avl_tree *cand_tree){
	int old_cost, new_cost, adjacent;
	vertex *min_vertex = NULL, *adjacent_vertex;
	avl_node *min_node;
	while(cand_tree->root){
		min_node = avl_walk_first(cand_tree);
		min_vertex = (vertex*)min_node;
		edge *aux = min_vertex->adjacent;
		while(aux){
			adjacent = aux->head_vertex;
			new_cost = min_vertex->cand_tree_node.key + aux->cost;
			adjacent_vertex = &(vertices[adjacent]);
			if(new_cost < adjacent_vertex->cand_tree_node.key){
				if (adjacent_vertex->cand_tree_node.key < INF) {
					avl_delete(cand_tree, &(adjacent_vertex->cand_tree_node));
				}

				/* re-insert on candidate tree with the better metric */
				adjacent_vertex->cand_tree_node.key = new_cost;
				avl_insert(cand_tree, &(adjacent_vertex->cand_tree_node), AVL_DUP);

				adjacent_vertex->predecessor = min_vertex;
			}
			aux = aux->next;
		}
		avl_delete(cand_tree, min_node);
	}
}
