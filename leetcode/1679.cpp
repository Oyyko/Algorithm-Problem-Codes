#include "base.hpp"
#include <unordered_map>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int ans{};
    for (auto &n : nums) {
      mp[n]++;
    }
    for (auto &n : nums) {
      if (mp.find(k - n) != mp.end() && mp.find(n) != mp.end()) {
        if (k - n == n && mp[n] < 2)
          continue;
        ans++;
        mp[k - n]--;
        mp[n]--;
        if (mp[k - n] == 0) {
          mp.erase(k - n);
        }
        if (mp[n] == 0) {
          mp.erase(n);
        }
      }
    }
    return ans;
  }
};

int main() {}