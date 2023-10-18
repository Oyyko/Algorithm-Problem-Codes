#include "../base.hpp"
#include <functional>

class Solution {
public:
  int minProcessingTime(vector<int> &processorTime, vector<int> &tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(), greater<int>());
    int ans{};
    int n = processorTime.size();
    for (int i = 0; i < n; ++i) {
      ans = max(ans, processorTime[i] + tasks[i * 4]);
    }
    return ans;
  }
};

int main() {}