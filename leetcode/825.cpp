#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
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
    int numFriendRequests(vector<int> &ages)
    {
        int n = ages.size(), ans{};
        sort(begin(ages), end(ages));
        auto l = ages.begin(), r = l;
        for (const auto &x : ages)
        {
            if (x >= 15)
            {
                while (2 * (*l) <= x + 14)
                {
                    l++;
                }
                while (r != ages.end() && *r <= x)
                {
                    r++;
                }
                ans += r - l - 1;
            }
        }
        return ans;
    }
};

int main()
{
}