#include "base.hpp"

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        if (n == 1)
            return vector<int>{0};
        const int inf = 0xfffff;
        vector<vector<int>> dp(2, vector<int>(n, inf));
        dp[0][0] = 0;
        dp[1][0] = 0;
        // 0 end with bule edge, 1 end with red edge
        vector<vector<int>> redin(n, vector<int>{}), bluein(n, vector<int>{});
        for (auto &v : redEdges)
            redin[v[1]].push_back(v[0]);
        for (auto &v : blueEdges)
            bluein[v[1]].push_back(v[0]);
        vector<int> ans(n, 0);
        ans[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            for (auto x : redin[i])
            {
                dp[0][i] = min(dp[0][i], dp[1][x] + 1);
            }
            for (auto x : bluein[i])
            {
                dp[1][i] = min(dp[1][i], dp[0][x] + 1);
            }
            ans[i] = min(dp[0][i], dp[1][i]);
            if (ans[i] == inf)
                ans[i] = -1;
        }
        return ans;
    }
};

int main()
{
}