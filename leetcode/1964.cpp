#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> dp(n, 1);
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < i; ++j)
            {
                if (obstacles[i] >= obstacles[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
};

int main()
{
    vector<int> v{2, 2, 1};
    Solution s;
    pr(s.longestObstacleCourseAtEachPosition(v));
}