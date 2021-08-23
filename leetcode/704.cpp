#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l{0};
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + (r - l) / 2);
            if (nums[mid] == target)
            {
                return mid;
            }
            if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1, 0, 3, 5, 9, 12};
    cout << s.search(v, 9);
}