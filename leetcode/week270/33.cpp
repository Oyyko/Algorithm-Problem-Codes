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
private:
    vector<bool> now;
    vector<bool> ss, dd;
    bool fs = 0, fd = 0;

public:
    void dfs(TreeNode *root, int startValue, int destValue)
    {
        if (fs & fd)
            return;
        if (root == nullptr)
            return;
        if (root->val == startValue)
            ss = now, fs = 1;
        if (root->val == destValue)
            dd = now, fd = 1;
        now.push_back(true);
        dfs(root->left, startValue, destValue);
        now.pop_back();
        now.push_back(false);
        dfs(root->right, startValue, destValue);
        now.pop_back();
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        now.reserve(100005);
        dfs(root, startValue, destValue);
        int i{};
        for (int _ = min(ss.size(), dd.size()); i < _; ++i)
        {
            if (ss[i] != dd[i])
                break;
        }
        string ans;
        for (int j = i; j < ss.size(); ++j)
        {
            ans.push_back('U');
        }
        for (int j = i; j < dd.size(); ++j)
        {
            ans.push_back(dd[j] ? 'L' : 'R');
        }
        return ans;
    }
};

int main()
{
}