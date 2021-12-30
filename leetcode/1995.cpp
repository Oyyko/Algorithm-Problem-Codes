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
    int countQuadruplets(vector<int> &nums)
    {
        int l = nums.size();
        int cnt{};
        for (int a{}; a < l; ++a)
            for (int b{a + 1}; b < l; ++b)
                for (int c{b + 1}; c < l; ++c)
                    for (int d{c + 1}; d < l; ++d)
                        cnt += nums[a] + nums[b] + nums[c] == nums[d];
        return cnt;
    }
};

int main()
{
}