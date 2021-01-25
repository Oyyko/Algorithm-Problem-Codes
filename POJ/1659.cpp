    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <cstdlib>
    #include <cstdio>

    using namespace std;

    const int maxn = 13;

    int mat[maxn][maxn];

    struct node
    {
        int id;
        int deg;
    } p[maxn];

    bool Cmp(node a, node b)
    {
        return a.deg > b.deg;
    }

    bool Havel(int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            sort(p + i, p + n + 1, Cmp);
            if (i + p[i].deg > n)
                return false;
            for (int j = i + 1; j <= i + p[i].deg; ++j)
            {
                --p[j].deg;

                if (p[j].deg < 0)
                    return false;
                mat[p[i].id][p[j].id] = mat[p[j].id][p[i].id] = 1;
            }
        }
        if (p[n].deg < 0)
            return false;
        return true;
    }

    int main()
    {
        int t;
        scanf("%d", &t);
        while (t--)
        {
            memset(mat, 0, sizeof(mat));
            int n;
            bool flag = true;
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i)
            {
                p[i].id = i;
                cin >> p[i].deg;
                if (p[i].deg >= n)
                    flag = false;
            }
            if (Havel(n) && flag)
            {
                printf("YES\n");
                for (int i = 1; i <= n; ++i)
                {
                    printf("%d", mat[i][1]);
                    for (int j = 2; j <= n; ++j)
                    {
                        printf(" %d", mat[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("NO\n");
            }
            if (t)
                putchar('\n');
        }
    }