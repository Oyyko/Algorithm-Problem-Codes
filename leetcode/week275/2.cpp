#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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
    int minSwaps(vector<int> &nums)
    {
        int ones{};
        int n = nums.size();
        for (auto &x : nums)
        {
            ones += x;
        }
        if (ones == n)
            return 0;
        if (n == 1)
            return 0;
        if (ones == 1 || ones == 0)
            return 0;
        vector<int> dp(n, 0);
        for (int i{}; i < ones; ++i)
        {
            dp[0] += nums[i];
        }
        int ans{dp[0]};
        for (int i = 1; i <= n - 1; ++i)
        {
            dp[i] = dp[i - 1] - nums[i - 1] + nums[(i + ones - 1) % n];
            ans = max(ans, dp[i]);
        }
        return ones - ans;
    }
};

int main()
{
    vector<int> v{1, 1, 1, 0, 0, 1, 0, 1, 1, 0};
    Solution s;
    cout << s.minSwaps(v);
}