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

// 暴力 O(n^2)做法
// class Solution
// {
// public:
//     using LL = long long;
//     long long subArrayRanges(vector<int> &nums)
//     {
//         LL ans{};
//         int minn = INT_MAX;
//         int maxx = INT_MIN;
//         int n = nums.size();
//         for (int l{}; l < n; ++l)
//         {
//             minn = nums[l];
//             maxx = nums[l];
//             for (int r{l + 1}; r < n; ++r)
//             {
//                 minn = min(minn, nums[r]);
//                 maxx = max(maxx, nums[r]);
//                 ans += maxx - minn;
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    using LL = long long;
    long long subArrayRanges(vector<int> &nums)
    {
        LL ans{};
        stack<int> s;
        int n = nums.size();
        vector<LL> l_less(n), r_more(n), l_more(n), r_less(n);
        for (int i{}; i < n; ++i)
        {
            while (!s.empty() && nums[i] > nums[s.top()])
                r_more[s.top()] = i, s.pop();
            s.push(i);
        }
        while (!s.empty())
            r_more[s.top()] = n, s.pop();

        for (int i{n - 1}; i >= 0; --i)
        {
            while (!s.empty() && nums[i] < nums[s.top()])
                l_less[s.top()] = i, s.pop();
            s.push(i);
        }
        while (!s.empty())
            l_less[s.top()] = -1, s.pop();

        for (int i{n - 1}; i >= 0; --i)
        {
            while (!s.empty() && nums[i] >= nums[s.top()])
                l_more[s.top()] = i, s.pop();
            s.push(i);
        }
        while (!s.empty())
            l_more[s.top()] = -1, s.pop();

        for (int i{}; i < n; ++i)
        {
            while (!s.empty() && nums[i] <= nums[s.top()])
                r_less[s.top()] = i, s.pop();
            s.push(i);
        }
        while (!s.empty())
            r_less[s.top()] = n, s.pop();

        for (int i{}; i < n; ++i)
        {
            ans += (r_more[i] - i) * (i - l_more[i]) * nums[i];
            ans -= (r_less[i] - i) * (i - l_less[i]) * nums[i];
        }

        return ans;
    }
};

int main()
{
    vector<int> v{4, -2, -3, 4, 1};
    Solution s;
    cout << s.subArrayRanges(v);
}