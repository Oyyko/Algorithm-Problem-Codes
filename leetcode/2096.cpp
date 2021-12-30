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
    vector<bool> ss;
    vector<bool> dd;
    vector<bool> path;
    bool fs{false}, fd{false};
    int s, d;
    void dfs(TreeNode *t)
    {
        if (!t || (fs && fd))
            return;
        if (t->val == s)
            ss = path, fs = true;
        if (t->val == d)
            dd = path, fd = true;
        path.push_back(1);
        dfs(t->left);
        path.pop_back();
        path.push_back(0);
        dfs(t->right);
        path.pop_back();
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        s = startValue, d = destValue;
        dfs(root);
        int i;
        int _ = min(ss.size(), dd.size());
        for (i = 0; i < _; ++i)
        {
            if (ss[i] != dd[i])
                break;
        }
        string ans;
        for (int j = i, k = ss.size(); j < k; ++j)
        {
            ans.push_back('U');
        }
        for (int j = i, k = dd.size(); j < k; ++j)
        {
            ans.push_back(dd[j] == false ? 'R' : 'L');
        }
        return ans;
    }
};

int main()
{
}