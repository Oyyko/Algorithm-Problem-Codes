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
    using pii = pair<int, int>;

public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
        for (int i{}; i < n; ++i)
            g[i][i] = 0;
        for (auto &e : edges)
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;
        vector<int> shortest_len(n, INT_MAX / 2);
        for (int i{}; i < n; ++i)
            shortest_len[i] = g[0][i];
        vector<int> vis(n, 0);
        for (int i{}; i < n; ++i)
        {
            int u = -1;
            for (int j{}; j < n; ++j)
                if (!vis[j] && (u == -1 || shortest_len[j] < shortest_len[u]))
                    u = j;
            vis[u] = 1;
            for (int j{}; j < n; ++j)
                shortest_len[j] = min(shortest_len[j], shortest_len[u] + g[u][j]);
        }
        // for (auto &x : shortest_len)
        // {
        //     cout << x << endl;
        // }
        int ans{};
        for (int i{}; i < n; ++i)
            if (maxMoves - shortest_len[i] >= 0)
                ans += 1;
        for (auto &e : edges)
        {
            int sum{};
            sum += maxMoves - shortest_len[e[0]] >= 0 ? maxMoves - shortest_len[e[0]] : 0;
            sum += maxMoves - shortest_len[e[1]] >= 0 ? maxMoves - shortest_len[e[1]] : 0;
            ans += min(sum, e[2]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{1, 2, 5}, {0, 3, 3}, {1, 3, 2}, {2, 3, 4}, {0, 4, 1}};
    cout << s.reachableNodes(v, 7, 5);
}