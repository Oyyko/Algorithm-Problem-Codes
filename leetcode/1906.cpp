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
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums.size();
        vector<vector<int>> presum(n, vector<int>(101, 0));
        presum[0][nums[0]]++;
        for (int i = 1; i < n; ++i)
        {
            presum[i] = presum[i - 1];
            presum[i][nums[i]]++;
        }
        for (auto &x : queries)
        {
            int &ll = x[0], &rr = x[1];
            int best = INT_MAX;
            int last = 0;
            for (int i = 1; i <= 100; ++i)
            {
                if (ll)
                {
                    if (presum[rr][i] - presum[ll - 1][i] > 0)
                    {
                        if (last)
                        {
                            best = min(i - last, best);
                        }
                        last = i;
                    }
                }
                else
                {
                    if (presum[rr][i])
                    {
                        if (last)
                        {
                            best = min(i - last, best);
                        }
                        last = i;
                    }
                }
            }
            ans.push_back(best == INT_MAX ? -1 : best);
        }
        return ans;
    }
};

int main()
{
}