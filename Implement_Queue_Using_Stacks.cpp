/*232. Implement Queue Using Stacks
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> pu;
    stack<int> po;
    void shiftStack()
    {
        if (po.empty())
        {
            while (!pu.empty())
            {
                po.push(pu.top());
                pu.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x)
    {
        pu.push(x);
    }

    int pop()
    {
        shiftStack();
        int t = po.top();
        po.pop();
        return t;
    }

    int peek()
    {
        shiftStack();
        return po.top();
    }

    bool empty()
    {
        if (pu.empty() && po.empty())
            return true;
        return false;
    }
};

int main()
{
    MyQueue *obj = new MyQueue();

    // Push elements into the queue
    obj->push(10);
    obj->push(20);
    obj->push(30);

    // Peek the front element
    cout << "Front element: " << obj->peek() << endl; // Should print 10

    // Pop elements
    cout << "Popped: " << obj->pop() << endl; // Should print 10
    cout << "Popped: " << obj->pop() << endl; // Should print 20

    // Check if queue is empty
    cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << endl; // Should print No

    // Peek and Pop the last element
    cout << "Front element: " << obj->peek() << endl; // Should print 30
    cout << "Popped: " << obj->pop() << endl;         // Should print 30

    // Check if queue is empty now
    cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << endl; // Should print Yes

    delete obj;
    return 0;
}
