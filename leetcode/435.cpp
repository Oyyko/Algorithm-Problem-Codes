#include "base.hpp"
#include <limits>

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &v1, const vector<int> &v2) {
           return v1[1] < v2[1];
         });
    int k = std::numeric_limits<int>::min();
    int ans{};
    for (auto &v : intervals) {
      int x = v[0];
      int y = v[1];
      if (x >= k) {
        k = y;
      } else {
        ans++;
      }
    }
    return ans;
  }
};

int main() {}