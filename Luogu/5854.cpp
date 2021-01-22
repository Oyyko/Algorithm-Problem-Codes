// Cartesian Tree //
#include <iostream>

using namespace std;

const int MAXN{static_cast<int>(1e7 + 100)};

int ls[MAXN];
int rs[MAXN];
int s[MAXN]; //stack
int v[MAXN]; //value

inline int read() // Quick Read
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main()
{
    int n;
    n = read();
    int top{};

    for (int i = 1; i <= n; ++i)
    {
        v[i] = read();
        while (top && v[s[top]] > v[i])
        {
            ls[i] = s[top];
            top--;
        }
        rs[s[top]] = i;
        s[++top] = i;
    }
    long long lans{};
    long long rans{};
    for (int i = 1; i <= n; ++i)
    {
        lans ^= 1ll * i * (ls[i] + 1);
        rans ^= 1ll * i * (rs[i] + 1);
    }
    printf("%lld %lld", lans, rans);
}