#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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
    bool stoneGameIX(vector<int> &stones)
    {
        int zero_even{1};
        int diff{};
        bool nott1{false};
        bool nott2{false};
        for (auto x : stones)
        {
            switch (x % 3)
            {
            case 0:
                zero_even ^= 1;
                break;
            case 1:
                nott1 = 1;
                diff++;
                break;
            case 2:
                nott2 = 1;
                diff--;
                break;
            default:
                break;
            }
        }
        if (zero_even)
        {
            if (nott1 && nott2)
            {
                return true;
            }
            return false;
        }
        if (diff >= 3 || diff <= -3)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v{5, 1, 2, 3, 4};
    cout << s.stoneGameIX(v);
}