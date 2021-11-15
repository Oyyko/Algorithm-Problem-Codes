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

//Definition for a binary tree node.
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
private:
    int ans = INT_MIN;

public:
    int max_contribution(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = max(max_contribution(root->left), 0);
        int r = max(max_contribution(root->right), 0);
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        return max_contribution(root), ans;
    }
};

int main()
{
}