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
    bool check(vector<int> &nums, int t, int mid)
    {
        int ans{};
        for (auto &x : nums)
        {
            ans += upper_divide(x, mid);
            if (ans > t)
                return 0;
        }
        return 1;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1, r = INT_MAX;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, threshold, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
}