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
    int cha(vector<int> &arr, int target, int m)
    {
        for (auto &x : arr)
        {
            if (x < m)
                target -= x;
            else
                target -= m;
        }
        return target;
    }
    int findBestValue(vector<int> &arr, int target)
    {
        int l = 0, r = accumulate(arr.begin(), arr.end(), INT_MIN, [](int a, int b)
                                  { return max(a, b); }),
            mid, tmp;
        while (l + 1 != r)
        {
            mid = l + (r - l) / 2;
            tmp = cha(arr, target, mid);
            if (tmp > 0)
            {
                l = mid;
            }
            else if (tmp == 0)
            {
                return mid;
            }
            else
            {
                r = mid;
            }
        }
        int ll = cha(arr, target, l);
        int rr = cha(arr, target, r);
        rr = -rr;
        if (ll <= rr)
            return l;
        else
            return r;
    }
};

int main()
{
}