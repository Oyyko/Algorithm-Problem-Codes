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
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto &e : edges)
        {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }

        vector<int> vis(n);
        vis[0] = true;
        int ans{};

        auto dfs = [&](auto &dfs, int u, int time, int value) -> void
        {
            if (u == 0)
            {
                ans = max(ans, value);
            }
            for (const auto &[v, dist] : g[u])
            {
                if (time + dist <= maxTime)
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        dfs(dfs, v, time + dist, value + values[v]);
                        vis[v] = false;
                    }
                    else
                    {
                        dfs(dfs, v, time + dist, value);
                    }
                }
            }
        };

        dfs(dfs, 0, 0, values[0]);
        return ans;
    }
};

int main()
{
}