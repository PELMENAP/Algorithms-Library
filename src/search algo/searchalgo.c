#include "searchalgo.h"


int binarySearch(const int *sorted_arr, int element, int start, int end)
{
    int pivot_index = start + (end - start)/2;
    int pivot = sorted_arr[pivot_index];
    if (element == pivot) return pivot_index;
    else if (end - start < 2) return -1;
    else if (element < pivot) return binarySearch(sorted_arr, element, start, pivot_index);
    else return binarySearch(sorted_arr, element, pivot_index, end);
}

int linearSearch(const int *arr, int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element) return i;
    }
    return -1;
}

struct indexes MatrixSearch(const int **arr, int element, int size_m, int size_n)
{
    struct indexes _indexes;
    _indexes.index_i = -1;
    _indexes.index_j = -1;
    for (int i = 0; i < size_m; i++)
    {
        for (int j = 0; j < size_n; j++)
        {
            if (arr[i][j] == element)
            {
                _indexes.index_i = i;
                _indexes.index_j = j;
                return _indexes;
            }
        }
    }
    return _indexes;
}
