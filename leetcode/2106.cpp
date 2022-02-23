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
    int solve(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();
        int p = upper_bound(fruits.begin(), fruits.end(), vector<int>{startPos, 0xffffff}) - fruits.begin();
        p--;
        int ans{};
        int r{}, sum{};
        for (int i{}; i <= p; ++i)
            sum += fruits[i][1];
        for (int l{}; l <= p; ++l)
        {
            if (l >= 1)
                sum -= fruits[l - 1][1];
            if (startPos - fruits[l][0] > k)
                continue;
            r = max(r, l);
            while (r + 1 < n && startPos - fruits[l][0] + fruits[r + 1][0] - fruits[l][0] <= k)
            {
                r++;
                if (r > p)
                    sum += fruits[r][1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int ans{solve(fruits, startPos, k)};
        for (auto &x : fruits)
            x[0] *= -1;
        reverse(begin(fruits), end(fruits));
        ans = max(ans, solve(fruits, startPos, k));
        return ans;
    }
};

int main()
{
}