#include "veb.h"

int high(int x, int u){
    return (int)(x/(int)sqrt(u));
}

int low(int x, int u){
    return (x % (int)sqrt(u));
}

vEB* vEB_tree_member(vEB *veb, int x){

    if(!veb)
        return NULL;
    else if(veb->min == x || veb->max == x)
        return veb;
    else{
        if(veb->cluster)
            return vEB_tree_member(veb->cluster[high(x, veb->u)], low(x, veb->u));
        else
            return NULL;
    }
}

void vEB_tree_print(vEB *veb){
    if(veb){
        printf("min: %d\tmax: %d\tu: %d\n",
        veb->min, veb->max, veb->u);
        printInOrder(veb->listMin);
        printInOrder(veb->listMax);
        if(veb->cluster){
            if(veb->cluster){
                int i=0;
                printf("cluster: ");
                for(i = 0; i < sqrt(veb->u); i++){
                    if(veb->cluster[i])
                        printf("%d\t", i);
                }
                printf("\n");
                for(i = 0; i < sqrt(veb->u); i++){
                    if(veb->cluster[i])
                        vEB_tree_print(veb->cluster[i]);
                }
                printf("\n");
            }
            else{
                printf("cluster: 0\n");
            }
        }
    }
}

int vEB_tree_Minimum(vEB *veb){
    return veb->min;
}

vertex* vEB_tree_Minimum_vertex(vEB *veb){
    return (vertex*)(veb->listMin);
}

int vEB_tree_Maximum(vEB *veb){
    return veb->max;
}

vEB* vEB_tree_add(vEB *veb, int x, listNode *list, int u){
    if(!veb){
        veb = (vEB*)malloc(sizeof(vEB));
        veb->min = veb->max = x;
        veb->u = u;
        veb->listMin = veb->listMax = list;
        veb->summary = NULL;
        if(u > 2){
            veb->cluster = (vEB**)calloc(sqrt(u),sizeof(vEB*));
        }
        else{
            veb->cluster = NULL;
        }
        return veb;
    }
    // else if(veb->min < x && x < veb->max){
    //     int high_value = high(x, u), square_of_u = sqrt(u);
    //     if(veb->cluster[high_value] == NULL){
    //         listNode *node = initNode(1);
    //         veb->summary = vEB_tree_add(veb->summary, high_value,  node, square_of_u);
    //     }
    //     veb->cluster[high_value] = vEB_tree_add(veb->cluster[high_value], low(x, u), list, square_of_u);
    // }
    else if(veb->min == x){
        merge(&(veb->listMin), &list);
        if(veb->max == x){
            veb->listMax = veb->listMin;
        }
    }
    else if(veb->max == x){
        merge(&(veb->listMax), &list);
    }
    else{
        if(x < veb->min){
            if(veb->min == veb->max){
                veb->min = x;
                veb->listMin = list;
                return veb;
            }
            int aux = veb->min;
            veb->min = x;
            x = aux;
            listNode *listAux = veb->listMin;
            veb->listMin = list;
            list = listAux;
        }
        else if(x > veb->max){
            int aux = veb->max;
            veb->max = x;
            x = aux;
            listNode *listAux = veb->listMax;
            veb->listMax = list;
            list = listAux;
            if(veb->min == x)
                return veb;
        }
        if(u > 2){
            int high_value = high(x, u), square_of_u = sqrt(u);
            if(veb->cluster[high_value] == NULL){
                listNode *node = initNode(1);
                veb->summary = vEB_tree_add(veb->summary, high_value,  node, square_of_u);
            }
            veb->cluster[high_value] = vEB_tree_add(veb->cluster[high_value], low(x, u), list, square_of_u);
        }
    }
    return veb;
}

vEB* vEB_tree_insert(vEB *veb, int value, int key, int u){
    // veb =  vEB_tree_add(veb, value, key, u);
    return veb;
}


