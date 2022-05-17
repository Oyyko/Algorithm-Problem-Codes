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
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        sort(ranges.begin(), ranges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int ll = ranges[0][0];
        int rr = ranges[0][1];
        if (left < ll)
            return false;
        if (right <= rr)
            return true;
        for (auto &ran : ranges)
        {
            if (ran[0] > rr + 1)
            {
                ll = ran[0];
                if (left < ll)
                    return false;
                rr = ran[1];
            }
            else
                rr = max(rr, ran[1]);
            // cout << rr << endl;
            if (right <= rr)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{3, 3}, {1, 1}};
    cout << s.isCovered(v, 3, 3);
}