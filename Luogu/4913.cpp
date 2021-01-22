#include <iostream>

#define MAXN 50010

struct node
{
    int l, r;
}

struct node tree[MAXN];

void dep(int now, int &d)
{
    static int d=0;
    d++;
    if (tree[now].l)
        dep[tree[now].l];
    d++;
    if (tree[now].r)
        dep[tree[now].r];
    
    
}

int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tree[i].l >> tree[i].r;
    }
}