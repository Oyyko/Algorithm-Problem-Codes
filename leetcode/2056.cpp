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
public:
    int countCombinations(vector<string> &pieces, vector<vector<int>> &positions)
    {
        auto dirs = unordered_map<string, vector<pair<int, int>>>{
            {"queen", {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}}},
            {"rook", {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}},
            {"bishop", {{-1, -1}, {1, 1}, {1, -1}, {-1, 1}}}};
        auto yes = [](auto x, auto y)
        { return 1 <= x && x <= 8 && 1 <= y && y <= 8; };
        vector<pair<int, int>> pos;
        for (auto &&e : positions)
            pos.emplace_back(e[0], e[1]);
        using P = vector<tuple<int, int, int>>;
        int n = pieces.size();
        auto check = [&](auto &&state)
        {
            int n = state.size();
            if (n <= 1)
                return true;
            auto cur = pos;
            for (int j = 0;; ++j)
            {
                bool flag = false;
                for (int i = 0; i != n; ++i)
                {
                    auto &&[x, y] = cur[i];
                    auto [dx, dy, step] = state[i];
                    if (j < step)
                        x += dx, y += dy, flag = true;
                }
                for (int i = 0; i != n - 1; ++i)
                    for (int j = i + 1; j != n; ++j)
                        if (cur[i] == cur[j])
                            return false;
                if (!flag)
                    return true;
            }
        };
        int ret = 0;
        vector<tuple<int, int, int>> now;
        auto dfs = [&](auto &&dfs, auto idx)
        {
            if (not check(now))
                return;
            if (idx == n)
                return (void)++ret;
            auto &&dir = dirs[pieces[idx]];
            auto [x, y] = pos[idx];
            for (int i = 1; i != 8; ++i)
                for (auto [dx, dy] : dir)
                {
                    auto xx = x + dx * i, yy = y + dy * i;
                    if (yes(xx, yy))
                    {
                        now.emplace_back(dx, dy, i);
                        dfs(dfs, idx + 1);
                        now.pop_back();
                    }
                }
            now.emplace_back();
            dfs(dfs, idx + 1);
            now.pop_back();
        };
        dfs(dfs, 0);
        return ret;
    }
};

int main()
{
}