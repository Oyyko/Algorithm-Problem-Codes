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
    using LL = long long;

public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 0)
            return nums;
        if (n - k - 1 < k)
        {
            return vector<int>(n, -1);
        }
        vector<LL> ans(n, -1);
        int dd = 2 * k + 1;
        for (int i = k; i <= n - k - 1; ++i)
        {
            ans[i] = 0;
            if (i == k)
            {
                for (int j = i - k; j <= i + k; ++j)
                {
                    ans[i] += nums[j];
                }
            }
            else
            {
                ans[i] = ans[i - 1] - nums[i - k - 1] + nums[i + k];
            }
        }
        vector<int> ans2(n, -1);
        for (int i = k; i <= n - k - 1; ++i)
        {
            ans2[i] = ans[i] / dd;
        }
        return ans2;
    }
};

int main()
{
}