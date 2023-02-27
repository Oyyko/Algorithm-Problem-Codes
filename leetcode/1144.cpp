#include "base.hpp"

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int ans1{}, ans2{};
        auto legal = [&n](int x)
        { return x >= 0 && x < n; };
        auto diff = [&nums](int i, int j)
        {if(nums[i]<nums[j])return 0;return nums[i]-nums[j]+1; };
        for (int i = 0; i < n; i += 2)
        {
            if (!legal(i - 1))
                ans1 += diff(i, i + 1);
            else if (!legal(i + 1))
                ans1 += diff(i, i - 1);
            else
                ans1 += max(diff(i, i + 1), diff(i, i - 1));
        }
        for (int i = 1; i < n; i += 2)
        {
            if (!legal(i - 1))
                ans2 += diff(i, i + 1);
            else if (!legal(i + 1))
                ans2 += diff(i, i - 1);
            else
                ans2 += max(diff(i, i + 1), diff(i, i - 1));
        }
        return min(ans1, ans2);
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3};
    cout << s.movesToMakeZigzag(v);
}