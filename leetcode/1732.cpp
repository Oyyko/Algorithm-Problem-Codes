#include "base.hpp"
#include <algorithm>
#include <ratio>

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    for (int i = 1; i < gain.size(); ++i) {
      gain[i] = gain[i - 1] + gain[i];
    }
    return max(0, *max_element(gain.begin(), gain.end()));
  }
};

int main() {}