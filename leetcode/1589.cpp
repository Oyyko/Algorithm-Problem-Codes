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
    const int MOD = 1000000007;
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for (auto &r : requests)
        {
            cnt[r[0]]++;
            if (r[1] + 1 < n)
                cnt[r[1] + 1]--;
        }
        partial_sum(cnt.begin(), cnt.end(), cnt.begin());
        // pr(cnt);
        sort(cnt.begin(), cnt.end());
        sort(nums.begin(), nums.end());
        long long ans{};
        for (int i = 0; i < n; ++i)
        {
            ans += (nums[i] + 0ll) * cnt[i];
            ans %= MOD;
        }
        return ans;
    }
};

int main()
{
}