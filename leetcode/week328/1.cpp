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

int f(int x)
{
    int ans{};
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int esum = accumulate(nums.begin(), nums.end(), 0);
        int nsum = accumulate(nums.begin(), nums.end(), 0, [](int a, int b)
                              { return a + f(b); });
        return abs(esum - nsum);
    }
};

int main()
{
}