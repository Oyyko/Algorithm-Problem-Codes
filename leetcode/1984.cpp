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
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        sort(begin(nums), end(nums));
        int n = nums.size();
        if (k == n)
            return nums.back() - nums.front();
        int ans{INT_MAX};
        for (int i{}; i + k - 1 <= n - 1; ++i)
        {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};

int main()
{
}