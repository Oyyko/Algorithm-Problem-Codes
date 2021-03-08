#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ll b, p, k;
    cin >> b >> p >> k;
    printf("%lld^%lld mod %lld=", b, p, k);
    b = b % k;
    ll ans = 1;
    do
    {
        if (p & 1)
        {
            ans = (ans * b) % k;
        }
        p >>= 1;
        b = (b * b) % k;
    } while (p);
    printf("%lld", ans % k);
}