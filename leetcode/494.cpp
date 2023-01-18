#include <bits/stdc++.h>

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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum{accumulate(nums.begin(), nums.end(), 0)};
        int neg = sum - target;
        if (neg < 0 || neg & 1 == 1)
        {
            return 0;
        }
        neg /= 2;
        vector<int> dp(neg + 1, 0);
        dp[0] = 1;
        for (auto num : nums)
        {
            for (int j{neg}; j >= num; --j)
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }
};

int main()
{
}