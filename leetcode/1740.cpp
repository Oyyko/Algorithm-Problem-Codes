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
    vector<bool> path;
    vector<bool> p1, p2;
    void dfs1(TreeNode *s, int f)
    {
        if (s == nullptr)
            return;
        if (s->val == f)
        {
            p1 = path;
            return;
        }
        path.push_back(1);
        dfs1(s->left, f);
        path.pop_back();
        path.push_back(0);
        dfs1(s->right, f);
        path.pop_back();
    }
    void dfs2(TreeNode *s, int f)
    {
        if (s == nullptr)
            return;
        if (s->val == f)
        {
            p2 = path;
            return;
        }
        path.push_back(1);
        dfs2(s->left, f);
        path.pop_back();
        path.push_back(0);
        dfs2(s->right, f);
        path.pop_back();
    }
    int findDistance(TreeNode *root, int p, int q)
    {
        if (p == q)
            return 0;
        dfs1(root, p);
        path.clear();
        dfs2(root, q);

        int ans{};
        int i;
        int _;
        for (i = 0, _ = min(p1.size(), p2.size()); i < _; i++)
        {
            if (p1[i] == p2[i])
                continue;
            else
                break;
        }
        ans += p1.size() - i;
        ans += p2.size() - i;
        return ans;
    }
};

int main()
{
    TreeNode *p[3];
    for (auto &x : p)
    {
        x = new TreeNode;
    }
    p[0]->val = 20;
    p[0]->left = p[1];
    p[0]->right = nullptr;
    p[1]->val = 15;
    p[1]->left = p[1]->right = nullptr;
    Solution s;
    s.findDistance(p[0], 15, 20);
}