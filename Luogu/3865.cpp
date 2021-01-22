// Sprase Table for Range Min Query //
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int Log2[MAXN];

int MAXX[MAXN][21];

int main()
{
    int n{};
    int m{};
    scanf("%d", &n);
    scanf("%d", &m);

    Log2[1] = 0;
    for (int i = 2; i <= MAXN; ++i)
    {
        Log2[i] = Log2[i / 2] + 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &MAXX[i][0]);
    }
    for (int j = 1; j <= 21; ++j)
    {
        int tmp = n - (1 << j) + 1;
        for (int i = 1; i <= tmp; ++i)
        {
            MAXX[i][j] = max(MAXX[i][j - 1], MAXX[i + (1 << (j - 1))][j - 1]);
        }
    }
    m = m - 1;
    for (int l, r, k; m; --m)
    {
        scanf("%d", &l);
        scanf("%d", &r);
        k = Log2[r - l + 1];
        //printf("k:%d ", k);
        //printf("MAXX[l][k]: %d ", MAXX[l][k]);
        //printf("MAXX[r - (1 << k) + 1][k]): %d ", MAXX[r - (1 << k) + 1][k]);
        printf("%d\n", max(MAXX[l][k], MAXX[r - (1 << k) + 1][k]));
    }
    int l, r, k;
    scanf("%d", &l);
    scanf("%d", &r);
    k = Log2[r - l + 1];
    printf("%d", max(MAXX[l][k], MAXX[r - (1 << k) + 1][k]));
}