#include "../base.hpp"

class Solution {
public:
  int differenceOfSums(int n, int m) {
    int num1, num2;
    for (int i = 1; i * m <= n; ++i) {
      num2 += i * m;
    }
    int all = n * (n + 1) / 2;
    num1 = all - num2;
    return num1 - num2;
  }
};

int main() {}