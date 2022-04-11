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
    constexpr ll pow10(int n)
    {
        if (n == 0)
            return 1;
        n--;
        ll ans = 1;
        for (; ans *= 10, n; n--)
            ;
        return ans;
    }
    ll rev(ll n)
    {
        ll ans{};
        while (n)
        {
            ans *= 10;
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        vector<ll> ans;
        if (intLength % 2 == 0)
        {
            ll dd = pow10(intLength / 2);
            ll d = dd / 10;
            for (auto &q : queries)
            {
                ll tmp = d + q - 1;
                if (tmp >= d * 10)
                {
                    ans.push_back(-1);
                    continue;
                }
                tmp = tmp * dd + rev(tmp);
                ans.push_back(tmp);
            }
        }
        else
        {
            ll dd = pow10((intLength + 1) / 2 - 1);
            for (auto &q : queries)
            {
                ll tmp = dd + q - 1;
                if (tmp >= dd * 10)
                {
                    ans.push_back(-1);
                    continue;
                }
                tmp = tmp * dd + rev(tmp / 10);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> x{2, 4, 6};
    pr(s.kthPalindrome(x, 4));
}