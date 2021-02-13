#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
using ll = long long;
const int maxn = 105;

inline ll read()
{
    ll a = 0;
    int f = 0;
    char p = getchar();
    while (!isdigit(p))
    {
        f |= (p == '-');
        p = getchar();
    }
    while (isdigit(p))
    {
        a = (a << 3) + (a << 1) + (p ^ 48);
        p = getchar();
    }
    return f ? -a : a;
}

struct martix
{
    ll a[maxn][maxn];
    int n;
    martix()
    {
        memset(a, 0, sizeof(a));
    }
    inline void build()
    {
        for (int i = 1; i <= n; ++i)
        {
            a[i][i] = 1;
        }
    }
};

martix operator*(const martix &a, const martix &b)
{
    martix c;
    c.n = a.n;
    for (int i = 1; i <= a.n; ++i)
    {
        for (int j = 1; j <= a.n; ++j)
        {
            for (int k = 1; k <= a.n; ++k)
            {
                c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
            }
        }
    }
    return c;
}

void ppp(martix A)
{
    int m{A.n};
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%lld ", A.a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    ll k;
    k = read();
    martix A;
    A.n = n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            A.a[i][j] = read();
        }
    }
    martix ans;
    ans.n = n;
    ans.build();
    do
    {
        if (k & 1)
        {
            ans = ans * A;
        }
        A = A * A;
        k >>= 1;
    } while (k);
    for (int i = 1; i <= n; putchar('\n'), ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d ", ans.a[i][j]);
        }
    }
    return 0;
}