#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double Pi = acos(-1.0);

inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

const int MAXN = static_cast<int>(6 * 1e6 + 10);

struct complex
{
    double x, y;
    complex(double xx = 0, double yy = 0)
    {
        x = xx;
        y = yy;
    }
} a[MAXN], b[MAXN];

complex operator+(complex a, complex b)
{
    return complex(a.x + b.x, a.y + b.y);
}
complex operator-(complex a, complex b)
{
    return complex(a.x - b.x, a.y - b.y);
}
complex operator*(complex a, complex b)
{

    return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ostream &operator<<(ostream &out, complex &x)
{
    out << x.x << "+" << x.y << "i"
        << " ";
    return out;
}

void fft(int limit, complex *a, int type)
{
    if (limit == 1)
        return;
    complex a1[limit >> 1], a2[limit >> 1];
    for (int i = 0; i < limit; i += 2)
    {
        a1[i >> 1] = a[i];
        a2[i >> 1] = a[i + 1];
    }
    fft(limit >> 1, a1, type);
    fft(limit >> 1, a2, type);
    complex Wn = complex(cos(2.0 * Pi / limit), type * sin(2.0 * Pi / limit));
    complex w = complex(1, 0);
    for (int i = 0; i < (limit >> 1); ++i, w = w * Wn)
    {
        complex tmp{w * a2[i]};
        a[i] = a1[i] + tmp;
        a[i + (limit >> 1)] = a1[i] - tmp;
    }
}

int main()
{
    int n = read();
    int m{read()};
    for (int i = 0; i <= n; ++i)
    {
        a[i].x = read();
    }
    for (int i = 0; i <= m; ++i)
    {
        b[i].x = read();
    }
    int limit{1};
    while (limit <= n + m)
    {
        limit <<= 1;
    }
    fft(limit, a, 1);
    fft(limit, b, 1);

    for (int i = 0; i <= limit; ++i)
    {
        a[i] = a[i] * b[i];
    }
    fft(limit, a, -1);
    for (int i = 0; i <= m + n; ++i)
    {
        printf("%d ", (int)(a[i].x / limit + 0.5));
    }
    return 0;
}