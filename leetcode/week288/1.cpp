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
    int largestInteger(int num)
    {
        stack<int> s;
        vector<int> v;
        while (num)
        {
            s.push(num % 10);
            num /= 10;
        }
        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        int n = v.size();
        for (int i{}; i < n; ++i)
        {
            int maxx = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (v[i] % 2 == v[j] % 2)
                {
                    if (v[maxx] < v[j])
                        maxx = j;
                }
            }
            swap(v[i], v[maxx]);
        }
        int ans{};
        for (auto &x : v)
        {
            ans *= 10;
            ans += x;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.largestInteger(103);
}