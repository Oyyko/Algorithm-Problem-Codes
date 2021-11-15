#include <bits/stdc++.h>

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
    int bulbSwitch(int n)
    {
        int cnt{};
        for (int i = 1; i * i <= n; ++i)
            cnt++;
        return cnt;
    }
};

int main()
{
}