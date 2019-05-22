#include <iostream>
#include "QueueUsingArray.h"
#include "QueueUsingStacks.h"
#include "StackUsingArray.h"
#include "StackUsingQueues.h"

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

int main()
{
    testStackUsingArrayWithTextbookData();
    testStackUsingArrayEdgeCases();
    testQueueUsingArrayWithTextbookData();
    testQueueUsingArrayEdgeCases();
    // TODO: #10.1-5 deque using array
    testQueueUsingStacksEdgeCases();
    testStackUsingQueuesEdgeCases();
    // TODO: #6.5-7 queue(enqueue, dequeue, getFront, isEmpty, clear), stack(push, pop, peek, isEmpty) using priority queue?
    return 0;
}
