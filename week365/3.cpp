#include "../leetcode/base.hpp"
#include <climits>
#include <numeric>
#include <unordered_map>
#include <vector>

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int minSizeSubarray(vector<int> &nums, int target) {
    int n = nums.size();
    unordered_map<ll, int> postsum;
    vector<ll> presum(n, 0);
    vector<ll> ppsum(n, 0);
    presum[0] = nums.front();
    ppsum.back() = nums.back();
    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + nums[i];
    }
    for (int i = n - 2; i >= 0; --i) {
      ppsum[i] = ppsum[i + 1] + nums[i];
    }
    for (int i = 0; i < n; ++i) {
      postsum[ppsum[i]] = n - i;
    }
    ll all_sum = accumulate(nums.begin(), nums.end(), 0ll);
    ll mod = target % all_sum;
    ll cishu = (target - mod) / all_sum;
    int ans = INT_MAX;
    if (mod == 0) {
      ans = cishu * n;
    }
    ll tmp = cishu * n;
    if (postsum.find(mod) != postsum.end()) {
      ans = min(ans + 0ll, tmp + postsum[mod]);
    }
    for (int i = 0; i < n; ++i) {
      if (mod < presum[i]) {
        break;
      }
      ll want = mod - presum[i];
      if (want == 0) {
        ans = min(ans + 0ll, i + 1 + tmp);
      }

      if (postsum.find(want) != postsum.end()) {
        ans = min(ans + 0ll, tmp + i + 1 + postsum[want]);
      }
    }

    tmp -= n;
    mod += all_sum;
    for (int i = 0; i < n; ++i) {
      if (mod < presum[i]) {
        break;
      }
      ll want = mod - presum[i];
      if (postsum.find(want) != postsum.end()) {
        ans = min(ans + 0ll, tmp + i + 1 + postsum[want]);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};

int main() {}