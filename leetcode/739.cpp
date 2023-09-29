#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> ms;
    int n = temperatures.size();
    vector<int> ans(n, 0);
    ms.push(0);
    for (int i{1}; i < n; ++i) {
      while (!ms.empty() && temperatures[i] > temperatures[ms.top()]) {
        ans[ms.top()] = i - ms.top();
        ms.pop();
      }
      ms.push(i);
    }
    return ans;
  }
};

int main() {}