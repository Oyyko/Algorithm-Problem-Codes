#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  int maxVowels(string s, int k) {
    int n = s.size();
    int ans{}, tmp{};
    for (int i = 0; i < k; ++i) {
      tmp += isVowel(s[i]);
    }
    ans = tmp;
    for (int i = 1; i + k - 1 < n; ++i) {
      tmp -= isVowel(s[i - 1]);
      tmp += isVowel(s[i + k - 1]);
      ans = max(tmp, ans);
    }
    return ans;
  }
};

int main() {}