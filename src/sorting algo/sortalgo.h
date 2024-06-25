#pragma once
#include <stdint.h>
#include <stddef.h>


int* generateRandomArrayMassive(size_t size, size_t maxValue);

void quickSort(int *arr, size_t start, size_t end);

void heapSort(int *arr, size_t n);

void introSort(int *arr, size_t n);

void insertionSort(int *arr, size_t left, size_t right);

void timSort(int *arr, size_t n);

void mergeSort(int *array, size_t n);

void bubbleSort(int *array, size_t n);

void combSort(int* array, size_t n);
