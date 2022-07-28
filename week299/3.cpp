#include <iostream>
#include <random>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums)
        {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        auto sum1 = accumulate(nums1.begin(), nums1.end(), 0ll);
        auto sum2 = accumulate(nums2.begin(), nums2.end(), 0ll);
        int n = nums1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i)
        {
            diff[i] = nums2[i] - nums1[i];
        }
        auto maxx1 = maxSubArray(diff);
        for (auto &x : diff)
            x = -x;
        auto maxx2 = maxSubArray(diff);
        return max(sum1, max(sum2, max(sum1 + maxx1, sum2 + maxx2)));
    }
};

int main()
{
}