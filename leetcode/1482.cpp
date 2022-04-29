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
    bool check(vector<int> &b, int m, int k, int day)
    {
        int f_num{}, cnt{};
        for (auto &x : b)
        {
            if (x <= day)
            {
                f_num++;
                if (f_num == k)
                {
                    f_num = 0;
                    cnt++;
                }
            }
            else
            {
                f_num = 0;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int l = 1, r = accumulate(bloomDay.begin(), bloomDay.end(), -1, [](auto &&x, auto &&y)
                                  { return max(x, y); });
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(bloomDay, m, k, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        bool bb = check(bloomDay, m, k, l);
        if (bb)
            return l;
        return -1;
    }
};

int main()
{
    Solution s;
}