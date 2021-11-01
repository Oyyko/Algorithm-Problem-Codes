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
    string smallestSubsequence(string s, int k, char letter, int repetition)
    {
        int n = s.size();
        int cnt = 0;
        for (auto x : s)
        {
            cnt += x == letter;
        }
        int rest = n - k;
        string ans;
        int now = 0;
        for (auto x : s)
        {
            while (rest && ans.size() && x < ans.back())
            {
                if (ans.back() == letter)
                {
                    if (repetition > now - 1 + cnt)
                        break;
                    else
                        now--;
                }
                ans.pop_back();
                rest--;
            }
            now += x == letter;
            cnt -= x == letter;
            ans += x;
        }

        while (ans.size() > k)
        {
            if (ans.back() == letter)
                now--;
            ans.pop_back();
        }
        for (int i = k - 1; i >= 0; --i)
        {
            if (now < repetition && ans[i] != letter)
            {
                ans[i] = letter;
                ++now;
            }
        }
        return ans;
    }
};

int main()
{
}