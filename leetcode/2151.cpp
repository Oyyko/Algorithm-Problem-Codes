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
        int all = (1 << n);
        int cnt{};
        int ans{};
        for (int i{}; i < all; ++i)
        {
            cnt = 0;
            for (int j{}; j < n; ++j)
            {
                if ((1 << j) & i) //第j个是好人
                {
                    for (int k{}; k < n; ++k)
                    {
                        if (statements[j][k] < 2 && statements[j][k] != (0 != ((1 << k) & i)))
                        {

                            goto NOTGOOD;
                        }
                    }
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        NOTGOOD:;
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