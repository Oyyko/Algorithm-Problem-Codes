#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        int sl = startWords.size();
        int tl = targetWords.size();
        vector<int> s(sl, 0);
        vector<int> t(tl, 0);
        for (int i{}; i < sl; ++i)
        {
            for (auto &x : startWords[i])
            {
                s[i] |= (1 << x - 'a');
            }
        }
        for (int i{}; i < tl; ++i)
        {
            for (auto &x : targetWords[i])
            {
                t[i] |= (1 << x - 'a');
            }
        }
        int ans{};
        unordered_map<int, bool> can;
        for (auto &x : s)
        {
            bool old = can[x];
            for (int i{}; i < 26; ++i)
            {
                can[(x | (1 << i))] = 1;
            }
            can[x] = old;
        }
        for (auto &x : t)
        {
            ans += can[x];
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<string> ss{"g", "vf", "ylpuk", "nyf", "gdj", "j", "fyqzg", "sizec"};
    vector<string> tt{"r", "am", "jg", "umhjo", "fov", "lujy", "b", "uz", "y"};
    cout << s.wordCount(ss, tt);
}