#include "../base.hpp"
#include <vector>

class Solution {
public:
  vector<int> findIndices(vector<int> &nums, int indexDifference,
                          int valueDifference) {
    int ans1 = -1, ans2 = -1, n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (abs(i - j) >= indexDifference &&
            abs(nums[i] - nums[j]) >= valueDifference) {
              return vector<int>{i,j};
        }
      }
    }
    return vector<int>{-1,-1};
  }
};

int main() {}