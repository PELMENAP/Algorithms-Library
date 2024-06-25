#include "sortalgo.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* generateRandomArrayMassive(size_t size, size_t maxValue)
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    srand(now.tv_nsec);
    int* arr = (int *)malloc(sizeof(int)*size);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand()%maxValue;
    }
    return arr;
}

void quickSort(int *arr, size_t start, size_t end)
{
	if (start >= end) return;
	int pivot = arr[(start+end)/2];
	size_t i = start;
	size_t j = end;
	while (i <= j)
    {
        while (arr[i] < pivot && i < end) i++;
        while (arr[j] > pivot && j > start) j--;
        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            if (i != end) i++;
            if (j != start) j--;
        }
	}
	quickSort(arr, start, j);
	quickSort(arr, i, end);
}

void heapify(int *arr, size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, size_t n)
{
    for (size_t i = n / 2; i > 0; i--) heapify(arr, n, i - 1);
    for (size_t i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionSort(int *arr, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        size_t j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left;
    size_t j = mid + 1;
    size_t k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void mergeSort(int *array, size_t n)
{
    if (n > 1)
    {
        size_t const left_size = n / 2;
        size_t const right_size = n - left_size;

        mergeSort(&array[0], left_size);
        mergeSort(&array[left_size], right_size);

        size_t lidx, idx, ridx;
        lidx = 0;
        idx = 0;
        ridx = left_size;
        int* tmp_array = (int *)malloc(n*sizeof(int));

        while (lidx < left_size || ridx < n)
        {
            if (array[lidx] < array[ridx])
            {
                tmp_array[idx++] = array[lidx];
                lidx++;
            }
            else
            {
                tmp_array[idx++] = array[ridx];
                ridx++;
            }

            if (lidx == left_size)
            {
                for (size_t i = ridx; i < n; i++){
                    tmp_array[idx+i-ridx] = array[i];
                }
                break;
            }
            if (ridx == n)
            {
                for (size_t i = lidx; i < left_size; i++){
                    tmp_array[idx+i-lidx] = array[i];
                }
                break;
            }
        }
        for (size_t i = 0; i < n; i++){
            array[i] = tmp_array[i];
        }
        free(tmp_array);
    }
}

void timSort(int *arr, size_t n)
{
    const int gap = 128;
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) return;
    for (size_t i = 0; i < n; i += gap)
        insertionSort(arr, i, (i + gap - 1 < n) ? (i + gap - 1) : (n - 1));
    for (size_t size = gap; size < n; size = 2 * size)
    {
        for (size_t left = 0; left < n; left += 2 * size)
        {
            size_t mid = left + size - 1;
            size_t right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            if (mid < right) merge(arr, temp, left, mid, right);
        }
    }
    free(temp);
}

void IntroQuickSort(int *arr, size_t start, size_t end, size_t depth)
{
    if (depth == 0)
    {
        heapSort(arr + start, end - start + 1);
        return;
    }
	if (start >= end) return;
	int pivot = arr[(start+end)/2];
	size_t i = start;
	size_t j = end;
	while (i <= j)
    {
        while (arr[i] < pivot && i < end) i++;
        while (arr[j] > pivot && j > start) j--;
        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            if (i != end) i++;
            if (j != start) j--;
        }
	}
	IntroQuickSort(arr, start, j, depth - 1);
	IntroQuickSort(arr, i, end, depth - 1);
}

void introSort(int *arr, size_t n)
{
    size_t max_depth = 4 * (log(n) / log(2));
    IntroQuickSort(arr, 0, n - 1, max_depth);
}

void bubbleSort(int *array, size_t n)
{
while (n > 0)
{
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] > array[i+1]) swap(&array[i], &array[i+1]);
    }
    n--;
}
}

void combSort(int* array, size_t n)
{
	double factor = 1.25;
	int step = n - 1;
	while (step >= 1)
	{
		for (int i = 0; i + step < n; i++)
		{
			if (array[i] > array[i + step])
			{
				swap(&array[i], &array[i + step]);
			}
		}
		step /= factor;
	}
}
