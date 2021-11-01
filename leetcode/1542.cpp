//2021-10-11
//11:55

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    int longestAwesome(string s)
    {
        map<int, int> mp;
        mp[0] = -1;
        int now_state{};
        int ans{};
        for (int i = 0; i < s.size(); ++i)
        {
            now_state ^= (1 << (s[i] - '0'));
            if (mp.count(now_state))
            {
                ans = max(ans, i - mp[now_state]);
            }
            else
            {
                mp[now_state] = i;
            }
            for (int j = 0; j < 10; ++j)
            {
                if (mp.count(now_state ^ (1 << j)))
                    ans = max(ans, i - mp[now_state ^ (1 << j)]);
            }
        }
        return ans;
    }
};

int main()
{
}
