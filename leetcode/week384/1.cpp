#include "../base.hpp"

class Solution {
public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {
    vector<vector<int>> ans = matrix;
    int m = ans.size();
    int n = ans.front().size();
    map<int, int> mp;
    for (int j = 0; j < n; ++j) {
      int tmp = -10;
      for (int i = 0; i < m; ++i) {
        tmp = max(tmp, ans[i][j]);
      }
      mp[j] = tmp;
    }
    for(int i{};i<m;++i){
      for(int j{};j<n;++j){
        if(ans[i][j]==-1){
          ans[i][j]=mp[j];
        }
      }
    }
    return ans;
  }
};

int main() {}