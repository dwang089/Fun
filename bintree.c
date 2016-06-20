#include "bintree.h"

struct bintree_node *create_bintree_node(void *data)
{
    struct bintree_node *new_node;

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void inorder(struct bintree_node *root)
{

}

void preorder(struct bintree_node *root)
{

}

void postorder(struct bintree_node *root)
{

}

void level_order(struct bintree_node *root)
{

}

int height(struct bintree_node *root)
{
    return 0;
}
