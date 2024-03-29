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
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (hour + 1 <= dist.size()) //注意是小于等于
            return -1;
        auto yes = [&](int speed) -> bool
        {
            int sum{};
            for (int i = 0; i < (dist.size() - 1); ++i)
            {
                sum += (dist[i] - 1) / speed + 1;
            }
            return hour >= sum + static_cast<double>(dist[dist.size() - 1]) / speed;
        };
        int l{1}, r{10000000}; //这里不是10^5，而是根据题意是10^7
        int mid{};
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (yes(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 3, 2};
    cout << s.minSpeedOnTime(v, 2.7);
}