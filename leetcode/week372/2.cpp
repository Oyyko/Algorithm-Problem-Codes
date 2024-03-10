#include "../base.hpp"

class Solution {
public:
  long long minimumSteps(string s) {
    using ll = long long;
    s.push_back('1');
    ll tmp{};
    ll last_ones{};
    ll ans{};
    for (auto &x : s) {
      if (x == '1') {
        ans += last_ones * tmp;
        tmp = 0;
        last_ones++;
      } else {
        tmp++;
      }
    }
    return ans;
  }
};

int main() {}