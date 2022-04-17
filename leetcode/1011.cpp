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

// 0 0 0 0 1 1 1 1

class Solution
{
public:
    bool check(vector<int> &weights, int days, int ship)
    {
        int tmp{};
        int dd{};
        for (auto &x : weights)
        {
            tmp += x;
            if (tmp > ship)
                dd++, tmp = x;
            if (dd > days)
                return false;
        }
        if (tmp)
            dd++;
        if (dd > days)
            return false;
        return 1;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 0, r = INT_MAX;
        l = accumulate(weights.begin(), weights.end(), INT_MIN, [](auto &&x, auto &&y)
                       { return max(x, y); });
        cout << l << endl;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(weights, days, mid))
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
    Solution s;
    vector<int> v{1, 2, 3, 1, 1};
    cout << s.shipWithinDays(v, 4);
}