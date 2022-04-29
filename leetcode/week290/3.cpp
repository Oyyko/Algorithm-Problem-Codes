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
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        vector<vector<int>> h(101);
        for (auto &r : rectangles)
        {
            h[r[1]].push_back(r[0]);
        }
        for (int i = 1; i <= 100; ++i)
        {
            sort(h.begin(), h.end());
        }
        int n = points.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            int hh = points[i][1];
            int xx = points[i][0];
            for (int hhh = hh; hhh <= 100; ++hhh)
            {
                int idx = lower_bound(h[hhh].begin(), h[hhh].end());
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> r{{1, 2}, {2, 3}, {2, 5}};
    vector<vector<int>> p{{2, 1}, {1, 4}};
    s.countRectangles(r, p);
}