#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    int MOD = 1e9 + 7;
    int countTexts(string pressedKeys)
    {
        int n = pressedKeys.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = dp[i - 1];
            if (pressedKeys[i] == pressedKeys[i - 1])
            {
                if (i >= 2)
                    dp[i] += dp[i - 2], dp[i] %= MOD;
                if (i == 1)
                    dp[i] += 1;
            }
            if (i >= 2)
            {
                if (pressedKeys[i] == pressedKeys[i - 1] && pressedKeys[i - 1] == pressedKeys[i - 2])
                {
                    if (i == 2)
                        dp[i] += 1;
                    else
                        dp[i] += dp[i - 3], dp[i] %= MOD;
                }
            }
            if (pressedKeys[i] == '9' || pressedKeys[i] == '7')
            {
                if (i >= 3)
                {
                    if (pressedKeys[i] == pressedKeys[i - 1] && pressedKeys[i - 1] == pressedKeys[i - 2] && pressedKeys[i - 2] == pressedKeys[i - 3])
                    {
                        if (i == 3)
                        {
                            dp[i] += 1;
                        }
                        else
                            dp[i] += dp[i - 4], dp[i] %= MOD;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution s;
    cout << s.countTexts("55555555999977779555");
}