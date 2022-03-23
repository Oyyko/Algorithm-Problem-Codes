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
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ans{};
        int n = nums.size();

        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                if (nums[j] == key && (abs(i - j) <= k))
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v{2, 2, 2, 2, 2};
    Solution s;
    pr(s.findKDistantIndices(v, 2, 2));
}