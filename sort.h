#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include "util.h"

int bin_search(void **array, void *data, int first, int last, 
        int (*cmp_fptr)(void *, void *));

void bubble_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *));
void selection_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *));
void insertion_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *));
void merge_sort(void **array, size_t size, int (*cmp_fptr)(void *, void *));

#endif
