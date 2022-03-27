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
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (auto &&x : piles)
        {
            int nn = x.size();
            if (nn >= 2)
            {
                for (int i = 1; i < nn; ++i)
                {
                    x[i] = x[i - 1] + x[i];
                }
            }
        }
        // cout << 333 << endl;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                for (int m = 1; m <= j && m <= piles[i - 1].size(); ++m)
                {
                    dp[i][j] = max(dp[i][j], piles[i - 1][m - 1] + dp[i - 1][j - m]);
                }
            }
        }
        // for (int i = 1; i <= n; ++i)
        // {
        //     for (int j = 1; j <= k; ++j)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][k];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v{{1}, {1, 1, 100}};
    cout << s.maxValueOfCoins(v, 3);
}