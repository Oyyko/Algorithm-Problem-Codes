#include <bits/stdc++.h>

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
    int search(vector<int> &nums, int target)
    {
        size_t l{0}, r{nums.size() - 1};
        auto yes = [&](int mid)
        { return nums[mid] >= target; };
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (yes(mid))
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] == target)
            return l;
        return -1;
    }
};

int main()
{
}