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
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        partial_sum
        vector<int> ans;
        copy_if(nums.begin(), nums.end(), inserter(ans, ans.begin()), [](int a)
                { return a % 2 == 0; });
        pr(ans);
        copy_if(nums.begin(), nums.end(), inserter(ans, ans.end()), [](int a)
                { return a % 2 == 1; });
        pr(ans);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{3, 1, 2, 4};
    s.sortArrayByParity(v);
}