#include "../base.hpp"

class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    set<int> s;
    for (int i{}; i < n; ++i) {
      s.insert(i);
    }
    for (auto &v : edges) {
      s.erase(v[1]);
    }
    if (s.size() == 1)
      return *s.begin();
    return -1;
  }
};

int main() {}