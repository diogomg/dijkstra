#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef int keyType;

typedef struct node{
    keyType key;
    int vertex;
    struct node *parent, *left, *right;
}node;

typedef struct heap{
    unsigned int count;
    struct node *root_node, *last_node;
}heap;

heap* heapCreateRoot();

node* heapCreateNode(keyType key, int vertex);

node* heapFindParentInsertNode(heap *root);

void heapDecreaseKey(heap *root, node *heap_node, keyType key);

node* heapInsert(heap *root, keyType key, int vertex);

void heapSwapLeft(heap *root, node *heap_node);

void heapSwapRight(heap *root, node *heap_node);

void heapIncreseKey(heap *root, node *heap_node, keyType key);

node* heapFindLastNode(heap *root);

node *heapExtractMin(heap *root);

void heapPrint(node *root);
