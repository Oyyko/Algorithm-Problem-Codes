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
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (auto &x : tasks)
        {
            mp[x]++;
        }
        vector<int> v;
        for (auto &x : mp)
        {
            v.push_back(x.second);
        }
        int ans{};
        for (auto &x : v)
        {
            if (x == 1)
                return -1;
            if (x == 2)
            {
                ans += 1;
            }
            if (x >= 3)
            {
                int yu = x % 3;
                int chu = x / 3;
                if (yu == 2)
                {
                    ans += chu;
                    ans += 1;
                }
                if (yu == 0)
                {
                    ans += chu;
                }
                if (yu == 1)
                {
                    ans += chu - 1;
                    ans += 2;
                }
            }
        }
        return ans;
    }
};

int main()
{
}