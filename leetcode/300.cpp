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
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> d; // d[len]=k 即 长为len的子序列，最小的末尾数是k
        d.push_back(nums[0]);
        for (int i{1}; i < n; ++i)
        {
            if (nums[i] > d.back())
            {
                d.push_back(nums[i]);
            }
            else
            {
                auto l = lower_bound(d.begin(), d.end(), nums[i]);
                *l = nums[i];
            }
        }
        return d.size();
    }
};

int main()
{
}