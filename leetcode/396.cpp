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
    int maxRotateFunction(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        int tmp = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            tmp += i * nums[i];
        }
        ans = tmp;
        for (int i = 1; i < n; ++i)
        {
            tmp = tmp + sum - n * nums[n - i];
            ans = max(ans, tmp);
        }
        return ans;
    }
};

int main()
{
}