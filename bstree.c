#include "bstree.h"

struct bstree *create_bstree()
{
    struct bstree *new_tree;

    new_tree = malloc(sizeof(struct bstree));
    new_tree->root = NULL;

    return new_tree;
}

static void insert_bstree_from_node(struct bintree_node **node, void *data, 
        int (*cmp_fptr)(void *, void *))
{
    if (*node == NULL)
    {
        insert_bintree(node, data);
        return; 
    }

    if (cmp_fptr(data, (*node)->data) <= 0)
    {
        insert_bstree_from_node(&((*node)->left), data, cmp_fptr);
    }
    else
    {
        insert_bstree_from_node(&((*node)->right), data, cmp_fptr);
    }
}

void insert_bstree(struct bstree *tree, void *data, int (*cmp_fptr)(void *, void *))
{
    insert_bstree_from_node(&(tree->root), data, cmp_fptr);
}

void inorder_bstree(struct bstree *tree, void (*fptr)(void *))
{
    inorder_bintree(tree->root, fptr);
}

void preorder_bstree(struct bstree *tree, void (*fptr)(void *))
{
    preorder_bintree(tree->root, fptr);
}

void postorder_bstree(struct bstree *tree, void (*fptr)(void *))
{
    postorder_bintree(tree->root, fptr);
}

void level_order_bstree(struct bstree *tree, void (*fptr)(void *))
{
    level_order_bintree(tree->root, fptr);
}

int bstree_height(struct bstree *tree)
{
    return bintree_height(tree->root);
}
