#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>

struct bintree_node
{
    void *data;
    struct bintree_node *left;
    struct bintree_node *right; 
};

struct bintree_node *create_bintree_node(void *data);

void inorder(struct bintree_node *root);
void preorder(struct bintree_node *root);
void postorder(struct bintree_node *root);
void level_order(struct bintree_node *root);

int height(struct bintree_node *root);

#endif
