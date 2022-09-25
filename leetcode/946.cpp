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
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    int n = pushed.size();
    int i{}, j{};
    for (; i < n; ++i) {
      s.push(pushed[i]);
      for (; j < n && !s.empty() && popped[j] == s.top(); j++) {
        s.pop();
      }
    }
    return s.empty();
  }
};

int main() {}