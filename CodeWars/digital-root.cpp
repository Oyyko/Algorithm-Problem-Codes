#include <iostream>

using namespace std;

int digital_root(int n)
{
    if (n < 10)
        return n;
    int q{};
    while (n)
    {
        q += n % 10;
        n = n / 10;
    }
    return digital_root(q);
}

int main()
{
    int x;
    cin >> x;
    cout << digital_root(x);
}