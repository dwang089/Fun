#include "util.h"

void print_int(void *data)
{
    printf("%d ", *(int *)data);
}

int cmp_int(void *data1, void *data2)
{
    return *(int *)data1 - *(int *)data2;
}
