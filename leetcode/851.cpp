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
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> ans(n);
        vector<int> in(n);
        for (int i{}; i < n; ++i)
            ans[i] = i;
        for (auto &x : richer)
        {
            graph[x[0]][x[1]] = true;
            in[x[1]]++;
        }
        queue<int> q;
        for (int i{}; i < n; ++i)
            if (in[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (int i{}; i < n; ++i)
            {
                if (graph[top][i])
                {
                    if (quiet[ans[top]] < quiet[ans[i]])
                        ans[i] = ans[top];
                    if (--in[i] == 0)
                        q.push(i);
                }
            }
        }
        return ans;
    }
};

int main()
{
}