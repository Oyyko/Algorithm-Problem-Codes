#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

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
public:
    inline int gcd(int a, int b)
    {
        return b > 0 ? gcd(b, a % b) : a;
    }
    using LL = long long;
    long long countPairs(vector<int> &nums, int k)
    {
        unordered_map<int, LL> cnt;
        for (auto &x : nums)
        {
            cnt[gcd(x, k)]++;
        }
        LL ans{};
        using pii = pair<LL, LL>;
        vector<pii> c;
        for (auto &[a, b] : cnt)
        {
            c.push_back({a, b});
        }
        int n = c.size();
        for (int i{}; i < n; ++i)
        {
            auto [a, ac] = c[i];
            if (a * a % k == 0)
            {
                ans += ac * (ac - 1) / 2;
            }
            for (int j{i + 1}; j < n; ++j)
            {
                auto [b, bc] = c[j];
                if (a * b % k == 0)
                {
                    ans += ac * bc;
                }
            }
        }
        return ans;
    }
};

int main()
{
}