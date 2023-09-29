#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int si{}, ti{};
    if (s.size() == 0)
      return true;
    for (; ti < t.size(); ++ti) {
      if (t[ti] == s[si]) {
        si++;
        if (si == s.size())
          return true;
      }
    }
    return false;
  }
};

int main() {}