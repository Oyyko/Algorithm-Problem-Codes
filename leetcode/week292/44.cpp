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
#define MP(c) (c == '(' ? +1 : -1)
    bool hasValidPath(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> cnt;
        if (m == 1 && n == 1)
            return false;
        if ((m + n - 1) % 2 == 1)
            return false;
        if (grid[m - 1][n - 1] == '(')
            return false;
        if (grid[0][0] == ')')
            return false;
        vector<vector<vector<int>>> want(m, vector<vector<int>>(n));
        
    }
};

int main()
{
}