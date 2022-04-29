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
#include <random>

class Solution
{
public:
    vector<int> &v;
    Solution(vector<int> &nums)
    {
        v = nums;
    }

    int pick(int target)
    {
        int ans = -1;
        int n = v.size();
        int cnt{};
        for (int i = 0; i < n; ++i)
        {
            if (v[i] == target)
            {
                cnt++;
                if (rand() % cnt == 0)
                {
                    ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main()
{
}