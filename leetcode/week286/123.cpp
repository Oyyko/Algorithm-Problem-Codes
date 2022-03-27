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

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 1)
            return 1;
        if (n == 2)
        {
            if (nums[0] != nums[1])
                return 0;
            else
                return 2;
        }
        if (nums[0] != nums[1])
        {
            dp[1] = 2;
        }
        else
        {
            dp[1] = 0;
        }
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] == nums[i - 1])
                dp[i] = dp[i - 1];
            else
                dp[i] = max(dp[i - 2] + 2, dp[i - 1]);
        }
        if (dp[n - 1] % 2 == 0)
            return n - dp[n - 1];
        else
            return n - dp[n - 1] + 1;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4};
    cout << s.minDeletion(v);
}