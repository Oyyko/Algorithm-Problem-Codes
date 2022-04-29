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
    vector<int> intersection(vector<vector<int>> &nums)
    {
        vector<bool> yes(1001, false);
        // for (int i = 1; i <= 10; ++i)
        // {
        //     cout << yes[i] << endl;
        // }
        for (int i = 1; i <= 1000; ++i)
        {
            bool yy = 1;
            for (auto &x : nums)
            {
                bool found = 0;
                for (auto &y : x)
                {
                    if (y == i)
                    {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    yy = 0;
                    break;
                }
            }
            yes[i] = yy;
        }
        // for (int i = 1; i <= 10; ++i)
        // {
        //     cout << yes[i] << endl;
        // }
        vector<int> v;
        for (int i = 1; i <= 1000; ++i)
        {
            if (yes[i])
                v.push_back(i);
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{7, 34, 45, 10, 12, 27, 13}, {27, 21, 45, 10, 12, 13}};
    pr(s.intersection(v));
}