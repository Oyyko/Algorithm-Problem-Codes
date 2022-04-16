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

int main()
{
}

class Solution
{
public:
    int dp[102][32];
    int inf = INT_MAX / 2;
    int com(int s, int lianhe)
    {
        int ans = 0;
        int kai = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (s & (1 << i))
            {
                if (kai == 2)
                {
                    if (lianhe & (1 << i))
                    {
                        ans += 1;
                    }
                    else
                    {
                        ans += 2;
                        kai = 1;
                    }
                }
                else if (kai == 1)
                {
                    if (lianhe & (1 << i))
                    {
                        ans += 3;
                        kai = 2;
                    }
                    else
                    {
                        ans += 1;
                    }
                }
                else
                {
                    if (lianhe & (1 << i))
                    {
                        ans += 3;
                        kai = 2;
                    }
                    else
                    {
                        ans += 2;
                        kai = 1;
                    }
                }
            }
            else
            {
                kai = 0;
            }
        }
        return ans;
    }
    bool is_subset(int a, int b)
    {
        return (a | b) == b;
    }
    int defendSpaceCity(vector<int> &time, vector<int> &position)
    {
        for (int i = 0; i < 102; ++i)
        {
            for (int j = 0; j <= 31; ++j)
            {
                dp[i][j] = inf;
            }
        }
        unordered_map<int, int> za;
        int n = time.size();
        for (int i = 0; i < n; ++i)
        {
            za[position[i]] |= (1 << (time[i] - 1));
        }
        for (int s = 0; s <= 31; ++s)
        {
            dp[0][s] = com(s, 0);
        }
        for (int i = 1; i < 102; ++i)
        {
            for (int s = 0; s <= 31; ++s)
            {
                for (int j = s; j; j = (j - 1) & s)
                {
                    int lianhe = j;
                    for (int k = 0; k <= 31; ++k)
                    {
                        if (k & lianhe)
                            continue;
                        if (((k | lianhe) | za[i - 1]) == (k | lianhe))
                        {
                            dp[i][s] = min(dp[i][s], dp[i - 1][k] + com(s, lianhe));
                        }
                    }
                }
                {
                    int j = 0;
                    int lianhe = j;
                    for (int k = 0; k <= 31; ++k)
                    {
                        if (k & lianhe)
                            continue;
                        if (((k | lianhe) | za[i - 1]) == (k | lianhe))
                        {
                            dp[i][s] = min(dp[i][s], dp[i - 1][k] + com(s, lianhe));
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int s = 0; s <= 31; ++s)
        {
            if (is_subset(za[100], s))
            {
                ans = min(ans, dp[100][s]);
            }
        }
        return ans;
    }
};