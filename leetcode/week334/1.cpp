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
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return vector<int>{0};
        vector<int> l(n, 0), r(n, 0);
        for (int i = 1; i < n; ++i)
        {
            l[i] = l[i - 1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i)
        {
            r[i] = r[i + 1] + nums[i + 1];
        }
        // pr(l);
        // pr(r);
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = abs(l[i] - r[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{10, 4, 8, 3};
    pr(s.leftRigthDifference(v));
}