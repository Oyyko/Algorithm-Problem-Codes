#include "base.hpp"


class Solution {
public:
  int maxSubarrayLength(vector<int> &nums) {
    vector<int> picked;
    int n = nums.size();
    int minn_now = {INT_MAX};
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] < minn_now) {
        picked.push_back(i);
        minn_now = nums[i];
      }
    }
    reverse(picked.begin(),picked.end());
    int i{}, j{}, ans{1};
    for (; i < n; ++i) {
      while (j < picked.size() && (i>=picked[j] || nums[i]>nums[picked[j]])) {
        if(picked[j]-i+1 > ans){
          ans=picked[j]-i+1;
        }
        j++;
      }
      if(j==picked.size())break;
    }
    return ans==1?0:ans;
  }
};

int main() {}