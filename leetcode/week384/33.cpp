#include "../base.hpp"

// 亲爱的写的

class Solution {
public:
  int maxPalindromesAfterOperations(vector<string> &words) {
    unordered_map<char, int> sxxs;
    for (auto &w : words)
      for (auto &c : w)
        sxxs[c]++;
    vector<int> size;
    int en{}, on{}, evaaa{}, odaaa{};
    for (auto &i : sxxs) {
      odaaa += i.second % 2;
      evaaa += i.second / 2;
    }
    for (auto &i : words) {
      on += i.size() % 2;
      en += i.size() / 2;
      size.push_back(i.size());
    }
    int ans{};
    sort(size.begin(), size.end());
    for (auto &s : size) {
      if (s % 2 == 0) {
        if (evaaa >= s / 2) {
          ans++;
          evaaa -= s / 2;
        } else {
          break;
        }
      } else {
        if (odaaa >= 1) {
          if (evaaa >= s / 2) {
            ans++;
            evaaa -= s / 2;
            odaaa--;
          } else {
            break;
          }
        } else {
          if (evaaa > 0) {
            odaaa += 2;
            evaaa -= 1;
            if (evaaa >= s / 2) {
              evaaa -= s / 2;
              ans++;
              odaaa--;
            } else {
              break;
            }
          } else
            break;
        }
      }
    }
    return ans;
  }
};

int main() {}