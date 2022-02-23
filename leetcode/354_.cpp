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
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2)
             { return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]); });
        vector<int> dp = {envelopes[0][1]};
        for (int i = 1; i < n; ++i)
        {
            if (int num = envelopes[i][1]; num > dp.back())
            {
                dp.push_back(num);
            }
            else
            {
                auto itr = lower_bound(dp.begin(), dp.end(), num);
                *itr = num;
            }
        }
        return dp.size();
    }
};

int main()
{
}