//
// Created by bartl on 05/20/2019.
//

#ifndef STACKSANDQUEUES_STACKUSINGARRAY_H
#define STACKSANDQUEUES_STACKUSINGARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class StackUsingArray
{
    /**
     * Implementation of stack of fixed size using an array
     **/
    T *array;
    size_t numElements;
    size_t capacity;
public:
    explicit StackUsingArray(size_t capacity);

    StackUsingArray() : StackUsingArray(10) {}

    ~StackUsingArray();

    void push(T element);

    void pop();

    bool empty() const;

    T top();
};

template<class T>
StackUsingArray<T>::StackUsingArray(const size_t capacity)
{
    array = new T[capacity];
    numElements = 0;
    this->capacity = capacity;
    clog << "Created a stack of capacity " << capacity << endl;
}

template<class T>
StackUsingArray<T>::~StackUsingArray()
{
    clog << "Deleting stack..." << endl;
    delete array;
}

template<class T>
void StackUsingArray<T>::pop()
{
    if (empty())
    {
        string message = string("Stack Underflow: The stack is empty.\n") +
                         "Couldn't pop any element from the stack.";
        throw out_of_range(message);
    }
    else
    {
        clog << "Popping an element(" << array[--numElements] << ") from the stack..." << endl;
    }
}

template<class T>
void StackUsingArray<T>::push(const T element)
{
    if (numElements == capacity)
    {
        string message = string("Stack Overflow: The stack is full.\n") +
                         "Couldn't push " + to_string(element) + " to the stack.";
        throw out_of_range(message);
    }
    else
    {
        array[numElements++] = element;
        clog << "Pushed an element(" << to_string(element) << ") to the stack." << endl;
    }
}

template<class T>
T StackUsingArray<T>::top()
{
    if (empty())
    {
        throw out_of_range("Stack Underflow: The stack is empty.");
    }
    else
    {
        clog << "Element on the top: " << array[numElements - 1] << endl;
        clog << "Number of elements on the stack: " << numElements << endl;
        return array[numElements - 1];
    }
}

template<class T>
bool StackUsingArray<T>::empty() const
{
    return numElements == 0;
}

#endif //STACKSANDQUEUES_STACKUSINGARRAY_H
