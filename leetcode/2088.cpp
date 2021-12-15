#include <bits/stdc++.h>

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
    int dp1[1005][1005] = {0};
    int dp2[1005][1005] = {0};
    // dp1[i][j]=min(dp1[i+1][j-1,j,j+1])+1;
    // dp2[i][j]=min(dp1[i-1][j-1,j,j+1])+1;
    int countPyramids(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        if (row == 1 || col == 1)
            return 0;
        if (row == 2 && col == 2)
            return 0;
        int ans{};
        auto is_tower1 = [&](int i, int j)
        { return grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i + 1][j + 1] == 1 && grid[i + 1][j - 1] == 1; };
        auto is_tower2 = [&](int i, int j)
        { return grid[i][j] == 1 && grid[i - 1][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 1][j - 1] == 1; };
        for (int i = row - 2; i >= 0; --i)
        {
            for (int j = 1; j <= col - 2; ++j)
            {
                if (is_tower1(i, j))
                {
                    dp1[i][j] = min({dp1[i + 1][j], dp1[i + 1][j - 1], dp1[i + 1][j + 1]}) + 1;
                    ans += dp1[i][j];
                }
            }
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j <= col - 2; ++j)
            {
                if (is_tower2(i, j))
                {
                    dp2[i][j] = min({dp2[i - 1][j], dp2[i - 1][j - 1], dp2[i - 1][j + 1]}) + 1;
                    ans += dp2[i][j];
                }
            }
        }
        for (int i{}; i < row; ++i)
        {
            for (int j{}; j < col; ++j)
                printf("%d ", dp1[i][j]);
            cout << endl;
        }
        cout << endl;
        for (int i{}; i < row; ++i)
        {
            for (int j{}; j < col; ++j)
                printf("%d ", dp2[i][j]);
            cout << endl;
        }
        return ans;
    }
};

int main()
{
}