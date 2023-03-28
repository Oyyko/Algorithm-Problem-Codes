#include "base.hpp"

class Solution
{
public:
    int countVowelStrings(int n)
    {
        using ll = long long;
        vector<vector<ll>> dp(n + 1, vector<ll>(5, 0));
        for (int i = 0; i < 5; ++i)
        {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            dp[i][0] = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0ll);
            dp[i][1] = accumulate(dp[i - 1].begin() + 1, dp[i - 1].end(), 0ll);
            dp[i][2] = accumulate(dp[i - 1].begin() + 2, dp[i - 1].end(), 0ll);
            dp[i][3] = accumulate(dp[i - 1].begin() + 3, dp[i - 1].end(), 0ll);
            dp[i][4] = accumulate(dp[i - 1].begin() + 4, dp[i - 1].end(), 0ll);
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0ll);
    }
};

int main()
{
}