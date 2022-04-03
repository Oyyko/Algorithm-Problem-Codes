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
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, int> cnt;
        set<int> winners;
        for (auto &x : matches)
        {
            cnt[x[1]]++;
            winners.insert(x[0]);
        }
        vector<vector<int>> ans(2);
        for (auto &[player, shu] : cnt)
        {
            if (shu == 0)
                ans[0].push_back(player);
            if (shu == 1)
                ans[1].push_back(player);
        }
        for (auto &x : winners)
        {
            if (cnt.find(x) == cnt.end())
                ans[0].push_back(x);
        }
        return ans;
    }
};

int main()
{
}