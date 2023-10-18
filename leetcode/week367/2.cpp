#include "../base.hpp"
#include <ostream>
#include <vector>

class Solution {
public:
  string small(const string &a, const string &b) {
    if(a=="x")return b;
    if(b=="x")return a;
    if (a.size() != b.size()) {
      return a.size() < b.size() ? a : b;
    }
    return a < b ? a : b;
  }
  string shortestBeautifulSubstring(string s, int k) {
    int n = s.size();
    vector<int> pre(n, 0);
    pre[0] = (s[0] == '1');
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] + (s[i] == '1');
    }
    // for(int i{};i<n;++i){
    //   cout<<pre[i];
    // }
    string tmp = "x";
    // cout<<"k"<<k<<endl;
    for (int l = k; l <= n; ++l) {
      if (pre[l-1] == k) {
        tmp = s.substr(0, l);
        // cout<<tmp<<endl;
      }
      for (int i = 0; i + l < n; ++i) {
        if (pre[i + l] - pre[i] == k) {
          // cout<< i<<" " << i+l<<" "<<s.substr(i+1,l)<<endl;
          tmp = small(tmp, s.substr(i+1,l));
        }
      }
      // cout<<tmp<< "XXX"<< (tmp!="x")<<endl;
      if(tmp!="x"){
        return tmp;
      }
    }
    return "";
  }
};

int main() {}