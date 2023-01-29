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
    int alternateDigitSum(int n)
    {
        int now = 1;
        int ans{};
        while (n)
        {
            ans += (n % 10) * now;
            now = -now;
            n /= 10;
        }
        if (now == 1)
        {
            return -ans;
        }
        return ans;
    }
};

int main()
{
}