#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int len = nums.size();
        int rm_size = len - k;
        if (!rm_size)
            return nums;
        vector<int> ans{};
        for (auto x : nums)
        {
            while (rm_size && !ans.empty() && x < ans.back())
            {
                ans.pop_back();
                rm_size--;
            }
            ans.push_back(x);
        }
        for (int i = 0; i < rm_size; ++i)
        {
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{3, 5, 2, 6};
    pr(s.mostCompetitive(nums, 2));
}