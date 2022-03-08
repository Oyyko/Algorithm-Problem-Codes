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
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> l(n + 1, 0);
        vector<int> r(n + 1, n);
        vector<int> sum(n + 1, 0);
        for (int i{}; i < n; ++i)
        {
            l[i + 1] = s[i] == '|' ? i : l[i];
            r[n - i - 1] = s[n - i - 1] == '|' ? n - i - 1 : r[n - i];
            sum[i + 1] = sum[i] + (s[i] == '*');
        }
        vector<int> ans;
        cout << l[6] << endl;
        cout << l[5 + 1] + 1 << endl;
        cout << r[0] << endl;
        for (auto x : queries)
            ans.push_back(max(0, sum[l[x[1] + 1] + 1] - sum[r[x[0]]]));
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{0, 5}};
    pr(s.platesBetweenCandles("*|**|*|*"s, v));
}