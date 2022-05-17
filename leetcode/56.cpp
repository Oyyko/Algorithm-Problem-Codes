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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int l = 0, r = 0, n = intervals.size();
        if (n == 1)
            return intervals;
        vector<vector<int>> ans;
        int nowl, nowr, i = 0;
        while (i < n)
        {
            nowl = intervals[i][0];
            nowr = intervals[i][1];
            i++;
            while (i < n && intervals[i][0] <= nowr)
            {
                nowr = max(nowr, intervals[i][1]);
                i++;
            }
            ans.push_back(vector<int>{nowl, nowr});
        }
        return ans;
    }
};
int main()
{
}