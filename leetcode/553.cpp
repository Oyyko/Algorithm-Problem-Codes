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
    string optimalDivision(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return to_string(nums[0]);
        if (n == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);

        string ans{};
        ans.reserve(10005);
        ans += to_string(nums[0]);
        ans += "/(";
        for (int i = 1; i < n - 1; ++i)
        {
            ans += to_string(nums[i]);
            ans += "/";
        }
        ans += to_string(nums[n - 1]);
        ans += ")";
        return ans;
    }
};

int main()
{
}