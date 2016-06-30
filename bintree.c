#include "bintree.h"

static struct bintree_node *create_bintree_node(void *data)
{
    struct bintree_node *new_node;

    new_node = malloc(sizeof(struct bintree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert_bintree(struct bintree_node **node, void *data)
{
    struct bintree_node *new_node;

    new_node = create_bintree_node(data);
    *node = new_node;
}

void inorder_bintree(struct bintree_node *node, void (*fptr)(void *))
{
    if (node == NULL)
    {
        return;
    }

    inorder_bintree(node->left, fptr);
    fptr(node->data);
    inorder_bintree(node->right, fptr);
}

void preorder_bintree(struct bintree_node *node, void (*fptr)(void *))
{
    if (node == NULL)
    {
        return;
    }

    fptr(node->data);
    preorder_bintree(node->left, fptr);
    preorder_bintree(node->right, fptr);
}

void postorder_bintree(struct bintree_node *node, void (*fptr)(void *))
{
    if (node == NULL)
    {
        return;
    }

    postorder_bintree(node->left, fptr);
    postorder_bintree(node->right, fptr);
    fptr(node->data);
}

static void level_order_bintree_at_level(struct bintree_node *node, 
        void (*fptr)(void *), int height)
{
    if (node == NULL)
    {
        return;
    }

    if (height == 1)
    {
        fptr(node->data);
    }
    else 
    {
        level_order_bintree_at_level(node->left, fptr, height - 1);
        level_order_bintree_at_level(node->right, fptr, height - 1);
    }    
}

void level_order_bintree(struct bintree_node *node, void (*fptr)(void *))
{
    int height;
    int i;

    height = bintree_height(node);

    for (i = 1; i <= height; i++)
    {
        level_order_bintree_at_level(node, fptr, i);       
    } 
}

int bintree_height(struct bintree_node *node)
{
    if (node == NULL)
    {
        return 0;
    }
 
    return ((bintree_height(node->left) + 1) < 
            (bintree_height(node->right) + 1)) ?
        (bintree_height(node->left) + 1) : (bintree_height(node->left) + 1); 
}

