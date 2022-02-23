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
    int kIncreasing(vector<int> &arr, int k)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            vector<int> dp;
            int l = 0;
            for (int j = i; j < n; j += k)
            {
                ++l;
                auto it = upper_bound(dp.begin(), dp.end(), arr[j]);
                if (it == dp.end())
                {
                    dp.push_back(arr[j]);
                }
                else
                {
                    *it = arr[j];
                }
            }
            ans += l - dp.size();
        }
        return ans;
    }
};

int main()
{
}