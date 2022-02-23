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
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = accumulate(nums.begin(), nums.end(), 0) - nums[0] * n;
        for (int i = 1; i < n; ++i)
            ans[i] = ans[i - 1] - (n - i * 2) * (nums[i] - nums[i - 1]);
        return ans;
    }
};

int main()
{
}