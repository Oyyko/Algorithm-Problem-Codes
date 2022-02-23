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
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();
        vector<int> dp((1 << n), INT_MAX);
        dp[0] = 0;
        vector<int> valid((1 << n), 0);
        for (int m{}; m < (1 << n); ++m)
        {
            int cnt{};
            for (int j{}; j < n || (valid[m] = 1, 0); ++j)
            {
                if (m & (1 << j))
                {
                    cnt += tasks[j];
                    if (cnt > sessionTime)
                    {
                        break;
                    }
                }
            }
        }
        for (int m{}; m < (1 << n); ++m)
        {
            int subset = m;
            while (subset)
            {
                if (valid[subset])
                {
                    dp[m] = min(dp[m], dp[m & (~subset)] + 1);
                }
                subset = (subset - 1) & m;
            }
        }
        return dp[(1 << n) - 1];
    }
};

int main()
{
}