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

class Solution
{
private:
    using LL = long long;

public:
    vector<vector<int>> child;
    vector<int> child_num;
    LL ans{INT_MIN};
    int len{}, sum{}, ret{};
    int countHighestScoreNodes(vector<int> &parents)
    {
        len = parents.size();
        child = vector<vector<int>>(len);
        child_num = vector<int>(len, 0);
        for (int i{}; i < len; ++i)
            if (parents[i] != -1)
                child[parents[i]].push_back(i);
        dfs(0);
        sum = child_num[0];
        for (int i = 0; i < len; ++i)
        {
            LL temp{score(i)};
            if (temp > ans)
                ret = 1, ans = temp;
            else
                ret += temp == ans;
        }
        return ret;
    }
    int dfs(int root)
    {
        if (!child[root].size())
            return child_num[root] = 1;
        for (auto x : child[root])
            child_num[root] += dfs(x);
        return ++child_num[root];
    }
    LL score(int i)
    {
        LL s{1};
        s = child_num[0] - child_num[i] == 0 ? 1 : child_num[0] - child_num[i];
        for (auto x : child[i])
            s *= child_num[x];
        return s;
    }
};

int main()
{
}