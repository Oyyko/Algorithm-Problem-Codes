#include "base.hpp"

class Solution {
public:
    int minimumBoxes(int n) {
        int ans = 0, max_n = 0;
        for (int i = 1; max_n + ans + i <= n; ++i) {
            ans += i;
            max_n += ans;
        }
        for (int j = 1; max_n < n; ++j) {
            ++ans;
            max_n += j;
        }
        return ans;
    }
};
int main() {}