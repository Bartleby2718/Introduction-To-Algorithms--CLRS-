//
// Created by bartl on 05/22/2019.
//

#ifndef STACKSANDQUEUES_QUEUEUSINGPRIORITYQUEUE_H
#define STACKSANDQUEUES_QUEUEUSINGPRIORITYQUEUE_H

#include <iostream>
#include <queue>

using namespace std;

template<class T>
struct Node
{
    unsigned index;
    T element;

    string toString()
    {
        return to_string(element) + "(index: " + to_string(index) + ")";
    }
};

template<class T>
bool operator<(const Node<T> &lhs, const Node<T> &rhs)
{
    return lhs.index < rhs.index;
}

template<class T>
class QueueUsingPriorityQueue
{
    priority_queue<Node<T>, vector<Node<T>>, greater<Node<T>>> pq; // minimum priority queue
    unsigned currentIndex;
public:
    QueueUsingPriorityQueue();

    void enqueue(const T &element);  // O(lgn)

    void dequeue();  // O(lgn)

    T front() const;  // O(1)

    bool empty() const;  // O(1)

    friend void testQueueUsingPriorityQueueOverflow();
};

template<class T>
QueueUsingPriorityQueue<T>::QueueUsingPriorityQueue()
{
    currentIndex = 0;
}

template<class T>
void QueueUsingPriorityQueue<T>::enqueue(const T &element)
{
    if (currentIndex >= numeric_limits<decltype(currentIndex)>::max())
    {
        throw out_of_range("Unable to enqueue. Too many insertions without resetting index.");
    }
    else
    {
        Node<T> newNode = {++currentIndex, element};
        clog << "Enqueued " << newNode.toString() << endl;
        pq.push(newNode);
    }
}

template<class T>
void QueueUsingPriorityQueue<T>::dequeue()
{
    if (empty())
    {
        throw out_of_range("Queue Underflow: The queue is already empty.");
    }
    else
    {
        Node<T> node = pq.top();
        clog << "Dequeued " << node.toString() << endl;
        pq.pop();
        if (empty())
        {
            currentIndex = 0;
            clog << "The queue is empty. Index reset to 0." << endl;
        }
    }
}

template<class T>
T QueueUsingPriorityQueue<T>::front() const
{
    if (empty())
    {
        throw out_of_range("The queue is empty.");
    }
    else
    {
        Node<T> node = pq.top();
        clog << "Element on the front: " << node.toString() << endl;
        return node.element;
    }
}

template<class T>
bool QueueUsingPriorityQueue<T>::empty() const
{
    return pq.empty();
}

#endif //STACKSANDQUEUES_QUEUEUSINGPRIORITYQUEUE_H
