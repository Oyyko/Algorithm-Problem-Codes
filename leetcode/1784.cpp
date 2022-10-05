#include "base.hpp"

class Solution {
public:
  bool checkOnesSegment(string s) {
    int stage{1};
    for (auto &c : s) {
      if (stage == 1 && c == '0') {
        stage = 0;
      } else if (stage == 0 && c == '1') {
        return false;
      }
    }
    return true;
  }
};

int main() {}