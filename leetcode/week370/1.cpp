#include "../base.hpp"

class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int n = grid.size();
    set<int> s;
    for (int i{}; i < n; ++i) {
      s.insert(i);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          s.erase(j);
        }
      }
    }
    if (s.size() == 1)
      return *s.begin();
    return -1;
  }
};

int main() {}