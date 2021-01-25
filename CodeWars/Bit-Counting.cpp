#include <iostream>

using namespace std;

unsigned int countBits(unsigned long long n)
{
    unsigned int cnt{};
    while (n)
    {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}

int main()
{
    int x;
    cin >> x;
    cout << countBits(x);
}