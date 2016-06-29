#include "slist.h"
#include "dlist.h"
#include "stack.h"
#include "queue.h"
#include "bintree.h"

static void test_slist() 
{
    struct slist_node *head = NULL;
    int *item1, *item2, *item3, *item4, *item5;
   
    item1 = malloc(sizeof(int));
    *item1 = 6;
    item2 = malloc(sizeof(int));
    *item2 = 7;
    item3 = malloc(sizeof(int));
    *item3 = 1;
    item4 = malloc(sizeof(int));
    *item4 = 4;
    item5 = malloc(sizeof(int));
    *item5 = 8;

    insert_slist_end(&head, (void *)item1);
    insert_slist_front(&head, (void *)item2);
    insert_slist_front(&head, (void *)item3);
    insert_slist_end(&head, (void *)item4);
    insert_slist_after(head->next, (void *)item5);
    print_slist(head, print_slist_int);

    remove_slist_data(&head, (void *)item3, sizeof(int));
    remove_slist_data(&head, (void *)item1, sizeof(int));
    print_slist(head, print_dlist_int);

    clear_slist(head);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
}

static void test_dlist() 
{
    struct dlist_node *head = NULL;
    int *item1, *item2, *item3, *item4, *item5;

    item1 = malloc(sizeof(int));
    *item1 = 6;
    item2 = malloc(sizeof(int));
    *item2 = 7;
    item3 = malloc(sizeof(int));
    *item3 = 1;
    item4 = malloc(sizeof(int));
    *item4 = 4;
    item5 = malloc(sizeof(int));
    *item5 = 8;

    insert_dlist_end(&head, (void *)item1);
    insert_dlist_front(&head, (void *)item2);
    insert_dlist_front(&head, (void *)item3);
    insert_dlist_end(&head, (void *)item4);
    insert_dlist_after(head->next, (void *)item5);
    print_dlist(head, print_dlist_int);

    remove_dlist_data(&head, (void *)item3, sizeof(int));
    remove_dlist_data(&head, (void *)item1, sizeof(int));
    print_dlist(head, print_dlist_int);

    reverse_dlist(&head);
    print_dlist(head, print_dlist_int);

    clear_dlist(head);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
}

static void test_stack()
{
    struct stack_node *root = NULL;
    int *item1, *item2, *item3;

    item1 = malloc(sizeof(int));
    *item1 = 10;
    item2 = malloc(sizeof(int));
    *item2 = 20;
    item3 = malloc(sizeof(int));
    *item3 = 30;

    push(&root, (void *)item1); 
    push(&root, (void *)item2); 
    push(&root, (void *)item3);

    if (!is_empty_stack(root)) 
    { 
        printf("The top is %d\n", *((int *)peek(root)));
    }
    pop(&root);
    if (!is_empty_stack(root)) 
    { 
        printf("The top is %d\n", *((int *)peek(root)));
    }
    pop(&root);
    if (!is_empty_stack(root)) 
    { 
        printf("The top is %d\n", *((int *)peek(root)));
    }
    pop(&root);
    if (!is_empty_stack(root)) 
    { 
        printf("The top is %d\n", *((int *)peek(root)));
    }
    pop(&root);
    if (!is_empty_stack(root)) 
    { 
        printf("The top is %d\n", *((int *)peek(root)));
    }

    free(item1);
    free(item2);
    free(item3);
}

static void test_queue()
{
    struct queue *q;
    int *item1, *item2, *item3, *item4, *item5;

    item1 = malloc(sizeof(int));
    *item1 = 10;
    item2 = malloc(sizeof(int));
    *item2 = 20;
    item3 = malloc(sizeof(int));
    *item3 = 30;
    item4 = malloc(sizeof(int));
    *item4 = 40;
    item5 = malloc(sizeof(int));
    *item5 = 50;

    q = create_queue();
    enqueue(q, item1);
    enqueue(q, item2);
    dequeue(q);

    if (!is_empty_queue(q))
    {
        printf("The top is %d\n", *((int *)front(q)));
    }

    enqueue(q, item3);
    enqueue(q, item4);
    enqueue(q, item5);
    dequeue(q);
    dequeue(q);

    if (!is_empty_queue(q))
    {
        printf("The top is %d\n", *((int *)front(q)));
    }
        
    clear_queue(q);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
}

static void test_bintree()
{

}

int main()
{
    //test_slist();
    //test_dlist();
    //test_stack();
    //test_queue();
    test_bintree();

    return 0;
}
