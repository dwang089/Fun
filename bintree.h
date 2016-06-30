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

void inorder_bintree(struct bintree_node *node, void (*fptr)(struct bintree_node *));
void preorder_bintree(struct bintree_node *node, void (*fptr)(struct bintree_node *));
void postorder_bintree(struct bintree_node *node, void (*fptr)(struct bintree_node *));
void level_order_bintree(struct bintree_node *node, void (*fptr)(struct bintree_node *));

int bintree_height(struct bintree_node *node);

void print_bintree_int(struct bintree_node *node);

#endif
