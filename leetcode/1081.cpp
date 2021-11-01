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
    string smallestSubsequence(string s)
    {
        unordered_map<char, int> cnt;
        string ans{};
        for (auto c : s)
        {
            cnt[c]++;
        }
        unordered_map<char, bool> ss;
        for (auto c : s)
        {
            cnt[c]--;
            if (ss[c])
                continue;
            while (ans.size() && ans.back() >= c && cnt[ans.back()])
            {
                ss[ans.back()] = false;
                ans.pop_back();
            }
            if (!ss[c])
            {
                ans += string(1, c);
                ss[c] = 1;
            }
        }
        return ans;
    }
};

int main()
{
}