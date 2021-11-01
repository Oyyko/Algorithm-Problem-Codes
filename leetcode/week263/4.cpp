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
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<int> dis;
        dis.resize(n);
        vector<bool> yes;
        yes.resize(n);
        for (auto &x : yes)
        {
            x = 0;
        }
        for (auto &x : dis)
        {
            x = 0xfffff;
        }
        dis[0] = 0;
        yes[0] = 1;
        for (auto x : edges)
        {
            if (x[1] == 0)
            {
                dis[x[2]] = 1;
            }
            if (x[2] == 0)
            {
                dis[x[1]] = 1;
            }
        }
        int min_index{};
        for (int i = 0; i < n; ++i)
        {
            
        }
    }
};

int main()
{
}