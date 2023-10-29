#include <bits/stdc++.h>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int to(int x, int k) { return x >= k ? 0 : k - x; }

  long long minIncrementOperations(vector<int> &nums, int k) {
    using ll = long long;
    int n = nums.size();
    vector<vector<ll>> dp(n, vector<ll>(3, INT_MAX));
    dp[2][0] = to(nums[0], k);
    dp[2][1] = to(nums[1], k);
    dp[2][2] = to(nums[2], k);
    for (int i = 3; i < n; ++i) {
      dp[i][0] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 2][2]));
      dp[i][1] = to(nums[i - 1], k) +
                 min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
      dp[i][2] = to(nums[i], k) +
                 min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
    }
    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  }
};