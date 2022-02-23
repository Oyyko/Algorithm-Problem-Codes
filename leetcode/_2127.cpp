#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();
        vector<int> in(n);
        for (int i = 0; i < n; ++i)
            ++in[favorite[i]];
        vector<int> used(n), f(n, 1);
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!in[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            used[u] = true;
            q.pop();
            int v = favorite[u];
            f[v] = max(f[v], f[u] + 1);
            --in[v];
            if (!in[v])
                q.push(v);
        }
        int r = 0, total = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                int j = favorite[i];
                if (favorite[j] == i)
                {
                    total += f[i] + f[j];
                    used[i] = used[j] = true;
                }
                else
                {
                    int u = i, cnt = 0;
                    while (true)
                    {
                        ++cnt;
                        u = favorite[u];
                        used[u] = true;
                        if (u == i)
                        {
                            break;
                        }
                    }
                    r = max(r, cnt);
                }
            }
        }
        return max(r, total);
    }
};

int main()
{
}