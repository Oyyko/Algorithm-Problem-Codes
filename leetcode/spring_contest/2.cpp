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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit)
    {
        int n = cookbooks.size();
        int ans = -1;
        int baofu{}, meiwei{};
        for (int i = 0; i < (1 << n); ++i)
        {
            baofu = 0, meiwei = 0;
            vector<int> x = materials;
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    for (int ii = 0; ii < 5; ++ii)
                    {
                        x[ii] -= cookbooks[j][ii];
                    }
                    meiwei += attribute[j][0];
                    baofu += attribute[j][1];
                }
            }
            bool yes = 1;
            for (int k = 0; k < 5; ++k)
            {
                if (x[k] < 0)
                {
                    yes = 0;
                    break;
                }
            }
            if (yes && baofu >= limit)
            {
                ans = max(meiwei, ans);
            }
        }
        return ans;
    }
};

int main()
{
}