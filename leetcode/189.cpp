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
    void reverse(vector<int> &nums, int l, int r)
    {
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4};
    Solution s;
    s.rotate(a, 2);
    pr<int>(a);
}