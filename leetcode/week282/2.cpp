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

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> cnt1(300, 0);
        vector<int> cnt2(300, 0);
        for (auto &x : s)
            cnt1[x]++;
        for (auto &x : t)
            cnt2[x]++;
        int ans{};
        for (int x = 'a'; x <= 'z'; ++x)
        {
            ans += abs(cnt1[x] - cnt2[x]);
        }
        return ans;
    }
};

int main()
{
}