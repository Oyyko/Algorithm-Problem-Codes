#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
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
    int ans;
    int depth(TreeNode *root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        int L = depth(root->left);
        int R = depth(root->right);
        ans=max(ans,L+R);
        return max(L,R) + 1;
    }

public:
    Solution()
    {
        ans=0;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return ans;
    }
};

int main()
{
}