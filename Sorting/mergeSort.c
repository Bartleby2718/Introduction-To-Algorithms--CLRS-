//
// Created by bartl on 03/25/2019.
//

#include "mergeSort.h"
#include <stdlib.h>

int *mergeSort(int *array, size_t length)
{
    if (length == 1)
        return array;
    size_t left_array_length = length / 2;
    size_t right_array_length = length - left_array_length;
    int *left_array = mergeSort(array, left_array_length);
    int *right_array = mergeSort(array + left_array_length, right_array_length);
    int *result = malloc(sizeof(int) * length);
    for (int i = 0, j = 0, k = 0; k < length; k++)
    {
        if (i == left_array_length)
        {
            for (; j < right_array_length; j++, k++)
            {
                result[k] = right_array[j];
            }
        } else if (j == right_array_length)
        {
            for (; i < left_array_length; i++, k++)
            {
                result[k] = left_array[i];
            }
        } else
        {
            if (left_array[i] <= right_array[j])
            {
                result[k] = left_array[i];
                i++;
            } else
            {
                result[k] = right_array[j];
                j++;
            }
        }
    }
    return result;
}
