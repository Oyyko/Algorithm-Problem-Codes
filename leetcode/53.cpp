#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSubArray{}, nowSubArray{};
    maxSubArray = nowSubArray = nums.front();
    for (int i = 1; i < nums.size(); ++i) {
      int num = nums[i];
      if (nowSubArray < 0) {
        nowSubArray = num;
      } else {
        nowSubArray = num + nowSubArray;
      }
      maxSubArray = max(maxSubArray, nowSubArray);
    }
    return maxSubArray;
  }
};

int main() {}