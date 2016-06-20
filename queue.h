#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct queue
{
    struct queue_node *front;
    struct queue_node *end;
};

struct queue *create_queue();

bool is_empty_queue(struct queue *queue); 
void enqueue(struct queue *queue, void *new_data);
void *dequeue(struct queue *queue);
void *front(struct queue *queue);

#endif
