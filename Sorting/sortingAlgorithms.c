#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubbleSort.h"
#include "heapSort.h"
#include "helperFunctions.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "priorityQueue.h"
#include "quickSort.h"
#include "selectionSort.h"

void testInsertionSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "insertion sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, insertion sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = insertionSort(copy, arrayLength);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

void testSelectionSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "selection sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, selection sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = selectionSort(copy, arrayLength);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

void testMergeSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "merge sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        printf("---%s--->", algorithmName);
        int *sorted = mergeSort(array, arrayLength);
        printArrayAndNewline(sorted, arrayLength);
    }
    putchar('\n');
}

void testBubbleSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "bubble sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, bubble sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = bubbleSort(copy, arrayLength);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

void testHeapSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "heap sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, heap sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = heapSort(copy, arrayLength);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

void testQuickSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "quick sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, quick sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = quickSort(copy, 0, arrayLength - 1);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

void testQuickSort2(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "quick sort 2";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, quick sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = quickSort2(copy, 0, arrayLength - 1);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

void testTailRecursiveQuickSort(int *arrays, size_t arrayCount, size_t arrayLength)
{
    char *algorithmName = "tail-recursive quick sort";
    printf("Start testing %s...\n", algorithmName);
    for (int i = 0; i < arrayCount; i++)
    {
        int *array = arrays + i * arrayLength;
        printArray(array, arrayLength);

        /* Being an in-place sorting algorithm, quick sort needs a copy*/
        int *copy = malloc(sizeof(int) * arrayLength);
        memcpy(copy, array, sizeof(int) * arrayLength);
        printf("---%s--->", algorithmName);
        int *sorted = tailRecursiveQuickSort(copy, 0, arrayLength - 1);
        printArrayAndNewline(sorted, arrayLength);
        free(copy);
    }
    putchar('\n');
}

int main()
{

    // arrays must be of same size
    int arrays[][10] = {
            {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
            {79, 27, 98, 31, 19, 85, 99, 50, 82, 70},
            {50, 27, 98, 31, 19, 27, 99, 50, 27, 99},
    };
    size_t arrayCount = sizeof(arrays) / sizeof(arrays[0]);
    size_t arrayLength = sizeof(arrays[0]) / sizeof(arrays[0][0]);
    /*
    testInsertionSort(arrays[0], arrayCount, arrayLength);
    testSelectionSort(arrays[0], arrayCount, arrayLength);
    testMergeSort(arrays[0], arrayCount, arrayLength);
    testBubbleSort(arrays[0], arrayCount, arrayLength);
    testHeapSort(arrays[0], arrayCount, arrayLength);
    testQuickSort(arrays[0], arrayCount, arrayLength);
    testQuickSort2(arrays[0], arrayCount, arrayLength);
    */
    testTailRecursiveQuickSort(arrays[0], arrayCount, arrayLength);
    /*
    int maxHeap[] = {10, 9, 6, 8, 7, 5, 4}, numElements = 7;
    printArrayAndNewline(maxHeap, numElements);
    printf("Inserting an element...");
    int *newArray = insert(maxHeap, numElements++, 11);
    printArrayAndNewline(newArray, numElements);
    int currentMax = getMax(newArray);
    printf("current max: %d\n", currentMax);
    int previousMax = extractMax(newArray, numElements--);
    printf("pulling out the largest element %d...\n", previousMax);
    printArrayAndNewline(newArray, numElements);
    printf("Increasing the key of the last element...");
    increaseKey(newArray, numElements - 1, 11);
    printArrayAndNewline(newArray, numElements);
    int indexToDelete = 1;
    printf("Deleting element at index %d(%d)...\n", indexToDelete, newArray[indexToDelete]);
    heapDelete(newArray, numElements--, indexToDelete);
    printArrayAndNewline(newArray, numElements);
    */
    return 0;
}