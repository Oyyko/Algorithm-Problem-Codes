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
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
            return nums;
        vector<int> v1, v2;
        for (int i{}; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                v1.push_back(nums[i]);
            }
            else
            {
                v2.push_back(nums[i]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());
        int cnt{};
        vector<int> ans;
        for (int i1{}, i2{}; i1 < v1.size() || i2 < v2.size(); ++i1, ++i2)
        {
            if (i1 < v1.size())
            {
                ans.push_back(v1[i1]);
            }
            if (i2 < v2.size())
            {
                ans.push_back(v2[i2]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4, 5};
    pr(s.sortEvenOdd(v));
}