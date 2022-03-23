#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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
    int maximumTop(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1 && k % 2 == 1)
            return -1;
        if (n == 1 && k % 2 == 0)
            return nums[0];
        int maxx = -1;

        if (k <= n)
        {
            for (int i = 0; i <= k - 2; ++i)
                maxx = max(maxx, nums[i]);
            if (k < n)
                maxx = max(maxx, nums[k]);
            return maxx;
        }
        else
        {
            for (auto &x : nums)
                maxx = max(maxx, x);
            return maxx;
        }
    }
};

int main()
{
    vector<int> v{35, 43, 23, 86, 23, 45, 84, 2, 18, 83, 79, 28, 54, 81, 12, 94, 14, 0, 0, 29, 94, 12, 13, 1, 48, 85, 22, 95, 24, 5, 73, 10, 96, 97, 72, 41, 52, 1, 91, 3, 20, 22, 41, 98, 70, 20, 52, 48, 91, 84, 16, 30, 27, 35, 69, 33, 67, 18, 4, 53, 86, 78, 26, 83, 13, 96, 29, 15, 34, 80, 16, 49};
    Solution s;
    for (int i = 0; i <= 14; ++i)
        cout << v[i] << endl;
    cout << s.maximumTop(v, 15);
}

//[91,98,17,79,15,55,47,86,4,5,17,79,68,60,60,31,72,85,25,77,8,78,40,96,76,69,95,2,42,87,48,72,45,25,40,60,21,91,32,79,2,87,80,97,82,94,69,43,18,19,21,36,44,81,99]
// 2
// 98