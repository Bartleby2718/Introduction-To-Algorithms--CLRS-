//
// Created by bartl on 05/21/2019.
//

#ifndef STACKSANDQUEUES_QUEUEUSINGSTACKS_H
#define STACKSANDQUEUES_QUEUEUSINGSTACKS_H

#include <iostream>
#include <stack>

using namespace std;

template<class T>
class QueueUsingStacks
{
    stack<T> emptyStack;
    stack<T> stackWithData;
public:
    QueueUsingStacks() = default;

    void enqueue(const T &element);  // O(n)

    void dequeue();  // O(1)

    bool empty() const;  // O(1)

    T front() const;  // O(1)
};

template<class T>
void QueueUsingStacks<T>::enqueue(const T &element)
{
    while (!stackWithData.empty())
    {
        emptyStack.push(stackWithData.top());
        stackWithData.pop();
    }
    emptyStack.push(element);
    while (!emptyStack.empty())
    {
        stackWithData.push(emptyStack.top());
        emptyStack.pop();
    }
    clog << "Added " << to_string(element) << " to the queue." << endl;
}

template<class T>
void QueueUsingStacks<T>::dequeue()
{
    if (empty())
    {
        throw out_of_range("Queue Underflow: The queue is already empty.");
    }
    else
    {
        T element = stackWithData.top();
        clog << "Removed " << to_string(element) << " from the queue." << endl;
        stackWithData.pop();
        if (empty())
        {
            clog << "The queue is now empty." << endl;
        }
        else
        {
            clog << "Element on the front: " << to_string(front()) << endl;
        }
    }
}

template<class T>
bool QueueUsingStacks<T>::empty() const
{
    return stackWithData.empty();
}

template<class T>
T QueueUsingStacks<T>::front() const
{
    if (empty())
    {
        throw out_of_range("Queue Underflow: The queue is already empty.");
    }
    else
    {
        return stackWithData.top();
    }
}

#endif //STACKSANDQUEUES_QUEUEUSINGSTACKS_H
