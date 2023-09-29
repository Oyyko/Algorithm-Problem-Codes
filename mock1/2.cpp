#include "../leetcode/base.hpp"
#include <algorithm>
#include <limits>
#include <string>
#include <vector>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  int kEmptySlots(vector<int> &bulbs, int k) {
    int n = bulbs.size();
    vector<int> days(n, 0);
    for (int i = 0; i < n; ++i) {
      days[bulbs[i] - 1] = i;
    }
    int left = 0, right = k + 1, res = std::numeric_limits<int>::max();
    for (int i = 0; right < n; ++i) {
      if (days[i] > days[left] && days[i] > days[right])
        continue;
      if (i == right) {
        res = min(res, max(days[left], days[right]));
      }
      left = i;
      right = i + k + 1;
    }
    return res == std::numeric_limits<int>::max() ? -1 : res + 1;
  }
};