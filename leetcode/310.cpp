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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<vector<int>> nei(n);
        vector<int> degree(n, 0);
        for (auto &e : edges)
        {
            nei[e[0]].push_back(e[1]);
            nei[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int cnt = n;
        queue<int> q;
        vector<int> ans;
        for (int i{}; i < n; ++i)
            if (degree[i] == 1)
                q.push(i);
        while (cnt > 2)
        {
            int sz = q.size();
            cnt -= sz;
            for (int i{}; i < sz; ++i)
            {
                int cur = q.front();
                q.pop();
                for (auto &v : nei[cur])
                {
                    degree[v]--;
                    if (degree[v] == 1)
                        q.push(v);
                }
            }
        }
        while (!q.empty())
        {
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }
};

int main()
{
}