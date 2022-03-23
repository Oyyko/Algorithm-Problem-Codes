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
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
    {
        int ans{};
        vector<vector<int>> d(n, vector<int>(n, 0));
        for (auto &x : dig)
        {
            d[x[0]][x[1]] = 1;
        }
        for (auto &x : artifacts)
        {
            int r1 = x[0];
            int c1 = x[1];
            int r2 = x[2];
            int c2 = x[3];
            bool yes = true;
            for (int r = r1; r <= r2; ++r)
            {
                for (int c = c1; c <= c2; ++c)
                {
                    if (d[r][c] == 0)
                    {
                        yes = false;
                        break;
                    }
                }
                if (!yes)
                    break;
            }
            ans += yes;
        }
        return ans;
    }
};

int main()
{
}