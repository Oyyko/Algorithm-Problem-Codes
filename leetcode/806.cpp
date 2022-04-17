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
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int hang{};
        int now{};
        for (auto &x : s)
        {
            now += widths[x - 'a'];
            if (now > 100)
                hang++, now = widths[x - 'a'];
        }
        vector<int> ans;
        ans.push_back(hang);
        ans.push_back(now);
        if (ans[1] != 0)
            ans[0]++;
        return ans;
    }
};

int main()
{
}