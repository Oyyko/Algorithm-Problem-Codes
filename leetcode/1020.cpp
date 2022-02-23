#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

using LL = long long;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << " ";
    }
    cout << endl;
}

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || i < 0 || j >= n || j < 0)
            return;
        if (vis[i][j])
            return;
        if (grid[i][j] == 0)
            return;
        vis[i][j] = 1;
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int cnt{};
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 || m == 2 || n == 1 || n == 2)
            return 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i{}; i < m; ++i)
        {
            dfs(i, 0, grid, vis);
            dfs(i, n - 1, grid, vis);
        }
        for (int j{}; j < n; ++j)
        {
            dfs(0, j, grid, vis);
            dfs(m - 1, j, grid, vis);
        }
        // for (int i{}; i < m; ++i)
        // {
        //     for (int j{}; j < n; ++j)
        //     {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i{1}; i < m - 1; ++i)
        {
            for (int j{1}; j < n - 1; ++j)
            {
                cnt += (grid[i][j] == 1 && vis[i][j] == 0);
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << s.numEnclaves(grid);
}