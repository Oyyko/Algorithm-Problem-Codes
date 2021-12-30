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
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> out(n+1);
        vector<int> in(n+1);
        for (auto &x : trust)
        {
            out[x[0]]++;
            in[x[1]]++;
        }
        int ans = -2;
        for (int i = 1; i <= n; ++i)
        {
            if (out[i] == 0 && in[i] == n - 1)
            {
                if (ans == -2)
                {
                    ans = i;
                }
                else
                {
                    ans = -1;
                    break;
                }
            }
        }
        return ans == -2 ? -1 : ans;
    }
};

int main()
{
}