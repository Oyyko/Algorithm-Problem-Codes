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
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        map<int, int> mp;
        int n = intervals.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            mp[intervals[i][0]] = i;
        }
        for (auto &x : intervals)
        {
            auto itr = mp.lower_bound(x[1]);
            if (itr == mp.end())
                ans.push_back(-1);
            else
                ans.push_back(itr->second);
        }
        return ans;
    }
};

int main()
{
}