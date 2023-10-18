#include "base.hpp"

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        int ans{};
        for(int i=n-1;i>=0;--i){
          int num{};
          while(!s.empty() &&  nums[i]>nums[s.top()]){
            num++;
            s.pop();
          }
          s.push(i);
        }
    }
};

int main()
{
  
}