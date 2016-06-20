#include "stack.h"

static struct stack_node *create_stack_node(void *data)
{
    struct stack_node *new_node;

    new_node = malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

bool is_empty_stack(struct stack_node *root)
{
    return !root;
}

void push(struct stack_node **root, void *new_data)
{
    struct stack_node *new_node;

    new_node = create_stack_node(new_data);
    new_node->next = *root;
    *root = new_node;
}

void *pop(struct stack_node **root)
{
    struct stack_node *temp = *root;
    void *data;

    if (is_empty_stack(*root))
    {
        printf("The stack is empty\n");
        return NULL;
    }

    *root = (*root)->next;
    data = temp->data;
    free(temp);

    return data;   
}

void *peek(struct stack_node *root)
{
    if (!is_empty_stack(root))
    {
        return root->data;
    }

    printf("The stack is empty\n");
    return NULL;
}
