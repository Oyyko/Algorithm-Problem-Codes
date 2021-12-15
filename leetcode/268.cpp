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
    int missingNumber(vector<int> &nums)
    {
        int ans{};
        for (int i = 1, _ = nums.size(); i <= _; ++i)
        {
            ans ^= i;
        }
        for (auto &x : nums)
        {
            ans ^= x;
        }
        return ans;
    }
};

int main()
{
}