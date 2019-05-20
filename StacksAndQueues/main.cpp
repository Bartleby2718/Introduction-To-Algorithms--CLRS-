#include <iostream>
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

    // TODO: queue using array
    // TODO: queue detecting underflow/overflow
    // TODO: deque using array
    // TODO: queue using two stacks
    // TODO: stack using two queues
    return 0;
}
