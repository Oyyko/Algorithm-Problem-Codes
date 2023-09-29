#include "base.hpp"

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
  int compress(vector<char> &chars) {
    int n = chars.size();
    int slow{}, fast{};
    char now_char = chars[0];
    int now_char_len{};
    while (fast < n) {
      if (chars[fast] == now_char) {
        now_char_len++;
      } else {
        if (now_char_len > 1) {
          chars[slow++] = now_char;
          for (auto &c : to_string(now_char_len)) {
            chars[slow++] = c;
          }
        } else {
          chars[slow++] = now_char;
        }
        now_char = chars[fast];
        now_char_len = 1;
      }
      fast++;
    }
    if (now_char_len > 1) {
      chars[slow++] = now_char;
      for (auto &c : to_string(now_char_len)) {
        chars[slow++] = c;
      }
    } else {
      chars[slow++] = now_char;
    }
    return slow;
  }
};

int main() {}