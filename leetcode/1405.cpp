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
    using pii = pair<int, int>;
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pii> pq{};
        string ans{};
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});
        while (!pq.empty())
        {
            auto [num, c] = pq.top();
            // cout << "NUM" << num << "  " << static_cast<char>(c) << endl;
            pq.pop();
            if (int n = ans.size(); n >= 2 && ans[n - 1] == c && ans[n - 2] == c)
            {
                if (pq.empty())
                    break;
                auto [num2, c2] = pq.top();
                pq.pop();
                // cout << "AAA" << pq.size() << endl;
                ans.push_back(c2);
                if (num2 - 1)
                    pq.push({num2 - 1, c2});
                pq.push({num, c});
            }
            else
            {
                ans.push_back(c);
                if (num - 1)
                    pq.push({num - 1, c});
            }
        }
        // cout << "ANS" << ans.size() << " " << pq.size() << endl;
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.longestDiverseString(1, 1, 7);
}