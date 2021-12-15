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
    int a = 0b11111'0101;
    int b = 0b11111'1100;
    int x = min(a, b);
    int y = max(a, b);
    while (y > x)
    {
        y &= y - 1;
    }
    cout << y;
}