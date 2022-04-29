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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

struct event
{
    pair<int, int> p;
    int idx;
    event(int a, int b, int c)
    {
        p.first = a;
        p.second = b;
        idx = c;
    }
    bool operator<(const event &x)
    {
        return p < x.p;
    }
};

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {
        int n = persons.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[persons[i]].push_back(i);
        }
        vector<int> ans(n);
        // 0 开花 1观察 2花谢
        using pii = pair<int, int>;
        vector<event> events;
        events.reserve(400500);
        for (auto &f : flowers)
        {
            events.emplace_back(f[0], 0, -1);
            events.emplace_back(f[1], 2, -1);
        }
        for (int i = 0; i < n; ++i)
        {
            auto &p = persons[i];
            events.emplace_back(p, 1, i);
        }
        sort(events.begin(), events.end());
        int flower_num{};
        for (auto &e : events)
        {
            if (e.p.second == 0)
            {
                flower_num++;
            }
            else if (e.p.second == 1)
            {
                ans[e.idx] = flower_num;
            }
            else
            {
                flower_num--;
            }
        }
        return ans;
    }
};

int main()
{
}