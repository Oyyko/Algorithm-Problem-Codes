#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    using ll = long long;
    bool check(int n, vector<int> &b, ll t)
    {
        ll ans{};
        for (auto &bb : b)
        {
            ans += min(t, static_cast<ll>(bb));
            if (ans / t >= n)
            {
                return 1;
            }
        }
        return 0;
    }
    long long maxRunTime(int n, vector<int> &batteries)
    { // 1 1 1 0 0 0
        ll l = 0, r = LONG_LONG_MAX, mid;
        while (l < r - 1)
        {
            mid = l + (r - l) / 2;
            if (check(n, batteries, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (check(n, batteries, r))
            return r;
        return l;
    }
};

int main()
{
}