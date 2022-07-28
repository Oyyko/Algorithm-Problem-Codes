#include <iostream>
#include <random>
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    using pii = pair<int, int>;
    pii dfs(TreeNode *x)
    {
        if (x == nullptr)
            return {0, 0};
        if (x->left == x->right)
            return {x->val, 1};
        auto ll = dfs(x->left);
        auto rr = dfs(x->right);
        if (ll.second >= rr.second)
            return {ll.first, ll.second + 1};
        else
            return {rr.first, rr.second + 1};
    }
    int findBottomLeftValue(TreeNode *root)
    {
        return dfs(root).first;
    }
};

int main()
{
}