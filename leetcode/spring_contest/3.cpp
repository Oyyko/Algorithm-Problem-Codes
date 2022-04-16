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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    using pii = pair<int, int>;
    set<pii> s;
    vector<int> v;
    vector<vector<pii>> mp;
    void zhongxu(TreeNode *root)
    {
        if (root == nullptr)
            return;
        zhongxu(root->left);
        v.push_back(root->val);
        zhongxu(root->right);
    }
    int getNumber(TreeNode *root, vector<vector<int>> &ops)
    {
        zhongxu(root);
        mp.resize(v.size() + 1);
        int ans{};
        for (int t = 0; t < ops.size(); t++)
        {
            int l = ops[t][1];
            int r = ops[t][2] + 1;
            int ll = lower_bound(v.begin(), v.end(), l) - v.begin();
            int rr = lower_bound(v.begin(), v.end(), r) - v.begin();
            mp[ll].push_back(make_pair(t, ops[t][0] + 1));
            mp[rr].push_back(make_pair(t, -ops[t][0] - 1));
        }
        int n = v.size();
        for (int i = 0; i < n; ++i)
        {
            for (auto &x : mp[i])
            {
                if (x.second < 0)
                {
                    auto tmp = x;
                    tmp.second = -tmp.second;
                    s.erase(tmp);
                }
                else
                    s.insert(x);
            }
            if (s.size())
            {
                auto itr = s.end();
                itr--;
                // cout << s.size() << itr->first << itr->second << endl;
                if (itr->second == 2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.getNumber()
}