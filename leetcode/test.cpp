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
    vector<int> v{1, 3, 5, 7, 2, 4, 6, 8};
    partial_sort(v.begin(), v.begin() + v.size(), v.end(), greater());
    pr(v);
}