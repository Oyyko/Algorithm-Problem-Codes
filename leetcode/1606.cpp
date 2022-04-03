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
    using pii = pair<int, int>;
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        set<int> ready;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // 完成时间 服务器id
        for (int i{}; i < k; ++i)
            ready.insert(i);
        vector<int> cnt(k);
        for (int i{}; i < arrival.size(); ++i)
        {
            int t = arrival[i];
            while (!pq.empty() && pq.top().first <= t)
            {
                ready.insert(pq.top().second);
                pq.pop();
            }
            if (ready.empty())
                continue;
            auto itr = ready.lower_bound(i % k);
            if (itr == ready.end())
                itr = ready.begin();
            cnt[*itr]++;
            pq.push(make_pair(t + load[i], *itr));
            ready.erase(itr);
        }
        auto mm = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i{}; i < k; ++i)
        {
            if (mm == cnt[i])
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
}