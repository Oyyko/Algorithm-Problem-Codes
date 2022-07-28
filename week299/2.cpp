#include <iostream>
#include <random>
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
    static constexpr int MOD = 1000000007;
    int countHousePlacements(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i][0] = (((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD + dp[i - 1][3]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][3] = (dp[i - 1][0]) % MOD;
        }
        int ans{};
        for (int i = 0; i <= 3; ++i)
        {
            ans += dp[n][i];
            ans %= MOD;
        }
        return ans;
    }
};

int main()
{
}