#include "base.hpp"

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int n = target.size();
        vector<int> d(n, 0);
        d[0] = target[0];
        for (int i = 1; i < n; ++i)
        {
            d[i] = target[i] - target[i - 1];
        }
        int ans{};
        for (auto dd : d)
        {
            ans += max(dd, 0);
        }
        return ans;
    }
};

int main()
{
}