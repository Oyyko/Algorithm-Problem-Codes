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
    int fa[1005];
    int size[1005];
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        vector<bool> ans;
        ans.reserve(1005);
        for (int i = 0; i < n; ++i)
        {
            fa[i] = i;
            size[i] = 1;
        }
        function<int(int)> find;
        find = [&](int i)
        { return fa[i] == i ? i : fa[i] = find(fa[i]); };
        auto merge = [&](int i, int j)
        {
            int set1 = find(i);
            int set2 = find(j);
            if (set1 == set2)
                return;
            if (size[set1] < size[set2])
            {
                swap(set1, set2);
            }
            fa[set2] = set1;
            size[set1] += size[set2];
        };
        auto check = [&](int a, int b) -> bool
        {
            int temp1, temp2;
            bool check1 = true;
            for (auto &x : restrictions)
            {
                temp1 = find(x[0]);
                temp2 = find(x[1]);
                if (temp1 == a && temp2 == b)
                {
                    check1 = false;
                    break;
                }
                else if (temp2 == a && temp1 == b)
                {
                    check1 = false;
                    break;
                }
            }
            return check1;
        };
        for (auto &req : requests)
        {
            int to_merge1 = find(req[0]);
            int to_merge2 = find(req[1]);
            if (check(to_merge1, to_merge2))
            {
                ans.emplace_back(true);
                merge(to_merge1, to_merge2);
            }
            else
            {
                ans.emplace_back(false);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res{{0, 1}};
    vector<vector<int>> req{{0, 2}, {2, 1}};
    auto ans = s.friendRequests(3, res, req);
    pr(ans);
}