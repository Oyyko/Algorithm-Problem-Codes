#include "../base.hpp"
#include <bits/floatn-common.h>

class Solution {
public:
  int sumIndicesWithKSetBits(vector<int> &nums, int k) {
    int ans{};
    int n=nums.size();
    for (int i{};i<n;++i) {
      if (__builtin_popcount(i) == k) {
        ans += nums[i];
      }
    }
    return ans;
  }
};

int main() {}