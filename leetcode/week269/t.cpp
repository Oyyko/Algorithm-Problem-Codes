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
    set<int> tt;
    tt.insert(3);
    tt.insert(2);
    tt.insert(5);
    for (auto &x : tt)
    {
        cout << x;
    }
}