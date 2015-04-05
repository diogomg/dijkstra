#ifndef _AVL_H
#define _AVL_H

#define MIN(x,y)        ((x) < (y) ? (x) : (y))
#define MAX(x,y)        ((x) < (y) ? (y) : (x))

typedef int keyType;

typedef struct avl_node {
    struct avl_node *parent;
    struct avl_node *left;
    struct avl_node *right;
    struct avl_node *next;
    struct avl_node *prev;
    keyType key;
    signed char balance;
    unsigned char leader;
}avl_node;

typedef struct avl_tree {
    struct avl_node *root;
    struct avl_node *first;
    struct avl_node *last;
    unsigned int count;
}avl_tree;

#define AVL_DUP    1
#define AVL_DUP_NO 0

void avl_init(struct avl_tree *);
struct avl_node *avl_find(struct avl_tree *, keyType);
int avl_insert(struct avl_tree *, struct avl_node *, int);
void avl_delete(struct avl_tree *, struct avl_node *);

struct avl_node *
avl_walk_first(struct avl_tree *tree);

struct avl_node *
avl_walk_last(struct avl_tree *tree);

struct avl_node *
avl_walk_next(struct avl_node *node);

struct avl_node *
avl_walk_prev(struct avl_node *node);

#endif /* _AVL_H */
