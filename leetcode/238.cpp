#include "base.hpp"
#include <vector>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> l_product(n, 1), r_product(n, 1);
    l_product[0] = nums[0];
    r_product[n - 1] = nums[n - 1];
    for (int i = 1; i < n; ++i) {
      l_product[i] = l_product[i - 1] * nums[i];
    }
    for (int i = n - 2; i >= 0; --i) {
      r_product[i] = r_product[i + 1] * nums[i];
    }
    vector<int> ans(n, 0);
    ans[0] = r_product[1];
    ans[n - 1] = l_product[n - 2];
    for (int i = 1; i <= n - 2; ++i) {
      ans[i] = l_product[i - 1] * r_product[i + 1];
    }
    return ans;
  }
};

int main() {}