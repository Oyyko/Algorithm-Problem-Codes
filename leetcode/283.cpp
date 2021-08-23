#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        auto now = nums.begin();
        auto dealed = nums.begin();
        while (dealed < nums.end())
        {
            if (*dealed != 0)
            {
                *(now++) = *dealed;
            }
            dealed++;
        }
        while (now < nums.end())
        {
            *now++ = 0;
        }
    }
};

int main()
{
    vector<int> v = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(v);
    pr(v);
}