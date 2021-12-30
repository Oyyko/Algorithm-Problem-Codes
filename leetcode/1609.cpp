#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> ceng;
        ceng.push(root);
        int cnt{};
        while (!ceng.empty())
        {
            int num = ceng.size();
            int prev = cnt % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 1; i <= num; ++i)
            {
                auto tmp = ceng.front();
                ceng.pop();
                if (tmp->val % 2 == cnt % 2)
                    return false;
                if (cnt % 2 == 1)
                {
                    if (tmp->val >= prev)
                        return false;
                }
                else if (tmp->val <= prev)
                    return false;
                if (tmp->left)
                    ceng.push(tmp->left);
                if (tmp->right)
                    ceng.push(tmp->right);
                prev = tmp->val;
            }
            cnt++;
        }
        return true;
    }
};

int main()
{
}