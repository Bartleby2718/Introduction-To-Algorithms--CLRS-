//
// Created by bartl on 06/21/2019.
//

#ifndef STACKSANDQUEUES_PRIORITYQUEUENODE_H
#define STACKSANDQUEUES_PRIORITYQUEUENODE_H

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
bool operator>(const Node<T> &lhs, const Node<T> &rhs)
{
    return operator<(rhs, lhs);
}

#endif //STACKSANDQUEUES_PRIORITYQUEUENODE_H
