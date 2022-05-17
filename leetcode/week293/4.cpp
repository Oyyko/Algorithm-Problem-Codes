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

class CountIntervals
{
public:
    vector<pair<int, int>> intervals;
    // vector<pair<int, int>> insert(int left, int right)
    // {
    //     bool placed = false;
    //     vector<pair<int, int>> ans;
    //     for (const auto &interval : intervals)
    //     {
    //         if (interval.first > right)
    //         {
    //             if (!placed)
    //             {
    //                 ans.push_back({left, right});
    //                 placed = true;
    //             }
    //             ans.push_back(interval);
    //         }
    //         else if (interval.second < left)
    //         {
    //             ans.push_back(interval);
    //         }
    //         else
    //         {
    //             left = min(left, interval.first);
    //             right = max(right, interval.second);
    //         }
    //     }
    //     if (!placed)
    //     {
    //         ans.push_back({left, right});
    //     }
    //     return ans;
    // }

    void insert(int left, int right)
    {
        bool placed = false;
        int n = intervals.size();
        int i = 0;
        for (const auto &interval : intervals)
        {
            if (interval.first > right)
            {
                if (!placed)
                {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval.second < left)
            {
                ans.push_back(interval);
            }
            else
            {
                left = min(left, interval.first);
                right = max(right, interval.second);
            }
        }
        if (!placed)
        {
            ans.push_back({left, right});
        }
        return ans;
    }

    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        intervals = insert(left, right);
    }

    int count()
    {
        int ans{};
        for (auto &x : intervals)
        {
            ans += x.second - x.first + 1;
        }
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main()
{
}