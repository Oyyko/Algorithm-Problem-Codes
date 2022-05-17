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
    using pii = pair<int, int>;
    vector<pair<int, int>> intervals;
    int ans = 0;

    CountIntervals()
    {
    }
    void pr()
    {
        for (auto &x : intervals)
        {
            cout << x.first << " " << x.second << endl;
        }
        cout << endl;
    }
    bool yes(int mid, int left)
    {
        return intervals[mid].second >= left;
    }

    void add(int left, int right)
    {
        bool placed = false;
        int n = intervals.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (yes(mid, left))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        for (int i = l; i < intervals.size(); ++i)
        {
            auto interval = intervals[i];
            if (interval.first > right)
            {
                if (!placed)
                {
                    // ans.push_back({left, right});
                    intervals.insert(intervals.begin() + i, {left, right});
                    ans += right - left + 1;
                    placed = true;
                    break;
                }
                // ans.push_back(interval);
            }
            else if (interval.second < left)
            {
                // ans.push_back(interval);
            }
            else
            {
                ans -= interval.second - interval.first + 1;
                intervals.erase(intervals.begin() + i);
                i--;
                left = min(left, interval.first);
                right = max(right, interval.second);
            }
        }
        if (!placed)
        {
            intervals.insert(intervals.end(), {left, right});
            ans += right - left + 1;
        }
    }

    int count()
    {
        return ans;
    }
};

int main()
{
    CountIntervals c;
    c.add(10, 27);
    c.pr();
    c.add(46, 50);
    c.pr();
    c.add(15, 35);
    c.pr();
    c.add(12, 32);
    c.pr();
    c.add(7, 15);
    c.pr();
    c.add(49, 49);
    c.pr();
    cout << c.count();
}