#include "../base.hpp"

class Solution {
public:
  int findMinimumOperations(string s1, string s2, string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    int x;
    if (s1[0] != s2[0] || s2[0] != s3[0]) {
      return -1;
    }
    for (int i = 1; i < l1; ++i) {
      if (s1[i] == s2[i] && s2[i] == s3[i]) {

      } else {
        x = i;
        break;
      }
    }
    int ans{};
    ans += l2 - x;
    ans += l3 - x;
    ans += l1 - x;
    return ans;
  }
};

int main() {}