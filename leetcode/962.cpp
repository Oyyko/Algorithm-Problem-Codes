#include "base.hpp"

class Solution {
public:
  int maxWidthRamp(vector<int> &nums) {
    int n = nums.size();
    int maxx = INT_MIN;
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] > maxx) {
        maxx = nums[i];
        s.push(i);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && (i >= s.top() || nums[i] <= nums[s.top()])) {
        ans = max(ans, s.top() - i);
        s.pop();
      }
    }
    return ans;
  }
};

int main() {}