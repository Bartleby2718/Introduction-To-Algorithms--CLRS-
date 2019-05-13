//
// Created by bartl on 05/07/2019.
//

#include <stdbool.h>
#include <stdio.h>
#include "heapSort.h"

void maxHeapify(int *array, size_t length, size_t index)
{
    int i = index;
    int leftIndex = 2 * i + 1;
    int indexWithLargest = i;
    if (leftIndex < length && array[leftIndex] > array[i])
    {
        indexWithLargest = leftIndex;
    }
    int rightIndex = 2 * i + 2;
    if (rightIndex < length && array[rightIndex] > array[indexWithLargest])
    {
        indexWithLargest = rightIndex;
    }
    int temp;
    while (!(i > length / 2 - 1 || i == indexWithLargest))
    {
        temp = array[indexWithLargest];
        array[indexWithLargest] = array[i];
        array[i] = temp;
        i = indexWithLargest;

        leftIndex = 2 * i + 1;
        if (leftIndex < length && array[leftIndex] > array[i])
        {
            indexWithLargest = leftIndex;
        }
        rightIndex = 2 * i + 2;
        if (rightIndex < length && array[rightIndex] > array[indexWithLargest])
        {
            indexWithLargest = rightIndex;
        }
    }
}

int *buildMaxHeap(int *array, size_t length)
{
    for (int i = length / 2 - 1; i >= 0; --i)
    {
        maxHeapify(array, length, i);
    }
    return array;
}

int *heapSort(int *array, size_t length)
{
    buildMaxHeap(array, length);
    for (int i = length - 1; i > 0; --i)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        maxHeapify(array, i, 0);
    }
    return array;
}

void heapDelete(int *array, size_t length, size_t index)
{
    array[index] = array[length - 1];
    maxHeapify(array, length - 1, index);
}