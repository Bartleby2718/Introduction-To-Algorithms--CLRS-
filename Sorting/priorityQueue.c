//
// Created by bartl on 05/09/2019.
//
#include <assert.h>
#include <limits.h>
#include <string.h>
#include "heapSort.h"
#include "helperFunctions.h"
#include "priorityQueue.h"

int *insert(int *array, size_t length, int element)
{
    size_t newArrayLength = length + 1;
    int *newArray = malloc(newArrayLength * sizeof(int));
    memcpy(newArray, array, length * sizeof(int));
    newArray[length] = INT_MIN;
    increaseKey(newArray, length, element);
    maxHeapify(newArray, newArrayLength, length);
    return newArray;
}

int getMax(int *array)
{
    return array[0];
}

int extractMax(int *array, size_t length)
{
    int maxElement = array[0];
    array[0] = array[length - 1];
    maxHeapify(array, length - 1, 0);
    return maxElement;
}

void increaseKey(int *array, size_t index, int key)
{
    /* increaseKey only goes up, decreaseKey=maxHeapify only goes down. */
    assert(key > array[index]);
    int i = index;
    while (i > 0 && array[(i - 1) / 2] < key)
    {
        array[i] = array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    array[i] = key;
}
