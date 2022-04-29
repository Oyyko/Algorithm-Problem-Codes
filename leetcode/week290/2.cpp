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
    int countLatticePoints(vector<vector<int>> &circles)
    {
        for (auto &c : circles)
        {
            c[2] *= c[2];
        }
        int cnt{};
        for (int x = 0; x <= 230; ++x)
        {
            for (int y = 0; y <= 230; ++y)
            {
                for (auto &c : circles)
                {
                    if ((c[0] - x) * (c[0] - x) + (c[1] - y) * (c[1] - y) <= c[2])
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
}