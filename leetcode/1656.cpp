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

class OrderedStream {
public:
  unordered_map<int, string> mp;
  int ptr;
  int maxn;
  OrderedStream(int n) : ptr(1), maxn(n) {}

  vector<string> insert(int idKey, string value) {
    vector<string> ans;
    mp[idKey] = value;
    int i{idKey};
    if (idKey == ptr) {
      for (; i <= maxn; ++i) {
        if (mp.find(i) != mp.end()) {
          ans.push_back(mp[i]);
        } else {
          break;
        }
      }
      ptr = i;
    }
    return ans;
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {}