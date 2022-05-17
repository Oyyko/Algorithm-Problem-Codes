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
    map<int, int> mp;
    int ans;
    CountIntervals()
    {
        ans = 0;
    }

    void add(int left, int right)
    {
        for (auto itr = mp.lower_bound(left); itr != mp.end() && itr->second <= right; itr = mp.erase(itr))
        {
            left = min(left, itr->second);
            right = max(right, itr->first);
            ans -= (itr->first - itr->second + 1);
        }
        mp[right] = left;
        ans += right - left + 1;
    }

    int count()
    {
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