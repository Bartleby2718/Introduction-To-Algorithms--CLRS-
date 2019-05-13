//
// Created by bartl on 04/01/2019.
//

#include "bubbleSort.h"

int *bubbleSort(int *array, size_t length)
{
    int temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = length - 1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}