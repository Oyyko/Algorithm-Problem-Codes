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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *ans = nullptr;
    bool dfs(TreeNode *curr, TreeNode *p, TreeNode *q)
    {
        if (curr == nullptr)
            return 0;
        bool now = curr->val == p->val || curr->val == q->val;
        bool l = dfs(curr->left, p, q);
        bool r = dfs(curr->right, p, q);
        if (l && r)
            ans = curr;
        else if ((l || r) && (now))
            ans = curr;
        return l || r || now;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }
};

int main()
{
}