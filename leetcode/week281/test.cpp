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

int sum(int x)
{
    int ans{};
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    vector<int> ans(1001, 0);
    for (int i = 1; i <= 1000; ++i)
    {
        if (sum(i) % 2 == 0)
        {
            ans[i] = ans[i - 1] + 1;
        }
        else
        {
            ans[i] = ans[i - 1];
        }
    }
    for (int i = 1; i <= 1000; ++i)
    {
        cout << ans[i] << ",";
    }
}