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
#include <bit>
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
#include <bit>
#include <bitset>
#include <cstdint>

class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int n = students[0].size();
        int m = students.size();
        vector<vector<int>> rank(m, vector<int>(m, 0)); // rank[stu][ment]
        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < m; ++j)
            {
                for (int k{}; k < n; ++k)
                {
                    rank[i][j] += (students[i][k] == mentors[j][k]);
                }
            }
        }
        vector<int> f(1 << m, 0);
        for (int i{1}; i < (1 << m); ++i)
        {
            int c{__builtin_popcount(i)};
            for (int ii{}; ii < m; ++ii)
            {
                if (i & (1 << ii))
                {
                    f[i] = max(f[i], f[i ^ (1 << ii)] + rank[c - 1][ii]);
                }
            }
        }
        return f[(1 << m) - 1];
    }
};

int main()
{
}