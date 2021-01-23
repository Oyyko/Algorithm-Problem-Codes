#include <iostream>

using namespace std;

const int n{1000005};

int main()
{
    int *ans = (int *)malloc(sizeof(int) * n);
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = 0;
    }
    ans[1] = 1;
    long long j{};
    for (int i = 2, cnt{1}; i < n; ++i)
    {
        j = i;
        while (j != 1)
        {
            if (j < n && ans[j])
            {
                cnt += ans[j] - 1;
                break;
            }
            if (j % 2 == 1)
            {
                j = j * 3 + 1;
                cnt++;
            }
            else
            {
                j = j / 2;
                cnt++;
            }
        }
        ans[i] = cnt;
        cnt = 1;
    }
    int l[10005], r[10005], a{};
    int len{};
    bool flag[10005]{false};
    while (~scanf("%d", &l[len]), ~scanf("%d", &r[len]))
    {
        if (l[len] > r[len])
        {
            swap(l[len], r[len]);
            flag[len] = true;
        }
        len++;
    }
    len--;

    int tmp{len};
    while (len)
    {
        a = 0;
        for (int i = l[tmp - len]; i <= r[tmp - len]; ++i)
        {
            a = max(a, ans[i]);
        }
        if (flag[tmp - len])
            swap(l[tmp - len], r[tmp - len]);
        printf("%d %d %d\n", l[tmp - len], r[tmp - len], a);
        len--;
    }
    a = 0;
    for (int i = l[tmp - len]; i <= r[tmp - len]; ++i)
    {
        a = max(a, ans[i]);
    }
    if (flag[tmp - len])
        swap(l[tmp - len], r[tmp - len]);
    printf("%d %d %d", l[tmp - len], r[tmp - len], a);
}