#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        int n = recipes.size();
        unordered_map<string, vector<string>> d;
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            for (const string &gred : ingredients[i])
            {
                d[gred].push_back(recipes[i]);
            }
            cnt[recipes[i]] = ingredients[i].size();
        }

        vector<string> ans;
        queue<string> q;
        for (const string &sup : supplies)
        {
            q.push(sup);
        }
        while (!q.empty())
        {
            string now = q.front();
            q.pop();
            if (d.count(now))
            {
                for (const string &rec : d[now])
                {
                    --cnt[rec];
                    if (cnt[rec] == 0)
                    {
                        ans.push_back(rec);
                        q.push(rec);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
}