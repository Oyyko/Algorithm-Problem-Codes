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
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {
        for (auto &f : favoriteCompanies)
            sort(f.begin(), f.end());
        map<int, vector<int>> mp;
        for (size_t i{0}, _{favoriteCompanies.size()}; i < _; ++i)
            mp[favoriteCompanies[i].size()].push_back(i);
        vector<int> ans{};
        for (auto i = mp.rbegin(); i != mp.rend(); i++)
            for (auto &p : i->second)
            {
                if (i != mp.rbegin() && check(favoriteCompanies, ans, p))
                    continue;
                ans.push_back(p);
            }
        sort(begin(ans), end(ans));
        return ans;
    }
    bool check(vector<vector<string>> &fc, vector<int> &ans, int p)
    {
        for (auto &i : ans)
            if (includes(fc[i].begin(), fc[i].end(), fc[p].begin(), fc[p].end()))
                return true;
        return false;
    }
};

int main()
{
}