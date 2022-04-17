#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    using pii = pair<int, int>;
    int fen(pii p)
    {
        return min(p.first, p.second);
    }
    int maxTrailingZeros(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pii> v;
        v.resize(1001);
        for (int i = 1; i <= 1000; ++i)
        {
            int tt{}, ww{};
            int j = i;
            while (j % 2 == 0)
            {
                j /= 2;
                tt++;
            }
            j = i;
            while (j % 5 == 0)
            {
                j /= 5;
                ww++;
            }
            v[i] = make_pair(tt, ww);
        }
        
    }
};

int main()
{
}