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
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int n = plantTime.size();
        int ans{};
        vector<pair<int, int>> d(n);
        for (int i{}; i < n; ++i)
        {
            d[i] = make_pair(i, growTime[i]);
        }
        sort(d.begin(), d.end(), [](pair<int, int> &x, pair<int, int> &y)
             { return x.second > y.second; });
        int p{};
        for (int i{}; i < n; ++i)
        {
            // cout << plantTime[d[i].first] << d[i].second << endl;
            ans = max(ans, p + plantTime[d[i].first] + d[i].second);
            p += plantTime[d[i].first];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> p{1, 4, 3};
    vector<int> g{2, 3, 1};
    cout << s.earliestFullBloom(p, g);
}