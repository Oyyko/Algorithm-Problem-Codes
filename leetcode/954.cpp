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
    bool canReorderDoubled(vector<int> &arr)
    {
        unordered_map<int, int> cnt;
        for (auto &&x : arr)
            cnt[x]++;
        if (cnt[0] % 2 == 1)
            return false;
        vector<int> num;
        num.reserve(cnt.size());
        for (auto &[x, y] : cnt)
        {
            num.push_back(x);
        }
        sort(num.begin(), num.end(), [](int &x, int &y)
             { return abs(x) < abs(y); });
        for (int x : num)
        {
            if (cnt[2 * x] < cnt[x])
                return false;
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};

int main()
{
}