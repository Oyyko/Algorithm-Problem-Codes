#include "../base.hpp"
#include <iostream>


constexpr int MOD = 1e9 + 7;
using ll = long long;
ll f(ll a, ll b, ll x) {
  ll aa = a ^ x;
  ll bb = b ^ x;
  aa %= MOD;
  bb %= MOD;
  return (aa * bb) % MOD;
}
class Solution {
public:
  int maximumXorProduct(long long a, long long b, int n) {
    ll ans1{};
    for (int i{}; i < n; ++i) {
      bool aa = (a & (1ll << i)) != 0;
      bool bb = (b & (1ll << i)) != 0;
      if (aa && bb) {

      } else if (!aa && !bb) {
        ans1 += (1ll << i);
      } else {
        ll tmp1 = a ^ (1ll << i);
        ll tmp2 = b ^ (1ll << i);
        if (tmp1 > tmp2 && !bb) {
          ans1 += (1ll << i);
        }
        if (tmp1 < tmp2 && !aa) {
          ans1 += (1ll << i);
        }
      }
    }
    return f(a, b, ans1);
  }
};


int main() {
  int n = 3;
  int a = 1, b = 6;
  for (int i = 0; i < (1 << n); ++i) {
    cout << i << "  " << f(a, b, i) << endl;
  }
}