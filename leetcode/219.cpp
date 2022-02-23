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
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> s;
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            if (i > k)
            {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i]))
            {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};

int main()
{
}