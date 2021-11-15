#include <bits/stdc++.h>

using namespace std;

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
private:
    typedef unsigned long l;

public:
    int minPushBox(vector<vector<char>> &grid)
    {
        priority_queue<vector<l>, vector<vector<l>>, greater<vector<l>>> pq;
        l m = grid.size();
        l n = grid[0].size();
        vector<l> a(5, 0);
        for (l x{}; x < m; x++)
            for (l y{}; y < n; y++)
                (grid[x][y] != 'S' || (a[1] = x, a[2] = y, grid[x][y] = '.')), (grid[x][y] != 'B' || (a[3] = x, a[4] = y, grid[x][y] = '.'));
        pq.push(a);

        set<vector<l>> dist;
        dist.insert({a[1], a[2], a[3], a[4]});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            for (int i{}; i < 4; ++i)
            {
                pair<l, l> next_s = {v[1] + dx[i], v[2] + dy[i]};
                if (next_s.first >= m || next_s.second >= n || grid[next_s.first][next_s.second] == '#')
                    continue;
                pair<l, l> next_b = {v[3], v[4]};
                l d{v[0]};
                if (next_s == next_b)
                {
                    next_b.first += dx[i];
                    next_b.second += dy[i];
                    if (next_b.first >= m || next_b.second >= n || grid[next_b.first][next_b.second] == '#')
                    {
                        continue;
                    }
                    d++;
                }
                if (grid[next_b.first][next_b.second] == 'T')
                    return static_cast<int>(d);
                if (dist.find({next_s.first, next_s.second, next_b.first, next_b.second}) != dist.end())
                {
                    continue;
                }
                dist.insert({next_s.first, next_s.second, next_b.first, next_b.second});
                pq.push({d, next_s.first, next_s.second, next_b.first, next_b.second});
            }
        }
        return -1;
    }
};

int main()
{
}