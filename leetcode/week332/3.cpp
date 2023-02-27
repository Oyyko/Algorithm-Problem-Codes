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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<vector<int>> ans{};
        using pii = pair<int, int>;
        map<int, pii> mp;
        using vi = vector<int>;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                mp[0].first = mp[0].second = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int v{};
            if (s[i] == '0')
                continue;
            for (int j = 0; j < 32 && i + j < n; ++j)
            {
                v *= 2;
                v += s[i + j] - '0';
                // if(i==2)cout<<"J"<<j<<endl;
                // if(i==2&&i+j==3)cout<<"AAA"<<v<<endl;
                if (mp.find(v) == mp.end())
                {
                    mp[v] = pii{i, i + j};
                }
            }
        }
        for (auto &v : queries)
        {
            int val = v[0] ^ v[1];
            if (mp.find(val) == mp.end())
            {
                ans.push_back(vi{-1, -1});
            }
            else
            {
                auto pp = mp[val];
                ans.push_back(vi{pp.first, pp.second});
            }
        }
        return ans;
    }
};

int main()
{
    map<int, int> x;
    cout << (x.find(2) == x.end());
}