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
    int compute(const string &x)
    {
        int nei{};
        int wai{};
        int wai2{};
        int lp{}, rp{};
        if (*x.begin() == '(')
        {
            auto itr = x.begin() + 1;
            while (*itr != '+')
            {
                lp *= 10;
                lp += *itr - '0';
                itr++;
            }
            itr++;
            while (*itr != ')')
            {
                rp *= 10;
                rp += *itr - '0';
                itr++;
            }
            itr++;
            nei = lp + rp;
            while (itr != x.end())
            {
                wai *= 10;
                wai += *itr - '0';
                itr++;
            }
            // cout << x << "---" << lp << " " << rp << " " << wai << endl;
            return wai != 0 ? nei * wai : nei;
        }
        else
        {
            auto itr = x.begin();
            while (*itr != '(')
            {
                wai *= 10;
                wai += *itr - '0';
                itr++;
            }
            itr++;
            while (*itr != '+')
            {
                lp *= 10;
                lp += *itr - '0';
                itr++;
            }
            itr++;
            while (*itr != ')')
            {
                rp *= 10;
                rp += *itr - '0';
                itr++;
            }
            itr++;
            if (itr != x.end())
            {
                while (itr != x.end())
                {
                    wai2 *= 10;
                    wai2 += *itr - '0';
                    itr++;
                }
                return wai * (lp + rp) * wai2;
            }
            else
            {
                return wai * (lp + rp);
            }
        }
    }
    string minimizeResult(string expression)
    {
        string ans;
        int n = expression.size();
        int add_pos = expression.find('+');
        int minn = INT_MAX;
        for (int l = 0; l < add_pos; ++l)
        {
            for (int r = add_pos + 1; r < n; ++r)
            {
                string s = expression;
                s.insert(s.begin() + l, '(');
                s.insert(s.begin() + r + 2, ')');
                int tmp = compute(s);
                // cout << s << " " << tmp << endl;
                if (tmp < minn)
                {
                    minn = tmp;
                    ans = s;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minimizeResult("247+38");
}