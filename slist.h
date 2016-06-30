#ifndef SLIST_H
#define SLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct slist_node 
{
    void *data;
    struct slist_node *next;
};

void insert_slist_front(struct slist_node **head, void *new_data);
void insert_slist_end(struct slist_node **head, void *new_data);
void insert_slist_after(struct slist_node *prev_node, void *new_data);

struct slist_node *get_slist_node(struct slist_node *head, void *data, size_t data_size);

void remove_slist_data(struct slist_node **head, void *data, size_t data_size);
void clear_slist(struct slist_node *head);

int slist_size(struct slist_node *head);

void print_slist(struct slist_node *head, void (*print_fptr)(void *));

#endif
