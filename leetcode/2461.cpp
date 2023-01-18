#include "base.hpp"

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
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        ll maxsum{}, sum{};
        map<int, int> mp;
        for (int i{}; i < k; ++i)
        {
            mp[nums[i]]++;
            sum += nums[i];
        }
        if (mp.size() == k)
        {
            maxsum = sum;
        }
        int n = nums.size();
        for (int l = 1; l + k <= n; ++l)
        {
            sum -= nums[l - 1];
            sum += nums[l + k - 1];
            mp[nums[l - 1]]--;
            if (mp[nums[l - 1]] == 0)
            {
                mp.erase(nums[l - 1]);
            }
            mp[nums[l + k - 1]]++;
            if (mp.size() == k)
            {
                maxsum = max(maxsum, sum);
            }
        }
        return maxsum;
    }
};

int main()
{
}