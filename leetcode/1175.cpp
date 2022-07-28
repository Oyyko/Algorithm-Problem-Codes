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
    const int MOD = 1e9 + 7;
    int numPrimeArrangements(int n)
    {
        vector<int> is_prime(n + 1, 1);
        is_prime[1] = 0;
        is_prime[0] = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (is_prime[i])
            {
                for (int j = 2; i * j <= n; ++j)
                {
                    is_prime[i * j] = 0;
                }
            }
        }
        int p_cnt = accumulate(is_prime.begin(), is_prime.end(), 0);
        long long ans = 1;
        for (int i = 2; i <= p_cnt; ++i)
        {
            ans *= i;
            ans %= MOD;
        }
        for (int i = 2; i <= (n - p_cnt); ++i)
        {
            ans *= i;
            ans %= MOD;
        }
        return ans;
    }
};

int main()
{
}