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
    // bool check(vector<int> &pos, int m, int d)
    // {
    //     auto itr = pos.begin();
    //     while (itr != pos.end() && m)
    //     {
    //         m--;
    //         itr = lower_bound(itr, pos.end(), *itr + d);
    //     }
    //     return m == 0;
    // }
    bool check(vector<int> &pos, int m, int d)
    {
        int pre = pos[0], cnt = 1;
        for (auto &x : pos)
            if (x - pre >= d)
                pre = x, cnt++;
        return cnt >= m;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int l = 0;
        int r = position.back() - position.front();
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (check(position, m, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (check(position, m, r))
            return r;
        return l;
    }
};

int main()
{
}