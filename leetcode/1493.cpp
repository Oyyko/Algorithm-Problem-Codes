#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int l{}, r{}, now_zeros{};
    int ans{};
    for (; r < n; r++) {
      now_zeros += nums[r] == 0;
      while (now_zeros >= 2) {
        now_zeros -= nums[l] == 0;
        l++;
      }
      if (now_zeros == 0) {
        ans = max(ans, r - l);
      } else if (now_zeros == 1) {
        ans = max(ans, r - l);
      }
    }
    return ans;
  }
};

int main() {}