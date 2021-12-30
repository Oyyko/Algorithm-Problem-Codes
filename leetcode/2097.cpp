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
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> in, out;
        for (const auto &p : pairs)
        {
            int x = p[0], y = p[1];
            edges[x].push_back(y);
            ++in[y];
            ++out[x];
        }
        int start = pairs[0][0];
        for (const auto &[x, occ] : out)
        {
            if (occ == in[x] + 1)
            {
                start = x;
                break;
            }
        }

        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int u) -> void
        {
            while (!edges[u].empty())
            {
                int v = edges[u].back();
                edges[u].pop_back();
                dfs(v);
                ans.emplace_back(vector<int>{u, v});
            }
        };
        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
}