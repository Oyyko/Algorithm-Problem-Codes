#include "base.hpp"

class Solution
{
public:
    int minimumMoves(string s)
    {
        int ans{};
        for (size_t i{}; i < s.size();)
        {
            if (s[i] == 'X')
            {
                i += 3;
                ans++;
            }
            else
            {
                i += 1;
            }
        }
        return ans;
    }
};

int main()
{
}