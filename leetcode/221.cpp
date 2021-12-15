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
    int dp[301][301];
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int row = matrix.size();
        if (!row)
            return 0;
        int col = matrix[0].size();
        if (!col)
            return 0;
        int ans{INT_MIN};
        vector<vector<int>> dp(row, vector<int>(col));
        for (int i{}; i < row; i++)
        {
            for (int j{}; j < col; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};

int main()
{
}