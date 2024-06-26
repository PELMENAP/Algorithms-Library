struct indexes
{
    int index_i;
    int index_j;
};

int binarySearch(const int *sorted_arr, int element, int start, int end);

int linearSearch(const int *arr, int element, int size);

struct indexes MatrixSearch(const int **arr, int element, int size_m, int size_n);