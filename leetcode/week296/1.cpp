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
    int minMaxGame(vector<int> &nums)
    {
        int n;
        while (nums.size() != 1)
        {
            n = nums.size();
            vector<int> newNums(n / 2);
            for (int i = 0; i < n / 2; i++)
            {
                if (i % 2 == 0)
                {
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
                else
                {
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            nums = newNums;
        }
        return nums[0];
    }
};

int main()
{
}