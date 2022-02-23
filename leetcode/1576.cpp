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
    string modifyString(string s)
    {
        int n = s.size();
        if (n == 1)
        {
            if (s[0] != '?')
                return s;
            else
                return "a";
        }
        auto next = [](char c) -> char
        {
            return (c + 1) > 'z' ? 'a' : (c + 1);
        };
        for (int i{}; i < n; ++i)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    if (s[1] != '?')
                    {
                        s[0] = next(s[1]);
                    }
                    else
                    {
                        s[0] = 'a';
                    }
                    continue;
                }
                if (i == n - 1)
                {
                    if (s[n - 2] != '?')
                    {
                        s[n - 1] = next(s[n - 2]);
                    }
                    else
                    {
                        s[n - 1] = 'a';
                    }
                    continue;
                }
                s[i] = next(s[i - 1]);
                if (s[i] == s[i + 1])
                {
                    s[i] = next(s[i]);
                }
            }
        }
        return s;
    }
};

int main()
{
}