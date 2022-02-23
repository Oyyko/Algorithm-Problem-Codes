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
    int totalMoney(int n)
    {
        int week = n / 7;
        int ans{};
        ans += (week + 1) * week * 7 / 2 + 21 * week;
        int d{n - 7 * week};
        ans += (week + week + d - 1) * d / 2;
        return ans;
    }
};

int main()
{
}