vEB* vEB_tree_delete(vEB *veb, int x, listNode *vertexNode, int u){
    if(veb->min == veb->max){
        if(veb->listMin == NULL || veb->listMax == NULL){
            if(veb->cluster)
                free(veb->cluster);
            free(veb);
            return NULL;
        }
        removeByKey(&(veb->listMin), vertexNode);
        if(veb->listMin != NULL){
            veb->listMax = veb->listMin;
        }
        else{
            if(veb->cluster)
                free(veb->cluster);
            free(veb);
            return NULL;
        }
    }
    // else if(veb->min < x && x < veb->max && veb->listMin && veb->listMax){
    //     int high_value = high(x, u);
    //     int square_value = sqrt(u);
    //     veb->cluster[high_value] = vEB_tree_delete(veb->cluster[high_value], low(x, u), vertexNode, square_value);
    //     if(veb->cluster[high_value] == NULL)
    //         veb->summary = vEB_tree_delete(veb->summary, high_value, NULL, square_value);
    // }
    else if(u == 2){
        if(x == 0){
            if(veb->listMin != NULL){
                removeByKey(&(veb->listMin), vertexNode);
            }
            if(veb->listMin == NULL){
                veb->min = 1;
                veb->listMin = veb->listMax;
            }
        }
        else{
            if(veb->listMax != NULL){
                removeByKey(&(veb->listMax), vertexNode);
            }
            if(veb->listMax == NULL){
                veb->max = 0;
                veb->listMax = veb->listMin;
            }
        }
    }
    else{
        if(x == veb->min){
            if(veb->listMin != NULL){
                removeByKey(&(veb->listMin), vertexNode);
            }
            if(veb->listMin == NULL){
                if(veb->summary){
                    int square_value = sqrt(u);
                    int first_cluster = vEB_tree_Minimum(veb->summary);
                    int new_min = vEB_tree_Minimum(veb->cluster[first_cluster]);
                    veb->min = first_cluster * square_value + new_min;
                    veb->listMin = (veb->cluster[first_cluster])->listMin;
                    (veb->cluster[first_cluster])->listMin = NULL;
                    veb->cluster[first_cluster] =  vEB_tree_delete(veb->cluster[first_cluster], new_min, vertexNode, square_value);
                    if(veb->cluster[first_cluster] == NULL)
                        veb->summary = vEB_tree_delete(veb->summary,   first_cluster, NULL, square_value);
                }
                else{
                    veb->min = veb->max;
                    veb->listMin = veb->listMax;
                }
            }
        }
        else if(x == veb->max){
            if(veb->listMax != NULL){
                removeByKey(&(veb->listMax), vertexNode);
            }
            if(veb->listMax == NULL){
                if(veb->summary){
                    int square_value = sqrt(u);
                    int last_cluster = vEB_tree_Maximum(veb->summary);
                    int new_max = vEB_tree_Maximum(veb->cluster[last_cluster]);
                    veb->max = last_cluster * square_value + new_max;
                    veb->listMax = veb->cluster[last_cluster]->listMax;
                    veb->cluster[last_cluster]->listMax = NULL;
                    veb->cluster[last_cluster] =    vEB_tree_delete(veb->cluster[last_cluster], new_max, vertexNode, square_value);
                    if(veb->cluster[last_cluster] == NULL)
veb->summary = vEB_tree_delete(veb->summary, last_cluster, NULL, square_value);
                }
                else{
                    veb->max = veb->min;
                    veb->listMax = veb->listMin;
                }
            }
        }
        else{
            int high_value = high(x, u);
            int square_value = sqrt(u);
            veb->cluster[high_value] = vEB_tree_delete(veb->cluster[high_value], low(x, u), vertexNode, square_value);
            if(veb->cluster[high_value] == NULL)
                veb->summary = vEB_tree_delete(veb->summary, high_value, NULL, square_value);
        }
    }
    return veb;
}

vertex *vEB_tree_extract_min(vEB **veb, int u){

    if(!*veb)
        return NULL;
    int min_value = vEB_tree_Minimum(*veb);
    vertex *min_vertex = vEB_tree_Minimum_vertex(*veb);
    *veb = vEB_tree_delete(*veb, min_value, (*veb)->listMin, u);
    return min_vertex;
}

int vEB_tree_decrease_key(vEB **veb, int old_cost, int new_cost, listNode *vertexNode, int u){

    if(!*veb)
        return 1;
    *veb = vEB_tree_delete(*veb, old_cost, vertexNode, u);
    vertexNode->next = vertexNode;
    vertexNode->prev = vertexNode;
    *veb = vEB_tree_add(*veb, new_cost, vertexNode, u);
    return 0;
}
