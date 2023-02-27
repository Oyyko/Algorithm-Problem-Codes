#include <bits/stdc++.h>

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
    bool yes(const vector<int> &nums, int ans)
    {
        int n = nums.size();
        for (int i = 1; i <= ans; ++i)
        {
            if (nums[i - 1] * 2 > nums[n - ans + i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l{}, r{n / 2};
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (yes(nums, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
            if (r - l == 1)
                break;
        }
        if (l == r)
            return l * 2;
        if (yes(nums, r))
            return r * 2;
        return l * 2;
    }
};

int main()
{
    Solution s;
    vector<int> v{2, 4, 5, 9};
    cout << s.maxNumOfMarkedIndices(v);
}