//
// Created by bartl on 03/21/2019.
//

#include "selectionSort.h"
#include <limits.h>

int *selectionSort(int *array, size_t length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minimum = INT_MAX;
        int index = i;
        for (int j = i; j < length; j++)
        {
            if (array[j] < minimum)
            {
                minimum = array[j];
                index = j;
            }
        }
        int temp = array[i];
        array[i] = minimum;
        array[index] = temp;
    }
    return array;
}
