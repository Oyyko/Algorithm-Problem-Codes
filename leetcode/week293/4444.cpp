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

struct qujian
{
    int l, r;
    bool operator<(const qujian &b) const
    {
        return l < b.l;
    }
    bool operator==(const qujian &b) const
    {
        return l == b.l;
    }
    qujian(int ll, int rr) : l{ll}, r{rr} {}
};

class CountIntervals
{
public:
    int ans{};

    set<qujian> intervals;

    CountIntervals()
    {
    }

    bool inter(const qujian &a, const qujian &b)
    {
        return (a.l >= b.l && a.l <= b.r) || (a.r >= b.l && a.r <= b.r) || (a.l <= b.l && a.r >= b.r);
    }

    void add(int l, int r)
    {
        qujian n_qujian = qujian(l, r);
        if (intervals.empty())
        {
            intervals.insert(n_qujian);
            ans += r - l + 1;
            return;
        }
        auto itr = intervals.upper_bound(n_qujian);

        if (itr != intervals.begin())
            itr--;
        if (!inter(*itr, n_qujian))
            itr++;
        int rest_v = 0;
        int ll = l, rr = r;
        auto str = itr;
        while (itr != intervals.end() && inter(n_qujian, *itr))
        {
            rest_v += (*itr).r - (*itr).l + 1;
            ll = min(ll, (*itr).l);
            rr = max(rr, (*itr).r);
            itr++;
        }
        intervals.erase(str, itr);
        intervals.insert((qujian){ll, rr});
        ans += (rr - ll + 1 - rest_v);
    }

    int count()
    {
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main()
{
}