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
        sort(meetings.begin(), meetings.end(), [&](auto &x, auto &y)
             { return x[2] < y[2]; });
        known[firstPerson] = 1;
        known[0] = 1;
        int now_time{-1};
        vector<vector<int>> sss;
        now_time = meetings[0][2];
        sss.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); ++i)
        {
            auto x = meetings[i];

            if (x[2] == now_time)
            {
                sss.push_back(x);
            }
            else
            {
                now_time = x[2];
                int fa[n + 1];
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
                    merge(xxx[1], xxx[0]);
                }
                for (auto &xxx : sss)
                {
                    known[find(xxx[1])] = known[find(xxx[1])] | (known[xxx[1]] | known[xxx[0]]);
                }
                for (auto &xxx : sss)
                {
                    known[xxx[1]] = known[find(xxx[1])];
                    known[xxx[0]] = known[find(xxx[1])];
                }

                sss.clear();
                sss.resize(0);
                sss.push_back(x);
            }
        }
        int fa[n + 1];
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
            merge(xxx[1], xxx[0]);
        }
        for (auto &xxx : sss)
        {
            known[find(xxx[1])] = known[find(xxx[1])] | (known[xxx[1]] | known[xxx[0]]);
        }
        for (auto &xxx : sss)
        {
            known[xxx[1]] = known[find(xxx[1])];
            known[xxx[0]] = known[find(xxx[1])];
        }

        vector<int> ans;
        for (int i = 0; i < known.size(); ++i)
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