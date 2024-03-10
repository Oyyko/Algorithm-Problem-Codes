#include "../base.hpp"
#include <vector>

class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    vector<int> a, b;
    a.push_back(nums.front());
    b.push_back(nums[1]);
    int n = nums.size();
    int i = 2;
    while (i < n) {
      if (a.back() > b.back()) {
        a.push_back(nums[i]);
      } else {
        b.push_back(nums[i]);
      }
      i++;
    }
    for (auto &x : b) {
      a.push_back(x);
    }
    return a;
  }
};

int main() {}