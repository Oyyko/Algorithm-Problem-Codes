#include "../base.hpp"
#include <climits>

class Solution {
public:
  bool isY(int i, int j, int n) {
    int m = n / 2;
    if (i == j && i <= m && j <= m) {
      return true;
    }
    if (i + j == n - 1 && i <= m) {
      return true;
    }
    if (j == m && i >= m) {
      return true;
    }
    return false;
  }
  int cnt(int y, int ny, const vector<vector<int>> &grid) {
    int ans{};
    int n = grid.size();
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        if (isY(i, j, n)) {
          if (grid[i][j] != y) {
            ans++;
          }
        } else {
          if (grid[i][j] != ny) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
  int minimumOperationsToWriteY(vector<vector<int>> &grid) {
    int ans = INT_MAX;
    for (int y = 0; y <= 2; ++y) {
      for (int ny = 0; ny <= 2; ++ny) {
        if (y == ny)
          continue;
        ans = min(ans, cnt(y, ny, grid));
      }
    }
    return ans;
  }
};

int main() {}