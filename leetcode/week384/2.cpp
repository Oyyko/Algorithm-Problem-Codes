#include "../base.hpp"
#include <vector>

vector<int> comp_shifts(vector<int> P) {
  int p = P.size();
  vector<int> shifts(p);
  for (int q = 1; q < p; q++) {
    int k = shifts[q - 1];
    while (k > 0 && P[k] != P[q])
      k = shifts[k - 1];
    if (P[k] == P[q])
      k++;
    shifts[q] = k;
  }
  return shifts;
}

int kmp(vector<int> P, vector<int> T) {
  vector<int> shifts = comp_shifts(P);
  int n = T.size();
  int m = P.size();

  int occurrences = 0;
  int q = 0;
  for (int i = 0; i < n; i++) {
    while (q && P[q] != T[i])
      q = shifts[q - 1];
    if (P[q] == T[i])
      q++;
    if (q == m) {
      occurrences++;
      q = shifts[q - 1];
    }
  }
  return occurrences;
}

class Solution {
public:
  int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern) {
    int ans{};
    int n = nums.size();
    int m = pattern.size();
    // cout<<"ANS\n";

    vector<int> t(n - 1, 0);
    for (int i = 0; i + 1 < n; ++i) {
      if (nums[i + 1] > nums[i]) {
        t[i] = 1;
      } else if (nums[i + 1] == nums[i]) {
        t[i] = 0;
      } else {
        t[i] = -1;
      }
    }
    return kmp(pattern, t);
  }
};

int main() {
  vector<int> a{1, 2, 3, 4, 1, 2};
  vector<int> b{1, 2};
  cout << kmp(b, a);
}