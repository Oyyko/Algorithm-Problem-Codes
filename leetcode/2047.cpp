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
    int countValidWords(string sentence)
    {
        int ans{};
        sentence.push_back(' ');
        auto check = [&](const string &token) -> void
        {
            int n = token.size();
            bool has_gang = false;
            for (int i{}; i < n || (ans++, 0); ++i)
            {
                if (token[i] >= '0' && token[i] <= '9')
                    break;
                if (token[i] == '-')
                    if (has_gang == false)
                    {
                        has_gang = true;
                        if (i == 0 || i == n - 1)
                            break;
                        if (token[i - 1] < 'a' || token[i - 1] > 'z' || token[i + 1] > 'z' || token[i + 1] < 'a')
                            break;
                    }
                    else
                        break;
                if (token[i] == '!' || token[i] == '.' || token[i] == ',')
                {
                    if (i == n - 1)
                    {
                    }
                    else
                    {
                        break;
                    }
                }
            }
        };
        string token{};
        int state = 0; // 0 space 1 word
        for (const auto &x : sentence)
        {
            if (state == 0)
            {
                if (x == ' ')
                {
                    continue;
                }
                else
                {
                    token.push_back(x);
                    state = 1;
                }
            }
            else
            {
                if (x == ' ')
                {
                    check(token);
                    token.resize(0);
                    state = 0;
                }
                else
                {
                    token.push_back(x);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countValidWords("cat and  dog");
}