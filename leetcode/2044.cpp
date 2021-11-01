#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << " ";
    }
    cout << endl;
}

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    
    {int t{},c{};for(int x:nums)t|=x;vector<int> dp(t+1,0);dp[0]=1;for(int x:nums){for(int i{c};~i;--i){if((i|x)>t)continue;dp[i|x]+=dp[i];}c|=x;}return dp[t];}
};

int main()
{
    Solution s;
    vector<int> n{3, 1};
    cout << s.countMaxOrSubsets(n);
}