#include "slist.h"

static struct slist_node *create_slist_node(void *data)
{
    struct slist_node *new_node; 

    new_node = malloc(sizeof(struct slist_node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void insert_slist_front(struct slist_node **head, void *new_data) 
{
    struct slist_node *new_node;

    new_node = create_slist_node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void insert_slist_end(struct slist_node **head, void *new_data) 
{
    struct slist_node *new_node; 
    struct slist_node *last = *head;

    new_node = create_slist_node(new_data);

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL) 
    {
        last = last->next;
    }

    last->next = new_node;
}

void insert_slist_after(struct slist_node *prev_node, void *new_data) 
{
    struct slist_node *new_node;

    if (prev_node == NULL)
    {
        printf("The previous node is null\n");
    }

    new_node = create_slist_node(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

struct slist_node *get_slist_node(struct slist_node *head, void *data, size_t data_size)
{
    struct slist_node *node = head;

    if (head == NULL)
    {
        printf("The slist is empty\n");
        return NULL;
    }

    while (node != NULL)
    {
        if (!memcmp(node->data, data, data_size))
        {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

static void remove_slist_node(struct slist_node **head, struct slist_node *node)
{
    struct slist_node *prev = *head;

    if (node == *head)
    {
        *head = node->next; 
    }
    else
    {
        while (prev && prev->next != node)
        {
            prev = prev->next;
        }

        if (prev)
        {
            prev->next = node->next;
        }
    }

    free(node);
}

void remove_slist_data(struct slist_node **head, void *data, size_t data_size)
{
    struct slist_node *node;

    node = get_slist_node(*head, data, data_size);
    if (node == NULL)
    {
        printf("The node does not exist\n");
        return;
    }

    remove_slist_node(head, node); 
}

void clear_slist(struct slist_node *head)
{
    while (head)
    {
        remove_slist_node(&head, head);
    }
}

int slist_size(struct slist_node *head)
{
    int count = 0;
    struct slist_node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void print_slist(struct slist_node *head, void (*print_fptr)(void *))
{
    struct slist_node *temp = head;

    while (temp != NULL) 
    {  
        print_fptr(temp->data);
        temp = temp->next;
    }

    printf("\n");
    //printf("The size of the slist is %d\n", slist_size(head));
}
