#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

template <typename T> void pr(vector<T> x) {
  for (auto a : x) {
    cout << a << " ";
  }
  cout << endl;
}

template <class T> void pr(vector<vector<T>> x) {
  for (auto &a : x) {
    for (auto &b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  cout << endl;
}

template <class T> T upper_divide(T a, T b) { return (a - 1) / b + 1; }

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int cnt{};
    int maxx = accumulate(nums.begin(), nums.end(), -1,
                          [](int a, int b) { return max(a, b); });
    int maxx2 =
        accumulate(nums.begin(), nums.end(), -1, [&maxx, &cnt](int a, int b) {
          if (b == maxx) {
            cnt++;
            return a;
          }
          return max(a, b);
        });
    return cnt >= 2 ? ((maxx - 1) * (maxx - 1)) : ((maxx - 1) * (maxx2 - 1));
  }
};

int main() {
  Solution s;
  vector<int> v{3, 2, 1};
  cout << s.maxProduct(v);
}