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
    using ll = long long;
    ll ab, ac, bc, abc;
    ll lcm(ll a, ll b)
    {
        return a * b / __gcd(a, b);
    }
    bool check(ll mid, int a, int b, int c, int n)
    {
        return (mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc) >= n;
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int l = 0, r = 2 * 1e9;
        ab = lcm(a, b);
        bc = lcm(b, c);
        ac = lcm(a, c);
        abc = lcm(ab, c);
        while (l < r)
        {
            ll mid = l + (r - l) / 2;
            if (check(mid, a, b, c, n))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution s;
    s.nthUglyNumber(4, 2, 3, 4);
    cout << "AAA\n";
    cout << s.check(4, 2, 3, 4, 4);
}