#include <iostream>

using namespace std;

void Rebuild(char *mid, char *post)
{
    char x[10];
    if (*mid)
    {
        char *root = post;
        while (*root)
        {
            root++;
        }
        root--;
        cout << *root;
        char *p = mid;
        while (*p != *root)
        {
            p++;
        }
        *p = '\0';
        *root = '\0';
        int k = p - mid; //left child tree
        for (int i = 0; i < k; ++i)
        {
            x[i] = post[i];
        }
        x[k] = '\0';
        Rebuild(mid, x);
        Rebuild(p + 1, post + k);
    }
}

int main()
{
    char Mid[10];
    char Post[10];
    cin >> Mid;
    cin >> Post;
    Rebuild(Mid, Post);
}