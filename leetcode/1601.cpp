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
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        int m = requests.size();
        int ans{-1};
        int limit = (1 << m);
        for (int i{}; i < limit; ++i)
        {
            vector<int> in(n, 0);
            int cnt = __builtin_popcount(i);
            if (cnt <= ans)
                continue;
            for (int j{}; j < m; ++j)
            {
                if (i & (1 << j))
                {
                    int &f = requests[j][0];
                    int &t = requests[j][1];
                    in[f]--;
                    in[t]++;
                }
            }
            for (int k{}; k < n || (ans = max(ans, cnt), 0); ++k)
            {
                if (in[k] != 0)
                    break;
            }
        }
        return ans;
    }
};

int main()
{
}