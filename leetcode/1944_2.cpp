#include "base.hpp"

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    stack<int> s;
    int n = heights.size();
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      int cnt{};
      while (!s.empty() && heights[i] >= heights[s.top()]) {
        cnt++;
        s.pop();
      }
      ans[i] = s.empty() ? cnt + 1 : cnt;
      s.push(i);
    }
    return ans;
  }
};

int main() {}