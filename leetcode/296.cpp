#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
private:
    int midd(vector<int> x)
    {
        return x[x.size() / 2];
    }
    int dis(int x, int y, int q, int p)
    {
        return abs(x - q) + abs(y - p);
    }

public:
    int minTotalDistance(vector<vector<int>> &grid)
    {
        vector<int> row;
        vector<int> col;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j])
                {
                    row.push_back(i);
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[j][i])
                {
                    col.push_back(i);
                }
            }
        }
        int xmid = midd(row);
        int ymid = midd(col);
        int ans{};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                ans += dis(xmid, ymid, i, j) * (grid[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
    Solution s;
    cout << "ANS" << s.minTotalDistance(v);
}