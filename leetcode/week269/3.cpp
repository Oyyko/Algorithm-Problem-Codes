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
    int minimumDeletions(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int maxi{};
        int mini{};
        int maxx{INT_MIN};
        int minn{INT_MAX};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > maxx)
            {
                maxx = nums[i];
                maxi = i;
            }
            if (nums[i] < minn)
            {
                minn = nums[i];
                mini = i;
            }
        }
        int a1, a2, a3, a4;
        a1 = max(maxi, mini) + 1;
        a2 = nums.size() - min(maxi, mini);
        a3 = min(maxi, mini) + 1 + (nums.size() - max(maxi, mini));
        return min(a1, min(a2, a3));
    }
};

int main()
{
}