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
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans(2);
        unordered_set<int> n1, n2;
        for (auto &&x : nums1)
            n1.insert(x);
        for (auto &&x : nums2)
            n2.insert(x);
        for (auto &&x : n1)
        {
            if (n2.find(x) == n2.end())
                ans[0].push_back(x);
        }
        for (auto &&x : n2)
        {
            if (n1.find(x) == n1.end())
                ans[1].push_back(x);
        }
        return ans;
    }
};

int main()
{
}