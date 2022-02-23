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
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        vector<int> fenshu(n + 1, 0);
        for (auto &x : nums)
        {
            fenshu[0] += x == 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (nums[i - 1] == 0)
            {
                fenshu[i] = fenshu[i - 1] + 1;
            }
            else
            {
                fenshu[i] = fenshu[i - 1] - 1;
            }
        }
        int max_fenshu{INT_MIN};
        for (auto &x : fenshu)
        {
            // cout << x << endl;
            max_fenshu = max(max_fenshu, x);
        }
        for (int i{}; i <= n; ++i)
        {
            if (fenshu[i] == max_fenshu)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{0, 0, 0};
    pr(s.maxScoreIndices(v));
}