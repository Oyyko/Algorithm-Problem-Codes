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
public:
    // dp[i][j]表示到第i个会议结束，已经参加了k个会议中，最大的价值
    // dp[i][j]=
    // 不参加第i个会议 则为 dp[i-1][j]
    // 参加第i个会议 则为 dp[last][j-1]+v[i], last e[last]为小于s[i]的第一个会议
    int maxValue(vector<vector<int>> &events, int k)
    {
        auto n{events.size()};
        int dp[n + 1][k + 1];
        for (int i = 0; i < n + 1; ++i)
        {
            for (int j{}; j < k + 1; ++j)
            {
                dp[i][j] = 0;
            }
        }
        int ans{};
        sort(events.begin(), events.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        for (int i = 1; i <= n; ++i)
        {
            int cur = events[i - 1][0];
            int idx{};
            for (int j{i - 1}; j >= 1; --j)
            {
                if (events[j - 1][1] < cur)
                {
                    idx = j;
                    break;
                }
            }
            for (int j{1}; j <= k; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[idx][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};

int main()
{
}