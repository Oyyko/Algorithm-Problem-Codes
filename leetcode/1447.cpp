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
    vector<string> simplifiedFractions(int n)
    {
        if (n == 1)
            return vector<string>{};
        vector<vector<bool>> is_true(101, vector<bool>(101, true));
        vector<string> res{};

        for (int fenmu = 2; fenmu <= 100; ++fenmu)
        {
            for (int fenzi{1}; fenzi <= fenmu - 1; ++fenzi)
            {
                if (!is_true[fenzi][fenmu])
                    continue;
                for (int k{2}; fenmu * k <= 100; ++k)
                {
                    is_true[fenzi * k][fenmu * k] = 0;
                }
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j{1}; j <= i - 1; ++j)
            {
                if (is_true[j][i])
                {
                    string ans{};
                    ans += to_string(j);
                    ans += "/"s;
                    ans += to_string(i);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    pr(s.simplifiedFractions(4));
}