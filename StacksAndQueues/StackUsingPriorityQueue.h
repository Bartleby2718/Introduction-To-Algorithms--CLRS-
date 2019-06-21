//
// Created by bartl on 05/24/2019.
//

#ifndef STACKSANDQUEUES_STACKUSINGPRIORITYQUEUE_H
#define STACKSANDQUEUES_STACKUSINGPRIORITYQUEUE_H

#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include "PriorityQueueNode.hpp"

using namespace std;

template<class T>
class StackUsingPriorityQueue
{
    priority_queue<Node<T>> pq; // maximum priority queue
    unsigned currentIndex;
public:
    StackUsingPriorityQueue();

    void push(const T &element); // O(lgn)

    void pop(); // O(lgn)

    T top() const; // O(1)

    bool empty() const; // O(1)

    void resetIndex();
};

template<class T>
StackUsingPriorityQueue<T>::StackUsingPriorityQueue()
{
    resetIndex();
}

template<class T>
void StackUsingPriorityQueue<T>::push(const T &element)
{
    if (currentIndex == numeric_limits<decltype(currentIndex)>::max())
    {
        throw out_of_range("Insertion failed. Ran out of indices.");
    }
    else
    {
        Node<T> node = {++currentIndex, element};
        clog << "Pushed " << node.toString() << " to the stack." << endl;
        pq.push(node);
    }
}

template<class T>
void StackUsingPriorityQueue<T>::pop()
{
    if (empty())
    {
        throw out_of_range("Deletion failed. The stack is currently empty.");
    }
    else
    {
        pq.pop();
        clog << "Popped an element from the stack." << endl;
        if (empty())
        {
            clog << "The stack is now empty." << endl;
            resetIndex();
        }
    }
}

template<class T>
T StackUsingPriorityQueue<T>::top() const
{
    if (empty())
    {
        throw out_of_range("Retrieval failed. The stack is currently empty.");
    }
    else
    {
        Node<T> node = pq.top();
        clog << "Element on top: " << node.toString() << endl;
        return node.element;
    }
}

template<class T>
bool StackUsingPriorityQueue<T>::empty() const
{
    return pq.empty();
}

template<class T>
void StackUsingPriorityQueue<T>::resetIndex()
{
    currentIndex = 0;
    clog << "Index set to " << currentIndex << endl;
}

#endif //STACKSANDQUEUES_STACKUSINGPRIORITYQUEUE_H
