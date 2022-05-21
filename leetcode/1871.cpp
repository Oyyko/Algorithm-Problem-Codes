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
    bool canReach(string s, int minJump, int maxJump)
    {
        if (s.back() == '1')
            return 0;
        int cnt{0};
        int n = s.size();
        vector<int> can(n, 0);
        can[0] = 1;
        for (int i = 0; i < n;)
        {
            // cout << cnt << endl;
            if (s[i] == '1')
            {
            }
            else
            {
                if (i != 0)
                    can[i] = cnt != 0;
            }
            i++;
            if (i >= maxJump + 1)
                cnt -= can[i - maxJump - 1];
            if (i >= minJump)
                cnt += can[i - minJump];
        }
        // pr(can);
        return can.back() != 0;
    }
};

int main()
{
    Solution s;
    s.canReach("011010", 2, 3);
}