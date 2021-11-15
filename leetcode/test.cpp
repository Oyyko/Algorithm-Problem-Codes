#include <bits/stdc++.h>

using namespace std;

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
    auto dfs = [](auto &&dfs, auto idx)
    {
        dfs(dfs, idx + 0);
    };
    auto fib = [](auto &&fib, int n)
    {
        if (n == 1 || n == 2)
            return 1;
        return fib(fib, n - 1) + fib(fib, n - 2);
    };
}