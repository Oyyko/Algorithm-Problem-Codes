#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

int main() {}