#include "../leetcode/base.hpp"
#include <algorithm>
#include <string>
#include <vector>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
private:
  int helper(char c) { return c - '0'; }
  string trans(const vector<int> &v) {
    return to_string(v[0]) + to_string(v[1]) + ":"s + to_string(v[2]) +
           to_string(v[3]);
  }

public:
  string nextClosestTime(string time) {
    vector<int> v{helper(time[0]), helper(time[1]), helper(time[3]),
                  helper(time[4])};
    int min = *min_element(v.begin(), v.end());
    int upper{};
    for (int i = 3; i >= 0; --i) {
      if (i == 3)
        upper = 9;
      else if (i == 2)
        upper = 5;
      else if (i == 1)
        if (v[0] == 2)
          upper = 3;
        else
          upper = 9;
      else if (i == 0)
        upper = 2;
      vector<int> candidate{};
      for (auto &num : v) {
        if (num > v[i] && num <= upper) {
          candidate.push_back(num);            
        }
      }
      if (!candidate.empty()) {
        v[i] = *min_element(candidate.begin(), candidate.end());
        for (int j = i + 1; j <= 3; ++j) {
          v[j] = min;
        }
        return trans(v);
      }
    }
    vector<int> ans{min, min, min, min};
    return trans(ans);
  }
};

int main() {}