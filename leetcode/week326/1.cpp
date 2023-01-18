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
    int countDigits(int num)
    {
        int ans{};
        int nn = num;
        while (num)
        {
            ans += (nn % (num % 10)) == 0;
            num /= 10;
        }
        return ans;
    }
};

int main()
{
}