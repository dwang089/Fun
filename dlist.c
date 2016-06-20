#include "dlist.h"

static struct dlist_node *create_dlist_node(void *data)
{
    struct dlist_node *new_node; 

    new_node = malloc(sizeof(struct dlist_node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void insert_dlist_front(struct dlist_node **head, void *new_data)
{
    struct dlist_node *new_node; 

    new_node = create_dlist_node(new_data);

    if (*head == NULL)
    {
        *head = new_node;
        return;     
    }

    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

void insert_dlist_end(struct dlist_node **head, void *new_data)
{
    struct dlist_node *new_node; 
    struct dlist_node *last = *head;

    new_node = create_dlist_node(new_data);

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
    new_node->prev = last;  
}

void insert_dlist_after(struct dlist_node *prev_node, void *new_data)
{
    struct dlist_node *new_node;

    if (!prev_node)
    {
        printf("The previous node is null\n");
    }

    new_node = create_dlist_node(new_data);

    if (prev_node->next != NULL)
    {
        prev_node->next->prev = new_node;
        new_node->next = prev_node->next;
    }
    else
    {
        new_node->next = NULL;
    }   
    new_node->prev = prev_node;   
    prev_node->next = new_node;
}

int dlist_size(struct dlist_node *head)
{
    int count = 0;
    struct dlist_node *temp = head;

    while (temp != NULL) 
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void print_dlist_int(void *data)
{
    printf("%d ", *(int *)data);
}

void print_dlist(struct dlist_node *head, void (*fptr)(void *))
{
    struct dlist_node *temp = head;

    while (temp != NULL)
    {
        fptr(temp->data);
        temp = temp->next;
    }

    printf("\nthe size of the dlist is %d\n", dlist_size(head));
}

void reverse_dlist(struct dlist_node **head)
{

}
