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
    bool possible(int guess, int k, vector<int> &nums)
    {
        int cnt{}, l{};
        int right;
        int now;
        for (right = 0, now = nums[0]; right < nums.size(); ++right, now = nums[right])
        {
            while (now > guess + nums[l])
            {
                l++;
            }
            cnt += right - l;
        }
        return cnt >= k;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l{}, r{nums.back() - nums.front()};
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (possible(m))
                h = m;
            else
                l = m + 1;
        }
        return l;
    }
};

int main()
{
}