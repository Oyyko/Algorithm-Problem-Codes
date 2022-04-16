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
    int giveGem(vector<int> &gem, vector<vector<int>> &operations)
    {
        for (auto &v : operations)
        {
            int tmp = gem[v[0]] / 2;
            gem[v[0]] -= tmp;
            gem[v[1]] += tmp;
        }
        int minn = accumulate(gem.begin(), gem.end(), INT_MAX, [](int a, int b)
                              { return min(a, b); });
        int maxx = accumulate(gem.begin(), gem.end(), INT_MIN, [](int a, int b)
                              { return max(a, b); });
        return maxx - minn;
    }
};

int main()
{
}