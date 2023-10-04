#include "base.hpp"
#include <vector>

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> ans;
    bool placed = false;
    for (auto &v : intervals) {
      if (!placed && v[0] > newInterval[1]) {
        ans.push_back(newInterval);
        ans.push_back(v);
        placed = 1;
        continue;
      }
      if (v[1] < newInterval[0] || v[0] > newInterval[1]) {
        ans.push_back(v);
        continue;
      }
      newInterval[0] = min(newInterval[0], v[0]);
      newInterval[1] = max(newInterval[1], v[1]);
    }
    if (!placed)
      ans.push_back(newInterval);
    return ans;
  }
};

int main() {}