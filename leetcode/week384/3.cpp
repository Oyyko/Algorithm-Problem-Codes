#include "../base.hpp"
#include <string>
#include <vector>

class Solution {
public:
  int maxPalindromesAfterOperations(vector<string> &words) {
    map<char, int> mp;
    int ans{};
    vector<int> t;
    for (auto &w : words) {
      t.push_back(w.size());
      for (auto &c : w) {
        mp[c]++;
      }
    }
    sort(t.begin(), t.end(), [](int a, int b) -> bool {
      if (a % 2 == 1 && b % 2 == 0) {
        return 1;
      } else if (a % 2 == 0 && b % 2 == 1) {
        return 0;
      } else {
        return a < b;
      }
    });
    // pr(t);
    for (auto &x : t) {
      map<char, int> mp2 = mp;
      if (x % 2 == 0) {
        for (char c = 'a'; c <= 'z'; ++c) {
          if (mp[c] % 2 == 0) {
            if (x >= mp[c]) {
              x -= mp[c];
              mp[c] = 0;
            } else {
              mp[c] -= x;
              x = 0;
            }
          } else {
            if (x >= mp[c] - 1) {
              x -= (mp[c] - 1);
              mp[c] = 1;
            } else {
              mp[c] -= x;
              x = 0;
            }
          }
        }
        if (x == 0) {
          ans++;
        } else {
          mp = mp2;
        }
      } else {
        for (char c = 'a'; c <= 'z'; ++c) {
          if (mp[c] % 2 == 1) {
            mp[c]--;
            x--;
            break;
          }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
          if (mp[c] % 2 == 0) {
            if (x >= mp[c]) {
              x -= mp[c];
              mp[c] = 0;
            } else {
              mp[c] -= x;
              x = 0;
            }
          } else {
            if (x >= mp[c] - 1) {
              x -= (mp[c] - 1);
              mp[c] = 1;
            } else {
              mp[c] -= x;
              x = 0;
            }
          }
        }
        if (x == 0) {
          ans++;
        } else {
          mp = mp2;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<string> w{"aagha", "bc"};
  vector<string> w2{"a", "ccc"};
  vector<string> w3{"moyu", "jpj",   "jle", "ofx",  "hjg",
                    "bpw",  "lcvvk", "ki",  "zndnq"};
  cout << s.maxPalindromesAfterOperations(w) << endl;
  cout << s.maxPalindromesAfterOperations(w2) << endl;
  cout << s.maxPalindromesAfterOperations(w3) << endl;
}