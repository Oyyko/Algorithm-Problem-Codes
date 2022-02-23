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
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans{};
        for (int col{}; col < n; col++)
        {
            int minn{INT_MAX};
            int mini{-1};
            for (int i{}; i < m; i++)
            {
                if (matrix[col][i] < minn)
                {
                    mini = i;
                    minn = matrix[col][i];
                }
            }
            for (int j{}; j < n || (ans.push_back(minn), 0); ++j)
            {
                if (minn < matrix[j][mini])
                {
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    pr(s.luckyNumbers(v));
}