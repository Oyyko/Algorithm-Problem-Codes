#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
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
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && s.top() < heights[i])
            {
                ans[i]++;
                s.pop();
            }
            ans[i] += (!s.empty());
            s.push(heights[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4};
    pr(s.canSeePersonsCount(v));
}