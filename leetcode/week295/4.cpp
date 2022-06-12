#include <iostream>
#include <random>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    int ans = INT_MAX;
    vector<vector<int>> dp;
    int m, n;
#define IS(x, y) (grid[x][y] == 1 ? 1 : 0)
#define LEGAL(x, y) (x >= 0 && y >= 0 && x <= m - 1 && y <= n - 1)
    void dfs(int x, int y, int num, const vector<vector<int>> &grid)
    {
        // cout << x << y << endl;
        if (dp[x][y] <= num)
            return;
        dp[x][y] = num;
        if (LEGAL(x + 1, y))
            dfs(x + 1, y, num + IS(x + 1, y), grid);
        if (LEGAL(x - 1, y))
            dfs(x - 1, y, num + IS(x - 1, y), grid);
        if (LEGAL(x, y + 1))
            dfs(x, y + 1, num + IS(x, y + 1), grid);
        if (LEGAL(x, y - 1))
            dfs(x, y - 1, num + IS(x, y - 1), grid);
    }
    int minimumObstacles(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        dfs(0, 0, IS(0, 0), grid);
        return dp[m - 1][n - 1];
    }
};

int main()
{
}