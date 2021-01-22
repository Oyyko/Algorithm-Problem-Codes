#include <iostream>

void f(int *p)
{
    static int xx = 0;
    int x = 2;
    int *y = &x;
    if (xx == 1)
        printf("%d\n", *p);
    xx++;
    if (xx == 1)
        f(y);
}

int main()
{
    f(NULL);
}