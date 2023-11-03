#include "../base.hpp"
#include <vector>

class Solution {
public:
  int minimumSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> l(n, INT_MAX), r(n, INT_MAX);
    for (int i = 1; i < n; ++i) {
      l[i] = min(l[i - 1], nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
      r[i] = min(r[i + 1], nums[i + 1]);
    }
    int ans = INT_MAX;
    for (int k = 0; k < n; ++k) {
      if (nums[k] > l[k] && nums[k] > r[k])
        ans = min(ans, l[k] + r[k] + nums[k]);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

int main() {}