// Fib Num

#include <iostream>

using namespace std;

struct Martix
{
    int a, b, c, d;
    // a b
    // c d
};

struct Vec
{
    int x, y;
};

Martix Mul(Martix A, Martix B)
{
    Martix C; // C=AB
    C.a = A.a * B.a + A.b * B.c;
    C.b = A.a * B.b + A.b * B.d;
    C.c = A.c * B.a + A.d * B.c;
    C.d = A.c * B.b + A.d * B.d;
    return C;
}

Vec MV(Martix X, Vec V)
{
    Vec R;
    R.x = X.a * V.x + X.b * V.y;
    R.y = X.c * V.x + X.d * V.y;
    return R;
}

int main()
{
    Martix A[3005];
    int fib[7050];
    A[1] = {1,
            1,
            1,
            0};
    A[1] = Mul(A[1], A[1]);
    Martix B;
    Vec V, V0;
    V0.x = 1;
    V0.y = 0;
    for (int i = 2; i <= 3000; ++i)
    {
        B = A[i / 2];
        B = Mul(B, B);
        if (i % 2 == 1)
        {
            A[i] = Mul(B, A[1]);
        }
        else
        {
            A[i] = B;
        }
        V = MV(A[i], V0);
        fib[2 * i] = V.y;
        fib[2 * i + 1] = V.x;
    }
    fib[1] = 1;
    fib[0] = 0;
    fib[2] = 1;
    fib[3] = 2;
    int n;
    while (~scanf("%d",&n))
    {
        printf("The Fibonacci number for %d is %d\n",n,fib[n]);
    }
    
}