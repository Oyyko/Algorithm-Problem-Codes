#include "../base.hpp"

class Solution {
public:
  int countWays(vector<int> &nums) {
    sort(nums.begin(),nums.end());
    int ans{};int n=nums.size();
    if(0<nums[0])ans++;
    if(n==1){
      if(1>nums[0])ans++;
      return ans;
    }
    for(int i=1;i<n;++i){
      if(i<nums[i]&&i>nums[i-1]){
        ans++;
      }
    }
    if(n>nums.back())ans++;
    return ans;
  }
};

int main() {
  vector<int> v{6, 0, 3, 3, 6, 7, 2, 7};
  Solution s;
  cout << s.countWays(v);
}