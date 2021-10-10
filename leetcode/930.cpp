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
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int suml{}, sumr{};
        int l{}, r{};
        int ans{};
        for (int j = 0; j < nums.size(); ++j)
        {
            suml += nums[j];
            while (l < j && suml > goal)
            {
                sunl -= nums[l++];
            }
            sumr += nums[j];
            while (r < j && (sumr > goal || (sumr == goal && nums[r] == 0)))
            {
                sumr -= nums[r++];
            }
            if (suml == goal)
            {
                ans += r - l + 1;
            }
        }
        return ans;
    }
};

int main()
{
}