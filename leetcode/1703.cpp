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
    int minMoves(vector<int> &nums, int k)
    {
        vector<int> ones;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                ones.push_back(i);
            }
        }
        int now{};
        for (int i = 0; i < k; ++i)
        {
            now += abs(ones[i] - ones[k / 2]) - abs(i - k / 2);
        }
        int ans{now};
        int mid{};
        for (int i = k; i < ones.size(); ++i)
        {
            mid = i - k + k / 2;
            now -= ones[mid] - ones.at(i - k >= 0 ? i - k : ones.size() + i - k) - mid + (i - k);
            mid = i - k + 1 + (k - 1) / 2;
            now += ones[i] - ones[mid] - (i - mid);
            cout<<"NOW"<<now<<endl;
            ans = min(ans, now);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 0, 0, 1, 0, 1};
    Solution s;
    cout << s.minMoves(nums, 2) << "AAA";
}