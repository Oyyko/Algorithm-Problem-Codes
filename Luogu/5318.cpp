#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int to;
    struct edge *next;
};

struct vec
{
    struct edge *first;
};

void add_edge(int from, int to, struct vec *v)
{
    from = from - 1;
    if (!v[from].first)
    {
        v[from].first = (struct edge *)malloc(sizeof(struct edge));
        v[from].first->next = NULL;
        v[from].first->to = to;
    }
    else
    {
        struct edge *p;
        p = v[from].first;
        while (p->next)
        {
            p = p->next;
        }
        p->next = (struct edge *)malloc(sizeof(struct edge));
        p->next->next = NULL;
        p->next->to = to;
    }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    struct vec *v = (struct vec *)malloc(sizeof(struct vec) * n);
    for (int i = 0; i < n; ++i)
    {
        v[i].first = NULL;
    }
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        add_edge(a, b, v);
    }
    
}