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
    int minFlips(string s)
    {
        int n = s.size();
        int ans{INT_MAX};
        int tmp{};
        if (n % 2 == 0)
        {
            for (int i{}; i < n; ++i)
            {
                tmp += s[i] != (i & 1 ? '0' : '1');
            }
            ans = min(ans, tmp);
            tmp = 0;
            for (int i{}; i < n; ++i)
            {
                tmp += s[i] != (i & 1 ? '1' : '0');
            }
            ans = min(ans, tmp);
            return ans;
        }
        for (int k{}; k <= n; ++k)
        {
            tmp = 0;
            for (int i{}; i < k; ++i)
            {
                tmp += s[i] != (i & 1 ? '1' : '0');
            }
            for (int i{k}; i <= n - 1; ++i)
            {
                tmp += s[i] != (i & 1 ? '0' : '1');
            }
            if (tmp == 3)
                cout << "K:" << k << endl;
            ans = min(ans, tmp);
        }
        for (int k{}; k <= n; ++k)
        {
            tmp = 0;
            for (int i{}; i < k; ++i)
            {
                tmp += s[i] != (i & 1 ? '0' : '1');
            }
            for (int i{k}; i <= n - 1; ++i)
            {
                tmp += s[i] != (i & 1 ? '1' : '0');
            }
            ans = min(ans, tmp);
        }
        return ans;
    }
};

// 00 0
// 01 1
// 10 -2
// 11 -1

int main()
{
    Solution s;
    cout << s.minFlips("001 000 000 010");
}