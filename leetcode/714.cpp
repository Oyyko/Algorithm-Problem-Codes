#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    vvi dp(n, vi(2, 0));
    dp[0][0] = 0;
    dp[0][1] = prices[0] - fee;
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][1] + prices[i - 1] - fee, dp[i - 1][0]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};

int main() {}