#include "../base.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;
struct Node {
  ll sum{};
  int val;
  vector<Node *> sons;
};

ll find_sum(Node *x) {
  if (x == nullptr)
    return 0;
  if (x->sons.size() == 0)
    return x->sum = x->val;

  ll ans{};
  for (auto &s : x->sons) {
    ans += find_sum(s);
  }
  return x->sum = ans + x->val;
}

class Solution {
public:
  long long maximumScoreAfterOperations(vector<vector<int>> &edges,
                                        vector<int> &values) {
    int n = values.size();
    vector<Node> v(n, Node{});
    for (int i{}; i < n; ++i)
      v[i].val = values[i];
    unordered_map<int, vector<int>> mp;
    for (auto &e : edges) {
      mp[e[0]].push_back(e[1]);
      mp[e[1]].push_back(e[0]);
    }
    unordered_set<int> al;
    al.insert(0);
    while(al.size()<n){
      
    }

    find_sum(&v[0]);
    // for (int i = 0; i < n; ++i) {
    //   cout << i << endl;
    //   for (auto &s : v[i].sons) {
    //     cout << s->val << " ";
    //   }
    //   cout << "END\n";
    // }
    // for (int i = 0; i < n; ++i) {
    //   cout << i << " " << f(&v[i]) << "  SUM" << v[i].sum << endl;
    // }
    // cout << v[3].sum << "---" << v[4].sum << endl;
    return f(&v[0]);
  }
  ll f(Node *x) {
    if (x->sons.size() == 0)
      return 0;
    ll ans1{};
    for (auto &s : x->sons) {
      ans1 += s->sum;
    }
    ll ans2{};
    ans2 += x->val;
    for (auto &s : x->sons) {
      ans2 += f(s);
    }
    return max(ans1, ans2);
  }
};

int main() {
  Solution s;
  vector<vector<int>> edges{{7, 0}, {3, 1}, {6, 2}, {4, 3},
                            {4, 5}, {4, 6}, {4, 7}};
  vector<int> vals{2, 16, 23, 17, 22, 21, 8, 6};
  cout << s.maximumScoreAfterOperations(edges, vals);
}