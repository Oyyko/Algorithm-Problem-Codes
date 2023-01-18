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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto &v : queries)
        {
            diff[v[0]][v[1]] += 1;
            diff[v[2] + 1][v[1]] -= 1;
            diff[v[0]][v[3] + 1] -= 1;
            diff[v[2] + 1][v[3] + 1] += 1;
        }
        ans[0][0] = diff[0][0];
        for (int j = 1; j < n; ++j)
        {
            ans[0][j] = ans[0][j - 1] + diff[0][j];
        }
        for (int i = 1; i < n; ++i)
        {
            ans[i][0] = ans[i - 1][0] + diff[i][0];
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + diff[i][j];

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{1, 1, 2, 2}, {0, 0, 1, 1}};
    s.rangeAddQueries(3, v);
}