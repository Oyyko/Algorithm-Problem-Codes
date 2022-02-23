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
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int i{}, j{};
        vector<int> ans;
        int n = nums.size();
        while (ans.size() < n)
        {
            while (nums[i] < 0)
                i++;
            while (nums[j] > 0)
                j++;
            ans.push_back(nums[i]), i++;
            ans.push_back(nums[j]), j++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{3, 1, -2, -5, 2, -4};
    pr(s.rearrangeArray(v));
}