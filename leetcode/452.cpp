#include "base.hpp"
#include <limits>

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](const vi &v1, const vi &v2) { return v1[1] < v2[1]; });
    int ans{}, k = numeric_limits<int>::min();
    bool k_init{false};
    for (auto &v : points) {
      int s = v[0], e = v[1];
      if (s > k || !k_init) {
        k_init = true;
        ans++;
        k = e;
      }
    }
    return ans;
  }
};

int main() {}