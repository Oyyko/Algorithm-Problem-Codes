#include "base.hpp"
#include <numeric>
#include <vector>

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    int lsum{};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (int i{}; i < n; ++i) {
      if (lsum == sum - lsum - nums[i]) {
        return i;
      }
      lsum += nums[i];
    }
    return -1;
  }
};

int main() {}