#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    int a = 100;
    int b = 300;
    tie(a, b) = pair{b, a};
    cout << a << b;
}