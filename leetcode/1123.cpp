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
    int get_dep(TreeNode *s)
    {
        if (s == nullptr)
            return 0;
        return max(get_dep(s->left), get_dep(s->right)) + 1;
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        int l{get_dep(root->left)};
        int r{get_dep(root->right)};
        if (l == r)
            return root;
        return (l > r) ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }
};
int main()
{
}