#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

bool path_finder(string maze)
{
    // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
    // starting from (0, 0) in a n × n maze (represented as a string)
    // and return a boolean value accordingly
    int n = (sqrt(5 + 4 * maze.length()) - 1) / 2;
    int xx{}, yy{};
    vector<vector<bool>> mp(n, vector<bool>(n, 0));
    vector<vector<int>> steps(n, vector<int>(n, -1));
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    for (const auto &x : maze)
    {
        if (x == '\n')
            continue;
        mp[yy][xx] = x == 'W' ? 1 : 0;
        xx++;
        if (xx == n)
            xx = 0, yy++;
    }
    function<void(int, int, int)> dfs;
    dfs = [&](int x, int y, int last_steps)
    {
        if (x < 0 || y < 0 || x == n || y == n)
            return;
        if (!vis[y][x])
        {
            vis[y][x] = 1;
            if (mp[y][x] == 1)
                return;
            steps[y][x] = last_steps + 1;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        }
    };
    dfs(0, 0, -1);

    return steps[n - 1][n - 1];
}

int main()
{
    cout << path_finder(".W.\n.W.\n...");
}