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
    string longestNiceSubstring(string s)
    {
        int maxPos{};
        int maxLen{};
        int n = s.size();
        for (int i{}; i < n; ++i)
        {
            int lower{}, upper{};
            for (int j{i}; j < n; ++j)
            {
                if (islower(s[j]))
                    lower |= (1 << (s[j] - 'a'));
                else
                    upper |= (1 << (s[j] - 'A'));
                if (lower == upper && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    maxPos = i;
                }
            }
        }
        return s.substr(maxPos, maxLen);
    }
};



int main()
{
}