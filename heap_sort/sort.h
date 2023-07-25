#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b, int *array, int lenght_array);
void heapify(int *array, int size, int i, int lenght_array);

#endif /* SORT_H */
