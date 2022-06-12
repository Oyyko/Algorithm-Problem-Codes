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
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        unordered_map<int, vector<int>> mp;
        for (auto &x : nums)
        {
            mp[x].push_back(x);
        }
        for (auto &p : operations)
        {
            for (auto &x : mp[p[0]])
                mp[p[1]].push_back(x);
            mp.erase(p[0]);
        }
        unordered_map<int, int> mp2;
        for (auto &[k, v] : mp)
        {
            for (auto &x : v)
            {
                mp2[x] = k;
            }
        }
        for (auto &x : nums)
        {
            x = mp2[x];
        }
        return nums;
    }
};

int main()
{
}