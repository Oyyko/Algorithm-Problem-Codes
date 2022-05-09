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

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *dfs(vector<vector<int>> &grid, int a, int b, int c, int d)
    {
        int v = grid[a][b];
        bool all_same = 1;
        for (int i = a; i <= c; ++i)
        {
            for (int j = b; j <= d; ++j)
            {
                if (grid[i][j] != v)
                {
                    all_same = 0;
                    goto OUT;
                }
            }
        }
    OUT:
        if (all_same)
        {
            Node *ans = new Node(v, 1);
            return ans;
        }
        int m1 = (a + c) / 2;
        int m2 = (b + d) / 2;
        return new Node(1, 0,
                        dfs(grid, a, b, m1, m2),
                        dfs(grid, a, m2 + 1, m1, d),
                        dfs(grid, m1 + 1, b, c, m2),
                        dfs(grid, m1 + 1, m2 + 1, c, d));
    }
    Node *construct(vector<vector<int>> &grid)
    {
        return dfs(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }
};

int main()
{
}