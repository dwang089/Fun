#include "queue.h"

struct queue_node
{
    void *data;
    struct queue_node *next;
};

static struct queue_node *create_queue_node(void *data)
{
    struct queue_node *new_node;

    new_node = malloc(sizeof(struct queue_node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;  
}

struct queue *create_queue()
{
    struct queue *new_queue; 

    new_queue = malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->end = NULL;

    return new_queue;
}

bool is_empty_queue(struct queue *queue)
{
    return !(queue->front);   
}

void enqueue(struct queue *queue, void *new_data)
{
    struct queue_node *new_node;

    new_node = create_queue_node(new_data);

    if (!is_empty_queue(queue))
    {
        queue->end->next = new_node;
    }
    else
    {
        queue->front = new_node;    
    }
        
    queue->end = new_node;
}

void *dequeue(struct queue *queue)
{
    struct queue_node *temp = queue->front;
    void *data;

    if (is_empty_queue(queue))
    {
        printf("The queue is empty\n");
        return NULL;
    }

    if (temp->next == NULL)
    {
        queue->end = NULL;
    }
    queue->front = temp->next;
    data = temp->data;
    free(temp);
    return data;
}

void *front(struct queue *queue)
{
    if (!is_empty_queue(queue))
    {
        return queue->front->data;
    }

    printf("The queue is empty\n");
    return NULL;
}

void clear_queue(struct queue *queue)
{
    while (queue->front)
    {
        dequeue(queue);
    }
   
    free(queue);
}
