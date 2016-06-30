#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

struct bintree_node
{
    void *data;
    struct bintree_node *left;
    struct bintree_node *right; 
};

void insert_bintree(struct bintree_node **node, void *data);

void inorder_bintree(struct bintree_node *node, void (*fptr)(void *));
void preorder_bintree(struct bintree_node *node, void (*fptr)(void *));
void postorder_bintree(struct bintree_node *node, void (*fptr)(void *));
void level_order_bintree(struct bintree_node *node, void (*fptr)(void *));

int bintree_height(struct bintree_node *node);

#endif
