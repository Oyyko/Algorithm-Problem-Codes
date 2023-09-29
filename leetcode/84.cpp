#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vi l(n, -1), r(n, n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && heights[i] < heights[s.top()]) {
        r[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
    stack<int> s2;
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && heights[i] < heights[s.top()]) {
        l[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
    int ans{};
    for (int i = 0; i < n; ++i) {
      ans = max(ans, heights[i] * (r[i] - l[i] - 1));
    }
    return ans;
  }
};

int main() {}