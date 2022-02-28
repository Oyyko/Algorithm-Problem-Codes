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
    vector<int> countSmaller(vector<int> &nums)
    {
        multiset<int> L;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i)
        {
            auto location = lower_bound(L.begin(), L.end(), nums[i]);
            ans[i] = location - L.begin();
            L.insert(location, nums[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{5, 2, 6, 1};
    pr(s.countSmaller(v));
}