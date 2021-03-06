#ifndef _SORT_
#define _SORT_
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void print_array(const int *array, size_t size);
void countingSort(int *a, int n, int div);
void radix_sort(int *array, size_t size);

#endif
