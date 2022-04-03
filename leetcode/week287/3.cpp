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
    using ll = long long;
    int maximumCandies(vector<int> &candies, long long k)
    {
        ll n = candies.size();
        ll sum = accumulate(candies.begin(), candies.end(), 0);
        if (k > sum)
            return 0;
        sort(candies.begin(), candies.end(), greater<int>());
        if (k <= n)
        {
            return candies[k - 1];
        }
        
    }
};

int main()
{
}