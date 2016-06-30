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

void inorder(struct bintree_node *node, void (*fptr)(struct bintree_node *))
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left, fptr);
    fptr(node);
    inorder(node->right, fptr);
}

void preorder(struct bintree_node *node, void (*fptr)(struct bintree_node *))
{
    if (node == NULL)
    {
        return;
    }

    fptr(node);
    preorder(node->left, fptr);
    preorder(node->right, fptr);
}

void postorder(struct bintree_node *node, void (*fptr)(struct bintree_node *))
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left, fptr);
    postorder(node->right, fptr);
    fptr(node);
}

static void level_order_at_level(struct bintree_node *node, 
        void (*fptr)(struct bintree_node *), int height)
{
    if (node == NULL)
    {
        return;
    }

    if (height == 1)
    {
        fptr(node);
    }
    else 
    {
        level_order_at_level(node->left, fptr, height - 1);
        level_order_at_level(node->right, fptr, height - 1);
    }    
}

void level_order(struct bintree_node *node, void (*fptr)(struct bintree_node *))
{
    int height;
    int i;

    height = bintree_height(node);

    for (i = 1; i <= height; i++)
    {
        level_order_at_level(node, fptr, i);       
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

void print_bintree_int(struct bintree_node *node)
{
    printf("%d ", *(int *)node->data);
}
