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
    int check(vector<int> &nums, int a)
    {
        int ans = a;
        for (auto &x : nums)
        {
            ans -= x >= a;
        }
        return ans;
    }
    int specialArray(vector<int> &nums)
    {
        int l = 0;
        int n = nums.size();
        int r = accumulate(nums.begin(), nums.end(), INT_MIN, [](int a, int b)
                           { return max(a, b); });
        r = min(r, n);
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int x = check(nums, mid);
            if (x < 0)
            {
                l = mid + 1;
            }
            else if (x > 0)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        if (check(nums, l) == 0)
            return l;
        return -1;
    }
};

int main()
{
}