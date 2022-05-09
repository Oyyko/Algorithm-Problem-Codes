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
    vector<int> r1, r2;
    void dfs1(TreeNode *n)
    {
        if (n == nullptr)
            return;
        dfs1(n->left);
        r1.push_back(n->val);
        dfs1(n->right);
    }
    void dfs2(TreeNode *n)
    {
        if (n == nullptr)
            return;
        dfs2(n->left);
        r2.push_back(n->val);
        dfs2(n->right);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        dfs1(root1), dfs2(root2);
        vector<int> ans;
        int i = 0, j = 0;
        while (i < r1.size() && j < r2.size())
        {
            if (r1[i] < r2[j])
            {
                ans.push_back(r1[i]);
                i++;
            }
            else
            {
                ans.push_back(r2[j++]);
            }
        }
        while (i < r1.size())
        {
            ans.push_back(r1[i++]);
        }
        while (j < r2.size())
        {
            ans.push_back(r2[j++]);
        }
        return ans;
    }
};

int main()
{
}