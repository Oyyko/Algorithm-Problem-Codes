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
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int ans{-1}, pre{nums[0]};
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > pre)
                ans = max(ans, nums[i] - pre);
            else
                pre = nums[i];
        }
        return ans;
    }
};

int main()
{
}