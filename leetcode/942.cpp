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
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        int ll = 0, rr = n;
        vector<int> ans;
        for (auto &t : s)
        {
            if (t == 'I')
            {
                ans.push_back(ll++);
            }
            else
            {
                ans.push_back(rr--);
            }
        }
        ans.push_back(ll);
        return ans;
    }
};

int main()
{
}