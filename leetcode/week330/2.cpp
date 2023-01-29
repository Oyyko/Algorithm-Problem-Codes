#include <bits/stdc++.h>

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

constexpr int MOD = 1000000007;
class Solution
{
public:
    using ll = long long;
    ll pow2(int n)
    {
        if (n == 1)
            return 2;
        if (n == 2)
            return 4;
        if (n == 0)
            return 1;
        ll tmp = pow2(n / 2);
        if (n % 2 == 0)
        {
            return (tmp * tmp) % MOD;
        }
        else
        {
            return (tmp * tmp * 2) % MOD;
        }
    }
    int monkeyMove(int n)
    {
        long long ans = pow2(n);
        ans -= 2;
        if (ans < 0)
            ans += MOD;
        return static_cast<int>(ans);
    }
};

int main()
{
}