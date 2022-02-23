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
    int countElements(vector<int> &nums)
    {
        int n = nums.size();
        int maxx = INT_MIN;
        int minn = INT_MAX;
        for (auto &x : nums)
        {
            maxx = max(maxx, x);
            minn = min(minn, x);
        }
        for (auto &x : nums)
        {
            if (x == maxx || x == minn)
            {
                n--;
            }
        }
        return n;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 1, 2, 3};
    cout << s.countElements(v);
}