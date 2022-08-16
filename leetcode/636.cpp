#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
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
private:
  enum class Type { Start, End, UnDecided };
  class Event {
  public:
    int id, time;
    Type t;
    Event() : id{}, time{}, t{Type::UnDecided} {}
  };
  Event trans(const string_view &x) {
    Event ans;
    char state = 0;
    for (const auto &c : x) {
      if (c == ':') {
        state++;
        continue;
      }
      if (state == 0) {
        ans.id *= 10;
        ans.id += (c - '0');
        continue;
      }
      if (state == 1 && ans.t == Type::UnDecided) {
        if (c == 's')
          ans.t = Type::Start;
        if (c == 'n')
          ans.t = Type::End;
      }
      if (state == 2) {
        ans.time *= 10;
        ans.time += (c - '0');
      }
    }
    return ans;
  }

public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    stack<int> s;
    vector<int> ans(n, 0);
    for (const auto &log : logs) {
      Event evt = trans(log);
    }
  }
};

int main() {}