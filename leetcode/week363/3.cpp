#include "../base.hpp"
#include <vector>

class Solution {
public:
  using ll = long long;
  bool check(int n, int k, int budget, vector<vector<int>> &composition,
             vector<int> &stock, vector<int> &cost, int x) {
    for (auto vv1 : composition) {
      ll money{};
      bool can_this = true;
      vector<ll> vv(n, 0);

      for (int i{}; i < n; ++i) {
        vv[i] = vv1[i];
        vv[i] *= x;
        vv[i] -= stock[i];
        if (vv[i] < 0)
          vv[i] = 0;
        money += vv[i] * (cost[i] + 0ll);
        if (money > budget) {
          can_this = false;
          break;
        }
      }
      if (can_this)
        return true;
    }
    return false;
  }
  int maxNumberOfAlloys(int n, int k, int budget,
                        vector<vector<int>> &composition, vector<int> &stock,
                        vector<int> &cost) {
    int l{}, r{INT_MAX};
    int mid = l + (r - l) / 2;
    while (l + 1 < r) {
      if (check(n, k, budget, composition, stock, cost, mid)) {
        l = mid;
      } else
        r = mid;
      mid = l + (r - l) / 2;
    }
    if (check(n, k, budget, composition, stock, cost, r))
      return r;
    return l;
  }
};

int main() {
}