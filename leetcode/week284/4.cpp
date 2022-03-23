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
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        using LL = long long;
        vector<LL> dis1(n, INT_MAX);
        vector<LL> dis2(n, INT_MAX);
        vector<LL> dis3(n, INT_MAX);
        unordered_map<int, vector<pii>> dd;
        unordered_map<int, vector<pii>> dd2;
        for (auto &x : edges)
        {
            dd[x[0]].push_back({x[1], x[2]});
            dd2[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq1;
        pq1.push({0, src1});
        while (pq1.empty() == false)
        {
            auto u = pq1.top();
            pq1.pop();
            for (auto &[weight, index] : dd[u.second])
            {
                if (dis1[index] > dis1[u.second] + weight)
                {
                    dis1[index] = dis1[u.second] + weight;
                    pq1.push({weight, index});
                }
            }
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq2;
        pq2.push({0, src2});
        while (pq2.empty() == false)
        {
            auto u = pq2.top();
            pq2.pop();
            for (auto &[weight, index] : dd[u.second])
            {
                if (dis2[index] > dis2[u.second] + weight)
                {
                    dis2[index] = dis2[u.second] + weight;
                    pq2.push({weight, index});
                }
            }
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq3;
        pq3.push({0, dest});
        while (pq3.empty() == false)
        {
            auto u = pq3.top();
            pq3.pop();
            for (auto &[weight, index] : dd2[u.second])
            {
                if (dis3[index] > dis3[u.second] + weight)
                {
                    dis3[index] = dis3[u.second] + weight;
                    pq3.push({weight, index});
                }
            }
        }

        LL ans{INT_MAX};
        ans = min(ans, dis1[src2] + dis2[dest]);
        ans = min(ans, dis2[src1] + dis1[dest]);
        for (int x{}; x < n; ++x)
        {
            ans = min(ans, dis1[x] + dis2[x] + dis3[x]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
}