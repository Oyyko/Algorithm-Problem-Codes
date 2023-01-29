#include <bits/stdc++.h>

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
    using ll = long long;
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        vector<vector<ll>> maxx(n, vector<ll>(k + 1, 0ll));
        vector<vector<ll>> minn(n, vector<ll>(k + 1, 0ll));
        for (int x = 0; x < n; ++x)
        {
            maxx[x][1] = weights[0] + weights[x];
            minn[x][1] = weights[0] + weights[x];
        }
        for (int j = 2; j <= k; ++j)
        {
            for (int x = j - 1; x < n; ++x)
            {
                // cout << maxx[0][1] << endl;
                // cout << maxx[1][1] << endl;
                maxx[x][j] = maxx[x - 1][j - 1] + weights[x] * 2;
                minn[x][j] = minn[x - 1][j - 1] + weights[x] * 2;
                // cout << x << j << maxx[x][j] << endl;
                for (int i = j - 2; i < x - 1; ++i)
                {
                    maxx[x][j] = max(maxx[x][j], maxx[i][j - 1] + weights[i + 1] + weights[x]);
                    minn[x][j] = min(minn[x][j], minn[i][j - 1] + weights[i + 1] + weights[x]);
                }
            }
        }
        // cout << maxx[n - 1][k] << " " << minn[n - 1][k] << endl;
        return maxx[n - 1][k] - minn[n - 1][k];
    }
};

int main()
{
    vector<int> v{1, 3, 5, 1};
    vector<int> v2{1, 3};
    vector<int> v3{1, 4, 2, 5, 2};
    Solution s;
    cout << s.putMarbles(v, 2) << endl;
    cout << s.putMarbles(v2, 2) << endl;
    cout << s.putMarbles(v3, 3) << endl;
}