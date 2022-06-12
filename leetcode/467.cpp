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
    bool nei(int i, int j, const string &p)
    {
        return p[j] - p[i] == 1 || (p[i] == 'z' && p[j] == 'a');
    }
    int findSubstringInWraproundString(string p)
    {
        vector<int> dp(26);
        int k{};
        int n = p.size();
        for (int i = 0; i < n; ++i)
        {
            if (i && nei(i - 1, i, p))
                ++k;
            else
                k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main()
{
}