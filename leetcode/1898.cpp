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
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = s.size();
        auto yes = [&](int mid) -> bool
        {
            vector<int> ok(n, 1);
            for (int i{}; i < mid; ++i)
                ok[removable[i]] = 0;
            auto j = 0;
            int ii = -1;
            for (const auto &x : s)
            {
                ++ii;
                if (x == p[j] && ok[ii])
                {
                    ++j;
                    if (j == p.size())
                        return true;
                }
            }
            return false;
        };
        int l{0}, r = removable.size() + 1;
        int mid{};
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (yes(mid))
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return l - 1;
    }
};

int main()
{
}