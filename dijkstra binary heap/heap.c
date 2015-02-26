#include "heap.h"

heap* heapCreateRoot(){
    heap *new_heap = (heap*)malloc(sizeof(heap));
    new_heap->count = 0;
    new_heap->root_node = new_heap->last_node = NULL;
    return new_heap;
}

node* heapCreateNode(keyType key, int vertex){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    new_node->vertex = vertex;
    new_node->parent = new_node->left = new_node->right = NULL;
    return new_node;
}


node* heapFindParentInsertNode(heap *root){
    node *aux = root->last_node;
    unsigned int N = root->count+1;
    if ( (int)(log2(N)) == log2(N) ){
        aux = root->root_node;
        while (aux->left) {
            aux = aux->left;
        }
    }
    else if ( N % 2 == 0){
        while(aux->parent->right == aux)
            aux = aux->parent;
        if(!aux->parent->right)
            return aux->parent;
        aux = aux->parent->right;
        while(aux->left)
            aux = aux->left;
    }
    else{
        aux = aux->parent;
    }
    return aux;
}

void heapDecreaseKey(heap *root, node *heap_node, keyType key){
    heap_node->key = key;
    node *parent = heap_node->parent;
    node *left = heap_node->left;
    node *right = heap_node->right;
    if(!parent)
        return;
    if(parent->key > heap_node->key){
        if(root->last_node == heap_node)
            root->last_node = parent;
    }
    while(parent && (parent->key > heap_node->key)){
        if(parent->left == heap_node){
            heap_node->left = parent;
            heap_node->right = parent->right;
            if(heap_node->right)
                heap_node->right->parent = heap_node;
            heap_node->parent = parent->parent;
            if(heap_node->parent){
                if(heap_node->parent->left == parent)
                    heap_node->parent->left = heap_node;
                else
                    heap_node->parent->right = heap_node;
            }
            else
                root->root_node = heap_node;
        }
        else{
            heap_node->right = parent;
            heap_node->left = parent->left;
            if(heap_node->left)
                heap_node->left->parent = heap_node;
            heap_node->parent = parent->parent;
            if(heap_node->parent){
                if(heap_node->parent->left == parent)
                    heap_node->parent->left = heap_node;
                else
                    heap_node->parent->right = heap_node;
            }
            else
                root->root_node = heap_node;
        }
        parent->left = left;
        parent->right = right;
        parent->parent = heap_node;
        if(left)
            left->parent = parent;
        if(right)
            right->parent = parent;
        parent = heap_node->parent;
        left = heap_node->left;
        right = heap_node->right;
    }
}

node* heapInsert(heap *root, keyType key, int vertex){
    node *new_node, *parent = NULL;
    new_node = heapCreateNode(key, vertex);
    if(!root->count){
        root->root_node = root->last_node = new_node;
        root->count++;
    }
    else{
        parent = heapFindParentInsertNode(root);
        if(parent->left){
            parent->right = new_node;
        }
        else{
            parent->left = new_node;
        }
        new_node->parent = parent;
        root->count++;
        root->last_node = new_node;
        heapDecreaseKey(root, new_node, new_node->key);
    }
    return new_node;
}


void heapSwapLeft(heap *root, node *heap_node){
    node *parent = heap_node->parent;
    node *left = heap_node->left;
    node *right = heap_node->right;

    heap_node->parent = left;
    heap_node->left = left->left;
    if(heap_node->left)
        heap_node->left->parent = heap_node;
    heap_node->right = left->right;
    if(heap_node->right)
        heap_node->right->parent = heap_node;

    left->parent = parent;
    if(parent){
        if(parent->left == heap_node)
            parent->left = left;
        else
            parent->right = left;
    }
    else
        root->root_node = left;
    left->left = heap_node;
    left->right = right;
    if(right)
        right->parent = left;
    if(root->last_node == left)
        root->last_node = heap_node;
}

void heapSwapRight(heap *root, node *heap_node){
    node *parent = heap_node->parent;
    node *left = heap_node->left;
    node *right = heap_node->right;

    heap_node->parent = right;
    heap_node->left = right->left;
    if(heap_node->left)
        heap_node->left->parent = heap_node;
    heap_node->right = right->right;
    if(heap_node->right)
        heap_node->right->parent = heap_node;

    right->parent = parent;
    if(parent){
        if(parent->left == heap_node)
            parent->left = right;
        else
            parent->right = right;
    }
    else
        root->root_node = right;
    right->right = heap_node;
    right->left = left;
    if(left)
        left->parent = right;
    if(root->last_node == right)
        root->last_node = heap_node;
}

void heapIncreseKey(heap *root, node *heap_node, keyType key){
    heap_node->key = key;
    node *parent = heap_node->parent;
    node *left = heap_node->left;
    node *right = heap_node->right;
    if(left && (heap_node->key > left->key)){
        if(right && (heap_node->key > right->key)){
            if(left->key < right->key)
                heapSwapLeft(root, heap_node);
            else
                heapSwapRight(root, heap_node);
        }
        else
            heapSwapLeft(root, heap_node);
        heapIncreseKey(root, heap_node, key);
    }
    else if(right && (heap_node->key > right->key)){
        heapSwapRight(root, heap_node);
        heapIncreseKey(root, heap_node, key);
    }
}

node* heapFindLastNode(heap *root){
    node *aux = root->last_node;
    unsigned int N = root->count+1;
    if ( (int)(log2(N)) == log2(N) ){
        aux = root->root_node;
        while (aux->right) {
            aux = aux->right;
        }
    }
    else if ( N % 2 == 0){
        while(aux->parent->left == aux)
            aux = aux->parent;
        aux = aux->parent->left;
        while(aux->right)
            aux = aux->right;
    }
    return aux;
}

node *heapExtractMin(heap *root){
    node *min_node = root->root_node;
    node *new_min = root->last_node;
    if(!min_node)
        return NULL;
    root->count--;
    if(root->count == 0){
        root->last_node = root->root_node = NULL;
        return min_node;
    }
    if(root->count == 1){
        root->last_node = root->root_node = new_min;
        new_min->parent = NULL;
        return min_node;
    }
    else{
        if(new_min->parent->left == new_min){
            new_min->parent->left = NULL;
            root->last_node = new_min->parent;
            root->last_node = heapFindLastNode(root);
        }
        else{
            new_min->parent->right = NULL;
            root->last_node = new_min->parent->left;
        }
        new_min->left = min_node->left;
        if(new_min->left)
            new_min->left->parent = new_min;
        new_min->right = min_node->right;
        if (new_min->right)
            new_min->right->parent = new_min;
        new_min->parent = NULL;
        root->root_node = new_min;
        heapIncreseKey(root, new_min, new_min->key);
    }
    return min_node;
}

void heapPrint(node *root){
    if(root){
        printf("%d\n", root->key);
        heapPrint(root->left);
        heapPrint(root->right);
    }
}
