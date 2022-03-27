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
    int maximumTop(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans{};
        if (n == 1 && k % 2 == 1)
            return -1;
        else
        {
            int r = min(k + 1, n);
            for (int i{}; i < min(n, k + 1); ++i)
                if (i != k - 1)
                    ans = max(ans, nums[i]);
        }
        return ans;
    }
};
int main()
{
}