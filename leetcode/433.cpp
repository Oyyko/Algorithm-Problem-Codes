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
    bool dis1(string &x, string &y)
    {
        bool yes = 0;
        for (int i = 0; i < 8; ++i)
        {
            if (yes == 0)
            {
                if (x[i] != y[i])
                    yes = 1;
            }
            else
            {
                if (x[i] != y[i])
                {
                    yes = 0;
                    break;
                }
            }
        }
        return yes;
    }
    int minMutation(string start, string end, vector<string> &bank)
    {
        int n = bank.size();
        int end_i = -1;
        for (int i = 0; i < n; ++i)
        {
            if (bank[i] == end)
            {
                end_i = i;
                break;
            }
        }
        if (end_i == -1)
            return -1;
        vector<vector<int>> nei(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (dis1(bank[i], bank[j]))
                {
                    nei[i].push_back(j);
                    nei[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (dis1(bank[i], start))
            {
                q.push(i);
            }
        }
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            int now = q.size();
            for (int k = 0; k < now; ++k)
            {
                auto tmp = q.front();
                q.pop();
                if (vis[tmp])
                    continue;
                if (tmp == end_i)
                    return ans;
                for (auto &t : nei[tmp])
                {
                    q.push(t);
                }
                vis[tmp] = 1;
            }
        }
        return -1;
    }
};

int main()
{
}