//
// Created by bartl on 05/20/2019.
//

#ifndef STACKSANDQUEUES_QUEUEUSINGARRAY_H
#define STACKSANDQUEUES_QUEUEUSINGARRAY_H

#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

template<class T>
class QueueUsingArray
{
    /**
     * Implementation of stack of fixed size using an array
     **/
    T *array;
    size_t headIndex;
    size_t tailIndex;
    size_t capacity;  // capacity of the stack (= capacity of the array - 1)
public:
    explicit QueueUsingArray(size_t capacity);

    QueueUsingArray() : QueueUsingArray(10) {}

    ~QueueUsingArray();

    void enqueue(T element); // O(1) because the size is fixed

    T dequeue(); // O(1)

    bool empty() const; // O(1)

    bool full() const; // O(1)

    void print() const; // O(n)
};

template<class T>
QueueUsingArray<T>::QueueUsingArray(const size_t capacity)
{
    if (capacity >= numeric_limits<size_t>::max())
    {
        throw out_of_range("Try a smaller capacity.");
    }
    else
    {
        array = new T[capacity + 1];  // space before head is always kept empty
        headIndex = 0;  // index of the first element
        tailIndex = 0;  // index after the last element
        this->capacity = capacity;
        clog << "Created a queue of capacity " << capacity << "." << endl;
    }
}

template<class T>
QueueUsingArray<T>::~QueueUsingArray()
{
    delete array;
    clog << "Destroyed a queue of capacity " << capacity << "." << endl;
}

template<class T>
void QueueUsingArray<T>::enqueue(const T element)
{
    if (full())
    {
        string message = string("Queue Overflow: The queue is full.")
                         + " Failed to enqueue " + to_string(element) + ".";
        throw out_of_range(message);
    }
    else
    {
        array[tailIndex++] = element;
        tailIndex %= (capacity + 1);
    }
}

template<class T>
T QueueUsingArray<T>::dequeue()
{
    if (empty())
    {
        string message = string("Queue Underflow: The queue is empty.")
                         + " Failed to dequeue.";
        throw out_of_range(message);
    }
    else
    {
        T element = array[headIndex++];
        headIndex %= (capacity + 1);
        return element;
    }
}

template<class T>
bool QueueUsingArray<T>::full() const
{
    return (tailIndex + 1) % (capacity + 1) == headIndex;
}

template<class T>
bool QueueUsingArray<T>::empty() const
{
    return headIndex == tailIndex;
}

template<class T>
void QueueUsingArray<T>::print() const
{
    if (empty())
    {
        clog << "The queue is currently empty." << endl;
    }
    else
    {
        clog << "Elements in the queue: ";
        for (size_t current = headIndex; current != tailIndex; (++current) %= (capacity + 1))
        {
            clog << to_string(array[current]) << " ";
        }
        if (full())
        {
            clog << "(The queue is currently full.)";
        }
        clog << endl;
    }
}

#endif //STACKSANDQUEUES_QUEUEUSINGARRAY_H
