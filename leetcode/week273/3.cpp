#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
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
    vector<long long> getDistances(vector<int> &arr)
    {
        unordered_map<int, vector<int>> mp;
        int l = arr.size();
        for (int i = 0, _ = arr.size(); i < _; ++i)
        {
            int x = arr[i];
            mp[x].push_back(i);
        }
        vector<long long> ans(l, -1);
        for (int i = 0; i < l; ++i)
        {
            if (ans[i] != -1)
                continue;
            if (mp[arr[i]].size() == 2)
            {
                ans[i] = abs(mp[arr[i]][0] - mp[arr[i]][1]);
                ans[mp[arr[i]][1]] = ans[i];
                continue;
            }
            if (mp[arr[i]].size() == 3)
            {
                int l, m, r;
                l = mp[arr[i]][0];
                m = mp[arr[i]][1];
                r = mp[arr[i]][2];
                ans[l] = r - l + m - l;
                ans[m] = r - l;
                ans[r] = r - l + r - m;
                continue;
            }
            int ll = mp[arr[i]].size();
            for (int ii = 0; ii < ll; ++ii)
            {
                ans[mp[arr[i]][ii]] = 0;
                for (int jj = 0; jj < ll; ++jj)
                {
                    ans[mp[arr[i]][ii]] += abs(mp[arr[i]][ii] - mp[arr[i]][jj]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821, 98818, 98821, 98818};
    for (auto &x : v)
    {
        x -= 98815;
    }
    pr(v);
    pr(s.getDistances(v));
}