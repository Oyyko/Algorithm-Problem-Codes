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
    vector<int> recoverArray(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        vector<int> ans;
        priority_queue<int, vector<int>, less<int>> pq;
        for (const auto &x : nums)
        {
            pq.push(x);
            cnt[x]++;
        }
        while (!pq.empty())
        {
            
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{2, 10, 6, 4, 8, 12};
    s.recoverArray(v);
}