#include <iostream>
#include <random>
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
    unordered_map<int, int> cnt;
    int dfs(TreeNode *x)
    {
        if (x == nullptr)
            return 0;
        if (x->left == nullptr && x->right == nullptr)
        {
            cnt[x->val]++;
            return x->val;
        }
        int ll = dfs(x->left);
        int rr = dfs(x->right);
        int ans = ll + rr + x->val;
        cnt[ans]++;
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        dfs(root);
        int maxx = (*max_element(cnt.begin(), cnt.end(), [](auto &&x, auto &&y)
                                 { return x.second < y.second; }))
                       .second;
        vector<int> ans;
        for (auto &[k, v] : cnt)
        {
            cout << k << v << endl;
            if (v == maxx)
                ans.push_back(k);
        }
        return ans;
    }
};

int main()
{
}