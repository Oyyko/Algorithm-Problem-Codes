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
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (tx > sx && ty > sy && tx != ty)
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        if (tx == sx)
            return (ty - sy) % sx == 0;
        if (ty == ty)
            return (tx - sx) % sy == 0;
        return false;
    }
};

int main()
{
    Solution s;
    s.reachingPoints(1, 1, 3, 5);
}