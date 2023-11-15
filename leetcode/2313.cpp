#include "base.hpp"
#include <algorithm>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  unordered_map<TreeNode *, pair<int, int>> dp;
  void dfs(TreeNode *x) {
    if (x->val == 0) {
      dp[x] = {0, 1};
      return;
    } else if (x->val == 1) {
      dp[x] = {1, 0};
      return;
    } else {
      if (x->left) {
        dfs(x->left);
      }
      if (x->right) {
        dfs(x->right);
      }
    }
    if (x->val == 2) {
      int first = min({dp[x->left].first + dp[x->right].first});
      int second = min({dp[x->left].first + dp[x->right].second,
                        dp[x->left].second + dp[x->right].first,
                        dp[x->left].second + dp[x->right].second});
      dp[x].first = first;
      dp[x].second = second;
    } else if (x->val == 3) {
      int second = min({dp[x->left].second + dp[x->right].second});
      int first = min({dp[x->left].first + dp[x->right].second,
                       dp[x->left].second + dp[x->right].first,
                       dp[x->left].first + dp[x->right].first});
      dp[x].first = first;
      dp[x].second = second;
    } else if (x->val == 4) {
      int second = min({dp[x->left].second + dp[x->right].first,
                        dp[x->left].first + dp[x->right].second});
      int first = min({dp[x->left].second + dp[x->right].second,
                       dp[x->left].first + dp[x->right].first});
      dp[x].first = first;
      dp[x].second = second;
    } else if (x->val == 5) {
      auto p = x->left;
      if (x->right)
        p = x->right;
      dp[x].first = dp[p].second;
      dp[x].second = dp[p].first;
    }
  }
  int minimumFlips(TreeNode *root, bool result) {
    dfs(root);
    return result ? dp[root].second : dp[root].first;
  }
};

int main() {}