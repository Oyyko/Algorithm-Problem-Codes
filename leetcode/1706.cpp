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
#include <numeric>
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
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> loc(n);
        iota(loc.begin(), loc.end(), 0);
        for (int i{}; i < m; ++i)
        {
            for (int ball{}; ball < n; ++ball)
            {
                int &location = loc[ball];
                if (location == -1)
                    continue;
                if (grid[i][location] == 1)
                {
                    if (location == n - 1 || grid[i][location + 1] == -1)
                    {
                        location = -1;
                    }
                    else
                    {
                        location++;
                    }
                }
                else
                {
                    if (location == 0 || grid[i][location - 1] == 1)
                    {
                        location = -1;
                    }
                    else
                    {
                        location--;
                    }
                }
            }
        }
        return loc;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> g = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    pr(s.findBall(g));
}