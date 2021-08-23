#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> sortedSquares(vector<int> &nums)
    {
        auto l = nums.begin();
        auto r = nums.end() - 1;
        int n = nums.size();
        vector<int> ans(n);
        int pos = n - 1;
        while (l <= r)
        {
            if ((*l) * (*l) > (*r) * (*r))
            {
                ans[pos--] = (*l) * (*l);
                l++;
            }
            else
            {
                ans[pos--] = (*r) * (*r);
                r--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {-4, -1, 0, 3, 10};
    Solution s;
    pr<int>(s.sortedSquares(a));
}