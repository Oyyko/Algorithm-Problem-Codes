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
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        int cnt1[130] = {0};
        for (auto x : licensePlate)
        {
            if ('a' <= x && 'z' >= x)
                cnt1[x]++;
            if ('A' <= x && 'Z' >= x)
                cnt1[x - 'A' + 'a']++;
        }
        int cnt2[130];
        string ans;
        auto i = words.rbegin();
        for (; i != words.rend(); ++i)
        {
            for (int j = 'a'; j <= 'z'; ++j)
                cnt2[j] = 0;
            for (auto x : *i)
            {
                if ('a' <= x && 'z' >= x)
                    cnt2[x]++;
                if ('A' <= x && 'Z' >= x)
                    cnt2[x - 'A' + 'a']++;
            }
            for (int j = 'a'; j <= 'z'; ++j)
            {
                if (cnt2[j] < cnt1[j])
                {
                    goto OUT;
                }
            }
            ans = *i;
            break;
        OUT:
            continue;
        }
        for (; i != words.rend(); ++i)
        {
            for (int j = 'a'; j <= 'z'; ++j)
                cnt2[j] = 0;
            for (auto x : *i)
            {
                if ('a' <= x && 'z' >= x)
                    cnt2[x]++;
                if ('A' <= x && 'Z' >= x)
                    cnt2[x - 'A' + 'a']++;
            }
            for (int j = 'a'; j <= 'z'; ++j)
            {
                if (cnt2[j] < cnt1[j])
                {
                    goto OUT2;
                }
            }
            if (ans.size() >= (*i).size())
            {
                ans = *i;
            }
        OUT2:
            continue;
        }
        return ans;
    }
};

int main()
{
}