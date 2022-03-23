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
    using pii = pair<int, int>;
    int countHillValley(vector<int> &nums)
    {
        vector<pii> v;
        int now = nums[0];
        int now_cnt = 0;
        for (int i{}; i < nums.size(); ++i)
        {
            if (nums[i] == now)
            {
                now_cnt++;
            }
            else
            {
                v.push_back({now, now_cnt});
                now = nums[i];
                now_cnt = 1;
            }
        }
        v.push_back({now, now_cnt});
        int n = v.size();
        // for (auto &x : v)
        // {
        //     cout << x.first << "  " << x.second << endl;
        // }
        if (n >= 3)
        {
            int cnt{};
            for (int i = 1; i <= n - 2; ++i)
            {
                cnt += (v[i].first > v[i + 1].first && v[i].first > v[i - 1].first);
                cnt += (v[i].first < v[i + 1].first && v[i].first < v[i - 1].first);
            }
            return cnt;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    vector<int> v{6, 5, 10};
    Solution s;
    cout << s.countHillValley(v);
}