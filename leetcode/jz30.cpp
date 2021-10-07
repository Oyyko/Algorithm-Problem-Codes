#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

#include <stack>
class MinStack
{
public:
    stack<int> s;
    stack<int> mins;
    /** initialize your data structure here. */
    MinStack()
    {
        mins.push(INT32_MAX);
    }

    void push(int x)
    {
        s.push(x);
        if (x <= mins.top())
        {
            mins.push(x);
        }
    }
    void pop()
    {
        if (s.top() == mins.top())
        {
            mins.pop();
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int min()
    {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{
    MinStack ms;
    ms.push(1);
    //ms.push(2);
    //ms.push(3);
    //ms.push(2);
    //ms.push(1);
    //ms.push(-2);
    cout << ms.min();
}