#ifndef BSTREE_H
#define BSTREE_H

#include "bintree.h"

struct bstree 
{
    struct bintree_node *root;
};

struct bstree *create_bstree();
void insert_bstree(struct bstree *tree, void *data, int (*cmp_fptr)(void *, void *));

void inorder_bstree(struct bstree *tree, void (*fptr)(void *));
void preorder_bstree(struct bstree *tree, void (*fptr)(void *));
void postorder_bstree(struct bstree *tree, void (*fptr)(void *));
void level_order_bstree(struct bstree *tree, void (*fptr)(void *));

int bstree_height(struct bstree *tree);

#endif
