/*225. Implement Stack using Queues
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

1.void push(int x) Pushes element x to the top of the stack.
2.int pop() Removes the element on the top of the stack and returns it.
3.int top() Returns the element on the top of the stack.
4.boolean empty() Returns true if the stack is empty, false otherwise.*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int topEle = q1.front();
        q1.pop();
        return topEle;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();

    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Top element: " << obj->top() << endl; // Should print 30

    cout << "Popped: " << obj->pop() << endl;      // Should print 30
    cout << "Top element: " << obj->top() << endl; // Should print 20

    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;

    obj->pop(); // Popping 20
    obj->pop(); // Popping 10

    cout << "Is stack empty now? " << (obj->empty() ? "Yes" : "No") << endl;

    delete obj;
    return 0;
}
