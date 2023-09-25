#include "base.hpp"
#include <unordered_map>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    for (int i{}, _ = nums.size(); i < _; ++i) {
      mp[nums[i]] = i;
    }
    for (int i{}, _ = nums.size(); i < _; ++i) {
      if (auto itr = mp.find(target - nums[i]); itr != mp.end()) {
        if (i != itr->second)
          return {i, itr->second};
      }
    }
    return {};
  }
};

int main() {}