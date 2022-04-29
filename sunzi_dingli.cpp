#include <iostream>

using namespace std;

long exgcd(long a, long b, long &x, long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long d = exgcd(b, a % b, x, y);
    long temp = x;
    x = y;
    y = temp - a / b * y;
    return d;
}

int main()
{
    long lcm, gcd, r, rem, x, y, a[10], k[10], p[10], q[10], gc[10], gd[10], ans[10];
    int n, i;
    cin >> n;
    while (n)
    {
        for (i = 0; i < n; i++)
            scanf("%ld", &a[i]);
        lcm = a[0];
        for (i = 1; i < n; i++)
            lcm = lcm * a[i] / exgcd(lcm, a[i], x, y);
        for (i = 0; i < n; i++)
            p[i] = q[i] = lcm / a[i]; // Mi
        gc[n - 1] = lcm;
        for (i = n - 1; i > 0; i--)
            gc[i - 1] = exgcd(gc[i], p[i], x, y);
        //
        for (i = 0; i < n; i++)
            gd[i] = gc[i];
        rem = 1;
        for (i = 0; i < n; i++)
        {
            gcd = exgcd(p[i], gc[i], x, y);
            q[i] /= gcd;
            gd[i] /= gcd;

            r = rem;
            while (r < 0)
                r += lcm;
            r /= gcd;
            r %= gd[i];
            exgcd(q[i], gd[i], x, y);
            k[i] = r * x;
            while (k[i] <= 0)
                k[i] += a[i];
            ans[i] = p[i] * k[i];
            rem -= ans[i];
        }
        for (i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
        cin >> n;
    }
    return 0;
}
