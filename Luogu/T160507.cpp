#include <iostream>

using namespace std;

int main()
{
    int n, v, m, a;
    cin >> n >> v >> m >> a;
    int q{n / m};
    int r{n - q * m};
    cout << static_cast<int>(m * (q * v + a * (q * (q - 1)) / 2) + r * (v + q * a));
}
