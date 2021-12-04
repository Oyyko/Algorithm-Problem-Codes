#include <bits/stdc++.h>

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
    int maxx(const vector<int> &v)
    {
        int ans{INT_MIN};
        for (const auto &x : v)
        {
            ans = max(x, ans);
        }
        return ans;
    }
    int yes(int mid, const int &n, const vector<int> &v)
    {
        int need{};
        for (const auto &x : v)
        {
            need += (x - 1) / mid + 1;
        }
        return n >= need;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int m = quantities.size();
        if (m == n)
            return maxx(quantities);
        int l{1}, r{100000};
        int mid{};
        while (l < r)
        {
            mid = (l) + (r - l) / 2;
            if (yes(mid, n, quantities))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution s;
    auto v = vector<int>{100000};
    cout << s.minimizedMaximum(1, v);
}