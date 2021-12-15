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
    long long poww(long long a, long long b)
    {
        if (b == 0)
            return 1;
        if (b == 1)
            return a;
        long long half = poww(a, b / 2);
        half %= 1337;
        half *= half;
        half %= 1337;
        return b % 2 == 0 ? half : half * a;
    }
    long long superPow(int a, vector<int> &b)
    {
        long long weight = a;
        weight %= 1337;
        long long ans{1};
        for (auto itr = prev(end(b)); itr != begin(b); itr--)
        {
            auto x = *itr;
            ans *= poww(weight, x);
            ans %= 1337;
            weight = poww(weight, 10);
            weight %= 1337;
        }
        ans *= poww(weight, *(begin(b)));
        ans %= 1337;
        return ans;
    }
};

long long main()
{
}