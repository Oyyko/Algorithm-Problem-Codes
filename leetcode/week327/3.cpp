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
    bool isItPossible(string word1, string word2)
    {
        unordered_map<char, int> cnt1, cnt2;
        for (auto &c : word1)
        {
            cnt1[c]++;
        }
        for (auto &c : word2)
        {
            cnt2[c]++;
        }
        int s1 = cnt1.size(), s2 = cnt2.size();
        // cout << s1 << " " << s2 << endl;
        if (s1 < s2)
        {
            swap(cnt1, cnt2);
            swap(s1, s2);
        }
        if (abs(s1 - s2) > 2)
        {
            return false;
        }
        if (s1 - s2 == 2)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (cnt1[c] == 1 && cnt2[c] == 0)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt2[c2] >= 2 && cnt1[c2] >= 1)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        if (s1 - s2 == 1)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (cnt1[c] == 1 && cnt2[c] >= 1)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (c != c2 && cnt1[c2] >= 1 && cnt2[c2] >= 2)
                        {
                            return true;
                        }
                    }
                }
                if (cnt1[c] >= 2 && cnt2[c] == 0)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt1[c2] >= 1 && cnt2[c2] >= 2)
                        {
                            return true;
                        }
                    }
                }
                if (cnt1[c] == 1 && cnt2[c] == 0)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt1[c2] == 0 && cnt2[c2] >= 2)
                        {
                            return true;
                        }
                        if (cnt1[c2] >= 1 && cnt2[c2] == 1)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        if (s1 == s2)
        {

            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (cnt1[c] >= 1 && cnt2[c] >= 1)
                {
                    return true;
                }
                if (cnt1[c] == 1 && cnt2[c] == 0)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt1[c2] == 0 && cnt2[c2] == 1)
                        {
                            return true;
                        }
                    }
                }
                if (cnt1[c] == 1 && cnt2[c] >= 1)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt2[c2] >= 2 && cnt1[c2] == 0)
                        {
                            return true;
                        }
                    }
                }
                if (cnt1[c] >= 2 && cnt2[c] == 0)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt1[c2] >= 1 && cnt2[c2] == 1)
                        {
                            return true;
                        }
                    }
                }
                if (cnt1[c] >= 2 && cnt2[c] == 0)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (cnt2[c2] >= 2 && cnt1[c2] == 0)
                        {
                            return true;
                        }
                    }
                }
                if (cnt1[c] == 1 && cnt2[c] >= 1)
                {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2)
                    {
                        if (c != c2 && cnt1[c2] >= 1 && cnt2[c2] == 1)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isItPossible("ruxqjgehncfwytpvlaizbk",
                           "eyktspcprsbgdzqcoyqxdgjlkavtozf");
}