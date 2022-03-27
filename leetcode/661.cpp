#include <iostream>
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

template <typename T>
void pr(vector<vector<T>> x)
{
    for (auto &&xx : x)
    {
        for (auto &&yy : xx)
        {
            cout << yy << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        using area = tuple<int, int, int, int>;
        auto find = [&](int x, int y)
        {
            int x1, y1, x2, y2;
            x1 = max(0, x - 1);
            y1 = max(0, y - 1);
            x2 = min(m - 1, x + 1);
            y2 = min(n - 1, y + 1);
            return make_tuple(x1, y1, x2, y2);
        };
        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                auto &&[x1, y1, x2, y2] = find(i, j);
                int size = (x2 + 1 - x1) * (y2 + 1 - y1);
                int sum = dp[x2 + 1][y2 + 1] - dp[x1][y2 + 1] - dp[x2 + 1][y1] + dp[x1][y1];
                ans[i][j] = sum / size;
                // cout << i << " " << j << " " << x1 << y1 << x2 << y2 << "-----" << size << " " << sum << endl;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    pr(s.imageSmoother(v));
}