#include "../base.hpp"
#include <algorithm>

class Solution {
public:
  int minOperations(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int b1 = nums1.back();
    int b2 = nums2.back();
    int cnt{};
    for (int i = 0; i < n; ++i) {
      if (nums1[i] > b1 && nums1[i] > b2) {
        return -1;
      }
      if (nums2[i] > b1 && nums2[i] > b2) {
        return -1;
      }
      if (nums1[i] > b1 && nums2[i] > b1) {
        return -1;
      }
      if (nums1[i] > b2 && nums2[i] > b2) {
        return -1;
      }
      if (nums1[i] > b1) {
        cnt++;
      }
      if (nums2[i] > b2) {
        cnt++;
      }
    }
    int cnt2{};
    for (int i = 0; i < n; ++i) {
      if (nums1[i] > b2) {
        cnt2++;
      }
      if (nums2[i] > b1) {
        cnt2++;
      }
    }
    return min(cnt, cnt2);
  }
};

int main() {}