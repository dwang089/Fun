#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dlist_node 
{
    void *data;
    struct dlist_node *next;
    struct dlist_node *prev;
};

void insert_dlist_front(struct dlist_node **head, void *new_data);
void insert_dlist_end(struct dlist_node **head, void *new_data);
void insert_dlist_after(struct dlist_node *prev_node, void *new_data);

void remove_node(struct dlist_node **head, int position);

int dlist_size(struct dlist_node *head);

void print_dlist_int(void *data);
void print_dlist(struct dlist_node *head, void (* fptr)(void *));

void reverse_dlist(struct dlist_node **head);

#endif
