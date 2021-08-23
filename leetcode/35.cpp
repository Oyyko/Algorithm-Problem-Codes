#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        while (l < r)
        {
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
        }
        if (nums[l] >= target)
        {
            return l;
        }
        else
        {
            return l + 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    cout << s.searchInsert(v, 7);
}