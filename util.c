#include "util.h"

void print_int(void *data)
{
    printf("%d ", *(int *)data);
}

void print_array(void **array, size_t size, void (*print_fptr)(void *))
{
    int i;

    for (i = 0; i < size; i++)
    {
        print_fptr(array[i]);
    } 
  
    printf("\n");
}

int cmp_int(void *data1, void *data2)
{
    return *(int *)data1 - *(int *)data2;
}

void swap(void **data1, void **data2)
{
    void *temp;

    temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}
