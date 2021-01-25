#include <iostream>

using namespace std;

bool Is_Prime(int n)
{
    int k = n % 6;
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (k == 0 || k == 2 || k == 3 || k == 4)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

char word[105];
int cnt[200];

int main()
{
    cin >> word;
    char *p = word;
    while (*p)
    {
        cnt[*p]++;
        p++;
    }
    int maxn = -1;
    int minn = 2000;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        //printf("%c:%d\n", i, cnt[i]);
        maxn = max(maxn, cnt[i]);
        if (cnt[i])
            minn = min(minn, cnt[i]);
    }

    //printf("%d\n", maxn);
    //printf("%d\n", minn);

    int d = maxn - minn;
    if (Is_Prime(d))
        printf("Lucky Word\n%d", d);
    else
        printf("No Answer\n%d", 0);
}