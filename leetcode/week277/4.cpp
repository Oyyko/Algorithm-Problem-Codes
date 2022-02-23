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
    int maximumGood(vector<vector<int>> &statements)
    {
        int n = statements.size();
        const int m = (1 << n);
        int ans{};
        for (int i{}; i < m; ++i)
        {
            int tmp{};
            bool yes{false};
            vector<int> is_good(n, 0);
            for (int j{}; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    is_good[j] = 1;
                    tmp++;
                }
            }
            for (int ii{}; ii < n; ++ii)
            {
                for (int jj{}; jj < n; ++jj)
                {
                    if (is_good[ii] == 1)
                    {
                        if (statements[ii][jj] == 1 && is_good[jj] == 0)
                        {
                            yes = false;
                            goto OUT;
                        }
                        if (statements[ii][jj] == 0 && is_good[jj] == 1)
                        {
                            yes = false;
                            goto OUT;
                        }
                    }
                }
            }
            yes = 1;
        OUT:
            if (yes)
                ans = max(ans, tmp), cout;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{2, 1, 2}, {1, 2, 2}, {2, 0, 2}};
    cout << s.maximumGood(v);
}