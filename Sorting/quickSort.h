//
// Created by bartl on 05/10/2019.
//

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

int *quickSort(int *array, int start, int end);

int *quickSort2(int *array, int start, int end);

int *tailRecursiveQuickSort(int *array, int start, int end);

int partition(int *array, int start, int end);

struct indices
{
    unsigned start;
    unsigned end;
};

struct indices partition2(int *array, int start, int end);

#endif //SORTING_QUICKSORT_H
