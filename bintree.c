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

void level_order(struct bintree_node *node, void (*fptr)(struct bintree_node *))
{

}

int bintree_height(struct bintree_node *node)
{
    return 0;
}

void print_bintree_int(struct bintree_node *node)
{
    printf("%d ", *(int *)node->data);
}
