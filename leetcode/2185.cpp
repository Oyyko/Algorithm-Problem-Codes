#include "base.hpp"

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans{};
        for (auto &x : words)
        {
            ans += x.find(pref) == 0;
        }
        return ans;
    }
};

int main()
{
}