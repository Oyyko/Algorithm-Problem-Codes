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
    vector<int> recoverArray(int n, vector<int> &sums)
    {
        sort(begin(sums), end(sums));
        vector<int> ans(n), low(1 << (n - 1)), high(1 << (n - 1));
        vector<bool> vis(1 << n);
        while (n)
        {
            const int d = sums[1] = sums[0], t = 1 << n;
            int l{}, r{1}, cnt{}, flag{};
            vis.assign(t, false);
            while (1)
            {
                while (l < t && vis[l])
                    ++l;
                if (l == t)
                    break;
                low[cnt] = sums[l];
                while (vis[r] || sums[r] != sums[l] + d)
                    ++r;
                high[cnt++] = sums[r];
                vis[r] = true;
                flag |= !sums[l];
            }
            ans[--n] = flag ? (swap(sums, low), d) : (swap(sums, high), -d);
        }
        return ans;
    }
};

int main()
{
}