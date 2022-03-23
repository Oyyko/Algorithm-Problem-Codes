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
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int lm{-1}, rm{-1};
        int ans{};
        while (l < r)
        {
            lm = max(lm, height[l]), rm = max(rm, height[r]);
            if (lm < rm)
                ans += lm - height[l++];
            else
                ans += rm - height[r--];
        }
        return ans;
    }
};

int main()
{
}