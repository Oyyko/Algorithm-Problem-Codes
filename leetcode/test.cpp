#include <bits/stdc++.h>

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

int main()
{
    priority_queue<int> x;
    x.push(2);
    x.push(3);
    x.push(4);
    cout << x.top();
}