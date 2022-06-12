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
#include <iomanip>
class Solution
{
public:
    string process(const string &s, int ss, int ee, double dd)
    {
        // cout << "[AAA]" << s.substr(ss, ee - ss + 1) << "  " << ee - ss + 1 << endl;
        if (s[ss] != '$')
            return s.substr(ss, ee - ss + 1);
        if (ee == ss)
            return "$"s;
        int point = 0;
        for (int i = ss + 1; i <= ee; ++i)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                if (s[i] == '.')
                    point++;
                else
                    return s.substr(ss, ee - ss + 1);
                if (point == 2)
                    return s.substr(ss, ee - ss + 1);
            }
        }
        string tmp = s.substr(ss + 1, ee - ss);
        stringstream ss1(tmp);
        double num;
        ss1 >> num;
        num *= (1 - dd);
        stringstream ss2;
        ss2 << setiosflags(ios::fixed) << setprecision(2) << num;
        return "$"s + ss2.str();
    }
    string discountPrices(string sentence, int discount)
    {
        string ans;
        double dd = discount / 100.0;
        int state = 0;
        int ss, ee;
        sentence.push_back(' ');
        int n = sentence.size();
        for (int i = 0; i < n; ++i)
        {
            // cout << i << state << endl;
            char c = sentence[i];
            if (state == 0)
            {
                if (c == ' ')
                {
                    ans.push_back(' ');
                }
                else
                {
                    state = 1;
                    ss = i;
                }
            }
            else
            {
                if (c == ' ')
                {
                    state = 0;
                    ee = i - 1;
                    ans += (process(sentence, ss, ee, dd));
                    ans.push_back(' ');
                }
                else
                {
                }
            }
        }
        return ans.substr(0, ans.size() - 1);
    }
};

int main()
{
    Solution s;
    cout << s.discountPrices("there are $1 $2 and 5$ candies in the shop", 50);
}