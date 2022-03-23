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

template <typename T>
class Heap
{
private:
    function<bool(const T &, const T &)> larger;

    int l_child(int parent)
    {
        if (int l = 2 * parent + 1; l < v.size())
            return l;
        return -1;
    }
    int r_child(int parent)
    {
        if (int r = 2 * parent + 2; r < v.size())
            return r;
        return -1;
    }
    int parent(int child)
    {
        if (child == 0)
            return -1;
        return (child - 1) / 2;
    }
    void heapify_up(int now)
    {
        if (int p = parent(now); now >= 0 && p >= 0 && v[p] > v[now])
        {
            swap(v[p], v[now]);
            heapify_up(p);
        }
    }
    void heapify_down(int now)
    {
        int l = l_child(now), r = r_child(now);
        int less_child = v[l] < v[r] ? l : r;
        if (less_child > 0 && v[now] > v[less_child])
        {
            swap(v[now], v[less_child]);
            heapify_down(less_child);
        }
    }

public:
    Heap(function<bool(const T &, const T &)> f) : larger{f} {}
    vector<T> v;
    void push(const T &x)
    {
        v.push_back(x);
        heapify_up(v.size() - 1);
    }
    void decrease_node(int idx, T new_val)
    {
        v[idx] = new_val;
        heapify_up(idx);
    }
    void delete_min()
    {
        if (v.size() == 0)
            return;
        v[0] = v.back();
        v.pop_back();
        heapify_down(0);
    }
    T top()
    {
        return *v.begin();
    }
    bool empty()
    {
        return v.size() == 0;
    }
    T at(int idx) const
    {
        return v[idx];
    }
};

class Solution
{
public:
    using pii = pair<int, int>;
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, unordered_map<int, int>> mp;
        for (auto &x : times)
        {
            mp[x[0]][x[1]] = x[2];
        }
        const int inf = INT_MAX / 2;
        auto larger = [](const pii &a, const pii &b)
        { return a.second > b.second; };
        Heap<pii> h(larger);
        for (int i = 0; i < n; ++i)
        {
            h.push({i, inf});
        }
        h.decrease_node(k - 1, {k - 1, 0});
        while (!h.empty())
        {
            auto t = h.top();
            h.delete_min();
            for (auto &[idx, len] : h.v)
            {
                if (len > t.second + mp[t.first][idx])
                {
                    h.decrease_node(idx, {idx, t.second + mp[t.first][idx]});
                }
            }
        }
        auto ans = *max_element(h.v.begin(), h.v.end());
        return ans.second == inf ? -1 : ans.second;
    }
};

int main()
{
}