#include "base.hpp"

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums) {
    vector<int> picked;
    int n = nums.size();
    int l{},r{};
    while(l<n){
      while(!(nums[l]>nums[r])){
        r++;
      }
    }
    
  }
};

int main()
{
  
}