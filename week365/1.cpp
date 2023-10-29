#include "../leetcode/base.hpp"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    ll ans{0};
    int n = nums.size();
    vi maxx(n, -1);
    maxx[n - 1] = nums.back();
    for (int i = n - 2; i >= 0; --i) {
      maxx[i] = max(maxx[i + 1], nums[i]);
    }
    // vi minn(n, 0);
    // minn[n - 1] = nums.back();
    // for (int i = n - 2; i >= 0; --i) {
    //   minn[i] = min(minn[i + 1], nums[i]);
    // }
    // for (int i = 0; i + 2 < n; ++i) {
    //   ans = max(ans, (nums[i] + 0ll - minn[i + 1]) * maxx[i + 2]);
    // }
    for (int i = 0; i + 2 < n; ++i) {
      for (int j = i + 1; j + 1 < n; ++j) {
        ans = max(ans, (nums[i] + 0ll - nums[j]) * maxx[j + 1]);
      }
    }
    return ans;
  }
};

int main() {}