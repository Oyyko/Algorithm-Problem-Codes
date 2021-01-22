#include <iostream>

using namespace std;

int Log2[65537];

int main()
{
    Log2[1] = 0;
    for (int i = 2; i <= 65536; ++i)
    {
        Log2[i] = 1 + Log2[i / 2];
        cout << i << " " << Log2[i] << "\n";
    }
}