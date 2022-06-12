#include <iostream>
#include <random>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int now_minn = -2 * k - 10;
        int ans{};
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] - now_minn > k)
            {
                now_minn = nums[i];
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
}