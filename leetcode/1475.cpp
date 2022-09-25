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
  vector<int> finalPrices(vector<int> &prices) {
    stack<int> s;
    int n = prices.size();
    if (n == 1)
      return prices;
    vector<int> v(n, 0);
    v.back() = prices.back();
    s.push(prices.back());
    for (int i = n - 2; i >= 0; --i) {
      if (s.empty()) {
        v[i] = prices[i];
        continue;
      }
      if (prices[i] >= s.top()) {
        v[i] = prices[i] - s.top();
      } else {
        while (prices[i] < s.top()) {
          s.pop();
          if (s.empty())
            break;
        }
        if (s.empty())
          v[i] = prices[i];
        else
          v[i] = prices[i] - s.top();
      }
      s.push(prices[i]);
    }
    return v;
  }
};

int main() {
  Solution s;
  vector<int> v{8, 4, 6, 2, 3};
  pr(s.finalPrices(v));
}