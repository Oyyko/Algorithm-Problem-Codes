#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
public:
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    using ll = long long;
    ll sum1 = accumulate(nums1.begin(), nums1.end(), 0ll);
    ll sum2 = accumulate(nums2.begin(), nums2.end(), 0ll);
    int cnt1{}, cnt2{};
    for (auto &x : nums1) {
      cnt1 += x == 0;
    }
    for (auto &x : nums2) {
      cnt2 += x == 0;
    }
    ll new1 = sum1 + cnt1;
    ll new2 = sum2 + cnt2;
    if (cnt1 == 0 && new1 < new2)
      return -1;
    if (cnt2 == 0 && new2 < new1)
      return -1;
    return max(new1, new2);
  }
};