#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    int waysToPartition(vector<int> &nums, int k)
    {
        int l = nums.size();
        vector<long long> presum;
        presum.resize(l);
        presum[0] = nums[0];
        for (int i = 1; i < l; ++i)
        {
            presum[i] = presum[i - 1] + nums[i];
        }
        unordered_map<long long, long long> left, right;
        long long ans{};
        for (int i = 0; i <= l - 2; ++i)
        {
            right[presum[i]]++;
        }
        ans = right[presum[l - 1] / 2];
        cout << "ANS: " << ans << endl;
        ans = max(ans, left[(presum[l - 1] - nums[0] + k) / 2] + right[presum[l - 1] / 2 - (k - nums[0]) / 2]);
        for (int i = 1; i <= l - 1; ++i)
        {

            left[presum[i - 1]]++;
            right[presum[i - 1]]--;
            if ((presum[l - 1] - nums[i] + k) % 2 == 0 && (presum[l - 1] + nums[i] - k) % 2 == 0)
                ans = max(ans, left[(presum[l - 1] - nums[i] + k) / 2] + right[(presum[l - 1] + nums[i] - k) / 2]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30827, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << v.size() << endl;
    cout << s.waysToPartition(v, 0);
}