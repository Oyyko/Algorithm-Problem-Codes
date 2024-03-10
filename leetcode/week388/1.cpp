#include "../base.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    int sum = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.begin(), capacity.end(), [](int a, int b) { return a > b; });
    int i = 0;
    int m = capacity.size();
    while (sum > 0) {
      sum -= capacity[i];
      i++;
    }
    return i;
  }
};

int main() {}