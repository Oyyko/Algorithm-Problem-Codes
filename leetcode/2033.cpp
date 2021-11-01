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
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int mod = grid[0][0] % x;

        vector<int> all;
        for (auto xx : grid)
        {
            for (auto y : xx)
            {
                if (y % x != mod)
                {
                    return -1;
                }
                all.push_back(y);
            }
        }
        sort(all.begin(), all.end());
        int mid = all[all.size() / 2];
        int ans{};
        for (auto x : grid)
        {
            for (auto y : x)
            {
                ans += abs(mid - y);
            }
        }
        return ans / x;
    }
};

int main()
{
}