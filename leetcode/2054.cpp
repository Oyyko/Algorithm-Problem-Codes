#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << " ";
    }
    cout << endl;
}

class Event
{
public:
    int ts, op, val;
    Event(int a, int b, int c) : ts(a), op(b), val(c) {}
    bool operator<(const Event &that) const { return tie(ts, op) < tie(that.ts, that.op); }
};
class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        vector<Event> es;
        for (const auto &e : events)
        {
            es.emplace_back(e[0], 0, e[2]);
            es.emplace_back(e[1], 1, e[2]);
        }
        sort(es.begin(), es.end());
        int ans{}, bestFirst{};
        for (const auto &[ts, op, val] : es)
        {
            if (!op)
                ans = max(ans, val + bestFirst);
            else
                bestFirst = max(bestFirst, val);
        }
        return ans;
    }
};

int main()
{
}