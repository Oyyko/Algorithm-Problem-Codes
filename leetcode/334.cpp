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
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        int dp1{INT_MAX}, dp2{INT_MAX};
        if (n <= 2)
            return 0;
        for (int i{}; i < n; ++i)
        {
            if (nums[i] > dp2)
                return 1;
            else if (nums[i] > dp1 && nums[i] < dp2)
                dp2 = nums[i];
            else if (nums[i] < dp1)
                dp1 = nums[i];
            // cout << dp1 << " " << dp2 << endl;
        }
        return 0;
    }
};

int main()
{
    vector<int> v = {1, 0, 0, 0, 0, 0, 0, 2};
    Solution s;
    cout << s.increasingTriplet(v);
}