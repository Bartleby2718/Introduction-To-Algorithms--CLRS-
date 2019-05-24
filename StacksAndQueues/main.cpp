#include <iostream>
#include "DequeUsingArray.h"
#include "QueueUsingArray.h"
#include "QueueUsingPriorityQueue.h"
#include "QueueUsingStacks.h"
#include "StackUsingArray.h"
#include "StackUsingQueues.h"
#include "StackUsingPriorityQueue.h"

using namespace std;

void testStackUsingArrayWithTextbookData()
{
    /** #10.1-1 stack using array (default constructor) */
    StackUsingArray<int> s1;
    s1.push(4);
    s1.top();
    s1.push(1);
    s1.top();
    s1.push(3);
    s1.top();
    s1.pop();
    s1.top();
    s1.push(8);
    s1.top();
    s1.pop();
    s1.top();
}

void testStackUsingArrayEdgeCases()
{
    /** #10.1-1 stack using array (parameterized constructor) */
    StackUsingArray<int> s2(1);
    try
    {
        s2.top();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    s2.push(11);
    try
    {
        s2.push(13);
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    s2.pop();
    try
    {
        s2.pop();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

void testQueueUsingArrayWithTextbookData()
{
    /** #10.1-3 queue using array */
    QueueUsingArray<int> q1(3);
    q1.enqueue(4);
    q1.print();
    q1.enqueue(1);
    q1.print();
    q1.enqueue(3);
    q1.print();
    q1.dequeue();
    q1.print();
    q1.enqueue(8);
    q1.print();
    q1.dequeue();
    q1.print();
}

void testQueueUsingArrayEdgeCases()
{
    /** #10.1-4 queue detecting overflow & underflow */
    QueueUsingArray<int> q2(3);
    try
    {
        q2.dequeue();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    q2.enqueue(5);
    q2.print();
    q2.enqueue(6);
    q2.print();
    q2.enqueue(7);
    q2.print();
    try
    {
        q2.enqueue(8);
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    q2.dequeue();
    q2.print();
    q2.dequeue();
    q2.print();
    q2.dequeue();
    q2.print();
    try
    {
        q2.dequeue();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    q2.enqueue(9);
    q2.print();
    q2.enqueue(10);
    q2.print();
    q2.enqueue(11);
    q2.print();
}

void testQueueUsingStacksEdgeCases()
{
    /** #10.1-6 queue using two stacks */
    QueueUsingStacks<int> qs1;
    try
    {
        qs1.dequeue();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    qs1.enqueue(5);
    qs1.enqueue(6);
    qs1.enqueue(7);
    qs1.dequeue();
    qs1.dequeue();
    qs1.enqueue(8);
    qs1.dequeue();
    qs1.dequeue();
    try
    {
        qs1.front();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

void testStackUsingQueuesEdgeCases()
{
    /** #10.1-7 stack using two queues */
    StackUsingQueues<int> sq1;
    try
    {
        sq1.top();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    sq1.push(1);
    sq1.print();
    sq1.push(2);
    sq1.print();
    sq1.push(3);
    sq1.print();
    sq1.push(4);
    sq1.print();
    sq1.pop();
    sq1.print();
    sq1.push(5);
    sq1.print();
    sq1.pop();
    sq1.print();
    sq1.pop();
    sq1.print();
    sq1.pop();
    sq1.print();
    sq1.pop();
    sq1.print();
    try
    {
        sq1.pop();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

void testQueueUsingPriorityQueuesEdgeCases()
{
    /** #6.5-7 queue using priority queue */
    QueueUsingPriorityQueue<double> q;
    try
    {
        q.front();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    q.enqueue(0.7);
    q.dequeue();
    q.enqueue(0.8);
    q.dequeue();
    q.enqueue(0.1);
    q.enqueue(0.2);
    q.enqueue(0.3);
    q.dequeue();
    q.enqueue(0.4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    try
    {
        q.dequeue();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

void testQueueUsingPriorityQueueOverflow()
{
    /** takes too much time unless the data model is LP32
     *  In order to run this test, redefine currentIndex to be unsigned short */
    QueueUsingPriorityQueue<int> q;
    for (auto i = 0; i < numeric_limits<decltype(q.currentIndex)>::max(); ++i)
    {
        q.enqueue(0);
    }
    try
    {
        q.enqueue(0);
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

void testStackUsingPriorityQueue()
{
    /** #6.5-7 stack using priority queue */
    StackUsingPriorityQueue<float> s;
    try
    {
        s.top();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    s.push(1.1);
    s.top();
    s.pop();
    s.push(1.2);
    s.top();
    s.push(1.3);
    s.top();
    s.pop();
    s.top();
    s.pop();
    try
    {
        s.pop();
    } catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

void testDequeUsingArray()
{
    /** #10.1-5 deque using array */
    DequeUsingArray<unsigned long> d;
    try
    {
        auto x = d[0];
        cout << "Element at index 0: " << x << endl;
    } catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }
    d.pushFront(333333333333333);
    d.back();
    d.print();
    d.pushFront(22222222222222222);
    d.print();
    d.pushFront(111111111111111);
    cout << "Element at index 0: " << d[0] << endl;
    cout << "Element at index 1: " << d[1] << endl;
    cout << "Element at index 2: " << d[2] << endl;
    try
    {
        auto y = d[3];
        cout << "Element at index 3: " << y << endl;
    } catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }
    d.pushFront(0);
    d.pushFront(0);
    try
    {
        d.pushFront(0);
    } catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }
    d.popFront();
    d.popFront();
    d.print();
    d.popBack();
    d.print();
    d.popFront();
    d.print();
    d.pushBack(44444444444444444);
    d.print();
    d.popFront();
    d.print();
    d.front();
    d.popFront();
    d.print();
    d.pushBack(5555555555555555555);
    d.front();
    d.back();
    d.popBack();
    try
    {
        d.popFront();
    } catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }
}

void testDequeUsingArrayZeroCapacity()
{
    DequeUsingArray<unsigned long> d(3);
    d.pushFront(1);
    d.popBack();
    d.pushFront(1);
    d.popBack();
    d.pushFront(1);
    d.popBack();
    d.print();
    try
    {
        d.pushFront(1);
    } catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    testStackUsingArrayWithTextbookData();
    testStackUsingArrayEdgeCases();
    testQueueUsingArrayWithTextbookData();
    testQueueUsingArrayEdgeCases();
    testDequeUsingArray();
    testQueueUsingStacksEdgeCases();
    testStackUsingQueuesEdgeCases();
    testQueueUsingPriorityQueuesEdgeCases();
    // testQueueUsingPriorityQueueOverflow(); // read the docstring before uncommenting
    testStackUsingPriorityQueue();
    testDequeUsingArrayZeroCapacity();
    return 0;
}
