#include <iostream>
#include <random>
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
    bool isBoomerang(vector<vector<int>> &points)
    {
        vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
    }
};

int main()
{
}