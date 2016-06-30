#include "sort.h"

int bin_search(void **array, void *data, int first, int last, 
        int (*cmp_fptr)(void *, void *))
{
    int middle; 

    if (first <= last)
    {
        middle = (last + first) / 2; 
    
        if (cmp_fptr(data, array[middle]) == 0)
        {
            return middle;
        }
        else if (cmp_fptr(data, array[middle]) < 0)
        {
            return bin_search(array, data, first, middle - 1, cmp_fptr);
        }
        else
        {
            return bin_search(array, data, middle + 1, last, cmp_fptr);
        }  
    }

    return -1;
}

void bubble_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *))
{
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (cmp_fptr(array[j], array[j + 1]) > 0)
            {
                swap(&array[j], &array[j + 1]);
            } 
        }      
    }
}

void selection_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *))
{
    int i, j, min;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i; j < size - 1; j++)
        {
            if (cmp_fptr(array[min], array[j + 1]) > 0)
            {
                min = j + 1;
            }
        }
        swap(&array[min], &array[i]);
    }
}

void insertion_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *))
{
    int i, j;
    void *temp;

    for (i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && cmp_fptr(array[i], array[j]) < 0)
        {
            array[j + 1] = array[j];
            j--;
        } 
    
        array[j + 1] = temp;
    }   
}

static void merge(void **array, int first, int middle, int last, 
        int (*cmp_fptr)(void *, void *))
{

}

static void merge_sort_with_index(void **array, int first, int last, 
        int (*cmp_fptr)(void *, void *))
{
    int middle; 

    middle = (first + last) / 2;

    merge_sort_with_index(array, first, middle, cmp_fptr);
    merge_sort_with_index(array, middle + 1, last, cmp_fptr);

    merge(array, first, middle, last, cmp_fptr);
}

void merge_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *))
{
    merge_sort_with_index(array, 0, size - 1, cmp_fptr);
}
