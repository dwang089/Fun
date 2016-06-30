#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack_node
{
    void *data;
    struct stack_node *next;
};

bool is_empty_stack(struct stack_node *root);
void push(struct stack_node **root, void *new_data);
void *pop(struct stack_node **root);
void *peek(struct stack_node *root);
void clear_stack(struct stack_node *root);

#endif
