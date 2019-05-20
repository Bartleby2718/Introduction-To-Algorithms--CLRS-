#include <iostream>
#include "QueueUsingArray.h"
#include "StackUsingArray.h"

using namespace std;

int main()
{
    // #10.1-1 stack using array (default constructor)
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

    // #10.1-1 stack using array (parameterized constructor)
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

    // #10.1-3 queue using array
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

    // #10.1-4 queue detecting overflow & underflow
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

    // TODO: queue detecting underflow/overflow
    // TODO: deque using array
    // TODO: queue using two stacks
    // TODO: stack using two queues
    return 0;
}
