#include "../base.hpp"

class Solution {
public:
  int xx;
  int dis(int a, int b) { return (a - b < xx) ? a - b : xx; }
  int minOperations(string s1, string s2, int x) {
    xx = x;
    int n = s1.size();
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (s1[i] != s2[i]) {
        v.push_back(i);
      }
    }
    if (v.size() % 2 == 1)
      return -1;
    int ans{};
    int m = v.size();
    if (m == 0)
      return 0;
  }
};

int main() {}