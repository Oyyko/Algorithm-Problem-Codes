#include "../base.hpp"
#include <numeric>
#include <vector>

class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    using ll = long long;
    ll ans{};
    sort(happiness.begin(), happiness.end(),
         [](auto a, auto b) { return a > b; });
    // pr(happiness);
    ans = accumulate(happiness.begin(), happiness.begin() + k, 0ll);
    for (int i = 0; i < k; ++i) {
      ans -= min(i, happiness[i]);
    }
    return ans;
  }
};

int main() {
  vector<int> v{1, 1, 1, 1};
  Solution s;
  cout << "\nAAA\n" << s.maximumHappinessSum(v, 2);
}