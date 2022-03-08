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
    int waysToMakeFair(vector<int> &nums)
    {
        int ans{};
        int even1{}, odd1{};
        int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return 0;
        for (int k{1}; k <= n - 1; ++k)
        {
            if (k & 1)
                odd1 += nums[k];
            else
                even1 += nums[k];
        }
        ans += odd1 == even1;
        int ll = 1, rr = 2;
        while (ll <= n - 1 && rr <= n - 1)
        {
            odd1 -= nums[ll];
            odd1 += nums[ll - 1];
            ll += 2;
            // cout << "LL" << ll << " RR" << rr << " ODD" << odd1 << " EVEN" << even1 << endl;
            ans += odd1 == even1;
            even1 -= nums[rr];
            even1 += nums[rr - 1];
            rr += 2;
            // cout << "LL" << ll << " RR" << rr << " ODD" << odd1 << " EVEN" << even1 << endl;

            ans += odd1 == even1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v = {2, 1, 6, 4};
    cout << s.waysToMakeFair(v);
}