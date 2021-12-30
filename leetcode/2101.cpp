#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
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
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int l = bombs.size();
        auto yes = [&](int u, int v) -> bool {
            long long dx = bombs[u][0] - bombs[v][0];
            long long dy = bombs[u][1] - bombs[v][1];
            return (long long)bombs[u][2] * bombs[u][2] >= dx * dx + dy * dy;
        };
        unordered_map<int, vector<int>> e;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                if (i != j && yes(i, j)) {
                    e[i].push_back(j);
                }
            }
        }
        int ans = 0;   
        for (int i = 0; i < l; ++i) {
            vector<int> visited(l);
            int cnt = 1;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int cidx = q.front();
                q.pop();
                for (const int nidx: e[cidx]) {
                    if (visited[nidx]) {
                        continue;
                    }
                    ++cnt;
                    q.push(nidx);
                    visited[nidx] = 1;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> v{{2, 1, 3}, {6, 1, 4}};
    cout << s.maximumDetonation(v);
}