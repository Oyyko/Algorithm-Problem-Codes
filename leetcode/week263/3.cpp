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
private:
    int orr(int subset, const vector<int> &nums)
    {
        int ans{};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (subset & (1 << i))
            {
                ans |= nums[i];
            }
        }
        return ans;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int sett = (1 << (nums.size()));
        int orr1 = orr(sett - 1, nums);
        int ans{};
        for (int k = 0; k <= sett - 1; ++k)
        {
            if (orr(k, nums) == orr1)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{2, 2, 2};
    cout << s.countMaxOrSubsets(v);
}