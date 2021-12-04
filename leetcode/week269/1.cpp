#include <bits/stdc++.h>

using namespace std;

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
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0, _ = nums.size(); i < _; ++i)
        {
            if (nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
}