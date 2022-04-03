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
    bool check(vector<int> &candies, long long k, ll ans)
    {
        ll cnt{};
        for (auto &x : candies)
        {
            cnt += x / ans;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        ll n = candies.size();
        ll sum = accumulate(candies.begin(), candies.end(), 0ll);
        if (k > sum)
            return 0;
        if (k == sum)
            return 1;
        ll l = 1, r = sum + 1;
        while (l < r - 1)
        {
            ll mid = l + (r - l) / 2;
            if (check(candies, k, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (l == r)
            return l;
        if (check(candies, k, r))
            return r;
        return l;
    }
};

int main()
{
    Solution s;
    vector<int> v{4, 7, 5};
    cout << s.maximumCandies(v, 4);
}