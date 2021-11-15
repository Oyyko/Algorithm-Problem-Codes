#include<bits/stdc++.h>

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
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> back(n + 1, 0);
        vector<int> next[n + 1];
        vector<int> s(n + 1, 0);
        for (auto &x : relations)
        {
            back[x[1]]++;
            next[x[0]].push_back(x[1]);
        }
        bool res[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            res[i] = true;
        }
        int maxx{INT_MIN};
        int cnt{};
        int ans{INT_MIN};
        int first = 1;
        queue<int> zeros;

        for (int i = 1; i <= n; ++i)
        {
            if (back[i] == 0)
            {
                zeros.push(i);
            }
        }
        while (!zeros.empty())
        {
            int t = zeros.front();
            zeros.pop();
            for (auto x : next[t])
            {
                back[x]--;
                s[x] = max(s[x], s[t] + time[t - 1]);
                if (back[x] == 0)
                {
                    zeros.push(x);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            ans = max(ans, s[i] + time[i - 1]);
        }
        return ans;
    }
};


int main()
{
    
}