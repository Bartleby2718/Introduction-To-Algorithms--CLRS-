//
// Created by bartl on 05/10/2019.
//

#include "quickSort.h"

int *quickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int q = partition(array, start, end);
        quickSort(array, start, q - 1);
        quickSort(array, q + 1, end);
    }
    return array;
}

int *quickSort2(int *array, int start, int end)
{
    if (start < end)
    {
        struct indices ii = partition2(array, start, end);
        quickSort(array, start, ii.start - 1);
        quickSort(array, ii.end + 1, end);
    }
    return array;
}

int *tailRecursiveQuickSort(int *array, int start, int end)
{
    while (start < end)
    {
        int q = partition(array, start, end);
        quickSort(array, start, q - 1);
        start = q + 1;
    }
    return array;
}

int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int i, j, temp;
    for (j = start, i = j - 1; j < end; ++j)
    {
        if (array[j] <= pivot)
        {
            temp = array[++i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[++i];
    array[i] = pivot;
    array[end] = temp;
    return i;
}

struct indices partition2(int *array, int start, int end)
{
    // TODO
    int pivot = array[end];
    int i, j, temp, max;
    for (i = start - 1, j = start; j < end; ++j)
    {
        if (array[j] < pivot)
        {
            temp = array[j];
            array[j] = array[++i];
            array[i] = temp;
        }
        else if (array[j] == pivot)
        {
            max = j;
        }
    }
    temp = array[++i];
    array[i] = pivot;
    array[end] = temp;
    struct indices ii = {i, max};
    return ii;
}