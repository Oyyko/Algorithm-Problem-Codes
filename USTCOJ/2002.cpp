#include <iostream>

using namespace std;

int Pre[1000005][2]; // 0为约数个数，1为约数和

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 1; i <= 1000000; ++i)
    {
        for (int j = 1; j * i <= 1000000; ++j)
        {
            Pre[j * i][0] += 1;
            Pre[j * i][1] += i;
        }
    }
    for (int i = 2; i <= 1000000; ++i)
    {
        Pre[i][0] = Pre[i - 1][0] + Pre[i][0];
        Pre[i][1] = Pre[i - 1][1] + Pre[i][1];
    }
    int f, l, r;
    for (int i = 1; i <= k; ++i)
    {
        cin >> f >> l >> r;
        f = f - 1;
        cout << Pre[r][f] - Pre[l - 1][f];
    }
}