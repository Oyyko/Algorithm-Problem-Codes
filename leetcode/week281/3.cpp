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
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> cnt(27, 0);
        for (auto &x : s)
        {
            cnt[x - 'a']++;
        }
        string ans{};
        for (int i = 25; i >= 0; --i)
        {
        START:
            int cnt1{};
            while (cnt[i] && cnt1 < repeatLimit)
            {
                ans.push_back(i + 'a');
                cnt[i]--;
                cnt1++;
            }
            if (cnt1 == repeatLimit && cnt[i])
            {
                bool find{false};
                for (int k = i - 1; k >= 0; --k)
                {
                    if (cnt[k])
                    {
                        find = true;
                        ans.push_back(k + 'a');
                        cnt[k]--;
                        break;
                    }
                }
                if (!find)
                    return ans;
                goto START;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.repeatLimitedString("aababab", 2);
}