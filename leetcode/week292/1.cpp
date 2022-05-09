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
    string largestGoodInteger(string num)
    {
        int ans = -1;
        int n = num.size();
        for (int i = 0; i + 2 < n; ++i)
        {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                ans = max(ans, num[i] - '0');
            }
        }
        if (ans == -1)
        {
            return "";
        }
        return to_string(ans) + to_string(ans) + to_string(ans);
    }
};

int main()
{
}