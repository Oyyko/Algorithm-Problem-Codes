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

int main()
{
    int n, m;
    vector<int> weight;
    weight.reserve(30);
    cin >> n >> m;
    {
        int tmp{};
        while (cin >> tmp)
        {
            weight.push_back(tmp);
        }
    }
    int num = n - m;
    int limit = (1 << n);
    int cur = (1 << num) - 1;
    int ans{};
    while (cur < limit)
    {
        vector<int> can(2005);
        can[0] = 1;
        for (int j{}; j < n; ++j)
        {
            if (cur & (1 << j))
            {
                for (int k = 2000; k >= 0; --k)
                {
                    if (can[k])
                    {
                        can[k + weight[j]] = 1;
                    }
                }
            }
        }
        int cnt{};
        for (int k = 2000; k >= 1; --k)
        {
            cnt += can[k];
        }
        ans = max(ans, cnt);

        int lb = cur & (-cur);
        int r = lb + cur;
        cur = ((cur ^ r) >> (__builtin_ctz(lb) + 2)) | r;
    }
    cout << ans;
}