// #include <bits/stdc++.h>

// using namespace std;

// using LL = long long;

// template <typename T>
// void pr(vector<T> x)
// {
//     for (auto a : x)
//     {
//         cout << a << " ";
//     }
//     cout << endl;
// }
// class Solution
// {
// public:
//     vector<int> targetIndices(vector<int> &nums, int target)
//     {
//         sort(nums.begin(), nums.end());
//         auto r = upper_bound(nums.begin(), nums.end(), target);
//         --r;
//         auto l = lower_bound(nums.begin(), nums.end(), target);
//         int i = r - nums.begin();
//         int j = l - nums.begin();
//         vector<int> ans;
//         for (int _ = j; _ <= i; ++_)
//         {
//             ans.push_back(_);
//         }
//         return ans;
//     }
// };

// int main()
// {
//     Solution s;
//     vector<int> v{1, 2, 5, 2, 3};
//     pr(s.targetIndices(v, 2));
// }

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
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        int a{}, b{};
        for (const auto &x : nums)
        {
            a += x < target;
            b += x == target;
        }
        vector<int> ans;
        for (int _{a}; _ < a + b; ++_)
        {
            ans.push_back(_);
        }
        return ans;
    }
};

int main()
{
}