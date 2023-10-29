#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findKOr(vector<int> &nums, int k) {
    int set[32] = {0};
    for (auto &x : nums) {
      for (int i = 0; i < 32; ++i) {
        set[i] += (((1 << i) & x) == (1 << i));
      }
    }
    int ans{};

    for (int i = 0; i < 32; ++i) {
      if (set[i] >= k) {
        ans += (1 << i);
      }
    }
    return ans;
  }
};

int main() {}