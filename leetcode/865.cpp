#include "base.hpp"

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
    pair<int, TreeNode *> helper(TreeNode *x)
    {
        if (x == nullptr)
            return {0, nullptr};
        auto [hL, L] = helper(x->left);
        auto [hR, R] = helper(x->right);
        return {max(hR, hL) + 1, hR == hL ? x : (hL > hR ? L : R)};
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return helper(root).second;
    }
};

int main()
{
}