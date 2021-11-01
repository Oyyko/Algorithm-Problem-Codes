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
    void getsum(vector<int> &nums, vector<int> &sum, int s)
    {
        int i, j, bit;
        for (i = 1; i < sum.size(); ++i)
        {
            for (j = 0, bit = 1; bit < sum.size(); ++j, bit <<= 1)
            {
                if ((i & bit) != 0)
                {
                    sum.at(i) = sum.at(i ^ bit) + nums.at(j + s);
                    break;
                }
            }
        }
    }

public:
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int half = n / 2;
        int ans = abs(goal);
        vector<int> sum1(1 << half, 0);
        vector<int> sum2(1 << (n - half), 0);
        getsum(nums, sum1, 0);
        sort(sum1.begin(), sum1.end());
        auto itr = lower_bound(sum1.begin(), sum1.end(), goal);
        if (itr != sum1.end())
        {
            ans = min(ans, abs(*itr - goal));
        }
        if (itr != sum1.begin())
        {
            ans = min(ans, abs(goal - *(--itr)));
        }

        getsum(nums, sum2, half);
        sort(sum2.begin(), sum2.end());
        itr = lower_bound(sum2.begin(), sum2.end(), goal);
        if (itr != sum2.end())
        {
            ans = min(ans, abs(*itr - goal));
        }
        if (itr != sum2.begin())
        {
            ans = min(ans, abs(goal - *(--itr)));
        }

        int ans2{INT_MAX};
        int l = 0, r = sum2.size() - 1;
        int sum{};
        while (l < sum1.size() && r >= 0)
        {
            sum = sum1.at(l) + sum2.at(r);
            ans2 = min(ans2, abs(sum - goal));
            if (sum == goal)
                break;
            if (sum > goal)
                --r;
            else
                ++l;
        }

        return min(ans, ans2);
    }
};

int main()
{
    vector<int> s{7, -9, 15, -2};
    Solution ss;
    cout << ss.minAbsDifference(s, -5);
}