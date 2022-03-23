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
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        vector<vector<int>> dp(13, vector<int>(numArrows + 1, 0));
        vector<vector<int>> yes(13, vector<int>(numArrows + 1, 0));
        for (auto &x : aliceArrows)
            x++;
        for (int i = 1; i <= 12; ++i)
        {
            for (int k = 1; k <= numArrows; ++k)
            {
                int vi = (k - aliceArrows[i - 1] >= 0) ? (i - 1 + dp[i - 1][k - aliceArrows[i - 1]]) : 0;
                int voi = dp[i - 1][k];
                if (vi > voi)
                {
                    yes[i][k] = yes[i - 1][k - aliceArrows[i - 1]] | (1 << (i - 1));
                    dp[i][k] = vi;
                }
                else
                {
                    dp[i][k] = voi;
                    yes[i][k] = yes[i - 1][k];
                }
            }
        }
        // // }}
        cout << dp[12][numArrows] << endl;
        // cout << yes[12][numArrows] << endl;
        vector<int> ans(12, 0);
        for (int i = 0; i < 12; ++i)
        {
            ans[i] = (yes[12][numArrows] & (1 << i)) != 0;
            ans[i] *= aliceArrows[i];
        }
        if (int sum = accumulate(ans.begin(), ans.end(), 0); sum != numArrows)
        {
            int d = numArrows - sum;
            for (int i = 11; i >= 0; --i)
            {
                if (ans[i] == 0 && d >= aliceArrows[i])
                {
                    ans[i] = d;
                    return ans;
                }
            }
            ans[0] = d;
            return ans;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // vector<int> v{1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0};
    // pr(s.maximumBobPoints(9, v));

    vector<int> v{3, 2, 28, 1, 7, 1, 16, 7, 3, 13, 3, 5};
    pr(s.maximumBobPoints(89, v));
}