//
// Created by bartl on 05/09/2019.
//
#ifndef INTRODUCTIONTOALGORITHMS_PRIORITYQUEUE_H
#define INTRODUCTIONTOALGORITHMS_PRIORITYQUEUE_H

#include <stdlib.h>

/* assumes that array does not hold enough memory for the inserted element */
int *insert(int *array, size_t length, int element);

int getMax(int *array);

int extractMax(int *array, size_t length);

void increaseKey(int *array, size_t index, int key);

#endif //INTRODUCTIONTOALGORITHMS_PRIORITYQUEUE_H
