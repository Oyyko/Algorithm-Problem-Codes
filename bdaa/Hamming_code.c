#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    unsigned int cnt = 0;
    while (~(x = getchar()))
    {
        if (x == '1')
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}