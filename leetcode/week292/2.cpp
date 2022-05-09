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
    int ans = 0;
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return make_pair(0, 0);
        if (root->left == nullptr && root->right == nullptr)
        {
            ans++;
            return make_pair(root->val, 1);
        }
        auto ll = dfs(root->left);
        auto rr = dfs(root->right);
        if (root->val == (ll.first + rr.first + root->val) / (ll.second + rr.second + 1))
        {
            // cout << root->val;
            ans++;
        }
        return make_pair(ll.first + rr.first + root->val, ll.second + rr.second + 1);
    }
    int averageOfSubtree(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};

int main()
{
}