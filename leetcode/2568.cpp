#include "base.hpp"

class Solution
{
public:
    int minImpossibleOR(vector<int> &nums)
    {
        set<int> s;
        for (auto &i : nums)
            s.insert(i);
        for (int i{}; i <= 30; ++i)
            if (s.count(1 << i) == 0)
                return 1 << i;
        return 0;
    }
};

int main()
{
}