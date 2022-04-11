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
    ll mod = 1e9 + 7;
    int maximumProduct(vector<int> &nums, int k)
    {
        int cnt_zero{};
        for (auto &x : nums)
        {
            cnt_zero += x == 0;
        }
        if (k < cnt_zero)
            return 0;
        k -= cnt_zero;
        for (auto &x : nums)
        {
            if (x == 0)
                x++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &x : nums)
            pq.push(x);
        while (k)
        {
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp + 1);
            k--;
        }
        ll tt = 1;
        while (!pq.empty())
        {
            tt *= pq.top();
            tt %= mod;
            pq.pop();
        }
        return tt;
    }
};

int main()
{
    Solution s;
    vector<int> v{0, 4};
    cout << s.maximumProduct(v, 5);
}