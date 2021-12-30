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
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = (numBottles / (numExchange - 1)) * numExchange + (numBottles % (numExchange - 1));
        if ((numBottles % (numExchange - 1)) == 0)
            return ans - 1;
        return ans;
    }
};

int main()
{
}