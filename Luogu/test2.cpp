#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k;
    for (int i = 1; i <= 65536; ++i)
    {
        k = log2(i);
        cout << i << " " << k << "\n";
    }
}