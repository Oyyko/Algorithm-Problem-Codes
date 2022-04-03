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
        for (auto &x : piles)
            partial_sum(x.begin(), x.end(), x.begin());
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= j && k <= piles[i - 1].size(); ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + piles[i - 1][k - 1]);
                }
            }
        }
        return dp[n][k];
    }
};

int main()
{
}