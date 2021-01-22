#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
    int id;
    int tk;
    int t;
    int k;
};

bool cmp(Item A, Item B)
{
    if (A.tk > B.tk)
        return 1;
    if (A.tk == B.tk)
    {
        if (A.t > B.t)
            return 1;
        if (A.t == B.t)
            return A.id < B.id;
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    Item tk[500005];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tk[i].t);
        scanf("%d", &tk[i].k);
        tk[i].tk = tk[i].t * tk[i].k;
        tk[i].id = i;
    }
    sort(tk, tk + n, cmp);
    for (int i = 0; i <= n - 2; ++i)
    {
        cout << tk[i].id + 1 << " ";
    }
    cout << tk[n - 1].id + 1;
}