//
// Created by bartl on 03/21/2019.
//

#include "insertionSort.h"

int *insertionSort(int *array, size_t length)
{
    for (int i = 1, key, j; i < length; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return array;
}

int *insertionSort2(int *array, size_t length)
{
    for (int i = 1, key, j; i < length; i++)
    {
        key = array[i];
        for (j = i - 1; j >= 0 && array[j] > key; --j)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = key;
    }
    return array;
}

