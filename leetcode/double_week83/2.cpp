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
    using ll = long long;
    long long zeroFilledSubarray(vector<int> &nums)
    {
        ll ans{};
        ll tmp = 0;
        for (auto &x : nums)
        {
            if (x == 0)
            {
                tmp++;
            }
            else
            {
                ans += (tmp * (tmp + 1ll)) / 2;
                tmp = 0;
            }
        }
        ans += (tmp * (tmp + 1ll)) / 2;
        return ans;
    }
};

int main()
{
    vector<int> v{1, 3, 0, 0, 2, 0, 0, 4};
    
}