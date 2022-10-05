#include "base.hpp"
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
  tuple<int, vector<string>> parse(const string &s) {
    stringstream ss{s};
    int rep{};
    ss >> rep;
    string tmp;
    vector<string> vs;
    while (std::getline(ss, tmp, '.')) {
      vs.emplace_back(tmp);
    }
    vs.front() = vs.front().substr(1, vs.front().size());
    return {rep, vs};
  }
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> mp;
    for (auto &s : cpdomains) {
      auto &&[rep, vs] = parse(s);
      string tmp{vs.back()};
      mp[tmp] += rep;
      for (auto i = vs.rbegin(); i != vs.rend(); ++i) {
        if (i == vs.rbegin())
          continue;
        tmp = *i + "."s + tmp;
        mp[tmp] += rep;
      }
    }
    vector<string> ans{};
    for (auto &[k, v] : mp) {
      ans.push_back(to_string(v) + " "s + k);
    }
    return ans;
  }
};

int main() {}
