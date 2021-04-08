#include <iostream>
#include <vector>
using namespace std;

int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 1;
    }
    int k;
    int fk;
    int fk_minus_one;
    if (n % 2 == 0)
    {
        k = n / 2;
        fk = fib(k);
        fk_minus_one = fib(k - 1);
        return (2 * fk_minus_one + fk) * fk;
    }
    k = (n + 1) / 2;
    fk = fib(k);
    fk_minus_one = fib(k - 1);
    return fk * fk + fk_minus_one * fk_minus_one;
}

int main()
{
    int d;
    scanf("%d", &d);
    printf("%d\n", fib(d));
}