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
    long long minimumRemoval(vector<int> &beans)
    {
        long long ans{LONG_LONG_MAX};
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long cnt{};
        for (int i{1}; i < n; ++i)
        {
            cnt += beans[i] - beans[0];
        }
        ans = min(cnt, ans);
        for (int i{1}; i < n; ++i)
        {
            cnt += beans[i - 1];
            long long d = beans[i] - beans[i - 1];
            long long nn = n - i;
            cnt -= d * nn;
            // cout << i << " " << cnt << endl;
            ans = min(cnt, ans);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{4, 1, 6, 5};
    cout << s.minimumRemoval(v);
}