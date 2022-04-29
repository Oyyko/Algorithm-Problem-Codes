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
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        int number = 1;
        for (int i = 0; i < n; ++i)
        {
            ans[i] = number;
            if (number * 10 <= n)
            {
                number *= 10;
            }
            else
            {
                while (number % 10 == 9 || number + 1 > n)
                {
                    number /= 10;
                }
                number++;
            }
        }
        return ans;
    }
};

int main()
{
}