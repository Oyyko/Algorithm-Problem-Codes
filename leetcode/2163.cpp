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
    long long minimumDifference(vector<int> &nums)
    {
        int m = nums.size(), n = m / 3;
        priority_queue<int, vector<int>, greater<int>> minPQ;
        long sum = 0L;
        for (int i = m - n; i < m; ++i)
        {
            minPQ.push(nums[i]);
            sum += nums[i];
        }
        vector<long> sufMax(m - n + 1);
        sufMax[m - n] = sum;
        for (int i = m - n - 1; i >= n; --i)
        {
            minPQ.push(nums[i]);
            sum += nums[i] - minPQ.top();
            minPQ.pop();
            sufMax[i] = sum;
        }

        priority_queue<int> maxPQ;
        long preMin = 0L;
        for (int i = 0; i < n; ++i)
        {
            maxPQ.push(nums[i]);
            preMin += nums[i];
        }
        long ans = preMin - sufMax[n];
        for (int i = n; i < m - n; ++i)
        {
            maxPQ.push(nums[i]);
            preMin += nums[i] - maxPQ.top();
            maxPQ.pop();
            ans = min(ans, preMin - sufMax[i + 1]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{3, 1, 2};
    cout << s.minimumDifference(v);
}