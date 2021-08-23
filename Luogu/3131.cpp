#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int P = 1000117;
const int N = 100050;
char rB[1 << 21], *rS, *rT;
inline char gc() { return rS == rT && (rT = (rS = rB) + fread(rB, 1, 1 << 21, stdin), rS == rT) ? EOF : *rS++; }
inline int rd()
{
    char c = gc();
    while (c < 48 || c > 57)
        c = gc();
    int x = c & 15;
    for (c = gc(); c >= 48 && c <= 57; c = gc())
        x = (x << 3) + (x << 1) + (c & 15);
    return x;
}
int x[N], y[N], G[N * 24], to[N * 192], nxt[N * 192], sz, cnt, pre[N * 24], dfsc, n, m, c, tmpx[N * 24], tmpy[N * 24], ctmp;
bool isok[N * 24], iscut[N * 24];
struct node
{
    int x, y;
    node() {}
    node(int x, int y) : x(x), y(y) {}
};
queue<node> Q, q;
struct Hash
{ //用hash实现map
    int h[P], vx[N * 25], vy[N * 25], p[N * 25], nxt[N * 25], sz;
    inline void clear()
    {
        memset(h, 0, sizeof(h));
        sz = 0;
    }
    inline void ins(int x, int y, int id)
    {
        int pos = ((ll)(x - 1) * n + y - 1) % P;
        vx[++sz] = x;
        vy[sz] = y;
        p[sz] = id;
        nxt[sz] = h[pos];
        h[pos] = sz;
    }
    inline int ask(int x, int y)
    {
        for (int k = h[((ll)(x - 1) * n + y - 1) % P]; k; k = nxt[k])
            if (vx[k] == x && vy[k] == y)
                return p[k];
        return 0;
    }
} h, col, tem;
inline int Abs(int x) { return x < 0 ? -x : x; }
inline int Max(int a, int b) { return a > b ? a : b; }
inline void add(int u, int v)
{
    to[++sz] = v;
    nxt[sz] = G[u];
    G[u] = sz;
    to[++sz] = u;
    nxt[sz] = G[v];
    G[v] = sz;
}
inline bool check()
{
    int i, j, k, tx, ty;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (!h.ask(i, j))
            {
                for (k = 0; k < 4; ++k)
                    if ((tx = i + dx[k]) && tx <= n && (ty = j + dy[k]) && ty <= m && !h.ask(tx, ty))
                        return 1;
                return 0;
            }
}
inline void bfs(int sx, int sy, int cl)
{ //第一次floodfill
    int i, u, v, tx, ty;
    q.push(node(sx, sy));
    col.ins(sx, sy, cl);
    while (!q.empty())
    {
        u = q.front().x;
        v = q.front().y;
        q.pop();
        for (i = 0; i < 4; ++i)
            if ((tx = u + dx[i]) && tx <= n && (ty = v + dy[i]) && ty <= m && h.ask(tx, ty) > 0 && !col.ask(tx, ty))
            {
                col.ins(tx, ty, cl); //用col来记录所属联通块编号（也成为颜色）
                q.push(node(tx, ty));
            }
    }
}
inline bool bfs2(int sx, int sy)
{
    int i, u, v, x, y, t;
    q.push(node(sx, sy));
    tem.ins(sx, sy, -1);
    while (!q.empty())
    {
        u = q.front().x;
        v = q.front().y;
        q.pop();
        for (x = Max(1, u - 1); x <= n && x <= u + 1; ++x)
            for (y = Max(1, v - 1); y <= m && y <= v + 1; ++y)
                if ((t = h.ask(x, y)) && !tem.ask(x, y))
                    if (t == -1)
                    {
                        tem.ins(x, y, -1); //用tem来防止对障碍结点重复访问
                                           //对跳蚤结点的重复访问最多总共c*8个，不会影响复杂度
                        q.push(node(x, y));
                    }
                    else
                    {
                        tmpx[++ctmp] = x;
                        tmpy[ctmp] = y;
                    }
    }
    if (ctmp == -1)
        return 1;
    for (i = 1, t = col.ask(tmpx[0], tmpy[0]); i <= ctmp; ++i)
        if (col.ask(tmpx[i], tmpy[i]) != t)
            return 0;
    return 1;
}
inline bool ncon()
{ //判断是否不连通
    int i, u, v, ccl = 0;
    col.clear();
    while (!Q.empty())
    {
        u = Q.front().x;
        v = Q.front().y;
        Q.pop();
        if (col.ask(u, v))
            continue;
        bfs(u, v, ++ccl);
    }
    tem.clear();
    for (i = 0; i < c; ++i)
        if (!tem.ask(x[i], y[i]))
        {
            ctmp = -1;
            if (!bfs2(x[i], y[i]))
                return 1;
        }
    return 0;
}
int dfs(int u, int fa)
{ //dfs求割顶
    int i, v, lowu = pre[u] = ++dfsc, lowv, chd = 0;
    for (i = G[u]; i; i = nxt[i])
        if ((v = to[i]) != fa)
            if (!pre[v])
            {
                ++chd;
                if ((lowv = dfs(v, u)) >= pre[u])
                    iscut[u] = 1;
                if (lowv < lowu)
                    lowu = lowv;
            }
            else if (pre[v] < lowu)
                lowu = pre[v];
    if (!fa && chd == 1)
        iscut[u] = 0;
    return lowu;
}
int main()
{
    int T = rd(), i, j, k, l, t, tt, tx, ty;
    bool ok;
    while (T--)
    {
        n = rd();
        m = rd();
        c = rd();
        h.clear();
        for (i = 0; i < c; ++i)
        {
            x[i] = rd();
            y[i] = rd();
            h.ins(x[i], y[i], -1);
        }
        if ((ll)n * m - c < 2ll)
        {
            puts("-1");
            continue;
        }
        if ((ll)n * m - c == 2ll)
        {
            puts(check() ? "-1" : "0");
            continue;
        }
        memset(G, 0, sizeof(G));
        ok = sz = cnt = dfsc = 0;
        memset(pre, 0, sizeof(pre));
        memset(iscut, 0, sizeof(iscut));
        memset(isok, 0, sizeof(isok));
        //建图
        for (i = 0; i < c; ++i)
            for (j = Max(1, x[i] - 2); j <= x[i] + 2 && j <= n; ++j)
                for (k = Max(1, y[i] - 2); k <= y[i] + 2 && k <= m; ++k)
                    if (!(t = h.ask(j, k)))
                    {
                        h.ins(j, k, ++cnt);
                        Q.push(node(j, k));
                        isok[cnt] = Max(Abs(j - x[i]), Abs(k - y[i])) <= 1;
                        for (l = 0; l < 4; ++l)
                            if ((tx = j + dx[l]) && tx <= n && (ty = k + dy[l]) && ty <= m && (tt = h.ask(tx, ty)) > 0)
                                add(cnt, tt);
                    }
                    else if (t > 0 && Max(Abs(j - x[i]), Abs(k - y[i])) <= 1)
                        isok[t] = 1;
        if (ncon())
        {
            puts("0");
            continue;
        }
        if (n == 1 || m == 1)
        {
            puts("1");
            continue;
        }
        for (i = 1; i <= cnt; ++i)
        {
            if (!pre[i])
                dfs(i, 0);
            if (isok[i] && iscut[i])
            {
                puts("1");
                ok = 1;
                break;
            }
        }
        if (!ok)
            puts("2");
    }
    return 0;
}