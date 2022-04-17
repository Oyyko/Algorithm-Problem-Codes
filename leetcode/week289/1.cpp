#include <iostream>
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
    string mp(string &s, int l, int r)
    {
        int ans{};
        for (int i = l; i <= r; ++i)
        {
            ans += s[i] - '0';
        }
        return to_string(ans);
    }
    string digitSum(string s, int k)
    {
        // int n = 0;
        while (s.size() > k)
        {
            string nn{};
            int l;
            for (l = 0; l + k < s.size(); l += k)
            {
                nn += mp(s, l, l + k - 1);
            }
            nn += mp(s, l, s.size() - 1);
            s = nn;
            // cout << s << endl, n++;
            // if (n == 10)
            //     exit(0);
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ss{"11111222223"};
    s.digitSum(ss, 3);
}