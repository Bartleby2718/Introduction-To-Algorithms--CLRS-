//
// Created by bartl on 05/24/2019.
//

#ifndef STACKSANDQUEUES_DEQUEUSINGARRAY_H
#define STACKSANDQUEUES_DEQUEUSINGARRAY_H

#include <iostream>

using namespace std;

template<class T>
class DequeUsingArray
{
    /** Implementation of deque using an array of fixed size */
    T *array;
    int head;  // index to push front
    int tail;  // index to push back
    int capacity;  // always even
    int getNumElements() const;

public:
    explicit DequeUsingArray(int halfCapacity);

    DequeUsingArray();

    ~DequeUsingArray();

    bool empty() const; // O(1)

    T front() const; // O(1)

    void pushFront(const T &element); // O(1) if the array is fixed, amortized O(1) otherwise

    void popFront(); // O(1)

    T back() const; // O(1)

    void pushBack(const T &element); // O(1) if the array is fixed, amortized O(1) otherwise

    void popBack(); // O(1)

    void print() const; // O(n)

    // O(1) because the deque was implemented using an array instead of a doubly linked list
    // only allow rvalue because insertion and deletion happens only on both ends
    const T &operator[](int index) const;
};

template<class T>
DequeUsingArray<T>::DequeUsingArray(int halfCapacity)
{
    capacity = 2 * halfCapacity;
    array = new T[capacity];
    head = halfCapacity - 1;
    tail = halfCapacity;
}

template<class T>
DequeUsingArray<T>::DequeUsingArray():DequeUsingArray(5)
{
}

template<class T>
DequeUsingArray<T>::~DequeUsingArray()
{
    delete[]array;
}

template<class T>
bool DequeUsingArray<T>::empty() const
{
    return head + 1 == tail;
}

template<class T>
T DequeUsingArray<T>::front() const
{
    if (empty())
    {
        throw out_of_range("front() failed. The deque is currently empty.");
    }
    else
    {
        const T element = array[head + 1];
        cout << "Element on the front: " << to_string(element) << endl;
        return element;
    }
}

template<class T>
void DequeUsingArray<T>::pushFront(const T &element)
{
    if (head < 0)
    {
        throw out_of_range("pushFront() failed. The deque is full on the front half.");
    }
    else
    {
        array[head--] = element;
        cout << "Pushed " << to_string(element) << " to the front." << endl;
    }
}

template<class T>
void DequeUsingArray<T>::popFront()
{
    if (empty())
    {
        throw out_of_range("popFront() failed. The deque is currently empty.");
    }
    else
    {
        cout << "Popped an element from the front." << endl;
        ++head;
    }
}

template<class T>
T DequeUsingArray<T>::back() const
{
    if (empty())
    {
        throw out_of_range("back() failed. The deque is currently empty.");
    }
    else
    {
        T element = array[tail - 1];
        cout << "Element on the back: " << to_string(element) << endl;
        return element;
    }
}

template<class T>
void DequeUsingArray<T>::pushBack(const T &element)
{
    if (tail >= capacity)
    {
        throw out_of_range("pushBack() failed. The deque is full on the back half.");
    }
    else
    {
        array[tail++] = element;
        cout << "Pushed " << to_string(element) << " to the back." << endl;
    }
}

template<class T>
void DequeUsingArray<T>::popBack()
{
    if (empty())
    {
        throw out_of_range("popBack() failed. The deque is currently empty.");
    }
    else
    {
        --tail;
        cout << "Popped an element from the back." << endl;
    }
}

template<class T>
const T &DequeUsingArray<T>::operator[](int index) const
{
    if (empty())
    {
        throw out_of_range("Array subscripting failed. The deque is currently empty.");
    }
    else if (index < 0 || index >= getNumElements())
    {
        throw out_of_range("No element at index " + to_string(index) + ".");
    }
    else
    {
        return array[(head + 1) + index];
    }
}

template<class T>
void DequeUsingArray<T>::print() const
{
    if (empty())
    {
        cout << "The deque is currently empty. " << endl;
    }
    else
    {
        int numElements = getNumElements();
        cout << "There " << ((numElements == 1) ? "is " : "are ");
        cout << numElements << " element" << ((numElements == 1) ? "" : "s");
        cout << " on the deque:";
        for (int i = head + 1; i < tail; ++i)
        {
            const T element = array[i];
            cout << " " << to_string(element);
        }
        cout << endl;
    }
}

template<class T>
int DequeUsingArray<T>::getNumElements() const
{
    return (tail - 1) - head;
}

#endif //STACKSANDQUEUES_DEQUEUSINGARRAY_H
