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
    int minimumDeletions(string s)
    {
        int ans{}, cnt_b{};
        for (const auto &x : s)
        {
            if (x == 'b')
                ++cnt_b;
            else
                ans = min(1 + ans, cnt_b);
        }
        return ans;
    }
};

int main()
{
}