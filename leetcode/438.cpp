#include <bits/stdc++.h>

using namespace std;

using LL = long long;

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
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return vector<int>{};
        vector<int> p_count(26);
        vector<int> s_count(26);
        for (const auto &x : p)
            p_count[x - 'a']++;
        for (int i = 0; i < p.size(); ++i)
        {
            char &x = s[i];
            s_count[x - 'a']++;
        }
        vector<int> ans;
        if (p_count == s_count)
            ans.push_back(0);
        for (int j = p.size(), _ = p.size(); j < s.size(); ++j)
        {
            char &x = s[j];
            s_count[s[j - _] - 'a']--;
            s_count[x - 'a']++;
            if (p_count == s_count)
                ans.push_back(j - _ + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    pr(s.findAnagrams("cbaebabacd", "abc"));
}