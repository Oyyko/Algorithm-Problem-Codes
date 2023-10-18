#include "base.hpp"
#include <algorithm>

class Solution {
public:
  string robotWithString(string s) {
    int n = s.size();
    auto mini = min_element(s.begin(), s.end());
    reverse(s.begin(), mini + 1);
    while (mini != s.end() - 1) {
      auto tmp = mini;
      mini = min_element(mini + 1, s.end());
      reverse(tmp + 1, mini + 1);
    }
    return s;
  }
};

int main() {}