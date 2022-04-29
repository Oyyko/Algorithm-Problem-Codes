#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

int main()
{
}

class Solution
{
public:
    using pii = pair<int, int>;
    using ppp = pair<pii, pii>;

    int ans = 0, N, n;
    int st[10], b[7][5], d[7][5];
    vector<ppp> edge;
    pii dian[8][3];
    void dfs2(int x)
    {
        if (x == 6)
        {
            int flag = 1;
            for (auto [op, ip] : edge)
            {
                int op1 = op.first, op2 = op.second;
                int ip1 = ip.first, ip2 = ip.second;
                if ((b[st[op1]][op2] ^ b[st[ip1]][ip2]) != (N - 1))
                    flag = 0;
            }
            for (int i = 0; i < 8; i++)
            {
                int t = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (d[st[dian[i][j].first]][dian[i][j].second] == 1)
                        t++;
                }
                if (t != 1)
                    flag = 0;
            }

            if (flag)
                ans = 1;
            return;
        }
        auto xuan = [&]()
        {
            for (int i = 0; i < 4; i++)
                b[x][i] = b[x][i + 1];
            b[x][4] = b[x][0];

            for (int i = 0; i < 4; i++)
                d[x][i] = d[x][i + 1];
            d[x][4] = d[x][0];
        };
        auto fan = [&]()
        {
            swap(b[x][1], b[x][3]);
            int t = 0, t2 = 0;
            for (int j = 0; j < n - 2; j++)
                if (b[x][2] >> j & 1)
                    t += (1 << (n - 2 - j));
            for (int j = 0; j < n - 2; j++)
                if (b[x][4] >> j & 1)
                    t2 += (1 << (n - 2 - j));
            b[x][2] = t, b[x][4] = t2;

            swap(d[x][1], d[x][4]);
            swap(d[x][2], d[x][3]);
        };
        fan();
        for (int i = 0; i < 4; i++)
        {
            xuan();
            dfs2(x + 1);
        }
        fan();
        for (int i = 0; i < 4; i++)
        {
            xuan();
            dfs2(x + 1);
        }
    }

    void dfs(int u)
    {
        if (u == 7)
        {
            dfs2(1);

            return;
        }
        for (int i = 2; i <= 6; i++)
            if (!st[i])
            {
                st[i] = u;
                dfs(u + 1);
                st[i] = 0;
            }
    }

    bool composeCube(vector<vector<string>> &s)
    {
        for (auto w : s)
        {
            for (int i = 1; i < n - 1; i++)
            {
                for (int j = 1; j < n - 1; j++)
                {
                    if (w[i][j] == '0')
                        return 0;
                }
            }
        }
        n = s[0].size(), N = 1 << (n - 2);
        vector<int> id(7), edd(7), dui = {0, 6, 4, 5, 2, 3, 1};

        edge.push_back({{2, 2}, {3, 4}});
        edge.push_back({{3, 2}, {4, 4}});
        edge.push_back({{4, 2}, {5, 4}});
        edge.push_back({{5, 2}, {2, 4}});

        edge.push_back({{2, 1}, {6, 1}});
        edge.push_back({{3, 1}, {6, 2}});
        edge.push_back({{4, 1}, {6, 3}});
        edge.push_back({{5, 1}, {6, 4}});

        edge.push_back({{2, 3}, {1, 1}});
        edge.push_back({{3, 3}, {1, 2}});
        edge.push_back({{4, 3}, {1, 3}});
        edge.push_back({{5, 3}, {1, 4}});

        dian[0][0] = {1, 1}, dian[0][1] = {5, 3}, dian[0][2] = {2, 4};
        dian[1][0] = {1, 2}, dian[1][1] = {2, 3}, dian[1][2] = {3, 4};
        dian[2][0] = {1, 3}, dian[2][1] = {3, 3}, dian[2][2] = {4, 4};
        dian[3][0] = {1, 4}, dian[3][1] = {4, 3}, dian[3][2] = {5, 4};

        dian[4][0] = {6, 1}, dian[4][1] = {5, 1}, dian[4][2] = {4, 2};
        dian[5][0] = {6, 2}, dian[5][1] = {4, 1}, dian[3][2] = {4, 2};
        dian[6][0] = {6, 3}, dian[6][1] = {3, 1}, dian[2][2] = {4, 2};
        dian[7][0] = {6, 4}, dian[7][1] = {2, 1}, dian[5][2] = {4, 2};

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                if (s[i][0][j + 1] == '1')
                    b[i + 1][1] += 1 << j;
                if (s[i][j + 1][n - 2] == '1')
                    b[i + 1][2] += 1 << j;
                if (s[i][n - 2][j + 1] == '1')
                    b[i + 1][3] += 1 << j;
                if (s[i][j + 1][0] == '1')
                    b[i + 1][4] += 1 << j;
            }
        }

        for (int i = 0; i < 6; i++)
        {
            if (s[i][0][0] == '1')
                d[i + 1][1] = 1;
            if (s[i][0][n - 1] == '1')
                d[i + 1][2] = 1;
            if (s[i][n - 1][0] == '1')
                d[i + 1][4] = 1;
            if (s[i][n - 1][n - 1] == '1')
                d[i + 1][3] = 1;
        }

        st[1] = 1;
        dfs(2);

        return ans;
    }
};