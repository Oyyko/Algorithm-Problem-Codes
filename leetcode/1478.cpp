#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    int minDistance(vector<int> &houses, int k)
    {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                v[i][j] = v[i + 1][j - 1] + houses[j] - houses[i];
            }
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, INT32_MAX));
        for (int i = 0; i < n; ++i)
        {
            f[i][1] = v[0][i];
            for (int j = 2; j <= min(k, i + 1); ++j)
            {
                for (int kk = 0; kk < i; ++kk)
                {
                    f[i][j] = min(f[i][j], f[kk][j - 1] + v[kk + 1][i]);
                }
            }
        }
        return f[n - 1][k];
    }
};

int main()
{
}