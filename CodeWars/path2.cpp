#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
#include <climits>
using namespace std;

int path_finder(string maze)
{
    // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
    // starting from (0, 0) in a n × n maze (represented as a string)
    // and return a boolean value accordingly
    using pii = pair<int, int>;
    int n = (sqrt(5 + 4 * maze.length()) - 1) / 2;
    int xx{}, yy{};
    vector<vector<bool>> mp(n, vector<bool>(n, 0));
    vector<vector<int>> dis(n, vector<int>(n, 0xfffff));
    for (const auto &x : maze)
    {
        if (x == '\n')
            continue;
        mp[yy][xx] = x == 'W' ? 1 : 0;
        xx++;
        if (xx == n)
            xx = 0, yy++;
    }
    queue<pii> q;
    q.push({0, 0});
    dis[0][0] = 0;
    auto is_legal = [&](int x, int y) -> bool
    { return x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1; };
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        auto [x, y] = tmp;
        if (is_legal(x + 1, y) && mp[x + 1][y] == 0 && dis[x + 1][y] > dis[x][y] + 1)
        {
            dis[x + 1][y] = dis[x][y] + 1;
            q.push({x + 1, y});
        }
        if (is_legal(x - 1, y) && mp[x - 1][y] == 0 && dis[x - 1][y] > dis[x][y] + 1)
        {
            dis[x - 1][y] = dis[x][y] + 1;
            q.push({x - 1, y});
        }
        if (is_legal(x, y + 1) && mp[x][y + 1] == 0 && dis[x][y + 1] > dis[x][y] + 1)
        {
            dis[x][y + 1] = dis[x][y] + 1;
            q.push({x, y + 1});
        }
        if (is_legal(x, y - 1) && mp[x][y - 1] == 0 && dis[x][y - 1] > dis[x][y] + 1)
        {
            dis[x][y - 1] = dis[x][y] + 1;
            q.push({x, y - 1});
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return dis[n - 1][n - 1] == 0xfffff ? -1 : dis[n - 1][n - 1];
}

int main()
{
    cout << path_finder(".W.\n.W.\n...");
}