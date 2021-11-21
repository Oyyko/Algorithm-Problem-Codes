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

public:
    LL maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        LL ans{};
        vector<LL> dp(n + 1, 0);
        vector<pair<int, int>> end[n + 1];
        for (auto &r : rides)
            end[r[1]].push_back(make_pair(r[0], r[1] - r[0] + r[2]));
        for (int i = 1, j{}; i <= n; ++i)
        {
            dp[i] = dp[i - 1];
            for (auto [s, w] : end[i])
                dp[i] = max(dp[i], dp[s] + w);
        }
        return dp[n];
    }
};

int main()
{
}