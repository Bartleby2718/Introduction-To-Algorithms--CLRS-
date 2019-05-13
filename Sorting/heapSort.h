//
// Created by bartl on 05/07/2019.
//
#ifndef INTRODUCTIONTOALGORITHMS_HEAPSORT_H
#define INTRODUCTIONTOALGORITHMS_HEAPSORT_H

#include <stddef.h>

void maxHeapify(int *array, size_t length, size_t index);

int *buildMaxHeap(int *array, size_t length);

int *heapSort(int *array, size_t length);

void heapDelete(int *array, size_t length, size_t index);

#endif //INTRODUCTIONTOALGORITHMS_HEAPSORT_H
