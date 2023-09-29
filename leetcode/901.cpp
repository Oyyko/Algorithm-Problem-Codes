#include "base.hpp"
#include <unordered_map>

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int, int>;

class StockSpanner {
public:
  stack<pii> s;
  StockSpanner() {}

  int next(int price) {
    int ans{1};
    while (!s.empty() && s.top().second <= price) {
      ans += s.top().first;
      s.pop();
    }
    s.push({ans, price});
    return ans;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {}