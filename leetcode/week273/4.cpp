#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
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
    vector<int> recoverArray(vector<int> &nums)
    {
        if (nums.size() == 2)
        {
            return vector<int>{(nums[0] + nums[1]) / 2};
        }
    }
};

int main()
{
}