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

struct frac
{
    int fenzi, fenmu;
    frac(int a, int b)
    {
        int tmp = __gcd(a, b);
        a /= tmp, b /= tmp;
        fenzi = a, fenmu = b;
    }
    frac(int x1, int y1, int x2, int y2) : frac(y2 - y1, x2 - x1)
    {
    }
    bool operator==(const frac &rhs) const
    {
        return fenzi == rhs.fenzi && fenmu == rhs.fenmu;
    }
};

class Solution
{
public:
    int minimumLines(vector<vector<int>> &stockPrices)
    {
        int n = stockPrices.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
        int ans{};
        sort(stockPrices.begin(), stockPrices.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        frac tmp(stockPrices[0][0], stockPrices[0][1], stockPrices[1][0], stockPrices[1][1]);
        for (int i = 1; i <= n - 2; ++i)
        {
            frac tmp2(stockPrices[i][0], stockPrices[i][1], stockPrices[i + 1][0], stockPrices[i + 1][1]);
            if (!(tmp == tmp2))
            {
                ans++;
            }
            tmp = tmp2;
        }
        ans++;
        return ans;
    }
};

int main()
{
}