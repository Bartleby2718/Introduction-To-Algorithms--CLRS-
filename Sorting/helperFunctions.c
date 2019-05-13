//
// Created by bartl on 05/09/2019.
//

#include <stdio.h>
#include "helperFunctions.h"

void printArray(int *array, size_t length)
{
    printf("{%d", array[0]);
    size_t i;
    for (i = 1; i < length; ++i)
    {
        printf(", %d", array[i]);
    }
    putchar('}');
}

void printArrayAndNewline(int *array, size_t length)
{
    printArray(array, length);
    putchar('\n');
}

