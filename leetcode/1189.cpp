#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> mp;
        for (const auto &x : text)
        {
            mp[x]++;
        }
        int ans{INT_MAX};
        // string want{"balloon"};
        ans = min(ans, mp['b']);
        ans = min(ans, mp['a']);
        ans = min(ans, mp['l'] / 2);
        ans = min(ans, mp['o'] / 2);
        ans = min(ans, mp['n']);
        return ans;
    }
};

int main()
{
}