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
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int all_sum = mean * (m + n);
        int ro_sum = accumulate(rolls.begin(), rolls.end(), 0);
        int ans_sum = all_sum - ro_sum;
        int ll = n, rr = 6 * n;
        if (ans_sum < ll || ans_sum > rr)
            return vector<int>{};
        vector<int> ans(n, 0);
        int q = ans_sum / n;
        int r = ans_sum % n;
        for (int i{}; i < r; ++i)
        {
            ans[i] = q + 1;
        }
        for (int i = r; i < n; ++i)
        {
            ans[i] = q;
        }
        return ans;
    }
};

int main()
{
}