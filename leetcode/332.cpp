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
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> vec;
    vector<string> ans;

    void dfs(const string &curr)
    {
        while (vec.count(curr) && vec[curr].size() > 0)
        {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        ans.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (const auto &x : tickets)
        {
            vec[x[0]].emplace(x[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
}