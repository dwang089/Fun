#include "util.h"
#include "slist.h"
#include "dlist.h"
#include "stack.h"
#include "queue.h"
#include "bintree.h"
#include "bstree.h"
#include "minheap.h"
#include "sort.h"

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
    print_slist(head, print_int);

    remove_slist_data(&head, (void *)item3, sizeof(int));
    remove_slist_data(&head, (void *)item1, sizeof(int));
    print_slist(head, print_int);

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
    print_dlist(head, print_int);

    remove_dlist_data(&head, (void *)item3, sizeof(int));
    remove_dlist_data(&head, (void *)item1, sizeof(int));
    print_dlist(head, print_int);

    reverse_dlist(&head);
    print_dlist(head, print_int);

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

    push(&root, (void *)item4); 
    push(&root, (void *)item5);
    pop(&root);
    if (!is_empty_stack(root)) 
    { 
        printf("The top is %d\n", *((int *)peek(root)));
    }

    clear_stack(root);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
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
    struct bintree_node *root = NULL;
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

    insert_bintree(&root, item1); 
    insert_bintree(&(root->left), item2); 
    insert_bintree(&(root->right), item3); 
    insert_bintree(&(root->left->left), item4); 
    insert_bintree(&(root->left->right), item5); 

    printf("Inorder traversal\n");
    inorder_bintree(root, print_int);
    printf("\n");
    
    printf("Preorder traversal\n");
    preorder_bintree(root, print_int);
    printf("\n");
    
    printf("Postorder traversal\n");
    postorder_bintree(root, print_int);
    printf("\n");
    
    printf("Level-order traversal\n");
    level_order_bintree(root, print_int);
    printf("\n");
    
    printf("The height is %d\n", bintree_height(root));

    clear_bintree(root);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
}

static void test_bstree()
{
    struct bstree *tree;
    int *item1, *item2, *item3, *item4, *item5;

    item1 = malloc(sizeof(int));
    *item1 = 30;
    item2 = malloc(sizeof(int));
    *item2 = 10;
    item3 = malloc(sizeof(int));
    *item3 = 20;
    item4 = malloc(sizeof(int));
    *item4 = 40;
    item5 = malloc(sizeof(int));
    *item5 = 50;
   
    tree = create_bstree();
    insert_bstree(tree, item1, cmp_int);
    insert_bstree(tree, item2, cmp_int);
    insert_bstree(tree, item3, cmp_int);
    insert_bstree(tree, item4, cmp_int);
    insert_bstree(tree, item5, cmp_int);

    printf("Inorder traversal\n");
    inorder_bstree(tree, print_int);
    printf("\n");
    
    printf("Preorder traversal\n");
    preorder_bstree(tree, print_int);
    printf("\n");
    
    printf("Postorder traversal\n");
    postorder_bstree(tree, print_int);
    printf("\n");
    
    printf("Level-order traversal\n");
    level_order_bstree(tree, print_int);
    printf("\n");
    
    printf("The height is %d\n", bstree_height(tree));

    clear_bstree(tree);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
}

static void test_minheap()
{

}

static void test_sort()
{
    int **array;
    size_t size = 5;
    int *item1, *item2, *item3, *item4, *item5, *item6;

    array = malloc(size * sizeof(int *));
    item1 = malloc(sizeof(int));
    *item1 = 30;
    array[0] = item1;
    item2 = malloc(sizeof(int));
    *item2 = 10;
    array[1] = item2;
    item3 = malloc(sizeof(int));
    *item3 = 20;
    array[2] = item3;
    item4 = malloc(sizeof(int));
    *item4 = 50;
    array[3] = item4;
    item5 = malloc(sizeof(int));
    *item5 = 40;
    array[4] = item5;
    item6 = malloc(sizeof(int));
    *item6 = 25;
   
    print_array((void **)array, size, print_int);
 
    /*
    bubble_sort((void **)array, size, cmp_int);
    printf("After bubble sort\n"); 
    print_array((void **)array, size, print_int);

    selection_sort((void **)array, size, cmp_int);
    printf("After selection sort\n"); 
    print_array((void **)array, size, print_int);
  
    insertion_sort((void **)array, size, cmp_int);
    printf("After insertion sort\n"); 
    print_array((void **)array, size, print_int);
    */
 
    merge_sort((void **)array, size, cmp_int);
    printf("After merge sort\n"); 
    print_array((void **)array, size, print_int);
   
    printf("item3 is element %d\n", 
            bin_search((void **)array, item3, 0, size - 1, cmp_int));
    printf("item6 is element %d\n", 
            bin_search((void **)array, item6, 0, size - 1, cmp_int));
    
    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
    free(array);
}

int main()
{
    //test_slist();
    //test_dlist();
    //test_stack();
    //test_queue();
    //test_bintree();
    //test_bstree();
    //test_minheap();
    test_sort();

    return 0;
}
