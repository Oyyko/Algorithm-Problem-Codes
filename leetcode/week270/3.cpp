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
    string str;
    string ssss, dddd;
    bool sss = false, ddd = false;

public:
    void dfs(TreeNode *root, int s, int d)
    {
        if (root == nullptr)
            return;
        if (sss && ddd)
            return;
        if (root->val == s)
        {
            sss = 1;
            ssss = str;
        }
        if (root->val == d)
        {
            ddd = 1;
            dddd = str;
        }
        string ostr = str;
        str.push_back('L');
        dfs(root->left, s, d);
        str = ostr;
        str.push_back('R');
        dfs(root->right, s, d);
        str = ostr;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        dfs(root, startValue, destValue);
        int i{};
        for (int _ = min(ssss.size(), dddd.size()); i < _; ++i)
        {
            if (ssss[i] == dddd[i])
            {
            }
            else
                break;
        }
        string ans1(ssss.size() - i, 'U');
        for (int j = i; j < dddd.size(); ++j)
        {
            ans1.push_back(dddd[j]);
        }
        return ans1;
    }
};

int main()
{
}