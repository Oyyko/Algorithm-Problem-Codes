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
    int numberOfWays(string corridor)
    {
        const int MOD = 1000000007;
        long long ans{1};
        int n = corridor.size();
        int cnt{}, pre{-1};
        for (int i{}; i < n; ++i)
        {
            if (corridor[i] == 'S')
            {
                cnt++;
                if (cnt >= 3 && cnt & 1)
                {
                    ans *= (i - pre);
                    ans %= MOD;
                }
                pre = i;
            }
        }
        if (!cnt || cnt & 1)
            return 0;
        return ans;
    }
};

int main()
{
}