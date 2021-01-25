#include <stdio.h>
#include <iostream>

int main()
{
    char x;
    while (std::cin>>x)
    {
        if (x >= 'a' && x <= 'z')
        {
            x += 'A' - 'a';
        }
        putchar(x);
    }
}
