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
    vector<int> selfDividingNumbers(int left, int right)
    {
        auto check = [](int x) -> bool
        {
            bool ans = true;
            int ori = x;
            while (x && ans)
            {
                if (x % 10 == 0)
                    return false;
                ans = ori % (x % 10) == 0;
                x /= 10;
            }
            return ans;
        };
        vector<int> ans;
        ans.reserve(10000);
        for (int i = left; i <= right; ++i)
        {
            if (check(i))
                ans.push_back(i);
        }
        return ans;
    }
};

auto check1 = [](int x) -> bool
{
    bool ans = true;
    int ori = x;
    while (x && ans)
    {
        cout << x << endl;
        if (x % 10 == 0)
            return false;
        ans = ori % (x % 10) == 0;
        x /= 10;
    }
    return ans;
};

int main()
{
    Solution s;
    cout << check1(21);
    // pr(s.selfDividingNumbers(1, 22));
}