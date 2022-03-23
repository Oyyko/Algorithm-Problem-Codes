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

class Solution
{
public:
    static constexpr int mod = 1e9 + 7;
    using ll = long long;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX / 2));

        for (int i{}; i < n; ++i)
            dist[i][i] = 0;
        for (auto &&road : roads)
            dist[road[0]][road[1]] = dist[road[1]][road[0]] = road[2];
        vector<int> vis(n, 0);
        for (int i{}; i < n; ++i)
        {
            int u = -1;
            for (int j{}; j < n; ++j)
            {
                if (!vis[j] && (u == -1 || dist[0][j] < dist[0][u]))
                    u = j;
            }
            vis[u] = 1;
            for (int j{}; j < n; ++j)
                dist[0][j] = min(dist[0][j], dist[0][u] + dist[u][j]);
        }

        vector<vector<int>> g(n);
        for (auto &&road : roads)
        {
            int x = road[0], y = road[1], z = road[2];
            int d = dist[0][y] - dist[0][x];
            if (d == z)
            {
                g[x].push_back(y);
            }
            else if (d == -z)
            {
                g[y].push_back(x);
            }
        }
        vector<int> dp(n, -1);
        function<int(int)> dfs = [&](int u)
        {
            if (u == n - 1)
                return 1;
            if (dp[u] != -1)
                return dp[u];
            dp[u] = 0;
            for (auto &x : g[u])
            {
                dp[u] += dfs(x);
                if (dp[u] >= mod)
                    dp[u] -= mod;
            }
            return dp[u];
        };
        return dfs(0);
    }
};

int main()
{
}