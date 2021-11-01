#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        const int n = nums.size() / 2;
        vector<vector<int>> s(n + 1);
        int ans = INT_MAX;
        for (int i = 0; i < (1 << n); ++i)
        {
            int sum{}, cnt{};
            for (int j{}; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    sum += nums[j];
                    cnt++;
                }
                else
                    sum -= nums[j];
            }
            s[cnt].push_back(sum);
        }
        for (auto &x : s)
        {
            sort(x.begin(), x.end());
        }

        for (int i = 0; i < (1 << n); ++i)
        {
            int sum{}, cnt{};
            for (int j{}; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    sum += nums[n + j];
                    cnt++;
                }
                else
                    sum -= nums[n + j];
            }
            int l{}, r = s[n - cnt].size() - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (s[n - cnt][mid] <= -sum)
                    l = mid;
                else
                    r = mid - 1;
            }
            ans = min(ans, abs(sum + s[n - cnt][l]));
            if (r < s[n - cnt].size() - 1)
                ans = min(ans, abs(sum + s[n - cnt][r + 1]));
        }
        return ans;
    }
};
int main()
{
}