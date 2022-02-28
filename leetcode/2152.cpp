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
    int minimumLines(vector<vector<int>> &points)
    {
        int n = points.size();
        const int limit = (1 << n);
        vector<int> dp((1 << n), 0);
        for (int set{1}; set < limit; ++set)
        {
            // 如果只有小于等于两个点 那么一定共线
            if (int num_of_points = __builtin_popcount(set); num_of_points <= 2)
            {
                dp[set] = 1;
                continue;
            }
            // 3点共线
            // (x1-x0)/(y1-y0) == (x2-x0)/(y2-y0)
            // (x1-x0)*(y2-y0) == (x2-x0)*(y1-y0)、
            // 看一下是不是集合中所有点都共线
            // 固定x1,x0,y1,y0 让其他的点来做x2,y2
            int x0, y0, x1, y1;
            int cnt{};
            bool all_points_on_one_line = true;
            for (int j{}; j < n; ++j)
            {
                if (set & (1 << j))
                {
                    if (cnt == 0)
                        x0 = points[j][0], y0 = points[j][1], cnt++;
                    else if (cnt == 1)
                        x1 = points[j][0], y1 = points[j][1], cnt++;
                    else
                    {
                        int x2{points[j][0]}, y2{points[j][1]};
                        if ((x1 - x0) * (y2 - y0) != (x2 - x0) * (y1 - y0))
                        {
                            all_points_on_one_line = false;
                            break;
                        }
                    }
                }
            }
            if (all_points_on_one_line)
            {
                dp[set] = 1;
                continue;
            }
            // 如果并不是所有点都在一个直线上，那么枚举set的子集subset
            // dp[set] = min(dp[set], dp[set & (~subset)] + dp[subset]);
            int subset = set;
            dp[set] = INT_MAX;
            while (subset)
            {
                dp[set] = min(dp[set], dp[set & (~subset)] + dp[subset]);
                subset = (subset - 1) & set;
            }
        }
        return dp[(1 << n) - 1];
    }
};

int main()
{
    Solution s;
}