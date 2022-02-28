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
private:
    using LL = long long;

public:
    bool check(LL mid, vector<int> &time, int totalTrips)
    {
        LL t{};
        for (auto &x : time)
        {
            t += mid / x;
            if (t >= totalTrips)
                return 1;
        }
        return t >= totalTrips;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        LL l{0}, r{LONG_LONG_MAX};
        while (l != r)
        {
            LL mid = l + (r - l) / 2;
            if (check(mid, time, totalTrips))
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
}