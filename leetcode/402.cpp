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
    string removeKdigits(string num, int k)
    {
        string ans{};
        int len = num.size() - k;
        if (!len)
            return "0"s;
        for (auto c : num)
        {
            while (k && ans.size() && ans.back() > c)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        ans = ans.substr(0, len);
        size_t i = 0;
        for (; i < ans.size(); ++i)
        {
            if (ans[i] != '0')
            {
                break;
            }
        }
        if (i == ans.size())
            return "0"s;
        string sss{};
        for (; i < ans.size(); ++i)
        {
            sss.push_back(ans[i]);
        }
        return sss;
    }
};

int main()
{
    Solution s;
    cout << s.removeKdigits("10200", 1);
}