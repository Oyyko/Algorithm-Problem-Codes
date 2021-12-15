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
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        int maxx = INT_MIN;
        int minn = INT_MAX;
        long long ans{};
        for (int l = 0; l < n; ++l)
        {
            maxx = nums[l];
            minn = nums[l];
            for (int r = l; r < n; ++r)
            {
                maxx = max(maxx, nums[r]);
                minn = min(minn, nums[r]);
                ans += maxx - minn;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{4, -2, -3, 4, 1};
    cout << s.subArrayRanges(v);
}