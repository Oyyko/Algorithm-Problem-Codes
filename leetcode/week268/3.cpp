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

class RangeFreqQuery
{
private:
    map<int, vector<pair<int, int>>> mp;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        map<int, int> temp;
        for (int i = 0; i < arr.size(); ++i)
        {
            mp[arr[i]].push_back(make_pair(i, temp[i] + 1));
            temp[i] = temp[i] + 1;
        }
    }
    int query(int left, int right, int value)
    {
#define VVV mp[value]
        auto rr = lower_bound(VVV.begin(), VVV.end(), make_pair(right, 0), [](auto &a, auto &b)
                              { return a.first < b.first; });
        auto ll = upper_bound(VVV.begin(), VVV.end(), make_pair(left, 0), [](auto &a, auto &b)
                              { return a.first < b.first; });
        int bbb;
        if (ll == VVV.begin())
            bbb = 0;
        else
        {
            --ll;
            bbb = (*ll).second;
        }
        return (*rr).second - bbb;
    }
};
int main()
{
}