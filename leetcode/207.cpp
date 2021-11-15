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
    void dfs(int u, vector<vector<int>> &edges, vector<int> &visited, bool &ans)
    {
        visited[u] = 1;
        for (int v : edges[u])
            if (!visited[v])
            {
                dfs(v, edges, visited, ans);
                if (!ans)
                    return;
            }
            else if (visited[v] == 1)
            {
                ans = false;
                return;
            }
        visited[u] = 2;
    };
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses);
        bool ans{true};
        for (auto &dui : prerequisites)
            edges[dui[1]].push_back(dui[0]);
        for (int i = 0; i < numCourses && ans; ++i)
            if (!visited[i])
                dfs(i, edges, visited, ans);
        return ans;
    }
};

int main()
{
}