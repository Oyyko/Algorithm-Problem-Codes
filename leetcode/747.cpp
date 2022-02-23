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
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int maxi{-1};
        int maxv{INT_MIN};
        int subv{INT_MIN};
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > maxv)
            {
                subv = maxv;
                maxv = nums[i];
                maxi = i;
            }
            else if (nums[i] > subv)
            {
                subv = nums[i];
            }
        }
        return maxv >= subv * 2 ? maxi : -1;
    }
};

int main()
{
}