#include "../base.hpp"

class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid.front().size();
    for (int i = 1; i < m; ++i) {
      grid[i][0] = grid[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; ++i) {
      grid[0][i] = grid[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (i == 1 && j == 1) {
          cout << "AAA\n";
          cout << grid[i - 1][j - 1] << endl;
          cout << grid[i - 1][j] << endl;
          cout << grid[i][j - 1] << endl;
          cout << grid[i][j] << endl;
          cout << (-grid[i - 1][j - 1] + grid[i - 1][j] + grid[i][j - 1] +
                   grid[i][j]);
        }
        grid[i][j] =
            -grid[i - 1][j - 1] + grid[i - 1][j] + grid[i][j - 1] + grid[i][j];
      }
    }
    int cnt{};
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        if (grid[i][j] <= k) {
          cnt++;
        }
      }
    }
    return cnt;
  }
};

int main() {}