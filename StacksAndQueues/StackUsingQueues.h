//
// Created by bartl on 05/21/2019.
//

#ifndef STACKSANDQUEUES_STACKUSINGQUEUES_H
#define STACKSANDQUEUES_STACKUSINGQUEUES_H

#include <cstddef>
#include <iostream>
#include <queue>

using namespace std;

template<class T>
class StackUsingQueues
{
    queue<T> emptyQueue;
    queue<T> queueWithElements;
    int numElements;
public:
    StackUsingQueues();

    void push(const T &element);  // O(1), but O(n) if the stack is already full

    void pop();  // O(n)

    T top() const;  // O(n), used another queue to stay const-qualified

    bool empty() const;  // O(1)

    void print() const;  // O(n), used another queue to stay const-qualified
};

template<class T>
StackUsingQueues<T>::StackUsingQueues()
{
    numElements = 0;
}

template<class T>
void StackUsingQueues<T>::push(const T &element)
{
    queueWithElements.push(element);
    clog << "Pushing element to the top: " << to_string(element) << endl;
    ++numElements;
}

template<class T>
void StackUsingQueues<T>::pop()
{
    if (empty())
    {
        throw out_of_range("Stack Underflow: The stack is already empty.");
    }
    else
    {
        for (int i = 0; i < numElements - 1; ++i)
        {
            T element = queueWithElements.front();
            queueWithElements.pop();
            emptyQueue.push(element);
        }
        T elementOnTop = queueWithElements.front();
        clog << "Popping element on the top: " << to_string(elementOnTop) << endl;
        queueWithElements.pop();
        swap(emptyQueue, queueWithElements);
        --numElements;
    }
}

template<class T>
T StackUsingQueues<T>::top() const
{
    if (empty())
    {
        throw out_of_range("The stack is empty.");
    }
    else
    {
        queue<T> copiedQueue(queueWithElements);
        for (int i = 0; i < numElements - 1; ++i)
        {
            copiedQueue.pop();
        }
        T elementOnTop = copiedQueue.front();
        clog << "Element on the top: " << to_string(elementOnTop) << endl;
        return elementOnTop;
    }
}

template<class T>
bool StackUsingQueues<T>::empty() const
{
    return numElements == 0;
}

template<class T>
void StackUsingQueues<T>::print() const
{
    if (empty())
    {
        clog << "The stack is empty." << endl;
    }
    else
    {
        clog << "Elements on the stack:";
        queue<T> copiedQueue(queueWithElements);
        for (int i = 0; i < numElements; ++i)
        {
            T element = copiedQueue.front();
            clog << " " << to_string(element);
            copiedQueue.pop();
        }
        clog << endl;
    }
}

#endif //STACKSANDQUEUES_STACKUSINGQUEUES_H
