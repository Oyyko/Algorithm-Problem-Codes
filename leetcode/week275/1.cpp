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
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i{}; i < n; ++i)
        {
            vector<bool> has(n + 1, 0);
            for (int j{}; j < n; ++j)
            {
                if (matrix[i][j] > n)
                    return false;
                has[matrix[i][j]] = 1;
            }
            for (int k{1}; k <= n; ++k)
            {
                if (!has[k])
                    return false;
            }
        }

        for (int i{}; i < n; ++i)
        {
            vector<bool> has(n + 1, 0);
            for (int j{}; j < n; ++j)
            {
                has[matrix[j][i]] = 1;
            }
            for (int k{1}; k <= n; ++k)
            {
                if (!has[k])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{1, 1, 1}, {1, 2, 3}, {1, 2, 3}};
    cout << s.checkValid(v);
}