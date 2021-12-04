#include <bits/stdc++.h>

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
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<int> known(n, 0);
        vector<vector<int>> times(100005);
        set<int> tt;
        set<int> temp;
        for (int i = 0; i < meetings.size(); ++i)
        {
            times[meetings[i][2]].push_back(i);
            tt.insert(meetings[i][2]);
        }
        known[0] = 1;
        known[firstPerson] = 1;
        int fa[n + 1];
        for (auto &x : tt)
        {
            vector<vector<int>> sss;
            for (auto &pp : times[x])
            {
                sss.push_back(meetings[pp]);
            }
            for (int i = 0; i < n; ++i)
            {
                fa[i] = i;
            }
            function<int(int)> find;
            find = [&](int x) -> int
            { return x == fa[x] ? x : (fa[x] = find(fa[x])); };
            auto merge = [&](int i, int j)
            { fa[find(i)] = find(j); };
            for (auto &xxx : sss)
            {
                temp.insert(xxx[1]);
                temp.insert(xxx[0]);
                merge(xxx[1], xxx[0]);
            }
            for (auto &xxx : sss)
            {
                known[find(xxx[1])] = known[find(xxx[1])] | (known[xxx[1]] | known[xxx[0]]);
            }
            for (auto &ttt : temp)
            {
                known[ttt] = known[find(ttt)];
            }
            temp.clear();
        }
        vector<int> ans;
        for (int i{}; i < known.size(); ++i)
        {
            if (known[i])
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
    pr(s.findAllPeople(5, v, 1));
}