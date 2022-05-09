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
    int m, n;
    bool yes = false;
    vector<vector<char>> g;
    void dfs(int x, int y, int ll, int rr)
    {
        if (yes == 1)
            return;
        ll += g[x][y] == '(';
        rr += g[x][y] == ')';
        if (!(ll >= rr))
            return;
        if (x == m - 1 && y == n - 1)
        {
            if (ll == rr)
                yes = 1;
            return;
        }
        if (x + 1 <= m - 1)
        {
            dfs(x + 1, y, ll, rr);
        }
        if (y + 1 <= n - 1)
            dfs(x, y + 1, ll, rr);
    }
    bool hasValidPath(vector<vector<char>> &grid)
    {
        g = grid;
        m = grid.size();
        n = grid[0].size();
        if (m == 1 && n == 1)
            return false;
        if ((m + n - 1) % 2 == 1)
            return false;
        if (grid[m - 1][n - 1] == '(')
            return false;
        if (grid[0][0] == ')')
            return false;
        
        dfs(0, 0, 0, 0);
        return yes;
    }
};

int main()
{
}