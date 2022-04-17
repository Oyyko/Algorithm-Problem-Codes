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
    using ll = long long;
    bool check(vector<int> &c, ll k, int num)
    {
        for (auto &&x : c)
        {
            k -= x / num;
            if (k <= 0)
                return 1;
        }
        return 0;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int l = 0, r = INT_MAX;
        // 111000
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (mid == 0)
                return 0;
            if (check(candies, k, mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l - 1;
    }
};

int main()
{
}