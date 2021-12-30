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
    using LL = long long;
    static constexpr LL MOD = 1000000000 + 7;
    // a[i]*(r-i+1)*(i-l+1)
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> l(n, 0), r(n, 0);
        stack<int> s1, s2;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!s1.empty() && arr[i] <= arr[s1.top()])
            {
                l[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        while (!s1.empty())
        {
            l[s1.top()] = -1;
            s1.pop();
        }

        for (int i = 0; i < n; ++i)
        {
            while (!s1.empty() && arr[i] < arr[s1.top()])
            {
                r[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        while (!s1.empty())
        {
            r[s1.top()] = n;
            s1.pop();
        }

        LL ans{};
        for (int i = 0; i < n; ++i)
        {
            ans += static_cast<LL>(arr[i]) * (r[i] - i) * (i - l[i]);
            ans %= MOD;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{3, 1, 2, 4};
    cout << s.sumSubarrayMins(v);
}