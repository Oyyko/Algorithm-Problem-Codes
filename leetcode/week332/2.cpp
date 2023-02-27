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
public:
    using ll = long long;
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        ll ans{};
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            auto j1 = lower_bound(nums.begin(), nums.end(), lower - nums[i]);
            auto j2 = upper_bound(nums.begin(), nums.end(), upper - nums[i]);
            ans += j2 - j1;
            auto ii = nums.begin() + i;
            if (ii >= j1 && ii <= j2)
                ans -= 1;
        }
        return ans / 2;
    }
};

int main()
{
}