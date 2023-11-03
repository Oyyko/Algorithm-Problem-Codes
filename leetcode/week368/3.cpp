#include "../base.hpp"
#include <unordered_map>

class Solution {
public:
  int minGroupsForValidAssignment(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (auto &c : nums) {
      mp[c]++;
    }
    int r = INT_MAX;
    for (auto &[k, v] : mp) {
      r = min(r, v);
    }
    r += 1;
    int l = 1;
    int mid;
    int gg;
    int ans{};
    auto is_ok = [&](int mid) -> bool {
      for (auto &[k, v] : mp) {
        if (v % mid == 0 || v % mid == (mid - 1)) {
        } else {
          return false;
        }
      }
      return true;
    };
    while (l + 1 < r) {
      mid = l + (r - l) / 2;
      if (is_ok(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (is_ok(r))
      gg = r;
    else
      gg = l;
    for (auto &[k, v] : mp) {
      if (v == gg - 1)
        ans++;
      else {
        ans += upper_divide(v, gg);
      }
    }
    return ans;
  }
};

int main() {}