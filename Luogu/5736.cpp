#include <iostream>

using namespace std;

bool Is_Prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 6 != 1 && n % 6 != 5)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int tmp;
    while (n != 1)
    {
        cin >> tmp;
        if (Is_Prime(tmp))
        {
            cout << tmp << " ";
        }
        --n;
    }
    cin >> tmp;
    if (Is_Prime(tmp))
    {
        cout << tmp;
    }
}