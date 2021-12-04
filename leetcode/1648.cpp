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

class Solution
{
private:
    const int MOD = 1000000007;

public:
    int maxProfit(vector<int> &inventory, int orders)
    {
        long long ans{};
        long long s{};
        for (auto &x : inventory)
            s += x;
        sort(inventory.begin(), inventory.end());
        long long r = s - orders;
        int n = inventory.size();
        for (long long i{}; i < n; ++i)
        {
            long long _ = inventory[i];
            long long each = r / (n - i);
            if (_ > each)
                ans += (each + 1ll + _) * (_ - static_cast<long long>(each)) / 2;
            r -= min(each, _);
        }
        return ans % MOD;
    }
};

int main()
{
}