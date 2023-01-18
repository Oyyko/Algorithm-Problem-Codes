#include "base.hpp"

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

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}


class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos{}, neg{};
        for (auto &x : nums)
        {
            if (x > 0)
            {
                pos++;
            }
            else if (x < 0)
            {
                neg++;
            }
        }
        return max(pos,neg);
    }
};

int main()
{
}