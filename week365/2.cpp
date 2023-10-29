#include "../leetcode/base.hpp"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    ll ans{0};
    ll last{0};
    int maxx{nums[0]};
    int n = nums.size();
    for (int k = 2; k < n; ++k) {
      maxx = max(maxx, nums[k - 2]);
      last = max(last, 0ll + maxx - nums[k - 1]);
      ans = max(ans, last * nums[k]);
    }

    return ans;
  }
};

int main() {}