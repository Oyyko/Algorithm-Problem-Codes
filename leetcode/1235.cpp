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
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<int> dp(n + 1);
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < n; ++i)
            v.push_back(make_tuple(startTime[i], endTime[i], profit[i]));
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return get<1>(a) < get<1>(b); });
        for (int i = 1; i <= n; ++i)
        {
            int last{};
            for (int j{i - 1}; j >= 1; --j)
            {
                if (get<1>(v[j - 1]) <= get<0>(v[i - 1]))
                {
                    last = j;
                    break;
                }
            }
            dp[i] = max(dp[i - 1], dp[last] + get<2>(v[i - 1]));
        }
        return dp[n];
    }
};

int main()
{
}