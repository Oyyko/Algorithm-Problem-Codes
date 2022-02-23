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
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int ans{};
        for (const auto &x : nums)
        {
            ans += mp[x - k];
            ans += mp[x + k];
            mp[x]++;
        }
        return ans;
    }
};

int main()
{
}