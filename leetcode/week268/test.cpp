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
    vector<pair<int, int>> v{{3, 1}, {4, 1}, {7, 2}, {12, 3}};
    cout << (*upper_bound(v.begin(), v.end(), make_pair(4, 0), [](auto &a, auto &b)
                          { return a.first < b.first; }))
                .first;
}