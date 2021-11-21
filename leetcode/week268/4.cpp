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

class Solution
{
private:
    using LL = long long;

    LL dp[35][2][35][35];
    LL x[110], temp[110];

public:
    LL dfs(int pos, int sta, bool limit, int k, int len)
    {
        if (pos < 0)
        {
            if (sta)
                return k;
            else
                return 1;
        }
        if (!limit && dp[pos][sta][len][k] != 1)
        {
            return dp[pos][sta][len][k];
        }
        LL sum{};
        LL up;
        up = limit ? x[pos] : k - 1;
        for (int i{}; i < up; ++i)
        {
            temp[pos] = i;
            if (i == 0 && len == pos)
                sum += dfs(pos - 1, sta, limit && (i == up), k, len - 1);
            else if (sta && pos < (len + 1) / 2)
            {
                sum += dfs(pos - 1, sta && i == temp[len - pos], limit && (i == up), k, len);
            }
            else
                sum += dfs(pos - 1, sta, limit && (i == up), k, len);
        }
        if (!limit)
            dp[pos][sta][len][k] = sum;
        return sum;
    }
    int f(int a, int k)
    {
        int pos{};
        while (a)
        {
            x[pos++] = a % k;
            a /= k;
        }
        return dfs(pos - 1, 1, true, k, pos - 1);
    }
    long long kMirror(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        cout << f(171, 7);
    }
};

int main()
{
    Solution s;
    s.kMirror(2, 2);
}