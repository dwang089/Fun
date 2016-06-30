#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdlib.h>

struct minheap {
    void **data;
    int capacity;
    int size;
};

struct minheap *create_minheap(int capacity, size_t data_size);


#endif
