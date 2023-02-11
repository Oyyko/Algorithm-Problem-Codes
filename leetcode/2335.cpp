#include "base.hpp"

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int sum = accumulate(amount.begin(), amount.end(), 0);
        int maxx = accumulate(amount.begin(), amount.end(), INT_MIN, [](int a, int b)
                              { return max(a, b); });
        if (2 * maxx >= sum)
            return maxx;
        return upper_divide(sum, 2);
    }
};

int main()
{
}