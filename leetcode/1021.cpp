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
    string removeOuterParentheses(string s)
    {
        string ans;
        int tmp = 0;
        for (auto &x : s)
        {
            if (tmp == 0 && x == '(')
            {
                tmp++;
            }
            else if (tmp == 1 && x == ')')
            {
                tmp--;
            }
            else
                tmp += (x == '(' ? 1 : -1), ans.push_back(x);
            cout << tmp << " ";
        }
        return ans;
    }
};

int main()
{
}