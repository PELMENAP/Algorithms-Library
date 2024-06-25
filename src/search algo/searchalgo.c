#include "searchalgo.h"
#include <stddef.h>


int binarySearch(const int *sorted_arr, int element, int start, int end)
{
    int pivot_index = start + (end - start)/2;
    int pivot = sorted_arr[pivot_index];
    if (element == pivot) return pivot_index;
    else if (end - start < 2) return -1;
    else if (element < pivot) return binarySearch(sorted_arr, element, start, pivot_index);
    else return binarySearch(sorted_arr, element, pivot_index, end);
}

