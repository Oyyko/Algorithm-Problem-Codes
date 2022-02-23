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
private:
    int cnt[100005] = {0};

public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        vector<int> ans;
        int n = changed.size();
        priority_queue<int, vector<int>, less<int>> pq;
        for (const auto &x : changed)
            pq.push(x), cnt[x]++;
        while (!pq.empty())
        {
            auto tmp = pq.top();
            // cout << tmp << endl;
            if (cnt[tmp] == 0)
            {
                pq.pop();
                continue;
            }
            else
            {
                cnt[tmp]--;
            }
            if (tmp % 2 == 1)
                return vector<int>{};
            auto x = tmp / 2;
            if (cnt[x])
            {
                cnt[x]--;
                ans.push_back(x);
            }
            else
            {
                return vector<int>{};
            }
            if (ans.size() * 2 == n)
                return ans;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 3, 4, 2, 6, 8};
    pr(s.findOriginalArray(v));
}