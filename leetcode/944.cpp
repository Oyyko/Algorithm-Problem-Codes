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
    int minDeletionSize(vector<string> &strs)
    {
        int cnt{};
        int n = strs.size();
        int m = strs[0].size();
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i <= n - 2; ++i)
            {
                if (strs[i][j] > strs[i + 1][j])
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main()
{
}