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
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());
        int ans = special[0] - bottom;
        int n = special.size();
        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        ans = max(ans, top - special.back());
        return ans;
    }
};

int main()
{
}