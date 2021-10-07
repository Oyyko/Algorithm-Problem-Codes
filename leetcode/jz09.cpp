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
class CQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    CQueue()
    {
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (s2.empty() == 1)
        {
            while (s1.empty() != 1)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
        {
            return -1;
        }
        int vv = s2.top();
        s2.pop();
        return vv;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
}