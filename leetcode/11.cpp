#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int l{}, n = height.size(), r{n - 1};
    int ans{-1};
    while (l < r) {
      ans = max(ans, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) {
        l++;
      } else if (height[l] > height[r]) {
        r--;
      } else {
        l++;
        r--;
      }
    }
    return ans;
  }
};

int main() {}