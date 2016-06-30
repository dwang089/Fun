#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

void print_int(void *data);
void print_array(void **array, size_t size, void (*print_fptr)(void *));

int cmp_int(void *data1, void *data2);

void swap(void **data1, void **data2);

#endif
