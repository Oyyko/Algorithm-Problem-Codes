#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    double ans{}, tmp{};
    int n = nums.size();
    int i{}, j{k - 1};
    for (int t = i; t <= j; ++t) {
      tmp += nums[t];
    }
    tmp /= k + 0.0;
    ans = tmp;
    ++i, ++j;
    for (; j < n; ++i, ++j) {
      tmp *= k;
      tmp -= nums[i-1];
      tmp += nums[j];
      tmp /= k + 0.0;
      ans = max(ans, tmp);
    }
    return ans;
  }
};

int main() {}