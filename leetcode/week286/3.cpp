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

class Solution
{
public:
    using ll = long long;
    ll pow10(int n)
    {
        ll ans = 1;
        for (int i{}; i < n; ++i)
            ans *= 10;
        return ans;
    }
    ll rev(ll x)
    {
        ll ans{};
        while (x)
        {
            int d = x % 10;
            ans *= 10;
            ans += d;
            x /= 10;
        }
        return ans;
    }
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        int n = queries.size();
        ll limit = pow10(intLength);
        vector<ll> ans{};
        ans.reserve(n);
        for (auto &x : queries)
        {
            if (intLength % 2 == 0)
            {
                int d = intLength / 2;
                ll dd = pow10(d);
                ll ddd = pow10(d - 1);
                ll dx = ddd + x - 1;
                ll t = dx * dd + rev(dx);
                if (t < limit)
                    ans.push_back(t);
                else
                    ans.push_back(-1);
            }
            else
            {
                int d = (intLength + 1) / 2;
                // cout << "D:" << d << endl;
                ll dd = pow10(d);
                ll ddd = pow10(d - 1);
                ll dx = ddd + x - 1;
                // cout << dx << " " << rev(dx / 10) << endl;
                ll t = dx * ddd + rev(dx / 10);
                if (t < limit)
                    ans.push_back(t);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 90};
    pr(s.kthPalindrome(v, 3));
}