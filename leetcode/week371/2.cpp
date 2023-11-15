#include "../base.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool ok(const string &a, const string &b, const string &c) {
    string tmp;
    if (a.substr(0, 2) != "23") {
      int h = stoi(a.substr(0, 2));
      h++;
      tmp = to_string(h);
      if (tmp.size() == 1) {
        tmp = "0"s + tmp;
      }
      tmp += a.substr(2, 2);
    } else {
      tmp = "2400";
    }
    return b < tmp & c < tmp;
  }
  vector<string> findHighAccessEmployees(vector<vector<string>> &access_times) {
    unordered_map<string, vector<string>> mp;
    unordered_set<string> ans;
    for (auto &v : access_times) {
      mp[v[0]].push_back(v[1]);
    }
    for (auto &[k, v] : mp) {
      sort(v.begin(), v.end());
      for (int i = 0; i + 2 < v.size(); ++i) {
        if (ok(v[i], v[i + 1], v[i + 2])) {
          ans.insert(k);
          break;
        }
      }
    }
    vector<string> ans2;
    for (auto &x : ans) {
      ans2.push_back(x);
    }
    return ans2;
  }
};

int main() { Solution s; }