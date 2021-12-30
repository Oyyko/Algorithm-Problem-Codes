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
    using pii = pair<int, int>;
    struct cmp
    {
        bool operator()(pii &a, pii &b)
        {
            return a.second > b.second;
        }
    };
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        priority_queue<pii, vector<pii>, cmp> apps;
        int n = apples.size();
        int ans{};
        int d = 0;
        while (d < n || !apps.empty())
        {
            if (d < n && apples[d] > 0)
                apps.push({apples[d], d + days[d]});
            while (!apps.empty() && (apps.top().second <= d || apps.top().first == 0))
                apps.pop();
            if (!apps.empty())
            {
                ans++;
                auto tmp = apps.top();
                tmp.first--;
                apps.pop();
                apps.emplace(tmp);
            }
            ++d;
        }
        return ans;
    }
};

int main()
{
}