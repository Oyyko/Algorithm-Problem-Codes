#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int ans{};
    int l{}, r{}, now_zeros{};
    for (; r < n; ++r) {
      now_zeros += nums[r] == 0;
      while (now_zeros > k) {
        now_zeros -= nums[l] == 0;
        l++;
      }
      ans = max(ans, r + 1 - l);
    }
    return ans;
  }
};

int main() {}