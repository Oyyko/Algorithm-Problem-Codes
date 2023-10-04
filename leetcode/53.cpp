#include "base.hpp"

  class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
      int n = nums.size();
      int now_max{};
      int ans=nums.front();
      for(auto&x: nums){
        now_max=max(now_max+x,x);
        ans=max(ans,now_max);
      }
      return ans;
    }
  };

int main() {}