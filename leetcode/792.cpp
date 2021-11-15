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

char *cur[26][50001];
int len[26];
#define numm(x) ((x) - 'a')
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        memset(len, 0, sizeof(len));
        auto n{words.size()};
        for (int i{}; i < n; ++i)
            cur[numm(words[i][0])][len[numm(words[i][0])]++] = &words[i][0];
        int ans{};
        for (char c : s)
        {
            c -= 'a';
            int k{len[c]};
            len[c] = 0;
            for (int i{}; i < k; ++i)
            {
                char *next{cur[c][i] + 1};
                if (!*next)
                    ans++;
                else
                    cur[numm(*next)][len[numm(*next)]++] = next;
            }
        }
        return ans;
    }
};
int main()
{
    Solution ss;
    string s{"abcde"};
    vector<string> words{"a", "bb", "acd", "ace"};
    cout << ss.numMatchingSubseq(s, words);
}