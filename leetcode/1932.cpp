#include "base.hpp"
#include <cstddef>
#include <unordered_map>
#include <unordered_set>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

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
  unordered_set<int> roots;
  void dfs(TreeNode *x) {
    if (!x)
      return;
    if (!x->left && !x->right) {
      if (roots.find(x->val) != roots.end()) {
        roots.erase(x->val);
      }
      return;
    }
    dfs(x->left);
    dfs(x->right);
  }
  void merge(TreeNode *leaf, TreeNode *root) {
    leaf->left = root->left;
    leaf->right = root->right;
  }
  unordered_map<int, TreeNode *> mp;
  void dfs1(TreeNode *x) {
    if (!x)
      return;
    if (!x->left && !x->right) {
      if (mp.find(x->val) != mp.end()) {
        merge(x, mp[x->val]);
      }
      return;
    }
    dfs1(x->left);
    dfs1(x->right);
  }
  bool check_BST(TreeNode *x) { return check(x, nullptr); }
  bool check(TreeNode *x, TreeNode *prev) {
    if (!x)
      return true;
    bool ll = check(x->left, prev);
    if (prev != nullptr && x->val < prev->val)
      return false;
    bool rr = check(x->right, x);
    return ll & rr;
  }
  TreeNode *canMerge(vector<TreeNode *> &trees) {
    for (auto &x : trees) {
      roots.insert(x->val);
    }
    for (auto &x : trees) {
      dfs(x);
    }
    if (roots.size() >= 2)
      return nullptr;
    TreeNode *final_root = [&]() -> TreeNode * {
      for (auto &x : trees) {
        if (x->val == *roots.begin())
          return x;
      }
      return nullptr;
    }();
    for (auto &x : trees) {
      mp[x->val] = x;
    }
    dfs1(final_root);

    return check_BST(final_root) ? final_root : nullptr;
  }
};

int main() {}